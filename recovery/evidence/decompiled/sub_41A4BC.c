// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A4BC; original name: ?GetMessageMap@CWnd@@MBEPBUAFX_MSGMAP@@XZ
// attributes: thunk
const struct AFX_MSGMAP *__thiscall CWnd::GetMessageMap(CWnd *this)
{
  return __imp_?GetMessageMap@CWnd@@MBEPBUAFX_MSGMAP@@XZ(this);
}
