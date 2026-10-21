#include "Preferences.h"
#include <atomic>
#include <string>

namespace ui
{
namespace
{
struct TemporaryPreferenceFile
{
    std::filesystem::path path;
    bool owned = false;
    ~TemporaryPreferenceFile()
    {
        if (owned) DeleteFileW(path.c_str());
    }
};
}
bool saveExtensionPreferences(const std::filesystem::path &path, bool skipSiege,
                              bool improveRewards, bool skipAttackDelay, PreferenceFileApi api)
{
    // Work on a full copy so unknown keys, sections and the existing encoding survive.
    // Never try to roll back individual writes: rollback can fail for the same reason.
    TemporaryPreferenceFile temporary;
    static std::atomic<unsigned long> sequence{0};
    for (unsigned attempt = 0; attempt < 100; ++attempt)
    {
        temporary.path = path;
        temporary.path += L".tmp-" + std::to_wstring(GetCurrentProcessId()) + L"-" +
                          std::to_wstring(sequence.fetch_add(1));
        if (CopyFileW(path.c_str(), temporary.path.c_str(), TRUE))
        {
            temporary.owned = true;
            break;
        }
        const auto error = GetLastError();
        if (error == ERROR_FILE_EXISTS || error == ERROR_ALREADY_EXISTS) continue;
        if (error != ERROR_FILE_NOT_FOUND) return false;
        // A missing INI is valid on first use. Reserve an empty staging file exclusively.
        const auto handle = CreateFileW(temporary.path.c_str(), GENERIC_WRITE, 0, nullptr,
                                        CREATE_NEW, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (handle == INVALID_HANDLE_VALUE)
        {
            if (GetLastError() == ERROR_FILE_EXISTS || GetLastError() == ERROR_ALREADY_EXISTS) continue;
            return false;
        }
        temporary.owned = true;
        if (!CloseHandle(handle)) return false;
        break;
    }
    if (!temporary.owned) return false;
    const wchar_t *keys[] = {L"SkipDurabilitySiegeSelection", L"ImproveComputerRewardTiming",
                             L"SkipComputerAttackStartDelay"};
    const bool values[] = {skipSiege, improveRewards, skipAttackDelay};
    for (unsigned i = 0; i < 3; ++i)
        if (!api.write(L"Extensions", keys[i], values[i] ? L"1" : L"0", temporary.path.c_str()))
            return false;
    if (!api.write(nullptr, nullptr, nullptr, temporary.path.c_str())) return false;
    const auto handle = CreateFileW(temporary.path.c_str(), GENERIC_WRITE, 0, nullptr,
                                    OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (handle == INVALID_HANDLE_VALUE) return false;
    const bool flushed = api.flush(handle) != FALSE;
    const bool closed = CloseHandle(handle) != FALSE;
    if (!flushed || !closed) return false;
    // Same-directory rename is the only operation that changes the published file.
    if (!api.replace(temporary.path.c_str(), path.c_str(), MOVEFILE_REPLACE_EXISTING)) return false;
    temporary.owned = false;
    return true;
}
}
