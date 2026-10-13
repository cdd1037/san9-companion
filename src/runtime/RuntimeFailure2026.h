#pragma once
#include <Windows.h>
#include <cstdint>

enum class RuntimeOperation2026 {
    None, ResolveProcess, OpenProcess, CaptureIdentity, VerifyProcess, VerifyWindow,
    RegisterMessage, CloseProcess, ClosePendingChanges, Allocate, QueryProtection,
    ValidateProtection, Protect, Read, ReadOriginal, Write, Flush, RestoreBytes,
    RestoreFlush, RestoreProtection, ReleaseAllocation, CloseExitedProcess, RuntimeException
};
// API errors are captured immediately; a successful short transfer has error zero.
struct RuntimeFailure2026 {
    RuntimeOperation2026 operation = RuntimeOperation2026::None;
    std::uintptr_t target = 0;
    SIZE_T requested = 0;
    SIZE_T transferred = 0;
    DWORD systemError = 0;
    explicit operator bool() const { return operation != RuntimeOperation2026::None; }
};
struct ProcessOperationFailure2026 {};
