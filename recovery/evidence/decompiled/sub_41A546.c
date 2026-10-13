// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A546; original name: ?GetScrollBarCtrl@CWnd@@UBEPAVCScrollBar@@H@Z
// attributes: thunk
struct CScrollBar *__thiscall CWnd::GetScrollBarCtrl(CWnd *this, int a2)
{
  return __imp_?GetScrollBarCtrl@CWnd@@UBEPAVCScrollBar@@H@Z(this, a2);
}
