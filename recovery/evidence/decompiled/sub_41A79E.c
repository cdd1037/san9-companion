// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A79E; original name: ?IsIdleMessage@CWinThread@@UAEHPAUtagMSG@@@Z
// attributes: thunk
int __thiscall CWinThread::IsIdleMessage(CWinThread *this, struct tagMSG *a2)
{
  return __imp_?IsIdleMessage@CWinThread@@UAEHPAUtagMSG@@@Z(this, a2);
}
