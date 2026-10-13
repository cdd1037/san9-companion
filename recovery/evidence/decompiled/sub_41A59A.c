// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A59A; original name: ?GetDispatchMap@CCmdTarget@@MBEPBUAFX_DISPMAP@@XZ
// attributes: thunk
const struct AFX_DISPMAP *__thiscall CCmdTarget::GetDispatchMap(CCmdTarget *this)
{
  return __imp_?GetDispatchMap@CCmdTarget@@MBEPBUAFX_DISPMAP@@XZ(this);
}
