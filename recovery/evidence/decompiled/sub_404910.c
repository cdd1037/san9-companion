// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00404910; original name: sub_404910
int __thiscall sub_404910(int this)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  void *v2; // esp
  int v4; // ebx
  struct AFX_MODULE_STATE *ModuleState; // eax
  int v6; // esi
  void *v7; // eax
  _WORD *v8; // ebp
  char *v9; // esi
  unsigned __int8 v10; // al
  char v11; // cl
  char v12; // dl
  char v13; // al
  __int16 v14; // cx
  _WORD *v15; // edx
  __int16 v16; // ax
  __int16 v17; // cx
  __int16 v18; // ax
  __int16 v19; // cx
  __int16 v20; // ax
  __int16 v21; // cx
  int v22; // eax
  _DWORD *v23; // ecx
  LRESULT v24; // eax
  struct CWnd *DlgItem; // eax
  void *v26; // eax
  struct CGdiObject *v27; // eax
  HFONT v28; // eax
  struct CWnd *v29; // eax
  WPARAM v30; // esi
  char *lpMultiByteStr; // [esp+0h] [ebp-39D5Ch]
  LPARAM lParam; // [esp+4h] [ebp-39D58h] BYREF
  _DWORD *v34; // [esp+8h] [ebp-39D54h]
  _WORD *v35; // [esp+Ch] [ebp-39D50h]
  int v36; // [esp+10h] [ebp-39D4Ch]
  LOGFONTA pv; // [esp+14h] [ebp-39D48h] BYREF
  _BYTE Buffer[178]; // [esp+50h] [ebp-39D0Ch] BYREF
  char v39; // [esp+102h] [ebp-39C5Ah] BYREF
  struct _EXCEPTION_REGISTRATION_RECORD *v40; // [esp+39D50h] [ebp-Ch]
  void *v41; // [esp+39D54h] [ebp-8h]
  int v42; // [esp+39D58h] [ebp-4h]

  v42 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v41 = &loc_41B05B;
  v40 = ExceptionList;
  v2 = alloca(236880);
  CDialog::OnInitDialog((CDialog *)this);
  CString::CString((CString *)&lParam);
  v4 = 0;
  v42 = 0;
  ModuleState = AfxGetModuleState();
  v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)ModuleState + 1) + 124))(*((_DWORD *)ModuleState + 1));
  *(_DWORD *)(this + 348) = 0;
  v36 = v6;
  *(_DWORD *)(this + 340) = v6 + 500;
  v7 = *(void **)(v6 + 112);
  if ( v7 != nullptr )
  {
    if ( ReadProcessMemory(v7, (LPCVOID)0x1258EE0, Buffer, 0x39D00u, nullptr) )
    {
      lpMultiByteStr = (char *)(this + 352);
      v34 = (_DWORD *)(this + 28352);
      v8 = (_WORD *)(this + 13954);
      v35 = (_WORD *)(this + 12352);
      v9 = &v39;
      while ( 1 )
      {
        sprintf(lpMultiByteStr, "%s%s", v9 - 162, v9 - 157);
        sub_41A110(lpMultiByteStr);
        v10 = *(v9 - 46);
        *(_BYTE *)(this + v4 + 8352) = v10;
        if ( v10 > 0xAu )
          *(_BYTE *)(this + v4 + 8352) = 10;
        v11 = *(v9 - 102);
        v12 = *(v9 - 94);
        *(_BYTE *)(this + v4 + 9152) = *(v9 - 78);
        v13 = *(v9 - 86);
        *(_BYTE *)(this + v4 + 9952) = v11;
        v14 = *((_WORD *)v9 + 27);
        *(_BYTE *)(this + v4 + 10752) = v12;
        v15 = v35;
        *(_BYTE *)(this + v4 + 11552) = v13;
        v16 = *((_WORD *)v9 - 7);
        *v15 = v14 >> 3;
        v17 = *((_WORD *)v9 - 6);
        LOWORD(v15) = *((_WORD *)v9 - 5);
        *(v8 - 1) = v16;
        v18 = *((_WORD *)v9 - 4);
        *v8 = v17;
        v19 = *((_WORD *)v9 - 3);
        v8[1] = (_WORD)v15;
        LOWORD(v15) = *((_WORD *)v9 - 2);
        v8[2] = v18;
        v20 = *((_WORD *)v9 - 1);
        v8[3] = v19;
        v21 = *(_WORD *)v9;
        v8[4] = (_WORD)v15;
        LOWORD(v15) = *((_WORD *)v9 + 1);
        v8[5] = v20;
        v22 = *(_DWORD *)(v9 + 78);
        v8[6] = v21;
        v23 = v34;
        v8[7] = (_WORD)v15;
        *v23 = v22;
        CString::Format((CString *)&lParam, "%03d %s", v4, lpMultiByteStr);
        v24 = SendMessageA(*(HWND *)(this + 128), 0x181u, 0xFFFFFFFF, lParam);
        if ( v24 == -1 || v24 == -2 )
          break;
        ++v4;
        ++v34;
        v8 += 9;
        v9 += 296;
        ++v35;
        lpMultiByteStr += 10;
        if ( v4 >= 800 )
          goto LABEL_12;
      }
      AfxMessageBox(&byte_41F780, 0, 0);
LABEL_12:
      v6 = v36;
      *(_DWORD *)(this + 348) = v4;
    }
    else
    {
      AfxMessageBox(&byte_41F798, 0, 0);
    }
  }
  *(_DWORD *)(this + 344) = 0;
  sub_405130((CWnd *)this);
  *(_DWORD *)(this + 31572) = v6 + 4408;
  *(_DWORD *)(this + 336) = *(unsigned __int16 *)(v6 + 4408);
  *(_DWORD *)(this + 31568) = v6 + 3704;
  SetScrollRange(*(HWND *)(this + 192), 2, 0, 115, true);
  SetScrollPos(*(HWND *)(this + 192), 2, *(_DWORD *)(this + 328), true);
  sub_4054F0(this);
  DlgItem = CWnd::GetDlgItem((CWnd *)this, 1043);
  v26 = (void *)SendMessageA(*((HWND *)DlgItem + 8), 0x31u, 0, 0);
  v27 = CGdiObject::FromHandle(v26);
  GetObjectA(*((HANDLE *)v27 + 1), 60, &pv);
  pv.lfHeight = -16;
  pv.lfWidth = 8;
  v28 = CreateFontIndirectA(&pv);
  CGdiObject::Attach((CGdiObject *)(this + 31552), v28);
  v29 = CWnd::GetDlgItem((CWnd *)this, 1043);
  if ( this == -31552 )
    v30 = 0;
  else
    v30 = *(_DWORD *)(this + 31556);
  SendMessageA(*((HWND *)v29 + 8), 0x30u, v30, 1);
  CString::operator=(this + 31560, &Str2);
  *(_BYTE *)(this + 31565) = -1;
  *(_BYTE *)(this + 31564) = -1;
  *(_BYTE *)(this + 31567) = -1;
  *(_BYTE *)(this + 31566) = -1;
  v42 = -1;
  CString::~CString((CString *)&lParam);
  return 1;
}
