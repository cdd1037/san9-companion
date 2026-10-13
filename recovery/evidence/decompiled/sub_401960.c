// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401960; original name: ??_Gfacet@locale@std@@UAEPAXI@Z
std::locale::facet *__thiscall std::locale::facet::`scalar deleting destructor'(std::locale::facet *this, char a2)
{
  *(_DWORD *)this = &off_41C570;
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
