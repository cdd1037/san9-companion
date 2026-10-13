// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405480; original name: sub_405480
int __thiscall sub_405480(int this)
{
  int result; // eax

  result = CWnd::UpdateData((CWnd *)this, 1);
  if ( result != 0 )
  {
    *(_WORD *)(*(_DWORD *)(this + 31568) + 6 * *(_DWORD *)(this + 328)) = *(_WORD *)(this + 324);
    *(_WORD *)(*(_DWORD *)(this + 31568) + 6 * *(_DWORD *)(this + 328) + 2) = *(_WORD *)(this + 326);
    *(_WORD *)(*(_DWORD *)(this + 31568) + 6 * *(_DWORD *)(this + 328) + 4) = *(_WORD *)(this + 322);
    return 1;
  }
  return result;
}
