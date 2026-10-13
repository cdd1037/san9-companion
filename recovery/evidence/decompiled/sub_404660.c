// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00404660; original name: sub_404660
int __thiscall sub_404660(CGdiObject *this)
{
  int result; // eax

  *(_DWORD *)this = &off_41C9AC;
  result = CGdiObject::DeleteObject(this);
  *(_DWORD *)this = &off_41C570;
  return result;
}
