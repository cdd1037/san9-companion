// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A528; original name: ?OnNotify@CWnd@@MAEHIJPAJ@Z
// attributes: thunk
int __thiscall CWnd::OnNotify(CWnd *this, unsigned int a2, int a3, int *a4)
{
  return __imp_?OnNotify@CWnd@@MAEHIJPAJ@Z(this, a2, a3, a4);
}
