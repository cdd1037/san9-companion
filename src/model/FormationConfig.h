#pragma once
#include "PackedConfigIO.h"
#include <array>
#include <ostream>
namespace san9 {
struct FormationValues {
    std::uint8_t troop=10, garrison=10, durability=10, defence=10, speed=10;
    std::uint8_t range=2, radius=1, angle=1;
    std::uint16_t expense=0;
    bool valid() const;
};
class FormationConfig {
public:
    static constexpr size_t Count=27, GameRecordSize=0x88, RecordSize=8;
    using Bytes=std::array<std::uint8_t,Count*RecordSize>;
    std::array<FormationValues,Count> entries{};
    bool valid() const;
    Bytes encode() const;
    void decode(const Bytes& bytes);
    PackedReadResult read(std::istream& input);
    bool write(std::ostream& output) const;
    bool importGame(size_t index,const std::uint8_t* bytes,size_t size);
};
}
