#include "Runtime2026.h"

// Evidence: 0x41A1F0. The seven records select a city from the address table;
// enabled selects the companion's corrected mapping, disabled the original one.
BOOL Runtime2026::updateZone(int enabled) {
    struct ZoneCity { size_t zone, originalCity, correctedCity; };
    static constexpr ZoneCity mapping[] = {
        {48, 15, 9}, {31, 9, 10}, {32, 9, 12}, {46, 15, 7},
        {59, 17, 18}, {131, 44, 34}, {100, 32, 34},
    };
    for (const auto& entry : mapping) {
        const DWORD target = field<DWORD>(san9::injection2026::ZoneAddresses + entry.zone * 4) + 68;
        const size_t city = enabled ? entry.correctedCity : entry.originalCity;
        writeGameValue(target, field<DWORD>(san9::injection2026::CityAddresses + city * 4));
    }
    return TRUE;
}
