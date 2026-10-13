// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A6BA; original name: ?GetDlgItem@CWnd@@QBEPAV1@H@Z
// attributes: thunk
struct CWnd *__thiscall CWnd::GetDlgItem(CWnd *this, int a2)
{
  return __imp_?GetDlgItem@CWnd@@QBEPAV1@H@Z(this, a2);
}
