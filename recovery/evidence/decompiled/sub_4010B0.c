// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004010B0; original name: sub_4010B0
CDialog *__thiscall sub_4010B0(CDialog *this, char a2)
{
  sub_4010D0(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
