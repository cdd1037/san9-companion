// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A4F8; original name: ?OnChildNotify@CWnd@@MAEHIIJPAJ@Z
// attributes: thunk
int __thiscall CWnd::OnChildNotify(CWnd *this, unsigned int a2, unsigned int a3, int a4, int *a5)
{
  return __imp_?OnChildNotify@CWnd@@MAEHIIJPAJ@Z(this, a2, a3, a4, a5);
}
