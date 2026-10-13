// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A58E; original name: ?GetInterfaceMap@CCmdTarget@@MBEPBUAFX_INTERFACEMAP@@XZ
// attributes: thunk
const struct AFX_INTERFACEMAP *__thiscall CCmdTarget::GetInterfaceMap(CCmdTarget *this)
{
  return __imp_?GetInterfaceMap@CCmdTarget@@MBEPBUAFX_INTERFACEMAP@@XZ(this);
}
