// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00402C60; original name: sub_402C60
void __thiscall sub_402C60(CDialog *this)
{
  if ( sub_402BB0((int)this) != 0 )
    CDialog::OnOK(this);
}
