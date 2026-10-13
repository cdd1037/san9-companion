// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401A70; original name: sub_401A70
_DWORD *__thiscall sub_401A70(_DWORD *this, struct CWnd *a2)
{
  CDialog::CDialog((CDialog *)this, 0x85u, a2);
  CWnd::CWnd((CWnd *)(this + 24));
  *(this + 24) = &off_41C498;
  *(this + 44) = 7;
  *(this + 45) = 7;
  *(this + 46) = 7;
  *this = &off_41C608;
  *(this + 48) = 50;
  *(this + 50) = 50;
  *(this + 51) = 50;
  *(this + 52) = 50;
  *(this + 53) = 50;
  *(this + 54) = 50;
  *(this + 55) = 50;
  *(this + 56) = 50;
  *(this + 57) = 50;
  *(this + 58) = 50;
  *(this + 40) = 0;
  *(this + 41) = 0;
  *(this + 42) = 0;
  *(this + 43) = 0;
  *(this + 47) = 10;
  *(this + 49) = 0;
  return this;
}
