#pragma once
#include <Windows.h>
#include "../generated/RuntimeLayout2026.h"
#include "../generated/InjectionNames2026.h"
#include <array>
#include <cstdint>
#include <type_traits>
#include <stdexcept>
#include <vector>
#include <string>
#include <functional>
#include "../model/ParameterConfig.h"
#include "../model/CityConfig.h"
#include "../model/SkillConfig.h"
#include "../model/FormationConfig.h"
#include "../model/PersonConfig.h"
#include "../model/PersonSnapshot.h"
#include "GameSnapshots2026.h"

struct ProcessApi2026 {
    decltype(&::FindWindowA) findWindow = ::FindWindowA;
    decltype(&::GetWindowThreadProcessId) windowProcess = ::GetWindowThreadProcessId;
    decltype(&::OpenProcess) openProcess = ::OpenProcess;
    decltype(&::CloseHandle) closeHandle = ::CloseHandle;
    decltype(&::VirtualAllocEx) allocate = ::VirtualAllocEx;
    decltype(&::VirtualFreeEx) release = ::VirtualFreeEx;
    decltype(&::VirtualProtectEx) protect = ::VirtualProtectEx;
    decltype(&::ReadProcessMemory) read = ::ReadProcessMemory;
    decltype(&::WriteProcessMemory) write = ::WriteProcessMemory;
    decltype(&::FlushInstructionCache) flush = ::FlushInstructionCache;
    decltype(&::RegisterWindowMessageA) registerMessage = ::RegisterWindowMessageA;
    decltype(&::VirtualQueryEx) query = ::VirtualQueryEx;
    decltype(&::GetProcessId) processId = ::GetProcessId;
    decltype(&::GetProcessTimes) processTimes = ::GetProcessTimes;
    decltype(&::WaitForSingleObject) wait = ::WaitForSingleObject;
};
// 0x409E10 dispatch; message-related names follow the host entry points,
// not an inferred game action. Values remain the recovered ABI values.
enum class ModifyReason2026 : int { TimerTick=1, GameNotification=2, GameDialogClosed=3, ParametersConfirmed=4 };

enum class SessionPhase2026 { Idle, Active, Applying, RollingBack, RecoveryRequired };
enum class OperationResult2026 { None, Committed, RolledBack, RecoveryRequired, Undone, ProcessExited };
enum class ProcessState2026 { None, Alive, Exited, Unavailable, IdentityChanged };
struct ProcessIdentity2026 {
    DWORD pid = 0;
    FILETIME created{};
    HWND window = nullptr;
    bool verified = false;
};
enum class ChangeKind2026 { Handle, Allocation, Protection, Bytes };
struct Change2026 {
    ChangeKind2026 kind;
    HANDLE process = nullptr;
    LPVOID address = nullptr;
    SIZE_T size = 0;
    DWORD protection = 0;
    std::vector<BYTE> before;
    SIZE_T transferred = 0;
    bool completed = false;
};
// Successful operations retain only first-observed bytes within each resource epoch.
// Build a new journal so allocation failure never damages the rollback history.
std::vector<Change2026> compactCommittedChanges2026(const std::vector<Change2026>& changes);
struct RuntimeSession2026 {
    SessionPhase2026 phase = SessionPhase2026::Idle;
    OperationResult2026 result = OperationResult2026::None;
    HANDLE process = nullptr;
    std::vector<Change2026> changes;
    ProcessIdentity2026 identity;
    ProcessState2026 processState = ProcessState2026::None;
    size_t boundary = 0;
    std::string failure;
    std::string recoveryFailure;
};
enum class RuntimeStatusKind2026 {
    None, Connected, WaitingForGame, OpenFailed, UnsupportedVersion, AllocationFailed,
    WriteFailed, ExitCleanupFailed, ProcessExited, IdentityUnavailable,
    RecoveryRequired, Restored, ModificationBlocked, ModificationRolledBack, ExceptionRolledBack
};
struct RuntimeStatus2026 {
    RuntimeStatusKind2026 kind = RuntimeStatusKind2026::None;
    DWORD errorCount = 0;
    DWORD writeStage = 0;
    DWORD systemError = 0;
    unsigned activityDots = 0;
};
struct ConfigurationState2026 {
    bool cityAutomatic = false;
    bool cityPending = false;
    bool skillLoaded = false;
    bool skillPending = false;
    bool formationLoaded = false;
    bool formationPending = false;
};
struct RuntimeTestAccess2026;
// Offset-addressed x86 state recovered from the 2026 binary, independent of MFC.
// Only this translation layer exposes offsets; dialogs exchange typed values.
class Runtime2026 final {
public:
    explicit Runtime2026(ProcessApi2026 api = {});
    Runtime2026(const Runtime2026&) = delete;
    Runtime2026& operator=(const Runtime2026&) = delete;
    // The endpoint is the game callback ABI, never a GUI control to update.
    void setCallbackWindow(HWND endpoint);
    bool isGameMessage(UINT message) const;
    bool handleGameMessage(UINT message, WPARAM action, LPARAM argument);
    const RuntimeStatus2026& status() const { return status_; }
    ConfigurationState2026 configurationState() const;
    void setConfigurationState(const ConfigurationState2026& state);
    void modify(ModifyReason2026 reason);
    bool togglePlayerForce(unsigned index);
    bool undo();
    bool retryRollback();
    bool hasGameSession() const {
        return session_.phase == SessionPhase2026::Active && session_.process != nullptr
            && session_.processState == ProcessState2026::Alive;
    }
    bool readPersonSnapshot(san9::PersonSnapshot& snapshot);
    bool readCitySnapshot(CitySnapshot2026& snapshot);
    bool readSkillSnapshot(SkillSnapshot2026& snapshot);
    bool readFormationSnapshot(FormationSnapshot2026& snapshot);
    bool readPlayerForces(std::vector<PlayerForce2026>& forces);
    const RuntimeSession2026& session() const { return session_; }
    void setSkipDurabilitySiegeSelection(bool enabled) { skipDurabilitySiegeSelection_ = enabled; }
    void setParameters(const san9::ParameterConfig& parameters);
    san9::PersonConfig personConfig() const;
    void setPersonConfig(const san9::PersonConfig& config);
    san9::FormationConfig formationConfig() const;
    void setFormationConfig(const san9::FormationConfig& config);
    san9::SkillConfig skillConfig() const;
    void setSkillConfig(const san9::SkillConfig& config);
    san9::CityConfig cityConfig() const;
    void setCityConfig(const san9::CityConfig& config);
private:
    friend struct RuntimeTestAccess2026;
    template<class T> T& field(size_t offset) {
        checkStateRange(offset,sizeof(T));
        return *reinterpret_cast<T*>(state_.data()+offset);
    }
    void copyIn(size_t offset, const void* source, size_t size);
    void copyOut(size_t offset, void* destination, size_t size) const;
    void dataIn(DWORD address, const void* source, size_t size);
    void dataOut(DWORD address, void* destination, size_t size);
    bool readGameMemory(DWORD address, void* buffer, SIZE_T size);
    bool rebase();
    void checkStateRange(size_t offset,size_t size) const {
        if(offset>state_.size() || size>state_.size()-offset)
            throw std::out_of_range("runtime state range");
    }
    ProcessApi2026 api_;
    alignas(4) std::array<BYTE, san9::layout2026::StateSize> state_{};
    alignas(4) std::array<BYTE, 0x11000> data_{};
    RuntimeStatus2026 status_;
    RuntimeSession2026 session_;
    decltype(state_) savedState_{}, initialState_{};
    decltype(data_) savedData_{}, initialData_{};
    bool undoPending_ = false;
    bool skipDurabilitySiegeSelection_ = true; // Preserve the companion default.
    struct OperationFailure {};
    [[noreturn]] void fail(const char* operation);
    void modifyBranches(ModifyReason2026 reason);
    void applyGameConfiguration(ModifyReason2026 reason);
    void applyCityConfiguration(ModifyReason2026 reason);
    void applySkillConfiguration();
    void applyFormationConfiguration(ModifyReason2026 reason);
    void writeGameValue(DWORD target, DWORD value, SIZE_T size = sizeof(DWORD));
    bool checkVersion();
    BOOL updateZone(int enabled);
    HWND findGameWindow(LPCSTR className, LPCSTR title);
    DWORD resolveProcess(HWND window, LPDWORD pid);
    UINT registerRuntimeMessage(LPCSTR name);
    HANDLE openProcess(DWORD access, BOOL inherit, DWORD pid);
    BOOL closeProcess(HANDLE process);
    LPVOID allocateMemory(HANDLE process, LPVOID address, SIZE_T size, DWORD type, DWORD protection);
    BOOL protectMemory(HANDLE process, LPVOID address, SIZE_T size, DWORD protection, PDWORD old);
    BOOL writeBytes(HANDLE process, LPVOID target, LPCVOID source, SIZE_T size);
    bool reverseChanges(size_t boundary);
    bool runOperation(const std::function<void()>& operation);
    ProcessState2026 observeProcess();
    void requireProcess(HANDLE process);
    bool retireExitedProcess();
    void restoreSessionBaseline();
    template<class T> T* pointer(DWORD address) {
        if (address < 0x41F000 || address + sizeof(T) > 0x430000)
            throw std::out_of_range("runtime data");
        return reinterpret_cast<T*>(data_.data()+address-0x41F000);
    }
    template<class T> T& global(DWORD address) { return *pointer<T>(address); }
    void setStatus(RuntimeStatusKind2026 kind) { status_ = {}; status_.kind = kind; }
    template<class T> static std::uintptr_t addressOf(T value) {
        if constexpr (std::is_pointer_v<T>) return reinterpret_cast<std::uintptr_t>(value);
        else return static_cast<std::uintptr_t>(value);
    }
    template<class T> const BYTE* sourceVA(T value) {
        return pointer<BYTE>(static_cast<DWORD>(addressOf(value)));
    }
    template<class A, class B> BOOL writeMemory(HANDLE process, A target, B source, SIZE_T size, SIZE_T*) {
        return writeBytes(process, reinterpret_cast<LPVOID>(addressOf(target)),
            reinterpret_cast<LPCVOID>(addressOf(source)), size);
    }
    template<class A, class B> BOOL readMemory(HANDLE process, A source, B target, SIZE_T size, SIZE_T*) {
        requireProcess(process);
        SIZE_T transferred = 0;
        if (!api_.read(process, reinterpret_cast<LPCVOID>(addressOf(source)),
            reinterpret_cast<LPVOID>(addressOf(target)), size, &transferred) || transferred != size)
            fail("read");
        return TRUE;
    }
};
