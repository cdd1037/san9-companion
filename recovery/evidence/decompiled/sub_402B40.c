// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00402B40; original name: sub_402B40
unsigned __int8 __thiscall sub_402B40(CWnd *this)
{
  unsigned __int8 result; // al
  int v3; // ecx
  int v4; // edx
  int v5; // ecx

  result = *((_BYTE *)this + 181);
  if ( result < *((_BYTE *)this + 180) )
  {
    v3 = *((_DWORD *)this + 43);
    v4 = *(unsigned __int8 *)(v3 + 4 * result);
    v5 = v3 + 4 * result;
    *((_DWORD *)this + 42) = v4;
    *((_DWORD *)this + 40) = *(unsigned __int8 *)(v5 + 1);
    *((_DWORD *)this + 41) = *(unsigned __int16 *)(v5 + 2);
    SendMessageA(*((HWND *)this + 32), 0x186u, result, 0);
    return CWnd::UpdateData(this, 0);
  }
  return result;
}
