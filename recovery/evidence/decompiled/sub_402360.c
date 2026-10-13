// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00402360; original name: sub_402360
void __thiscall sub_402360(CDialog *this)
{
  if ( sub_4021C0((int)this) != 0 )
  {
    *(_DWORD *)(*((_DWORD *)this + 60) + 4412) = *((_DWORD *)this + 49);
    CDialog::OnOK(this);
  }
}
