// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004010D0; original name: sub_4010D0
void __thiscall sub_4010D0(CDialog *this)
{
  CListBox::~CListBox((CDialog *)((char *)this + 96));
  CDialog::~CDialog(this);
}
