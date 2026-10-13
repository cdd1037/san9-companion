#include "FormationConfig.h"
namespace san9 {
namespace {
std::uint32_t load(const FormationConfig::Bytes& b,size_t n) {
    return std::uint32_t(b[n])|(std::uint32_t(b[n+1])<<8)|(std::uint32_t(b[n+2])<<16)|(std::uint32_t(b[n+3])<<24);
}
void store(FormationConfig::Bytes& b,size_t n,std::uint32_t v) {
    for(size_t k=0;k<4;++k) b[n+k]=static_cast<std::uint8_t>(v>>(k*8));
}
}
bool FormationValues::valid() const {
    return troop>=5 && troop<=50 && garrison>=5 && garrison<=50 && durability>=5 && durability<=60
        && defence>=5 && defence<=30 && speed>=5 && speed<=50 && range>=1 && range<=5
        && radius<=10 && angle>=1 && angle<=8 && expense<=10000;
}
bool FormationConfig::valid() const {
    for(const auto& row:entries) if(!row.valid()) return false;
    return true;
}
FormationConfig::Bytes FormationConfig::encode() const {
    Bytes b{};
    for(size_t i=0;i<Count;++i) {
        const auto& r=entries.at(i);
        store(b,i*8,std::uint32_t(r.troop)|(std::uint32_t(r.garrison)<<6)|(std::uint32_t(r.durability)<<12)
            |(std::uint32_t(r.defence)<<18)|(std::uint32_t(r.speed)<<24));
        store(b,i*8+4,std::uint32_t(r.range)|(std::uint32_t(r.radius)<<4)|(std::uint32_t(r.angle)<<8)|(std::uint32_t(r.expense)<<16));
    }
    return b;
}
void FormationConfig::decode(const Bytes& b) {
    for(size_t i=0;i<Count;++i) {
        const auto a=load(b,i*8),v=load(b,i*8+4);
        auto& r=entries.at(i);
        r.troop=a&63;r.garrison=(a>>6)&63;r.durability=(a>>12)&63;r.defence=(a>>18)&63;r.speed=(a>>24)&63;
        r.range=v&15;r.radius=(v>>4)&15;r.angle=(v>>8)&15;r.expense=static_cast<std::uint16_t>(v>>16);
    }
}
PackedReadResult FormationConfig::read(std::istream& input) {
    Bytes bytes{};
    for(size_t i=0;i<Count*2;++i) {
        std::uint32_t value=0;const auto error=packed::number(input,value);
        if(error!=PackedReadError::none) return {error,i+1};
        if(value & (i%2 ? 0x0000F000u : 0xC0000000u)) return {PackedReadError::outOfRange,i+1};
        store(bytes,i*4,value);
    }
    FormationConfig candidate;candidate.decode(bytes);
    for(size_t i=0;i<Count;++i) if(!candidate.entries.at(i).valid()) return {PackedReadError::outOfRange,i*2+1};
    const auto tail = packed::finish(input, Count*2);
    if (tail.error != PackedReadError::none) return tail;
    *this=candidate;return {};
}
bool FormationConfig::write(std::ostream& output) const {
    if(!valid()) return false;
    const auto bytes=encode();
    for(size_t i=0;i<Count*2;++i) output<<load(bytes,i*4)<<'\n';
    output.flush();return bool(output);
}
bool FormationConfig::importGame(size_t index,const std::uint8_t* bytes,size_t size) {
    if(index>=Count || !bytes || size<GameRecordSize) return false;
    auto row=entries.at(index); // Range belongs to the companion's separate table.
    row.troop=bytes[0x60];row.garrison=bytes[0x64];row.durability=bytes[0x68];row.defence=bytes[0x6C];row.speed=bytes[0x5C];
    row.radius=bytes[0x70];row.angle=bytes[0x74];row.expense=bytes[0x78]|(std::uint16_t(bytes[0x79])<<8);
    if(!row.valid()) return false;
    entries.at(index)=row;return true;
}
}
