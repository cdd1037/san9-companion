// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A612; original name: ?AfxMessageBox@@YGHPBDII@Z
// attributes: thunk
int __stdcall AfxMessageBox(const char *a1, unsigned int a2, unsigned int a3)
{
  return __imp_?AfxMessageBox@@YGHPBDII@Z(a1, a2, a3);
}
