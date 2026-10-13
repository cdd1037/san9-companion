// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405CF0; original name: sub_405CF0
CScrollBar *__thiscall sub_405CF0(CScrollBar *this, char a2)
{
  CScrollBar::~CScrollBar(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
