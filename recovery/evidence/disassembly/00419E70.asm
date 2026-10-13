00419E70  55                                            push    ebp
00419E71  8b ec                                         mov     ebp, esp
00419E73  6a ff                                         push    0FFFFFFFFh
00419E75  68 b0 b2 41 00                                push    offset SEH_419E70
00419E7A  64 a1 00 00 00 00                             mov     eax, large fs:0
00419E80  50                                            push    eax
00419E81  64 89 25 00 00 00 00                          mov     large fs:0, esp
00419E88  83 ec 30                                      sub     esp, 30h
00419E8B  53                                            push    ebx
00419E8C  56                                            push    esi
00419E8D  57                                            push    edi
00419E8E  8b f9                                         mov     edi, ecx
00419E90  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00419E93  89 65 f0                                      mov     [ebp+var_10], esp
00419E96  e8 d7 07 00 00                                call    ??0CStdioFile@@QAE@XZ; CStdioFile::CStdioFile(void)
00419E9B  33 f6                                         xor     esi, esi
00419E9D  8d 4d ec                                      lea     ecx, [ebp+String]; this
00419EA0  89 75 fc                                      mov     [ebp+var_4], esi
00419EA3  e8 76 07 00 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
00419EA8  56                                            push    esi; struct CFileException *
00419EA9  68 20 40 00 00                                push    4020h; unsigned int
00419EAE  68 88 f6 41 00                                push    offset aSan9pkhardskil; "San9PKHardSkill.txt"
00419EB3  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00419EB6  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00419EBA  e8 9b 07 00 00                                call    ?Open@CStdioFile@@UAEHPBDIPAVCFileException@@@Z; CStdioFile::Open(char const *,uint,CFileException *)
00419EBF  85 c0                                         test    eax, eax
00419EC1  0f 84 b3 00 00 00                             jz      loc_419F7A
00419EC7  8b 1d fc c2 41 00                             mov     ebx, ds:atoi; MSVCRT
00419ECD  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
00419ED1  83 fe 27                                      cmp     esi, 27h ; '''
00419ED4  0f 8d 83 00 00 00                             jge     loc_419F5D
00419EDA  8d 45 ec                                      lea     eax, [ebp+String]
00419EDD  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00419EE0  50                                            push    eax; struct CString *
00419EE1  e8 24 09 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419EE6  85 c0                                         test    eax, eax
00419EE8  75 12                                         jnz     short loc_419EFC
00419EEA  50                                            push    eax; unsigned int
00419EEB  50                                            push    eax; unsigned int
00419EEC  68 8c ee 42 00                                push    offset byte_42EE8C; char *
00419EF1  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00419EF5  e8 18 07 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00419EFA  eb 76                                         jmp     short loc_419F72
00419EFC  8b 4d ec                                      mov     ecx, [ebp+String]
00419EFF  51                                            push    ecx; String
00419F00  ff d3                                         call    ebx ; atoi; MSVCRT
00419F02  83 c4 04                                      add     esp, 4
00419F05  89 84 b7 e6 12 00 00                          mov     [edi+esi*4+12E6h], eax
00419F0C  46                                            inc     esi
00419F0D  eb c2                                         jmp     short loc_419ED1
00419F0F  8b 55 d0                                      mov     edx, [ebp+var_30]
00419F12  8b 45 cc                                      mov     eax, [ebp+var_34]
00419F15  52                                            push    edx
00419F16  50                                            push    eax
00419F17  8d 4d ec                                      lea     ecx, [ebp+String]
00419F1A  68 70 ee 42 00                                push    offset byte_42EE70; char *
00419F1F  51                                            push    ecx; this
00419F20  c6 45 fc 04                                   mov     byte ptr [ebp+var_4], 4
00419F24  e8 e3 06 00 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00419F29  8b 55 ec                                      mov     edx, [ebp+String]
00419F2C  83 c4 10                                      add     esp, 10h
00419F2F  6a 00                                         push    0; unsigned int
00419F31  6a 00                                         push    0; unsigned int
00419F33  52                                            push    edx; char *
00419F34  e8 d9 06 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00419F39  c7 45 c4 84 c5 41 00                          mov     [ebp+var_3C], offset off_41C584
00419F40  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419F43  c6 45 fc 05                                   mov     byte ptr [ebp+var_4], 5
00419F47  e8 ba 06 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00419F4C  c6 45 fc 03                                   mov     byte ptr [ebp+var_4], 3
00419F50  c7 45 c4 70 c5 41 00                          mov     [ebp+var_3C], offset off_41C570
00419F57  b8 72 9f 41 00                                mov     eax, offset loc_419F72
00419F5C  c3                                            retn
00419F5D  8a 87 e4 12 00 00                             mov     al, [edi+12E4h]
00419F63  c7 45 fc 01 00 00 00                          mov     [ebp+var_4], 1
00419F6A  0c 01                                         or      al, 1
00419F6C  88 87 e4 12 00 00                             mov     [edi+12E4h], al
00419F72  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00419F75  e8 d4 06 00 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
00419F7A  8d 4d ec                                      lea     ecx, [ebp+String]; this
00419F7D  c6 45 fc 00                                   mov     byte ptr [ebp+var_4], 0
00419F81  e8 80 06 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00419F86  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00419F89  c7 45 fc ff ff ff ff                          mov     [ebp+var_4], 0FFFFFFFFh
00419F90  e8 b3 06 00 00                                call    ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
00419F95  8b 4d f4                                      mov     ecx, [ebp+var_C]
00419F98  5f                                            pop     edi
00419F99  5e                                            pop     esi
00419F9A  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00419FA1  5b                                            pop     ebx
00419FA2  8b e5                                         mov     esp, ebp
00419FA4  5d                                            pop     ebp
00419FA5  c3                                            retn
0041B290  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0041B293  e9 b0 f3 ff ff                                jmp     ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
0041B298  8d 4d ec                                      lea     ecx, [ebp+String]; this
0041B29B  e9 66 f3 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B2A0  8d 4d c4                                      lea     ecx, [ebp+var_3C]
0041B2A3  e9 28 67 fe ff                                jmp     sub_4019D0
0041B2A8  8d 4d c4                                      lea     ecx, [ebp+var_3C]
0041B2AB  e9 f0 66 fe ff                                jmp     sub_4019A0
0041B2B0  b8 e8 db 41 00                                mov     eax, offset stru_41DBE8
0041B2B5  e9 62 f5 ff ff                                jmp     __CxxFrameHandler
