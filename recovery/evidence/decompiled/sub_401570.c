// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401570; original name: sub_401570
int __thiscall sub_401570(int this)
{
  int result; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  __int16 v7; // dx

  result = CWnd::UpdateData((CWnd *)this, 1);
  if ( result != 0 )
  {
    *(_DWORD *)(*(_DWORD *)(this + 196) + 8 * *(unsigned __int8 *)(this + 205)) = *(_DWORD *)(this + 184);
    v3 = (_DWORD *)(*(_DWORD *)(this + 196) + 8 * *(unsigned __int8 *)(this + 205));
    *v3 |= *(_DWORD *)(this + 180) << 6;
    v4 = (_DWORD *)(*(_DWORD *)(this + 196) + 8 * *(unsigned __int8 *)(this + 205));
    *v4 |= *(_DWORD *)(this + 176) << 12;
    v5 = (_DWORD *)(*(_DWORD *)(this + 196) + 8 * *(unsigned __int8 *)(this + 205));
    *v5 |= *(_DWORD *)(this + 164) << 18;
    v6 = (_DWORD *)(*(_DWORD *)(this + 196) + 8 * *(unsigned __int8 *)(this + 205));
    *v6 |= *(_DWORD *)(this + 172) << 24;
    *(_WORD *)(*(_DWORD *)(this + 196) + 8 * *(unsigned __int8 *)(this + 205) + 4) = *(_WORD *)(this + 160);
    *(_WORD *)(*(_DWORD *)(this + 196) + 8 * *(unsigned __int8 *)(this + 205) + 4) |= 16 * *(_WORD *)(this + 192);
    LOBYTE(v7) = 0;
    HIBYTE(v7) = *(_BYTE *)(this + 188);
    *(_WORD *)(*(_DWORD *)(this + 196) + 8 * *(unsigned __int8 *)(this + 205) + 4) |= v7;
    *(_WORD *)(*(_DWORD *)(this + 196) + 8 * *(unsigned __int8 *)(this + 205) + 6) = *(_WORD *)(this + 168);
    return 1;
  }
  return result;
}
