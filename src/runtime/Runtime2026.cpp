#include "Runtime2026.h"
#include "../model/PatchImage.h"
#include <algorithm>
#include <cstring>
#include <map>
#include <limits>

std::vector<Change2026> compactCommittedChanges2026(const std::vector<Change2026>& changes) {
    std::vector<Change2026> result;
    std::map<std::uintptr_t, std::uintptr_t> covered;
    HANDLE process = nullptr;
    for (const auto& entry : changes) {
        if (!entry.completed) throw std::logic_error("cannot compact an unfinished operation");
        if (entry.kind != ChangeKind2026::Bytes) {
            result.push_back(entry);
            // Never move restoration across protection, allocation or handle ownership.
            covered.clear();
            process = nullptr;
            continue;
        }
        if (entry.process != process) { covered.clear(); process = entry.process; }
        const auto begin = reinterpret_cast<std::uintptr_t>(entry.address);
        if (entry.size > (std::numeric_limits<std::uintptr_t>::max)() - begin
            || entry.before.size() != entry.size)
            throw std::logic_error("invalid journal byte range");
        const std::uintptr_t end = begin + static_cast<std::uintptr_t>(entry.size);
        auto cursor = begin;
        auto range = covered.lower_bound(begin);
        if (range != covered.begin() && std::prev(range)->second >= begin) --range;
        auto append = [&](std::uintptr_t first, std::uintptr_t last) {
            if (first == last) return;
            Change2026 retained{ChangeKind2026::Bytes, entry.process,
                reinterpret_cast<LPVOID>(first), last-first};
            retained.before.assign(entry.before.begin() + (first-begin), entry.before.begin() + (last-begin));
            retained.transferred = retained.size;
            retained.completed = true;
            result.push_back(std::move(retained));
        };
        auto mergedBegin = begin;
        auto mergedEnd = end;
        while (range != covered.end() && range->first <= mergedEnd) {
            const auto gapEnd = (std::min)(end, range->first);
            if (cursor < gapEnd) append(cursor, gapEnd);
            cursor = (std::max)(cursor, range->second);
            mergedBegin = (std::min)(mergedBegin, range->first);
            mergedEnd = (std::max)(mergedEnd, range->second);
            range = covered.erase(range);
        }
        if (cursor < end) append(cursor, end);
        covered.emplace(mergedBegin, mergedEnd);
    }
    return result;
}

// Fail the build if model encoding and the recovered layout ever drift.
static_assert(san9::PersonConfig::Count*4 == san9::layout2026::PersonLevelsSize);
static_assert(san9::PersonConfig::FriendshipCount*6 == san9::layout2026::PersonFriendshipsSize);
static_assert(san9::CityConfig::Count*san9::CityConfig::RecordSize == san9::layout2026::CityLimitsSize);
static_assert(san9::SkillConfig::Bytes{}.size() == san9::layout2026::SkillEntriesSize);
static_assert(san9::FormationConfig::Bytes{}.size() == san9::layout2026::FormationEntriesSize);
static_assert(sizeof(WORD) == san9::layout2026::MaxExperienceSize);
static_assert(sizeof(DWORD) == san9::layout2026::CityAutomaticSize && sizeof(DWORD) == san9::layout2026::CityPendingSize);
static_assert(sizeof(BYTE) == san9::layout2026::SkillFlagsSize && sizeof(BYTE) == san9::layout2026::FormationFlagsSize);

[[noreturn]] void Runtime2026::fail(const char* operation) {
    session_.failure = operation;
    throw OperationFailure{};
}
ProcessState2026 Runtime2026::observeProcess() {
    auto state = ProcessState2026::None;
    if (session_.process) {
        FILETIME created{}, exited{}, kernel{}, user{};
        const DWORD pid = api_.processId(session_.process);
        if (!pid || !api_.processTimes(session_.process, &created, &exited, &kernel, &user))
            state = ProcessState2026::Unavailable;
        else if (!session_.identity.verified || pid != session_.identity.pid
            || created.dwLowDateTime != session_.identity.created.dwLowDateTime
            || created.dwHighDateTime != session_.identity.created.dwHighDateTime)
            state = ProcessState2026::IdentityChanged;
        else {
            const DWORD wait = api_.wait(session_.process, 0);
            state = wait == WAIT_OBJECT_0 ? ProcessState2026::Exited
                : wait == WAIT_TIMEOUT ? ProcessState2026::Alive : ProcessState2026::Unavailable;
        }
    }
    session_.processState = state;
    return state;
}
void Runtime2026::requireProcess(HANDLE process) {
    if (!process || process != session_.process || observeProcess() != ProcessState2026::Alive)
        fail("process is not the live session target");
}
void Runtime2026::restoreSessionBaseline() {
    // Keep user inputs; discard game addresses, version-derived data and event state.
    const auto inputs = state_;
    std::array<BYTE, 450> inputData{};
    dataOut(0x42D948, inputData.data(), 400);
    dataOut(0x42DAD8, inputData.data()+400, 50);
    state_ = initialState_;
    data_ = initialData_;
    for (const auto& field : san9::ParameterConfig::fields())
        copyIn(field.hostOffset, inputs.data()+field.hostOffset, sizeof(std::int32_t));
    for (const auto& span : san9::layout2026::LifecyclePreserveSpans)
        copyIn(span.offset,inputs.data()+span.offset,span.size);
    for (const auto& span : san9::layout2026::ConfigurationSpans)
        copyIn(span.offset,inputs.data()+span.offset,span.size);
    dataIn(0x42D948, inputData.data(), 400);
    dataIn(0x42DAD8, inputData.data()+400, 50);
    for (const auto& span : san9::layout2026::LifecycleResetSpans)
        std::fill_n(state_.data()+span.offset,span.size,BYTE{0});
    if (field<DWORD>(san9::layout2026::CityAutomatic)) field<DWORD>(san9::layout2026::CityPending)=1;
    if (field<BYTE>(san9::layout2026::SkillFlags)&1) field<BYTE>(san9::layout2026::SkillFlags)|=2;
    if (field<BYTE>(san9::layout2026::FormationFlags)&1) field<BYTE>(san9::layout2026::FormationFlags)|=2;
}
bool Runtime2026::retireExitedProcess() {
    // Only a signaled handle with the captured identity proves the address space is gone.
    if (observeProcess() != ProcessState2026::Exited) return false;
    if (!api_.closeHandle(session_.process)) {
        session_.phase = SessionPhase2026::RecoveryRequired;
        session_.result = OperationResult2026::RecoveryRequired;
        session_.recoveryFailure = "close exited process";
        setStatus(RuntimeStatusKind2026::ExitCleanupFailed);
        return false;
    }
    restoreSessionBaseline();
    session_.changes.clear();
    session_.boundary = 0;
    session_.process = nullptr;
    session_.identity = {};
    session_.processState = ProcessState2026::None;
    session_.phase = SessionPhase2026::Idle;
    session_.result = OperationResult2026::ProcessExited;
    session_.recoveryFailure.clear();
    undoPending_ = false;
    setStatus(RuntimeStatusKind2026::ProcessExited);
    return true;
}
HANDLE Runtime2026::openProcess(DWORD access, BOOL inherit, DWORD pid) {
    session_.changes.push_back({ChangeKind2026::Handle});
    auto& entry = session_.changes.back();
    entry.process = api_.openProcess(access | PROCESS_QUERY_INFORMATION | SYNCHRONIZE, inherit, pid);
    if (!entry.process) { session_.changes.pop_back(); fail("open process"); }
    entry.completed = true;
    session_.process = entry.process;
    initialState_ = savedState_; initialData_ = savedData_;
    session_.identity = {};
    session_.identity.pid = pid;
    session_.identity.window = field<HWND>(san9::layout2026::TargetWindow);
    FILETIME exited{}, kernel{}, user{};
    if (api_.processId(entry.process) != pid
        || !api_.processTimes(entry.process, &session_.identity.created, &exited, &kernel, &user))
        fail("capture process identity");
    session_.identity.verified = true;
    requireProcess(entry.process);
    DWORD windowPid = 0;
    if (!api_.windowProcess(session_.identity.window, &windowPid) || windowPid != pid)
        fail("window changed while connecting");
    return entry.process;
}
HWND Runtime2026::findGameWindow(LPCSTR className, LPCSTR title) {
    const auto window = api_.findWindow(className, title);
    if (session_.process) {
        requireProcess(session_.process);
        DWORD pid = 0;
        if (!window || !api_.windowProcess(window, &pid) || pid != session_.identity.pid)
            fail("game window changed");
        session_.identity.window = window;
        field<HWND>(san9::layout2026::TargetWindow) = window;
    }
    return window;
}
DWORD Runtime2026::resolveProcess(HWND window, LPDWORD pid) {
    *pid = 0;
    const auto thread = api_.windowProcess(window, pid);
    if (!thread || !*pid) fail("resolve process");
    return thread;
}
UINT Runtime2026::registerRuntimeMessage(LPCSTR name) {
    const auto message = api_.registerMessage(name);
    if (!message) fail("register message");
    return message;
}
BOOL Runtime2026::closeProcess(HANDLE process) {
    // Only the version-rejection path closes from generated code, before edits.
    if (session_.changes.empty() || session_.changes.back().kind != ChangeKind2026::Handle)
        fail("close with pending changes");
    if (!api_.closeHandle(process)) fail("close process");
    session_.changes.pop_back();
    session_.process = nullptr;
    session_.identity = {};
    session_.processState = ProcessState2026::None;
    return TRUE;
}
LPVOID Runtime2026::allocateMemory(HANDLE process, LPVOID address, SIZE_T size, DWORD, DWORD protection) {
    requireProcess(process);
    session_.changes.push_back({ChangeKind2026::Allocation, process, nullptr, size});
    auto& entry = session_.changes.back();
    entry.address = api_.allocate(process, address, size, MEM_RESERVE | MEM_COMMIT, protection);
    if (!entry.address) { session_.changes.pop_back(); fail("allocate"); }
    entry.completed = true;
    return entry.address;
}
BOOL Runtime2026::protectMemory(HANDLE process, LPVOID address, SIZE_T size, DWORD protection, PDWORD old) {
    SYSTEM_INFO info{};
    GetSystemInfo(&info);
    const auto page = static_cast<std::uintptr_t>(info.dwPageSize);
    auto cursor = reinterpret_cast<std::uintptr_t>(address) & ~(page - 1);
    const auto end = (reinterpret_cast<std::uintptr_t>(address) + size + page - 1) & ~(page - 1);
    bool first = true;
    while (cursor < end) {
        requireProcess(process);
        MEMORY_BASIC_INFORMATION region{};
        if (!api_.query(process, reinterpret_cast<LPCVOID>(cursor), &region, sizeof(region))) fail("query protection");
        const auto limit = (std::min)(end, reinterpret_cast<std::uintptr_t>(region.BaseAddress) + region.RegionSize);
        if (limit <= cursor || region.State != MEM_COMMIT) fail("invalid protection region");
        requireProcess(process);
        session_.changes.push_back({ChangeKind2026::Protection, process, reinterpret_cast<LPVOID>(cursor), limit-cursor});
        auto& entry = session_.changes.back();
        if (!api_.protect(process, entry.address, entry.size, protection, &entry.protection)) {
            session_.changes.pop_back(); fail("protect");
        }
        entry.completed = true;
        if (first) { *old = entry.protection; first = false; }
        cursor = limit;
    }
    return TRUE;
}
BOOL Runtime2026::writeBytes(HANDLE process, LPVOID target, LPCVOID source, SIZE_T size) {
    requireProcess(process);
    Change2026 entry{ChangeKind2026::Bytes, process, target, size};
    entry.before.resize(size);
    SIZE_T read = 0;
    if (!api_.read(process, target, entry.before.data(), size, &read) || read != size) fail("read original bytes");
    requireProcess(process);
    // Persist BEFORE attempting the write: FALSE and short writes can both mutate memory.
    session_.changes.push_back(std::move(entry));
    auto& pending = session_.changes.back();
    if (!api_.write(process, target, source, size, &pending.transferred) || pending.transferred != size) fail("write");
    requireProcess(process);
    if (!api_.flush(process, target, size)) fail("flush");
    pending.completed = true;
    return TRUE;
}
bool Runtime2026::reverseChanges(size_t boundary) {
    session_.phase = SessionPhase2026::RollingBack;
    session_.recoveryFailure.clear();
    while (session_.changes.size() > boundary) {
        if (session_.identity.verified) {
            const auto state = observeProcess();
            if (state == ProcessState2026::Exited) return retireExitedProcess();
            if (state != ProcessState2026::Alive) {
                session_.phase = SessionPhase2026::RecoveryRequired;
                session_.result = OperationResult2026::RecoveryRequired;
                session_.recoveryFailure = "cannot verify recovery target";
                setStatus(RuntimeStatusKind2026::IdentityUnavailable);
                return false;
            }
        }
        const auto& entry = session_.changes.back();
        bool ok = false;
        SIZE_T transferred = 0;
        DWORD ignored = 0;
        switch (entry.kind) {
        case ChangeKind2026::Bytes:
            ok = api_.write(entry.process, entry.address, entry.before.data(), entry.size, &transferred)
                && transferred == entry.size && observeProcess() == ProcessState2026::Alive
                && api_.flush(entry.process, entry.address, entry.size);
            if (!ok) session_.recoveryFailure = "restore bytes/flush";
            break;
        case ChangeKind2026::Protection:
            ok = api_.protect(entry.process, entry.address, entry.size, entry.protection, &ignored) != FALSE;
            if (!ok) session_.recoveryFailure = "restore protection";
            break;
        case ChangeKind2026::Allocation:
            ok = api_.release(entry.process, entry.address, 0, MEM_RELEASE) != FALSE;
            if (!ok) session_.recoveryFailure = "release allocation";
            break;
        case ChangeKind2026::Handle:
            ok = api_.closeHandle(entry.process) != FALSE;
            if (ok) { session_.process = nullptr; session_.identity = {}; session_.processState = ProcessState2026::None; }
            else session_.recoveryFailure = "close process";
            break;
        }
        if (!ok) {
            if (observeProcess() == ProcessState2026::Exited) return retireExitedProcess();
            session_.phase = SessionPhase2026::RecoveryRequired;
            session_.result = OperationResult2026::RecoveryRequired;
            setStatus(RuntimeStatusKind2026::RecoveryRequired);
            return false;
        }
        session_.changes.pop_back();
    }
    return true;
}
bool Runtime2026::retryRollback() {
    if (session_.process && observeProcess() == ProcessState2026::Exited) return retireExitedProcess();
    if (session_.phase != SessionPhase2026::RecoveryRequired) return true;
    if (session_.process && session_.identity.verified && session_.processState != ProcessState2026::Alive) {
        session_.result = OperationResult2026::RecoveryRequired;
        session_.recoveryFailure = "cannot verify recovery target";
        setStatus(RuntimeStatusKind2026::IdentityUnavailable);
        return false;
    }
    if (!reverseChanges(session_.boundary)) return false;
    if (session_.result == OperationResult2026::ProcessExited) return true;
    if (undoPending_) restoreSessionBaseline();
    else { state_ = savedState_; data_ = savedData_; }
    session_.phase = session_.process ? SessionPhase2026::Active : SessionPhase2026::Idle;
    session_.result = undoPending_ ? OperationResult2026::Undone : OperationResult2026::RolledBack;
    undoPending_ = false;
    setStatus(RuntimeStatusKind2026::Restored);
    return true;
}
void Runtime2026::modify(ModifyReason2026 reason) {
    if (session_.process) {
        if (observeProcess() == ProcessState2026::Exited) { retireExitedProcess(); return; }
        if (session_.phase == SessionPhase2026::Active && session_.processState == ProcessState2026::Alive) {
            const auto window = api_.findWindow(pointer<char>(0x42EDD4), nullptr);
            DWORD pid = 0;
            if (window && api_.windowProcess(window, &pid) && pid && pid != session_.identity.pid) {
                undo(); // Finish the old session before ever opening the replacement.
                return;
            }
        }
    }
    const bool updateExtension = hasGameSession() && reason==ModifyReason2026::ParametersConfirmed;
    runOperation([&] {
        modifyBranches(reason);
        // The recovered patch site is in the initial-connection branch only.
        // Live confirmation must update it in the same rollback transaction.
        if (updateExtension && session_.process) {
            const BYTE instruction = skipDurabilitySiegeSelection_ ? 0x33 : 0x85;
            writeMemory(session_.process, 0x4B87EBu, &instruction, 1, nullptr);
        }
    });
}
bool Runtime2026::readGameMemory(DWORD address, void* buffer, SIZE_T size) {
    if (session_.process && observeProcess() == ProcessState2026::Exited) { retireExitedProcess(); return false; }
    if (!hasGameSession()) return false;
    try { return readMemory(session_.process, address, buffer, size, nullptr) != FALSE; }
    catch (const OperationFailure&) {
        if (observeProcess() == ProcessState2026::Exited) retireExitedProcess();
        return false;
    }
}
bool Runtime2026::togglePlayerForce(unsigned index) {
    if (index >= 50 || session_.phase != SessionPhase2026::Active) return false;
    return runOperation([&] {
        findGameWindow(pointer<char>(0x42EDD4), nullptr);
        const DWORD address = 0x1253C38 + index * 0xD4 + 0x34;
        BYTE flag = 0;
        readMemory(session_.process, address, &flag, 1, nullptr);
        flag ^= 1;
        writeMemory(session_.process, address, &flag, 1, nullptr);
    });
}
bool Runtime2026::runOperation(const std::function<void()>& operation) {
    if (session_.phase == SessionPhase2026::Applying || session_.phase == SessionPhase2026::RollingBack)
        return false;
    if (session_.phase == SessionPhase2026::RecoveryRequired) {
        setStatus(RuntimeStatusKind2026::ModificationBlocked);
        return false;
    }
    savedState_ = state_;
    savedData_ = data_;
    session_.boundary = session_.changes.size();
    session_.failure.clear();
    session_.result = OperationResult2026::None;
    session_.phase = SessionPhase2026::Applying;
    try {
        if (session_.process) requireProcess(session_.process);
        operation();
        if (session_.process) requireProcess(session_.process);
        if (session_.boundary == 0 && !session_.changes.empty()) {
            initialState_ = savedState_; initialData_ = savedData_;
        }
        // Keep operation history intact until this succeeds. Any exception still
        // rolls back the complete operation to the preceding committed baseline.
        if (session_.changes.size() != session_.boundary) {
            auto committed = compactCommittedChanges2026(session_.changes);
            session_.changes.swap(committed);
        }
        session_.boundary = session_.changes.size();
        session_.phase = session_.process ? SessionPhase2026::Active : SessionPhase2026::Idle;
        session_.result = OperationResult2026::Committed;
    } catch (const OperationFailure&) {
        session_.phase = SessionPhase2026::RecoveryRequired;
        retryRollback();
        if (session_.result == OperationResult2026::RolledBack)
            setStatus(RuntimeStatusKind2026::ModificationRolledBack);
    } catch (...) {
        session_.failure = "runtime exception";
        session_.phase = SessionPhase2026::RecoveryRequired;
        retryRollback();
        if (session_.result == OperationResult2026::RolledBack)
            setStatus(RuntimeStatusKind2026::ExceptionRolledBack);
    }
    return session_.result == OperationResult2026::Committed;
}
bool Runtime2026::undo() {
    if (session_.process && observeProcess() == ProcessState2026::Exited) return retireExitedProcess();
    if (!retryRollback()) return false;
    if (session_.changes.empty()) { session_.result = OperationResult2026::Undone; return true; }
    savedState_ = initialState_; savedData_ = initialData_;
    session_.boundary = 0;
    undoPending_ = true;
    session_.phase = SessionPhase2026::RecoveryRequired;
    return retryRollback();
}

static_assert(sizeof(void*) == 4, "2026 runtime requires Win32");

Runtime2026::Runtime2026(ProcessApi2026 api): api_(api) {
    static constexpr BYTE seed[] = {
#include "../generated/companion_data.inc"
    };
    std::copy(std::begin(seed), std::end(seed), data_.begin());
#include "../generated/StateConstants.inc"
    constexpr DWORD offsets[] = {7620,3700,4720,4724,4828,4832,5212};
    constexpr DWORD values[] = {0xA31B0,0xA4000,0xA5662,0xA5630,0xA6E00,0xA3CC0,0xA1AE0};
    for (size_t i=0; i<std::size(offsets); ++i) field<DWORD>(offsets[i]) = values[i];
    for (size_t i=0;i<san9::PersonConfig::Count;++i) field<DWORD>(san9::layout2026::PersonLevels+4*i)=0x3FEAA;
    field<WORD>(san9::layout2026::MaxExperience)=1500;
    field<DWORD>(san9::injection2026::PersonFriendshipAddress)=0x610740;
    copyIn(san9::layout2026::PersonFriendships, pointer<BYTE>(0x42DB28), 58*6);
    std::fill_n(pointer<BYTE>(0x42DC84), 58*6, BYTE{0});
    std::fill_n(state_.data()+san9::injection2026::InitialCityMaxSoldier,50,BYTE{50});
    std::fill_n(state_.data()+san9::injection2026::InitialCityMaxPeopleHeart,50,BYTE{10});
    for (DWORD i=0;i<50;++i) global<BYTE>(0x42DAD8+i) += 2;
    const auto limits = san9::CityConfig{}.encodeLimits();
    copyIn(san9::layout2026::CityLimits, limits.data(), limits.size());
    setSkillConfig(san9::SkillConfig{});
    setFormationConfig(san9::FormationConfig{});
    setParameters(san9::ParameterConfig{});
}
void Runtime2026::setCallbackWindow(HWND owner) {
    field<HWND>(san9::layout2026::OwnerWindow)=owner;
    field<UINT>(san9::layout2026::MessageId)=api_.registerMessage("San9PKHard");
    field<DWORD>(san9::layout2026::CallbackReturnStub)=0xC3C3C3C3;
}
bool Runtime2026::isGameMessage(UINT message) const {
    UINT registered = 0;
    copyOut(san9::layout2026::MessageId, &registered, sizeof(registered));
    return registered != 0 && message == registered && hasGameSession();
}
bool Runtime2026::handleGameMessage(UINT message, WPARAM action, LPARAM argument) {
    if (!isGameMessage(message)) return false;
    auto& sequence = field<DWORD>(san9::layout2026::EventSequence);
    if (!sequence) {
        if (action == 1 && argument) modify(ModifyReason2026::GameNotification);
        else if (action == 2 && argument == 1020) sequence = 1;
    } else if (sequence == 1 && action == 2) {
        if (argument == 0) { modify(ModifyReason2026::GameDialogClosed); sequence = 0; }
        else if (argument == 1003) sequence = 0;
    }
    return true;
}
ConfigurationState2026 Runtime2026::configurationState() const {
    DWORD automatic = 0, pending = 0;
    BYTE skill = 0, formation = 0;
    copyOut(san9::layout2026::CityAutomatic, &automatic, sizeof(automatic));
    copyOut(san9::layout2026::CityPending, &pending, sizeof(pending));
    copyOut(san9::layout2026::SkillFlags, &skill, sizeof(skill));
    copyOut(san9::layout2026::FormationFlags, &formation, sizeof(formation));
    return {automatic != 0, pending != 0, (skill & 1) != 0, (skill & 2) != 0,
        (formation & 1) != 0, (formation & 2) != 0};
}
void Runtime2026::setConfigurationState(const ConfigurationState2026& state) {
    field<DWORD>(san9::layout2026::CityAutomatic) = state.cityAutomatic ? 1 : 0;
    field<DWORD>(san9::layout2026::CityPending) = state.cityPending ? 1 : 0;
    field<BYTE>(san9::layout2026::SkillFlags) = BYTE((state.skillLoaded ? 1 : 0) | (state.skillPending ? 2 : 0));
    field<BYTE>(san9::layout2026::FormationFlags) = BYTE((state.formationLoaded ? 1 : 0) | (state.formationPending ? 2 : 0));
}
void Runtime2026::copyIn(size_t offset, const void* source, size_t size) {
    checkStateRange(offset,size);
    std::memcpy(state_.data()+offset,source,size);
}
void Runtime2026::copyOut(size_t offset, void* destination, size_t size) const {
    checkStateRange(offset,size);
    std::memcpy(destination,state_.data()+offset,size);
}
void Runtime2026::dataIn(DWORD address, const void* source, size_t size) {
    if (address<0x41F000 || address>0x430000 || size>0x430000-address) throw std::out_of_range("data copy in");
    std::memcpy(pointer<BYTE>(address),source,size);
}
void Runtime2026::dataOut(DWORD address, void* destination, size_t size) {
    if (address<0x41F000 || address>0x430000 || size>0x430000-address) throw std::out_of_range("data copy out");
    std::memcpy(destination,pointer<BYTE>(address),size);
}
void Runtime2026::setParameters(const san9::ParameterConfig& parameters) {
    if (parameters.validate().error != san9::ParameterError::none)
        throw std::invalid_argument("Invalid parameter configuration");
    for (const auto& f:san9::ParameterConfig::fields()) field<std::int32_t>(f.hostOffset)=parameters.get(f.controlId);
}
san9::PersonConfig Runtime2026::personConfig() const {
    san9::PersonConfig config;san9::PersonConfig::LevelBytes levels{};san9::PersonConfig::FriendshipBytes friendships{};
    copyOut(san9::layout2026::PersonLevels,levels.data(),levels.size());copyOut(san9::layout2026::PersonFriendships,friendships.data(),friendships.size());
    WORD maximum=0;copyOut(san9::layout2026::MaxExperience,&maximum,sizeof(maximum));config.decode(levels,friendships,maximum);return config;
}
void Runtime2026::setPersonConfig(const san9::PersonConfig& config) {
    const auto levels=config.encodeLevels();const auto friendships=config.encodeFriendships();
    copyIn(san9::layout2026::PersonLevels,levels.data(),levels.size());copyIn(san9::layout2026::PersonFriendships,friendships.data(),friendships.size());
    field<WORD>(san9::layout2026::MaxExperience)=config.maxExperience;
}
san9::FormationConfig Runtime2026::formationConfig() const {
    san9::FormationConfig config;san9::FormationConfig::Bytes bytes{};
    copyOut(san9::layout2026::FormationEntries,bytes.data(),bytes.size());config.decode(bytes);return config;
}
void Runtime2026::setFormationConfig(const san9::FormationConfig& config) {
    const auto bytes=config.encode();copyIn(san9::layout2026::FormationEntries,bytes.data(),bytes.size());
}
san9::SkillConfig Runtime2026::skillConfig() const {
    san9::SkillConfig config;san9::SkillConfig::Bytes bytes{};
    copyOut(san9::layout2026::SkillEntries,bytes.data(),bytes.size());config.decode(bytes);return config;
}
void Runtime2026::setSkillConfig(const san9::SkillConfig& config) {
    const auto bytes=config.encode();copyIn(san9::layout2026::SkillEntries,bytes.data(),bytes.size());
}
san9::CityConfig Runtime2026::cityConfig() const {
    san9::CityConfig config;
    std::array<BYTE, san9::CityConfig::Count * san9::CityConfig::RecordSize> limits{};
    copyOut(san9::layout2026::CityLimits,limits.data(),limits.size());
    config.decodeLimits(limits);
    std::memcpy(config.relations.data(),data_.data()+0x42D948-0x41F000,400);
    std::memcpy(config.attackDays.data(),data_.data()+0x42DAD8-0x41F000,50);
    return config;
}
void Runtime2026::setCityConfig(const san9::CityConfig& config) {
    const auto limits=config.encodeLimits();
    copyIn(san9::layout2026::CityLimits,limits.data(),limits.size());
    dataIn(0x42D948,config.relations.data(),400);
    dataIn(0x42DAD8,config.attackDays.data(),50);
}
bool Runtime2026::rebase() {
    static constexpr san9::Relocation relocations[] = {
#include "../generated/relocations.inc"
    };
    const DWORD base = field<DWORD>(san9::layout2026::AllocationBase);
    const DWORD delta = base-global<DWORD>(0x420050);
    if (!delta) return false;
    for (const auto& r:relocations) {
        DWORD value;
        BYTE* destination = r.objectField ? state_.data()+r.location : data_.data()+r.location-0x41F000;
        std::memcpy(&value,destination,4);
        value += delta;
        std::memcpy(destination,&value,4);
    }
    return true; // Caller updates the base slot, as in 0x409E10.
}
