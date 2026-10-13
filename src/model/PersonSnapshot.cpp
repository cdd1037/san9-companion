#include "PersonSnapshot.h"
#include <cstdlib>
namespace san9 {
bool PersonSnapshot::decode(const std::uint8_t* bytes,size_t size) {
    if(!bytes || size!=Count*RecordSize) return false;
    for(size_t i=0;i<Count;++i) {
        const auto* p=bytes+i*RecordSize;
        const auto word=[p](size_t offset) {return std::uint16_t(p[offset]|(std::uint16_t(p[offset+1])<<8));};
        PersonInfo row;
        size_t out=0;
        for(size_t start:{0x10u,0x15u}) for(size_t k=0;k<4 && p[start+k];++k) row.name[out++]=static_cast<char>(p[start+k]);
        row.status=p[0x84]<=10?p[0x84]:10;
        row.abilities={p[0x64],p[0x4C],p[0x54],p[0x5C]};
        row.good=(word(0xE8)>>3)&0x1FF;
        for(size_t k=0;k<9;++k) row.proficiency[k]=word(0xA4+2*k);
        row.learned=std::uint32_t(word(0x100))|(std::uint32_t(word(0x102))<<16);
        entries_.at(i)=row;
    }
    count_=Count;return true;
}
int PersonSnapshot::abilityTolerance(int value) {
    return value>90?2:value>80?1:value>60?0:value>50?1:value>30?2:5;
}
std::optional<size_t> PersonSnapshot::nextAbility(size_t current,size_t ability,int value) const {
    if(ability>=4 || value<0 || value>255) return std::nullopt;
    const int tolerance=abilityTolerance(value);
    return next(current,[=](const PersonInfo& row) {return std::abs(int(row.abilities[ability])-value)<=tolerance;});
}
}
