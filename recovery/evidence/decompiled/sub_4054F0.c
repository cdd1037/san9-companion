// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004054F0; original name: sub_4054F0
int __thiscall sub_4054F0(int this)
{
  _WORD *v1; // eax

  v1 = (_WORD *)(*(_DWORD *)(this + 31568) + 6 * *(_DWORD *)(this + 328));
  *(_WORD *)(this + 324) = *v1;
  *(_WORD *)(this + 326) = v1[1];
  *(_WORD *)(this + 322) = v1[2];
  return CWnd::UpdateData((CWnd *)this, 0);
}
