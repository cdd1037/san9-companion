// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004046B0; original name: sub_4046B0
void *__thiscall sub_4046B0(void *this, char a2)
{
  sub_4046D0();
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
