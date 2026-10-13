// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00419BE0; original name: sub_419BE0
void __thiscall sub_419BE0(struct CWnd *this, char a2)
{
  char v3; // bl
  int PathName; // eax
  int i; // esi
  char *v6; // edi
  int v7; // esi
  int v8; // [esp+0h] [ebp-278h] BYREF
  _BYTE v9[176]; // [esp+Ch] [ebp-26Ch] BYREF
  _BYTE v10[332]; // [esp+BCh] [ebp-1BCh] BYREF
  char v11[48]; // [esp+208h] [ebp-70h] BYREF
  _BYTE v12[20]; // [esp+24Ch] [ebp-2Ch] BYREF
  struct CWnd *v13; // [esp+260h] [ebp-18h]
  char *String[2]; // [esp+264h] [ebp-14h] BYREF
  int v15; // [esp+274h] [ebp-4h]

  String[1] = (char *)&v8;
  v13 = this;
  CStdioFile::CStdioFile((CStdioFile *)v12);
  v15 = 0;
  CString::CString((CString *)String, aSan9pkhardcity);
  strcpy(v11, "Text Files (*.txt)|*.txt|All Files (*.*)|*.*||");
  LOBYTE(v15) = 1;
  CFileDialog::CFileDialog((CFileDialog *)v9, 1, nullptr, String[0], 4u, v11, this);
  v3 = a2;
  LOBYTE(v15) = 2;
  if ( a2 != 0 )
  {
    if ( CFileDialog::DoModal((CFileDialog *)v9) != 1 )
    {
      LOBYTE(v15) = 3;
      goto LABEL_23;
    }
    PathName = CFileDialog::GetPathName(v9, &a2);
    LOBYTE(v15) = 4;
    CString::operator=(String, PathName);
    LOBYTE(v15) = 2;
    CString::~CString((CString *)&a2);
  }
  if ( CStdioFile::Open((CStdioFile *)v12, String[0], 0x4020u, nullptr) != 0 )
  {
    LOBYTE(v15) = 6;
    for ( i = 0; i < 50; ++i )
    {
      if ( CStdioFile::ReadString((CStdioFile *)v12, (struct CString *)String) == 0
        || (v6 = (char *)v13 + 6 * i,
            *((_DWORD *)v6 + 1105) = atoi(String[0]),
            CStdioFile::ReadString((CStdioFile *)v12, (struct CString *)String) == 0) )
      {
LABEL_19:
        LOBYTE(v15) = 2;
        AfxMessageBox(&byte_42EE5C, 0, 0);
        goto LABEL_22;
      }
      *((_WORD *)v6 + 2212) = atoi(String[0]);
    }
    v7 = 0;
    *((_DWORD *)v13 + 1104) = 1;
    while ( v7 < 50 )
    {
      if ( CStdioFile::ReadString((CStdioFile *)v12, (struct CString *)String) == 0 )
        goto LABEL_19;
      dword_42D948[2 * v7] = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v12, (struct CString *)String) == 0 )
        goto LABEL_19;
      dword_42D94C[2 * v7] = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v12, (struct CString *)String) == 0 )
        goto LABEL_19;
      byte_42DAD8[v7++] = atoi(String[0]);
    }
    v15 = 2;
LABEL_22:
    CStdioFile::Close((CStdioFile *)v12);
    LOBYTE(v15) = 10;
  }
  else
  {
    if ( v3 != 0 )
      AfxMessageBox(&byte_41F624, 0, 0);
    LOBYTE(v15) = 5;
  }
LABEL_23:
  CString::~CString((CString *)v10);
  LOBYTE(v15) = 1;
  CDialog::~CDialog((CDialog *)v9);
  LOBYTE(v15) = 0;
  CString::~CString((CString *)String);
  v15 = -1;
  CStdioFile::~CStdioFile((CStdioFile *)v12);
}
