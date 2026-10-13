// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A57C; original name: ?GetInterfaceHook@CCmdTarget@@UAEPAUIUnknown@@PBX@Z
// attributes: thunk
struct IUnknown *__thiscall CCmdTarget::GetInterfaceHook(CCmdTarget *this, const void *a2)
{
  return __imp_?GetInterfaceHook@CCmdTarget@@UAEPAUIUnknown@@PBX@Z(this, a2);
}
