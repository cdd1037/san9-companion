// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401E00; original name: sub_401E00
int __thiscall sub_401E00(int this)
{
  int v2; // ebp
  struct AFX_MODULE_STATE *ModuleState; // eax
  int v4; // eax
  void *v5; // eax
  int v6; // ebx
  CHAR *p_MultiByteStr; // edi
  LRESULT v8; // eax
  int v9; // eax
  int i; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  LPARAM lParam; // [esp+8h] [ebp-60F0h] BYREF
  _BYTE Buffer[32]; // [esp+Ch] [ebp-60ECh] BYREF
  CHAR MultiByteStr; // [esp+2Ch] [ebp-60CCh] BYREF
  int v18; // [esp+60F4h] [ebp-4h]

  CDialog::OnInitDialog((CDialog *)this);
  CString::CString((CString *)&lParam);
  v2 = 0;
  v18 = 0;
  ModuleState = AfxGetModuleState();
  v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)ModuleState + 1) + 124))(*((_DWORD *)ModuleState + 1));
  *(_DWORD *)(this + 240) = v4;
  *(_DWORD *)(this + 236) = v4 + 4420;
  *(_DWORD *)(this + 196) = *(_DWORD *)(v4 + 4412);
  *(_BYTE *)(this + 244) = 0;
  v5 = *(void **)(v4 + 112);
  if ( v5 != nullptr )
  {
    if ( ReadProcessMemory(v5, (LPCVOID)0x124DB58, Buffer, 0x60E0u, nullptr) )
    {
      v6 = 0;
      p_MultiByteStr = &MultiByteStr;
      while ( 1 )
      {
        sub_41A110(p_MultiByteStr);
        CString::Format((CString *)&lParam, "%02d %s", v6, p_MultiByteStr);
        v8 = SendMessageA(*(HWND *)(this + 128), 0x181u, 0xFFFFFFFF, lParam);
        if ( v8 == -1 || v8 == -2 )
          break;
        if ( *(_DWORD *)(this + 196) == 0 && *(_DWORD *)(*(_DWORD *)(this + 240) + 4416) == 0 )
        {
          v9 = *(_DWORD *)(p_MultiByteStr + 49);
          LOBYTE(i) = 0;
          *(_DWORD *)(this + 160) = v9;
          if ( (v9 & 2) == 0 )
          {
            LOBYTE(i) = 1;
            if ( (v9 & 4) == 0 )
            {
              LOBYTE(i) = 2;
              if ( (v9 & 8) == 0 )
              {
                *(_DWORD *)(this + 160) = v9 >> 15;
                for ( i = 3; i < 11; ++i )
                {
                  v11 = *(_DWORD *)(this + 160);
                  if ( (v11 & 1) != 0 )
                    break;
                  *(_DWORD *)(this + 160) = v11 >> 1;
                }
              }
            }
          }
          *(_BYTE *)(*(_DWORD *)(this + 236) + v2) = i;
          v12 = *((_DWORD *)p_MultiByteStr + 13);
          *(_DWORD *)(this + 160) = v12;
          if ( (v12 & 0x80u) != 0 )
            *(_BYTE *)(*(_DWORD *)(this + 236) + v2) |= 0x10u;
          if ( (*(_DWORD *)(this + 160) & 0x100) != 0 )
            *(_BYTE *)(*(_DWORD *)(this + 236) + v2) |= 0x20u;
          v13 = *((_DWORD *)p_MultiByteStr + 112);
          *(_DWORD *)(this + 160) = v13;
          if ( (v13 & 1) != 0 )
            *(_BYTE *)(v2 + *(_DWORD *)(this + 236)) |= 0x80u;
          *(_BYTE *)(*(_DWORD *)(this + 236) + v2 + 2) = *((_DWORD *)p_MultiByteStr + 106) / 100;
          *(_BYTE *)(*(_DWORD *)(this + 236) + v2 + 4) = *((_DWORD *)p_MultiByteStr + 109) / 100;
          *(_BYTE *)(*(_DWORD *)(this + 236) + v2 + 5) = *((_DWORD *)p_MultiByteStr + 110) / 100;
        }
        v2 += 6;
        ++v6;
        p_MultiByteStr += 496;
        if ( v2 >= 300 )
          goto LABEL_25;
      }
      AfxMessageBox(&byte_41F5E0, 0, 0);
LABEL_25:
      *(_BYTE *)(this + 244) = v6;
      if ( (_BYTE)v6 == 50 )
        *(_DWORD *)(*(_DWORD *)(this + 240) + 4416) = 1;
    }
    else
    {
      AfxMessageBox(&byte_41F5F0, 0, 0);
    }
  }
  *(_BYTE *)(this + 245) = 0;
  sub_4020A0((CWnd *)this);
  v18 = -1;
  CString::~CString((CString *)&lParam);
  return 1;
}
