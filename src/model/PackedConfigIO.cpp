#include "PackedConfigIO.h"
#include <charconv>
#include <limits>
namespace san9::packed {
std::string_view trim(const std::string& line) {
    const auto start=line.find_first_not_of(" \t\r");
    if (start==std::string::npos) return {};
    return std::string_view(line).substr(start,line.find_last_not_of(" \t\r")-start+1);
}
PackedReadResult finish(std::istream& input, size_t line) {
    std::string extra;
    while (std::getline(input, extra)) {
        ++line;
        if (!trim(extra).empty()) return {PackedReadError::extraData, line};
    }
    if (input.bad() || !input.eof()) return {PackedReadError::ioError, line};
    return {};
}
PackedReadError number(std::istream& input, std::uint32_t& value) {
    std::string line;
    if (!std::getline(input,line)) return input.bad() || !input.eof()?PackedReadError::ioError:PackedReadError::missingLine;
    auto text=trim(line);
    if (text.empty()) return PackedReadError::invalidInteger;
    if (text.front()=='+') { text.remove_prefix(1); if(text.empty() || text.front()=='-') return PackedReadError::invalidInteger; }
    std::int64_t parsed=0;
    const auto result=std::from_chars(text.data(),text.data()+text.size(),parsed);
    if (result.ec==std::errc::result_out_of_range) return PackedReadError::integerOverflow;
    if (result.ec!=std::errc{} || result.ptr!=text.data()+text.size()) return PackedReadError::invalidInteger;
    if (parsed<std::numeric_limits<std::int32_t>::min() || parsed>std::numeric_limits<std::int32_t>::max())
        return PackedReadError::integerOverflow;
    value=static_cast<std::uint32_t>(parsed);
    return PackedReadError::none;
}
}
