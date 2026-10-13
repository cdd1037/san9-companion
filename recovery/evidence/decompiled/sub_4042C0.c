// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004042C0; original name: sub_4042C0
int __thiscall sub_4042C0(int this)
{
  CMenu *v2; // esi
  int result; // eax
  HMENU PopupMenu; // eax
  unsigned int v5; // esi
  _BYTE *v6; // edx
  _BYTE *v7; // ecx
  int v8; // ebp
  _BYTE *v9; // ebx
  const void *v10; // eax
  struct CWnd *DlgItem; // eax
  _BYTE v12[16]; // [esp+0h] [ebp-2AC8h] BYREF
  _BYTE *v13; // [esp+10h] [ebp-2AB8h]
  _BYTE *v14; // [esp+14h] [ebp-2AB4h]
  CMenu *v15; // [esp+18h] [ebp-2AB0h]
  CHAR NewItem[12]; // [esp+1Ch] [ebp-2AACh] BYREF
  struct tagRECT Rect; // [esp+28h] [ebp-2AA0h] BYREF
  _BYTE v18[16]; // [esp+38h] [ebp-2A90h] BYREF
  char v19[5]; // [esp+48h] [ebp-2A80h] BYREF
  char v20[275]; // [esp+4Dh] [ebp-2A7Bh] BYREF
  _BYTE Buffer[52]; // [esp+160h] [ebp-2968h] BYREF

  v2 = (CMenu *)(this + 448);
  v15 = (CMenu *)(this + 448);
  CMenu::DestroyMenu((CMenu *)(this + 448));
  result = *(_DWORD *)(this + 456);
  if ( *(_DWORD *)(result + 112) != 0 )
  {
    PopupMenu = CreatePopupMenu();
    result = CMenu::Attach(v2, PopupMenu);
    if ( result != 0 )
    {
      result = ReadProcessMemory(
                 *(HANDLE *)(*(_DWORD *)(this + 456) + 112),
                 (LPCVOID)0x1253C38,
                 Buffer,
                 0x2968u,
                 nullptr);
      if ( result != 0 )
      {
        v5 = 19217464;
        v6 = &v12[-19216928];
        v7 = &v12[-19216924];
        v8 = 0;
        v13 = v6;
        v14 = v7;
        v9 = &v12[-19217060];
        do
        {
          if ( (v9[v5] & 4) == 0 && *(_DWORD *)&v6[v5] == v5 )
          {
            v10 = *(const void **)&v7[v5];
            if ( v10 != nullptr )
            {
              result = ReadProcessMemory(*(HANDLE *)(*(_DWORD *)(this + 456) + 112), v10, v18, 0x128u, nullptr);
              if ( result == 0 )
                return result;
              sprintf(NewItem, "%s%s", v19, v20);
              sub_41A110(NewItem);
              result = AppendMenuA(*(HMENU *)(this + 452), 8 * (v9[v5] & 1), v8 + 32771, NewItem);
              if ( result == 0 )
                return result;
              v7 = v14;
              v6 = v13;
            }
          }
          v5 += 212;
          ++v8;
        }
        while ( v5 < 0x12565A0 );
        DlgItem = CWnd::GetDlgItem((CWnd *)this, 1010);
        GetWindowRect(*((HWND *)DlgItem + 8), &Rect);
        return CMenu::TrackPopupMenu(v15, 0, Rect.left, Rect.top, (struct CWnd *)this, nullptr);
      }
    }
  }
  return result;
}
