#include "CityConfig.h"
#include <algorithm>

namespace san9 {
namespace {
std::uint32_t load(const std::uint8_t* bytes, size_t count) {
    std::uint32_t value = 0;
    for (size_t i=0; i<count; ++i) value |= std::uint32_t(bytes[i]) << (8*i);
    return value;
}
void store(std::uint32_t value, std::uint8_t* bytes, size_t count) {
    for (size_t i=0; i<count; ++i) bytes[i] = static_cast<std::uint8_t>(value >> (8*i));
}
using packed::number;
}
CityConfig::CityConfig() {
    for (auto& row:relations) row.fill(50);
    attackDays.fill(50);
}
bool CityConfig::validCity(size_t index) const {
    if (index>=Count) return false;
    const auto& c=limits.at(index);
    return (c.flags&0x40)==0 && (c.flags&15)<=11
        && c.soldiers>=10 && c.soldiers<=50 && c.durability>=6 && c.durability<=20
        && c.peopleHeart>=4 && c.peopleHeart<=10 && c.income>=4 && c.income<=15
        && c.harvest>=4 && c.harvest<=15 && attackDays.at(index)>=20 && attackDays.at(index)<=100
        && std::all_of(relations.at(index).begin(),relations.at(index).end(),[](auto v){return v<=50;});
}
bool CityConfig::valid() const {
    for(size_t i=0;i<Count;++i) if(!validCity(i)) return false;
    return true;
}
std::array<std::uint8_t, CityConfig::Count * CityConfig::RecordSize> CityConfig::encodeLimits() const {
    std::array<std::uint8_t,Count*RecordSize> bytes{};
    for(size_t i=0;i<Count;++i) {
        const auto& c=limits.at(i);
        const std::uint8_t row[]={c.flags,c.soldiers,c.durability,c.peopleHeart,c.income,c.harvest};
        std::copy(std::begin(row),std::end(row),bytes.begin()+i*RecordSize);
    }
    return bytes;
}
void CityConfig::decodeLimits(const std::array<std::uint8_t,Count*RecordSize>& bytes) {
    for(size_t i=0;i<Count;++i) {
        const auto* b=bytes.data()+i*RecordSize;
        limits.at(i)={b[0],b[1],b[2],b[3],b[4],b[5]};
    }
}
CityReadResult CityConfig::read(std::istream& input) {
    CityConfig candidate;
    std::array<std::uint8_t,Count*RecordSize> bytes{};
    size_t line=0;
    for(size_t i=0;i<Count;++i) {
        for(size_t part=0;part<2;++part) {
            std::uint32_t value=0;
            const auto error=number(input,value);++line;
            if(error!=CityReadError::none) return {error,line};
            // The sample reads DWORD then WORD. The second line's upper word is not a field.
            store(value,bytes.data()+i*RecordSize+part*4,part==0?4:2);
        }
    }
    candidate.decodeLimits(bytes);
    for(size_t i=0;i<Count;++i) {
        for(size_t part=0;part<3;++part) {
            std::uint32_t value=0;
            const auto error=number(input,value);++line;
            if(error!=CityReadError::none) return {error,line};
            if(part<2) store(value,candidate.relations.at(i).data()+part*4,4);
            else {
                if(value<20 || value>100) return {CityReadError::outOfRange,line};
                candidate.attackDays.at(i)=static_cast<std::uint8_t>(value);
            }
        }
        if(!candidate.validCity(i)) return {CityReadError::outOfRange,line};
    }
    const auto tail = packed::finish(input, line);
    if (tail.error != PackedReadError::none) return tail;
    *this=candidate;
    return {};
}
bool CityConfig::write(std::ostream& output) const {
    if(!valid()) return false;
    const auto bytes=encodeLimits();
    for(size_t i=0;i<Count;++i) {
        output<<load(bytes.data()+i*RecordSize,4)<<'\n'<<load(bytes.data()+i*RecordSize+4,2)<<'\n';
    }
    for(size_t i=0;i<Count;++i) output<<load(relations.at(i).data(),4)<<'\n'
        <<load(relations.at(i).data()+4,4)<<'\n'<<unsigned(attackDays.at(i))<<'\n';
    output.flush();
    return bool(output);
}
bool CityConfig::importGameCity(size_t index,const std::uint8_t* bytes,size_t size) {
    if(index>=Count || !bytes || size<GameRecordSize) return false;
    auto candidate=*this;
    auto& c=candidate.limits.at(index);
    const auto skills=load(bytes+0x51,4);
    unsigned skill=11;
    for(unsigned i=0;i<11;++i) if(skills & (1u<<(i<3?i+1:i+12))) {skill=i;break;}
    c.flags=static_cast<std::uint8_t>(skill | ((load(bytes+0x54,4)&0x80)?0x10:0)
        | ((load(bytes+0x54,4)&0x100)?0x20:0) | ((load(bytes+0x1E0,4)&1)?0x80:0));
    const auto durability=load(bytes+0x1C8,4)/100, income=load(bytes+0x1D4,4)/100, harvest=load(bytes+0x1D8,4)/100;
    if(durability>255 || income>255 || harvest>255) return false;
    c.durability=static_cast<std::uint8_t>(durability);c.income=static_cast<std::uint8_t>(income);c.harvest=static_cast<std::uint8_t>(harvest);
    if(!candidate.validCity(index)) return false;
    limits.at(index)=c;return true;
}
}
