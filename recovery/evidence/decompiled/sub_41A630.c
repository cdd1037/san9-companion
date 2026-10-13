// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A630; original name: ?ReportError@CException@@UAEHII@Z
// attributes: thunk
int __thiscall CException::ReportError(CException *this, unsigned int a2, unsigned int a3)
{
  return __imp_?ReportError@CException@@UAEHII@Z(this, a2, a3);
}
