// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A738; original name: ?Find@CString@@QBEHPBD@Z
// attributes: thunk
int __thiscall CString::Find(CString *this, const char *a2)
{
  return __imp_?Find@CString@@QBEHPBD@Z(this, a2);
}
