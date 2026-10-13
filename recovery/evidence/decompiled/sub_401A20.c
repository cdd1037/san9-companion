// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401A20; original name: sub_401A20
BOOL __thiscall sub_401A20(HWND *this)
{
  return EnableWindow(*(this + 8), false);
}
