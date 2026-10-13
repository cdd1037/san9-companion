// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00404570; original name: sub_404570
void sub_404570()
{
  _DWORD v0[24]; // [esp+0h] [ebp-DCh] BYREF
  _BYTE v1[112]; // [esp+60h] [ebp-7Ch] BYREF
  int v2; // [esp+D8h] [ebp-4h]

  sub_401000(v0, nullptr);
  v2 = 0;
  CDialog::DoModal((CDialog *)v0);
  v2 = 1;
  CListBox::~CListBox((CListBox *)v1);
  v2 = -1;
  CDialog::~CDialog((CDialog *)v0);
}
