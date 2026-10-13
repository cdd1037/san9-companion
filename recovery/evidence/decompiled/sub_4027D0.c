// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004027D0; original name: sub_4027D0
void __thiscall sub_4027D0(struct CWnd *this)
{
  int v2; // esi
  int i; // esi
  const char *v4; // [esp-Ch] [ebp-284h]
  int v5; // [esp+0h] [ebp-278h] BYREF
  _BYTE v6[176]; // [esp+Ch] [ebp-26Ch] BYREF
  _BYTE v7[332]; // [esp+BCh] [ebp-1BCh] BYREF
  char v8[48]; // [esp+208h] [ebp-70h] BYREF
  _BYTE v9[4]; // [esp+24Ch] [ebp-2Ch] BYREF
  _BYTE v10[20]; // [esp+250h] [ebp-28h] BYREF
  char *v11[2]; // [esp+264h] [ebp-14h] BYREF
  int v12; // [esp+274h] [ebp-4h]

  v11[1] = (char *)&v5;
  CStdioFile::CStdioFile((CStdioFile *)v10);
  v12 = 0;
  CString::CString((CString *)v11);
  strcpy(v8, "Text Files (*.txt)|*.txt|All Files (*.*)|*.*||");
  LOBYTE(v12) = 1;
  CFileDialog::CFileDialog((CFileDialog *)v6, 0, nullptr, aSan9pkhardskil, 6u, v8, this);
  LOBYTE(v12) = 2;
  if ( sub_402BB0(this) != 0 )
  {
    if ( CFileDialog::DoModal((CFileDialog *)v6) == 1 )
    {
      v4 = *(const char **)CFileDialog::GetPathName(v6, v9);
      LOBYTE(v12) = 5;
      v2 = CStdioFile::Open((CStdioFile *)v10, v4, 0x5011u, nullptr);
      LOBYTE(v12) = 2;
      CString::~CString((CString *)v9);
      if ( v2 != 0 )
      {
        LOBYTE(v12) = 7;
        for ( i = 0; i < 39; ++i )
        {
          CString::Format((CString *)v11, "%d\n", *(_DWORD *)(*((_DWORD *)this + 43) + 4 * i));
          CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        }
        v12 = 2;
        CStdioFile::Close((CStdioFile *)v10);
        LOBYTE(v12) = 12;
      }
      else
      {
        AfxMessageBox(&byte_41F670, 0, 0);
        LOBYTE(v12) = 6;
      }
    }
    else
    {
      LOBYTE(v12) = 4;
    }
  }
  else
  {
    LOBYTE(v12) = 3;
  }
  CString::~CString((CString *)v7);
  LOBYTE(v12) = 1;
  CDialog::~CDialog((CDialog *)v6);
  LOBYTE(v12) = 0;
  CString::~CString((CString *)v11);
  v12 = -1;
  CStdioFile::~CStdioFile((CStdioFile *)v10);
}
