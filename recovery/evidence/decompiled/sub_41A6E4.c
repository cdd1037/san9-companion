// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A6E4; original name: ?GetRuntimeClass@CFont@@UBEPAUCRuntimeClass@@XZ
// attributes: thunk
struct CRuntimeClass *__thiscall CFont::GetRuntimeClass(CFont *this)
{
  return __imp_?GetRuntimeClass@CFont@@UBEPAUCRuntimeClass@@XZ(this);
}
