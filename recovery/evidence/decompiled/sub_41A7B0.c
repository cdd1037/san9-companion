// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A7B0; original name: ?PreTranslateMessage@CWinThread@@UAEHPAUtagMSG@@@Z
// attributes: thunk
int __thiscall CWinThread::PreTranslateMessage(CWinThread *this, struct tagMSG *a2)
{
  return __imp_?PreTranslateMessage@CWinThread@@UAEHPAUtagMSG@@@Z(this, a2);
}
