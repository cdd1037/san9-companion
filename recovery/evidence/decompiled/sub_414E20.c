// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00414E20; original name: sub_414E20
CEdit *__thiscall sub_414E20(CEdit *this, char a2)
{
  CEdit::~CEdit(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
