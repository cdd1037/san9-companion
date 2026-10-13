// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00404180; original name: sub_404180
void __thiscall sub_404180(CDialog *this)
{
  CString::~CString((CDialog *)((char *)this + 31560));
  *((_DWORD *)this + 7888) = &off_41C9AC;
  CGdiObject::DeleteObject((CDialog *)((char *)this + 31552));
  *((_DWORD *)this + 7888) = &off_41C570;
  CString::~CString((CDialog *)((char *)this + 332));
  CString::~CString((CDialog *)((char *)this + 224));
  CScrollBar::~CScrollBar((CDialog *)((char *)this + 160));
  CListBox::~CListBox((CDialog *)((char *)this + 96));
  CDialog::~CDialog(this);
}
