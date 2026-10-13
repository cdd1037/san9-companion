// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00404080; original name: sub_404080
void sub_404080()
{
  _BYTE v0[96]; // [esp+4h] [ebp-7B64h] BYREF
  _BYTE v1[64]; // [esp+64h] [ebp-7B04h] BYREF
  _BYTE v2[64]; // [esp+A4h] [ebp-7AC4h] BYREF
  _BYTE v3[108]; // [esp+E4h] [ebp-7A84h] BYREF
  _BYTE v4[31220]; // [esp+150h] [ebp-7A18h] BYREF
  struct CRuntimeClass *(__thiscall **v5)(CObject *__hidden); // [esp+7B44h] [ebp-24h] BYREF
  _BYTE v6[16]; // [esp+7B4Ch] [ebp-1Ch] BYREF
  int v7; // [esp+7B64h] [ebp-4h]

  sub_404720(nullptr);
  v7 = 0;
  CDialog::DoModal((CDialog *)v0);
  v7 = 6;
  CString::~CString((CString *)v6);
  v5 = &off_41C9AC;
  LOBYTE(v7) = 7;
  CGdiObject::DeleteObject((CGdiObject *)&v5);
  v5 = &off_41C570;
  LOBYTE(v7) = 4;
  CString::~CString((CString *)v4);
  LOBYTE(v7) = 3;
  CString::~CString((CString *)v3);
  LOBYTE(v7) = 2;
  CScrollBar::~CScrollBar((CScrollBar *)v2);
  LOBYTE(v7) = 1;
  CListBox::~CListBox((CListBox *)v1);
  v7 = -1;
  CDialog::~CDialog((CDialog *)v0);
}
