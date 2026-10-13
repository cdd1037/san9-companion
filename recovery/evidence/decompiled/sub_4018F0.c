// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004018F0; original name: sub_4018F0
void __thiscall sub_4018F0(CDialog *this)
{
  CString::~CString((CDialog *)((char *)this + 176));
  CDialog::~CDialog(this);
}
