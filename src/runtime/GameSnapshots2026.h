#pragma once
#include "../model/CityConfig.h"
#include "../model/FormationConfig.h"
#include "../model/SkillConfig.h"
#include <optional>

template <class Config, size_t NameCapacity> struct ConfigurationSnapshot2026
{
    Config config;
    std::array<std::array<char, NameCapacity>, Config::Count> names{};
    std::optional<size_t> invalidRow;
};
using CitySnapshot2026 =
    ConfigurationSnapshot2026<san9::CityConfig, san9::CityConfig::GameRecordSize - 0x20 + 1>;
using SkillSnapshot2026 =
    ConfigurationSnapshot2026<san9::SkillConfig, san9::SkillConfig::GameRecordSize - 0x10 + 1>;
using FormationSnapshot2026 =
    ConfigurationSnapshot2026<san9::FormationConfig, san9::FormationConfig::GameRecordSize - 0x10 + 1>;
struct PlayerForce2026
{
    unsigned index = 0;
    bool player = false;
    std::array<char, 10> leaderName{};
};
