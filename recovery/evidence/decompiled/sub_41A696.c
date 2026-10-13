// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A696; original name: ?GetRuntimeClass@CMenu@@UBEPAUCRuntimeClass@@XZ
// attributes: thunk
struct CRuntimeClass *__thiscall CMenu::GetRuntimeClass(CMenu *this)
{
  return __imp_?GetRuntimeClass@CMenu@@UBEPAUCRuntimeClass@@XZ(this);
}
