#pragma once
#include <array>
#include <cstdint>
#include <type_traits>

// Serialized x86 records in the companion image; source interpretation is explicit.
struct PatchDescriptor2026
{
    std::uint32_t target;
    std::uint32_t length;
    std::uint32_t source;
};
enum class PatchSource2026 { CompanionAddress, HostPointer };
struct InlinePatch2026
{
    std::uint32_t target;
    std::uint32_t length;
    std::array<std::uint8_t, 8> bytes;
};
static_assert(sizeof(PatchDescriptor2026) == 12 && std::is_trivially_copyable_v<PatchDescriptor2026>);
static_assert(sizeof(InlinePatch2026) == 16 && std::is_trivially_copyable_v<InlinePatch2026>);
