00419FB0  55                                            push    ebp
00419FB1  8b ec                                         mov     ebp, esp
00419FB3  6a ff                                         push    0FFFFFFFFh
00419FB5  68 e0 b2 41 00                                push    offset SEH_419FB0
00419FBA  64 a1 00 00 00 00                             mov     eax, large fs:0
00419FC0  50                                            push    eax
00419FC1  64 89 25 00 00 00 00                          mov     large fs:0, esp
00419FC8  83 ec 30                                      sub     esp, 30h
00419FCB  53                                            push    ebx
00419FCC  56                                            push    esi
00419FCD  57                                            push    edi
00419FCE  8b f9                                         mov     edi, ecx
00419FD0  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00419FD3  89 65 f0                                      mov     [ebp+var_10], esp
00419FD6  e8 97 06 00 00                                call    ??0CStdioFile@@QAE@XZ; CStdioFile::CStdioFile(void)
00419FDB  33 f6                                         xor     esi, esi
00419FDD  8d 4d ec                                      lea     ecx, [ebp+String]; this
00419FE0  89 75 fc                                      mov     [ebp+var_4], esi
00419FE3  e8 36 06 00 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
00419FE8  56                                            push    esi; struct CFileException *
00419FE9  68 20 40 00 00                                push    4020h; unsigned int
00419FEE  68 9c f5 41 00                                push    offset aSan9pkhardarra; "San9PKHardArray.txt"
00419FF3  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00419FF6  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00419FFA  e8 5b 06 00 00                                call    ?Open@CStdioFile@@UAEHPBDIPAVCFileException@@@Z; CStdioFile::Open(char const *,uint,CFileException *)
00419FFF  85 c0                                         test    eax, eax
0041A001  0f 84 d5 00 00 00                             jz      loc_41A0DC
0041A007  8b 1d fc c2 41 00                             mov     ebx, ds:atoi; MSVCRT
0041A00D  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
0041A011  83 fe 1b                                      cmp     esi, 1Bh
0041A014  0f 8d a5 00 00 00                             jge     loc_41A0BF
0041A01A  8d 45 ec                                      lea     eax, [ebp+String]
0041A01D  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0041A020  50                                            push    eax; struct CString *
0041A021  e8 e4 07 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041A026  85 c0                                         test    eax, eax
0041A028  74 20                                         jz      short loc_41A04A
0041A02A  8b 4d ec                                      mov     ecx, [ebp+String]
0041A02D  51                                            push    ecx; String
0041A02E  ff d3                                         call    ebx ; atoi; MSVCRT
0041A030  83 c4 04                                      add     esp, 4
0041A033  8d 55 ec                                      lea     edx, [ebp+String]
0041A036  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0041A039  89 84 f7 84 13 00 00                          mov     [edi+esi*8+1384h], eax
0041A040  52                                            push    edx; struct CString *
0041A041  e8 c4 07 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041A046  85 c0                                         test    eax, eax
0041A048  75 14                                         jnz     short loc_41A05E
0041A04A  6a 00                                         push    0; unsigned int
0041A04C  6a 00                                         push    0; unsigned int
0041A04E  68 bc ee 42 00                                push    offset byte_42EEBC; char *
0041A053  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
0041A057  e8 b6 05 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
0041A05C  eb 76                                         jmp     short loc_41A0D4
0041A05E  8b 45 ec                                      mov     eax, [ebp+String]
0041A061  50                                            push    eax; String
0041A062  ff d3                                         call    ebx ; atoi; MSVCRT
0041A064  83 c4 04                                      add     esp, 4
0041A067  89 84 f7 88 13 00 00                          mov     [edi+esi*8+1388h], eax
0041A06E  46                                            inc     esi
0041A06F  eb a0                                         jmp     short loc_41A011
0041A071  8b 4d d0                                      mov     ecx, [ebp+var_30]
0041A074  8b 55 cc                                      mov     edx, [ebp+var_34]
0041A077  51                                            push    ecx
0041A078  52                                            push    edx
0041A079  8d 45 ec                                      lea     eax, [ebp+String]
0041A07C  68 a0 ee 42 00                                push    offset byte_42EEA0; char *
0041A081  50                                            push    eax; this
0041A082  c6 45 fc 04                                   mov     byte ptr [ebp+var_4], 4
0041A086  e8 81 05 00 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
0041A08B  8b 4d ec                                      mov     ecx, [ebp+String]
0041A08E  83 c4 10                                      add     esp, 10h
0041A091  6a 00                                         push    0; unsigned int
0041A093  6a 00                                         push    0; unsigned int
0041A095  51                                            push    ecx; char *
0041A096  e8 77 05 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
0041A09B  c7 45 c4 84 c5 41 00                          mov     [ebp+var_3C], offset off_41C584
0041A0A2  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041A0A5  c6 45 fc 05                                   mov     byte ptr [ebp+var_4], 5
0041A0A9  e8 58 05 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
0041A0AE  c6 45 fc 03                                   mov     byte ptr [ebp+var_4], 3
0041A0B2  c7 45 c4 70 c5 41 00                          mov     [ebp+var_3C], offset off_41C570
0041A0B9  b8 d4 a0 41 00                                mov     eax, offset loc_41A0D4
0041A0BE  c3                                            retn
0041A0BF  8a 87 82 13 00 00                             mov     al, [edi+1382h]
0041A0C5  c7 45 fc 01 00 00 00                          mov     [ebp+var_4], 1
0041A0CC  0c 01                                         or      al, 1
0041A0CE  88 87 82 13 00 00                             mov     [edi+1382h], al
0041A0D4  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0041A0D7  e8 72 05 00 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
0041A0DC  8d 4d ec                                      lea     ecx, [ebp+String]; this
0041A0DF  c6 45 fc 00                                   mov     byte ptr [ebp+var_4], 0
0041A0E3  e8 1e 05 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
0041A0E8  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0041A0EB  c7 45 fc ff ff ff ff                          mov     [ebp+var_4], 0FFFFFFFFh
0041A0F2  e8 51 05 00 00                                call    ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
0041A0F7  8b 4d f4                                      mov     ecx, [ebp+var_C]
0041A0FA  5f                                            pop     edi
0041A0FB  5e                                            pop     esi
0041A0FC  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
0041A103  5b                                            pop     ebx
0041A104  8b e5                                         mov     esp, ebp
0041A106  5d                                            pop     ebp
0041A107  c3                                            retn
0041B2C0  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0041B2C3  e9 80 f3 ff ff                                jmp     ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
0041B2C8  8d 4d ec                                      lea     ecx, [ebp+String]; this
0041B2CB  e9 36 f3 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B2D0  8d 4d c4                                      lea     ecx, [ebp+var_3C]
0041B2D3  e9 f8 66 fe ff                                jmp     sub_4019D0
0041B2D8  8d 4d c4                                      lea     ecx, [ebp+var_3C]
0041B2DB  e9 c0 66 fe ff                                jmp     sub_4019A0
0041B2E0  b8 60 dc 41 00                                mov     eax, offset stru_41DC60
0041B2E5  e9 32 f5 ff ff                                jmp     __CxxFrameHandler
