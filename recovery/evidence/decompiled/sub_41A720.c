// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A720; original name: ?OnHScroll@CWnd@@IAEXIIPAVCScrollBar@@@Z
// attributes: thunk
void __thiscall CWnd::OnHScroll(CWnd *this, unsigned int a2, unsigned int a3, struct CScrollBar *a4)
{
  __imp_?OnHScroll@CWnd@@IAEXIIPAVCScrollBar@@@Z(this, a2, a3, a4);
}
