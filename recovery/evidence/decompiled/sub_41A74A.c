// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A74A; original name: ?FromHandle@CWnd@@SGPAV1@PAUHWND__@@@Z
// attributes: thunk
static struct CWnd *__stdcall CWnd::FromHandle(HWND a1)
{
  return __imp_?FromHandle@CWnd@@SGPAV1@PAUHWND__@@@Z(a1);
}
