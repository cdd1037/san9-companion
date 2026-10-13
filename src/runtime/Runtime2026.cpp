#include "Runtime2026.h"
#include "../model/PatchImage.h"
#include <algorithm>
#include <cstring>

// Fail the build if model encoding and the recovered layout ever drift.
static_assert(san9::PersonConfig::Count*4 == san9::layout2026::PersonLevelsSize);
static_assert(san9::PersonConfig::FriendshipCount*6 == san9::layout2026::PersonFriendshipsSize);
static_assert(san9::CityConfig::Count*san9::CityConfig::RecordSize == san9::layout2026::CityLimitsSize);
static_assert(san9::SkillConfig::Bytes{}.size() == san9::layout2026::SkillEntriesSize);
static_assert(san9::FormationConfig::Bytes{}.size() == san9::layout2026::FormationEntriesSize);
static_assert(sizeof(WORD) == san9::layout2026::MaxExperienceSize);
static_assert(sizeof(DWORD) == san9::layout2026::CityAutomaticSize && sizeof(DWORD) == san9::layout2026::CityPendingSize);
static_assert(sizeof(BYTE) == san9::layout2026::SkillFlagsSize && sizeof(BYTE) == san9::layout2026::FormationFlagsSize);

void Runtime2026::restoreSessionBaseline() {
    ++configurationEpoch_;
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
    if (!process_.retireExited()) {
        if (process_.state().recoveryFailure.operation == RuntimeOperation2026::CloseExitedProcess)
            setStatus(RuntimeStatusKind2026::ExitCleanupFailed);
        return false;
    }
    restoreSessionBaseline();
    undoPending_ = false;
    setStatus(RuntimeStatusKind2026::ProcessExited);
    return true;
}
HANDLE Runtime2026::openProcess(DWORD access, BOOL inherit, DWORD pid) {
    const HANDLE handle = process_.acquire(access, inherit, pid, field<HWND>(san9::layout2026::TargetWindow));
    initialState_ = savedState_; initialData_ = savedData_;
    process_.verifyConnection();
    return handle;
}
HWND Runtime2026::findGameWindow(LPCSTR className, LPCSTR title) {
    const auto window = process_.findWindow(className, title);
    if (process_.state().process) field<HWND>(san9::layout2026::TargetWindow) = window;
    return window;
}
DWORD Runtime2026::resolveProcess(HWND window, LPDWORD pid) { return process_.resolve(window, pid); }
UINT Runtime2026::registerRuntimeMessage(LPCSTR name) { return process_.requireMessage(name); }
BOOL Runtime2026::closeProcess(HANDLE process) { return process_.closeRejected(process); }
LPVOID Runtime2026::allocateMemory(HANDLE process, LPVOID address, SIZE_T size, DWORD, DWORD protection) {
    return process_.allocate(process, address, size, protection);
}
BOOL Runtime2026::protectMemory(HANDLE process, LPVOID address, SIZE_T size, DWORD protection, PDWORD old) {
    return process_.protect(process, address, size, protection, old);
}
BOOL Runtime2026::writeBytes(HANDLE process, LPVOID target, LPCVOID source, SIZE_T size) {
    return process_.write(process, target, source, size);
}
bool Runtime2026::reverseChanges() {
    if (!process_.restore()) {
        const auto operation = process_.state().recoveryFailure.operation;
        setStatus(operation == RuntimeOperation2026::VerifyProcess ? RuntimeStatusKind2026::IdentityUnavailable
            : operation == RuntimeOperation2026::CloseExitedProcess ? RuntimeStatusKind2026::ExitCleanupFailed
            : RuntimeStatusKind2026::RecoveryRequired);
        return false;
    }
    if (process_.state().result == OperationResult2026::ProcessExited) {
        restoreSessionBaseline();
        undoPending_ = false;
        setStatus(RuntimeStatusKind2026::ProcessExited);
    }
    return true;
}
bool Runtime2026::retryRollback() {
    if (process_.state().process && observeProcess() == ProcessState2026::Exited) return retireExitedProcess();
    if (process_.state().phase != SessionPhase2026::RecoveryRequired) return true;
    if (!process_.canRecover()) {
        setStatus(RuntimeStatusKind2026::IdentityUnavailable);
        return false;
    }
    if (!reverseChanges()) return false;
    if (process_.state().result == OperationResult2026::ProcessExited) return true;
    if (undoPending_) restoreSessionBaseline();
    else { state_ = savedState_; data_ = savedData_; }
    process_.state().phase = process_.state().process ? SessionPhase2026::Active : SessionPhase2026::Idle;
    process_.state().result = undoPending_ ? OperationResult2026::Undone : OperationResult2026::RolledBack;
    undoPending_ = false;
    setStatus(RuntimeStatusKind2026::Restored);
    return true;
}
void Runtime2026::modify(ModifyReason2026 reason) {
    if (process_.state().process) {
        if (observeProcess() == ProcessState2026::Exited) { retireExitedProcess(); return; }
        if (process_.state().phase == SessionPhase2026::Active && process_.state().processState == ProcessState2026::Alive) {
            if (process_.replacementWindow(pointer<char>(0x42EDD4))) {
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
        if (updateExtension && process_.state().process) {
            const BYTE instruction = skipDurabilitySiegeSelection_ ? 0x33 : 0x85;
            writeMemory(process_.state().process, 0x4B87EBu, &instruction, 1, nullptr);
        }
    });
}
bool Runtime2026::readGameMemory(DWORD address, void* buffer, SIZE_T size) {
    if (process_.state().process && observeProcess() == ProcessState2026::Exited) { retireExitedProcess(); return false; }
    if (!hasGameSession()) return false;
    try { return readMemory(process_.state().process, address, buffer, size, nullptr) != FALSE; }
    catch (const ProcessOperationFailure2026&) {
        if (observeProcess() == ProcessState2026::Exited) retireExitedProcess();
        return false;
    }
}
bool Runtime2026::togglePlayerForce(unsigned index) {
    if (index >= 50 || process_.state().phase != SessionPhase2026::Active) return false;
    return runOperation([&] {
        findGameWindow(pointer<char>(0x42EDD4), nullptr);
        const DWORD address = 0x1253C38 + index * 0xD4 + 0x34;
        BYTE flag = 0;
        readMemory(process_.state().process, address, &flag, 1, nullptr);
        flag ^= 1;
        writeMemory(process_.state().process, address, &flag, 1, nullptr);
    });
}
bool Runtime2026::runOperation(const std::function<void()>& operation) {
    if (process_.state().phase == SessionPhase2026::Applying || process_.state().phase == SessionPhase2026::RollingBack)
        return false;
    if (process_.state().phase == SessionPhase2026::RecoveryRequired) {
        setStatus(RuntimeStatusKind2026::ModificationBlocked);
        return false;
    }
    savedState_ = state_;
    savedData_ = data_;
    process_.beginOperation();
    try {
        if (process_.state().process) requireProcess(process_.state().process);
        operation();
        if (process_.state().process) requireProcess(process_.state().process);
        if (process_.state().journal.boundary() == 0 && !process_.state().journal.empty()) {
            initialState_ = savedState_; initialData_ = savedData_;
        }
        // Keep operation history intact until this succeeds. Any exception still
        // rolls back the complete operation to the preceding committed baseline.
        process_.state().journal.commit();
        process_.state().phase = process_.state().process ? SessionPhase2026::Active : SessionPhase2026::Idle;
        process_.state().result = OperationResult2026::Committed;
    } catch (const ProcessOperationFailure2026&) {
        process_.state().phase = SessionPhase2026::RecoveryRequired;
        retryRollback();
        if (process_.state().result == OperationResult2026::RolledBack)
            setStatus(RuntimeStatusKind2026::ModificationRolledBack);
    } catch (...) {
        process_.state().failure = {RuntimeOperation2026::RuntimeException};
        process_.state().phase = SessionPhase2026::RecoveryRequired;
        retryRollback();
        if (process_.state().result == OperationResult2026::RolledBack)
            setStatus(RuntimeStatusKind2026::ExceptionRolledBack);
    }
    return process_.state().result == OperationResult2026::Committed;
}
bool Runtime2026::undo() {
    if (process_.state().process && observeProcess() == ProcessState2026::Exited) return retireExitedProcess();
    if (!retryRollback()) return false;
    if (process_.state().journal.empty()) { process_.state().result = OperationResult2026::Undone; return true; }
    savedState_ = initialState_; savedData_ = initialData_;
    process_.state().journal.restoreAll();
    undoPending_ = true;
    process_.state().phase = SessionPhase2026::RecoveryRequired;
    return retryRollback();
}

static_assert(sizeof(void*) == 4, "2026 runtime requires Win32");

Runtime2026::Runtime2026(ProcessApi2026 api): process_(api) {
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
    field<UINT>(san9::layout2026::MessageId)=process_.registerMessage("San9PKHard");
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
