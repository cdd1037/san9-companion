00405530  55                                            push    ebp
00405531  8b ec                                         mov     ebp, esp
00405533  6a ff                                         push    0FFFFFFFFh
00405535  68 e5 b0 41 00                                push    offset SEH_405530
0040553A  64 a1 00 00 00 00                             mov     eax, large fs:0
00405540  50                                            push    eax
00405541  64 89 25 00 00 00 00                          mov     large fs:0, esp
00405548  81 ec 60 02 00 00                             sub     esp, 260h
0040554E  53                                            push    ebx
0040554F  56                                            push    esi
00405550  8b d9                                         mov     ebx, ecx
00405552  57                                            push    edi
00405553  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00405556  89 65 f0                                      mov     [ebp+var_10], esp
00405559  e8 14 51 01 00                                call    ??0CStdioFile@@QAE@XZ; CStdioFile::CStdioFile(void)
0040555E  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
00405561  c7 45 fc 00 00 00 00                          mov     [ebp+var_4], 0
00405568  e8 b1 50 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
0040556D  b9 0b 00 00 00                                mov     ecx, 0Bh
00405572  be b0 f5 41 00                                mov     esi, offset aTextFilesTxtTx; "Text Files (*.txt)|*.txt|All Files (*.*"...
00405577  8d 7d 90                                      lea     edi, [ebp+var_70]
0040557A  8d 45 90                                      lea     eax, [ebp+var_70]
0040557D  f3 a5                                         rep movsd
0040557F  53                                            push    ebx; struct CWnd *
00405580  50                                            push    eax; char *
00405581  66 a5                                         movsw
00405583  6a 06                                         push    6; unsigned int
00405585  68 e8 f7 41 00                                push    offset aSan9pkhardpers; "San9PKHardPerson.txt"
0040558A  6a 00                                         push    0; char *
0040558C  6a 00                                         push    0; int
0040558E  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
00405594  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00405598  a4                                            movsb
00405599  e8 ce 50 01 00                                call    ??0CFileDialog@@QAE@HPBD0K0PAVCWnd@@@Z; CFileDialog::CFileDialog(int,char const *,char const *,ulong,char const *,CWnd *)
0040559E  8b cb                                         mov     ecx, ebx
004055A0  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
004055A4  e8 07 fb ff ff                                call    sub_4050B0
004055A9  85 c0                                         test    eax, eax
004055AB  75 09                                         jnz     short loc_4055B6
004055AD  c6 45 fc 03                                   mov     byte ptr [ebp+var_4], 3
004055B1  e9 a0 01 00 00                                jmp     loc_405756
004055B6  8b cb                                         mov     ecx, ebx
004055B8  e8 c3 fe ff ff                                call    sub_405480
004055BD  85 c0                                         test    eax, eax
004055BF  75 09                                         jnz     short loc_4055CA
004055C1  c6 45 fc 04                                   mov     byte ptr [ebp+var_4], 4
004055C5  e9 8c 01 00 00                                jmp     loc_405756
004055CA  8b 8b 54 7b 00 00                             mov     ecx, [ebx+7B54h]
004055D0  66 8b 93 50 01 00 00                          mov     dx, [ebx+150h]
004055D7  66 89 11                                      mov     [ecx], dx
004055DA  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
004055E0  e8 81 50 01 00                                call    ?DoModal@CFileDialog@@UAEHXZ; CFileDialog::DoModal(void)
004055E5  83 f8 01                                      cmp     eax, 1
004055E8  74 09                                         jz      short loc_4055F3
004055EA  c6 45 fc 05                                   mov     byte ptr [ebp+var_4], 5
004055EE  e9 63 01 00 00                                jmp     loc_405756
004055F3  8d 45 d4                                      lea     eax, [ebp+var_2C]
004055F6  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]
004055FC  50                                            push    eax
004055FD  e8 5e 50 01 00                                call    ?GetPathName@CFileDialog@@QBE?AVCString@@XZ; CFileDialog::GetPathName(void)
00405602  8b 00                                         mov     eax, [eax]
00405604  6a 00                                         push    0; struct CFileException *
00405606  68 11 50 00 00                                push    5011h; unsigned int
0040560B  50                                            push    eax; char *
0040560C  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0040560F  c6 45 fc 06                                   mov     byte ptr [ebp+var_4], 6
00405613  e8 42 50 01 00                                call    ?Open@CStdioFile@@UAEHPBDIPAVCFileException@@@Z; CStdioFile::Open(char const *,uint,CFileException *)
00405618  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0040561B  8b f0                                         mov     esi, eax
0040561D  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
00405621  e8 e0 4f 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00405626  85 f6                                         test    esi, esi
00405628  75 15                                         jnz     short loc_40563F
0040562A  56                                            push    esi; unsigned int
0040562B  56                                            push    esi; unsigned int
0040562C  68 d0 f7 41 00                                push    offset byte_41F7D0; char *
00405631  e8 dc 4f 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00405636  c6 45 fc 07                                   mov     byte ptr [ebp+var_4], 7
0040563A  e9 17 01 00 00                                jmp     loc_405756
0040563F  c6 45 fc 08                                   mov     byte ptr [ebp+var_4], 8
00405643  33 f6                                         xor     esi, esi
00405645  81 fe 20 03 00 00                             cmp     esi, 320h
0040564B  7d 2a                                         jge     short loc_405677
0040564D  8b 8b 54 01 00 00                             mov     ecx, [ebx+154h]
00405653  8d 45 ec                                      lea     eax, [ebp+var_14]
00405656  8b 14 b1                                      mov     edx, [ecx+esi*4]
00405659  52                                            push    edx
0040565A  68 80 f5 41 00                                push    offset aD; "%d\n"
0040565F  50                                            push    eax; this
00405660  e8 a7 4f 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00405665  8b 4d ec                                      mov     ecx, [ebp+var_14]
00405668  83 c4 0c                                      add     esp, 0Ch
0040566B  51                                            push    ecx; char *
0040566C  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0040566F  e8 e0 4f 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00405674  46                                            inc     esi
00405675  eb ce                                         jmp     short loc_405645
00405677  33 f6                                         xor     esi, esi
00405679  83 fe 74                                      cmp     esi, 74h ; 't'
0040567C  7d 49                                         jge     short loc_4056C7
0040567E  8b 83 50 7b 00 00                             mov     eax, [ebx+7B50h]
00405684  8d 14 76                                      lea     edx, [esi+esi*2]
00405687  33 c9                                         xor     ecx, ecx
00405689  66 8b 4c 50 04                                mov     cx, [eax+edx*2+4]
0040568E  8d 04 50                                      lea     eax, [eax+edx*2]
00405691  33 d2                                         xor     edx, edx
00405693  66 8b 50 02                                   mov     dx, [eax+2]
00405697  c1 e1 0a                                      shl     ecx, 0Ah
0040569A  03 ca                                         add     ecx, edx
0040569C  33 d2                                         xor     edx, edx
0040569E  66 8b 10                                      mov     dx, [eax]
004056A1  8d 45 ec                                      lea     eax, [ebp+var_14]
004056A4  c1 e1 0a                                      shl     ecx, 0Ah
004056A7  03 ca                                         add     ecx, edx
004056A9  51                                            push    ecx
004056AA  68 80 f5 41 00                                push    offset aD; "%d\n"
004056AF  50                                            push    eax; this
004056B0  e8 57 4f 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
004056B5  8b 4d ec                                      mov     ecx, [ebp+var_14]
004056B8  83 c4 0c                                      add     esp, 0Ch
004056BB  51                                            push    ecx; char *
004056BC  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004056BF  e8 90 4f 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
004056C4  46                                            inc     esi
004056C5  eb b2                                         jmp     short loc_405679
004056C7  8b 93 50 01 00 00                             mov     edx, [ebx+150h]
004056CD  8d 45 ec                                      lea     eax, [ebp+var_14]
004056D0  52                                            push    edx
004056D1  68 80 f5 41 00                                push    offset aD; "%d\n"
004056D6  50                                            push    eax; this
004056D7  e8 30 4f 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
004056DC  8b 4d ec                                      mov     ecx, [ebp+var_14]
004056DF  83 c4 0c                                      add     esp, 0Ch
004056E2  51                                            push    ecx; char *
004056E3  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004056E6  e8 69 4f 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
004056EB  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004056EE  c7 45 fc 02 00 00 00                          mov     [ebp+var_4], 2
004056F5  e8 54 4f 01 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
004056FA  c6 45 fc 0d                                   mov     byte ptr [ebp+var_4], 0Dh
004056FE  eb 56                                         jmp     short loc_405756
00405700  8b 55 cc                                      mov     edx, [ebp+var_34]
00405703  8b 45 c8                                      mov     eax, [ebp+var_38]
00405706  52                                            push    edx
00405707  50                                            push    eax
00405708  8d 4d ec                                      lea     ecx, [ebp+var_14]
0040570B  68 b0 f7 41 00                                push    offset byte_41F7B0; char *
00405710  51                                            push    ecx; this
00405711  c6 45 fc 0a                                   mov     byte ptr [ebp+var_4], 0Ah
00405715  e8 f2 4e 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
0040571A  8b 55 ec                                      mov     edx, [ebp+var_14]
0040571D  83 c4 10                                      add     esp, 10h
00405720  6a 00                                         push    0; unsigned int
00405722  6a 00                                         push    0; unsigned int
00405724  52                                            push    edx; char *
00405725  e8 e8 4e 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
0040572A  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0040572D  e8 1c 4f 01 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
00405732  c7 45 c0 84 c5 41 00                          mov     [ebp+var_40], offset off_41C584
00405739  8d 4d d0                                      lea     ecx, [ebp+var_30]; this
0040573C  c6 45 fc 0b                                   mov     byte ptr [ebp+var_4], 0Bh
00405740  e8 c1 4e 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00405745  c7 45 c0 70 c5 41 00                          mov     [ebp+var_40], offset off_41C570
0040574C  b8 52 57 40 00                                mov     eax, offset loc_405752
00405751  c3                                            retn
00405752  c6 45 fc 0c                                   mov     byte ptr [ebp+var_4], 0Ch
00405756  8d 8d 44 fe ff ff                             lea     ecx, [ebp+var_1BC]; this
0040575C  e8 a5 4e 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00405761  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
00405767  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
0040576B  e8 66 4e 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
00405770  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
00405773  c6 45 fc 00                                   mov     byte ptr [ebp+var_4], 0
00405777  e8 8a 4e 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
0040577C  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0040577F  c7 45 fc ff ff ff ff                          mov     [ebp+var_4], 0FFFFFFFFh
00405786  e8 bd 4e 01 00                                call    ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
0040578B  8b 4d f4                                      mov     ecx, [ebp+var_C]
0040578E  5f                                            pop     edi
0040578F  5e                                            pop     esi
00405790  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00405797  5b                                            pop     ebx
00405798  8b e5                                         mov     esp, ebp
0040579A  5d                                            pop     ebp
0040579B  c3                                            retn
0041B070  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0041B073  e9 d0 f5 ff ff                                jmp     ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
0041B078  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
0041B07B  e9 86 f5 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B080  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041B086  e9 65 68 fe ff                                jmp     sub_4018F0
0041B08B  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041B091  e9 ca 69 fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B096  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041B09C  e9 bf 69 fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B0A1  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041B0A7  e9 b4 69 fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B0AC  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041B0AF  e9 52 f5 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B0B4  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041B0BA  e9 a1 69 fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B0BF  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041B0C5  e9 96 69 fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B0CA  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041B0CD  e9 fe 68 fe ff                                jmp     sub_4019D0
0041B0D2  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041B0D5  e9 c6 68 fe ff                                jmp     sub_4019A0
0041B0DA  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041B0E0  e9 7b 69 fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B0E5  b8 90 d8 41 00                                mov     eax, offset stru_41D890
0041B0EA  e9 2d f7 ff ff                                jmp     __CxxFrameHandler
