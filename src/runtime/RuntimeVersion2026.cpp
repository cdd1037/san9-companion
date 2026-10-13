#include "Runtime2026.h"

using _DWORD = DWORD;
using _WORD = WORD;
using _BYTE = BYTE;
static_assert(sizeof(void*) == 4, "2026 injection requires Win32");
#include "../generated/Symbols.inc"

// Maintained source. Evidence is retained for review, not used to regenerate this file.
// Recovered control flow from 0x409840.
// 校验游戏版本后初始化都市、地域地址和三 DWORD 写入描述符（目标、长度、宿主源缓冲区）。
bool Runtime2026::checkVersion()
{
  const auto state = reinterpret_cast<std::uintptr_t>(state_.data());
  int cityAddressCursor;
  int remainingCities;
  int previousCityAddress;
  int zoneAddressCursor;
  int remainingZones;
  int previousZoneAddress;
  char *patchCodeCursorAt4204C8;
  _DWORD *patchDescriptorCursorAt42F704;
  int patchIndexAt4204B8;
  int patchTargetAt4204B8;
  char *patchCodeCursorAt41F9B0;
  _DWORD *patchDescriptorCursorAt42F584;
  int patchIndexAt41F9A0;
  int patchTargetAt41F9A0;
  char *patchCodeCursorAt4210A8;
  LPCVOID *patchDescriptorCursorAt42F7BC;
  int patchIndexAt421098;
  int patchTargetAt421098;
  _DWORD *patchDescriptorCursorAt42F59C;
  char *patchCodeCursorAt41FB44;
  int patchIndexAt41FAEC;
  int remainingDispatchPatches;
  int patchTargetAt41FAEC;
  char *patchCodeCursorAt41FF30;
  _DWORD *patchDescriptorCursorAt42F6C4;
  int patchIndexAt41FF18;
  int patchTargetAt41FF18;
  char *patchCodeCursorAt421EB8;
  _DWORD *patchDescriptorCursorAt42F7EC;
  int patchIndexAt421EA8;
  int patchTargetAt421EA8;
  char *patchCodeCursorAt41FE40;
  _DWORD *patchDescriptorCursorAt42F67C;
  int patchIndexAt41FE30;
  int patchTargetAt41FE30;
  char *patchCodeCursorAt420FA0;
  LPCVOID *patchDescriptorCursorAt42F794;
  int patchIndexAt420F88;
  int patchTargetAt420F88;
  char *patchCodeCursorAt41FFC0;
  LPCVOID *patchDescriptorCursorAt42F6EC;
  int patchIndexAt41FFB0;
  int patchTargetAt41FFB0;
  char *patchCodeCursorAt41FEA8;
  _DWORD *patchDescriptorCursorAt42F694;
  int patchIndexAt41FE88;
  int patchTargetAt41FE88;
  char *patchCodeCursorAt420560;
  _DWORD *patchDescriptorCursorAt42F71C;
  int patchIndexAt420548;
  int patchTargetAt420548;
  char *patchCodeCursorAt420CB8;
  LPCVOID *patchDescriptorCursorAt42F76C;
  int patchIndexAt420CA0;
  int patchTargetAt420CA0;
  char *patchCodeCursorAt41FCC8;
  LPCVOID *patchDescriptorCursorAt42F61C;
  int patchIndexAt41FCA8;
  int patchTargetAt41FCA8;
  char *patchCodeCursorAt421D90;
  _DWORD *patchDescriptorCursorAt42F7D4;
  int patchIndexAt421D80;
  int patchTargetAt421D80;
  char *patchCodeCursorAt41FDE8;
  _DWORD *patchDescriptorCursorAt42F664;
  int patchIndexAt41FDD8;
  int patchTargetAt41FDD8;
  char *patchCodeCursorAt41FD40;
  _DWORD *patchDescriptorCursorAt42F64C;
  int patchIndexAt41FD30;
  int patchTargetAt41FD30;
  char *patchCodeCursorAt420B28;
  LPCVOID *patchDescriptorCursorAt42F744;
  int patchIndexAt420B10;
  int patchTargetAt420B10;
  int versionWord;

  if ( !readMemory(
          *(HANDLE *)(state + san9::layout2026::ProcessHandle),
          (LPCVOID)(*(_DWORD *)(state + san9::injection2026::FixedFileInfoOffset) + *(_DWORD *)(state + san9::injection2026::ResourceInfoAddr)),
          &versionWord,
          4u,
          nullptr)
    || versionWord != -17890115
    || !readMemory(
          *(HANDLE *)(state + san9::layout2026::ProcessHandle),
          (LPCVOID)(*(_DWORD *)(state + san9::injection2026::ResourceInfoAddr) + *(_DWORD *)(state + san9::injection2026::FixedFileInfoOffset) + 8),
          &versionWord,
          4u,
          nullptr)
    || versionWord != 0x10000
    || !readMemory(
          *(HANDLE *)(state + san9::layout2026::ProcessHandle),
          (LPCVOID)(*(_DWORD *)(state + san9::injection2026::ResourceInfoAddr) + *(_DWORD *)(state + san9::injection2026::FixedFileInfoOffset) + 12),
          &versionWord,
          4u,
          nullptr)
    || versionWord != 0x10000 )
  {
    return 0;
  }
  *(_DWORD *)(state + san9::injection2026::CityAddresses) = 19192664;
  cityAddressCursor = state + 5228;
  for ( remainingCities = 49; remainingCities != 0; --remainingCities )
  {
    previousCityAddress = *(_DWORD *)(cityAddressCursor - 4);
    cityAddressCursor += 4;
    *(_DWORD *)(cityAddressCursor - 4) = previousCityAddress + 496;
  }
  *(_DWORD *)(state + san9::injection2026::ZoneAddresses) = 19103864;
  zoneAddressCursor = state + 5428;
  for ( remainingZones = 199; remainingZones != 0; --remainingZones )
  {
    previousZoneAddress = *(_DWORD *)(zoneAddressCursor - 4);
    zoneAddressCursor += 4;
    *(_DWORD *)(zoneAddressCursor - 4) = previousZoneAddress + 444;
  }
  patchCodeCursorAt4204C8 = (char *)&unk_4204C8;
  patchDescriptorCursorAt42F704 = &unk_42F704;
  patchIndexAt4204B8 = 0;
  do
  {
    patchTargetAt4204B8 = dword_4204B8[patchIndexAt4204B8++];
    *(patchDescriptorCursorAt42F704 - 1) = patchTargetAt4204B8;
    *patchDescriptorCursorAt42F704 = dword_4204BC[patchIndexAt4204B8];
    patchDescriptorCursorAt42F704[1] = reinterpret_cast<DWORD>(patchCodeCursorAt4204C8);
    patchCodeCursorAt4204C8 += 16;
    patchDescriptorCursorAt42F704 += 3;
  }
  while ( (int)patchCodeCursorAt4204C8 < (int)byte_4204E8 );
  patchCodeCursorAt41F9B0 = (char *)&unk_41F9B0;
  patchDescriptorCursorAt42F584 = &unk_42F584;
  patchIndexAt41F9A0 = 0;
  do
  {
    patchTargetAt41F9A0 = dword_41F9A0[patchIndexAt41F9A0++];
    *(patchDescriptorCursorAt42F584 - 1) = patchTargetAt41F9A0;
    *patchDescriptorCursorAt42F584 = dword_41F9A4[patchIndexAt41F9A0];
    patchDescriptorCursorAt42F584[1] = reinterpret_cast<DWORD>(patchCodeCursorAt41F9B0);
    patchCodeCursorAt41F9B0 += 16;
    patchDescriptorCursorAt42F584 += 3;
  }
  while ( (int)patchCodeCursorAt41F9B0 < (int)codeMinDurabilityThunk );
  patchCodeCursorAt4210A8 = (char *)&unk_4210A8;
  patchDescriptorCursorAt42F7BC = &dword_42F7BC;
  patchIndexAt421098 = 0;
  do
  {
    patchTargetAt421098 = dword_421098[patchIndexAt421098++];
    *(patchDescriptorCursorAt42F7BC - 1) = (LPCVOID)patchTargetAt421098;
    *patchDescriptorCursorAt42F7BC = (LPCVOID)dword_42109C[patchIndexAt421098];
    patchDescriptorCursorAt42F7BC[1] = patchCodeCursorAt4210A8;
    patchCodeCursorAt4210A8 += 16;
    patchDescriptorCursorAt42F7BC += 3;
  }
  while ( (int)patchCodeCursorAt4210A8 < (int)byte_4210C8 );
  patchDescriptorCursorAt42F59C = &unk_42F59C;
  patchCodeCursorAt41FB44 = (char *)&unk_41FB44;
  patchIndexAt41FAEC = 0;
  for ( remainingDispatchPatches = 5; remainingDispatchPatches != 0; --remainingDispatchPatches )
  {
    patchTargetAt41FAEC = dword_41FAEC[patchIndexAt41FAEC--];
    *(patchDescriptorCursorAt42F59C - 1) = patchTargetAt41FAEC;
    *patchDescriptorCursorAt42F59C = dword_41FB04[patchIndexAt41FAEC];
    patchDescriptorCursorAt42F59C[1] = reinterpret_cast<DWORD>(patchCodeCursorAt41FB44);
    patchCodeCursorAt41FB44 -= 16;
    patchDescriptorCursorAt42F59C += 3;
  }
  patchCodeCursorAt41FF30 = (char *)&unk_41FF30;
  patchDescriptorCursorAt42F6C4 = &unk_42F6C4;
  patchIndexAt41FF18 = 0;
  do
  {
    patchTargetAt41FF18 = dword_41FF18[patchIndexAt41FF18++];
    *(patchDescriptorCursorAt42F6C4 - 1) = patchTargetAt41FF18;
    *patchDescriptorCursorAt42F6C4 = dword_41FF20[patchIndexAt41FF18];
    patchDescriptorCursorAt42F6C4[1] = reinterpret_cast<DWORD>(patchCodeCursorAt41FF30);
    patchCodeCursorAt41FF30 += 16;
    patchDescriptorCursorAt42F6C4 += 3;
  }
  while ( (int)patchCodeCursorAt41FF30 < (int)byte_41FF60 );
  patchCodeCursorAt421EB8 = (char *)&unk_421EB8;
  patchDescriptorCursorAt42F7EC = &unk_42F7EC;
  patchIndexAt421EA8 = 0;
  do
  {
    patchTargetAt421EA8 = dword_421EA8[patchIndexAt421EA8++];
    *(patchDescriptorCursorAt42F7EC - 1) = patchTargetAt421EA8;
    *patchDescriptorCursorAt42F7EC = dword_421EAC[patchIndexAt421EA8];
    patchDescriptorCursorAt42F7EC[1] = reinterpret_cast<DWORD>(patchCodeCursorAt421EB8);
    patchCodeCursorAt421EB8 += 16;
    patchDescriptorCursorAt42F7EC += 3;
  }
  while ( (int)patchCodeCursorAt421EB8 < (int)byte_421ED8 );
  patchCodeCursorAt41FE40 = (char *)&unk_41FE40;
  patchDescriptorCursorAt42F67C = &unk_42F67C;
  patchIndexAt41FE30 = 0;
  do
  {
    patchTargetAt41FE30 = dword_41FE30[patchIndexAt41FE30++];
    *(patchDescriptorCursorAt42F67C - 1) = patchTargetAt41FE30;
    *patchDescriptorCursorAt42F67C = dword_41FE34[patchIndexAt41FE30];
    patchDescriptorCursorAt42F67C[1] = reinterpret_cast<DWORD>(patchCodeCursorAt41FE40);
    patchCodeCursorAt41FE40 += 16;
    patchDescriptorCursorAt42F67C += 3;
  }
  while ( (int)patchCodeCursorAt41FE40 < (int)byte_41FE60 );
  patchCodeCursorAt420FA0 = (char *)&unk_420FA0;
  patchDescriptorCursorAt42F794 = &dword_42F794;
  patchIndexAt420F88 = 0;
  do
  {
    patchTargetAt420F88 = dword_420F88[patchIndexAt420F88++];
    *(patchDescriptorCursorAt42F794 - 1) = (LPCVOID)patchTargetAt420F88;
    *patchDescriptorCursorAt42F794 = (LPCVOID)dword_420F90[patchIndexAt420F88];
    patchDescriptorCursorAt42F794[1] = patchCodeCursorAt420FA0;
    patchCodeCursorAt420FA0 += 16;
    patchDescriptorCursorAt42F794 += 3;
  }
  while ( (int)patchCodeCursorAt420FA0 < (int)byte_420FD0 );
  dword_42F5D8 = dword_41FB80;
  dword_42F5DC = dword_41FB84;
  dword_42F5E0 = (int)&unk_41FB88;
  patchCodeCursorAt41FFC0 = (char *)&unk_41FFC0;
  patchDescriptorCursorAt42F6EC = &dword_42F6EC;
  patchIndexAt41FFB0 = 0;
  do
  {
    patchTargetAt41FFB0 = dword_41FFB0[patchIndexAt41FFB0++];
    *(patchDescriptorCursorAt42F6EC - 1) = (LPCVOID)patchTargetAt41FFB0;
    *patchDescriptorCursorAt42F6EC = (LPCVOID)dword_41FFB4[patchIndexAt41FFB0];
    patchDescriptorCursorAt42F6EC[1] = patchCodeCursorAt41FFC0;
    patchCodeCursorAt41FFC0 += 16;
    patchDescriptorCursorAt42F6EC += 3;
  }
  while ( (int)patchCodeCursorAt41FFC0 < (int)byte_41FFE0 );
  dword_42F5E8 = dword_41FBE8;
  dword_42F5EC = dword_41FBEC;
  dword_42F5F0 = (int)&unk_41FBF0;
  patchCodeCursorAt41FEA8 = (char *)&unk_41FEA8;
  patchDescriptorCursorAt42F694 = &unk_42F694;
  patchIndexAt41FE88 = 0;
  do
  {
    patchTargetAt41FE88 = dword_41FE88[patchIndexAt41FE88++];
    *(patchDescriptorCursorAt42F694 - 1) = patchTargetAt41FE88;
    *patchDescriptorCursorAt42F694 = dword_41FE94[patchIndexAt41FE88];
    patchDescriptorCursorAt42F694[1] = reinterpret_cast<DWORD>(patchCodeCursorAt41FEA8);
    patchCodeCursorAt41FEA8 += 16;
    patchDescriptorCursorAt42F694 += 3;
  }
  while ( (int)patchCodeCursorAt41FEA8 < (int)codeEnableDraftThunk );
  patchCodeCursorAt420560 = (char *)&unk_420560;
  patchDescriptorCursorAt42F71C = &unk_42F71C;
  patchIndexAt420548 = 0;
  do
  {
    patchTargetAt420548 = dword_420548[patchIndexAt420548++];
    *(patchDescriptorCursorAt42F71C - 1) = patchTargetAt420548;
    *patchDescriptorCursorAt42F71C = dword_420550[patchIndexAt420548];
    patchDescriptorCursorAt42F71C[1] = reinterpret_cast<DWORD>(patchCodeCursorAt420560);
    patchCodeCursorAt420560 += 16;
    patchDescriptorCursorAt42F71C += 3;
  }
  while ( (int)patchCodeCursorAt420560 < (int)codeMinDispatchSoldierThunk );
  patchCodeCursorAt420CB8 = (char *)&unk_420CB8;
  patchDescriptorCursorAt42F76C = &dword_42F76C;
  patchIndexAt420CA0 = 0;
  do
  {
    patchTargetAt420CA0 = dword_420CA0[patchIndexAt420CA0++];
    *(patchDescriptorCursorAt42F76C - 1) = (LPCVOID)patchTargetAt420CA0;
    *patchDescriptorCursorAt42F76C = (LPCVOID)dword_420CA8[patchIndexAt420CA0];
    patchDescriptorCursorAt42F76C[1] = patchCodeCursorAt420CB8;
    patchCodeCursorAt420CB8 += 16;
    patchDescriptorCursorAt42F76C += 3;
  }
  while ( (int)patchCodeCursorAt420CB8 < (int)byte_420CE8 );
  dword_42F5F8 = dword_41FC28;
  dword_42F5FC = dword_41FC2C;
  dword_42F608 = dword_41FC68;
  dword_42F60C = dword_41FC6C;
  dword_42F600 = (int)&unk_41FC30;
  dword_42F610 = (int)&unk_41FC70;
  patchCodeCursorAt41FCC8 = (char *)&unk_41FCC8;
  patchDescriptorCursorAt42F61C = &dword_42F61C;
  patchIndexAt41FCA8 = 0;
  do
  {
    patchTargetAt41FCA8 = dword_41FCA8[patchIndexAt41FCA8++];
    *(patchDescriptorCursorAt42F61C - 1) = (LPCVOID)patchTargetAt41FCA8;
    *patchDescriptorCursorAt42F61C = (LPCVOID)dword_41FCB4[patchIndexAt41FCA8];
    patchDescriptorCursorAt42F61C[1] = patchCodeCursorAt41FCC8;
    patchCodeCursorAt41FCC8 += 16;
    patchDescriptorCursorAt42F61C += 3;
  }
  while ( (int)patchCodeCursorAt41FCC8 < (int)codeRobMoneyThunk );
  patchCodeCursorAt421D90 = (char *)&unk_421D90;
  patchDescriptorCursorAt42F7D4 = &unk_42F7D4;
  patchIndexAt421D80 = 0;
  do
  {
    patchTargetAt421D80 = dword_421D80[patchIndexAt421D80++];
    *(patchDescriptorCursorAt42F7D4 - 1) = patchTargetAt421D80;
    *patchDescriptorCursorAt42F7D4 = dword_421D84[patchIndexAt421D80];
    patchDescriptorCursorAt42F7D4[1] = reinterpret_cast<DWORD>(patchCodeCursorAt421D90);
    patchCodeCursorAt421D90 += 16;
    patchDescriptorCursorAt42F7D4 += 3;
  }
  while ( (int)patchCodeCursorAt421D90 < (int)byte_421DB0 );
  patchCodeCursorAt41FDE8 = (char *)&unk_41FDE8;
  patchDescriptorCursorAt42F664 = &unk_42F664;
  patchIndexAt41FDD8 = 0;
  do
  {
    patchTargetAt41FDD8 = dword_41FDD8[patchIndexAt41FDD8++];
    *(patchDescriptorCursorAt42F664 - 1) = patchTargetAt41FDD8;
    *patchDescriptorCursorAt42F664 = dword_41FDDC[patchIndexAt41FDD8];
    patchDescriptorCursorAt42F664[1] = reinterpret_cast<DWORD>(patchCodeCursorAt41FDE8);
    patchCodeCursorAt41FDE8 += 16;
    patchDescriptorCursorAt42F664 += 3;
  }
  while ( (int)patchCodeCursorAt41FDE8 < (int)byte_41FE08 );
  patchCodeCursorAt41FD40 = (char *)&unk_41FD40;
  patchDescriptorCursorAt42F64C = &unk_42F64C;
  patchIndexAt41FD30 = 0;
  do
  {
    patchTargetAt41FD30 = dword_41FD30[patchIndexAt41FD30++];
    *(patchDescriptorCursorAt42F64C - 1) = patchTargetAt41FD30;
    *patchDescriptorCursorAt42F64C = pointer<int>(0x41FD34)[patchIndexAt41FD30];
    patchDescriptorCursorAt42F64C[1] = reinterpret_cast<DWORD>(patchCodeCursorAt41FD40);
    patchCodeCursorAt41FD40 += 16;
    patchDescriptorCursorAt42F64C += 3;
  }
  while ( (int)patchCodeCursorAt41FD40 < (int)codePersonJudgementThunk );
  patchCodeCursorAt420B28 = (char *)&unk_420B28;
  patchDescriptorCursorAt42F744 = &dword_42F744;
  patchIndexAt420B10 = 0;
  do
  {
    patchTargetAt420B10 = dword_420B10[patchIndexAt420B10++];
    *(patchDescriptorCursorAt42F744 - 1) = (LPCVOID)patchTargetAt420B10;
    *patchDescriptorCursorAt42F744 = (LPCVOID)dword_420B18[patchIndexAt420B10];
    patchDescriptorCursorAt42F744[1] = patchCodeCursorAt420B28;
    patchCodeCursorAt420B28 += 16;
    patchDescriptorCursorAt42F744 += 3;
  }
  while ( (int)patchCodeCursorAt420B28 < (int)byte_420B58 );
  return 1;
}
