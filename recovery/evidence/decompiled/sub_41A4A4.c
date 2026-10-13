// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A4A4; original name: ?SetOccDialogInfo@CWnd@@MAEHPAU_AFX_OCC_DIALOG_INFO@@@Z
// attributes: thunk
int __thiscall CWnd::SetOccDialogInfo(CWnd *this, struct _AFX_OCC_DIALOG_INFO *a2)
{
  return __imp_?SetOccDialogInfo@CWnd@@MAEHPAU_AFX_OCC_DIALOG_INFO@@@Z(this, a2);
}
