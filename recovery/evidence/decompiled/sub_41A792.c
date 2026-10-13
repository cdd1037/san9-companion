// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A792; original name: ?ProcessWndProcException@CWinApp@@UAEJPAVCException@@PBUtagMSG@@@Z
// attributes: thunk
int __thiscall CWinApp::ProcessWndProcException(CWinApp *this, struct CException *a2, const struct tagMSG *a3)
{
  return __imp_?ProcessWndProcException@CWinApp@@UAEJPAVCException@@PBUtagMSG@@@Z(this, a2, a3);
}
