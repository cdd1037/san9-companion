// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A756; original name: ?OnDDECommand@CWinApp@@UAEHPAD@Z
// attributes: thunk
int __thiscall CWinApp::OnDDECommand(CWinApp *this, char *a2)
{
  return __imp_?OnDDECommand@CWinApp@@UAEHPAD@Z(this, a2);
}
