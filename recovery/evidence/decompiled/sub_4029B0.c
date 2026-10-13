// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004029B0; original name: sub_4029B0
int __thiscall sub_4029B0(int this)
{
  int v2; // ebx
  struct AFX_MODULE_STATE *ModuleState; // eax
  int v4; // eax
  void *v5; // eax
  CHAR *p_MultiByteStr; // edi
  LRESULT v7; // eax
  LPARAM lParam; // [esp+8h] [ebp-1564h] BYREF
  _BYTE Buffer[16]; // [esp+Ch] [ebp-1560h] BYREF
  CHAR MultiByteStr; // [esp+1Ch] [ebp-1550h] BYREF
  int v12; // [esp+1568h] [ebp-4h]

  CDialog::OnInitDialog((CDialog *)this);
  CString::CString((CString *)&lParam);
  v2 = 0;
  v12 = 0;
  ModuleState = AfxGetModuleState();
  v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)ModuleState + 1) + 124))(*((_DWORD *)ModuleState + 1));
  *(_DWORD *)(this + 176) = v4;
  *(_DWORD *)(this + 172) = v4 + 4838;
  *(_BYTE *)(this + 180) = 0;
  v5 = *(void **)(v4 + 112);
  if ( v5 == nullptr )
    goto LABEL_14;
  if ( !ReadProcessMemory(v5, (LPCVOID)0x14FDAD0, Buffer, 0x1554u, nullptr) )
  {
    AfxMessageBox(&byte_41F6AC, 0, 0);
    goto LABEL_14;
  }
  p_MultiByteStr = &MultiByteStr;
  while ( 1 )
  {
    sub_41A110(p_MultiByteStr);
    CString::Format((CString *)&lParam, "%02d %s", v2, p_MultiByteStr);
    v7 = SendMessageA(*(HWND *)(this + 128), 0x181u, 0xFFFFFFFF, lParam);
    if ( (*(_BYTE *)(*(_DWORD *)(this + 176) + 4836) & 3) == 0 )
      break;
LABEL_9:
    ++v2;
    p_MultiByteStr += 140;
    if ( v2 >= 39 )
      goto LABEL_12;
  }
  if ( v7 != -1 && v7 != -2 )
  {
    *(_BYTE *)(*(_DWORD *)(this + 172) + 4 * v2) = p_MultiByteStr[84];
    *(_BYTE *)(*(_DWORD *)(this + 172) + 4 * v2 + 1) = p_MultiByteStr[108];
    *(_WORD *)(*(_DWORD *)(this + 172) + 4 * v2 + 2) = *((_WORD *)p_MultiByteStr + 36);
    goto LABEL_9;
  }
  AfxMessageBox(&byte_41F69C, 0, 0);
LABEL_12:
  *(_BYTE *)(this + 180) = v2;
  if ( (_BYTE)v2 == 39 )
    *(_BYTE *)(*(_DWORD *)(this + 176) + 4836) |= 2u;
LABEL_14:
  *(_BYTE *)(this + 181) = 0;
  sub_402B40((CWnd *)this);
  v12 = -1;
  CString::~CString((CString *)&lParam);
  return 1;
}
