// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A6C0; original name: ?GetRuntimeClass@CGdiObject@@UBEPAUCRuntimeClass@@XZ
// attributes: thunk
struct CRuntimeClass *__thiscall CGdiObject::GetRuntimeClass(CGdiObject *this)
{
  return __imp_?GetRuntimeClass@CGdiObject@@UBEPAUCRuntimeClass@@XZ(this);
}
