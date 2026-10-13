// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00402EF0; original name: sub_402EF0
CDialog *__thiscall sub_402EF0(CDialog *this, char a2)
{
  sub_402F10(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
