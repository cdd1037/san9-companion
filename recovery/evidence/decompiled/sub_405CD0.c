// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405CD0; original name: sub_405CD0
CGdiObject *__thiscall sub_405CD0(CGdiObject *this, char a2)
{
  sub_404660(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
