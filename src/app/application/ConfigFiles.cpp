#include "ConfigFiles.h"
#include <atomic>
#include <algorithm>
#include <cerrno>
#include <limits>
#include <utility>

namespace app
{
ConfigFileResult configReadResult(const san9::ConfigReadResult &result)
{
    using S = san9::ConfigReadStatus;
    ConfigFileError error;
    switch (result.status)
    {
    case S::complete: error = ConfigFileError::none; break;
    case S::truncated: error = ConfigFileError::missingLine; break;
    case S::integerOverflow: error = ConfigFileError::integerOverflow; break;
    case S::ioError: error = ConfigFileError::readFailed; break;
    case S::invalidInteger: error = ConfigFileError::invalidInteger; break;
    case S::extraData: error = ConfigFileError::extraData; break;
    case S::invalidValues: error = ConfigFileError::outOfRange; break;
    default: error = ConfigFileError::readFailed;
    }
    return {error, result.line, result.controlId};
}
ConfigFileResult configReadResult(const san9::PackedReadResult &result)
{
    using E = san9::PackedReadError;
    ConfigFileError error;
    switch (result.error)
    {
    case E::none: error = ConfigFileError::none; break;
    case E::missingLine: error = ConfigFileError::missingLine; break;
    case E::invalidInteger: error = ConfigFileError::invalidInteger; break;
    case E::integerOverflow: error = ConfigFileError::integerOverflow; break;
    case E::outOfRange: error = ConfigFileError::outOfRange; break;
    case E::extraData: error = ConfigFileError::extraData; break;
    case E::ioError: error = ConfigFileError::readFailed; break;
    default: error = ConfigFileError::readFailed;
    }
    return {error, result.line};
}
ConfigFileResult configOpenError(const std::filesystem::path &path)
{
    unsigned long systemError = 0;
    _get_doserrno(&systemError);
    const DWORD attributes = GetFileAttributesW(path.c_str());
    if (attributes == INVALID_FILE_ATTRIBUTES)
    {
        const DWORD error = GetLastError();
        if (error == ERROR_FILE_NOT_FOUND || error == ERROR_PATH_NOT_FOUND)
            return {ConfigFileError::missingFile, 0, 0, error};
        return {ConfigFileError::openFailed, 0, 0, error};
    }
    return {ConfigFileError::openFailed, 0, 0, systemError};
}
namespace
{
struct TemporaryFile
{
    ConfigFileApi api;
    std::filesystem::path path;
    HANDLE handle = INVALID_HANDLE_VALUE;
    bool owned = false;
    ConfigFileResult discard(ConfigFileResult result)
    {
        if (handle != INVALID_HANDLE_VALUE)
        {
            if (!api.close(handle))
            {
                result.cleanupSystemError = GetLastError();
                result.temporaryFile = path;
                return result;
            }
            handle = INVALID_HANDLE_VALUE;
        }
        if (owned)
        {
            if (api.remove(path.c_str())) owned = false;
            else
            {
                result.cleanupSystemError = GetLastError();
                result.temporaryFile = path;
            }
        }
        return result;
    }
    ~TemporaryFile()
    {
        if (handle != INVALID_HANDLE_VALUE) api.close(handle);
        if (owned) api.remove(path.c_str());
    }
};
ConfigFileResult failure(ConfigFileError error)
{
    return {error, 0, 0, GetLastError()};
}
}
ConfigFileResult saveConfigFile(const std::filesystem::path &path,
                               const std::function<bool(std::ostream &)> &serialize, ConfigFileApi api)
{
    std::ostringstream output;
    if (!serialize(output) || !output) return {ConfigFileError::invalidConfig};
    const auto text = output.str();
    std::string bytes;
    bytes.reserve(text.size());
    for (char ch : text)
    {
        if (ch == '\n') bytes += '\r';
        bytes += ch;
    }
    static std::atomic<unsigned long> sequence{0};
    TemporaryFile temporary{api};
    for (unsigned attempt = 0; attempt < 100; ++attempt)
    {
        temporary.path = path;
        temporary.path += L".tmp-" + std::to_wstring(GetCurrentProcessId()) + L"-" +
                          std::to_wstring(sequence.fetch_add(1));
        temporary.handle = api.create(temporary.path.c_str(), GENERIC_WRITE, 0, nullptr,
                                       CREATE_NEW, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (temporary.handle != INVALID_HANDLE_VALUE) { temporary.owned = true; break; }
        if (GetLastError() != ERROR_FILE_EXISTS && GetLastError() != ERROR_ALREADY_EXISTS)
            return failure(ConfigFileError::createFailed);
    }
    if (!temporary.owned) return failure(ConfigFileError::createFailed);
    auto abort = [&](ConfigFileResult result) { return temporary.discard(std::move(result)); };
    size_t position = 0;
    while (position < bytes.size())
    {
        const DWORD size = static_cast<DWORD>((std::min)(bytes.size() - position,
            size_t((std::numeric_limits<DWORD>::max)())));
        DWORD written = 0;
        if (!api.write(temporary.handle, bytes.data() + position, size, &written, nullptr))
            return abort(failure(ConfigFileError::writeFailed));
        if (!written) return abort({ConfigFileError::writeFailed, 0, 0, ERROR_WRITE_FAULT});
        position += written;
    }
    if (!api.flush(temporary.handle)) return abort(failure(ConfigFileError::flushFailed));
    if (!api.close(temporary.handle)) return abort(failure(ConfigFileError::closeFailed));
    temporary.handle = INVALID_HANDLE_VALUE;
    if (!api.replace(temporary.path.c_str(), path.c_str(), MOVEFILE_REPLACE_EXISTING))
        return abort(failure(ConfigFileError::replaceFailed));
    temporary.owned = false;
    return {};
}
} // namespace app
