#include "../src/app/platform/Preferences.h"
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>

namespace
{
void require(bool value, const char *message)
{
    if (!value) throw std::runtime_error(message);
}
struct Directory
{
    std::filesystem::path path;
    Directory()
    {
        wchar_t root[MAX_PATH], name[MAX_PATH];
        require(GetTempPathW(MAX_PATH, root) != 0, "temporary directory lookup");
        require(GetTempFileNameW(root, L"s9p", 0, name) != 0, "temporary name");
        path = name;
        require(DeleteFileW(name) && CreateDirectoryW(name, nullptr), "temporary directory creation");
    }
    ~Directory()
    {
        std::error_code error;
        std::filesystem::remove_all(path, error);
    }
};
std::string bytes(const std::filesystem::path &path)
{
    std::ifstream file(path, std::ios::binary);
    require(bool(file), "read INI bytes");
    return {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
}
unsigned calls, failAt;
BOOL WINAPI failingWrite(LPCWSTR section, LPCWSTR key, LPCWSTR value, LPCWSTR path)
{
    // Even a failing call may have modified the staging file before returning failure.
    const auto result = WritePrivateProfileStringW(section, key, value, path);
    if (++calls == failAt) { SetLastError(ERROR_WRITE_FAULT); return FALSE; }
    return result;
}
BOOL WINAPI failingFlush(HANDLE) { SetLastError(ERROR_WRITE_FAULT); return FALSE; }
BOOL WINAPI failingReplace(LPCWSTR, LPCWSTR, DWORD) { SetLastError(ERROR_ACCESS_DENIED); return FALSE; }
void reread(const std::filesystem::path &path, bool changed)
{
    // Clear the profile cache, then use the same reader as a newly started application.
    WritePrivateProfileStringW(nullptr, nullptr, nullptr, path.c_str());
    require(GetPrivateProfileIntW(L"Extensions", L"SkipDurabilitySiegeSelection", 9, path.c_str()) == (changed ? 0u : 1u), "siege reread");
    require(GetPrivateProfileIntW(L"Extensions", L"ImproveComputerRewardTiming", 9, path.c_str()) == (changed ? 1u : 0u), "rewards reread");
    require(GetPrivateProfileIntW(L"Extensions", L"SkipComputerAttackStartDelay", 9, path.c_str()) == (changed ? 1u : 0u), "attack reread");
}
void noTemporaryFiles(const std::filesystem::path &root)
{
    for (const auto &entry : std::filesystem::directory_iterator(root))
        require(entry.path().extension() == L".ini", "staging file leaked");
}
}
void preferencesTest()
{
    Directory directory;
    const auto path = directory.path / L"settings.ini";
    const std::string fixture = "; preserved comment\r\n[City]\r\nAutoApply=0\r\n"
        "[Presentation]\r\nSpeed=4\r\n[Unknown]\r\nCustom=keep me\r\n"
        "[Extensions]\r\nUnknownOption=37\r\nSkipDurabilitySiegeSelection=1\r\n"
        "ImproveComputerRewardTiming=0\r\nSkipComputerAttackStartDelay=0\r\n";
    // Cover both existing ANSI and UTF-16 INIs, including unrelated sections/keys.
    for (bool unicode : {false, true})
    {
        std::string original = fixture;
        if (unicode)
        {
            original = "\xff\xfe";
            for (char ch : fixture) { original += ch; original += '\0'; }
        }
        { std::ofstream file(path, std::ios::binary); file.write(original.data(), original.size()); }
        reread(path, false);
        for (unsigned failure : {1u, 2u, 3u, 4u, 5u, 6u})
        {
            ui::PreferenceFileApi api;
            calls = 0; failAt = failure;
            if (failure <= 4) api.write = failingWrite;
            if (failure == 5) api.flush = failingFlush;
            if (failure == 6) api.replace = failingReplace;
            require(!ui::saveExtensionPreferences(path, false, true, true, api), "failure must be reported");
            if (failure <= 4) require(calls == failure, "stop on first failed write");
            require(bytes(path) == original, "failed save changed original bytes");
            reread(path, false);
            noTemporaryFiles(directory.path);
        }
        require(ui::saveExtensionPreferences(path, false, true, true), "successful retry");
        // Also exercise a read without explicitly clearing the cache after replacement.
        require(GetPrivateProfileIntW(L"Extensions", L"ImproveComputerRewardTiming", 9, path.c_str()) == 1, "immediate reread");
        reread(path, true);
        require(GetPrivateProfileIntW(L"City", L"AutoApply", 9, path.c_str()) == 0, "preserve city");
        require(GetPrivateProfileIntW(L"Presentation", L"Speed", 9, path.c_str()) == 4, "preserve speed");
        require(GetPrivateProfileIntW(L"Extensions", L"UnknownOption", 9, path.c_str()) == 37, "preserve unknown key");
        wchar_t custom[32]{};
        GetPrivateProfileStringW(L"Unknown", L"Custom", L"", custom, 32, path.c_str());
        require(std::wstring(custom) == L"keep me", "preserve unknown section");
        noTemporaryFiles(directory.path);
    }
    const auto missing = directory.path / L"new.ini";
    for (unsigned failure : {2u, 3u})
    {
        calls = 0; failAt = failure;
        ui::PreferenceFileApi api; api.write = failingWrite;
        require(!ui::saveExtensionPreferences(missing, false, true, true, api), "first save failure");
        require(!std::filesystem::exists(missing), "failed first save published INI");
        for (const auto key : {L"SkipDurabilitySiegeSelection", L"ImproveComputerRewardTiming", L"SkipComputerAttackStartDelay"})
            require(GetPrivateProfileIntW(L"Extensions", key, 9, missing.c_str()) == 9, "missing INI fallback");
        noTemporaryFiles(directory.path);
    }
    require(ui::saveExtensionPreferences(missing, false, true, true), "first save success");
    reread(missing, true);
    noTemporaryFiles(directory.path);
}
#ifdef SAN9_PREFERENCES_TEST_STANDALONE
int main() { preferencesTest(); }
#endif
