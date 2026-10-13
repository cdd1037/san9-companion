// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A5D0; original name: ?GetRuntimeClass@CDialog@@UBEPAUCRuntimeClass@@XZ
// attributes: thunk
struct CRuntimeClass *__thiscall CDialog::GetRuntimeClass(CDialog *this)
{
  return __imp_?GetRuntimeClass@CDialog@@UBEPAUCRuntimeClass@@XZ(this);
}
