// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401B50; original name: sub_401B50
CDialog *__thiscall sub_401B50(CDialog *this, char a2)
{
  sub_401B70(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
