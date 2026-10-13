// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A830; original name: sub_41A830
type_info *__thiscall sub_41A830(type_info *this, char a2)
{
  type_info::~type_info(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
