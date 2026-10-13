// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401B70; original name: sub_401B70
void __thiscall sub_401B70(CDialog *this)
{
  CListBox::~CListBox((CDialog *)((char *)this + 96));
  CDialog::~CDialog(this);
}
