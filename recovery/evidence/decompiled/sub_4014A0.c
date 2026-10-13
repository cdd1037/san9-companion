// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004014A0; original name: sub_4014A0
unsigned __int8 __thiscall sub_4014A0(CWnd *this)
{
  unsigned __int8 v2; // cl
  unsigned __int8 result; // al
  int v4; // eax
  int v5; // edx
  int v6; // eax
  unsigned int v7; // edx

  v2 = *((_BYTE *)this + 205);
  result = *((_BYTE *)this + 204);
  if ( v2 < result )
  {
    v4 = *((_DWORD *)this + 49);
    v5 = *(_DWORD *)(v4 + 8 * v2);
    v6 = v4 + 8 * v2;
    *((_DWORD *)this + 46) = v5 & 0x3F;
    *((_DWORD *)this + 45) = (*(_DWORD *)v6 >> 6) & 0x3F;
    *((_DWORD *)this + 44) = (*(_DWORD *)v6 >> 12) & 0x3F;
    *((_DWORD *)this + 41) = (*(_DWORD *)v6 >> 18) & 0x3F;
    *((_DWORD *)this + 43) = HIBYTE(*(_DWORD *)v6) & 0x3F;
    *((_DWORD *)this + 40) = *(_BYTE *)(v6 + 4) & 0xF;
    v7 = *(unsigned __int8 *)(v6 + 4) >> 4;
    *((_DWORD *)this + 48) = v7;
    LOWORD(v7) = *(_WORD *)(v6 + 4);
    *((_DWORD *)this + 47) = (v7 >> 8) & 0xF;
    *((_DWORD *)this + 42) = *(unsigned __int16 *)(v6 + 6);
    SendMessageA(*((HWND *)this + 32), 0x186u, v2, 0);
    return CWnd::UpdateData(this, 0);
  }
  return result;
}
