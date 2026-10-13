// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A6B4; original name: ?SetFocus@CWnd@@QAEPAV1@XZ
// attributes: thunk
struct CWnd *__thiscall CWnd::SetFocus(CWnd *this)
{
  return __imp_?SetFocus@CWnd@@QAEPAV1@XZ(this);
}
