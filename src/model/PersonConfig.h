#pragma once
#include "PackedConfigIO.h"
#include <array>
#include <ostream>
namespace san9 {
class PersonConfig {
public:
    static constexpr size_t Count=800, FriendshipCount=116;
    using LevelBytes=std::array<std::uint8_t,Count*4>;
    using FriendshipBytes=std::array<std::uint8_t,FriendshipCount*6>;
    std::array<std::uint32_t,Count> levels{};
    std::array<std::array<std::uint16_t,3>,FriendshipCount> friendships{};
    std::uint16_t maxExperience=1500;
    PersonConfig() { levels.fill(0x3FEAA); }
    bool valid() const;
    LevelBytes encodeLevels() const;
    FriendshipBytes encodeFriendships() const;
    void decode(const LevelBytes& levels,const FriendshipBytes& friendships,std::uint16_t maximum);
    PackedReadResult read(std::istream& input);
    bool write(std::ostream& output) const;
};
}
