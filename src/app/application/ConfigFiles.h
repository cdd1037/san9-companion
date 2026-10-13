#pragma once
#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <functional>
#include <sstream>
#include "../../model/ParameterConfig.h"
#include "../../model/PackedConfigIO.h"

namespace app
{
enum class ConfigFileError
{
    none, missingFile, openFailed, missingLine, invalidInteger, integerOverflow,
    outOfRange, extraData, readFailed, invalidConfig, createFailed, writeFailed,
    flushFailed, closeFailed, replaceFailed
};
struct ConfigFileResult
{
    ConfigFileError error = ConfigFileError::none;
    size_t line = 0;
    unsigned controlId = 0;
    DWORD systemError = 0;
    DWORD cleanupSystemError = 0;
    std::filesystem::path temporaryFile;
    bool ok() const { return error == ConfigFileError::none; }
};
ConfigFileResult configReadResult(const san9::ConfigReadResult &result);
ConfigFileResult configReadResult(const san9::PackedReadResult &result);
ConfigFileResult configOpenError(const std::filesystem::path &path);
struct ConfigFileApi
{
    decltype(&::CreateFileW) create = ::CreateFileW;
    decltype(&::WriteFile) write = ::WriteFile;
    decltype(&::FlushFileBuffers) flush = ::FlushFileBuffers;
    decltype(&::CloseHandle) close = ::CloseHandle;
    decltype(&::MoveFileExW) replace = ::MoveFileExW;
    decltype(&::DeleteFileW) remove = ::DeleteFileW;
};

template<class Config>
ConfigFileResult loadConfigFile(const std::filesystem::path &path, Config &config)
{
    std::ifstream input(path);
    if (!input) return configOpenError(path);
    return configReadResult(config.read(input));
}

// Same-directory exclusive temporary file, durable write, close, then rename.
// The target is never opened for writing. Failed saves attempt cleanup and report cleanup errors.
ConfigFileResult saveConfigFile(const std::filesystem::path &path,
                               const std::function<bool(std::ostream &)> &serialize,
                               ConfigFileApi api = {});
template<class Config>
ConfigFileResult saveConfigFile(const std::filesystem::path &path, const Config &config)
{
    return saveConfigFile(path, std::function<bool(std::ostream &)>(
        [&](std::ostream &output) { return config.write(output); }));
}
} // namespace app
