// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004046D0; original name: sub_4046D0
int __thiscall sub_4046D0(CMenu *this)
{
  int result; // eax

  *(_DWORD *)this = &off_41C990;
  result = CMenu::DestroyMenu(this);
  *(_DWORD *)this = &off_41C570;
  return result;
}
