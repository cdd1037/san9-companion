// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405C10; original name: sub_405C10
int __thiscall sub_405C10(int this)
{
  return CString::operator=((void *)(this + 31560), (int)&Str2);
}
