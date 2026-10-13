// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405130; original name: sub_405130
int __thiscall sub_405130(CWnd *this)
{
  unsigned int v2; // eax
  int v3; // eax
  int v4; // edx
  _WORD *v5; // ecx
  unsigned int v6; // ebx
  HWND *DlgItem; // edi
  _DWORD *v8; // eax
  int v10; // [esp+4h] [ebp-4h]

  v2 = *((_DWORD *)this + 86);
  if ( v2 < *((_DWORD *)this + 87) )
  {
    CString::Format((CWnd *)((char *)this + 224), "%s", (const char *)this + 10 * v2 + 352);
    CString::operator=((char *)this + 332, 8 * *((char *)this + *((_DWORD *)this + 86) + 8352) + 4323112);
    *((_BYTE *)this + 264) = *((_BYTE *)this + *((_DWORD *)this + 86) + 9152);
    v3 = *((_DWORD *)this + 86);
    *((_BYTE *)this + 266) = *((_BYTE *)this + v3 + 9952);
    *((_BYTE *)this + 265) = *((_BYTE *)this + v3 + 10752);
    *((_BYTE *)this + 267) = *((_BYTE *)this + v3 + 11552);
    *((_DWORD *)this + 67) = *((_BYTE *)this + 2 * v3 + 12352) & 1;
    LOBYTE(v4) = *((_BYTE *)this + 2 * v3 + 12352);
    *((_DWORD *)this + 73) = (v4 >> 1) & 1;
    *((_DWORD *)this + 70) = ((int)*((unsigned __int8 *)this + 2 * v3 + 12352) >> 2) & 1;
    *((_DWORD *)this + 72) = ((int)*((unsigned __int8 *)this + 2 * v3 + 12352) >> 3) & 1;
    *((_DWORD *)this + 74) = ((int)*((unsigned __int8 *)this + 2 * v3 + 12352) >> 4) & 1;
    *((_DWORD *)this + 69) = ((int)*((unsigned __int8 *)this + 2 * v3 + 12352) >> 5) & 1;
    *((_DWORD *)this + 75) = ((int)*((unsigned __int8 *)this + 2 * v3 + 12352) >> 6) & 1;
    *((_DWORD *)this + 71) = (int)*((unsigned __int8 *)this + 2 * v3 + 12352) >> 7;
    *((_DWORD *)this + 68) = ((int)*((unsigned __int16 *)this + v3 + 6176) >> 8) & 1;
    v5 = (_WORD *)((char *)this + 18 * v3);
    *((_WORD *)this + 152) = v5[6976];
    *((_WORD *)this + 158) = v5[6977];
    *((_WORD *)this + 155) = v5[6978];
    *((_WORD *)this + 157) = v5[6979];
    *((_WORD *)this + 159) = v5[6980];
    *((_WORD *)this + 154) = v5[6981];
    *((_WORD *)this + 160) = v5[6982];
    *((_WORD *)this + 156) = v5[6983];
    *((_WORD *)this + 153) = *((_WORD *)this + 9 * v3 + 6984);
    v6 = 1056;
    v10 = 1;
    do
    {
      if ( v6 == 1059 || v6 == 1063 || v6 == 1067 || v6 == 1071 || v6 == 1075 )
        ++v6;
      DlgItem = (HWND *)CWnd::GetDlgItem(this, v6);
      if ( (*((_DWORD *)this + *((_DWORD *)this + 86) + 7088) & v10) != 0 )
      {
        if ( (((unsigned __int16)CWnd::GetStyle((CWnd *)DlgItem) >> 8) & 0x80u) == 0 )
        {
          CWnd::ModifyStyle((CWnd *)DlgItem, 0, 0x8000u, 0);
          RedrawWindow(DlgItem[8], nullptr, nullptr, 0x105u);
        }
      }
      else if ( (((unsigned __int16)CWnd::GetStyle((CWnd *)DlgItem) >> 8) & 0x80u) != 0 )
      {
        CWnd::ModifyStyle((CWnd *)DlgItem, 0x8000u, 0, 0);
        RedrawWindow(DlgItem[8], nullptr, nullptr, 0x105u);
      }
      ++v6;
      v10 *= 2;
    }
    while ( v6 <= 0x443 );
    SendMessageA(*((HWND *)this + 32), 0x186u, *((_DWORD *)this + 86), 0);
  }
  v8 = (_DWORD *)(*((_DWORD *)this + 85) + 4 * *((_DWORD *)this + 86));
  *((_DWORD *)this + 57) = *v8 & 3;
  *((_DWORD *)this + 58) = (*v8 >> 2) & 3;
  *((_DWORD *)this + 59) = (*v8 >> 4) & 3;
  *((_DWORD *)this + 60) = (*v8 >> 6) & 3;
  *((_DWORD *)this + 65) = (*v8 >> 8) & 3;
  *((_DWORD *)this + 61) = (*v8 >> 10) & 3;
  *((_DWORD *)this + 62) = (*v8 >> 12) & 3;
  *((_DWORD *)this + 63) = (unsigned __int8)HIBYTE(*(_WORD *)v8) >> 6;
  *((_DWORD *)this + 64) = HIWORD(*v8) & 3;
  return CWnd::UpdateData(this, 0);
}
