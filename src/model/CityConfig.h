#pragma once
#include <array>
#include <cstdint>
#include <istream>
#include <ostream>
#include "PackedConfigIO.h"

namespace san9 {
struct CityLimits {
    std::uint8_t flags = 0, soldiers = 50, durability = 7, peopleHeart = 10, income = 7, harvest = 7;
};
using CityReadError = PackedReadError;
using CityReadResult = PackedReadResult;
class CityConfig {
public:
    static constexpr size_t Count = 50, RecordSize = 6, GameRecordSize = 0x1F0;
    std::array<CityLimits, Count> limits{};
    std::array<std::array<std::uint8_t, 8>, Count> relations{};
    std::array<std::uint8_t, Count> attackDays{};
    CityConfig();
    bool validCity(size_t index) const;
    bool valid() const;
    CityReadResult read(std::istream& input); // All-or-nothing, 250 decimal lines.
    bool write(std::ostream& output) const;
    std::array<std::uint8_t, Count * RecordSize> encodeLimits() const;
    void decodeLimits(const std::array<std::uint8_t, Count * RecordSize>& bytes);
    bool importGameCity(size_t index, const std::uint8_t* bytes, size_t size);
};
}
