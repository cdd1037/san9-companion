00402390  55                                            push    ebp
00402391  8b ec                                         mov     ebp, esp
00402393  6a ff                                         push    0FFFFFFFFh
00402395  68 aa ac 41 00                                push    offset SEH_402390
0040239A  64 a1 00 00 00 00                             mov     eax, large fs:0
004023A0  50                                            push    eax
004023A1  64 89 25 00 00 00 00                          mov     large fs:0, esp
004023A8  81 ec 60 02 00 00                             sub     esp, 260h
004023AE  53                                            push    ebx
004023AF  56                                            push    esi
004023B0  8b d9                                         mov     ebx, ecx
004023B2  57                                            push    edi
004023B3  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004023B6  89 65 f0                                      mov     [ebp+var_10], esp
004023B9  e8 b4 82 01 00                                call    ??0CStdioFile@@QAE@XZ; CStdioFile::CStdioFile(void)
004023BE  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
004023C1  c7 45 fc 00 00 00 00                          mov     [ebp+var_4], 0
004023C8  e8 51 82 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
004023CD  b9 0b 00 00 00                                mov     ecx, 0Bh
004023D2  be b0 f5 41 00                                mov     esi, offset aTextFilesTxtTx; "Text Files (*.txt)|*.txt|All Files (*.*"...
004023D7  8d 7d 90                                      lea     edi, [ebp+var_70]
004023DA  8d 45 90                                      lea     eax, [ebp+var_70]
004023DD  f3 a5                                         rep movsd
004023DF  53                                            push    ebx; struct CWnd *
004023E0  50                                            push    eax; char *
004023E1  66 a5                                         movsw
004023E3  6a 06                                         push    6; unsigned int
004023E5  68 3c f6 41 00                                push    offset aSan9pkhardcity; "San9PKHardCity.txt"
004023EA  6a 00                                         push    0; char *
004023EC  6a 00                                         push    0; int
004023EE  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
004023F4  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
004023F8  a4                                            movsb
004023F9  e8 6e 82 01 00                                call    ??0CFileDialog@@QAE@HPBD0K0PAVCWnd@@@Z; CFileDialog::CFileDialog(int,char const *,char const *,ulong,char const *,CWnd *)
004023FE  8b cb                                         mov     ecx, ebx
00402400  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
00402404  e8 b7 fd ff ff                                call    sub_4021C0
00402409  85 c0                                         test    eax, eax
0040240B  75 09                                         jnz     short loc_402416
0040240D  c6 45 fc 03                                   mov     byte ptr [ebp+var_4], 3
00402411  e9 b0 01 00 00                                jmp     loc_4025C6
00402416  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0040241C  e8 45 82 01 00                                call    ?DoModal@CFileDialog@@UAEHXZ; CFileDialog::DoModal(void)
00402421  83 f8 01                                      cmp     eax, 1
00402424  74 09                                         jz      short loc_40242F
00402426  c6 45 fc 04                                   mov     byte ptr [ebp+var_4], 4
0040242A  e9 97 01 00 00                                jmp     loc_4025C6
0040242F  8d 4d d4                                      lea     ecx, [ebp+var_2C]
00402432  51                                            push    ecx
00402433  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]
00402439  e8 22 82 01 00                                call    ?GetPathName@CFileDialog@@QBE?AVCString@@XZ; CFileDialog::GetPathName(void)
0040243E  8b 00                                         mov     eax, [eax]
00402440  6a 00                                         push    0; struct CFileException *
00402442  68 11 50 00 00                                push    5011h; unsigned int
00402447  50                                            push    eax; char *
00402448  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0040244B  c6 45 fc 05                                   mov     byte ptr [ebp+var_4], 5
0040244F  e8 06 82 01 00                                call    ?Open@CStdioFile@@UAEHPBDIPAVCFileException@@@Z; CStdioFile::Open(char const *,uint,CFileException *)
00402454  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00402457  8b f0                                         mov     esi, eax
00402459  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
0040245D  e8 a4 81 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00402462  85 f6                                         test    esi, esi
00402464  75 15                                         jnz     short loc_40247B
00402466  56                                            push    esi; unsigned int
00402467  56                                            push    esi; unsigned int
00402468  68 24 f6 41 00                                push    offset byte_41F624; char *
0040246D  e8 a0 81 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00402472  c6 45 fc 06                                   mov     byte ptr [ebp+var_4], 6
00402476  e9 4b 01 00 00                                jmp     loc_4025C6
0040247B  c6 45 fc 07                                   mov     byte ptr [ebp+var_4], 7
0040247F  33 ff                                         xor     edi, edi
00402481  83 ff 32                                      cmp     edi, 32h ; '2'
00402484  7d 57                                         jge     short loc_4024DD
00402486  8b 93 ec 00 00 00                             mov     edx, [ebx+0ECh]
0040248C  8d 34 7f                                      lea     esi, [edi+edi*2]
0040248F  d1 e6                                         shl     esi, 1
00402491  8d 4d ec                                      lea     ecx, [ebp+var_14]
00402494  8b 04 32                                      mov     eax, [edx+esi]
00402497  50                                            push    eax
00402498  68 80 f5 41 00                                push    offset aD; "%d\n"
0040249D  51                                            push    ecx; this
0040249E  e8 69 81 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
004024A3  8b 55 ec                                      mov     edx, [ebp+var_14]
004024A6  83 c4 0c                                      add     esp, 0Ch
004024A9  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004024AC  52                                            push    edx; char *
004024AD  e8 a2 81 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
004024B2  8b 83 ec 00 00 00                             mov     eax, [ebx+0ECh]
004024B8  8d 55 ec                                      lea     edx, [ebp+var_14]
004024BB  8b 4c 30 04                                   mov     ecx, [eax+esi+4]
004024BF  51                                            push    ecx
004024C0  68 80 f5 41 00                                push    offset aD; "%d\n"
004024C5  52                                            push    edx; this
004024C6  e8 41 81 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
004024CB  8b 45 ec                                      mov     eax, [ebp+var_14]
004024CE  83 c4 0c                                      add     esp, 0Ch
004024D1  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004024D4  50                                            push    eax; char *
004024D5  e8 7a 81 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
004024DA  47                                            inc     edi
004024DB  eb a4                                         jmp     short loc_402481
004024DD  33 f6                                         xor     esi, esi
004024DF  83 fe 32                                      cmp     esi, 32h ; '2'
004024E2  0f 8d cb 00 00 00                             jge     loc_4025B3
004024E8  8b 0c f5 48 d9 42 00                          mov     ecx, dword_42D948[esi*8]
004024EF  8d 55 ec                                      lea     edx, [ebp+var_14]
004024F2  51                                            push    ecx
004024F3  68 80 f5 41 00                                push    offset aD; "%d\n"
004024F8  52                                            push    edx; this
004024F9  e8 0e 81 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
004024FE  8b 45 ec                                      mov     eax, [ebp+var_14]
00402501  83 c4 0c                                      add     esp, 0Ch
00402504  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00402507  50                                            push    eax; char *
00402508  e8 47 81 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
0040250D  8b 0c f5 4c d9 42 00                          mov     ecx, dword_42D94C[esi*8]
00402514  8d 55 ec                                      lea     edx, [ebp+var_14]
00402517  51                                            push    ecx
00402518  68 80 f5 41 00                                push    offset aD; "%d\n"
0040251D  52                                            push    edx; this
0040251E  e8 e9 80 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00402523  8b 45 ec                                      mov     eax, [ebp+var_14]
00402526  83 c4 0c                                      add     esp, 0Ch
00402529  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0040252C  50                                            push    eax; char *
0040252D  e8 22 81 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00402532  33 c9                                         xor     ecx, ecx
00402534  8d 55 ec                                      lea     edx, [ebp+var_14]
00402537  8a 8e d8 da 42 00                             mov     cl, byte_42DAD8[esi]
0040253D  51                                            push    ecx
0040253E  68 80 f5 41 00                                push    offset aD; "%d\n"
00402543  52                                            push    edx; this
00402544  e8 c3 80 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00402549  8b 45 ec                                      mov     eax, [ebp+var_14]
0040254C  83 c4 0c                                      add     esp, 0Ch
0040254F  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00402552  50                                            push    eax; char *
00402553  e8 fc 80 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00402558  46                                            inc     esi
00402559  eb 84                                         jmp     short loc_4024DF
0040255B  8b 4d cc                                      mov     ecx, [ebp+var_34]
0040255E  8b 55 c8                                      mov     edx, [ebp+var_38]
00402561  51                                            push    ecx
00402562  52                                            push    edx
00402563  8d 45 ec                                      lea     eax, [ebp+var_14]
00402566  68 04 f6 41 00                                push    offset byte_41F604; char *
0040256B  50                                            push    eax; this
0040256C  c6 45 fc 09                                   mov     byte ptr [ebp+var_4], 9
00402570  e8 97 80 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00402575  8b 4d ec                                      mov     ecx, [ebp+var_14]
00402578  83 c4 10                                      add     esp, 10h
0040257B  6a 00                                         push    0; unsigned int
0040257D  6a 00                                         push    0; unsigned int
0040257F  51                                            push    ecx; char *
00402580  e8 8d 80 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00402585  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00402588  e8 c1 80 01 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
0040258D  c7 45 c0 84 c5 41 00                          mov     [ebp+var_40], offset off_41C584
00402594  8d 4d d0                                      lea     ecx, [ebp+var_30]; this
00402597  c6 45 fc 0a                                   mov     byte ptr [ebp+var_4], 0Ah
0040259B  e8 66 80 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
004025A0  c7 45 c0 70 c5 41 00                          mov     [ebp+var_40], offset off_41C570
004025A7  b8 ad 25 40 00                                mov     eax, offset loc_4025AD
004025AC  c3                                            retn
004025AD  c6 45 fc 0b                                   mov     byte ptr [ebp+var_4], 0Bh
004025B1  eb 13                                         jmp     short loc_4025C6
004025B3  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004025B6  c7 45 fc 02 00 00 00                          mov     [ebp+var_4], 2
004025BD  e8 8c 80 01 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
004025C2  c6 45 fc 0c                                   mov     byte ptr [ebp+var_4], 0Ch
004025C6  8d 8d 44 fe ff ff                             lea     ecx, [ebp+var_1BC]; this
004025CC  e8 35 80 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
004025D1  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
004025D7  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
004025DB  e8 f6 7f 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
004025E0  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
004025E3  c6 45 fc 00                                   mov     byte ptr [ebp+var_4], 0
004025E7  e8 1a 80 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
004025EC  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004025EF  c7 45 fc ff ff ff ff                          mov     [ebp+var_4], 0FFFFFFFFh
004025F6  e8 4d 80 01 00                                call    ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
004025FB  8b 4d f4                                      mov     ecx, [ebp+var_C]
004025FE  5f                                            pop     edi
004025FF  5e                                            pop     esi
00402600  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00402607  5b                                            pop     ebx
00402608  8b e5                                         mov     esp, ebp
0040260A  5d                                            pop     ebp
0040260B  c3                                            retn
0041AC40  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0041AC43  e9 00 fa ff ff                                jmp     ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
0041AC48  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
0041AC4B  e9 b6 f9 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AC50  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AC56  e9 95 6c fe ff                                jmp     sub_4018F0
0041AC5B  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AC61  e9 fa 6d fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AC66  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AC6C  e9 ef 6d fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AC71  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041AC74  e9 8d f9 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AC79  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AC7F  e9 dc 6d fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AC84  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041AC87  e9 44 6d fe ff                                jmp     sub_4019D0
0041AC8C  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041AC8F  e9 0c 6d fe ff                                jmp     sub_4019A0
0041AC94  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AC9A  e9 c1 6d fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AC9F  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041ACA5  e9 b6 6d fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041ACAA  b8 68 d3 41 00                                mov     eax, offset stru_41D368
0041ACAF  e9 68 fb ff ff                                jmp     __CxxFrameHandler
