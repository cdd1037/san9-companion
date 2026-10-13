// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004044F0; original name: sub_4044F0
void sub_4044F0()
{
  _DWORD v0[24]; // [esp+0h] [ebp-C4h] BYREF
  _BYTE v1[88]; // [esp+60h] [ebp-64h] BYREF
  int v2; // [esp+C0h] [ebp-4h]

  sub_402650(v0, nullptr);
  v2 = 0;
  CDialog::DoModal((CDialog *)v0);
  v2 = 1;
  CListBox::~CListBox((CListBox *)v1);
  v2 = -1;
  CDialog::~CDialog((CDialog *)v0);
}
