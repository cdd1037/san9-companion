// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004057A0; original name: sub_4057A0
void __thiscall sub_4057A0(CDialog *this)
{
  if ( sub_4050B0(this) != 0 && sub_405480((int)this) != 0 )
  {
    **((_WORD **)this + 7893) = *((_WORD *)this + 168);
    CDialog::OnOK(this);
  }
}
