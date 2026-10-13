// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004048F0; original name: sub_4048F0
CDialog *__thiscall sub_4048F0(CDialog *this, char a2)
{
  sub_404180(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
