// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004019B0; original name: sub_4019B0
void *__thiscall sub_4019B0(void *this, char a2)
{
  sub_4019D0();
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
