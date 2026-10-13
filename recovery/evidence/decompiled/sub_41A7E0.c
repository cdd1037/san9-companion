// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A7E0; original name: ?GetRuntimeClass@CEdit@@UBEPAUCRuntimeClass@@XZ
// attributes: thunk
struct CRuntimeClass *__thiscall CEdit::GetRuntimeClass(CEdit *this)
{
  return __imp_?GetRuntimeClass@CEdit@@UBEPAUCRuntimeClass@@XZ(this);
}
