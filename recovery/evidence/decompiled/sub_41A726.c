// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A726; original name: ?ModifyStyle@CWnd@@QAEHKKI@Z
// attributes: thunk
int __thiscall CWnd::ModifyStyle(CWnd *this, unsigned int a2, unsigned int a3, unsigned int a4)
{
  return __imp_?ModifyStyle@CWnd@@QAEHKKI@Z(this, a2, a3, a4);
}
