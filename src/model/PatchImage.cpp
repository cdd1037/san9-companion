#include "PatchImage.h"
#include <iterator>
#include <stdexcept>

namespace san9 {
namespace {
constexpr std::uint8_t InitialData[] = {
#include "companion_data.inc"
};
constexpr Relocation Relocations[] = {
#include "relocations.inc"
};
constexpr std::uint32_t ObjectOffsets[] = {7620, 3700, 4720, 4724, 4828, 4832, 5212};
constexpr std::uint32_t ObjectValues[] = {0xA31B0, 0xA4000, 0xA5662, 0xA5630, 0xA6E00, 0xA3CC0, 0xA1AE0};
static_assert(sizeof(InitialData) == 0x11000, "Recovered data size changed");
static_assert(sizeof(Relocations) / sizeof(Relocations[0]) == 969, "Relocation count changed");

// Explicit little-endian access also handles unaligned instruction immediates.
template<class Buffer>
std::uint32_t load(const Buffer& bytes, std::size_t offset) {
    if (offset > bytes.size() || bytes.size() - offset < 4)
        throw std::out_of_range("recovered dword");
    return std::uint32_t(bytes[offset]) | (std::uint32_t(bytes[offset+1]) << 8)
        | (std::uint32_t(bytes[offset+2]) << 16) | (std::uint32_t(bytes[offset+3]) << 24);
}
template<class Buffer>
void store(Buffer& bytes, std::size_t offset, std::uint32_t value) {
    if (offset > bytes.size() || bytes.size() - offset < 4)
        throw std::out_of_range("recovered dword");
    for (unsigned i = 0; i < 4; ++i) bytes[offset+i] = std::uint8_t(value >> (8*i));
}
} // namespace

PatchImage::PatchImage() : data_(std::begin(InitialData), std::end(InitialData)) {
    for (std::size_t i = 0; i < 7; ++i) store(object_, ObjectOffsets[i], ObjectValues[i]);
}
std::uint32_t PatchImage::read32(std::uint32_t va) const {
    if (va < DataVA) throw std::out_of_range("companion VA");
    return load(data_, va - DataVA);
}
std::uint32_t PatchImage::object32(std::size_t offset) const { return load(object_, offset); }

// Recovered from 0x41A400, with the base-slot update performed by 0x409E10.
// First seven table entries use object offsets instead of fabricated host pointers.
std::vector<RelocationChange> PatchImage::rebase(std::uint32_t newBase) {
    if (!newBase || (newBase & 0xFFF) || std::uint64_t(newBase) + AllocationSize > 0x100000000ULL)
        throw std::invalid_argument("nonzero page-aligned 32-bit allocation required");
    const std::uint32_t delta = newBase - base();
    store(object_, 96, newBase);
    std::vector<RelocationChange> changes;
    if (!delta) return changes;
    changes.reserve(969);
    for (const auto& slot : Relocations) {
        const auto old = slot.objectField ? object32(slot.location) : read32(slot.location);
        const std::uint32_t next = old + delta;
        if (slot.objectField) store(object_, slot.location, next);
        else store(data_, slot.location - DataVA, next);
        changes.push_back({slot, old, next});
    }
    store(data_, BaseSlot - DataVA, newBase);
    return changes;
}
} // namespace san9
