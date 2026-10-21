#pragma once
#include <Windows.h>
#include <filesystem>

namespace ui
{
// Injectable OS boundary for failure tests; normal callers use the Win32 defaults.
struct PreferenceFileApi
{
    decltype(&WritePrivateProfileStringW) write = &WritePrivateProfileStringW;
    decltype(&FlushFileBuffers) flush = &FlushFileBuffers;
    decltype(&MoveFileExW) replace = &MoveFileExW;
};
bool saveExtensionPreferences(const std::filesystem::path &path, bool skipSiege,
                              bool improveRewards, bool skipAttackDelay,
                              PreferenceFileApi api = {});
}
