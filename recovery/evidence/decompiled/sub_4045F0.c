// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004045F0; original name: sub_4045F0
void *__thiscall sub_4045F0(void *this, char a2)
{
  sub_404610();
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
