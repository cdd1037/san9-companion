// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A786; original name: ?GetMainWnd@CWinThread@@UAEPAVCWnd@@XZ
// attributes: thunk
struct CWnd *__thiscall CWinThread::GetMainWnd(CWinThread *this)
{
  return __imp_?GetMainWnd@CWinThread@@UAEPAVCWnd@@XZ(this);
}
