// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A4E0; original name: ?DoModal@CDialog@@UAEHXZ
// attributes: thunk
int __thiscall CDialog::DoModal(CDialog *this)
{
  return __imp_?DoModal@CDialog@@UAEHXZ(this);
}
