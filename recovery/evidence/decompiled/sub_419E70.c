// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00419E70; original name: sub_419E70
void __thiscall sub_419E70(_BYTE *this)
{
  int v2; // esi
  char v3; // al
  int v4; // [esp+0h] [ebp-48h] BYREF
  _BYTE v5[20]; // [esp+20h] [ebp-28h] BYREF
  char *String[2]; // [esp+34h] [ebp-14h] BYREF
  int v7; // [esp+44h] [ebp-4h]

  String[1] = (char *)&v4;
  CStdioFile::CStdioFile((CStdioFile *)v5);
  v2 = 0;
  v7 = 0;
  CString::CString((CString *)String);
  LOBYTE(v7) = 1;
  if ( CStdioFile::Open((CStdioFile *)v5, aSan9pkhardskil, 0x4020u, nullptr) != 0 )
  {
    LOBYTE(v7) = 2;
    while ( v2 < 39 )
    {
      if ( CStdioFile::ReadString((CStdioFile *)v5, (struct CString *)String) == 0 )
      {
        LOBYTE(v7) = 1;
        AfxMessageBox(&byte_42EE8C, 0, 0);
        goto LABEL_8;
      }
      *(_DWORD *)(this + 4 * v2++ + 4838) = atoi(String[0]);
    }
    v3 = *(this + 4836);
    v7 = 1;
    *(this + 4836) = v3 | 1;
LABEL_8:
    CStdioFile::Close((CStdioFile *)v5);
  }
  LOBYTE(v7) = 0;
  CString::~CString((CString *)String);
  v7 = -1;
  CStdioFile::~CStdioFile((CStdioFile *)v5);
}
