// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401000; original name: sub_401000
_DWORD *__thiscall sub_401000(_DWORD *this, struct CWnd *a2)
{
  CDialog::CDialog((CDialog *)this, 0x87u, a2);
  CWnd::CWnd((CWnd *)(this + 24));
  *(this + 24) = &off_41C498;
  *(this + 41) = 10;
  *(this + 43) = 10;
  *(this + 44) = 10;
  *(this + 45) = 10;
  *(this + 46) = 10;
  *this = &off_41C3C0;
  *(this + 47) = 1;
  *(this + 48) = 1;
  *(this + 40) = 2;
  *(this + 42) = 0;
  return this;
}
