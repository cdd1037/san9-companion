// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004026F0; original name: sub_4026F0
void __thiscall sub_4026F0(CDialog *this)
{
  CListBox::~CListBox((CDialog *)((char *)this + 96));
  CDialog::~CDialog(this);
}
