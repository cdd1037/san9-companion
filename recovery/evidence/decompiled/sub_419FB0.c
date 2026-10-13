// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00419FB0; original name: sub_419FB0
void __thiscall sub_419FB0(_BYTE *this)
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
  if ( CStdioFile::Open((CStdioFile *)v5, aSan9pkhardarra, 0x4020u, nullptr) != 0 )
  {
    LOBYTE(v7) = 2;
    while ( v2 < 27 )
    {
      if ( CStdioFile::ReadString((CStdioFile *)v5, (struct CString *)String) == 0
        || (*((_DWORD *)this + 2 * v2 + 1249) = atoi(String[0]),
            CStdioFile::ReadString((CStdioFile *)v5, (struct CString *)String) == 0) )
      {
        LOBYTE(v7) = 1;
        AfxMessageBox(&byte_42EEBC, 0, 0);
        goto LABEL_9;
      }
      *((_DWORD *)this + 2 * v2++ + 1250) = atoi(String[0]);
    }
    v3 = *(this + 4994);
    v7 = 1;
    *(this + 4994) = v3 | 1;
LABEL_9:
    CStdioFile::Close((CStdioFile *)v5);
  }
  LOBYTE(v7) = 0;
  CString::~CString((CString *)String);
  v7 = -1;
  CStdioFile::~CStdioFile((CStdioFile *)v5);
}
