// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A4E6; original name: ?SetOccDialogInfo@CDialog@@MAEHPAU_AFX_OCC_DIALOG_INFO@@@Z
// attributes: thunk
int __thiscall CDialog::SetOccDialogInfo(CDialog *this, struct _AFX_OCC_DIALOG_INFO *a2)
{
  return __imp_?SetOccDialogInfo@CDialog@@MAEHPAU_AFX_OCC_DIALOG_INFO@@@Z(this, a2);
}
