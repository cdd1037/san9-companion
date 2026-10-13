// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405E80; original name: sub_405E80
void __thiscall sub_405E80(CDialog *this)
{
  CEdit::~CEdit((CDialog *)((char *)this + 7624));
  CDialog::~CDialog(this);
}
