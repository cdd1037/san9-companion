#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <istream>
#include <ostream>

namespace san9 {
struct ParameterField {
    unsigned controlId, hostOffset, dialogOffset, fileLine;
    std::uint32_t mask;
    std::int32_t defaultValue, minimum, maximum;
    bool unsignedValue;
};
enum class ConfigReadStatus { complete, truncated, integerOverflow, ioError, invalidInteger, extraData, invalidValues };
struct ConfigReadResult {
    ConfigReadStatus status;
    std::size_t linesApplied;
};
enum class ParameterError { none, range, cutOrder };
struct ParameterValidation {
    ParameterError error;
    unsigned controlId; // First control the original dialog would focus.
};

// Pure value model. Offsets describe the 2026 x86 objects, not this C++ class.
class ParameterConfig final {
public:
    static constexpr std::size_t FieldCount = 88;
    static constexpr std::size_t FileLineCount = 34;
    static const std::array<ParameterField, FieldCount>& fields();
    ParameterConfig();
    std::int32_t get(unsigned controlId) const;
    void set(unsigned controlId, std::int32_t value);
    // Parse and validate the complete file before committing any values.
    // On failure linesApplied is zero and the existing configuration is unchanged.
    ConfigReadResult read(std::istream& input);
    ParameterValidation validate() const;
    // Like 0x403780/0x403FF0: reject invalid dialog values before writing.
    // Emits '\n'; use a Windows text-mode stream for original CRLF files.
    bool write(std::ostream& output) const;
private:
    static std::size_t index(unsigned controlId);
    std::array<std::int32_t, FieldCount> values_{};
};
} // namespace san9
