// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A4B6; original name: ?PreTranslateMessage@CWnd@@UAEHPAUtagMSG@@@Z
// attributes: thunk
int __thiscall CWnd::PreTranslateMessage(CWnd *this, struct tagMSG *a2)
{
  return __imp_?PreTranslateMessage@CWnd@@UAEHPAUtagMSG@@@Z(this, a2);
}
