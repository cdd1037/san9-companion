// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00402BB0; original name: sub_402BB0
int __thiscall sub_402BB0(int this)
{
  int result; // eax

  result = CWnd::UpdateData((CWnd *)this, 1);
  if ( result != 0 )
  {
    *(_BYTE *)(*(_DWORD *)(this + 172) + 4 * *(unsigned __int8 *)(this + 181)) = *(_BYTE *)(this + 168);
    *(_BYTE *)(*(_DWORD *)(this + 172) + 4 * *(unsigned __int8 *)(this + 181) + 1) = *(_BYTE *)(this + 160);
    *(_WORD *)(*(_DWORD *)(this + 172) + 4 * *(unsigned __int8 *)(this + 181) + 2) = *(_WORD *)(this + 164);
    return 1;
  }
  return result;
}
