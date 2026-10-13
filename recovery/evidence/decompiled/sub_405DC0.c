// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405DC0; original name: sub_405DC0
int __thiscall sub_405DC0(CWinApp *this)
{
  HWND WindowA; // eax
  HWND v3; // edi
  _DWORD v5[1906]; // [esp+8h] [ebp-1E18h] BYREF
  _BYTE v6[68]; // [esp+1DD0h] [ebp-50h] BYREF
  int v7; // [esp+1E1Ch] [ebp-4h]

  CWinApp::Enable3dControls(this);
  WindowA = FindWindowA(nullptr, &WindowName);
  v3 = WindowA;
  if ( WindowA != nullptr )
  {
    SetForegroundWindow(WindowA);
    ShowWindow(v3, 9);
  }
  else
  {
    sub_408670(v5, nullptr);
    v7 = 0;
    *((_DWORD *)this + 8) = v5;
    CDialog::DoModal((CDialog *)v5);
    v7 = 1;
    CEdit::~CEdit((CEdit *)v6);
    v7 = -1;
    CDialog::~CDialog((CDialog *)v5);
  }
  return 0;
}
