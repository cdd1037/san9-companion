// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A7AA; original name: ?PumpMessage@CWinThread@@UAEHXZ
// attributes: thunk
int __thiscall CWinThread::PumpMessage(CWinThread *this)
{
  return __imp_?PumpMessage@CWinThread@@UAEHXZ(this);
}
