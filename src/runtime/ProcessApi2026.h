#pragma once
#include <Windows.h>

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
