#include "../src/app/application/ConfigFiles.h"
#include "../src/model/CityConfig.h"
#include "../src/model/SkillConfig.h"
#include "../src/model/FormationConfig.h"
#include "../src/model/PersonConfig.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>

namespace
{
using namespace app;
void require(bool condition, const char *message)
{
    if (!condition) throw std::runtime_error(message);
}
std::string bytes(const std::filesystem::path &path)
{
    std::ifstream input(path, std::ios::binary);
    require(bool(input), "cannot read configuration fixture");
    return {std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>()};
}
struct Directory
{
    std::filesystem::path path;
    Directory()
    {
        wchar_t root[MAX_PATH], name[MAX_PATH];
        require(GetTempPathW(MAX_PATH, root) != 0, "temporary directory lookup failed");
        require(GetTempFileNameW(root, L"s9c", 0, name) != 0, "temporary name failed");
        path = name;
        require(DeleteFileW(name) && CreateDirectoryW(name, nullptr), "temporary directory creation failed");
    }
    ~Directory()
    {
        std::error_code error;
        for (const auto &entry : std::filesystem::directory_iterator(path))
            std::filesystem::remove(entry.path(), error);
        std::filesystem::remove(path, error);
    }
};
void noTemporaryFiles(const std::filesystem::path &root)
{
    for (const auto &entry : std::filesystem::directory_iterator(root))
        require(entry.path().filename().wstring().find(L".tmp-") == std::wstring::npos,
                "temporary configuration leaked");
}
BOOL WINAPI writeFailure(HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED)
{
    SetLastError(ERROR_DISK_FULL); return FALSE;
}
BOOL WINAPI shortWrite(HANDLE file, LPCVOID data, DWORD size, LPDWORD written, LPOVERLAPPED overlapped)
{
    return WriteFile(file, data, (std::min)(size, DWORD{3}), written, overlapped);
}
BOOL WINAPI zeroWrite(HANDLE, LPCVOID, DWORD, LPDWORD written, LPOVERLAPPED)
{
    *written = 0; return TRUE;
}
bool failAfterPartial;
BOOL WINAPI partialFailure(HANDLE file, LPCVOID data, DWORD size, LPDWORD written, LPOVERLAPPED overlapped)
{
    if (failAfterPartial) return writeFailure(file, data, size, written, overlapped);
    failAfterPartial = true;
    return shortWrite(file, data, size, written, overlapped);
}
BOOL WINAPI flushFailure(HANDLE)
{
    SetLastError(ERROR_WRITE_FAULT); return FALSE;
}
BOOL WINAPI removeFailure(LPCWSTR)
{
    SetLastError(ERROR_ACCESS_DENIED); return FALSE;
}
bool failClose;
BOOL WINAPI closeFailure(HANDLE file)
{
    if (failClose) { failClose = false; SetLastError(ERROR_INVALID_HANDLE); return FALSE; }
    return CloseHandle(file);
}
template<class Config>
void roundTrip(const std::filesystem::path &path)
{
    Config config, loaded;
    require(saveConfigFile(path, config).ok(), "configuration save failed");
    const auto serialized = bytes(path);
    for (size_t index = 0; index < serialized.size(); ++index)
        if (serialized[index] == '\n') require(index && serialized[index-1] == '\r', "export must use CRLF");
    require(loadConfigFile(path, loaded).ok(), "export cannot be loaded");
    require(saveConfigFile(path, loaded).ok() && bytes(path) == serialized, "configuration round trip differs");
}
}

void configFilesTest()
{
    Directory directory;
    const auto path = directory.path / L"配置.txt";
    roundTrip<san9::ParameterConfig>(path);
    roundTrip<san9::PersonConfig>(path);
    roundTrip<san9::CityConfig>(path);
    roundTrip<san9::SkillConfig>(path);
    roundTrip<san9::FormationConfig>(path);
    const auto before = bytes(path);
    const std::function<bool(std::ostream &)> serialize = [](auto &out) { out << "12\n34\n"; return true; };
    auto checkFailure = [&](ConfigFileApi api, ConfigFileError expected) {
        const auto result = saveConfigFile(path, serialize, api);
        require(result.error == expected && result.systemError != 0, "save failure diagnostic missing");
        require(bytes(path) == before, "failed save damaged original file");
        noTemporaryFiles(directory.path);
    };
    ConfigFileApi api;
    api.write = writeFailure; checkFailure(api, ConfigFileError::writeFailed);
    api = {}; api.write = partialFailure; failAfterPartial = false; checkFailure(api, ConfigFileError::writeFailed);
    api = {}; api.write = zeroWrite; checkFailure(api, ConfigFileError::writeFailed);
    api = {}; api.flush = flushFailure; checkFailure(api, ConfigFileError::flushFailed);
    api = {}; api.close = closeFailure; failClose = true; checkFailure(api, ConfigFileError::closeFailed);
    api = {}; api.flush = flushFailure; api.remove = removeFailure;
    const auto cleanup = saveConfigFile(path, serialize, api);
    require(cleanup.error == ConfigFileError::flushFailed && cleanup.systemError == ERROR_WRITE_FAULT &&
            cleanup.cleanupSystemError == ERROR_ACCESS_DENIED && !cleanup.temporaryFile.empty(),
            "cleanup failure must preserve primary error and report temporary path");
    require(bytes(path) == before && std::filesystem::exists(cleanup.temporaryFile),
            "cleanup failure damaged original or lost temporary path");
    require(DeleteFileW(cleanup.temporaryFile.c_str()), "cannot remove retained temporary fixture");
    noTemporaryFiles(directory.path);
    const auto locked = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
    require(locked != INVALID_HANDLE_VALUE, "cannot lock target");
    checkFailure({}, ConfigFileError::replaceFailed);
    require(CloseHandle(locked), "cannot close target lock");
    const std::function<bool(std::ostream &)> invalid = [](auto &out) { out << "partial"; return false; };
    require(saveConfigFile(path, invalid).error == ConfigFileError::invalidConfig && bytes(path) == before,
            "rejected serialization damaged target");
    bool threw = false;
    try {
        const std::function<bool(std::ostream &)> throwing = [](auto &) -> bool { throw std::runtime_error("serialization"); };
        saveConfigFile(path, throwing);
    } catch (const std::runtime_error &) { threw = true; }
    require(threw && bytes(path) == before, "serialization exception lost or damaged target");
    const auto absent = directory.path / L"missing" / L"config.txt";
    require(saveConfigFile(absent, serialize).error == ConfigFileError::createFailed, "missing directory diagnostic");
    san9::ParameterConfig parameter;
    require(loadConfigFile(absent, parameter).error == ConfigFileError::missingFile, "missing file diagnostic");
    const auto denied = CreateFileW(path.c_str(), GENERIC_READ, 0, nullptr, OPEN_EXISTING, 0, nullptr);
    require(denied != INVALID_HANDLE_VALUE, "cannot lock configuration for read");
    require(loadConfigFile(path, parameter).error == ConfigFileError::openFailed, "read access failure diagnostic");
    CloseHandle(denied);
    api = {}; api.write = shortWrite;
    require(saveConfigFile(path, serialize, api).ok() && bytes(path) == "12\r\n34\r\n", "short writes lost data");
    const auto created = directory.path / L"new.txt";
    require(saveConfigFile(created, serialize).ok() && bytes(created) == bytes(path), "new file save failed");
    noTemporaryFiles(directory.path);

    std::ostringstream defaults;
    parameter.write(defaults);
    auto readParameter = [&](const std::string &text) {
        const auto prior = parameter.get(1020);
        std::istringstream input(text);
        const auto result = configReadResult(parameter.read(input));
        require(parameter.get(1020) == prior, "invalid load changed parameter configuration");
        return result;
    };
    auto result = readParameter("12\nwrong\n");
    require(result.error == ConfigFileError::invalidInteger && result.line == 2, "invalid integer line missing");
    result = readParameter("12\n");
    require(result.error == ConfigFileError::missingLine && result.line == 2, "missing line location");
    result = readParameter("2147483648\n");
    require(result.error == ConfigFileError::integerOverflow && result.line == 1, "overflow line location");
    result = readParameter(defaults.str() + "extra\n");
    require(result.error == ConfigFileError::extraData && result.line == 35, "extra data line location");
    auto outOfRange = defaults.str(); outOfRange.replace(0, 2, "-1");
    result = readParameter(outOfRange);
    require(result.error == ConfigFileError::outOfRange && result.line == 1 && result.controlId == 1020,
            "invalid parameter field location");
    san9::SkillConfig skill;
    std::istringstream badSkill("bad\n");
    result = configReadResult(skill.read(badSkill));
    require(result.error == ConfigFileError::invalidInteger && result.line == 1, "packed diagnostic differs");
    std::cout << "Configuration round trips, CRLF, failed save preservation, cleanup and load diagnostics passed.\n";
}
