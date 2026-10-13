// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A666; original name: ?DoModal@CFileDialog@@UAEHXZ
// attributes: thunk
int __thiscall CFileDialog::DoModal(CFileDialog *this)
{
  return __imp_?DoModal@CFileDialog@@UAEHXZ(this);
}
