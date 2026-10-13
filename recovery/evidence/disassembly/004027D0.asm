004027D0  55                                            push    ebp
004027D1  8b ec                                         mov     ebp, esp
004027D3  6a ff                                         push    0FFFFFFFFh
004027D5  68 6a ad 41 00                                push    offset SEH_4027D0
004027DA  64 a1 00 00 00 00                             mov     eax, large fs:0
004027E0  50                                            push    eax
004027E1  64 89 25 00 00 00 00                          mov     large fs:0, esp
004027E8  81 ec 60 02 00 00                             sub     esp, 260h
004027EE  53                                            push    ebx
004027EF  56                                            push    esi
004027F0  8b d9                                         mov     ebx, ecx
004027F2  57                                            push    edi
004027F3  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004027F6  89 65 f0                                      mov     [ebp+var_10], esp
004027F9  e8 74 7e 01 00                                call    ??0CStdioFile@@QAE@XZ; CStdioFile::CStdioFile(void)
004027FE  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
00402801  c7 45 fc 00 00 00 00                          mov     [ebp+var_4], 0
00402808  e8 11 7e 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
0040280D  b9 0b 00 00 00                                mov     ecx, 0Bh
00402812  be b0 f5 41 00                                mov     esi, offset aTextFilesTxtTx; "Text Files (*.txt)|*.txt|All Files (*.*"...
00402817  8d 7d 90                                      lea     edi, [ebp+var_70]
0040281A  8d 45 90                                      lea     eax, [ebp+var_70]
0040281D  f3 a5                                         rep movsd
0040281F  53                                            push    ebx; struct CWnd *
00402820  50                                            push    eax; char *
00402821  66 a5                                         movsw
00402823  6a 06                                         push    6; unsigned int
00402825  68 88 f6 41 00                                push    offset aSan9pkhardskil; "San9PKHardSkill.txt"
0040282A  6a 00                                         push    0; char *
0040282C  6a 00                                         push    0; int
0040282E  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
00402834  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00402838  a4                                            movsb
00402839  e8 2e 7e 01 00                                call    ??0CFileDialog@@QAE@HPBD0K0PAVCWnd@@@Z; CFileDialog::CFileDialog(int,char const *,char const *,ulong,char const *,CWnd *)
0040283E  8b cb                                         mov     ecx, ebx
00402840  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
00402844  e8 67 03 00 00                                call    sub_402BB0
00402849  85 c0                                         test    eax, eax
0040284B  75 09                                         jnz     short loc_402856
0040284D  c6 45 fc 03                                   mov     byte ptr [ebp+var_4], 3
00402851  e9 09 01 00 00                                jmp     loc_40295F
00402856  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0040285C  e8 05 7e 01 00                                call    ?DoModal@CFileDialog@@UAEHXZ; CFileDialog::DoModal(void)
00402861  83 f8 01                                      cmp     eax, 1
00402864  74 09                                         jz      short loc_40286F
00402866  c6 45 fc 04                                   mov     byte ptr [ebp+var_4], 4
0040286A  e9 f0 00 00 00                                jmp     loc_40295F
0040286F  8d 4d d4                                      lea     ecx, [ebp+var_2C]
00402872  51                                            push    ecx
00402873  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]
00402879  e8 e2 7d 01 00                                call    ?GetPathName@CFileDialog@@QBE?AVCString@@XZ; CFileDialog::GetPathName(void)
0040287E  8b 00                                         mov     eax, [eax]
00402880  6a 00                                         push    0; struct CFileException *
00402882  68 11 50 00 00                                push    5011h; unsigned int
00402887  50                                            push    eax; char *
00402888  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0040288B  c6 45 fc 05                                   mov     byte ptr [ebp+var_4], 5
0040288F  e8 c6 7d 01 00                                call    ?Open@CStdioFile@@UAEHPBDIPAVCFileException@@@Z; CStdioFile::Open(char const *,uint,CFileException *)
00402894  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00402897  8b f0                                         mov     esi, eax
00402899  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
0040289D  e8 64 7d 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
004028A2  85 f6                                         test    esi, esi
004028A4  75 15                                         jnz     short loc_4028BB
004028A6  56                                            push    esi; unsigned int
004028A7  56                                            push    esi; unsigned int
004028A8  68 70 f6 41 00                                push    offset byte_41F670; char *
004028AD  e8 60 7d 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
004028B2  c6 45 fc 06                                   mov     byte ptr [ebp+var_4], 6
004028B6  e9 a4 00 00 00                                jmp     loc_40295F
004028BB  c6 45 fc 07                                   mov     byte ptr [ebp+var_4], 7
004028BF  33 f6                                         xor     esi, esi
004028C1  83 fe 27                                      cmp     esi, 27h ; '''
004028C4  0f 8d 82 00 00 00                             jge     loc_40294C
004028CA  8b 93 ac 00 00 00                             mov     edx, [ebx+0ACh]
004028D0  8d 4d ec                                      lea     ecx, [ebp+var_14]
004028D3  8b 04 b2                                      mov     eax, [edx+esi*4]
004028D6  50                                            push    eax
004028D7  68 80 f5 41 00                                push    offset aD; "%d\n"
004028DC  51                                            push    ecx; this
004028DD  e8 2a 7d 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
004028E2  8b 55 ec                                      mov     edx, [ebp+var_14]
004028E5  83 c4 0c                                      add     esp, 0Ch
004028E8  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004028EB  52                                            push    edx; char *
004028EC  e8 63 7d 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
004028F1  46                                            inc     esi
004028F2  eb cd                                         jmp     short loc_4028C1
004028F4  8b 45 cc                                      mov     eax, [ebp+var_34]
004028F7  8b 4d c8                                      mov     ecx, [ebp+var_38]
004028FA  50                                            push    eax
004028FB  51                                            push    ecx
004028FC  8d 55 ec                                      lea     edx, [ebp+var_14]
004028FF  68 50 f6 41 00                                push    offset byte_41F650; char *
00402904  52                                            push    edx; this
00402905  c6 45 fc 09                                   mov     byte ptr [ebp+var_4], 9
00402909  e8 fe 7c 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
0040290E  8b 45 ec                                      mov     eax, [ebp+var_14]
00402911  83 c4 10                                      add     esp, 10h
00402914  6a 00                                         push    0; unsigned int
00402916  6a 00                                         push    0; unsigned int
00402918  50                                            push    eax; char *
00402919  e8 f4 7c 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
0040291E  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00402921  e8 28 7d 01 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
00402926  c7 45 c0 84 c5 41 00                          mov     [ebp+var_40], offset off_41C584
0040292D  8d 4d d0                                      lea     ecx, [ebp+var_30]; this
00402930  c6 45 fc 0a                                   mov     byte ptr [ebp+var_4], 0Ah
00402934  e8 cd 7c 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00402939  c7 45 c0 70 c5 41 00                          mov     [ebp+var_40], offset off_41C570
00402940  b8 46 29 40 00                                mov     eax, offset loc_402946
00402945  c3                                            retn
00402946  c6 45 fc 0b                                   mov     byte ptr [ebp+var_4], 0Bh
0040294A  eb 13                                         jmp     short loc_40295F
0040294C  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0040294F  c7 45 fc 02 00 00 00                          mov     [ebp+var_4], 2
00402956  e8 f3 7c 01 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
0040295B  c6 45 fc 0c                                   mov     byte ptr [ebp+var_4], 0Ch
0040295F  8d 8d 44 fe ff ff                             lea     ecx, [ebp+var_1BC]; this
00402965  e8 9c 7c 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
0040296A  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
00402970  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00402974  e8 5d 7c 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
00402979  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
0040297C  c6 45 fc 00                                   mov     byte ptr [ebp+var_4], 0
00402980  e8 81 7c 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00402985  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00402988  c7 45 fc ff ff ff ff                          mov     [ebp+var_4], 0FFFFFFFFh
0040298F  e8 b4 7c 01 00                                call    ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
00402994  8b 4d f4                                      mov     ecx, [ebp+var_C]
00402997  5f                                            pop     edi
00402998  5e                                            pop     esi
00402999  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
004029A0  5b                                            pop     ebx
004029A1  8b e5                                         mov     esp, ebp
004029A3  5d                                            pop     ebp
004029A4  c3                                            retn
0041AD00  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0041AD03  e9 40 f9 ff ff                                jmp     ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
0041AD08  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
0041AD0B  e9 f6 f8 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AD10  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AD16  e9 d5 6b fe ff                                jmp     sub_4018F0
0041AD1B  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AD21  e9 3a 6d fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AD26  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AD2C  e9 2f 6d fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AD31  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041AD34  e9 cd f8 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AD39  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AD3F  e9 1c 6d fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AD44  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041AD47  e9 84 6c fe ff                                jmp     sub_4019D0
0041AD4C  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041AD4F  e9 4c 6c fe ff                                jmp     sub_4019A0
0041AD54  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AD5A  e9 01 6d fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AD5F  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AD65  e9 f6 6c fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AD6A  b8 68 d4 41 00                                mov     eax, offset stru_41D468
0041AD6F  e9 a8 fa ff ff                                jmp     __CxxFrameHandler
