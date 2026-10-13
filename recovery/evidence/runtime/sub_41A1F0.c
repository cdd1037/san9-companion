BOOL __thiscall sub_41A1F0(int this, int a2)
{
  int v3; // eax
  BOOL result; // eax
  int v5; // eax

  v3 = -(a2 != 0);
  LOBYTE(v3) = v3 & 0xFA;
  result = WriteProcessMemory(
             *(HANDLE *)(this + 112),
             (LPVOID)(*(_DWORD *)(this + 5616) + 68),
             (LPCVOID)(this + 4 * (v3 + 15) + 5224),
             4u,
             nullptr);
  if ( result )
  {
    result = WriteProcessMemory(
               *(HANDLE *)(this + 112),
               (LPVOID)(*(_DWORD *)(this + 5548) + 68),
               (LPCVOID)(this + 4 * ((a2 != 0) + 9) + 5224),
               4u,
               nullptr);
    if ( result )
    {
      result = WriteProcessMemory(
                 *(HANDLE *)(this + 112),
                 (LPVOID)(*(_DWORD *)(this + 5552) + 68),
                 (LPCVOID)(this + 4 * (a2 != 0 ? 12 : 9) + 5224),
                 4u,
                 nullptr);
      if ( result )
      {
        v5 = -(a2 != 0);
        LOBYTE(v5) = v5 & 0xF8;
        result = WriteProcessMemory(
                   *(HANDLE *)(this + 112),
                   (LPVOID)(*(_DWORD *)(this + 5608) + 68),
                   (LPCVOID)(this + 4 * (v5 + 15) + 5224),
                   4u,
                   nullptr);
        if ( result )
        {
          result = WriteProcessMemory(
                     *(HANDLE *)(this + 112),
                     (LPVOID)(*(_DWORD *)(this + 5660) + 68),
                     (LPCVOID)(this + 4 * ((a2 != 0) + 17) + 5224),
                     4u,
                     nullptr);
          if ( result )
          {
            result = WriteProcessMemory(
                       *(HANDLE *)(this + 112),
                       (LPVOID)(*(_DWORD *)(this + 5948) + 68),
                       (LPCVOID)(this + 4 * (a2 != 0 ? 34 : 44) + 5224),
                       4u,
                       nullptr);
            if ( result )
              return WriteProcessMemory(
                       *(HANDLE *)(this + 112),
                       (LPVOID)(*(_DWORD *)(this + 5824) + 68),
                       (LPCVOID)(this + 4 * (a2 != 0 ? 34 : 32) + 5224),
                       4u,
                       nullptr);
          }
        }
      }
    }
  }
  return result;
}
