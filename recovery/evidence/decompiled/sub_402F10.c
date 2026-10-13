// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00402F10; original name: sub_402F10
void __thiscall sub_402F10(CDialog *this)
{
  _DWORD *v2; // esi

  v2 = (_DWORD *)((char *)this + 448);
  *((_DWORD *)this + 112) = &off_41C990;
  CMenu::DestroyMenu((CDialog *)((char *)this + 448));
  *v2 = &off_41C570;
  CDialog::~CDialog(this);
}
