// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A5B8; original name: ?GetDispatchIID@CCmdTarget@@UAEHPAU_GUID@@@Z
// attributes: thunk
int __thiscall CCmdTarget::GetDispatchIID(CCmdTarget *this, struct _GUID *a2)
{
  return __imp_?GetDispatchIID@CCmdTarget@@UAEHPAU_GUID@@@Z(this, a2);
}
