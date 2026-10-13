#include "Runtime2026.h"
#include <cstring>

namespace
{
template <class Snapshot, class Config, class Bytes, class Import>
Snapshot decodeConfiguration(const Config &saved, const Bytes &game, size_t nameOffset, bool import,
                             Import importRow)
{
    Snapshot result;
    result.config = saved;
    auto candidate = saved;
    for (size_t i = 0; i < Config::Count; ++i)
    {
        const auto row = game.data() + i * Config::GameRecordSize;
        std::memcpy(result.names[i].data(), row + nameOffset, result.names[i].size() - 1);
        if (import && !result.invalidRow && !importRow(candidate, i, row))
            result.invalidRow = i;
    }
    if (import && !result.invalidRow)
        result.config = candidate;
    return result;
}
} // namespace
bool Runtime2026::readPersonSnapshot(san9::PersonSnapshot &snapshot)
{
    std::vector<BYTE> game(san9::PersonSnapshot::Count * san9::PersonSnapshot::RecordSize);
    return readGameMemory(0x1258EE0, game.data(), game.size()) && snapshot.decode(game.data(), game.size());
}
bool Runtime2026::readCitySnapshot(CitySnapshot2026 &snapshot)
{
    std::array<BYTE, san9::CityConfig::Count * san9::CityConfig::GameRecordSize> game{};
    if (!readGameMemory(0x124DB58, game.data(), game.size()))
        return false;
    const auto flags = configurationState();
    snapshot = decodeConfiguration<CitySnapshot2026>(
        cityConfig(), game, 0x20, !flags.cityAutomatic && !flags.cityPending,
        [](auto &config, size_t i, const BYTE *row) {
            return config.importGameCity(i, row, san9::CityConfig::GameRecordSize);
        });
    return true;
}
bool Runtime2026::readSkillSnapshot(SkillSnapshot2026 &snapshot)
{
    std::array<BYTE, san9::SkillConfig::Count * san9::SkillConfig::GameRecordSize> game{};
    if (!readGameMemory(0x14FDAD0, game.data(), game.size()))
        return false;
    const auto flags = configurationState();
    snapshot = decodeConfiguration<SkillSnapshot2026>(
        skillConfig(), game, 0x10, !flags.skillLoaded && !flags.skillPending,
        [](auto &config, size_t i, const BYTE *row) {
            return config.importGame(i, row, san9::SkillConfig::GameRecordSize);
        });
    return true;
}
bool Runtime2026::readFormationSnapshot(FormationSnapshot2026 &snapshot)
{
    std::array<BYTE, san9::FormationConfig::Count * san9::FormationConfig::GameRecordSize> game{};
    if (!readGameMemory(0x1500B70, game.data(), game.size()))
        return false;
    const auto flags = configurationState();
    snapshot = decodeConfiguration<FormationSnapshot2026>(
        formationConfig(), game, 0x10, !flags.formationLoaded && !flags.formationPending,
        [](auto &config, size_t i, const BYTE *row) {
            return config.importGame(i, row, san9::FormationConfig::GameRecordSize);
        });
    return true;
}
bool Runtime2026::readPlayerForces(std::vector<PlayerForce2026> &forces)
{
    constexpr DWORD base = 0x1253C38;
    constexpr size_t stride = 0xD4;
    std::array<BYTE, 50 * stride> game{};
    if (!readGameMemory(base, game.data(), game.size()))
        return false;
    std::vector<PlayerForce2026> candidate;
    for (unsigned i = 0; i < 50; ++i)
    {
        const auto row = game.data() + i * stride;
        if (row[0x34] & 4)
            continue;
        DWORD owner = 0, leader = 0;
        std::memcpy(&owner, row + 0xB8, 4);
        std::memcpy(&leader, row + 0xBC, 4);
        if (owner != base + i * stride || !leader)
            continue;
        std::array<char, 0x128> person{};
        if (!readGameMemory(leader, person.data(), person.size()))
            return false;
        PlayerForce2026 force;
        force.index = i;
        force.player = (row[0x34] & 1) != 0;
        size_t cursor = 0;
        for (size_t offset : {size_t{0x10}, size_t{0x15}})
            for (size_t j = 0; j < 4 && person[offset + j]; ++j)
                force.leaderName[cursor++] = person[offset + j];
        candidate.push_back(force);
    }
    forces = std::move(candidate);
    return true;
}
