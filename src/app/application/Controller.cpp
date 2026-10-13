#include "Controller.h"
#include "../../runtime/AppPaths.h"
#include <fstream>
namespace app
{
Controller::Controller()
{
    syncFromCore();
}
std::vector<ConfigLoadError> Controller::load(bool automatic, bool skipSelection)
{
    std::vector<ConfigLoadError> errors;
    flags.cityAutomatic = automatic;
    skipSiegeSelection = skipSelection;
    std::ifstream parameterFile(san9::executableFile(L"San9PKHardPara.txt"));
    if (parameterFile && parameters.read(parameterFile).status != san9::ConfigReadStatus::complete)
        errors.push_back({L"San9PKHardPara.txt", 0});
    auto load = [&](auto &config, const wchar_t *name) {
        std::ifstream input(san9::executableFile(name));
        if (!input)
            return false;
        auto result = config.read(input);
        if (result.error != san9::PackedReadError::none)
        {
            errors.push_back({name, result.line});
            return false;
        }
        return true;
    };
    load(persons, L"San9PKHardPerson.txt");
    flags.cityPending = load(cities, L"San9PKHardCity.txt");
    flags.skillLoaded = load(skills, L"San9PKHardSkill.txt");
    flags.formationLoaded = load(formations, L"San9PKHardArray.txt");
    syncToCore();
    return errors;
}
void Controller::syncToCore()
{
    runtime.setParameters(parameters);
    runtime.setPersonConfig(persons);
    runtime.setCityConfig(cities);
    runtime.setSkillConfig(skills);
    runtime.setFormationConfig(formations);
    runtime.setConfigurationState(flags);
    runtime.setSkipDurabilitySiegeSelection(skipSiegeSelection);
}
void Controller::syncFromCore()
{
    persons = runtime.personConfig();
    cities = runtime.cityConfig();
    skills = runtime.skillConfig();
    formations = runtime.formationConfig();
    flags = runtime.configurationState();
}
void Controller::modify(ModifyReason2026 reason)
{
    syncToCore();
    runtime.modify(reason);
    syncFromCore();
}
bool Controller::gameMessage(UINT message, WPARAM action, LPARAM argument)
{
    if (!runtime.isGameMessage(message))
        return false;
    syncToCore();
    runtime.handleGameMessage(message, action, argument);
    syncFromCore();
    return true;
}
bool Controller::undo()
{
    bool result = runtime.undo();
    syncFromCore();
    return result;
}
bool Controller::toggleForce(unsigned index)
{
    syncToCore();
    bool result = runtime.togglePlayerForce(index);
    syncFromCore();
    return result;
}
#define SNAPSHOT(method, coreMethod, type)                                                                   \
    bool Controller::method(type &value)                                                                     \
    {                                                                                                        \
        syncToCore();                                                                                        \
        bool result = runtime.coreMethod(value);                                                             \
        syncFromCore();                                                                                      \
        return result;                                                                                       \
    }
SNAPSHOT(personSnapshot, readPersonSnapshot, san9::PersonSnapshot)
SNAPSHOT(citySnapshot, readCitySnapshot, CitySnapshot2026)
SNAPSHOT(skillSnapshot, readSkillSnapshot, SkillSnapshot2026)
SNAPSHOT(formationSnapshot, readFormationSnapshot, FormationSnapshot2026)
SNAPSHOT(forces, readPlayerForces, std::vector<PlayerForce2026>)
#undef SNAPSHOT
} // namespace app
