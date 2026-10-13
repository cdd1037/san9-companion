// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A7F8; original name: ??0CPaintDC@@QAE@PAVCWnd@@@Z
// attributes: thunk
CPaintDC *__thiscall CPaintDC::CPaintDC(CPaintDC *this, struct CWnd *a2)
{
  return __imp_??0CPaintDC@@QAE@PAVCWnd@@@Z(this, a2);
}
