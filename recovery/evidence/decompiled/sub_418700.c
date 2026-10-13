// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00418700; original name: sub_418700
void __thiscall sub_418700(CDialog *this)
{
  ((void (*)(void))sub_414E40)();
  if ( *((_DWORD *)this + 26) != 0 )
    KillTimer(*((HWND *)this + 8), *((_DWORD *)this + 26));
  CDialog::OnCancel(this);
}
