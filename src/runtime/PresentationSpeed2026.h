#pragma once
#include <Windows.h>
#include <array>
#include <vector>

namespace presentation2026 {
inline bool validMultiplier(unsigned value) { return value == 1 || value == 2 || value == 4; }
inline constexpr DWORD PayloadSize = 0x1000;
struct Hook {
    DWORD site;
    std::vector<BYTE> original;
    DWORD offset;
};
// Verified TC101 instruction boundaries; all injected paths are leaf code.
const std::array<Hook, 5>& hooks();
std::vector<BYTE> payload(DWORD clock, unsigned multiplier);
std::vector<BYTE> redirect(const Hook& hook, DWORD base);
}
