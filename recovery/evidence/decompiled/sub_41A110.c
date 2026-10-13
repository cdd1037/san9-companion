// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A110; original name: sub_41A110
void __cdecl sub_41A110(CHAR *lpMultiByteStr)
{
  int v1; // esi
  WCHAR *v2; // ebx
  int v3; // esi
  CHAR *v4; // ebp
  CHAR *v5; // [esp+10h] [ebp-4h]

  v1 = MultiByteToWideChar(0x3B6u, 0, lpMultiByteStr, -1, nullptr, 0);
  v2 = (WCHAR *)operator new(2 * v1 + 2);
  MultiByteToWideChar(0x3B6u, 0, lpMultiByteStr, -1, v2, v1);
  v3 = WideCharToMultiByte(0x3A8u, 0, v2, -1, nullptr, 0, nullptr, nullptr);
  v4 = (CHAR *)operator new(v3 + 1);
  v5 = (CHAR *)operator new(v3 + 1);
  WideCharToMultiByte(0x3A8u, 0, v2, -1, v4, v3, nullptr, nullptr);
  LCMapStringA(0x804u, 0x2000000u, v4, -1, v5, v3);
  strcpy(lpMultiByteStr, v5);
  operator delete(v2);
  operator delete(v4);
  operator delete(v5);
}
