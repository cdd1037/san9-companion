// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A642; original name: ?GetRuntimeClass@CObject@@UBEPAUCRuntimeClass@@XZ
// attributes: thunk
struct CRuntimeClass *__thiscall CObject::GetRuntimeClass(CObject *this)
{
  return __imp_?GetRuntimeClass@CObject@@UBEPAUCRuntimeClass@@XZ(this);
}
