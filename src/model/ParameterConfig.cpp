#include "ParameterConfig.h"
#include <stdexcept>
#include <string>
#include "PackedConfigIO.h"

namespace san9 {
namespace {
constexpr std::array<ParameterField, ParameterConfig::FieldCount> Fields{{
#include "parameter_fields.inc"
}};

} // namespace

const std::array<ParameterField, ParameterConfig::FieldCount>& ParameterConfig::fields() { return Fields; }
ParameterConfig::ParameterConfig() {
    for (std::size_t i = 0; i < FieldCount; ++i) values_[i] = Fields[i].defaultValue;
}
std::size_t ParameterConfig::index(unsigned controlId) {
    for (std::size_t i = 0; i < FieldCount; ++i)
        if (Fields[i].controlId == controlId) return i;
    throw std::out_of_range("Unknown 2026 parameter control ID");
}
std::int32_t ParameterConfig::get(unsigned controlId) const { return values_[index(controlId)]; }
void ParameterConfig::set(unsigned controlId, std::int32_t value) { values_[index(controlId)] = value; }

ConfigReadResult ParameterConfig::read(std::istream& input) {
    ParameterConfig candidate;
    for (std::size_t line = 1; line <= FileLineCount; ++line) {
        std::uint32_t number = 0;
        switch (packed::number(input, number)) {
        case PackedReadError::none: break;
        case PackedReadError::missingLine: return {ConfigReadStatus::truncated, 0};
        case PackedReadError::integerOverflow: return {ConfigReadStatus::integerOverflow, 0};
        case PackedReadError::ioError: return {ConfigReadStatus::ioError, 0};
        default: return {ConfigReadStatus::invalidInteger, 0};
        }
        for (std::size_t i = 0; i < FieldCount; ++i) {
            const auto& field = Fields[i];
            if (field.fileLine == line)
                candidate.values_[i] = field.mask ? ((number & field.mask) != 0)
                                                 : static_cast<std::int32_t>(number);
        }
    }
    const auto tail = packed::finish(input, FileLineCount);
    if (tail.error != PackedReadError::none)
        return {tail.error == PackedReadError::ioError ? ConfigReadStatus::ioError : ConfigReadStatus::extraData, 0};
    if (candidate.validate().error != ParameterError::none)
        return {ConfigReadStatus::invalidValues, 0};
    *this = candidate;
    return {ConfigReadStatus::complete, FileLineCount};
}

ParameterValidation ParameterConfig::validate() const {
    for (std::size_t i = 0; i < FieldCount; ++i) {
        const auto& f = Fields[i];
        const auto value = values_[i];
        // Checkboxes are a boolean API invariant; original DDX receives 0/1.
        if (f.unsignedValue ? (static_cast<std::uint32_t>(value) < static_cast<std::uint32_t>(f.minimum) ||
                              static_cast<std::uint32_t>(value) > static_cast<std::uint32_t>(f.maximum))
                            : (value < f.minimum || value > f.maximum))
            return {ParameterError::range, f.controlId};
    }
    // 0x403FF0 uses unsigned comparisons in money, food, draft order.
    constexpr unsigned chains[][3] = {{1020,1021,1022}, {1023,1024,1025}, {1026,1027,1028}};
    for (const auto& chain : chains)
        for (unsigned i = 0; i < 2; ++i)
            if (static_cast<std::uint32_t>(get(chain[i])) > static_cast<std::uint32_t>(get(chain[i+1])))
                return {ParameterError::cutOrder, chain[i]};
    return {ParameterError::none, 0};
}

bool ParameterConfig::write(std::ostream& output) const {
    if (validate().error != ParameterError::none) return false;
    for (std::size_t line = 1; line <= FileLineCount; ++line) {
        std::int32_t number = 0;
        std::uint32_t mask = 0;
        for (std::size_t i = 0; i < FieldCount; ++i) {
            const auto& field = Fields[i];
            if (field.fileLine != line) continue;
            if (field.mask) {
                if (values_[i] != 0) mask |= field.mask;
            } else number = values_[i];
        }
        // Recovered masks never use bit 31; signed %d is therefore positive.
        output << std::to_string(mask ? static_cast<std::int32_t>(mask) : number) << '\n';
        if (!output) return false;
    }
    return true;
}
} // namespace san9
