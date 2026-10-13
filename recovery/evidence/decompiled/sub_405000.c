// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405000; original name: sub_405000
void __thiscall sub_405000(CWnd *this, unsigned int a2, unsigned int a3, struct CScrollBar *a4)
{
  int v5; // edi
  int v6; // edi
  CWnd *DlgItem; // eax

  if ( a4 == (CWnd *)((char *)this + 160) )
  {
    v5 = *((_DWORD *)this + 82);
    switch ( a2 )
    {
      case 0u:
      case 2u:
        v6 = v5 - 1;
        if ( v6 < 0 )
          v6 = 0;
        goto LABEL_8;
      case 1u:
      case 3u:
        v6 = v5 + 1;
        if ( v6 > 115 )
          v6 = 115;
        goto LABEL_8;
      case 5u:
        v6 = a3;
LABEL_8:
        if ( sub_405480(this) != 0 )
        {
          *((_DWORD *)this + 82) = v6;
          SetScrollPos(*((HWND *)this + 48), 2, v6, true);
          DlgItem = CWnd::GetDlgItem(this, 1118);
          CWnd::SetFocus(DlgItem);
          sub_4054F0(this);
        }
        break;
      default:
        break;
    }
  }
  CWnd::OnHScroll(this, a2, a3, a4);
}
