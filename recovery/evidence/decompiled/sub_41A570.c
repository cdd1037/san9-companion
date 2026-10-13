// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A570; original name: ?GetConnectionHook@CCmdTarget@@MAEPAUIConnectionPoint@@ABU_GUID@@@Z
// attributes: thunk
struct IConnectionPoint *__thiscall CCmdTarget::GetConnectionHook(CCmdTarget *this, const struct _GUID *a2)
{
  return __imp_?GetConnectionHook@CCmdTarget@@MAEPAUIConnectionPoint@@ABU_GUID@@@Z(this, a2);
}
