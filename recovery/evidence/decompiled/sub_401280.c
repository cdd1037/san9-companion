// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00401280; original name: sub_401280
int __thiscall sub_401280(HWND *this)
{
  int v2; // ebx
  struct AFX_MODULE_STATE *ModuleState; // eax
  int v4; // eax
  void *v5; // eax
  CHAR *p_MultiByteStr; // edi
  LRESULT v7; // eax
  __int16 v8; // cx
  _WORD *v9; // eax
  LPARAM lParam; // [esp+8h] [ebp-E68h] BYREF
  _BYTE Buffer[16]; // [esp+Ch] [ebp-E64h] BYREF
  CHAR MultiByteStr; // [esp+1Ch] [ebp-E54h] BYREF
  int v14; // [esp+E6Ch] [ebp-4h]

  CDialog::OnInitDialog((CDialog *)this);
  CString::CString((CString *)&lParam);
  v2 = 0;
  v14 = 0;
  ModuleState = AfxGetModuleState();
  v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)ModuleState + 1) + 124))(*((_DWORD *)ModuleState + 1));
  *(this + 50) = (HWND)v4;
  *(this + 49) = (HWND)(v4 + 4996);
  *((_BYTE *)this + 204) = 0;
  v5 = *(void **)(v4 + 112);
  if ( v5 != nullptr )
  {
    if ( ReadProcessMemory(v5, (LPCVOID)0x1500B70, Buffer, 0xE58u, nullptr) )
    {
      p_MultiByteStr = &MultiByteStr;
      while ( 1 )
      {
        sub_41A110(p_MultiByteStr);
        CString::Format((CString *)&lParam, "%02d %s", v2, p_MultiByteStr);
        v7 = SendMessageA(*(this + 32), 0x181u, 0xFFFFFFFF, lParam);
        if ( v7 == -1 || v7 == -2 )
          break;
        if ( (*((_BYTE *)*(this + 50) + 4994) & 3) == 0 )
        {
          *((_DWORD *)*(this + 49) + 2 * v2) = p_MultiByteStr[80];
          *((_DWORD *)*(this + 49) + 2 * v2) |= p_MultiByteStr[84] << 6;
          *((_DWORD *)*(this + 49) + 2 * v2) |= p_MultiByteStr[88] << 12;
          *((_DWORD *)*(this + 49) + 2 * v2) |= p_MultiByteStr[92] << 18;
          *((_DWORD *)*(this + 49) + 2 * v2) |= p_MultiByteStr[76] << 24;
          *((_WORD *)*(this + 49) + 4 * v2 + 2) &= 0xFu;
          *((_WORD *)*(this + 49) + 4 * v2 + 2) |= 16 * p_MultiByteStr[96];
          LOBYTE(v8) = 0;
          HIBYTE(v8) = p_MultiByteStr[100];
          v9 = *(this + 49) + 2 * v2 + 1;
          *v9 |= v8;
          *((_WORD *)*(this + 49) + 4 * v2 + 3) = *((_WORD *)p_MultiByteStr + 52);
        }
        ++v2;
        p_MultiByteStr += 136;
        if ( v2 >= 27 )
          goto LABEL_12;
      }
      AfxMessageBox(&byte_41F510, 0, 0);
LABEL_12:
      *((_BYTE *)this + 204) = v2;
      if ( (_BYTE)v2 == 27 )
        *((_BYTE *)*(this + 50) + 4994) |= 2u;
    }
    else
    {
      AfxMessageBox(&byte_41F528, 0, 0);
    }
  }
  *((_BYTE *)this + 205) = 0;
  sub_4014A0((CWnd *)this);
  v14 = -1;
  CString::~CString((CString *)&lParam);
  return 1;
}
