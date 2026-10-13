// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00409430; original name: sub_409430
int __thiscall sub_409430(struct CWnd *this)
{
  _WORD *v2; // eax
  _WORD *v3; // ecx
  __int16 v4; // di
  _WORD *v5; // eax
  _WORD *v6; // ecx
  char *v7; // eax
  int i; // eax
  UINT_PTR v9; // eax

  CDialog::OnInitDialog(this);
  SendMessageA(*((HWND *)this + 8), 0x80u, 1u, *((_DWORD *)this + 1922));
  SendMessageA(*((HWND *)this + 8), 0x80u, 0, *((_DWORD *)this + 1922));
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 30) = *((_DWORD *)this + 8);
  *((_DWORD *)this + 31) = RegisterWindowMessageA(String);
  *((_DWORD *)this + 32) = -1010580541;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 43) = 0;
  *((_DWORD *)this + 42) = 0;
  *((_DWORD *)this + 41) = 0;
  *((_DWORD *)this + 40) = 0;
  *((_DWORD *)this + 47) = 0;
  *((_DWORD *)this + 46) = 0;
  *((_DWORD *)this + 45) = 0;
  *((_DWORD *)this + 69) = 0;
  *((_DWORD *)this + 44) = 0;
  *((_DWORD *)this + 51) = 0;
  *((_DWORD *)this + 50) = 0;
  *((_DWORD *)this + 49) = 0;
  *((_DWORD *)this + 48) = 0;
  *((_DWORD *)this + 88) = 0;
  *((_DWORD *)this + 87) = 0;
  *((_DWORD *)this + 86) = 0;
  *((_DWORD *)this + 85) = 0;
  *((_DWORD *)this + 92) = 0;
  *((_DWORD *)this + 91) = 0;
  *((_DWORD *)this + 90) = 0;
  *((_DWORD *)this + 89) = 0;
  *((_DWORD *)this + 55) = 0;
  *((_DWORD *)this + 54) = 0;
  *((_DWORD *)this + 53) = 0;
  *((_DWORD *)this + 83) = 0;
  *((_DWORD *)this + 52) = 0;
  *((_DWORD *)this + 60) = 0;
  *((_DWORD *)this + 59) = 0;
  *((_DWORD *)this + 58) = 0;
  *((_DWORD *)this + 57) = 0;
  *((_DWORD *)this + 56) = 0;
  *((_DWORD *)this + 65) = 0;
  *((_DWORD *)this + 64) = 0;
  *((_DWORD *)this + 63) = 0;
  *((_DWORD *)this + 62) = 0;
  *((_DWORD *)this + 61) = 0;
  *((_DWORD *)this + 70) = 0;
  *((_DWORD *)this + 68) = 0;
  *((_DWORD *)this + 67) = 0;
  *((_DWORD *)this + 66) = 0;
  *((_DWORD *)this + 74) = 0;
  *((_DWORD *)this + 73) = 0;
  *((_DWORD *)this + 72) = 0;
  *((_DWORD *)this + 71) = 0;
  *((_DWORD *)this + 78) = 0;
  *((_DWORD *)this + 77) = 0;
  *((_DWORD *)this + 76) = 0;
  *((_DWORD *)this + 95) = 49;
  *((_DWORD *)this + 97) = 49;
  *((_DWORD *)this + 101) = 49;
  *((_DWORD *)this + 75) = 0;
  *((_DWORD *)this + 82) = 0;
  *((_DWORD *)this + 81) = 0;
  *((_DWORD *)this + 80) = 0;
  *((_DWORD *)this + 79) = 0;
  *((_DWORD *)this + 84) = 0;
  *((_DWORD *)this + 93) = 12;
  *((_DWORD *)this + 94) = 24;
  *((_DWORD *)this + 96) = 24;
  *((_DWORD *)this + 98) = 98;
  *((_DWORD *)this + 99) = 9;
  *((_DWORD *)this + 100) = 24;
  *((_DWORD *)this + 102) = 0;
  *((_DWORD *)this + 103) = 10;
  *((_DWORD *)this + 104) = 0;
  *((_DWORD *)this + 105) = 1;
  *((_DWORD *)this + 106) = 5;
  *((_DWORD *)this + 107) = 0;
  *((_DWORD *)this + 108) = 0;
  *((_DWORD *)this + 109) = 20;
  *((_DWORD *)this + 110) = 14;
  *((_DWORD *)this + 111) = 10;
  *((_DWORD *)this + 112) = 9;
  *((_DWORD *)this + 113) = 8;
  *((_DWORD *)this + 114) = 0;
  *((_DWORD *)this + 115) = 36;
  *((_DWORD *)this + 116) = 0;
  *((_DWORD *)this + 117) = 10;
  *((_DWORD *)this + 120) = 80;
  *((_DWORD *)this + 121) = 60;
  *((_DWORD *)this + 122) = 40;
  *((_DWORD *)this + 123) = 50;
  *((_DWORD *)this + 124) = 5;
  *((_DWORD *)this + 925) = 671744;
  memset32((char *)this + 500, 261802, 0x320u);
  *((_WORD *)this + 2204) = 1500;
  *((_DWORD *)this + 1100) = 6358848;
  v2 = &unk_42DB2A;
  v3 = (_WORD *)((char *)this + 3706);
  do
  {
    v4 = *(v2 - 1);
    v2 += 3;
    *(v3 - 1) = v4;
    *v3 = *(v2 - 3);
    v3[1] = *(v2 - 2);
    v3 += 3;
  }
  while ( (int)v2 < (int)word_42DC86 );
  v5 = word_42DC86;
  v6 = (_WORD *)((char *)this + 4054);
  do
  {
    v6[1] = 0;
    *v6 = 0;
    *(v6 - 1) = 0;
    v5[1] = 0;
    *v5 = 0;
    *(v5 - 1) = 0;
    v5 += 3;
    v6 += 3;
  }
  while ( (int)v5 < (int)word_42DDE2 );
  *((_DWORD *)this + 1103) = 0;
  *((_DWORD *)this + 1104) = 0;
  *((_DWORD *)this + 1180) = 677474;
  *((_DWORD *)this + 1181) = 677424;
  v7 = (char *)this + 4778;
  do
  {
    *(v7 - 50) = 50;
    *v7++ = 10;
  }
  while ( (int)&v7[-4778 - (_DWORD)this] < 50 );
  *((_DWORD *)this + 1207) = 683520;
  *((_DWORD *)this + 1208) = 670912;
  for ( i = 0; i < 50; ++i )
    byte_42DAD8[i] += 2;
  *((_BYTE *)this + 4836) = 0;
  *((_BYTE *)this + 4994) = 0;
  *((_DWORD *)this + 1303) = 662240;
  *((_DWORD *)this + 118) = 0;
  *((_DWORD *)this + 119) = 35;
  v9 = SetTimer(*((HWND *)this + 8), 0x27u, 0x3E8u, nullptr);
  *((_DWORD *)this + 26) = v9;
  if ( v9 == 0 )
    AfxMessageBox((const char *)byte_42ED1C, 0, 0);
  sub_4191C0(this);
  return 1;
}
