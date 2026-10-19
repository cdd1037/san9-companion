#include "../src/runtime/PresentationSpeed2026.h"
#include <cstring>
#include <stdexcept>
#include <cstdio>

extern "C" {
    DWORD PresentationTestInvoke(void* hook, DWORD* object, DWORD now, DWORD previous, DWORD* ediValue);
    DWORD PresentationTestInvokeWait(void* hook, DWORD now, DWORD start, DWORD duration);
    extern const BYTE PresentationTestReturn[], PresentationTestEnterTail[], PresentationTestWaitTail[];
    extern const BYTE PresentationTestWaitCaller[];
}

namespace {
// Independent description of the assembled settings ABI; addresses are replaced only in this fixture.
struct PayloadFixture {
    DWORD rate = 2, owner = 0, map = 0, clock = 0;
    DWORD mapVtable = 0x611308, pause = 0x1545ED8, clockSlot = 0x5FF4D8, sleepSlot = 0x5FF118;
    std::array<DWORD, 5> continuation{0x4348FA, 0x43491D, 0x434934, 0x53DB69, 0x53033B};
    std::array<DWORD, 3> mapWaitCallers{0x5344CC, 0x534656, 0x53499C};
};
static_assert(sizeof(PayloadFixture)==64, "fixture matches the assembled settings ABI");
constexpr DWORD Owner = 4, Map = 8;
void require(bool ok, const char* message) {
    if (!ok) throw std::runtime_error(message);
}
DWORD WINAPI fakeSleep(DWORD milliseconds, BOOL alertable) {
    require(milliseconds==0 && alertable,"exit preserves SleepEx arguments");
    return 1;
}

}
void presentationSpeedMachineCodeTest() {
    using namespace presentation2026;
    constexpr DWORD AllocationSize=PayloadSize*2;
    BYTE* allocation=static_cast<BYTE*>(VirtualAlloc(nullptr,AllocationSize,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE));
    require(allocation!=nullptr,"allocate native speed fixture");
    try {
        DWORD paused=0, clock=0x70001000;
        auto sleep=&fakeSleep;
        PayloadFixture targets;
        targets.clock=clock;
        auto code=payload(clock,2);
        require(std::memcmp(code.data(),&targets,sizeof(targets))==0,"production payload uses fixed TC101 targets");
        targets.pause=reinterpret_cast<DWORD>(&paused);
        targets.clockSlot=reinterpret_cast<DWORD>(&clock);
        targets.sleepSlot=reinterpret_cast<DWORD>(&sleep);
        const auto returnTail=reinterpret_cast<DWORD>(PresentationTestReturn);
        targets.continuation={returnTail,reinterpret_cast<DWORD>(PresentationTestEnterTail),
                              returnTail,returnTail,reinterpret_cast<DWORD>(PresentationTestWaitTail)};
        targets.mapWaitCallers.fill(reinterpret_cast<DWORD>(PresentationTestWaitCaller));
        std::memcpy(code.data(),&targets,sizeof(targets));
        // Exercise the assembled entry redirects as well as the production hook bodies.
        std::array<size_t, 5> entries{};
        for (size_t i=0;i<entries.size();++i) {
            entries[i]=code.size();
            auto entry=hooks()[i];
            entry.site=reinterpret_cast<DWORD>(allocation)+static_cast<DWORD>(entries[i]);
            const auto branch=redirect(entry,reinterpret_cast<DWORD>(allocation));
            code.insert(code.end(),branch.begin(),branch.end());
        }
        require(code.size()<=AllocationSize,"assembled hooks and redirects fit the fixture");
        std::memcpy(allocation,code.data(),code.size());
        FlushInstructionCache(GetCurrentProcess(),allocation,code.size());
        DWORD map[170]{}; map[0]=targets.mapVtable; map[58]=100; map[77]=1; map[165]=1;
        DWORD output=0;
        auto run=[&](unsigned hook,DWORD* object,DWORD now=150,DWORD previous=100) {
            return PresentationTestInvoke(allocation+entries[hook],object,now,previous,&output);
        };
        for (unsigned rate:{1u,2u,4u}) {
            *reinterpret_cast<DWORD*>(allocation)=rate;
            run(0,map);
            require(output==100/rate,"period scales without changing game period field");
            require(map[58]==100,"original period remains 100ms for slot lifetime deltas");
            run(1,map);
            require(*reinterpret_cast<DWORD*>(allocation+Owner)==GetCurrentThreadId(),"scope stores current game thread");
            DWORD motion[20]{}; motion[12]=100; motion[13]=100;
            require(run(3,motion)==50*rate && output==150 && motion[13]==100,
                    "motion scales elapsed while preserving real clock and stored timestamp");
            require(PresentationTestInvokeWait(allocation+entries[4],150,100,50*rate)==1,"scoped map wait reaches scaled boundary");
            require(PresentationTestInvokeWait(allocation+entries[4],150,100,50*rate+1)==0,"scoped map wait retains duration boundary");
        }
        DWORD motion[20]{}; motion[12]=100;
        *reinterpret_cast<DWORD*>(allocation)=4;
        paused=1; run(0,map); require(output==100,"paused map uses original cadence");
        require(run(3,motion)==50,"paused motion uses original elapsed");
        paused=0; map[77]=0; run(0,map); require(output==100,"command phase uses original cadence");
        map[77]=1; map[165]=0; run(0,map); require(output==100,"disabled map uses original cadence");
        map[165]=1; clock=0x71001000; run(0,map); require(output==100,"foreign clock owner disables speed");
        clock=0x70001000;
        require(run(3,motion,0x20,0xFFFFFFF0)==0xC0,"elapsed subtraction handles DWORD wrap");
        require(run(3,motion,0xFFFFFFF0,0x10)==MAXDWORD,"elapsed multiplication saturates instead of wrapping");
        *reinterpret_cast<DWORD*>(allocation+Owner)=GetCurrentThreadId()+1;
        require(run(3,motion)==50,"other thread does not inherit map scope");
        run(1,map);
        require(run(2,map)==1,"exit tail returns through original continuation");
        require(*reinterpret_cast<DWORD*>(allocation+Owner)==0 && *reinterpret_cast<DWORD*>(allocation+Map)==0,
                "exit clears scope before original SleepEx");
        require(run(3,motion)==50,"motion outside map callback uses real elapsed");
        map[0]=0x12340000; run(0,map); require(output==100,"other view cadence is unchanged");
        run(1,map); require(run(3,motion)==50,"nested nonmap dispatcher suppresses map scope");
        bool rejected=false;
        try { payload(clock,3); } catch (const std::invalid_argument&) { rejected=true; }
        require(rejected,"unsupported multiplier is rejected");
    } catch (...) { VirtualFree(allocation,0,MEM_RELEASE); throw; }
    VirtualFree(allocation,0,MEM_RELEASE);
    std::puts("Presentation x86 execution: cadence, scoped waits, real timestamps, pause, wrap and exit passed.");
}
