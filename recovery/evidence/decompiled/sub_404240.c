// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00404240; original name: sub_404240
void sub_404240()
{
  _DWORD v0[24]; // [esp+0h] [ebp-104h] BYREF
  _BYTE v1[152]; // [esp+60h] [ebp-A4h] BYREF
  int v2; // [esp+100h] [ebp-4h]

  sub_401A70(v0, nullptr);
  v2 = 0;
  CDialog::DoModal((CDialog *)v0);
  v2 = 1;
  CListBox::~CListBox((CListBox *)v1);
  v2 = -1;
  CDialog::~CDialog((CDialog *)v0);
}
