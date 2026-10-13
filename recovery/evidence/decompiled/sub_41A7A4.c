// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A7A4; original name: ?OnIdle@CWinApp@@UAEHJ@Z
// attributes: thunk
int __thiscall CWinApp::OnIdle(CWinApp *this, int a2)
{
  return __imp_?OnIdle@CWinApp@@UAEHJ@Z(this, a2);
}
