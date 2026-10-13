#pragma once
#include <cstdint>
#include <istream>
#include <string>
#include <string_view>
namespace san9 {
enum class PackedReadError { none, missingLine, invalidInteger, integerOverflow, outOfRange, extraData, ioError };
struct PackedReadResult { PackedReadError error = PackedReadError::none; size_t line = 0; };
namespace packed {
std::string_view trim(const std::string& line);
// Accept blank trailing lines and report the first unexpected line or I/O error.
PackedReadResult finish(std::istream& input, size_t line);
PackedReadError number(std::istream& input, std::uint32_t& value);
}
}
