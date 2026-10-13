// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A5BE; original name: ?IsInvokeAllowed@CCmdTarget@@UAEHJ@Z
// attributes: thunk
int __thiscall CCmdTarget::IsInvokeAllowed(CCmdTarget *this, int a2)
{
  return __imp_?IsInvokeAllowed@CCmdTarget@@UAEHJ@Z(this, a2);
}
