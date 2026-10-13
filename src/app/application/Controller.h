#pragma once
#include "../../runtime/Runtime2026.h"
#include "ConfigFiles.h"

namespace app
{
struct ConfigLoadError
{
    std::wstring file;
    ConfigFileResult result;
};
class Controller
{
  public:
    Runtime2026 runtime;
    san9::ParameterConfig parameters;
    san9::PersonConfig persons;
    san9::CityConfig cities;
    san9::SkillConfig skills;
    san9::FormationConfig formations;
    ConfigurationState2026 flags;
    bool skipSiegeSelection = true;
    Controller();
    std::vector<ConfigLoadError> load(bool cityAutomatic, bool skipSelection);
    void syncToCore();
    void syncFromCore();
    void modify(ModifyReason2026 reason);
    bool gameMessage(UINT message, WPARAM action, LPARAM argument);
    bool undo();
    bool toggleForce(unsigned index);
    bool personSnapshot(san9::PersonSnapshot &value);
    bool citySnapshot(CitySnapshot2026 &value);
    bool skillSnapshot(SkillSnapshot2026 &value);
    bool formationSnapshot(FormationSnapshot2026 &value);
    bool forces(std::vector<PlayerForce2026> &value);
};

} // namespace app
