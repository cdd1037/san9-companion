// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A55E; original name: ?DestroyWindow@CWnd@@UAEHXZ
// attributes: thunk
int __thiscall CWnd::DestroyWindow(CWnd *this)
{
  return __imp_?DestroyWindow@CWnd@@UAEHXZ(this);
}
