// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A4EC; original name: ?IsFrameWnd@CWnd@@UBEHXZ
// attributes: thunk
int __thiscall CWnd::IsFrameWnd(CWnd *this)
{
  return __imp_?IsFrameWnd@CWnd@@UBEHXZ(this);
}
