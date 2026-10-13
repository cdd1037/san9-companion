#pragma once
#include "PersonConfig.h"
#include <optional>
namespace san9 {
struct PersonInfo {
    std::array<char,9> name{};
    std::uint8_t status=10;
    // Command, strength, intelligence, politics; display/search, never configuration.
    std::array<std::uint8_t,4> abilities{};
    std::uint16_t good=0;
    std::array<std::uint16_t,9> proficiency{};
    std::uint32_t learned=0;
};
class PersonSnapshot {
public:
    static constexpr size_t Count=PersonConfig::Count, RecordSize=0x128;
    bool decode(const std::uint8_t* bytes,size_t size);
    size_t size() const { return count_; }
    PersonInfo& at(size_t i) { return entries_.at(i); }
    const PersonInfo& at(size_t i) const { return entries_.at(i); }
    static int abilityTolerance(int value);
    template<class Predicate> std::optional<size_t> next(size_t current,Predicate matches) const {
        if(current>=count_) return std::nullopt;
        for(size_t step=1;step<count_;++step) {
            const size_t index=(current+step)%count_;
            if(matches(entries_.at(index))) return index;
        }
        return std::nullopt;
    }
    std::optional<size_t> nextAbility(size_t current,size_t ability,int value) const;
private:
    std::array<PersonInfo,Count> entries_{};
    size_t count_=0;
};
}
