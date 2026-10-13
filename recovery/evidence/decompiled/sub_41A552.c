// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A552; original name: ?CalcWindowRect@CWnd@@UAEXPAUtagRECT@@I@Z
// attributes: thunk
void __thiscall CWnd::CalcWindowRect(CWnd *this, struct tagRECT *a2, unsigned int a3)
{
  __imp_?CalcWindowRect@CWnd@@UAEXPAUtagRECT@@I@Z(this, a2, a3);
}
