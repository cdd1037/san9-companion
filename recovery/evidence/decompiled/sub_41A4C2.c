// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A4C2; original name: ?OnCmdMsg@CCmdTarget@@UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z
// attributes: thunk
int __thiscall CCmdTarget::OnCmdMsg(CCmdTarget *this, unsigned int a2, int a3, void *a4, struct AFX_CMDHANDLERINFO *a5)
{
  return __imp_?OnCmdMsg@CCmdTarget@@UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z(this, a2, a3, a4, a5);
}
