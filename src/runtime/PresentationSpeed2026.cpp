#include "PresentationSpeed2026.h"
#include <cstring>
#include <stdexcept>
#include <cstdint>

extern "C" {
    extern const BYTE PresentationPayloadBegin[], PresentationPayloadEnd[];
    extern const BYTE PresentationRedirectBegin[], PresentationRedirectEnd[], PresentationNop[];
    extern const BYTE PresentationPeriod[], PresentationEnter[], PresentationExit[], PresentationMotion[], PresentationWait[];
}
namespace presentation2026 {
namespace {
DWORD offset(const BYTE* symbol) {
    return static_cast<DWORD>(reinterpret_cast<std::uintptr_t>(symbol)-reinterpret_cast<std::uintptr_t>(PresentationPayloadBegin));
}
struct Settings {
    DWORD rate, owner, map, clock;
    DWORD mapVtable = 0x611308;
    DWORD pause = 0x1545ED8;
    DWORD clockSlot = 0x5FF4D8;
    DWORD sleepSlot = 0x5FF118;
    std::array<DWORD, 5> continuation{0x4348FA, 0x43491D, 0x434934, 0x53DB69, 0x53033B};
    std::array<DWORD, 3> mapWaitCallers{0x5344CC, 0x534656, 0x53499C};
};
static_assert(sizeof(Settings)==64, "MASM payload settings layout");
}
const std::array<Hook, 5>& hooks() {
    static const std::array<Hook, 5> value{{
        {0x4348F4, {0x8B,0xBE,0xE8,0,0,0}, offset(PresentationPeriod)},
        {0x434918, {0x8B,0x16,0x53,0x8B,0xCE}, offset(PresentationEnter)},
        {0x43492A, {0x6A,1,0x6A,0,0xFF,0x15,0x18,0xF1,0x5F,0}, offset(PresentationExit)},
        {0x53DB62, {0x8B,0xC7,0x2B,0xC1,0x8B,0x4E,0x30}, offset(PresentationMotion)},
        {0x530335, {0x8B,0x4C,0x24,4,0x3B,0xC8}, offset(PresentationWait)}
    }};
    return value;
}
std::vector<BYTE> payload(DWORD clock, unsigned multiplier) {
    if (!validMultiplier(multiplier)) throw std::invalid_argument("Invalid presentation multiplier");
    const auto size=offset(PresentationPayloadEnd);
    if (size>PayloadSize || size<sizeof(Settings)) throw std::logic_error("Invalid assembled payload range");
    std::vector<BYTE> bytes(PayloadSize,0xCC);
    std::memcpy(bytes.data(),PresentationPayloadBegin,size);
    const Settings settings{multiplier,0,0,clock};
    std::memcpy(bytes.data(),&settings,sizeof(settings));
    return bytes;
}
std::vector<BYTE> redirect(const Hook& hook, DWORD base) {
    const auto jumpSize=reinterpret_cast<std::uintptr_t>(PresentationRedirectEnd)
                       -reinterpret_cast<std::uintptr_t>(PresentationRedirectBegin);
    if (jumpSize!=1+sizeof(DWORD) || hook.original.size()<jumpSize)
        throw std::logic_error("Invalid assembled entry jump range");
    std::vector<BYTE> bytes(hook.original.size(),*PresentationNop);
    std::memcpy(bytes.data(),PresentationRedirectBegin,jumpSize);
    const DWORD displacement=base+hook.offset-(hook.site+static_cast<DWORD>(jumpSize));
    std::memcpy(bytes.data()+jumpSize-sizeof(displacement),&displacement,sizeof(displacement));
    return bytes;
}
}
