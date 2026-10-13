// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A54C; original name: ?OnToolHitTest@CWnd@@UBEHVCPoint@@PAUtagTOOLINFOA@@@Z
// attributes: thunk
int __stdcall CWnd::OnToolHitTest(int a1, int a2, int a3)
{
  return __imp_?OnToolHitTest@CWnd@@UBEHVCPoint@@PAUtagTOOLINFOA@@@Z(a1, a2, a3);
}
