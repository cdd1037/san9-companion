// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004026D0; original name: sub_4026D0
CDialog *__thiscall sub_4026D0(CDialog *this, char a2)
{
  sub_4026F0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
