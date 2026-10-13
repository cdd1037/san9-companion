#include "ParameterConfig.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace san9;
namespace {
unsigned checks = 0;
void check(bool condition, const char* message) {
    ++checks;
    if (!condition) throw std::runtime_error(message);
}
const std::vector<std::string> Defaults = {
    "12","24","49","24","49","98","9","24","49","80","60","40","50","5",
    "0","0","0","10","0","1","5","0","0","20","14","10","9","8","0","36","0","0","35","10"
};
std::string join(const std::vector<std::string>& lines, std::size_t count = 34, const char* eol = "\n") {
    std::string text;
    for (std::size_t i = 0; i < count; ++i) text += lines[i] + eol;
    return text;
}
std::string saved(const ParameterConfig& config) {
    std::ostringstream output;
    check(config.write(output), "write failed");
    return output.str();
}
ConfigReadResult read(ParameterConfig& config, const std::string& text) {
    std::istringstream input(text);
    return config.read(input);
}
void run() {
    ParameterConfig defaults;
    check(defaults.validate().error == ParameterError::none, "defaults invalid");
    check(saved(defaults) == join(Defaults), "default file differs from initialization evidence");
    for (const auto& f : ParameterConfig::fields()) {
        check(defaults.get(f.controlId) == f.defaultValue, "default field mismatch");
        if (f.mask) {
            ParameterConfig config;
            config.set(f.controlId, 1);
            auto expected = Defaults;
            expected[f.fileLine - 1] = std::to_string(f.mask);
            check(saved(config) == join(expected), "single-bit serialization mismatch");
            ParameterConfig decoded;
            check(read(decoded, join(expected)).status == ConfigReadStatus::complete, "single-bit read failed");
            for (const auto& other : ParameterConfig::fields())
                check(decoded.get(other.controlId) == config.get(other.controlId), "single-bit field mismatch");
        } else {
            for (const auto invalid : {f.minimum - 1, f.maximum + 1}) {
                ParameterConfig config;
                config.set(f.controlId, invalid);
                const auto result = config.validate();
                check(result.error == ParameterError::range && result.controlId == f.controlId, "range/focus mismatch");
                std::ostringstream output;
                check(!config.write(output) && output.str().empty(), "invalid value wrote output");
            }
        }
    }
    ParameterConfig baseline;
    baseline.set(1020, 11);
    const auto baselineText = saved(baseline);
    auto reject = [&](const std::string& text, ConfigReadStatus expected) {
        auto config = baseline;
        const auto result = read(config, text);
        check(result.status == expected && result.linesApplied == 0, "invalid file status/commit count");
        check(saved(config) == baselineText, "invalid file partially committed");
    };
    for (std::size_t count = 0; count < 34; ++count)
        reject(join(Defaults, count), ConfigReadStatus::truncated);
    for (const std::string& token : std::vector<std::string>{"", "no digits", "0x20", "+", "12tail", std::string("\0" "123", 4)}) {
        auto lines = Defaults; lines[20] = token;
        reject(join(lines), ConfigReadStatus::invalidInteger);
    }
    for (const auto token : {"2147483648", "-2147483649", "9999999999999999999999"}) {
        auto lines = Defaults; lines[20] = token;
        reject(join(lines), ConfigReadStatus::integerOverflow);
    }
    for (const auto& f : ParameterConfig::fields()) if (!f.mask) {
        for (const auto value : {f.minimum - 1, f.maximum + 1}) {
            auto lines = Defaults; lines[f.fileLine - 1] = std::to_string(value);
            reject(join(lines), ConfigReadStatus::invalidValues);
        }
    }
    auto unordered = Defaults; unordered[0] = "30";
    reject(join(unordered), ConfigReadStatus::invalidValues);
    reject(join(Defaults) + "garbage\n", ConfigReadStatus::extraData);
    for (const auto* eol : {"\n", "\r\n"}) {
        auto config = baseline;
        auto lines = Defaults; lines[0] = " \t+12 ";
        const auto result = read(config, join(lines, 34, eol) + " \t\n");
        check(result.status == ConfigReadStatus::complete && result.linesApplied == 34, "valid full file rejected");
        check(saved(config) == join(Defaults), "round trip mismatch");
    }
    {
        ParameterConfig config;
        auto text = join(Defaults); text.pop_back();
        check(read(config, text).status == ConfigReadStatus::complete, "last line without newline failed");
        auto lines = Defaults; lines[14] = "-1"; lines[15] = "-1";
        check(read(config, join(lines)).status == ConfigReadStatus::complete, "signed flag words failed");
        lines[14] = "33554431"; lines[15] = "2147483647";
        check(saved(config) == join(lines), "flag word decoding mismatch");
    }
    for (unsigned cid : {1020u,1021u,1023u,1024u,1026u,1027u}) {
        ParameterConfig config;
        config.set(cid, 123);
        const auto result = config.validate();
        check(result.error == ParameterError::cutOrder && result.controlId == cid, "cut order focus wrong");
    }
    {
        ParameterConfig config;
        config.set(1013, 2);
        check(config.validate().error == ParameterError::range, "invalid checkbox accepted");
        bool threw = false;
        try { config.get(0); } catch (const std::out_of_range&) { threw = true; }
        check(threw, "unknown control accepted");
        std::istringstream input; input.setstate(std::ios::badbit);
        check(config.read(input).status == ConfigReadStatus::ioError, "I/O error not reported");
        std::ostringstream output; output.setstate(std::ios::badbit);
        check(!defaults.write(output), "failed output not reported");
    }
}
} // namespace
int main() {
    try { run(); std::cout << checks << " parameter checks passed\n"; return 0; }
    catch (const std::exception& e) { std::cerr << e.what() << '\n'; return 1; }
}
