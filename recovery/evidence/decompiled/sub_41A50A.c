// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A50A; original name: ?OnWndMsg@CWnd@@MAEHIIJPAJ@Z
// attributes: thunk
int __thiscall CWnd::OnWndMsg(CWnd *this, unsigned int a2, unsigned int a3, int a4, int *a5)
{
  return __imp_?OnWndMsg@CWnd@@MAEHIIJPAJ@Z(this, a2, a3, a4, a5);
}
