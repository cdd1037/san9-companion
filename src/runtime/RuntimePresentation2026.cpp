#include "Runtime2026.h"

void Runtime2026::setPresentationSpeed(unsigned multiplier) {
    if (!presentation2026::validMultiplier(multiplier)) throw std::invalid_argument("Invalid presentation multiplier");
    speedMultiplier_=multiplier;
}
bool Runtime2026::pauseSpeedThreads(bool installing) {
    if (!process_.state().process || (!speedAllocation_ && !installing)) return true;
    std::vector<ExecutionRange2026> ranges;
    for (const auto& hook:presentation2026::hooks())
        ranges.push_back({hook.site+1,static_cast<DWORD>(hook.original.size()-1)});
    if (speedAllocation_) ranges.push_back({speedAllocation_,presentation2026::PayloadSize});
    auto failure=threadBarrier_.pause(process_.state().identity.pid,ranges);
    if (!failure) return true;
    if (process_.state().phase==SessionPhase2026::RecoveryRequired) process_.state().recoveryFailure=failure;
    else process_.state().failure=failure;
    return false;
}
bool Runtime2026::resumeSpeedThreads() {
    if (auto failure=threadBarrier_.resume()) {
        process_.state().recoveryFailure=failure;
        process_.state().phase=SessionPhase2026::RecoveryRequired;
        process_.state().result=OperationResult2026::RecoveryRequired;
        setStatus(RuntimeStatusKind2026::RecoveryRequired);
        return false;
    }
    return true;
}
void Runtime2026::applyPresentationSpeed() {
    if (!process_.state().process || appliedSpeed_==speedMultiplier_) return;
    if (!pauseSpeedThreads(true)) throw ProcessOperationFailure2026{};
    if (!speedAllocation_) {
        if (speedMultiplier_==1) return;
        const HANDLE process=process_.state().process;
        DWORD clock=0;
        readMemory(process,0x5FF4D8u,&clock,sizeof(clock),nullptr);
        if (auto failure=threadBarrier_.validateClock(process_.state().identity.pid,clock)) {
            process_.state().failure=failure; throw ProcessOperationFailure2026{};
        }
        for (const auto& hook:presentation2026::hooks()) {
            std::vector<BYTE> actual(hook.original.size());
            readMemory(process,hook.site,actual.data(),actual.size(),nullptr);
            if (actual!=hook.original) {
                process_.state().failure={RuntimeOperation2026::ValidateSpeed,hook.site,hook.original.size(),0,0};
                throw ProcessOperationFailure2026{};
            }
        }
        speedAllocation_=reinterpret_cast<DWORD>(allocateMemory(process,nullptr,presentation2026::PayloadSize,
                                                               MEM_COMMIT,PAGE_EXECUTE_READWRITE));
        const auto bytes=presentation2026::payload(clock,speedMultiplier_);
        writePatch(speedAllocation_,bytes.data(),bytes.size());
        for (const auto& hook:presentation2026::hooks()) {
            const auto patch=presentation2026::redirect(hook,speedAllocation_);
            writePatch(hook.site,patch.data(),patch.size());
        }
    } else {
        // A live range is already suspended by runOperation. Fail closed on foreign detours.
        for (const auto& hook:presentation2026::hooks()) {
            const auto expected=presentation2026::redirect(hook,speedAllocation_);
            std::vector<BYTE> actual(expected.size());
            readMemory(process_.state().process,hook.site,actual.data(),actual.size(),nullptr);
            if (actual!=expected) {
                process_.state().failure={RuntimeOperation2026::ValidateSpeed,hook.site,expected.size(),0,0};
                throw ProcessOperationFailure2026{};
            }
        }
        const DWORD rate=speedMultiplier_;
        writePatch(speedAllocation_,&rate,sizeof(rate));
    }
    appliedSpeed_=speedMultiplier_;
}
