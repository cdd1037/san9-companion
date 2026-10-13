// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A660; original name: ?GetPathName@CFileDialog@@QBE?AVCString@@XZ
// attributes: thunk
int __thiscall CFileDialog::GetPathName(void *this, int a2)
{
  return __imp_?GetPathName@CFileDialog@@QBE?AVCString@@XZ(this, a2);
}
