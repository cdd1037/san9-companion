// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A636; original name: ?GetErrorMessage@CFileException@@UAEHPADIPAI@Z
// attributes: thunk
int __thiscall CFileException::GetErrorMessage(CFileException *this, char *a2, unsigned int a3, unsigned int *a4)
{
  return __imp_?GetErrorMessage@CFileException@@UAEHPADIPAI@Z(this, a2, a3, a4);
}
