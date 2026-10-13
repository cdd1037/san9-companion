// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401A40; original name: sub_401A40
CListBox *__thiscall sub_401A40(CListBox *this, char a2)
{
  CListBox::~CListBox(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
