// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401A30; original name: sub_401A30
BOOL __thiscall sub_401A30(HWND *this)
{
  return EnableWindow(*(this + 8), true);
}
