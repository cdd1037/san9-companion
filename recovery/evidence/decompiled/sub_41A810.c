// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A810; original name: ??0CString@@QAE@PBD@Z
// attributes: thunk
CString *__thiscall CString::CString(CString *this, const char *a2)
{
  return __imp_??0CString@@QAE@PBD@Z(this, a2);
}
