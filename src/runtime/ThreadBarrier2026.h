#pragma once
#include "ProcessApi2026.h"
#include "RuntimeFailure2026.h"
#include <vector>

struct ExecutionRange2026 { DWORD address, size; };
// Owns exactly the suspension count it acquired; failed resumes retain their handles.
class ThreadBarrier2026 final {
public:
    explicit ThreadBarrier2026(ProcessApi2026 api): api_(api) {}
    RuntimeFailure2026 pause(DWORD pid, const std::vector<ExecutionRange2026>& ranges);
    RuntimeFailure2026 resume();
    bool pending() const { return !threads_.empty(); }
    RuntimeFailure2026 validateClock(DWORD pid, DWORD clock);
private:
    struct Thread { DWORD id; HANDLE handle; bool suspended; };
    ProcessApi2026 api_;
    std::vector<Thread> threads_;
    bool complete_ = false;
};
