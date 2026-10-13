// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A78C; original name: ?ProcessMessageFilter@CWinThread@@UAEHHPAUtagMSG@@@Z
// attributes: thunk
int __thiscall CWinThread::ProcessMessageFilter(CWinThread *this, int a2, struct tagMSG *a3)
{
  return __imp_?ProcessMessageFilter@CWinThread@@UAEHHPAUtagMSG@@@Z(this, a2, a3);
}
