// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A5A0; original name: ?GetCommandMap@CCmdTarget@@MBEPBUAFX_OLECMDMAP@@XZ
// attributes: thunk
const struct AFX_OLECMDMAP *__thiscall CCmdTarget::GetCommandMap(CCmdTarget *this)
{
  return __imp_?GetCommandMap@CCmdTarget@@MBEPBUAFX_OLECMDMAP@@XZ(this);
}
