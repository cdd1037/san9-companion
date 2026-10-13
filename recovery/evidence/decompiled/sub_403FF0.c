// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00403FF0; original name: sub_403FF0
char __thiscall sub_403FF0(CWnd *this)
{
  unsigned int v3; // eax
  CWnd *DlgItem; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax

  if ( CWnd::UpdateData(this, 1) == 0 )
    return 0;
  v3 = *((_DWORD *)this + 31);
  if ( *((_DWORD *)this + 30) > v3 )
  {
    DlgItem = CWnd::GetDlgItem(this, 1020);
LABEL_15:
    CWnd::SetFocus(DlgItem);
    AfxMessageBox(&byte_41F70C, 0, 0);
    return 0;
  }
  if ( v3 > *((_DWORD *)this + 32) )
  {
    DlgItem = CWnd::GetDlgItem(this, 1021);
    goto LABEL_15;
  }
  v5 = *((_DWORD *)this + 28);
  if ( *((_DWORD *)this + 27) > v5 )
  {
    DlgItem = CWnd::GetDlgItem(this, 1023);
    goto LABEL_15;
  }
  if ( v5 > *((_DWORD *)this + 29) )
  {
    DlgItem = CWnd::GetDlgItem(this, 1024);
    goto LABEL_15;
  }
  v6 = *((_DWORD *)this + 24);
  if ( *((_DWORD *)this + 25) > v6 )
  {
    DlgItem = CWnd::GetDlgItem(this, 1026);
    goto LABEL_15;
  }
  if ( v6 > *((_DWORD *)this + 26) )
  {
    DlgItem = CWnd::GetDlgItem(this, 1027);
    goto LABEL_15;
  }
  return 1;
}
