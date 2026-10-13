#include "SkillConfig.h"
namespace san9 {
bool SkillConfig::valid() const {
    for(const auto& row:entries) if(!row.valid()) return false;
    return true;
}
SkillConfig::Bytes SkillConfig::encode() const {
    Bytes bytes{};
    for(size_t i=0;i<Count;++i) {
        const auto& row=entries.at(i);
        bytes[i*4]=row.power;bytes[i*4+1]=row.interval;
        bytes[i*4+2]=static_cast<std::uint8_t>(row.proficiency);
        bytes[i*4+3]=static_cast<std::uint8_t>(row.proficiency>>8);
    }
    return bytes;
}
void SkillConfig::decode(const Bytes& bytes) {
    for(size_t i=0;i<Count;++i) entries.at(i)={bytes[i*4],bytes[i*4+1],
        static_cast<std::uint16_t>(bytes[i*4+2]|(std::uint16_t(bytes[i*4+3])<<8))};
}
PackedReadResult SkillConfig::read(std::istream& input) {
    SkillConfig candidate;
    for(size_t i=0;i<Count;++i) {
        std::uint32_t value=0;
        const auto error=packed::number(input,value);
        if(error!=PackedReadError::none) return {error,i+1};
        auto& row=candidate.entries.at(i);
        row={static_cast<std::uint8_t>(value),static_cast<std::uint8_t>(value>>8),static_cast<std::uint16_t>(value>>16)};
        if(!row.valid()) return {PackedReadError::outOfRange,i+1};
    }
    const auto tail = packed::finish(input, Count);
    if (tail.error != PackedReadError::none) return tail;
    *this=candidate;return {};
}
bool SkillConfig::write(std::ostream& output) const {
    if(!valid()) return false;
    for(const auto& row:entries) output<<(std::uint32_t(row.power)|(std::uint32_t(row.interval)<<8)
        |(std::uint32_t(row.proficiency)<<16))<<'\n';
    output.flush();return bool(output);
}
bool SkillConfig::importGame(size_t index,const std::uint8_t* bytes,size_t size) {
    if(index>=Count || !bytes || size<GameRecordSize) return false;
    const SkillValues row{bytes[0x64],bytes[0x7C],static_cast<std::uint16_t>(bytes[0x58]|(std::uint16_t(bytes[0x59])<<8))};
    if(!row.valid()) return false;
    entries.at(index)=row;return true;
}
}
