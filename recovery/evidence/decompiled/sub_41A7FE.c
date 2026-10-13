// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A7FE; original name: ?SetWindowTextA@CWnd@@QAEXPBD@Z
// attributes: thunk
void __thiscall CWnd::SetWindowTextA(CWnd *this, const char *a2)
{
  __imp_?SetWindowTextA@CWnd@@QAEXPBD@Z(this, a2);
}
