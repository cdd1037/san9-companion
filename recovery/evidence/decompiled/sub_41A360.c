// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A360; original name: sub_41A360
void __thiscall sub_41A360(char *this)
{
  UINT v1; // eax
  char *v2; // [esp+0h] [ebp-10h] BYREF
  int v3; // [esp+Ch] [ebp-4h]

  v2 = this;
  CString::CString((CString *)&v2);
  v3 = 0;
  if ( FindWindowA(ClassName, nullptr) != nullptr )
  {
    AfxMessageBox(a39, 0, 0);
  }
  else
  {
    v1 = WinExec(CmdLine, 5u);
    if ( v1 <= 0x1F )
    {
      CString::Format((CString *)&v2, &byte_42EED0, v1);
      AfxMessageBox(v2, 0, 0);
    }
  }
  v3 = -1;
  CString::~CString((CString *)&v2);
}
