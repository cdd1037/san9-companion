// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004191C0; original name: sub_4191C0
void __thiscall sub_4191C0(struct CWnd *this)
{
  int (__cdecl *v2)(const char *); // ebx
  int v3; // eax
  int v4; // eax
  int i; // edi
  int j; // edi
  int v7; // eax
  char *v8; // ecx
  int v9; // ecx
  int v10; // [esp+0h] [ebp-4Ch] BYREF
  _BYTE v11[20]; // [esp+20h] [ebp-2Ch] BYREF
  struct CWnd *v12; // [esp+34h] [ebp-18h]
  char *String[2]; // [esp+38h] [ebp-14h] BYREF
  int v14; // [esp+48h] [ebp-4h]

  String[1] = (char *)&v10;
  v12 = this;
  CStdioFile::CStdioFile((CStdioFile *)v11);
  v14 = 0;
  CString::CString((CString *)String);
  LOBYTE(v14) = 1;
  if ( CStdioFile::Open((CStdioFile *)v11, aSan9pkhardpara, 0x4020u, nullptr) != 0 )
  {
    LOBYTE(v14) = 2;
    if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) != 0 )
    {
      v2 = atoi;
      *((_DWORD *)this + 93) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 94) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 95) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 96) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 97) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 98) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 99) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 100) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 101) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 120) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 121) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 122) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 123) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 124) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      v3 = atoi(String[0]);
      *((_DWORD *)this + 37) = v3 & 1;
      *((_DWORD *)this + 81) = (v3 & 2) != 0;
      *((_DWORD *)this + 38) = (v3 & 4) != 0;
      *((_DWORD *)this + 39) = (v3 & 8) != 0;
      *((_DWORD *)this + 40) = (v3 & 0x10) != 0;
      *((_DWORD *)this + 41) = (v3 & 0x20) != 0;
      *((_DWORD *)this + 42) = (v3 & 0x40) != 0;
      *((_DWORD *)this + 43) = (v3 & 0x80) != 0;
      *((_DWORD *)this + 44) = (v3 & 0x100) != 0;
      *((_DWORD *)this + 69) = (v3 & 0x200) != 0;
      *((_DWORD *)this + 45) = (v3 & 0x400) != 0;
      *((_DWORD *)this + 46) = (v3 & 0x800) != 0;
      *((_DWORD *)this + 47) = (v3 & 0x1000) != 0;
      *((_DWORD *)this + 48) = (v3 & 0x2000) != 0;
      *((_DWORD *)this + 49) = (v3 & 0x4000) != 0;
      *((_DWORD *)this + 50) = (v3 & 0x8000) != 0;
      *((_DWORD *)this + 51) = (v3 & 0x10000) != 0;
      *((_DWORD *)this + 85) = (v3 & 0x20000) != 0;
      *((_DWORD *)this + 86) = (v3 & 0x40000) != 0;
      *((_DWORD *)this + 87) = (v3 & 0x80000) != 0;
      *((_DWORD *)this + 88) = (v3 & 0x100000) != 0;
      *((_DWORD *)this + 89) = (v3 & 0x200000) != 0;
      *((_DWORD *)this + 90) = (v3 & 0x400000) != 0;
      *((_DWORD *)this + 91) = (v3 & 0x800000) != 0;
      *((_DWORD *)this + 92) = (v3 & 0x1000000) != 0;
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      v4 = atoi(String[0]);
      *((_DWORD *)this + 77) = v4 & 1;
      *((_DWORD *)this + 52) = (v4 & 2) != 0;
      *((_DWORD *)this + 53) = (v4 & 4) != 0;
      *((_DWORD *)this + 54) = (v4 & 8) != 0;
      *((_DWORD *)this + 55) = (v4 & 0x10) != 0;
      *((_DWORD *)this + 56) = (v4 & 0x20) != 0;
      *((_DWORD *)this + 57) = (v4 & 0x40) != 0;
      *((_DWORD *)this + 58) = (v4 & 0x80) != 0;
      *((_DWORD *)this + 59) = (v4 & 0x100) != 0;
      *((_DWORD *)this + 60) = (v4 & 0x200) != 0;
      *((_DWORD *)this + 61) = (v4 & 0x400) != 0;
      *((_DWORD *)this + 62) = (v4 & 0x800) != 0;
      *((_DWORD *)this + 63) = (v4 & 0x1000) != 0;
      *((_DWORD *)this + 64) = (v4 & 0x2000) != 0;
      *((_DWORD *)this + 65) = (v4 & 0x4000) != 0;
      *((_DWORD *)this + 66) = (v4 & 0x8000) != 0;
      *((_DWORD *)this + 67) = (v4 & 0x10000) != 0;
      *((_DWORD *)this + 68) = (v4 & 0x20000) != 0;
      *((_DWORD *)this + 70) = (v4 & 0x40000) != 0;
      *((_DWORD *)this + 71) = (v4 & 0x80000) != 0;
      *((_DWORD *)this + 72) = (v4 & 0x100000) != 0;
      *((_DWORD *)this + 73) = (v4 & 0x200000) != 0;
      *((_DWORD *)this + 74) = (v4 & 0x400000) != 0;
      *((_DWORD *)this + 75) = (v4 & 0x800000) != 0;
      *((_DWORD *)this + 76) = (v4 & 0x1000000) != 0;
      *((_DWORD *)this + 78) = (v4 & 0x2000000) != 0;
      *((_DWORD *)this + 79) = (v4 & 0x4000000) != 0;
      *((_DWORD *)this + 80) = (v4 & 0x8000000) != 0;
      *((_DWORD *)this + 82) = (v4 & 0x10000000) != 0;
      *((_DWORD *)this + 83) = (v4 & 0x20000000) != 0;
      *((_DWORD *)this + 84) = (v4 & 0x40000000) != 0;
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 102) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 103) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 104) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 105) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 106) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 107) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 108) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 109) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 110) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 111) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_37;
      *((_DWORD *)this + 112) = atoi(String[0]);
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) != 0
        && (*((_DWORD *)this + 113) = atoi(String[0]),
            CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) != 0)
        && (*((_DWORD *)this + 114) = atoi(String[0]),
            CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) != 0)
        && (*((_DWORD *)this + 115) = atoi(String[0]),
            CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) != 0)
        && (*((_DWORD *)this + 116) = atoi(String[0]),
            CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) != 0)
        && (*((_DWORD *)this + 118) = atoi(String[0]),
            CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) != 0)
        && (*((_DWORD *)this + 119) = atoi(String[0]),
            CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) != 0) )
      {
        *((_DWORD *)this + 117) = atoi(String[0]);
        v14 = 1;
        CStdioFile::Close((CStdioFile *)v11);
      }
      else
      {
LABEL_37:
        LOBYTE(v14) = 1;
        AfxMessageBox(&byte_42EE30, 0, 0);
        CStdioFile::Close((CStdioFile *)v11);
      }
    }
    else
    {
      v2 = atoi;
      LOBYTE(v14) = 1;
      AfxMessageBox(&byte_42EE30, 0, 0);
      CStdioFile::Close((CStdioFile *)v11);
    }
  }
  else
  {
    v2 = atoi;
  }
  if ( CStdioFile::Open((CStdioFile *)v11, aSan9pkhardpers, 0x4020u, nullptr) != 0 )
  {
    LOBYTE(v14) = 6;
    for ( i = 0; i < 800; ++i )
    {
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_50;
      *((_DWORD *)this + i + 125) = v2(String[0]);
    }
    for ( j = 0; j < 116; ++j )
    {
      if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
        goto LABEL_50;
      v7 = v2(String[0]);
      v8 = (char *)this + 6 * j;
      *((_WORD *)v8 + 1852) = v7 & 0x3FF;
      *((_WORD *)v8 + 1853) = (v7 >> 10) & 0x3FF;
      v9 = 3 * j + 1854;
      *((_WORD *)this + v9) = (v7 >> 20) & 0x3F;
    }
    if ( CStdioFile::ReadString((CStdioFile *)v11, (struct CString *)String) == 0 )
    {
LABEL_50:
      LOBYTE(v14) = 1;
      AfxMessageBox(&byte_42EE00, 0, 0);
      goto LABEL_52;
    }
    *((_WORD *)this + 2204) = v2(String[0]);
    v14 = 1;
LABEL_52:
    CStdioFile::Close((CStdioFile *)v11);
  }
  sub_419BE0(this, 0);
  sub_419E70(this);
  sub_419FB0(this);
  LOBYTE(v14) = 0;
  CString::~CString((CString *)String);
  v14 = -1;
  CStdioFile::~CStdioFile((CStdioFile *)v11);
}
