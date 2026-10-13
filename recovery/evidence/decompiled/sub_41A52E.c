// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A52E; original name: ?OnCommand@CWnd@@MAEHIJ@Z
// attributes: thunk
int __thiscall CWnd::OnCommand(CWnd *this, unsigned int a2, int a3)
{
  return __imp_?OnCommand@CWnd@@MAEHIJ@Z(this, a2, a3);
}
