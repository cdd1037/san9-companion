// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004019D0; original name: sub_4019D0
void __thiscall sub_4019D0(_DWORD *this)
{
  *this = &off_41C584;
  CString::~CString((CString *)(this + 4));
  *this = &off_41C570;
}
