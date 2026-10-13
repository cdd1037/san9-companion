// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00403760; original name: sub_403760
void __thiscall sub_403760(CDialog *this)
{
  if ( (unsigned __int8)sub_403FF0(this) != 0 )
    CDialog::EndDialog(this, 1);
}
