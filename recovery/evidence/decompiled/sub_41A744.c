// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A744; original name: ?GetDlgCtrlID@CWnd@@QBEHXZ
// attributes: thunk
int __thiscall CWnd::GetDlgCtrlID(CWnd *this)
{
  return __imp_?GetDlgCtrlID@CWnd@@QBEHXZ(this);
}
