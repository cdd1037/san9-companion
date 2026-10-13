// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A510; original name: ?WindowProc@CWnd@@MAEJIIJ@Z
// attributes: thunk
int __thiscall CWnd::WindowProc(CWnd *this, unsigned int a2, unsigned int a3, int a4)
{
  return __imp_?WindowProc@CWnd@@MAEJIIJ@Z(this, a2, a3, a4);
}
