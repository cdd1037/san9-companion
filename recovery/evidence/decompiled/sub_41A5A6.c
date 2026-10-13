// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A5A6; original name: ?GetTypeLib@CCmdTarget@@UAEJKPAPAUITypeLib@@@Z
// attributes: thunk
int __thiscall CCmdTarget::GetTypeLib(CCmdTarget *this, unsigned int a2, struct ITypeLib **a3)
{
  return __imp_?GetTypeLib@CCmdTarget@@UAEJKPAPAUITypeLib@@@Z(this, a2, a3);
}
