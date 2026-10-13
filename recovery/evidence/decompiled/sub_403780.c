// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00403780; original name: sub_403780
void __thiscall sub_403780(CWnd *this)
{
  int v2; // esi
  const char *v3; // [esp-Ch] [ebp-284h]
  int v4; // [esp-4h] [ebp-27Ch]
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
  CFileDialog::CFileDialog((CFileDialog *)v6, 0, nullptr, aSan9pkhardpara, 6u, v8, this);
  LOBYTE(v12) = 2;
  if ( (unsigned __int8)sub_403FF0(this) != 0 )
  {
    if ( CFileDialog::DoModal((CFileDialog *)v6) == 1 )
    {
      v3 = *(const char **)CFileDialog::GetPathName(v6, v9);
      LOBYTE(v12) = 5;
      v2 = CStdioFile::Open((CStdioFile *)v10, v3, 0x5011u, nullptr);
      LOBYTE(v12) = 2;
      CString::~CString((CString *)v9);
      if ( v2 != 0 )
      {
        v4 = *((_DWORD *)this + 30);
        LOBYTE(v12) = 7;
        CString::Format((CString *)v11, "%d\n", v4);
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 31));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 32));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 27));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 28));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 29));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 25));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 24));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 26));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 68));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 69));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 70));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 71));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 85));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format(
          (CString *)v11,
          "%d\n",
          *((_DWORD *)this + 96)
        | (2
         * (*((_DWORD *)this + 95)
          | (2
           * (*((_DWORD *)this + 39)
            | (2
             * (*((_DWORD *)this + 47)
              | (2
               * (*((_DWORD *)this + 48)
                | (2
                 * (*((_DWORD *)this + 51)
                  | (2
                   * (*((_DWORD *)this + 53)
                    | (2
                     * (*((_DWORD *)this + 58)
                      | (2
                       * (*((_DWORD *)this + 61)
                        | (2
                         * (*((_DWORD *)this + 59)
                          | (2
                           * (*((_DWORD *)this + 65)
                            | (2
                             * (*((_DWORD *)this + 67)
                              | (2
                               * (*((_DWORD *)this + 81)
                                | (2
                                 * (*((_DWORD *)this + 83)
                                  | (2
                                   * (*((_DWORD *)this + 86)
                                    | (2
                                     * (*((_DWORD *)this + 88)
                                      | (2
                                       * (*((_DWORD *)this + 100)
                                        | (2
                                         * (*((_DWORD *)this + 104)
                                          | (2
                                           * (*((_DWORD *)this + 105)
                                            | (2
                                             * (*((_DWORD *)this + 106)
                                              | (2
                                               * (*((_DWORD *)this + 107)
                                                | (2
                                                 * (*((_DWORD *)this + 108)
                                                  | (2
                                                   * (*((_DWORD *)this + 109)
                                                    | (2 * (*((_DWORD *)this + 110) | (2 * *((_DWORD *)this + 111)))))))))))))))))))))))))))))))))))))))))))))))));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format(
          (CString *)v11,
          "%d\n",
          *((_DWORD *)this + 87)
        | (2
         * (*((_DWORD *)this + 34)
          | (2
           * (*((_DWORD *)this + 37)
            | (2
             * (*((_DWORD *)this + 35)
              | (2
               * (*((_DWORD *)this + 38)
                | (2
                 * (*((_DWORD *)this + 36)
                  | (2
                   * (*((_DWORD *)this + 52)
                    | (2
                     * (*((_DWORD *)this + 40)
                      | (2
                       * (*((_DWORD *)this + 41)
                        | (2
                         * (*((_DWORD *)this + 43)
                          | (2
                           * (*((_DWORD *)this + 44)
                            | (2
                             * (*((_DWORD *)this + 45)
                              | (2
                               * (*((_DWORD *)this + 46)
                                | (2
                                 * (*((_DWORD *)this + 49)
                                  | (2
                                   * (*((_DWORD *)this + 50)
                                    | (2
                                     * (*((_DWORD *)this + 33)
                                      | (2
                                       * (*((_DWORD *)this + 55)
                                        | (2
                                         * (*((_DWORD *)this + 60)
                                          | (2
                                           * (*((_DWORD *)this + 62)
                                            | (2
                                             * (*((_DWORD *)this + 64)
                                              | (2
                                               * (*((_DWORD *)this + 66)
                                                | (2
                                                 * (*((_DWORD *)this + 78)
                                                  | (2
                                                   * (*((_DWORD *)this + 79)
                                                    | (2
                                                     * (*((_DWORD *)this + 80)
                                                      | (2
                                                       * (*((_DWORD *)this + 82)
                                                        | (2
                                                         * (*((_DWORD *)this + 89)
                                                          | (2
                                                           * (*((_DWORD *)this + 93)
                                                            | (2
                                                             * (*((_DWORD *)this + 94)
                                                              | (2
                                                               * (*((_DWORD *)this + 98)
                                                                | (2
                                                                 * (*((_DWORD *)this + 101)
                                                                  | (2 * *((_DWORD *)this + 102)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 42));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 54));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 56));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 57));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 63));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 72));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 84));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 75));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 77));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 76));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 74));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 73));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 90));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 91));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 92));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 97));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 99));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        CString::Format((CString *)v11, "%d\n", *((_DWORD *)this + 103));
        CStdioFile::WriteString((CStdioFile *)v10, v11[0]);
        v12 = 2;
        CStdioFile::Close((CStdioFile *)v10);
        LOBYTE(v12) = 12;
      }
      else
      {
        AfxMessageBox(&byte_41F6E0, 0, 0);
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
