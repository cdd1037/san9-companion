// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A762; original name: ?DoMessageBox@CWinApp@@UAEHPBDII@Z
// attributes: thunk
int __thiscall CWinApp::DoMessageBox(CWinApp *this, const char *a2, unsigned int a3, unsigned int a4)
{
  return __imp_?DoMessageBox@CWinApp@@UAEHPBDII@Z(this, a2, a3, a4);
}
