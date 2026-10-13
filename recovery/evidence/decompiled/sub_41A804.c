// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A804; original name: ??YCString@@QAEABV0@PBD@Z
// attributes: thunk
int __thiscall CString::operator+=(void *this, int a2)
{
  return __imp_??YCString@@QAEABV0@PBD@Z(this, a2);
}
