// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004093E0; original name: sub_4093E0
CDialog *__thiscall sub_4093E0(CDialog *this, char a2)
{
  sub_405E80(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
