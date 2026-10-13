// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00402650; original name: sub_402650
_DWORD *__thiscall sub_402650(_DWORD *this, struct CWnd *a2)
{
  CDialog::CDialog((CDialog *)this, 0x86u, a2);
  CWnd::CWnd((CWnd *)(this + 24));
  *(this + 24) = &off_41C498;
  *this = &off_41C730;
  *(this + 40) = 9;
  *(this + 41) = 100;
  *(this + 42) = 10;
  return this;
}
