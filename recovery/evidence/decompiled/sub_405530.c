// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405530; original name: sub_405530
void __thiscall sub_405530(struct CWnd *this)
{
  int v2; // esi
  int i; // esi
  int j; // esi
  const char *v5; // [esp-Ch] [ebp-284h]
  int v6; // [esp+0h] [ebp-278h] BYREF
  _BYTE v7[176]; // [esp+Ch] [ebp-26Ch] BYREF
  _BYTE v8[332]; // [esp+BCh] [ebp-1BCh] BYREF
  char v9[48]; // [esp+208h] [ebp-70h] BYREF
  _BYTE v10[4]; // [esp+24Ch] [ebp-2Ch] BYREF
  _BYTE v11[20]; // [esp+250h] [ebp-28h] BYREF
  char *v12[2]; // [esp+264h] [ebp-14h] BYREF
  int v13; // [esp+274h] [ebp-4h]

  v12[1] = (char *)&v6;
  CStdioFile::CStdioFile((CStdioFile *)v11);
  v13 = 0;
  CString::CString((CString *)v12);
  strcpy(v9, "Text Files (*.txt)|*.txt|All Files (*.*)|*.*||");
  LOBYTE(v13) = 1;
  CFileDialog::CFileDialog((CFileDialog *)v7, 0, nullptr, aSan9pkhardpers, 6u, v9, this);
  LOBYTE(v13) = 2;
  if ( sub_4050B0(this) != 0 )
  {
    if ( sub_405480((int)this) != 0 )
    {
      **((_WORD **)this + 7893) = *((_WORD *)this + 168);
      if ( CFileDialog::DoModal((CFileDialog *)v7) == 1 )
      {
        v5 = *(const char **)CFileDialog::GetPathName(v7, v10);
        LOBYTE(v13) = 6;
        v2 = CStdioFile::Open((CStdioFile *)v11, v5, 0x5011u, nullptr);
        LOBYTE(v13) = 2;
        CString::~CString((CString *)v10);
        if ( v2 != 0 )
        {
          LOBYTE(v13) = 8;
          for ( i = 0; i < 800; ++i )
          {
            CString::Format((CString *)v12, "%d\n", *(_DWORD *)(*((_DWORD *)this + 85) + 4 * i));
            CStdioFile::WriteString((CStdioFile *)v11, v12[0]);
          }
          for ( j = 0; j < 116; ++j )
          {
            CString::Format(
              (CString *)v12,
              "%d\n",
              *(unsigned __int16 *)(*((_DWORD *)this + 7892) + 6 * j)
            + ((*(unsigned __int16 *)(*((_DWORD *)this + 7892) + 6 * j + 2)
              + (*(unsigned __int16 *)(*((_DWORD *)this + 7892) + 6 * j + 4) << 10)) << 10));
            CStdioFile::WriteString((CStdioFile *)v11, v12[0]);
          }
          CString::Format((CString *)v12, "%d\n", *((_DWORD *)this + 84));
          CStdioFile::WriteString((CStdioFile *)v11, v12[0]);
          v13 = 2;
          CStdioFile::Close((CStdioFile *)v11);
          LOBYTE(v13) = 13;
        }
        else
        {
          AfxMessageBox(&byte_41F7D0, 0, 0);
          LOBYTE(v13) = 7;
        }
      }
      else
      {
        LOBYTE(v13) = 5;
      }
    }
    else
    {
      LOBYTE(v13) = 4;
    }
  }
  else
  {
    LOBYTE(v13) = 3;
  }
  CString::~CString((CString *)v8);
  LOBYTE(v13) = 1;
  CDialog::~CDialog((CDialog *)v7);
  LOBYTE(v13) = 0;
  CString::~CString((CString *)v12);
  v13 = -1;
  CStdioFile::~CStdioFile((CStdioFile *)v11);
}
