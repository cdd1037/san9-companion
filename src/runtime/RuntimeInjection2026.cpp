#include "Runtime2026.h"

using _DWORD = DWORD;
using _WORD = WORD;
using _BYTE = BYTE;
static_assert(sizeof(void*) == 4, "2026 injection requires Win32");
#include "../generated/Symbols.inc"

static const BYTE unk_41CD60[] = {
#include "../generated/OfficialLoyalty.inc"
};

// Maintained injection sequence. Evidence: 0x409E10; preserve patch order and operand widths.
// 按接入原因写入代码与配置；所有远程读写都经过会话事务，失败由 Runtime2026 回滚。
void Runtime2026::modifyBranches(ModifyReason2026 reason)
{
  const auto state = reinterpret_cast<std::uintptr_t>(state_.data());
  HWND gameWindow;
  int connectTicks;
  HANDLE gameProcess;
  LPVOID remoteAllocation;
  LPCVOID *patchDescriptorCursorAt42F620;
  LPCVOID *patchDescriptorCursorAt42F720;
  LPCVOID *patchDescriptorCursorAt42F698;
  char *patchCodeCursorAt41F930;
  int patchIndexAt41F920;
  LPCVOID *patchDescriptorCursorAt42F748;
  LPCVOID *patchDescriptorCursorAt42F6F0;
  LPCVOID *patchDescriptorCursorAt42F7D8;
  LPCVOID *patchDescriptorCursorAt42F588;
  LPCVOID *patchDescriptorCursorAt42F6C8;
  LPCVOID *patchDescriptorCursorAt42F610;
  LPCVOID *patchDescriptorCursorAt42F770;
  LPCVOID *patchDescriptorCursorAt42F708;
  LPCVOID *patchDescriptorCursorAt42F5A0;
  LPCVOID *patchDescriptorCursorAt42F668;
  LPCVOID *patchDescriptorCursorAt42F7C0;
  LPCVOID *patchDescriptorCursorAt42F5E0;
  LPCVOID *patchDescriptorCursorAt42F5F0;
  LPCVOID *patchDescriptorCursorAt42F798;
  LPCVOID *patchDescriptorCursorAt42F600;
  LPCVOID *patchDescriptorCursorAt42F7F0;
  LPCVOID *patchDescriptorCursorAt42F680;
  LPCVOID *patchDescriptorCursorAt42F650;
  int patchIndexAt42B890;
  int patchIndexAt42B908;
  int *patchCodeCursorAt42B990;
  int patchIndexAt42B970;
  int patchIndexAt42B9D0;
  UINT messageId;
  char *patchCodeCursorAt41F848;
  int patchIndexAt41F818;
  int *patchCodeCursorAt425870;
  int patchIndexAt425840;
  LPCVOID *patchDescriptorCursorAt42CF70;
  LPCVOID *patchDescriptorCursorAt41FA60;
  LPVOID *patchDescriptorCursorAt422918;
  LPCVOID *patchDescriptorCursorAt42CE40;
  int patchIndexAt4258D0;
  LPCVOID *patchDescriptorCursorAt426698;
  int patchIndexAt428000;
  LPCVOID *patchDescriptorCursorAt42B698;
  int patchIndexAt42C134;
  int patchIndexAt42CA78;
  int patchIndexAt42CADC;
  int patchIndexAt42CB74;
  LPCVOID *patchDescriptorCursorAt42CD48;
  LPCVOID *patchDescriptorCursorAt42D0C8;
  LPCVOID *patchDescriptorCursorAt42D340;
  LPCVOID *patchDescriptorCursorAt42D7C0;
  LPVOID *patchDescriptorCursorAt42C258;
  LPVOID *patchDescriptorCursorAt42C620;
  BOOL writeSucceeded;
  int selectedSoldierCommandKillerIndexBias;
  int selectedNpcAllieAttackIndexBias;
  int selectedDisableBurnIndexBias;
  int selectedEnableRelayDispatchIndexBias;
  int selectedEnableCityPopulationCoefIndexBias;
  DWORD lastError;
  int nextStatusTicks;
  // 原变量复用为写入值、旧页保护或错误编号；各用途沿用原调用顺序。
  DWORD writeValueOrError;
  int initializationValue;

  initializationValue = 1;
  writeValueOrError = 0;
  gameWindow = findGameWindow(ClassName, nullptr);
  if ( gameWindow != nullptr )
  {
    if ( *(HWND *)(state + san9::layout2026::TargetWindow) == gameWindow )
    {
      if ( reason != ModifyReason2026::ParametersConfirmed )
      {
        if ( reason != ModifyReason2026::GameNotification && reason != ModifyReason2026::GameDialogClosed )
        {
          if ( reason != ModifyReason2026::TimerTick )
            goto finishModification;
          goto animateStatus;
        }
applyConfiguration:
        applyGameConfiguration(reason);
animateStatus:
        nextStatusTicks = *(_DWORD *)(state + san9::layout2026::StatusTicks) + 1;
        *(_DWORD *)(state + san9::layout2026::StatusTicks) = nextStatusTicks;
        if (nextStatusTicks < 1) goto finishModification;
        setStatus(RuntimeStatusKind2026::Connected);
        status_.errorCount = *(_DWORD *)(state + san9::layout2026::ErrorCount);
        status_.activityDots = unsigned(nextStatusTicks - 1);
        if (*(_DWORD *)(state + san9::layout2026::StatusTicks) == 6)
            *(_DWORD *)(state + san9::layout2026::StatusTicks) = 0;
displayStatus:
        goto finishModification;
      }
    }
    else
    {
      connectTicks = *(_DWORD *)(state + san9::layout2026::ConnectTicks) + 1;
      *(_DWORD *)(state + san9::layout2026::ConnectTicks) = connectTicks;
      if ( connectTicks <= 5 )
        goto finishModification;
      *(_DWORD *)(state + san9::layout2026::ConnectTicks) = 0;
      *(_DWORD *)(state + san9::layout2026::StatusTicks) = 0;
      *(_DWORD *)(state + san9::layout2026::TargetWindow) = reinterpret_cast<DWORD>(gameWindow);
      resolveProcess(gameWindow, (LPDWORD)(state + san9::layout2026::ProcessId));
      gameProcess = openProcess(0x38u, false, *(_DWORD *)(state + san9::layout2026::ProcessId));
      *(_DWORD *)(state + san9::layout2026::ProcessHandle) = reinterpret_cast<DWORD>(gameProcess);
      if ( gameProcess == nullptr )
      {
        *(_DWORD *)(state + san9::layout2026::TargetWindow) = 0;
        setStatus(RuntimeStatusKind2026::OpenFailed);
        goto finishModification;
      }
      if ( (unsigned __int8)checkVersion() == 0 )
      {
        *(_DWORD *)(state + san9::layout2026::TargetWindow) = 0;
        closeProcess(*(HANDLE *)(state + san9::layout2026::ProcessHandle));
        *(_DWORD *)(state + san9::layout2026::ProcessHandle) = 0;
        setStatus(RuntimeStatusKind2026::UnsupportedVersion);
        goto finishModification;
      }
      if ( !protectMemory(
              *(HANDLE *)(state + san9::layout2026::ProcessHandle),
              *(LPVOID *)(state + 7448),
              *(_DWORD *)(state + san9::injection2026::PageSize),
              0x40u,
              &writeValueOrError) )
      {
        writeValueOrError = 600;
reportWriteFailure:
    // 记录原调用错误编号；真正的内存传输失败会由事务层抛出。
        lastError = GetLastError();
        setStatus(RuntimeStatusKind2026::WriteFailed);
        status_.writeStage = writeValueOrError;
        status_.systemError = lastError;
        ++*(_DWORD *)(state + san9::layout2026::ErrorCount);
        *(_DWORD *)(state + san9::layout2026::StatusTicks) = -8;
        goto displayStatus;
      }
      if ( !protectMemory(
              *(HANDLE *)(state + san9::layout2026::ProcessHandle),
              *(LPVOID *)(state + 7452),
              *(_DWORD *)(state + san9::injection2026::PageSize),
              4u,
              &writeValueOrError) )
      {
        writeValueOrError = 601;
        goto reportWriteFailure;
      }
      if ( !protectMemory(
              *(HANDLE *)(state + san9::layout2026::ProcessHandle),
              *(LPVOID *)(state + 7456),
              *(_DWORD *)(state + san9::injection2026::PageSize),
              4u,
              &writeValueOrError) )
      {
        writeValueOrError = 605;
        goto reportWriteFailure;
      }
      if ( !protectMemory(
              *(HANDLE *)(state + san9::layout2026::ProcessHandle),
              *(LPVOID *)(state + 7468),
              *(_DWORD *)(state + san9::injection2026::PageSize),
              0x40u,
              &writeValueOrError) )
      {
        writeValueOrError = 604;
        goto reportWriteFailure;
      }
      remoteAllocation = allocateMemory(
             *(HANDLE *)(state + san9::layout2026::ProcessHandle),
             nullptr,
             *(_DWORD *)(state + san9::injection2026::PageSize) * *(_DWORD *)(state + san9::injection2026::AllocPageNum),
             0x1000u,
             0x40u);
      *(_DWORD *)(state + san9::layout2026::AllocationBase) = reinterpret_cast<DWORD>(remoteAllocation);
      if ( remoteAllocation == nullptr )
      {
        setStatus(RuntimeStatusKind2026::AllocationFailed);
        goto finishModification;
      }
      if ( rebase() != 0 )
        lpAddress = reinterpret_cast<LPVOID>(*(_DWORD *)(state + san9::layout2026::AllocationBase));
      *(_DWORD *)(state + san9::layout2026::EventSequence) = 0;
      patchDescriptorCursorAt42F620 = (LPCVOID *)&unk_42F620;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F620 - 2), *patchDescriptorCursorAt42F620, (SIZE_T)*(patchDescriptorCursorAt42F620 - 1), nullptr) )
        {
          writeValueOrError = 19;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F620 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F620 < (int)dword_42F650 );
      patchDescriptorCursorAt42F720 = dword_42F720;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F720 - 2), *patchDescriptorCursorAt42F720, (SIZE_T)*(patchDescriptorCursorAt42F720 - 1), nullptr) )
        {
          writeValueOrError = 35;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F720 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F720 < (int)&dword_42F744 );
      patchDescriptorCursorAt42F698 = dword_42F698;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F698 - 2), *patchDescriptorCursorAt42F698, (SIZE_T)*(patchDescriptorCursorAt42F698 - 1), nullptr) )
        {
          writeValueOrError = 23;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F698 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F698 < (int)dword_42F6C8 );
      patchCodeCursorAt41F930 = (char *)&unk_41F930;
      patchIndexAt41F920 = 0;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)dword_41F920[patchIndexAt41F920], patchCodeCursorAt41F930, dword_41F928[patchIndexAt41F920], nullptr) )
        {
          writeValueOrError = 57;
          goto reportWriteFailure;
        }
        patchCodeCursorAt41F930 += 16;
        ++patchIndexAt41F920;
      }
      while ( (int)patchCodeCursorAt41F930 < (int)byte_41F950 );
      patchDescriptorCursorAt42F748 = (LPCVOID *)&unk_42F748;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F748 - 2), *patchDescriptorCursorAt42F748, (SIZE_T)*(patchDescriptorCursorAt42F748 - 1), nullptr) )
        {
          writeValueOrError = 44;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F748 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F748 < (int)&dword_42F76C );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), lpBaseAddress, &codeDefenceHorseWimble, 0xFu, nullptr) )
      {
        writeValueOrError = 24;
        goto reportWriteFailure;
      }
      patchDescriptorCursorAt42F6F0 = (LPCVOID *)&unk_42F6F0;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F6F0 - 2), *patchDescriptorCursorAt42F6F0, (SIZE_T)*(patchDescriptorCursorAt42F6F0 - 1), nullptr) )
        {
          writeValueOrError = 30;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F6F0 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F6F0 < (int)dword_42F708 );
      patchDescriptorCursorAt42F7D8 = dword_42F7D8;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F7D8 - 2), *patchDescriptorCursorAt42F7D8, (SIZE_T)*(patchDescriptorCursorAt42F7D8 - 1), nullptr) )
        {
          writeValueOrError = 26;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F7D8 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F7D8 < (int)dword_42F7F0 );
      patchDescriptorCursorAt42F588 = (LPCVOID *)&unk_42F588;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F588 - 2), *patchDescriptorCursorAt42F588, (SIZE_T)*(patchDescriptorCursorAt42F588 - 1), nullptr) )
        {
          writeValueOrError = 10;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F588 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F588 < (int)dword_42F5A0 );
      patchDescriptorCursorAt42F6C8 = dword_42F6C8;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F6C8 - 2), *patchDescriptorCursorAt42F6C8, (SIZE_T)*(patchDescriptorCursorAt42F6C8 - 1), nullptr) )
        {
          writeValueOrError = 27;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F6C8 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F6C8 < (int)&dword_42F6EC );
      patchDescriptorCursorAt42F610 = (LPCVOID *)&dword_42F610;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F610 - 2), *patchDescriptorCursorAt42F610, (SIZE_T)*(patchDescriptorCursorAt42F610 - 1), nullptr) )
        {
          writeValueOrError = 16;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F610 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F610 < (int)&dword_42F61C );
      patchDescriptorCursorAt42F770 = (LPCVOID *)&unk_42F770;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F770 - 2), *patchDescriptorCursorAt42F770, (SIZE_T)*(patchDescriptorCursorAt42F770 - 1), nullptr) )
        {
          writeValueOrError = 46;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F770 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F770 < (int)&dword_42F794 );
      patchDescriptorCursorAt42F708 = dword_42F708;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F708 - 2), *patchDescriptorCursorAt42F708, (SIZE_T)*(patchDescriptorCursorAt42F708 - 1), nullptr) )
        {
          writeValueOrError = 33;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F708 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F708 < (int)dword_42F720 );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421640, &codeWisdomAntiBlackArt, 0xEu, nullptr) )
      {
        writeValueOrError = 29;
        goto reportWriteFailure;
      }
      patchDescriptorCursorAt42F5A0 = dword_42F5A0;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F5A0 - 2), *patchDescriptorCursorAt42F5A0, (SIZE_T)*(patchDescriptorCursorAt42F5A0 - 1), nullptr) )
        {
          writeValueOrError = 13;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F5A0 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F5A0 < (int)&dword_42F5DC );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420510, &codeLowerBuildExpense, 9u, nullptr) )
      {
        writeValueOrError = 38;
        goto reportWriteFailure;
      }
      patchDescriptorCursorAt42F668 = dword_42F668;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F668 - 2), *patchDescriptorCursorAt42F668, (SIZE_T)*(patchDescriptorCursorAt42F668 - 1), nullptr) )
        {
          writeValueOrError = 21;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F668 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F668 < (int)dword_42F680 );
      patchDescriptorCursorAt42F7C0 = (LPCVOID *)&unk_42F7C0;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F7C0 - 2), *patchDescriptorCursorAt42F7C0, (SIZE_T)*(patchDescriptorCursorAt42F7C0 - 1), nullptr) )
        {
          writeValueOrError = 48;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F7C0 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F7C0 < (int)dword_42F7D8 );
      patchDescriptorCursorAt42F5E0 = (LPCVOID *)&dword_42F5E0;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F5E0 - 2), *patchDescriptorCursorAt42F5E0, (SIZE_T)*(patchDescriptorCursorAt42F5E0 - 1), nullptr) )
        {
          writeValueOrError = 15;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F5E0 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F5E0 < (int)&dword_42F5EC );
      patchDescriptorCursorAt42F5F0 = (LPCVOID *)&dword_42F5F0;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F5F0 - 2), *patchDescriptorCursorAt42F5F0, (SIZE_T)*(patchDescriptorCursorAt42F5F0 - 1), nullptr) )
        {
          writeValueOrError = 17;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F5F0 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F5F0 < (int)&dword_42F5FC );
      patchDescriptorCursorAt42F798 = (LPCVOID *)&unk_42F798;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F798 - 2), *patchDescriptorCursorAt42F798, (SIZE_T)*(patchDescriptorCursorAt42F798 - 1), nullptr) )
        {
          writeValueOrError = 47;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F798 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F798 < (int)&dword_42F7BC );
      patchDescriptorCursorAt42F600 = (LPCVOID *)&dword_42F600;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F600 - 2), *patchDescriptorCursorAt42F600, (SIZE_T)*(patchDescriptorCursorAt42F600 - 1), nullptr) )
        {
          writeValueOrError = 18;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F600 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F600 < (int)&dword_42F60C );
      patchDescriptorCursorAt42F7F0 = dword_42F7F0;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F7F0 - 2), *patchDescriptorCursorAt42F7F0, (SIZE_T)*(patchDescriptorCursorAt42F7F0 - 1), nullptr) )
        {
          writeValueOrError = 3;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F7F0 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F7F0 < (int)&dword_42F808 );
      patchDescriptorCursorAt42F680 = dword_42F680;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F680 - 2), *patchDescriptorCursorAt42F680, (SIZE_T)*(patchDescriptorCursorAt42F680 - 1), nullptr) )
        {
          writeValueOrError = 22;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F680 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F680 < (int)dword_42F698 );
      patchDescriptorCursorAt42F650 = dword_42F650;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42F650 - 2), *patchDescriptorCursorAt42F650, (SIZE_T)*(patchDescriptorCursorAt42F650 - 1), nullptr) )
        {
          writeValueOrError = 20;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42F650 += 3;
      }
      while ( (int)patchDescriptorCursorAt42F650 < (int)dword_42F668 );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4215D4, &codeIntelligenceKillerCoef, 8u, nullptr) )
      {
        writeValueOrError = 25;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421608, &codeIntelligenceKillerCoef2, 9u, nullptr) )
      {
        writeValueOrError = 4;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422598, &codeTreasureValue, 9u, nullptr) )
      {
        writeValueOrError = 14;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423888, &codeOfficialLoyaty, 0xBu, nullptr) )
      {
        writeValueOrError = 36;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4244C0, &codeBuildRealGoal, 0xFu, nullptr) )
      {
        writeValueOrError = 52;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422D60, &codeSetForceGoal, 0xBu, nullptr) )
      {
        writeValueOrError = 54;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425A10, &codeGetCityMaxPeopleHeart, 0xFu, nullptr) )
      {
        writeValueOrError = 45;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0D0, &unk_4298B8, 0x36u, nullptr) )
      {
        writeValueOrError = 55;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0CC, &unk_429918, 0x14u, nullptr) )
      {
        writeValueOrError = 1154;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420014, &codeTestDarkFlag, 0xDu, nullptr) )
      {
        writeValueOrError = 56;
        goto reportWriteFailure;
      }
      for ( patchIndexAt42B890 = 0; patchIndexAt42B890 < 4; ++patchIndexAt42B890 )
      {
        if ( !writeMemory(
                *(HANDLE *)(state + san9::layout2026::ProcessHandle),
                (LPVOID)dword_42B890[patchIndexAt42B890],
                (char *)&unk_42B8C0 + dword_42B8B0[patchIndexAt42B890],
                dword_42B8A0[patchIndexAt42B890],
                nullptr) )
        {
          writeValueOrError = 60;
          goto reportWriteFailure;
        }
      }
      for ( patchIndexAt42B908 = 0; patchIndexAt42B908 < 4; ++patchIndexAt42B908 )
      {
        if ( !writeMemory(
                *(HANDLE *)(state + san9::layout2026::ProcessHandle),
                (LPVOID)dword_42B908[patchIndexAt42B908],
                (char *)&unk_42B938 + dword_42B928[patchIndexAt42B908],
                dword_42B918[patchIndexAt42B908],
                nullptr) )
        {
          writeValueOrError = 61;
          goto reportWriteFailure;
        }
      }
      patchCodeCursorAt42B990 = (int *)&unk_42B990;
      patchIndexAt42B970 = 0;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)dword_42B970[patchIndexAt42B970], patchCodeCursorAt42B990, dword_42B980[patchIndexAt42B970], nullptr) )
        {
          writeValueOrError = 62;
          goto reportWriteFailure;
        }
        patchCodeCursorAt42B990 += 4;
        ++patchIndexAt42B970;
      }
      while ( (int)patchCodeCursorAt42B990 < (int)dword_42B9D0 );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F56C, &unk_4201BC, 0x20u, nullptr) )
      {
        writeValueOrError = 631;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F568, &unk_4201DC, 0x20u, nullptr) )
      {
        writeValueOrError = 766;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3DC, &unk_423D8C, 0x18u, nullptr) )
      {
        writeValueOrError = 808;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7620), &unk_41CD60, 0x4Du, nullptr) )
      {
        writeValueOrError = 450;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 5216), &unk_42DDE0, 0xCu, nullptr) )
      {
        writeValueOrError = 480;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420008, &btMapKillerPower, 8u, nullptr) )
      {
        writeValueOrError = 481;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F578, &codeChaseFlag, 0x39u, nullptr) )
      {
        writeValueOrError = 613;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F564, &codeDispatchPerson, 0x86u, nullptr) )
      {
        writeValueOrError = 633;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F560, &unk_4202B0, 0xF4u, nullptr) )
      {
        writeValueOrError = 1096;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F530, &codeBuildingTotalSoldier, 0x8Fu, nullptr) )
      {
        writeValueOrError = 649;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F514, &unk_421230, 0x2D4u, nullptr) )
      {
        writeValueOrError = 663;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F50C, &codeEnableCommerce, 0x6Au, nullptr) )
      {
        writeValueOrError = 669;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F508, &codeCheckAbuse, 0x52u, nullptr) )
      {
        writeValueOrError = 671;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4F8, &codeSaveTroopExpense, 0x2Fu, nullptr) )
      {
        writeValueOrError = 679;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4E8, &codeEnableCultivate, 0x85u, nullptr) )
      {
        writeValueOrError = 687;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4D8, &codeCommandAbility, 0x3Fu, nullptr) )
      {
        writeValueOrError = 692;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4CC, &codeJiaXuBack, 0x26u, nullptr) )
      {
        writeValueOrError = 698;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4E4, &codeMoveIdlePerson, 0x1Au, nullptr) )
      {
        writeValueOrError = 709;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4DC, &codeCommandIntAbility, 0x1Eu, nullptr) )
      {
        writeValueOrError = 717;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F104, &codeCaptiveMoney2, 0x26u, nullptr) )
      {
        writeValueOrError = 1109;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4B4, &codeCaptiveMoney, 0xDu, nullptr) )
      {
        writeValueOrError = 725;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4A4, &codeInviteNewPerson, 0x20u, nullptr) )
      {
        writeValueOrError = 733;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4A0, &codeUpdateKillerDamage, 0x2Fu, nullptr) )
      {
        writeValueOrError = 735;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F490, &codeSaveHarbor, 0x31u, nullptr) )
      {
        writeValueOrError = 743;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F48C, &codeGotoNpcCity, 0x66u, nullptr) )
      {
        writeValueOrError = 750;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F480, &codeFightToKiller, 0x17u, nullptr) )
      {
        writeValueOrError = 757;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F46C, &codePreBuildingSoldier, 0x5Cu, nullptr) )
      {
        writeValueOrError = 685;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F458, &codeNearNullCity, 0x5Du, nullptr) )
      {
        writeValueOrError = 767;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F450, &codeAllieAttack, 0x28u, nullptr) )
      {
        writeValueOrError = 775;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F43C, &unk_423110, 0x66u, nullptr) )
      {
        writeValueOrError = 783;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3D8, &codeDecideAttackOk, 0x20u, nullptr) )
      {
        writeValueOrError = 791;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F40C, &unk_4237A8, 0x18u, nullptr) )
      {
        writeValueOrError = 797;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3EC, &codeOperationPerDay, 0xA6u, nullptr) )
      {
        writeValueOrError = 635;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3AC, &codeLeagueSucceed, 0x4Fu, nullptr) )
      {
        writeValueOrError = 815;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3A4, &unk_424420, 0x1Du, nullptr) )
      {
        writeValueOrError = 817;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3B4, &codeGoThroughNearBuilding, 0xC3u, nullptr) )
      {
        writeValueOrError = 825;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3C8, &codeSelectWaterWisdom, 0x2Fu, nullptr) )
      {
        writeValueOrError = 832;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F464, &unk_422BB0, 0x3Cu, nullptr) )
      {
        writeValueOrError = 839;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F378, &unk_424870, 0xBAu, nullptr) )
      {
        writeValueOrError = 852;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3F4, &codeLoadNearMaxSoldier, 0x10u, nullptr) )
      {
        writeValueOrError = 860;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3F0, &codeLoadNearMaxSoldier2, 0x10u, nullptr) )
      {
        writeValueOrError = 860;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F424, &codeTestRegardedBuilding, 0x81u, nullptr) )
      {
        writeValueOrError = 867;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F38C, &codeKillerPowerToDamage, 0x24u, nullptr) )
      {
        writeValueOrError = 876;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F340, &codeGetBuildingProp, 0x28u, nullptr) )
      {
        writeValueOrError = 903;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F330, &unk_4252F8, 0x28u, nullptr) )
      {
        writeValueOrError = 909;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F2C0, &codeGetTransportSoldier, 0x50u, nullptr) )
      {
        writeValueOrError = 920;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F350, &codePhaseErrorAlienate, 0x34u, nullptr) )
      {
        writeValueOrError = 928;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F298, &codeMaxPeopleHeartPush, 0x26u, nullptr) )
      {
        writeValueOrError = 941;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F294, &codeMaxPeopleHeartMov, 0x12u, nullptr) )
      {
        writeValueOrError = 943;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F274, &codeAttackTroopSoldier2, 0xBDu, nullptr) )
      {
        writeValueOrError = 958;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F264, &codePreBuildingSoldier2, 0x118u, nullptr) )
      {
        writeValueOrError = 966;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F254, &codeSecondKillerInterval, 0x2Eu, nullptr) )
      {
        writeValueOrError = 972;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F244, &codeKillerArrayCoef, 0x82u, nullptr) )
      {
        writeValueOrError = 979;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F238, &codeDisplayTroopCondition, 0x6Au, nullptr) )
      {
        writeValueOrError = 984;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F224, &codeTroopAtSmallMap, 0x16u, nullptr) )
      {
        writeValueOrError = 990;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1D4, &unk_4277A8, 0xB5u, nullptr) )
      {
        writeValueOrError = 996;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1C8, &codeAllStrongForce, 0x3Au, nullptr) )
      {
        writeValueOrError = 1001;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1B8, &codeKillerDriveProp, 0x7Au, nullptr) )
      {
        writeValueOrError = 1008;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F354, &codeDirectBigAnimation, 0x16u, nullptr) )
      {
        writeValueOrError = 1013;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F19C, &codeUpdateCaptiveProp, 0x1Fu, nullptr) )
      {
        writeValueOrError = 1019;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F190, &codeRobFood, 0x6Au, nullptr) )
      {
        writeValueOrError = 1027;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F220, &codeGetTroopViewState, 0x1Bu, nullptr) )
      {
        writeValueOrError = 1034;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F208, &codeHideDutyPersonNum, 0x3Eu, nullptr) )
      {
        writeValueOrError = 1040;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1F0, &codeHideCityMorale, 0x18u, nullptr) )
      {
        writeValueOrError = 1053;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1E4, &codeCounselorReportProp, 0x63u, nullptr) )
      {
        writeValueOrError = 1062;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F17C, &codeBuildArriveDay, 0xA9u, nullptr) )
      {
        writeValueOrError = 1066;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F570, &codeRetreatSoldierTroop, 0x14u, nullptr) )
      {
        writeValueOrError = 1071;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F154, &codeHarvest, 0x72u, nullptr) )
      {
        writeValueOrError = 1077;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F130, &codeAutoProcessTask, 0x26u, nullptr) )
      {
        writeValueOrError = 1090;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F120, &codeKillSubPrestige, 0x2Eu, nullptr) )
      {
        writeValueOrError = 1099;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F110, &codeAbilityKillerProp, 0x4Cu, nullptr) )
      {
        writeValueOrError = 1103;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F100, &codeAddWaterKiller, 0x35u, nullptr) )
      {
        writeValueOrError = 1115;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0FC, &codeEnableWaterKiller, 0x10u, nullptr) )
      {
        writeValueOrError = 1117;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0F8, &unk_429220, 0x9Au, nullptr) )
      {
        writeValueOrError = 1113;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0F4, &codeInvestment, 0x62u, nullptr) )
      {
        writeValueOrError = 1126;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0F0, &codeHeartAttackDamage1, 0x28u, nullptr) )
      {
        writeValueOrError = 1128;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0EC, &codeHeartAttackDamage2, 0x13u, nullptr) )
      {
        writeValueOrError = 1130;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0E8, &unk_429410, 0x67u, nullptr) )
      {
        writeValueOrError = 1132;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0E4, &unk_4294F0, 0xF4u, nullptr) )
      {
        writeValueOrError = 1137;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0E0, &unk_429610, 0x5Au, nullptr) )
      {
        writeValueOrError = 1139;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0DC, &unk_429690, 0x70u, nullptr) )
      {
        writeValueOrError = 1141;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0D8, &unk_429728, 0x48u, nullptr) )
      {
        writeValueOrError = 1143;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0D4, &unk_429798, 0xF4u, nullptr) )
      {
        writeValueOrError = 1156;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F070, &unk_42B3F0, 0xECu, nullptr) )
      {
        writeValueOrError = 1158;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F06C, &unk_42B5C8, 0x98u, nullptr) )
      {
        writeValueOrError = 1172;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42B700, sourceVA(lpBuffer), nSize, nullptr) )
      {
        writeValueOrError = 1182;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F068, &unk_42B718, 0x4Fu, nullptr) )
      {
        writeValueOrError = 1168;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F064, aQhld, 0x2Cu, nullptr) )
      {
        writeValueOrError = 1177;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F060, &unk_42B7BC, 0x40u, nullptr) )
      {
        writeValueOrError = 1178;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F05C, &unk_42B850, 0x17u, nullptr) )
      {
        writeValueOrError = 1180;
        goto reportWriteFailure;
      }
      for ( patchIndexAt42B9D0 = 0; patchIndexAt42B9D0 < 6; ++patchIndexAt42B9D0 )
      {
        if ( !writeMemory(
                *(HANDLE *)(state + san9::layout2026::ProcessHandle),
                (LPVOID)dword_42B9D0[patchIndexAt42B9D0],
                (char *)&unk_42BA18 + dword_42BA00[patchIndexAt42B9D0],
                dword_42B9E8[patchIndexAt42B9D0],
                nullptr) )
        {
          writeValueOrError = 63;
          goto reportWriteFailure;
        }
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F058, &unk_42BA48, 0x358u, nullptr) )
      {
        writeValueOrError = 1184;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F054, &unk_42BDE0, 0x1A0u, nullptr) )
      {
        writeValueOrError = 1186;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F050, &unk_42BFA8, 0xA0u, nullptr) )
      {
        writeValueOrError = 1212;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F04C, &unk_42C070, 0xC4u, nullptr) )
      {
        writeValueOrError = 1188;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F048, &unk_42C4F0, 0x4Eu, nullptr) )
      {
        writeValueOrError = 1214;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F044, &unk_42C568, 0x2Eu, nullptr) )
      {
        writeValueOrError = 1216;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F040, &unk_42C5C0, 0x2Au, nullptr) )
      {
        writeValueOrError = 1190;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), off_42C7C8, &unk_42C7CC, 8u, nullptr) )
      {
        writeValueOrError = 1193;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F03C, dword_42C7D4, 0xBEu, nullptr) )
      {
        writeValueOrError = 1199;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F038, &unk_42C894, 0x88u, nullptr) )
      {
        writeValueOrError = 1197;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F034, &unk_42C9D0, 0x20u, nullptr) )
      {
        writeValueOrError = 1195;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F030, &unk_42CA18, 0x2Eu, nullptr) )
      {
        writeValueOrError = 1204;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F02C, &unk_42CC90, 0x72u, nullptr) )
      {
        writeValueOrError = 1210;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F024, &unk_42CE68, 0x6Eu, nullptr) )
      {
        writeValueOrError = 1220;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F020, &unk_42CFF0, 0x9Eu, nullptr) )
      {
        writeValueOrError = 1222;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F01C, aHX, 0x84u, nullptr) )
      {
        writeValueOrError = 1224;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F018, &unk_42D568, 0xAEu, nullptr) )
      {
        writeValueOrError = 1228;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0A8, &unk_42A1B8, 0x24u, nullptr) )
      {
        writeValueOrError = 274;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0A4, &unk_42A1DC, 0x34u, nullptr) )
      {
        writeValueOrError = 275;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0A0, &unk_42A210, 0xECu, nullptr) )
      {
        writeValueOrError = 276;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F09C, &unk_42A2FC, 0x112u, nullptr) )
      {
        writeValueOrError = 277;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F098, &unk_42A410, 0x13Eu, nullptr) )
      {
        writeValueOrError = 278;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F094, &unk_42A578, 0x32u, nullptr) )
      {
        writeValueOrError = 283;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F090, &unk_42A5D8, 0x18Cu, nullptr) )
      {
        writeValueOrError = 285;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F08C, &unk_42A798, 0x6C0u, nullptr) )
      {
        writeValueOrError = 296;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F088, &unk_42AE58, 0x98u, nullptr) )
      {
        writeValueOrError = 297;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F084, &unk_42AEF0, 0x9Cu, nullptr) )
      {
        writeValueOrError = 280;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F080, &unk_42AFB8, 0xFCu, nullptr) )
      {
        writeValueOrError = 287;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F07C, asc_42B0B4, 0xEAu, nullptr) )
      {
        writeValueOrError = 290;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F078, &unk_42B1C8, 0x9Eu, nullptr) )
      {
        writeValueOrError = 292;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F074, &unk_42B2B8, 0xBCu, nullptr) )
      {
        writeValueOrError = 294;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0C8, sub_429958, 0x80u, nullptr) )
      {
        writeValueOrError = 85;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0C4, &unk_4299D8, 0xBAu, nullptr) )
      {
        writeValueOrError = 95;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0C0, &unk_429D18, 0x88u, nullptr) )
      {
        writeValueOrError = 96;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0BC, &unk_429DC8, 0x14u, nullptr) )
      {
        writeValueOrError = 83;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0B8, &unk_429DDC, 0x88u, nullptr) )
      {
        writeValueOrError = 73;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0B4, &unk_42A048, 0x1Au, nullptr) )
      {
        writeValueOrError = 632;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0B0, &unk_42A098, 0x6Eu, nullptr) )
      {
        writeValueOrError = 97;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0AC, &unk_42A158, 0x34u, nullptr) )
      {
        writeValueOrError = 98;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F55C, &codeWisdomPerson, 0x49u, nullptr) )
      {
        writeValueOrError = 620;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F540, &unk_4209C0, 0x59u, nullptr) )
      {
        writeValueOrError = 642;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F534, &codeForceTroopList, 0x40u, nullptr) )
      {
        writeValueOrError = 647;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F524, &codeRelayDispatchOk, 0x27u, nullptr) )
      {
        writeValueOrError = 654;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F51C, &codeBattleDisableTask, 0x72u, nullptr) )
      {
        writeValueOrError = 658;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F504, &codeBuildingBackup, 0x6Au, nullptr) )
      {
        writeValueOrError = 674;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4F4, &unk_421B88, 0x2Eu, nullptr) )
      {
        writeValueOrError = 681;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4E0, &codeCheckOfficerMoney, 0xA7u, nullptr) )
      {
        writeValueOrError = 694;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4C4, &codeDegradePerson, 0x84u, nullptr) )
      {
        writeValueOrError = 707;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4B0, &codeSearchRange, 0x78u, nullptr) )
      {
        writeValueOrError = 727;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F498, &codeBuildingKillerPerson, 0x6Eu, nullptr) )
      {
        writeValueOrError = 737;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F47C, &codeDraftMinMoney, 0x10u, nullptr) )
      {
        writeValueOrError = 759;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F468, &codeGoOnAttack, 0x4Du, nullptr) )
      {
        writeValueOrError = 765;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F454, &codeGetPlayerCity, 0xCDu, nullptr) )
      {
        writeValueOrError = 769;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F444, &codeAttackSourceCity, 0x24u, nullptr) )
      {
        writeValueOrError = 777;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F438, &codeAddCityRelation, 0x5Cu, nullptr) )
      {
        writeValueOrError = 786;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F428, &codeRetryAttackedBuilding, 0x2Bu, nullptr) )
      {
        writeValueOrError = 793;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F404, &codeLeftCleverKiller, 0x35u, nullptr) )
      {
        writeValueOrError = 799;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3E8, &codeSelectAttackArray, 0x1A2u, nullptr) )
      {
        writeValueOrError = 805;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3D4, &codeSetNearAttackFlag, 0x54u, nullptr) )
      {
        writeValueOrError = 809;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3A0, &codeDecideBuild, 0x29u, nullptr) )
      {
        writeValueOrError = 819;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3D0, &codeAdjustAttackSoldier, 0xCu, nullptr) )
      {
        writeValueOrError = 827;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3C0, &codeAntiAttackAntitrap, 0x29u, nullptr) )
      {
        writeValueOrError = 834;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F398, &codeSelectTrainPerson, 0x23u, nullptr) )
      {
        writeValueOrError = 840;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F390, &codeRefuseChange, 0x29u, nullptr) )
      {
        writeValueOrError = 846;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F374, &unk_424958, 0xD0u, nullptr) )
      {
        writeValueOrError = 854;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F430, &codeTestAttackGoalForce, 0x7Fu, nullptr) )
      {
        writeValueOrError = 862;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F420, &codeRegardedBuildingOnAttack, 0x3Eu, nullptr) )
      {
        writeValueOrError = 868;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F368, &codeLinkageKillerToRecord, 0x16u, nullptr) )
      {
        writeValueOrError = 878;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F360, &codeUpdateSeigePower, 0x30u, nullptr) )
      {
        writeValueOrError = 884;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F34C, &codeForceFightTroop, 0x2Au, nullptr) )
      {
        writeValueOrError = 897;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F33C, &codeGetForceDangerCoef, 0x5Bu, nullptr) )
      {
        writeValueOrError = 904;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F380, &codeStopTaskBug, 0x16u, nullptr) )
      {
        writeValueOrError = 912;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F2BC, &codeAutoSaveDocname, 0x15u, nullptr) )
      {
        writeValueOrError = 922;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F2B0, &codePersonExperience, 0x5Du, nullptr) )
      {
        writeValueOrError = 930;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F2A0, &codeIntelligenceOfficerPara, 0x2Fu, nullptr) )
      {
        writeValueOrError = 937;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F290, &codeMaxPeopleHeartBasic, 0x17u, nullptr) )
      {
        writeValueOrError = 945;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F27C, &codeDynamicAddProficiency, 0x46u, nullptr) )
      {
        writeValueOrError = 952;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F270, &codePersonCharNum, 0x8Cu, nullptr) )
      {
        writeValueOrError = 960;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F260, &unk_426220, 0xBDu, nullptr) )
      {
        writeValueOrError = 967;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F250, &unk_426540, 0x100u, nullptr) )
      {
        writeValueOrError = 974;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F54C, &codeDeleteBigPerson, 0x4Fu, nullptr) )
      {
        writeValueOrError = 980;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F230, &codeComparePersonName, 0x35u, nullptr) )
      {
        writeValueOrError = 986;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1E0, &codeBlcokProp, 0x1Eu, nullptr) )
      {
        writeValueOrError = 992;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0BC, &unk_429DC8, 0x14u, nullptr) )
      {
        writeValueOrError = 83;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1B4, &codeClearTroopCurGoal, 0x19u, nullptr) )
      {
        writeValueOrError = 713;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1A4, &codeStrengthKillerBigAnimaiton, 0x21u, nullptr) )
      {
        writeValueOrError = 1015;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F198, aHX_0, 0xBCu, nullptr) )
      {
        writeValueOrError = 1021;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1CC, &codeKillerToBuilding, 0x1Du, nullptr) )
      {
        writeValueOrError = 1029;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F21C, &codeJourneyGoalTroop, 0x1Du, nullptr) )
      {
        writeValueOrError = 1003;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F204, &codeHideInfoMenu, 0x2Du, nullptr) )
      {
        writeValueOrError = 1043;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1F8, &codeHideDownStone, 0x1Au, nullptr) )
      {
        writeValueOrError = 1048;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1EC, &codeHideCityIncome, 0x17u, nullptr) )
      {
        writeValueOrError = 1055;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F188, &codeChaosPowerCoef, 0x40u, nullptr) )
      {
        writeValueOrError = 397;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F170, &codeAttackPlayerBuild, 0xA4u, nullptr) )
      {
        writeValueOrError = 1072;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F150, &unk_4287C8, 0x58u, nullptr) )
      {
        writeValueOrError = 1079;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F144, &unk_428954, 0x60u, nullptr) )
      {
        writeValueOrError = 1124;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F140, &unk_4289E0, 0x22u, nullptr) )
      {
        writeValueOrError = 1084;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F13C, &unk_428A30, 0x98u, nullptr) )
      {
        writeValueOrError = 1162;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F12C, &codeGetLeagueGoal, 0xBCu, nullptr) )
      {
        writeValueOrError = 1092;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F11C, &codeTrainBasicAbility, 0x37u, nullptr) )
      {
        writeValueOrError = 1101;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F10C, &unk_429050, 0x2Du, nullptr) )
      {
        writeValueOrError = 1105;
        goto reportWriteFailure;
      }
      if ( *(_DWORD *)(state + san9::layout2026::MessageId) == 0 )
      {
        messageId = registerRuntimeMessage(String);
        *(_DWORD *)(state + san9::layout2026::MessageId) = messageId;
        if ( messageId == 0 )
        {
          goto reportWriteFailure;
        }
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43F7E4, (LPCVOID)(state + san9::layout2026::OwnerWindow), 0xCu, nullptr) )
      {
        writeValueOrError = 200;
        goto reportWriteFailure;
      }
      patchCodeCursorAt41F848 = (char *)&unk_41F848;
      patchIndexAt41F818 = 0;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)dword_41F818[patchIndexAt41F818], patchCodeCursorAt41F848, dword_41F830[patchIndexAt41F818], nullptr) )
        {
          writeValueOrError = 201;
          goto reportWriteFailure;
        }
        patchCodeCursorAt41F848 += 16;
        ++patchIndexAt41F818;
      }
      while ( (int)patchCodeCursorAt41F848 < (int)byte_41F8A8 );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F574, &codeCheckTroopPos, 0x9Bu, nullptr) )
      {
        writeValueOrError = 618;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F0B4, &unk_42A048, 0x1Au, nullptr) )
      {
        writeValueOrError = 632;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F520, &codeFastRelay, 0x8Bu, nullptr) )
      {
        writeValueOrError = 656;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F550, &unk_4206A8, 0x1A1u, nullptr) )
      {
        writeValueOrError = 616;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F548, &codeAntiAttackMinDefence2, 0xC7u, nullptr) )
      {
        writeValueOrError = 616;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F500, &unk_421914, 0x13Eu, nullptr) )
      {
        writeValueOrError = 675;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4F0, &codeMaxAntiTroop, 0x47u, nullptr) )
      {
        writeValueOrError = 683;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4D0, &codeUndelCommandPerson, 0x19u, nullptr) )
      {
        writeValueOrError = 700;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4BC, &codeArrayImage, 0x23u, nullptr) )
      {
        writeValueOrError = 715;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4B8, &codeTroopExperience, 0x3Cu, nullptr) )
      {
        writeValueOrError = 720;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4AC, &codeSearchCondition, 0x51u, nullptr) )
      {
        writeValueOrError = 729;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F494, &codeNotSureCaptive, 0x13u, nullptr) )
      {
        writeValueOrError = 739;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F488, &codeNewForceSoldier, 0x1Au, nullptr) )
      {
        writeValueOrError = 745;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F474, &codeSafeArriveDay, 0x14u, nullptr) )
      {
        writeValueOrError = 763;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F478, &codeAttackMinMoney, 0x71u, nullptr) )
      {
        writeValueOrError = 761;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F44C, &unk_422EE0, 0x18u, nullptr) )
      {
        writeValueOrError = 771;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422FD0, &codeCircleAttackBuilding, 0xFu, nullptr) )
      {
        writeValueOrError = 779;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F510, &codeCheckGoOnAttack, 0xA2u, nullptr) )
      {
        writeValueOrError = 764;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F414, &unk_423570, 0x1AEu, nullptr) )
      {
        writeValueOrError = 741;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F400, &codeAddOfficialLoyaty, 0x26u, nullptr) )
      {
        writeValueOrError = 801;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3E4, &codeAdjustKiller, 0x55u, nullptr) )
      {
        writeValueOrError = 691;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3B8, &unk_424060, 0x6Bu, nullptr) )
      {
        writeValueOrError = 811;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F408, &codeBeingBuild, 0x13u, nullptr) )
      {
        writeValueOrError = 821;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3BC, &codeAntiAttackWisdom, 0x60u, nullptr) )
      {
        writeValueOrError = 836;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3C4, &codeSelectAttackWisdom, 0x31u, nullptr) )
      {
        writeValueOrError = 842;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F384, &codeDraftFailBug, 0x3Bu, nullptr) )
      {
        writeValueOrError = 848;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3A8, &unk_424310, 0x12u, nullptr) )
      {
        writeValueOrError = 856;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F554, &codeCheckMinDefence, 0x23u, nullptr) )
      {
        writeValueOrError = 863;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F41C, &codeRegardedBuildingOnAttack2, 0x4Eu, nullptr) )
      {
        writeValueOrError = 870;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F370, &codeCheckPersonKillerLevel, 0x40u, nullptr) )
      {
        writeValueOrError = 829;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F388, &codeLinkageKillerToDialog, 0x1Du, nullptr) )
      {
        writeValueOrError = 880;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F35C, &codeGetArrayToWall, 0x21u, nullptr) )
      {
        writeValueOrError = 885;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F348, &codeCheckTransportTask, 0x3Fu, nullptr) )
      {
        writeValueOrError = 899;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F338, &unk_4251F4, 0x50u, nullptr) )
      {
        writeValueOrError = 905;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F2C8, &unk_4253FC, 0x34u, nullptr) )
      {
        writeValueOrError = 895;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F2B8, &codeMultiAlienate, 0x16u, nullptr) )
      {
        writeValueOrError = 924;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F2AC, &codeGetOfficerType, 0x20u, nullptr) )
      {
        writeValueOrError = 932;
        goto reportWriteFailure;
      }
      patchCodeCursorAt425870 = (int *)&unk_425870;
      patchIndexAt425840 = 0;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)dword_425840[patchIndexAt425840], patchCodeCursorAt425870, dword_425858[patchIndexAt425840], nullptr) )
        {
          writeValueOrError = 939;
          goto reportWriteFailure;
        }
        patchCodeCursorAt425870 += 4;
        ++patchIndexAt425840;
      }
      while ( (int)patchCodeCursorAt425870 < (int)dword_4258D0 );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F28C, &codeMaxSoldierPush, 0x14u, nullptr) )
      {
        writeValueOrError = 947;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F288, &unk_425C28, 0x18u, nullptr) )
      {
        writeValueOrError = 1200;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F284, &unk_425C80, 0x12u, nullptr) )
      {
        writeValueOrError = 1202;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F26C, &codeAttackRatioDoor, 0x35u, nullptr) )
      {
        writeValueOrError = 962;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F25C, &codeTroopRetreat, 0x1Cu, nullptr) )
      {
        writeValueOrError = 968;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F24C, &unk_42670C, 0x1Eu, nullptr) )
      {
        writeValueOrError = 976;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F240, &codeGetArrayAttackRange, 0x30u, nullptr) )
      {
        writeValueOrError = 981;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F22C, &codeCheckPlayerViewRange, 0x9Bu, nullptr) )
      {
        writeValueOrError = 987;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1DC, &codeAdjustAttackArray, 0x274u, nullptr) )
      {
        writeValueOrError = 994;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1C4, &codeCheckLongRangeArray, 0x24u, nullptr) )
      {
        writeValueOrError = 1005;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1B0, &codeMoveGuardTroop, 0xBCu, nullptr) )
      {
        writeValueOrError = 1010;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F49C, &codeSoldierCommandKiller, 0x59u, nullptr) )
      {
        writeValueOrError = 1017;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F194, &codeYearTableInfo, 0x17u, nullptr) )
      {
        writeValueOrError = 1023;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1BC, &codeWaterKillerProp, 0x4Eu, nullptr) )
      {
        writeValueOrError = 1031;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F214, &codeFalseGoalTroop, 0x1Au, nullptr) )
      {
        writeValueOrError = 1035;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F200, &codeDamageNumberDown, 0x1Au, nullptr) )
      {
        writeValueOrError = 1045;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1F4, &codeHideSpecialState, 0x17u, nullptr) )
      {
        writeValueOrError = 1050;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F18C, &codeRetreatBuildingCondition, 0x10u, nullptr) )
      {
        writeValueOrError = 1058;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F234, &codeTestPlayerViewRange, 0x75u, nullptr) )
      {
        writeValueOrError = 889;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F184, &codeClearSecondKillerPerson, 0xDu, nullptr) )
      {
        writeValueOrError = 890;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F178, &codeJudgeAttackBuild, 0x2Fu, nullptr) )
      {
        writeValueOrError = 1068;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F15C, &codeMaxBusiness, 0x47u, nullptr) )
      {
        writeValueOrError = 1073;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F14C, &codeGetForceMilitaryPop, 0x28u, nullptr) )
      {
        writeValueOrError = 838;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F138, &codePhaseErrorInvite, 0xAu, nullptr) )
      {
        writeValueOrError = 1086;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F128, &codeFightSubIncome, 0x64u, nullptr) )
      {
        writeValueOrError = 1094;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F118, &codeCheckDraftFood, 0x4Cu, nullptr) )
      {
        writeValueOrError = 639;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F108, &codeGetMaxCaptive, 0x17u, nullptr) )
      {
        writeValueOrError = 1107;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F558, &codeAttackTroopCondition, 0x78u, nullptr) )
      {
        writeValueOrError = 640;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F538, &unk_420A80, 0x64u, nullptr) )
      {
        writeValueOrError = 645;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F52C, &codeRelayFailedDispatch, 0x146u, nullptr) )
      {
        writeValueOrError = 652;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F53C, &unk_420A48, 0x36u, nullptr) )
      {
        writeValueOrError = 644;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F518, &codeCheckAttackTroop, 0x6Bu, nullptr) )
      {
        writeValueOrError = 660;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4FC, &codeAdjustPersonPos, 0x85u, nullptr) )
      {
        writeValueOrError = 677;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4EC, &codeBuildingAntiAttackTroop, 0x34u, nullptr) )
      {
        writeValueOrError = 788;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F544, &unk_420990, 0x2Eu, nullptr) )
      {
        writeValueOrError = 51;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4D4, &codeJiaXuOfficer, 0x54u, nullptr) )
      {
        writeValueOrError = 696;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4C8, &codeIntelligenceAbility, 0x1Eu, nullptr) )
      {
        writeValueOrError = 705;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4C0, &codeStoneStop, 0x7Du, nullptr) )
      {
        writeValueOrError = 711;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F4A8, &codeSearchInvite, 0x29u, nullptr) )
      {
        writeValueOrError = 731;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F484, &codeSubAntiTrick, 0x26u, nullptr) )
      {
        writeValueOrError = 754;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F470, &codeGossipToPlayer, 0x13u, nullptr) )
      {
        writeValueOrError = 752;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F45C, &codeFilterBuildingSoldier, 0x19u, nullptr) )
      {
        writeValueOrError = 689;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F448, &unk_422F20, 0x38u, nullptr) )
      {
        writeValueOrError = 773;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F440, &unk_423010, 0xD4u, nullptr) )
      {
        writeValueOrError = 781;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F42C, &codeReserveAttackedBuilding, 0x1Cu, nullptr) )
      {
        writeValueOrError = 789;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F028, &unk_42CD8C, 0x86u, nullptr) )
      {
        writeValueOrError = 1218;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F410, &unk_423748, 0x36u, nullptr) )
      {
        writeValueOrError = 795;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3FC, &unk_423910, 0x68u, nullptr) )
      {
        writeValueOrError = 803;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3E0, &unk_423D60, 0x2Au, nullptr) )
      {
        writeValueOrError = 807;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3B0, &unk_424258, 0x14u, nullptr) )
      {
        writeValueOrError = 813;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F39C, &codeMaxBuildMoney, 0x31u, nullptr) )
      {
        writeValueOrError = 823;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3CC, &codeCheckWisdomAntitrap, 0x1Eu, nullptr) )
      {
        writeValueOrError = 831;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F394, &unk_4245B0, 0x20u, nullptr) )
      {
        writeValueOrError = 844;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F37C, &codeDraftMinFood, 0x13u, nullptr) )
      {
        writeValueOrError = 850;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F3F8, &unk_4239B8, 0x16u, nullptr) )
      {
        writeValueOrError = 858;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F460, &codePreBuildingSoldier3, 0xA2u, nullptr) )
      {
        writeValueOrError = 612;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F434, &codeTestNotNullCity, 0x29u, nullptr) )
      {
        writeValueOrError = 865;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F418, &codeRegardedBuildingOnAttack3, 0x34u, nullptr) )
      {
        writeValueOrError = 872;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F36C, &codeJudgeKillerLinkage, 0x25u, nullptr) )
      {
        writeValueOrError = 874;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F364, &codeMainForceDispatch, 0x55u, nullptr) )
      {
        writeValueOrError = 882;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F358, &codeGetArrayToGarrison, 0x21u, nullptr) )
      {
        writeValueOrError = 887;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F344, &unk_424DF0, 0x356u, nullptr) )
      {
        writeValueOrError = 901;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F334, &unk_425270, 0x60u, nullptr) )
      {
        writeValueOrError = 907;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F2C4, &codeCheckTransportBlock, 0xACu, nullptr) )
      {
        writeValueOrError = 918;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F2B4, &codeTryInviteCaptive, 0x68u, nullptr) )
      {
        writeValueOrError = 926;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F2A8, &codeCommandOfficerPara, 0x2Bu, nullptr) )
      {
        writeValueOrError = 933;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F29C, &codeMaxPeopleHeartCmp, 0x27u, nullptr) )
      {
        writeValueOrError = 723;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F2A4, &codeDeleteMaxOfficer, 0x12u, nullptr) )
      {
        writeValueOrError = 935;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F280, &codeMaxSoldierCmp, 0x11u, nullptr) )
      {
        writeValueOrError = 949;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F278, &codeAttackTroopSoldier, 0xEAu, nullptr) )
      {
        writeValueOrError = 956;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F268, &codeTroopAtGoodPlace, 0x3Fu, nullptr) )
      {
        writeValueOrError = 964;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F258, &codeSecondKiller, 0x198u, nullptr) )
      {
        writeValueOrError = 970;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F248, &codeGetAntiAttackGarrison, 0x30Bu, nullptr) )
      {
        writeValueOrError = 978;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F23C, &unk_426B40, 0xE0u, nullptr) )
      {
        writeValueOrError = 983;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F228, &codePersonSmallDialog, 0x10u, nullptr) )
      {
        writeValueOrError = 988;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1D8, &codeGetArrayKillerPower, 0x6Cu, nullptr) )
      {
        writeValueOrError = 995;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1D0, &codeChaosLinkageFlag, 0x17u, nullptr) )
      {
        writeValueOrError = 997;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1C0, &codeChangeTroopCommand, 0x1Cu, nullptr) )
      {
        writeValueOrError = 1006;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1A8, &codeUseBaramArray, 0x58u, nullptr) )
      {
        writeValueOrError = 1012;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1A0, &codeWeakenLongRangeKiller, 0x48u, nullptr) )
      {
        writeValueOrError = 1018;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1AC, &codeMonthTableInfo, 0x22u, nullptr) )
      {
        writeValueOrError = 1025;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F218, &codeGetInfoDistance, 0x6Cu, nullptr) )
      {
        writeValueOrError = 1033;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F210, &codeDisplayBuildingCondition, 0xB8u, nullptr) )
      {
        writeValueOrError = 1038;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1FC, &codeGetPlayerForce, 0x1Bu, nullptr) )
      {
        writeValueOrError = 1047;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F20C, &codeGetBuildingViewState, 0x1Cu, nullptr) )
      {
        writeValueOrError = 1052;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1E8, &codeAllocFreeTroop, 0x39u, nullptr) )
      {
        writeValueOrError = 1060;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F180, &codeSkipArriveDay, 0x1C9u, nullptr) )
      {
        writeValueOrError = 892;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F174, &codeGetBuildSoldier, 0xA4u, nullptr) )
      {
        writeValueOrError = 1070;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F158, &codeIncome, 0x6Bu, nullptr) )
      {
        writeValueOrError = 1075;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F148, &codeGetForceStrength, 0x32u, nullptr) )
      {
        writeValueOrError = 1081;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F134, &codePlayerAutoProcess, 0x33u, nullptr) )
      {
        writeValueOrError = 1088;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F124, &codeLeaderInspire, 0xD1u, nullptr) )
      {
        writeValueOrError = 1097;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F114, &codeRetreatChangeArray, 0x1Bu, nullptr) )
      {
        writeValueOrError = 637;
        goto reportWriteFailure;
      }
      patchDescriptorCursorAt42CF70 = (LPCVOID *)&off_42CF70;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42CF70 - 2), sourceVA(*patchDescriptorCursorAt42CF70), (SIZE_T)*(patchDescriptorCursorAt42CF70 - 1), nullptr) )
        {
          writeValueOrError = 1221;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42CF70 += 3;
      }
      while ( (int)patchDescriptorCursorAt42CF70 < (int)&dword_42CFC4 );
      patchDescriptorCursorAt41FA60 = (LPCVOID *)&off_41FA60;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt41FA60 - 2), sourceVA(*patchDescriptorCursorAt41FA60), (SIZE_T)*(patchDescriptorCursorAt41FA60 - 1), nullptr) )
        {
          writeValueOrError = 12;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt41FA60 += 3;
      }
      while ( (int)patchDescriptorCursorAt41FA60 < (int)&off_41FAA8 );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41F960, sourceVA(off_41F968), dword_41F964, nullptr) )
      {
        writeValueOrError = 58;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FB68, sourceVA(off_41FB70), dword_41FB6C, nullptr) )
      {
        writeValueOrError = 112;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422390, sourceVA(off_422398), dword_422394, nullptr) )
      {
        writeValueOrError = 722;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422368, sourceVA(off_422370), dword_42236C, nullptr) )
      {
        writeValueOrError = 721;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FBA8, sourceVA(off_41FBB0), dword_41FBAC, nullptr) )
      {
        writeValueOrError = 115;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FBD0, sourceVA(off_41FBD8), dword_41FBD4, nullptr) )
      {
        writeValueOrError = 116;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FC10, sourceVA(off_41FC18), dword_41FC14, nullptr) )
      {
        writeValueOrError = 118;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FC50, sourceVA(off_41FC58), dword_41FC54, nullptr) )
      {
        writeValueOrError = 119;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FC90, sourceVA(off_41FC98), dword_41FC94, nullptr) )
      {
        writeValueOrError = 117;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FD18, sourceVA(off_41FD20), dword_41FD1C, nullptr) )
      {
        writeValueOrError = 120;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FDC0, sourceVA(off_41FDC8), dword_41FDC4, nullptr) )
      {
        writeValueOrError = 121;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FE18, sourceVA(off_41FE20), dword_41FE1C, nullptr) )
      {
        writeValueOrError = 122;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FE70, sourceVA(off_41FE78), dword_41FE74, nullptr) )
      {
        writeValueOrError = 123;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FF00, sourceVA(off_41FF08), dword_41FF04, nullptr) )
      {
        writeValueOrError = 124;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421518, sourceVA(off_421520), dword_42151C, nullptr) )
      {
        writeValueOrError = 664;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421700, sourceVA(off_421708), dword_421704, nullptr) )
      {
        writeValueOrError = 670;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421D20, sourceVA(off_421D28), dword_421D24, nullptr) )
      {
        writeValueOrError = 688;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FF98, sourceVA(off_41FFA0), dword_41FF9C, nullptr) )
      {
        writeValueOrError = 128;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41FFF0, sourceVA(off_41FFF8), dword_41FFF4, nullptr) )
      {
        writeValueOrError = 130;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4200A0, sourceVA(off_4200A8), dword_4200A4, nullptr) )
      {
        writeValueOrError = 614;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4200C8, sourceVA(off_4200D0), dword_4200CC, nullptr) )
      {
        writeValueOrError = 615;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420690, sourceVA(off_420698), dword_420694, nullptr) )
      {
        writeValueOrError = 864;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420190, sourceVA(off_420198), dword_420194, nullptr) )
      {
        writeValueOrError = 619;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4204F8, sourceVA(off_420500), dword_4204FC, nullptr) )
      {
        writeValueOrError = 132;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420400, sourceVA(off_420408), dword_420404, nullptr) )
      {
        writeValueOrError = 621;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420428, sourceVA(off_420430), dword_42042C, nullptr) )
      {
        writeValueOrError = 622;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420450, sourceVA(off_420458), dword_420454, nullptr) )
      {
        writeValueOrError = 623;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420478, sourceVA(off_420480), dword_42047C, nullptr) )
      {
        writeValueOrError = 624;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4204A0, sourceVA(off_4204A8), dword_4204A4, nullptr) )
      {
        writeValueOrError = 625;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420298, sourceVA(off_4202A0), dword_42029C, nullptr) )
      {
        writeValueOrError = 634;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4205A0, sourceVA(off_4205A8), dword_4205A4, nullptr) )
      {
        writeValueOrError = 134;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420530, sourceVA(off_420538), dword_420534, nullptr) )
      {
        writeValueOrError = 137;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420640, sourceVA(off_420648), dword_420644, nullptr) )
      {
        writeValueOrError = 641;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420AF8, sourceVA(off_420B00), dword_420AFC, nullptr) )
      {
        writeValueOrError = 646;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420860, sourceVA(off_420868), dword_420864, nullptr) )
      {
        writeValueOrError = 617;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420A30, sourceVA(off_420A38), dword_420A34, nullptr) )
      {
        writeValueOrError = 643;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420B68, sourceVA(off_420B70), dword_420B6C, nullptr) )
      {
        writeValueOrError = 143;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420BD0, sourceVA(off_420BD8), dword_420BD4, nullptr) )
      {
        writeValueOrError = 648;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420C88, sourceVA(off_420C90), dword_420C8C, nullptr) )
      {
        writeValueOrError = 650;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424BB0, sourceVA(off_424BB8), dword_424BB4, nullptr) )
      {
        writeValueOrError = 883;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420CF8, sourceVA(off_420D00), dword_420CFC, nullptr) )
      {
        writeValueOrError = 145;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420E68, sourceVA(off_420E70), dword_420E6C, nullptr) )
      {
        writeValueOrError = 653;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420EB8, sourceVA(off_420EC0), dword_420EBC, nullptr) )
      {
        writeValueOrError = 655;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420F70, sourceVA(off_420F78), dword_420F74, nullptr) )
      {
        writeValueOrError = 657;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420FE0, sourceVA(off_420FE8), dword_420FE4, nullptr) )
      {
        writeValueOrError = 146;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4210D8, sourceVA(off_4210E0), dword_4210DC, nullptr) )
      {
        writeValueOrError = 147;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421168, sourceVA(off_421170), dword_42116C, nullptr) )
      {
        writeValueOrError = 661;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421180, sourceVA(off_421188), dword_421184, nullptr) )
      {
        writeValueOrError = 662;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421080, sourceVA(off_421088), dword_421084, nullptr) )
      {
        writeValueOrError = 659;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4215F0, sourceVA(off_4215F8), dword_4215F4, nullptr) )
      {
        writeValueOrError = 126;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421628, sourceVA(off_421630), dword_42162C, nullptr) )
      {
        writeValueOrError = 103;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421668, sourceVA(off_421670), dword_42166C, nullptr) )
      {
        writeValueOrError = 129;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421740, sourceVA(off_421748), dword_421744, nullptr) )
      {
        writeValueOrError = 125;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421868, sourceVA(off_421870), dword_42186C, nullptr) )
      {
        writeValueOrError = 672;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421890, sourceVA(off_421898), dword_421894, nullptr) )
      {
        writeValueOrError = 673;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421A68, sourceVA(off_421A70), dword_421A6C, nullptr) )
      {
        writeValueOrError = 676;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421B18, sourceVA(off_421B20), dword_421B1C, nullptr) )
      {
        writeValueOrError = 678;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421B70, sourceVA(off_421B78), dword_421B74, nullptr) )
      {
        writeValueOrError = 680;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421BC8, sourceVA(off_421BD0), dword_421BCC, nullptr) )
      {
        writeValueOrError = 682;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421C38, sourceVA(off_421C40), dword_421C3C, nullptr) )
      {
        writeValueOrError = 684;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422B48, sourceVA(off_422B50), dword_422B4C, nullptr) )
      {
        writeValueOrError = 686;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421E90, sourceVA(off_421E98), dword_421E94, nullptr) )
      {
        writeValueOrError = 695;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421EE8, sourceVA(off_421EF0), dword_421EEC, nullptr) )
      {
        writeValueOrError = 102;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421F88, sourceVA(off_421F90), dword_421F8C, nullptr) )
      {
        writeValueOrError = 693;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422008, sourceVA(off_422010), dword_42200C, nullptr) )
      {
        writeValueOrError = 697;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422050, sourceVA(off_422058), dword_422054, nullptr) )
      {
        writeValueOrError = 701;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422078, sourceVA(off_422080), dword_42207C, nullptr) )
      {
        writeValueOrError = 702;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422118, sourceVA(off_422120), dword_42211C, nullptr) )
      {
        writeValueOrError = 699;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4220A0, sourceVA(off_4220A8), dword_4220A4, nullptr) )
      {
        writeValueOrError = 703;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4220C8, sourceVA(off_4220D0), dword_4220CC, nullptr) )
      {
        writeValueOrError = 704;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422158, sourceVA(off_422160), dword_42215C, nullptr) )
      {
        writeValueOrError = 706;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422208, sourceVA(off_422210), dword_42220C, nullptr) )
      {
        writeValueOrError = 708;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421D68, sourceVA(off_421D70), dword_421D6C, nullptr) )
      {
        writeValueOrError = 710;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421DC0, sourceVA(off_421DC8), dword_421DC4, nullptr) )
      {
        writeValueOrError = 127;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422300, sourceVA(off_422308), dword_422304, nullptr) )
      {
        writeValueOrError = 716;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4222B0, sourceVA(off_4222B8), dword_4222B4, nullptr) )
      {
        writeValueOrError = 712;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421F28, sourceVA(off_421F30), dword_421F2C, nullptr) )
      {
        writeValueOrError = 718;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429120, sourceVA(off_429128), dword_429124, nullptr) )
      {
        writeValueOrError = 1110;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4223C8, sourceVA(off_4223D0), dword_4223CC, nullptr) )
      {
        writeValueOrError = 726;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422468, sourceVA(off_422470), dword_42246C, nullptr) )
      {
        writeValueOrError = 728;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4224E0, sourceVA(off_4224E8), dword_4224E4, nullptr) )
      {
        writeValueOrError = 730;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422538, sourceVA(off_422540), dword_42253C, nullptr) )
      {
        writeValueOrError = 732;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422580, sourceVA(off_422588), dword_422584, nullptr) )
      {
        writeValueOrError = 734;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4225B8, sourceVA(off_4225C0), dword_4225BC, nullptr) )
      {
        writeValueOrError = 114;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422610, sourceVA(off_422618), dword_422614, nullptr) )
      {
        writeValueOrError = 736;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422708, sourceVA(off_422710), dword_42270C, nullptr) )
      {
        writeValueOrError = 738;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4227A8, sourceVA(off_4227B0), dword_4227AC, nullptr) )
      {
        writeValueOrError = 744;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422880, sourceVA(off_422888), dword_422884, nullptr) )
      {
        writeValueOrError = 746;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4211A0, sourceVA(off_4211A8), dword_4211A4, nullptr) )
      {
        writeValueOrError = 747;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4211B8, sourceVA(off_4211C0), dword_4211BC, nullptr) )
      {
        writeValueOrError = 748;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4211D0, sourceVA(off_4211D8), dword_4211D4, nullptr) )
      {
        writeValueOrError = 749;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4211E8, sourceVA(off_4211F0), dword_4211EC, nullptr) )
      {
        writeValueOrError = 785;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421200, sourceVA(off_421208), dword_421204, nullptr) )
      {
        writeValueOrError = 785;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421218, sourceVA(off_421220), dword_42121C, nullptr) )
      {
        writeValueOrError = 785;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422838, sourceVA(off_422840), dword_42283C, nullptr) )
      {
        writeValueOrError = 751;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4228D0, sourceVA(off_4228D8), dword_4228D4, nullptr) )
      {
        writeValueOrError = 755;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4228F8, sourceVA(off_422900), dword_4228FC, nullptr) )
      {
        writeValueOrError = 756;
        goto reportWriteFailure;
      }
      patchDescriptorCursorAt422918 = (LPVOID *)&unk_422918;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *patchDescriptorCursorAt422918, &unk_422910, 4u, nullptr) )
        {
          writeValueOrError = 131;
          goto reportWriteFailure;
        }
        ++patchDescriptorCursorAt422918;
      }
      while ( (int)patchDescriptorCursorAt422918 < (int)&dword_422948 );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422958, sourceVA(off_422960), dword_42295C, nullptr) )
      {
        writeValueOrError = 133;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4229D0, sourceVA(off_4229D8), dword_4229D4, nullptr) )
      {
        writeValueOrError = 760;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422A70, sourceVA(off_422A78), dword_422A74, nullptr) )
      {
        writeValueOrError = 762;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422AC0, sourceVA(off_422AC8), dword_422AC4, nullptr) )
      {
        writeValueOrError = 753;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422CC0, sourceVA(off_422CC8), dword_422CC4, nullptr) )
      {
        writeValueOrError = 690;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422D48, sourceVA(off_422D50), dword_422D4C, nullptr) )
      {
        writeValueOrError = 768;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422E78, sourceVA(off_422E80), dword_422E7C, nullptr) )
      {
        writeValueOrError = 770;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422F08, sourceVA(off_422F10), dword_422F0C, nullptr) )
      {
        writeValueOrError = 772;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422F68, sourceVA(off_422F70), dword_422F6C, nullptr) )
      {
        writeValueOrError = 774;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422EC8, sourceVA(off_422ED0), dword_422ECC, nullptr) )
      {
        writeValueOrError = 776;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422FB8, sourceVA(off_422FC0), dword_422FBC, nullptr) )
      {
        writeValueOrError = 778;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422FF8, sourceVA(off_423000), dword_422FFC, nullptr) )
      {
        writeValueOrError = 780;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4230F8, sourceVA(off_423100), dword_4230FC, nullptr) )
      {
        writeValueOrError = 782;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423190, sourceVA(off_423198), dword_423194, nullptr) )
      {
        writeValueOrError = 784;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42B5B0, sourceVA(off_42B5B8), dword_42B5B4, nullptr) )
      {
        writeValueOrError = 1170;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423218, sourceVA(off_423220), dword_42321C, nullptr) )
      {
        writeValueOrError = 787;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423338, sourceVA(off_423340), dword_42333C, nullptr) )
      {
        writeValueOrError = 790;
        goto reportWriteFailure;
      }
      patchDescriptorCursorAt42CE40 = (LPCVOID *)&off_42CE40;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42CE40 - 2), sourceVA(*patchDescriptorCursorAt42CE40), (SIZE_T)*(patchDescriptorCursorAt42CE40 - 1), nullptr) )
        {
          writeValueOrError = 1219;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42CE40 += 3;
      }
      while ( (int)patchDescriptorCursorAt42CE40 < (int)&off_42CE58 );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423DD8, sourceVA(off_423DE0), dword_423DDC, nullptr) )
      {
        writeValueOrError = 792;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423390, sourceVA(off_423398), dword_423394, nullptr) )
      {
        writeValueOrError = 794;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423730, sourceVA(off_423738), dword_423734, nullptr) )
      {
        writeValueOrError = 742;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423790, sourceVA(off_423798), dword_423794, nullptr) )
      {
        writeValueOrError = 796;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4237D0, sourceVA(off_4237D8), dword_4237D4, nullptr) )
      {
        writeValueOrError = 798;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423870, sourceVA(off_423878), dword_423874, nullptr) )
      {
        writeValueOrError = 800;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4238A8, sourceVA(off_4238B0), dword_4238AC, nullptr) )
      {
        writeValueOrError = 135;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4238F8, sourceVA(off_423900), dword_4238FC, nullptr) )
      {
        writeValueOrError = 802;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4239A0, sourceVA(off_4239A8), dword_4239A4, nullptr) )
      {
        writeValueOrError = 804;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423CF0, sourceVA(off_423CF8), dword_423CF4, nullptr) )
      {
        writeValueOrError = 806;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423E58, sourceVA(off_423E60), dword_423E5C, nullptr) )
      {
        writeValueOrError = 810;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4240E0, sourceVA(off_4240E8), dword_4240E4, nullptr) )
      {
        writeValueOrError = 812;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424280, sourceVA(off_424288), dword_424284, nullptr) )
      {
        writeValueOrError = 814;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4242F8, sourceVA(off_424300), dword_4242FC, nullptr) )
      {
        writeValueOrError = 816;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424450, sourceVA(off_424458), dword_424454, nullptr) )
      {
        writeValueOrError = 818;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4244A8, sourceVA(off_4244B0), dword_4244AC, nullptr) )
      {
        writeValueOrError = 820;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423810, sourceVA(off_423818), dword_423814, nullptr) )
      {
        writeValueOrError = 822;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424108, sourceVA(off_424110), dword_42410C, nullptr) )
      {
        writeValueOrError = 142;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4244E8, sourceVA(off_4244F0), dword_4244EC, nullptr) )
      {
        writeValueOrError = 148;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424548, sourceVA(off_424550), dword_42454C, nullptr) )
      {
        writeValueOrError = 824;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4241F8, sourceVA(off_424200), dword_4241FC, nullptr) )
      {
        writeValueOrError = 826;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424218, sourceVA(off_424220), dword_42421C, nullptr) )
      {
        writeValueOrError = 826;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423E90, sourceVA(off_423E98), dword_423E94, nullptr) )
      {
        writeValueOrError = 828;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423F08, sourceVA(off_423F10), dword_423F0C, nullptr) )
      {
        writeValueOrError = 833;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423FC0, sourceVA(off_423FC8), dword_423FC4, nullptr) )
      {
        writeValueOrError = 835;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424048, sourceVA(off_424050), dword_42404C, nullptr) )
      {
        writeValueOrError = 837;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424598, sourceVA(off_4245A0), dword_42459C, nullptr) )
      {
        writeValueOrError = 841;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423F68, sourceVA(off_423F70), dword_423F6C, nullptr) )
      {
        writeValueOrError = 843;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4245E0, sourceVA(off_4245E8), dword_4245E4, nullptr) )
      {
        writeValueOrError = 845;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424638, sourceVA(off_424640), dword_42463C, nullptr) )
      {
        writeValueOrError = 847;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424738, sourceVA(off_424740), dword_42473C, nullptr) )
      {
        writeValueOrError = 849;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424858, sourceVA(off_424860), dword_42485C, nullptr) )
      {
        writeValueOrError = 851;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424940, sourceVA(off_424948), dword_424944, nullptr) )
      {
        writeValueOrError = 853;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424A38, sourceVA(off_424A40), dword_424A3C, nullptr) )
      {
        writeValueOrError = 855;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424338, sourceVA(off_424340), dword_42433C, nullptr) )
      {
        writeValueOrError = 857;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4239E0, sourceVA(off_4239E8), dword_4239E4, nullptr) )
      {
        writeValueOrError = 859;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423A18, sourceVA(off_423A20), dword_423A1C, nullptr) )
      {
        writeValueOrError = 861;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423A50, sourceVA(off_423A58), dword_423A54, nullptr) )
      {
        writeValueOrError = 861;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_422D80, sourceVA(off_422D88), dword_422D84, nullptr) )
      {
        writeValueOrError = 149;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423270, sourceVA(off_423278), dword_423274, nullptr) )
      {
        writeValueOrError = 866;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423480, sourceVA(off_423488), dword_423484, nullptr) )
      {
        writeValueOrError = 869;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4234F8, sourceVA(off_423500), dword_4234FC, nullptr) )
      {
        writeValueOrError = 871;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423558, sourceVA(off_423560), dword_42355C, nullptr) )
      {
        writeValueOrError = 873;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424AA0, sourceVA(off_424AA8), dword_424AA4, nullptr) )
      {
        writeValueOrError = 830;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424AF0, sourceVA(off_424AF8), dword_424AF4, nullptr) )
      {
        writeValueOrError = 875;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424688, sourceVA(off_424690), dword_42468C, nullptr) )
      {
        writeValueOrError = 877;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424B30, sourceVA(off_424B38), dword_424B34, nullptr) )
      {
        writeValueOrError = 879;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4246D0, sourceVA(off_4246D8), dword_4246D4, nullptr) )
      {
        writeValueOrError = 881;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424C30, sourceVA(off_424C38), dword_424C34, nullptr) )
      {
        writeValueOrError = 886;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424C80, sourceVA(off_424C88), dword_424C84, nullptr) )
      {
        writeValueOrError = 888;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424CC0, sourceVA(off_424CC8), dword_424CC4, nullptr) )
      {
        writeValueOrError = 1014;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424D70, sourceVA(off_424D78), dword_424D74, nullptr) )
      {
        writeValueOrError = 898;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425590, sourceVA(off_425598), dword_425594, nullptr) )
      {
        writeValueOrError = 921;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424DD8, sourceVA(off_424DE0), dword_424DDC, nullptr) )
      {
        writeValueOrError = 900;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425158, sourceVA(off_425160), dword_42515C, nullptr) )
      {
        writeValueOrError = 902;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425258, sourceVA(off_425260), dword_42525C, nullptr) )
      {
        writeValueOrError = 906;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4252E0, sourceVA(off_4252E8), dword_4252E4, nullptr) )
      {
        writeValueOrError = 908;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425328, sourceVA(off_425330), dword_42532C, nullptr) )
      {
        writeValueOrError = 910;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424778, sourceVA(off_424780), dword_42477C, nullptr) )
      {
        writeValueOrError = 913;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4247A0, sourceVA(off_4247A8), dword_4247A4, nullptr) )
      {
        writeValueOrError = 914;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4247C8, sourceVA(off_4247D0), dword_4247CC, nullptr) )
      {
        writeValueOrError = 915;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4247F0, sourceVA(off_4247F8), dword_4247F4, nullptr) )
      {
        writeValueOrError = 916;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424818, sourceVA(off_424820), dword_42481C, nullptr) )
      {
        writeValueOrError = 917;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425440, sourceVA(off_425448), dword_425444, nullptr) )
      {
        writeValueOrError = 896;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425518, sourceVA(off_425520), dword_42551C, nullptr) )
      {
        writeValueOrError = 919;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4255D0, sourceVA(off_4255D8), dword_4255D4, nullptr) )
      {
        writeValueOrError = 923;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425610, sourceVA(off_425618), dword_425614, nullptr) )
      {
        writeValueOrError = 925;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425728, sourceVA(off_425730), dword_42572C, nullptr) )
      {
        writeValueOrError = 931;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425798, sourceVA(off_4257A0), dword_42579C, nullptr) )
      {
        writeValueOrError = 934;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4257D8, sourceVA(off_4257E0), dword_4257DC, nullptr) )
      {
        writeValueOrError = 936;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425828, sourceVA(off_425830), dword_42582C, nullptr) )
      {
        writeValueOrError = 938;
        goto reportWriteFailure;
      }
      for ( patchIndexAt4258D0 = 0; patchIndexAt4258D0 < 2; ++patchIndexAt4258D0 )
      {
        if ( !writeMemory(
                *(HANDLE *)(state + san9::layout2026::ProcessHandle),
                (LPVOID)dword_4258D0[patchIndexAt4258D0],
                (char *)&unk_425900 + dword_4258E0[patchIndexAt4258D0],
                dword_4258D8[patchIndexAt4258D0],
                nullptr) )
        {
          writeValueOrError = 940;
          goto reportWriteFailure;
        }
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425980, sourceVA(off_425988), dword_425984, nullptr) )
      {
        writeValueOrError = 724;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4259A8, sourceVA(off_4259B0), dword_4259AC, nullptr) )
      {
        writeValueOrError = 724;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4259D0, sourceVA(off_4259D8), dword_4259D4, nullptr) )
      {
        writeValueOrError = 724;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4259F8, sourceVA(off_425A00), dword_4259FC, nullptr) )
      {
        writeValueOrError = 724;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425A38, sourceVA(off_425A40), dword_425A3C, nullptr) )
      {
        writeValueOrError = 144;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425A88, sourceVA(off_425A90), dword_425A8C, nullptr) )
      {
        writeValueOrError = 942;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425AB0, sourceVA(off_425AB8), dword_425AB4, nullptr) )
      {
        writeValueOrError = 942;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425AD8, sourceVA(off_425AE0), dword_425ADC, nullptr) )
      {
        writeValueOrError = 942;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425B00, sourceVA(off_425B08), dword_425B04, nullptr) )
      {
        writeValueOrError = 942;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425B40, sourceVA(off_425B48), dword_425B44, nullptr) )
      {
        writeValueOrError = 944;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425B68, sourceVA(off_425B70), dword_425B6C, nullptr) )
      {
        writeValueOrError = 944;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425BA8, sourceVA(off_425BB0), dword_425BAC, nullptr) )
      {
        writeValueOrError = 946;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425BE8, sourceVA(off_425BF0), dword_425BEC, nullptr) )
      {
        writeValueOrError = 948;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425C10, sourceVA(off_425C18), dword_425C14, nullptr) )
      {
        writeValueOrError = 948;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425C48, sourceVA(off_425C50), dword_425C4C, nullptr) )
      {
        writeValueOrError = 1201;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425C68, sourceVA(off_425C70), dword_425C6C, nullptr) )
      {
        writeValueOrError = 1201;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425CA0, sourceVA(off_425CA8), dword_425CA4, nullptr) )
      {
        writeValueOrError = 1203;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425CC0, sourceVA(off_425CC8), dword_425CC4, nullptr) )
      {
        writeValueOrError = 1203;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425D00, sourceVA(off_425D08), dword_425D04, nullptr) )
      {
        writeValueOrError = 950;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425D70, sourceVA(off_425D78), dword_425D74, nullptr) )
      {
        writeValueOrError = 953;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425E88, sourceVA(off_425E90), dword_425E8C, nullptr) )
      {
        writeValueOrError = 957;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_425F70, sourceVA(off_425F78), dword_425F74, nullptr) )
      {
        writeValueOrError = 959;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426028, sourceVA(off_426030), dword_42602C, nullptr) )
      {
        writeValueOrError = 961;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426088, sourceVA(off_426090), dword_42608C, nullptr) )
      {
        writeValueOrError = 963;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4260F0, sourceVA(off_4260F8), dword_4260F4, nullptr) )
      {
        writeValueOrError = 965;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426310, sourceVA(off_426318), dword_426314, nullptr) )
      {
        writeValueOrError = 969;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426528, sourceVA(off_426530), dword_42652C, nullptr) )
      {
        writeValueOrError = 973;
        goto reportWriteFailure;
      }
      patchDescriptorCursorAt426698 = (LPCVOID *)&off_426698;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt426698 - 2), sourceVA(*patchDescriptorCursorAt426698), (SIZE_T)*(patchDescriptorCursorAt426698 - 1), nullptr) )
        {
          writeValueOrError = 975;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt426698 += 3;
      }
      while ( (int)patchDescriptorCursorAt426698 < (int)&dword_4266D4 );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426740, sourceVA(off_426748), dword_426744, nullptr) )
      {
        writeValueOrError = 977;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426B28, sourceVA(off_426B30), dword_426B2C, nullptr) )
      {
        writeValueOrError = 982;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426CA0, sourceVA(off_426CA8), dword_426CA4, nullptr) )
      {
        writeValueOrError = 985;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426E28, sourceVA(off_426E30), dword_426E2C, nullptr) )
      {
        writeValueOrError = 989;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426E68, sourceVA(off_426E70), dword_426E6C, nullptr) )
      {
        writeValueOrError = 991;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426FD0, sourceVA(off_426FD8), dword_426FD4, nullptr) )
      {
        writeValueOrError = 1037;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4274B0, sourceVA(off_4274B8), dword_4274B4, nullptr) )
      {
        writeValueOrError = 993;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427890, sourceVA(off_427898), dword_427894, nullptr) )
      {
        writeValueOrError = 998;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4278B8, sourceVA(off_4278C0), dword_4278BC, nullptr) )
      {
        writeValueOrError = 999;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4278E0, sourceVA(off_4278E8), dword_4278E4, nullptr) )
      {
        writeValueOrError = 1000;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427990, sourceVA(off_427998), dword_427994, nullptr) )
      {
        writeValueOrError = 1002;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429900, sourceVA(off_429908), dword_429904, nullptr) )
      {
        writeValueOrError = 155;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427B18, sourceVA(off_427B20), dword_427B1C, nullptr) )
      {
        writeValueOrError = 1009;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427B40, sourceVA(off_427B48), dword_427B44, nullptr) )
      {
        writeValueOrError = 1009;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429940, sourceVA(off_429948), dword_429944, nullptr) )
      {
        writeValueOrError = 1155;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427B88, sourceVA(off_427B90), dword_427B8C, nullptr) )
      {
        writeValueOrError = 714;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427C70, sourceVA(off_427C78), dword_427C74, nullptr) )
      {
        writeValueOrError = 1011;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427D68, sourceVA(off_427D70), dword_427D6C, nullptr) )
      {
        writeValueOrError = 1016;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427DF8, sourceVA(off_427E00), dword_427DFC, nullptr) )
      {
        writeValueOrError = 1020;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427EE0, sourceVA(off_427EE8), dword_427EE4, nullptr) )
      {
        writeValueOrError = 1022;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427F20, sourceVA(off_427F28), dword_427F24, nullptr) )
      {
        writeValueOrError = 1024;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427CC0, sourceVA(off_427CC8), dword_427CC4, nullptr) )
      {
        writeValueOrError = 1026;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427FB8, sourceVA(off_427FC0), dword_427FBC, nullptr) )
      {
        writeValueOrError = 1028;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427928, sourceVA(off_427930), dword_42792C, nullptr) )
      {
        writeValueOrError = 1030;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426ED0, sourceVA(off_426ED8), dword_426ED4, nullptr) )
      {
        writeValueOrError = 1004;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426FA8, sourceVA(off_426FB0), dword_426FAC, nullptr) )
      {
        writeValueOrError = 1036;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4270B0, sourceVA(off_4270B8), dword_4270B4, nullptr) )
      {
        writeValueOrError = 1039;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427138, sourceVA(off_427140), dword_42713C, nullptr) )
      {
        writeValueOrError = 1041;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427160, sourceVA(off_427168), dword_427164, nullptr) )
      {
        writeValueOrError = 1042;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_420038, sourceVA(off_420040), dword_42003C, nullptr) )
      {
        writeValueOrError = 156;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_426EF8, sourceVA(off_426F00), dword_426EFC, nullptr) )
      {
        writeValueOrError = 1004;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4271E0, sourceVA(off_4271E8), dword_4271E4, nullptr) )
      {
        writeValueOrError = 1044;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427228, sourceVA(off_427230), dword_42722C, nullptr) )
      {
        writeValueOrError = 1046;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427288, sourceVA(off_427290), dword_42728C, nullptr) )
      {
        writeValueOrError = 1049;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4272C8, sourceVA(off_4272D0), dword_4272CC, nullptr) )
      {
        writeValueOrError = 1051;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427FE8, sourceVA(off_427FF0), dword_427FEC, nullptr) )
      {
        writeValueOrError = 1059;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427308, sourceVA(off_427310), dword_42730C, nullptr) )
      {
        writeValueOrError = 1054;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427348, sourceVA(off_427350), dword_42734C, nullptr) )
      {
        writeValueOrError = 1056;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427370, sourceVA(off_427378), dword_427374, nullptr) )
      {
        writeValueOrError = 1057;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4273D8, sourceVA(off_4273E0), dword_4273DC, nullptr) )
      {
        writeValueOrError = 1061;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427468, sourceVA(off_427470), dword_42746C, nullptr) )
      {
        writeValueOrError = 1063;
        goto reportWriteFailure;
      }
      for ( patchIndexAt428000 = 0; patchIndexAt428000 < 5; ++patchIndexAt428000 )
      {
        if ( !writeMemory(
                *(HANDLE *)(state + san9::layout2026::ProcessHandle),
                (LPVOID)dword_428000[patchIndexAt428000],
                (char *)&unk_42803C + dword_428028[patchIndexAt428000],
                dword_428014[patchIndexAt428000],
                nullptr) )
        {
          writeValueOrError = 1065;
          goto reportWriteFailure;
        }
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428118, sourceVA(off_428120), dword_42811C, nullptr) )
      {
        writeValueOrError = 398;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428150, sourceVA(off_428158), dword_428154, nullptr) )
      {
        writeValueOrError = 891;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428348, sourceVA(off_428350), dword_42834C, nullptr) )
      {
        writeValueOrError = 893;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428420, sourceVA(off_428428), dword_428424, nullptr) )
      {
        writeValueOrError = 1067;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428478, sourceVA(off_428480), dword_42847C, nullptr) )
      {
        writeValueOrError = 1069;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428658, sourceVA(off_428660), dword_42865C, nullptr) )
      {
        writeValueOrError = 1074;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428678, sourceVA(off_428680), dword_42867C, nullptr) )
      {
        writeValueOrError = 1074;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428710, sourceVA(off_428718), dword_428714, nullptr) )
      {
        writeValueOrError = 1076;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4287B0, sourceVA(off_4287B8), dword_4287B4, nullptr) )
      {
        writeValueOrError = 1078;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428830, sourceVA(off_428838), dword_428834, nullptr) )
      {
        writeValueOrError = 1080;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428850, sourceVA(off_428858), dword_428854, nullptr) )
      {
        writeValueOrError = 1080;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428870, sourceVA(off_428878), dword_428874, nullptr) )
      {
        writeValueOrError = 1080;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428890, sourceVA(off_428898), dword_428894, nullptr) )
      {
        writeValueOrError = 1080;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4288B8, sourceVA(off_4288C0), dword_4288BC, nullptr) )
      {
        writeValueOrError = 1183;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4288E0, sourceVA(off_4288E8), dword_4288E4, nullptr) )
      {
        writeValueOrError = 1183;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4289C8, sourceVA(off_4289D0), dword_4289CC, nullptr) )
      {
        writeValueOrError = 1125;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428A18, sourceVA(off_428A20), dword_428A1C, nullptr) )
      {
        writeValueOrError = 1085;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428CA8, sourceVA(off_428CB0), dword_428CAC, nullptr) )
      {
        writeValueOrError = 1093;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428D38, sourceVA(off_428D40), dword_428D3C, nullptr) )
      {
        writeValueOrError = 1095;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428D58, sourceVA(off_428D60), dword_428D5C, nullptr) )
      {
        writeValueOrError = 1095;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428D78, sourceVA(off_428D80), dword_428D7C, nullptr) )
      {
        writeValueOrError = 1095;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_423B20, sourceVA(off_423B28), dword_423B24, nullptr) )
      {
        writeValueOrError = 636;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428ED0, sourceVA(off_428ED8), dword_428ED4, nullptr) )
      {
        writeValueOrError = 1100;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428BC0, sourceVA(off_428BC8), dword_428BC4, nullptr) )
      {
        writeValueOrError = 1091;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), off_428F30, sourceVA(off_428F38), dword_428F34, nullptr) )
      {
        writeValueOrError = 1102;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_428FC0, sourceVA(off_428FC8), dword_428FC4, nullptr) )
      {
        writeValueOrError = 638;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429090, sourceVA(off_429098), dword_429094, nullptr) )
      {
        writeValueOrError = 1106;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4290D0, sourceVA(off_4290D8), dword_4290D4, nullptr) )
      {
        writeValueOrError = 1108;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4291B0, sourceVA(off_4291B8), dword_4291B4, nullptr) )
      {
        writeValueOrError = 1118;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4292D0, sourceVA(off_4292D8), dword_4292D4, nullptr) )
      {
        writeValueOrError = 1114;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429360, sourceVA(off_429368), dword_429364, nullptr) )
      {
        writeValueOrError = 1127;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4293B8, sourceVA(off_4293C0), dword_4293BC, nullptr) )
      {
        writeValueOrError = 1129;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4293F8, sourceVA(off_429400), dword_4293FC, nullptr) )
      {
        writeValueOrError = 1131;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429488, sourceVA(off_429490), dword_42948C, nullptr) )
      {
        writeValueOrError = 1133;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4294B0, sourceVA(off_4294B8), dword_4294B4, nullptr) )
      {
        writeValueOrError = 1135;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4294D8, sourceVA(off_4294E0), dword_4294DC, nullptr) )
      {
        writeValueOrError = 1136;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4295F8, sourceVA(off_429600), dword_4295FC, nullptr) )
      {
        writeValueOrError = 1138;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429678, sourceVA(off_429680), dword_42967C, nullptr) )
      {
        writeValueOrError = 1140;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429710, sourceVA(off_429718), dword_429714, nullptr) )
      {
        writeValueOrError = 1142;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429780, sourceVA(off_429788), dword_429784, nullptr) )
      {
        writeValueOrError = 1144;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4298A0, sourceVA(off_4298A8), dword_4298A4, nullptr) )
      {
        writeValueOrError = 1157;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42B500, sourceVA(off_42B508), dword_42B504, nullptr) )
      {
        writeValueOrError = 1159;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42B528, sourceVA(off_42B530), dword_42B52C, nullptr) )
      {
        writeValueOrError = 1160;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42B540, sourceVA(off_42B548), dword_42B544, nullptr) )
      {
        writeValueOrError = 1161;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42B568, sourceVA(off_42B570), dword_42B56C, nullptr) )
      {
        writeValueOrError = 1165;
        goto reportWriteFailure;
      }
      patchDescriptorCursorAt42B698 = (LPCVOID *)&off_42B698;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42B698 - 2), sourceVA(*patchDescriptorCursorAt42B698), (SIZE_T)*(patchDescriptorCursorAt42B698 - 1), nullptr) )
        {
          writeValueOrError = 1174;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42B698 += 3;
      }
      while ( (int)patchDescriptorCursorAt42B698 < (int)&dword_42B6BC );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42B778, sourceVA(off_42B780), dword_42B77C, nullptr) )
      {
        writeValueOrError = 1169;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42B810, sourceVA(off_42B818), dword_42B814, nullptr) )
      {
        writeValueOrError = 1179;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42B838, sourceVA(off_42B840), dword_42B83C, nullptr) )
      {
        writeValueOrError = 1179;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42B878, sourceVA(off_42B880), dword_42B87C, nullptr) )
      {
        writeValueOrError = 1181;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42BDC8, sourceVA(off_42BDD0), dword_42BDCC, nullptr) )
      {
        writeValueOrError = 1185;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42BF90, sourceVA(off_42BF98), dword_42BF94, nullptr) )
      {
        writeValueOrError = 1187;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42C058, sourceVA(off_42C060), dword_42C05C, nullptr) )
      {
        writeValueOrError = 1213;
        goto reportWriteFailure;
      }
      for ( patchIndexAt42C134 = 0; patchIndexAt42C134 < 6; ++patchIndexAt42C134 )
      {
        if ( !writeMemory(
                *(HANDLE *)(state + san9::layout2026::ProcessHandle),
                (LPVOID)dword_42C134[patchIndexAt42C134],
                (char *)&unk_42C17C + dword_42C164[patchIndexAt42C134],
                dword_42C14C[patchIndexAt42C134],
                nullptr) )
        {
          writeValueOrError = 1189;
          goto reportWriteFailure;
        }
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42C550, sourceVA(off_42C558), dword_42C554, nullptr) )
      {
        writeValueOrError = 1215;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), off_42C5A8, sourceVA(off_42C5B0), dword_42C5AC, nullptr) )
      {
        writeValueOrError = 1217;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42C600, sourceVA(off_42C608), dword_42C604, nullptr) )
      {
        writeValueOrError = 1191;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42C930, sourceVA(off_42C938), dword_42C934, nullptr) )
      {
        writeValueOrError = 1198;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42C9B8, sourceVA(off_42C9C0), dword_42C9BC, nullptr) )
      {
        writeValueOrError = 1194;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42CA00, sourceVA(off_42CA08), dword_42CA04, nullptr) )
      {
        writeValueOrError = 1196;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42CA60, sourceVA(off_42CA68), dword_42CA64, nullptr) )
      {
        writeValueOrError = 1205;
        goto reportWriteFailure;
      }
      for ( patchIndexAt42CA78 = 0; patchIndexAt42CA78 < 3; ++patchIndexAt42CA78 )
      {
        if ( !writeMemory(
                *(HANDLE *)(state + san9::layout2026::ProcessHandle),
                (LPVOID)dword_42CA78[patchIndexAt42CA78],
                (char *)&unk_42CA9C + dword_42CA90[patchIndexAt42CA78],
                dword_42CA84[patchIndexAt42CA78],
                nullptr) )
        {
          writeValueOrError = 1206;
          goto reportWriteFailure;
        }
      }
      for ( patchIndexAt42CADC = 0; patchIndexAt42CADC < 4; ++patchIndexAt42CADC )
      {
        if ( !writeMemory(
                *(HANDLE *)(state + san9::layout2026::ProcessHandle),
                (LPVOID)dword_42CADC[patchIndexAt42CADC],
                (char *)&unk_42CB0C + dword_42CAFC[patchIndexAt42CADC],
                dword_42CAEC[patchIndexAt42CADC],
                nullptr) )
        {
          writeValueOrError = 1207;
          goto reportWriteFailure;
        }
      }
      for ( patchIndexAt42CB74 = 0; patchIndexAt42CB74 < 4; ++patchIndexAt42CB74 )
      {
        if ( !writeMemory(
                *(HANDLE *)(state + san9::layout2026::ProcessHandle),
                (LPVOID)dword_42CB74[patchIndexAt42CB74],
                (char *)&unk_42CBA4 + dword_42CB94[patchIndexAt42CB74],
                dword_42CB84[patchIndexAt42CB74],
                nullptr) )
        {
          writeValueOrError = 1208;
          goto reportWriteFailure;
        }
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42CC78, sourceVA(off_42CC80), dword_42CC7C, nullptr) )
      {
        writeValueOrError = 1209;
        goto reportWriteFailure;
      }
      patchDescriptorCursorAt42CD48 = (LPCVOID *)&off_42CD48;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42CD48 - 2), sourceVA(*patchDescriptorCursorAt42CD48), (SIZE_T)*(patchDescriptorCursorAt42CD48 - 1), nullptr) )
        {
          writeValueOrError = 1211;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42CD48 += 3;
      }
      while ( (int)patchDescriptorCursorAt42CD48 < (int)&dword_42CD6C );
      patchDescriptorCursorAt42D0C8 = (LPCVOID *)&off_42D0C8;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42D0C8 - 2), sourceVA(*patchDescriptorCursorAt42D0C8), (SIZE_T)*(patchDescriptorCursorAt42D0C8 - 1), nullptr) )
        {
          writeValueOrError = 1223;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42D0C8 += 3;
      }
      while ( (int)patchDescriptorCursorAt42D0C8 < (int)&dword_42D0EC );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42D1A0, sourceVA(off_42D1A8), dword_42D1A4, nullptr) )
      {
        writeValueOrError = 1225;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42D1C8, sourceVA(off_42D1D0), dword_42D1CC, nullptr) )
      {
        writeValueOrError = 1226;
        goto reportWriteFailure;
      }
      patchDescriptorCursorAt42D340 = (LPCVOID *)&off_42D340;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42D340 - 2), sourceVA(*patchDescriptorCursorAt42D340), (SIZE_T)*(patchDescriptorCursorAt42D340 - 1), nullptr) )
        {
          writeValueOrError = 1227;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42D340 += 3;
      }
      while ( (int)patchDescriptorCursorAt42D340 < (int)dword_42D454 );
      patchDescriptorCursorAt42D7C0 = (LPCVOID *)&off_42D7C0;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)*(patchDescriptorCursorAt42D7C0 - 2), sourceVA(*patchDescriptorCursorAt42D7C0), (SIZE_T)*(patchDescriptorCursorAt42D7C0 - 1), nullptr) )
        {
          writeValueOrError = 1229;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42D7C0 += 3;
      }
      while ( (int)patchDescriptorCursorAt42D7C0 < (int)&dword_42D88C );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42A080, sourceVA(off_42A088), dword_42A084, nullptr) )
      {
        writeValueOrError = 171;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42A118, sourceVA(off_42A120), dword_42A11C, nullptr) )
      {
        writeValueOrError = 172;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42A140, sourceVA(off_42A148), dword_42A144, nullptr) )
      {
        writeValueOrError = 173;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42A1A0, sourceVA(off_42A1A8), dword_42A1A4, nullptr) )
      {
        writeValueOrError = 169;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429E78, sourceVA(off_429E80), dword_429E7C, nullptr) )
      {
        writeValueOrError = 170;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429EA0, sourceVA(off_429EA8), dword_429EA4, nullptr) )
      {
        writeValueOrError = 174;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429EC8, sourceVA(off_429ED0), dword_429ECC, nullptr) )
      {
        writeValueOrError = 175;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429EF0, sourceVA(off_429EF8), dword_429EF4, nullptr) )
      {
        writeValueOrError = 176;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429F18, sourceVA(off_429F20), dword_429F1C, nullptr) )
      {
        writeValueOrError = 177;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429F40, sourceVA(off_429F48), dword_429F44, nullptr) )
      {
        writeValueOrError = 178;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429F68, sourceVA(off_429F70), dword_429F6C, nullptr) )
      {
        writeValueOrError = 181;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429F90, sourceVA(off_429F98), dword_429F94, nullptr) )
      {
        writeValueOrError = 179;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429FB8, sourceVA(off_429FC0), dword_429FBC, nullptr) )
      {
        writeValueOrError = 180;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429FE0, sourceVA(off_429FE8), dword_429FE4, nullptr) )
      {
        writeValueOrError = 182;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42A008, sourceVA(off_42A010), dword_42A00C, nullptr) )
      {
        writeValueOrError = 183;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42A030, sourceVA(off_42A038), dword_42A034, nullptr) )
      {
        writeValueOrError = 184;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429AA8, sourceVA(off_429AB0), dword_429AAC, nullptr) )
      {
        writeValueOrError = 185;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429AD0, sourceVA(off_429AD8), dword_429AD4, nullptr) )
      {
        writeValueOrError = 186;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429AF8, sourceVA(off_429B00), dword_429AFC, nullptr) )
      {
        writeValueOrError = 187;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429B20, sourceVA(off_429B28), dword_429B24, nullptr) )
      {
        writeValueOrError = 187;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429B48, sourceVA(off_429B50), dword_429B4C, nullptr) )
      {
        writeValueOrError = 188;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429B70, sourceVA(off_429B78), dword_429B74, nullptr) )
      {
        writeValueOrError = 188;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429B98, sourceVA(off_429BA0), dword_429B9C, nullptr) )
      {
        writeValueOrError = 189;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429BC0, sourceVA(off_429BC8), dword_429BC4, nullptr) )
      {
        writeValueOrError = 189;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429BE8, sourceVA(off_429BF0), dword_429BEC, nullptr) )
      {
        writeValueOrError = 190;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429C10, sourceVA(off_429C18), dword_429C14, nullptr) )
      {
        writeValueOrError = 190;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429C38, sourceVA(off_429C40), dword_429C3C, nullptr) )
      {
        writeValueOrError = 191;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429C60, sourceVA(off_429C68), dword_429C64, nullptr) )
      {
        writeValueOrError = 191;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429C88, sourceVA(off_429C90), dword_429C8C, nullptr) )
      {
        writeValueOrError = 192;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429CB0, sourceVA(off_429CB8), dword_429CB4, nullptr) )
      {
        writeValueOrError = 192;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429CD8, sourceVA(off_429CE0), dword_429CDC, nullptr) )
      {
        writeValueOrError = 193;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429D00, sourceVA(off_429D08), dword_429D04, nullptr) )
      {
        writeValueOrError = 195;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_429DB0, sourceVA(off_429DB8), dword_429DB4, nullptr) )
      {
        writeValueOrError = 194;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41F8E0, sourceVA(off_41F8E8), dword_41F8E4, nullptr) )
      {
        writeValueOrError = 204;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41F908, sourceVA(off_41F910), dword_41F90C, nullptr) )
      {
        writeValueOrError = 203;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41F8B8, sourceVA(off_41F8C0), dword_41F8BC, nullptr) )
      {
        writeValueOrError = 206;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6440), &initializationValue, 1u, nullptr) )
      {
        writeValueOrError = 268;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42A560, sourceVA(off_42A568), dword_42A564, nullptr) )
      {
        writeValueOrError = 279;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42A5C0, sourceVA(off_42A5C8), dword_42A5C4, nullptr) )
      {
        writeValueOrError = 284;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), off_42AFA0, sourceVA(off_42AFA8), dword_42AFA4, nullptr) )
      {
        writeValueOrError = 281;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42B1B0, sourceVA(off_42B1B8), dword_42B1B4, nullptr) )
      {
        writeValueOrError = 291;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), off_42B278, sourceVA(off_42B280), dword_42B27C, nullptr) )
      {
        writeValueOrError = 293;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), off_42B2A0, sourceVA(off_42B2A8), dword_42B2A4, nullptr) )
      {
        writeValueOrError = 293;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), off_42B388, sourceVA(off_42B390), dword_42B38C, nullptr) )
      {
        writeValueOrError = 295;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), off_42B3B0, sourceVA(off_42B3B8), dword_42B3B4, nullptr) )
      {
        writeValueOrError = 295;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), off_42B3D8, sourceVA(off_42B3E0), dword_42B3DC, nullptr) )
      {
        writeValueOrError = 295;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_41F988, sourceVA(off_41F990), dword_41F98C, nullptr) )
      {
        writeValueOrError = 235;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_421788, sourceVA(off_421790), dword_42178C, nullptr) )
      {
        writeValueOrError = 234;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4217B8, sourceVA(off_4217C0), dword_4217BC, nullptr) )
      {
        writeValueOrError = 233;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4217E8, sourceVA(off_4217F0), dword_4217EC, nullptr) )
      {
        writeValueOrError = 232;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424240, sourceVA(off_424248), dword_424244, nullptr) )
      {
        writeValueOrError = 231;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424360, sourceVA(off_424368), dword_424364, nullptr) )
      {
        writeValueOrError = 230;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4243E0, sourceVA(off_4243E8), dword_4243E4, nullptr) )
      {
        writeValueOrError = 236;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_424408, sourceVA(off_424410), dword_42440C, nullptr) )
      {
        writeValueOrError = 237;
        goto reportWriteFailure;
      }
      if ( !readMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4253B4, sourceVA(off_4253BC), dword_4253B8, nullptr) )
      {
        writeValueOrError = 238;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4253A8, sourceVA(off_4253B0), dword_4253AC, nullptr) )
      {
        writeValueOrError = 239;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_4253C0, &codeGetPersonFriendship, 0x38u, nullptr) )
      {
        writeValueOrError = 240;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_427188, sourceVA(off_427190), dword_42718C, nullptr) )
      {
        writeValueOrError = 241;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::BurnExperienceAddr), (LPCVOID)(state + san9::injection2026::BurnExperienceCode), 4u, nullptr) )
      {
        writeValueOrError = 308;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::RobExperienceAddr), (LPCVOID)(state + san9::injection2026::RobExperienceCode), 4u, nullptr) )
      {
        writeValueOrError = 309;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::ReinforceExperienceAddr), (LPCVOID)(state + san9::injection2026::ReinforceExperienceCode), 4u, nullptr) )
      {
        writeValueOrError = 310;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::TrainExperienceAddr), (LPCVOID)(state + san9::injection2026::TrainExperienceCode), 4u, nullptr) )
      {
        writeValueOrError = 311;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::RepairExperienceAddr), (LPCVOID)(state + san9::injection2026::RepairExperienceCode), 4u, nullptr) )
      {
        writeValueOrError = 312;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::CultivateMinPoliticsAddr), (LPCVOID)(state + san9::injection2026::CultivateMinPolitics), 1u, nullptr) )
      {
        writeValueOrError = 313;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::DispatchArrayAddr), (LPCVOID)(state + san9::injection2026::DispatchArray), 1u, nullptr) )
      {
        writeValueOrError = 314;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::DispatchShipAddr), (LPCVOID)(state + san9::injection2026::DispatchShip), 1u, nullptr) )
      {
        writeValueOrError = 315;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::ChaosDayAddr), (LPCVOID)(state + san9::injection2026::ChaosDayCoef), 4u, nullptr) )
      {
        writeValueOrError = 318;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::LowerTrickAddr), (LPCVOID)(state + san9::injection2026::LowerTrickCoef), 1u, nullptr) )
      {
        writeValueOrError = 320;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6480), (LPCVOID)(state + 6484), 1u, nullptr) )
      {
        writeValueOrError = 321;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::LowerTrapAddr), (LPCVOID)(state + san9::injection2026::LowerTrickCoef), 1u, nullptr) )
      {
        writeValueOrError = 323;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::AlienateIntelligenceAddr), (LPCVOID)(state + san9::injection2026::AlienateIntelligenceCode), 1u, nullptr) )
      {
        writeValueOrError = 325;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::GossipIntelligenceAddr), (LPCVOID)(state + san9::injection2026::GossipIntelligenceCode), 1u, nullptr) )
      {
        writeValueOrError = 326;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::InspireIntelligenceAddr), (LPCVOID)(state + san9::injection2026::InspireIntelligenceCode), 1u, nullptr) )
      {
        writeValueOrError = 327;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::CheatIntelligenceAddr), (LPCVOID)(state + san9::injection2026::CheatIntelligenceCode), 1u, nullptr) )
      {
        writeValueOrError = 328;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::DisorderIntelligenceAddr), (LPCVOID)(state + san9::injection2026::DisorderIntelligenceCode), 1u, nullptr) )
      {
        writeValueOrError = 329;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::BuildExperienceAddr), (LPCVOID)(state + san9::injection2026::BuildExperienceCode), 1u, nullptr) )
      {
        writeValueOrError = 330;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::AntiAttackMinSoldierdAddr), (LPCVOID)(state + san9::injection2026::AntiAttackMinSoldier), 4u, nullptr) )
      {
        writeValueOrError = 324;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::AntiAttackBarbarismAddr), (LPCVOID)(state + san9::injection2026::AntiAttackBarbarism), 1u, nullptr) )
      {
        writeValueOrError = 331;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6504), (LPCVOID)(state + 6508), 4u, nullptr) )
      {
        writeValueOrError = 332;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::AlienateForceNameAddr), (LPCVOID)(state + san9::injection2026::AlienateForceName), 1u, nullptr) )
      {
        writeValueOrError = 333;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::AntiMinTroopSoldierAddr), (LPCVOID)(state + san9::injection2026::AntiMinTroopSoldier), 4u, nullptr) )
      {
        writeValueOrError = 334;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::SaveBaseAddr), (LPCVOID)(state + san9::injection2026::SaveBase), 1u, nullptr) )
      {
        writeValueOrError = 335;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::OfficerBasicCommandAddr), (LPCVOID)(state + san9::injection2026::OfficerBasicCommand), 1u, nullptr) )
      {
        writeValueOrError = 340;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::OfficerBasicIntAddr), (LPCVOID)(state + san9::injection2026::OfficerBasicInt), 4u, nullptr) )
      {
        writeValueOrError = 341;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::SearchMinPoliticsAddr), (LPCVOID)(state + san9::injection2026::SearchMinPolitics), 1u, nullptr) )
      {
        writeValueOrError = 346;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::FootAntiElephantAddr), (LPCVOID)(state + san9::injection2026::FootAntiElephant), 4u, nullptr) )
      {
        writeValueOrError = 348;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::InspireMaxVigourAddr), (LPCVOID)(state + san9::injection2026::InspireMaxVigour), 1u, nullptr) )
      {
        writeValueOrError = 352;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6740), (LPCVOID)(state + 6744), 1u, nullptr) )
      {
        writeValueOrError = 354;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6752), (LPCVOID)(state + san9::injection2026::GossipSubLoyalty), 1u, nullptr) )
      {
        writeValueOrError = 355;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::GoalNullCityAddr), (LPCVOID)(state + san9::injection2026::GoalNullCity), 4u, nullptr) )
      {
        writeValueOrError = 357;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::NullBulidingDangerAddr), (LPCVOID)(state + san9::injection2026::NullBulidingDanger), 1u, nullptr) )
      {
        writeValueOrError = 359;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::AvoidNearCityAddr), (LPCVOID)(state + san9::injection2026::AvoidNearCity), 2u, nullptr) )
      {
        writeValueOrError = 360;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::RetreatMinVigourAddr), (LPCVOID)(state + san9::injection2026::RetreatMinVigour), 1u, nullptr) )
      {
        writeValueOrError = 317;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::SelectCleverKillerAddr), (LPCVOID)(state + san9::injection2026::SelectCleverKiller), 1u, nullptr) )
      {
        writeValueOrError = 361;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::NeglectChongCheAddr), (LPCVOID)(state + (skipDurabilitySiegeSelection_ ? 6828 : 6832)), 1u, nullptr) )
      {
        writeValueOrError = 362;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::SameForceTroopAddr), (LPCVOID)(state + san9::injection2026::SameForceTroop), 1u, nullptr) )
      {
        writeValueOrError = 363;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::SameForceTroopAddr2), (LPCVOID)(state + san9::injection2026::SameForceTroop), 1u, nullptr) )
      {
        writeValueOrError = 363;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::AttackIgnoreAntitrapAddr), (LPCVOID)(state + san9::injection2026::AttackIgnoreAntitrap), 1u, nullptr) )
      {
        writeValueOrError = 365;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::HomeForceDoorAddr), (LPCVOID)(state + san9::injection2026::HomeForceDoor), 1u, nullptr) )
      {
        writeValueOrError = 356;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::AvoidInduceMaxDayAddr), (LPCVOID)(state + san9::injection2026::AvoidInduceMaxDay), 1u, nullptr) )
      {
        writeValueOrError = 371;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::GetTroopGoalBugAddr), (LPCVOID)(state + san9::injection2026::GetTroopGoalBug), 4u, nullptr) )
      {
        writeValueOrError = 378;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::GoalToSourceDamageAddr), (LPCVOID)(state + san9::injection2026::GoalToSourceDamage), 1u, nullptr) )
      {
        writeValueOrError = 380;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::BadBrothersArrayEndAddr), (LPCVOID)(state + san9::injection2026::BadBrothersArrayEnd), 4u, nullptr) )
      {
        writeValueOrError = 381;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::TroopFromBuildingAddr), (LPCVOID)(state + san9::injection2026::TroopFromBuilding), 1u, nullptr) )
      {
        writeValueOrError = 382;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::FalseAntiTroopAddr), (LPCVOID)(state + san9::injection2026::ExternalAntiTroop), 4u, nullptr) )
      {
        writeValueOrError = 385;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::DisorderAntiTroopAddr), (LPCVOID)(state + san9::injection2026::InternalAntiTroop), 4u, nullptr) )
      {
        writeValueOrError = 386;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::DeclareAttackTroopAddr), (LPCVOID)(state + san9::injection2026::DeclareAttackTroop), 1u, nullptr) )
      {
        writeValueOrError = 379;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::InviteSubLoyatyAddr), (LPCVOID)(state + san9::injection2026::InviteSubLoyaty), 1u, nullptr) )
      {
        writeValueOrError = 387;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::CommandOfficerEndFlagAddr), (LPCVOID)(state + san9::injection2026::CommandOfficerEndFlag), 1u, nullptr) )
      {
        writeValueOrError = 390;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::IntelligenceOfficerEndFlagAddr), (LPCVOID)(state + san9::injection2026::IntelligenceOfficerEndFlag), 1u, nullptr) )
      {
        writeValueOrError = 391;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::ShowCelueKillerAddr), (LPCVOID)(state + san9::injection2026::ShowCelueKiller), 4u, nullptr) )
      {
        writeValueOrError = 393;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::LvbuAttackDoorAddr), (LPCVOID)(state + san9::injection2026::LvbuAttackDoor), 1u, nullptr) )
      {
        writeValueOrError = 403;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::EnableSecondKillerAddr), (LPCVOID)(state + san9::injection2026::EnableSecondKiller), 1u, nullptr) )
      {
        writeValueOrError = 372;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::TroopGoalBuildingAddr), (LPCVOID)(state + san9::injection2026::TroopGoalBuilding), 4u, nullptr) )
      {
        writeValueOrError = 405;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::NotGetPersonQuotaAddr), (LPCVOID)(state + san9::injection2026::NotGetPersonQuota), 1u, nullptr) )
      {
        writeValueOrError = 370;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::YearTableInvalidFlagAddr), (LPCVOID)(state + san9::injection2026::YearTableInvalidFlag), 1u, nullptr) )
      {
        writeValueOrError = 407;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::TransportGoalInfoAddr), (LPCVOID)(state + san9::injection2026::TransportGoalInfo), 4u, nullptr) )
      {
        writeValueOrError = 409;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::CounselorMinCandidateAddr), (LPCVOID)(state + san9::injection2026::CounselorMinCandidate), 1u, nullptr) )
      {
        writeValueOrError = 410;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::NoarrayToBuildingAddr), (LPCVOID)(state + san9::injection2026::NoarrayToBuilding), 1u, nullptr) )
      {
        writeValueOrError = 414;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::NoarrayToBuildingAddr2), (LPCVOID)(state + san9::injection2026::NoarrayToBuilding), 1u, nullptr) )
      {
        writeValueOrError = 414;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::SearchNoResultAddr), (LPCVOID)(state + san9::injection2026::SearchNoResult), 1u, nullptr) )
      {
        writeValueOrError = 420;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::AttackBuildForceAddr), (LPCVOID)(state + san9::injection2026::AttackBuildForce), 1u, nullptr) )
      {
        writeValueOrError = 422;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::BuildMaxArriveDayAddr), (LPCVOID)(state + san9::injection2026::BuildMaxArriveDay), 1u, nullptr) )
      {
        writeValueOrError = 423;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::GameEndYearAddr), (LPCVOID)(state + san9::injection2026::GameEndYear), 4u, nullptr) )
      {
        writeValueOrError = 425;
        goto reportWriteFailure;
      }
      if ( !writeMemory(
              *(HANDLE *)(state + san9::layout2026::ProcessHandle),
              (LPVOID)(*(_DWORD *)(state + san9::injection2026::BuildMinBuildingAddr) - 32),
              (LPCVOID)(state + san9::injection2026::BuildMinBuilding),
              1u,
              nullptr) )
      {
        writeValueOrError = 301;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::BuildMinBuildingAddr), (LPCVOID)(state + san9::injection2026::BuildMinBuilding), 1u, nullptr) )
      {
        writeValueOrError = 301;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::UpdateGoalForceAddr), (LPCVOID)(state + san9::injection2026::UpdateGoalForce), 1u, nullptr) )
      {
        writeValueOrError = 427;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::UpdateGoalPropAddr), (LPCVOID)(state + san9::injection2026::UpdateGoalProp), 1u, nullptr) )
      {
        writeValueOrError = 428;
        goto reportWriteFailure;
      }
      patchDescriptorCursorAt42C258 = (LPVOID *)&unk_42C258;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(patchDescriptorCursorAt42C258 - 2), patchDescriptorCursorAt42C258, (SIZE_T)*(patchDescriptorCursorAt42C258 - 1), nullptr) )
        {
          writeValueOrError = 1149;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42C258 += 4;
      }
      while ( (int)patchDescriptorCursorAt42C258 < (int)&dword_42C4F8 );
      patchDescriptorCursorAt42C620 = (LPVOID *)&unk_42C620;
      do
      {
        if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(patchDescriptorCursorAt42C620 - 2), patchDescriptorCursorAt42C620, (SIZE_T)*(patchDescriptorCursorAt42C620 - 1), nullptr) )
        {
          writeValueOrError = 1192;
          goto reportWriteFailure;
        }
        patchDescriptorCursorAt42C620 += 4;
      }
      while ( (int)patchDescriptorCursorAt42C620 < (int)&dword_42C7D0 );
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7480), (LPCVOID)(state + 7484), 1u, nullptr) )
      {
        writeValueOrError = 1152;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7492), (LPCVOID)(state + 7504), 1u, nullptr) )
      {
        writeValueOrError = 1153;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7496), (LPCVOID)(state + 7504), 1u, nullptr) )
      {
        writeValueOrError = 1153;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7500), (LPCVOID)(state + 7512), 1u, nullptr) )
      {
        writeValueOrError = 1153;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7520), (LPCVOID)(state + 7524), 1u, nullptr) )
      {
        writeValueOrError = 1150;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7532), (LPCVOID)(state + 7536), 1u, nullptr) )
      {
        writeValueOrError = 1167;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7544), (LPCVOID)(state + 7548), 4u, nullptr) )
      {
        writeValueOrError = 1167;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7556), (LPCVOID)(state + 7560), 1u, nullptr) )
      {
        writeValueOrError = 1167;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7580), (LPCVOID)(state + 7584), 1u, nullptr) )
      {
        writeValueOrError = 1171;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7592), (LPCVOID)(state + 7596), 4u, nullptr) )
      {
        writeValueOrError = 1175;
        goto reportWriteFailure;
      }
      if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7604), (LPCVOID)(state + 7608), 4u, nullptr) )
      {
        writeValueOrError = 1175;
        goto reportWriteFailure;
      }
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 4404), (LPCVOID)(state + san9::layout2026::MaxExperience), 2u, nullptr) )
    {
      writeValueOrError = 392;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 3700), (LPCVOID)(state + san9::layout2026::PersonLevels), 0xC80u, nullptr) )
    {
      writeValueOrError = 453;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::PersonFriendshipAddress), (LPCVOID)(state + san9::layout2026::PersonFriendships), 0x2B8u, nullptr) )
    {
      writeValueOrError = 500;
      goto reportWriteFailure;
    }
    byte_42F164 = *(_BYTE *)(state + san9::injection2026::MoneyCut1);
    byte_42F165 = *(_BYTE *)(state + san9::injection2026::MoneyCut2);
    byte_42F166 = *(_BYTE *)(state + san9::injection2026::MoneyCut3);
    byte_42F167 = *(_BYTE *)(state + san9::injection2026::FoodCut1);
    byte_42F168 = *(_BYTE *)(state + san9::injection2026::FoodCut2);
    byte_42F169 = *(_BYTE *)(state + san9::injection2026::FoodCut3);
    byte_42F16A = *(_BYTE *)(state + san9::injection2026::DraftCut1);
    byte_42F16B = *(_BYTE *)(state + san9::injection2026::DraftCut2);
    byte_42F16C = *(_BYTE *)(state + san9::injection2026::DraftCut3);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F160, &byte_42F164, 9u, nullptr) )
    {
      writeValueOrError = 300;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::YearDifference);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F394 + 2, &writeValueOrError, 4u, nullptr) )
    {
      writeValueOrError = 366;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F194 + 12, &writeValueOrError, 4u, nullptr) )
    {
      writeValueOrError = 366;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::KillerPowerCoef);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F4A0 + 29, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 395;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldSlashDeadCoef) + 4 * *(_DWORD *)(state + san9::injection2026::SlashDeadCoef);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::SlashDeadCoefAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 401;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::SecondKillerEnabled) == 0;
    writeSucceeded = writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_4264D0[3 * writeValueOrError], sourceVA(*(&off_4264D8 + 3 * writeValueOrError)),
            dword_4264D4[3 * writeValueOrError],
            nullptr);
    if ( !writeSucceeded )
    {
      writeValueOrError = 971;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::NoOfficialSalary);
    if ( writeValueOrError != 0 )
      writeSucceeded = writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7616), &writeValueOrError, 4u, nullptr);
    if ( !writeSucceeded )
    {
      writeValueOrError = 373;
      goto reportWriteFailure;
    }
    writeValueOrError = 40 - 2 * *(_DWORD *)(state + san9::injection2026::BlockPropCoef);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F1E0 + 8, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 408;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::NpcAttackDisorder);
    if ( writeValueOrError != 0 )
      writeValueOrError = 10 - writeValueOrError;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43F4CC, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 419;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43F4CF, (LPCVOID)(state + san9::injection2026::NatureAttractCoef), 1u, nullptr) )
    {
      writeValueOrError = 426;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7360), (LPCVOID)(state + san9::injection2026::OnePersonKillerProp), 1u, nullptr) )
    {
      writeValueOrError = 421;
      goto reportWriteFailure;
    }
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)(*(_DWORD *)(state + 7360) + 8),
            (LPCVOID)(state + san9::injection2026::TwoPersonKillerProp),
            1u,
            nullptr) )
    {
      writeValueOrError = 421;
      goto reportWriteFailure;
    }
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)(*(_DWORD *)(state + 7360) + 16),
            (LPCVOID)(state + san9::injection2026::ThreePersonKillerProp),
            1u,
            nullptr) )
    {
      writeValueOrError = 421;
      goto reportWriteFailure;
    }
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)(*(_DWORD *)(state + 7360) + 24),
            (LPCVOID)(state + san9::injection2026::FourPersonKillerProp),
            1u,
            nullptr) )
    {
      writeValueOrError = 421;
      goto reportWriteFailure;
    }
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)(*(_DWORD *)(state + 7360) + 32),
            (LPCVOID)(state + san9::injection2026::FivePersonKillerProp),
            1u,
            nullptr) )
    {
      writeValueOrError = 421;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43FF19, (LPCVOID)(state + san9::injection2026::AntiPlayerLeagueCoef), 1u, nullptr) )
    {
      writeValueOrError = 389;
      goto reportWriteFailure;
    }
    writeValueOrError = 4 - (*(_DWORD *)(state + san9::injection2026::AntiPlayerLeagueCoef) >> 2);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::CheckLeagueProbabilityAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 337;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::LeagueTimeAddr), (LPCVOID)(state + san9::injection2026::LeagueTime), 1u, nullptr) )
    {
      writeValueOrError = 338;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43FF1A, (LPCVOID)(state + san9::injection2026::FightSubIncomeCoef), 1u, nullptr) )
    {
      writeValueOrError = 430;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43FF1D, (LPCVOID)(state + san9::injection2026::MaxCaptiveCoef), 1u, nullptr) )
    {
      writeValueOrError = 347;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43F3D1, (LPCVOID)(state + san9::injection2026::BasicAbilityCoef), 1u, nullptr) )
    {
      writeValueOrError = 432;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::SexCoefAddr), (LPCVOID)(state + san9::injection2026::SexCoef), 1u, nullptr) )
    {
      writeValueOrError = 434;
      goto reportWriteFailure;
    }
    writeValueOrError = (unsigned __int8)*(_DWORD *)(state + san9::injection2026::TroopViewRange)
                 + (((unsigned __int8)*(_DWORD *)(state + san9::injection2026::BuildingViewRange)
                   + (((unsigned __int8)*(_DWORD *)(state + san9::injection2026::CityViewRange) + ((*(_DWORD *)(state + san9::injection2026::SoldierDisplayError) & 0x7F) << 8)) << 8)) << 8);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43F887, &writeValueOrError, 4u, nullptr) )
    {
      writeValueOrError = 412;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43F88F, (LPCVOID)(state + san9::injection2026::CounselorReportCoef), 1u, nullptr) )
    {
      writeValueOrError = 418;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 4828), &dword_42D948, 0x190u, nullptr) )
    {
      writeValueOrError = 452;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 4832), &byte_42DAD8, 0x32u, nullptr) )
    {
      writeValueOrError = 451;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::EnableTrainEnabled) != 0 ? 0x32 : 0;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6224), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 302;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6228), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 302;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::AllPersonLiveEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::AllPersonLive);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldAllPersonLive);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::AllPersonLiveAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 344;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::DynamicAddProficiencyEnabled) != 0 ? 47513 : 10219;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F2B0, &writeValueOrError, 2u, nullptr) )
    {
      writeValueOrError = 342;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::DisableAlienateEnabled) != 0 ? 22 : 10;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)(reinterpret_cast<std::uintptr_t>(dword_41FFA4) + 24), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 343;
      goto reportWriteFailure;
    }
    selectedSoldierCommandKillerIndexBias = -(*(_DWORD *)(state + san9::injection2026::SoldierCommandKillerEnabled) != 0);
    selectedSoldierCommandKillerIndexBias = (selectedSoldierCommandKillerIndexBias & ~0xFF) | ((selectedSoldierCommandKillerIndexBias & 0xFE) & 0xFF);
    writeValueOrError = selectedSoldierCommandKillerIndexBias + 204;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F49C + 88, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 349;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::AllPersonDeadEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + 6608);
    else
      writeValueOrError = *(_DWORD *)(state + 6612);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6596), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 345;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6600), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 345;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6604), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 345;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::FriendToAlienateEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_424D20[3 * writeValueOrError], sourceVA(*(&off_424D28 + 3 * writeValueOrError)),
            dword_424D24[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 929;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::FriendToAlienateEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + 7056);
    else
      writeValueOrError = *(_DWORD *)(state + 7060);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7052), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 406;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::FriendToAlienateEnabled) != 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_4256A0[3 * writeValueOrError], sourceVA(*(&off_4256A8 + 3 * writeValueOrError)),
            dword_4256A4[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 927;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::FriendToAlienateEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_428B10[3 * writeValueOrError], sourceVA(*(&off_428B18 + 3 * writeValueOrError)),
            dword_428B14[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 1087;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::UpdateWaterKillerPropEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_427A70[3 * writeValueOrError], sourceVA(*(&off_427A78 + 3 * writeValueOrError)),
            dword_427A74[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 1032;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::AbilityKillerPropEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_429038[3 * writeValueOrError], sourceVA(*(&off_429040 + 3 * writeValueOrError)),
            dword_42903C[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 1104;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::SubWoundSoldierEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::TroopWound);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldTroopWound);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::TroopWoundAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 336;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::SubWoundSoldierEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::BuildingWound);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldBuildingWound);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::BuildingWoundAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 336;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::ChangeTroopCommandEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_4279F8[3 * writeValueOrError], sourceVA(*(&off_427A00 + 3 * writeValueOrError)),
            dword_4279FC[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 1007;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::NpcAllieAttackEnabled) != 0 ? 5 : 0;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F454 + 26, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 358;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::NpcAllieAttackEnabled) != 0;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F450 + 9, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 358;
      goto reportWriteFailure;
    }
    selectedNpcAllieAttackIndexBias = -(*(_DWORD *)(state + san9::injection2026::NpcAllieAttackEnabled) != 0);
    selectedNpcAllieAttackIndexBias = (selectedNpcAllieAttackIndexBias & ~0xFF) | ((selectedNpcAllieAttackIndexBias & 0x8A) & 0xFF);
    writeValueOrError = selectedNpcAllieAttackIndexBias + 235;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F3B8 + 28, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 358;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::DisableNpcPlotForceEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::DisableNpcPlotForce);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldDisableNpcPlotForce);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::DisableNpcPlotForceAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 364;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::BurnFoodEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::BurnFoodProbability);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldBurnFoodProbability);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::BurnFoodProbabilityAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 368;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::BurnFoodEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::BurnFoodEffect);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldBurnFoodEffect);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::BurnFoodEffectAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 368;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::BurnFoodEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::BurnBuildingEffect);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldBurnBuildingEffect);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::BurnBuildingEffectAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 368;
      goto reportWriteFailure;
    }
    selectedDisableBurnIndexBias = -(*(_DWORD *)(state + san9::injection2026::DisableBurnEnabled) != 0);
    selectedDisableBurnIndexBias = (selectedDisableBurnIndexBias & ~0xFF) | ((selectedDisableBurnIndexBias & 0xAE) & 0xFF);
    writeValueOrError = selectedDisableBurnIndexBias + 133;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6924), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 369;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::MunicipalDraftEnabled) != 0 ? 0 : 3;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F364 + 41, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 399;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::DoubleBuildingDefenseEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::BuildingDefenseCoef);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldBuildingDefenseCoef);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::BuildingDefenseCoefAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 350;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::DisableSearchEventEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::EventMeetHuaTuo);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldEventMeetHuaTuo);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::EventMeetHuaTuoAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 394;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::SubRobFoodEnabled) != 0;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43FF1C, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 411;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::DynamicAddAbilityEnabled) != 0 ? 6 : 0;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F27C + 1, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 400;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::DispatchSoldierToPlayerEnabled) != 0 ? 116 : 235;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F33C + 45, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 388;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::SubCounsellorJudgeEnabled) != 0 ? 3 : 1;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)(dword_41FD34 + 3), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 374;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::SubCounsellorJudgeEnabled) != 0 ? 9 : 5;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_41FDC0 + 29, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 374;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::AddNpcMoneyFoodEnabled) != 0;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43FF16, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 375;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::SearchMaxAbilityEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::MaxBasicAbility);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldMaxBasicAbility);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::MaxSearchAbilityAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 396;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::MaxBasicAbilityAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 319;
      goto reportWriteFailure;
    }
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)(*(_DWORD *)(state + san9::injection2026::MaxBasicAbilityAddr) + 48),
            &writeValueOrError,
            1u,
            nullptr) )
    {
      writeValueOrError = 319;
      goto reportWriteFailure;
    }
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)(*(_DWORD *)(state + san9::injection2026::MaxBasicAbilityAddr) + 96),
            &writeValueOrError,
            1u,
            nullptr) )
    {
      writeValueOrError = 319;
      goto reportWriteFailure;
    }
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)(*(_DWORD *)(state + san9::injection2026::MaxBasicAbilityAddr) + 144),
            &writeValueOrError,
            1u,
            nullptr) )
    {
      writeValueOrError = 319;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::NotAddDraftEnabled) != 0 ? 3051 : 1795;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F140 + 14, &writeValueOrError, 2u, nullptr) )
    {
      writeValueOrError = 376;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::AlikeKillerLinkageEnabled) != 0 ? 0xE : 0;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F36C + 1, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 377;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::EnableBaramArrayEnabled) != 0 ? 86 : 195;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1A8, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 351;
      goto reportWriteFailure;
    }
    selectedEnableRelayDispatchIndexBias = -(*(_DWORD *)(state + san9::injection2026::EnableRelayDispatchEnabled) != 0);
    selectedEnableRelayDispatchIndexBias = (selectedEnableRelayDispatchIndexBias & ~0xFF) | ((selectedEnableRelayDispatchIndexBias & 0x8A) & 0xFF);
    writeValueOrError = selectedEnableRelayDispatchIndexBias + 235;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F52C + 20, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 384;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::DisableNpcPlotForceEnabled) != 0;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43F4CD, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 364;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::WeakenLongRangeKillerEnabled) != 0 ? 86 : 195;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1A0, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 404;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::MunicipalForceDraftEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::MunicipalForceDraft);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldMunicipalForceDraft);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6876), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 316;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::MunicipalForceDraftEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + 7440);
    else
      writeValueOrError = *(_DWORD *)(state + 7444);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7436), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 1145;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::MinDurabilityZeroEnabled) != 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_41F9E0[3 * writeValueOrError], sourceVA(*(&off_41F9E8 + 3 * writeValueOrError)),
            dword_41F9E4[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 109;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::FightKillerPropEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_422998[3 * writeValueOrError], sourceVA(*(&off_4229A0 + 3 * writeValueOrError)),
            dword_42299C[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 758;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::NotSureCaptiveEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_422748[3 * writeValueOrError], sourceVA(*(&off_422750 + 3 * writeValueOrError)),
            dword_42274C[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 740;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::GooseKillerLinkageEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_4285E8[3 * writeValueOrError], sourceVA(*(&off_4285F0 + 3 * writeValueOrError)),
            dword_4285EC[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 242;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::GooseKillerLinkageEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::BlockArrayNum);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldBlockArrayNum);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::BlockArrayNumAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 1111;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::NullCitySubMunicipalEnabled) != 0;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43F4CE, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 424;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::NpcSearchTreasureEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::NpcSearchTreasure);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldNpcSearchTreasure);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::NpcSearchTreasureAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 347;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::NpcSearchTreasureEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::NpcDisplayTreasure);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldNpcDisplayTreasure);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::NpcDisplayTreasureAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 347;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::SoldierSubKillerEnabled) != 0 ? 61943 : 747;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F49C + 33, &writeValueOrError, 2u, nullptr) )
    {
      writeValueOrError = 349;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::NpcAutoDraftEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_428AD8[3 * writeValueOrError], sourceVA((&off_428AE0)[3 * writeValueOrError]),
            dword_428ADC[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 1163;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::PlayerAutoProcessEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_428B70[3 * writeValueOrError], sourceVA(*(&off_428B78 + 3 * writeValueOrError)),
            dword_428B74[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 1089;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::LowDurabilityChaosEnabled) != 0;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (LPVOID)0x43FF1B, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 431;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::LeaderInspireEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_428E78[3 * writeValueOrError], sourceVA(*(&off_428E80 + 3 * writeValueOrError)),
            dword_428E7C[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 1098;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::DisableKillPersonEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::KillPersonProp);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldKillPersonProp);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::KillPersonPropAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 433;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::KillAddProficiencyEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::BattleExperienceCode);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::BattleExperienceOldCode);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::BattleExperienceAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 306;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::KillAddProficiencyEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::WaterExperienceCode);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::WaterExperienceOldCode);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::WaterExperienceAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 307;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::DisableMovePersonEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::EnableGoMenu);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldEnableGoMenu);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::EnableGoMenuAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 435;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::EnableComeMenuAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 435;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::GeneralDeadEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + 6628);
    else
      writeValueOrError = *(_DWORD *)(state + 6632);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6616), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 345;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6620), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 345;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 6624), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 345;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::BarbarianNotDisappearEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + 7412);
    else
      writeValueOrError = *(_DWORD *)(state + 7416);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7400), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 1112;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7404), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 1112;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7408), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 1112;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::AddKillerJianyuEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_429178[3 * writeValueOrError], sourceVA(*(&off_429180 + 3 * writeValueOrError)),
            dword_42917C[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 1116;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::AddKillerJianyuEnabled) != 0 ? 1 : 5;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F0FC + 9, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 1120;
      goto reportWriteFailure;
    }
    writeValueOrError = 6 - (*(_DWORD *)(state + san9::injection2026::DisableKillerJianlanEnabled) != 0);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F0FC + 4, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 1121;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::DisableKillerJianlanEnabled) == 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_429208[3 * writeValueOrError], sourceVA(*(&off_429210 + 3 * writeValueOrError)),
            dword_42920C[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 1119;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::NotDisplayExchangeEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::NotDisplayExchange);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldNotDisplayExchange);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::NotDisplayExchangeAddr1), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 1123;
      goto reportWriteFailure;
    }
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::NotDisplayExchangeAddr2), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 1123;
      goto reportWriteFailure;
    }
    selectedEnableCityPopulationCoefIndexBias = -(*(_DWORD *)(state + san9::injection2026::EnableCityPopulationCoefEnabled) != 0);
    selectedEnableCityPopulationCoefIndexBias = (selectedEnableCityPopulationCoefIndexBias & ~0xFF) | ((selectedEnableCityPopulationCoefIndexBias & 0x4C) & 0xFF);
    writeValueOrError = selectedEnableCityPopulationCoefIndexBias + 195;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42F150 + 6, &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 1148;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::Parameter1164) != 0 )
      writeValueOrError = *(_DWORD *)(state + 7572);
    else
      writeValueOrError = *(_DWORD *)(state + 7576);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + 7568), &writeValueOrError, 2u, nullptr) )
    {
      writeValueOrError = 1166;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::Parameter1165) != 0 ? 30089 : 59011;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), (char *)dword_42B5B0 + 8, &writeValueOrError, 2u, nullptr) )
    {
      writeValueOrError = 1170;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::WarFogEnabled) != 0 ? 53811 : 5867;
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), dword_42F1FC, &writeValueOrError, 2u, nullptr) )
    {
      writeValueOrError = 413;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::WarFogEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::DisableBurnExplorer);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldDisableBurnExplorer);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::DisableBurnExplorerAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 415;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::WarFogEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::DisableAttackExplorer);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldDisableAttackExplorer);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::DisableAttackExplorerAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 416;
      goto reportWriteFailure;
    }
    if ( *(_DWORD *)(state + san9::injection2026::WarFogEnabled) != 0 )
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::MaskPersonWhere);
    else
      writeValueOrError = *(_DWORD *)(state + san9::injection2026::OldMaskPersonWhere);
    if ( !writeMemory(*(HANDLE *)(state + san9::layout2026::ProcessHandle), *(LPVOID *)(state + san9::injection2026::MaskPersonWhereAddr), &writeValueOrError, 1u, nullptr) )
    {
      writeValueOrError = 417;
      goto reportWriteFailure;
    }
    writeValueOrError = *(_DWORD *)(state + san9::injection2026::WarFogEnabled) != 0;
    if ( !writeMemory(
            *(HANDLE *)(state + san9::layout2026::ProcessHandle),
            (LPVOID)dword_42A780[3 * writeValueOrError], sourceVA(*(&off_42A788 + 3 * writeValueOrError)),
            dword_42A784[3 * writeValueOrError],
            nullptr) )
    {
      writeValueOrError = 286;
      goto reportWriteFailure;
    }
    goto applyConfiguration;
  }
  *(_DWORD *)(state + san9::layout2026::ProcessHandle) = 0;
  *(_DWORD *)(state + san9::layout2026::TargetWindow) = 0;
  *(_DWORD *)(state + san9::layout2026::ConnectTicks) = 0;
  setStatus(RuntimeStatusKind2026::WaitingForGame);
finishModification:
  return;
}
