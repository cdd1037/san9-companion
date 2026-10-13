// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A6EA; original name: ??4CString@@QAEABV0@PBD@Z
// attributes: thunk
int __thiscall CString::operator=(void *this, int a2)
{
  return __imp_??4CString@@QAEABV0@PBD@Z(this, a2);
}
