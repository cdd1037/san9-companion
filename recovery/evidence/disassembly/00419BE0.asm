00419BE0  55                                            push    ebp
00419BE1  8b ec                                         mov     ebp, esp
00419BE3  6a ff                                         push    0FFFFFFFFh
00419BE5  68 84 b2 41 00                                push    offset SEH_419BE0
00419BEA  64 a1 00 00 00 00                             mov     eax, large fs:0
00419BF0  50                                            push    eax
00419BF1  64 89 25 00 00 00 00                          mov     large fs:0, esp
00419BF8  81 ec 60 02 00 00                             sub     esp, 260h
00419BFE  53                                            push    ebx
00419BFF  56                                            push    esi
00419C00  8b d9                                         mov     ebx, ecx
00419C02  57                                            push    edi
00419C03  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419C06  89 65 f0                                      mov     [ebp+var_10], esp
00419C09  89 5d e8                                      mov     [ebp+var_18], ebx
00419C0C  e8 61 0a 00 00                                call    ??0CStdioFile@@QAE@XZ; CStdioFile::CStdioFile(void)
00419C11  68 3c f6 41 00                                push    offset aSan9pkhardcity; "San9PKHardCity.txt"
00419C16  8d 4d ec                                      lea     ecx, [ebp+String]; this
00419C19  c7 45 fc 00 00 00 00                          mov     [ebp+var_4], 0
00419C20  e8 eb 0b 00 00                                call    ??0CString@@QAE@PBD@Z; CString::CString(char const *)
00419C25  b9 0b 00 00 00                                mov     ecx, 0Bh
00419C2A  be b0 f5 41 00                                mov     esi, offset aTextFilesTxtTx; "Text Files (*.txt)|*.txt|All Files (*.*"...
00419C2F  8d 7d 90                                      lea     edi, [ebp+var_70]
00419C32  8d 45 90                                      lea     eax, [ebp+var_70]
00419C35  f3 a5                                         rep movsd
00419C37  8b 4d ec                                      mov     ecx, [ebp+String]
00419C3A  53                                            push    ebx; struct CWnd *
00419C3B  66 a5                                         movsw
00419C3D  50                                            push    eax; char *
00419C3E  6a 04                                         push    4; unsigned int
00419C40  51                                            push    ecx; char *
00419C41  6a 00                                         push    0; char *
00419C43  6a 01                                         push    1; int
00419C45  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
00419C4B  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00419C4F  a4                                            movsb
00419C50  e8 17 0a 00 00                                call    ??0CFileDialog@@QAE@HPBD0K0PAVCWnd@@@Z; CFileDialog::CFileDialog(int,char const *,char const *,ulong,char const *,CWnd *)
00419C55  8a 5d 08                                      mov     bl, [ebp+arg_0]
00419C58  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
00419C5C  84 db                                         test    bl, bl
00419C5E  74 41                                         jz      short loc_419CA1
00419C60  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
00419C66  e8 fb 09 00 00                                call    ?DoModal@CFileDialog@@UAEHXZ; CFileDialog::DoModal(void)
00419C6B  83 f8 01                                      cmp     eax, 1
00419C6E  74 09                                         jz      short loc_419C79
00419C70  c6 45 fc 03                                   mov     byte ptr [ebp+var_4], 3
00419C74  e9 a7 01 00 00                                jmp     loc_419E20
00419C79  8d 55 08                                      lea     edx, [ebp+arg_0]
00419C7C  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]
00419C82  52                                            push    edx
00419C83  e8 d8 09 00 00                                call    ?GetPathName@CFileDialog@@QBE?AVCString@@XZ; CFileDialog::GetPathName(void)
00419C88  50                                            push    eax
00419C89  8d 4d ec                                      lea     ecx, [ebp+String]
00419C8C  c6 45 fc 04                                   mov     byte ptr [ebp+var_4], 4
00419C90  e8 a9 0a 00 00                                call    ??4CString@@QAEABV0@ABV0@@Z; CString::operator=(CString const &)
00419C95  8d 4d 08                                      lea     ecx, [ebp+arg_0]; this
00419C98  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
00419C9C  e8 65 09 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00419CA1  8b 45 ec                                      mov     eax, [ebp+String]
00419CA4  6a 00                                         push    0; struct CFileException *
00419CA6  68 20 40 00 00                                push    4020h; unsigned int
00419CAB  50                                            push    eax; char *
00419CAC  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419CAF  e8 a6 09 00 00                                call    ?Open@CStdioFile@@UAEHPBDIPAVCFileException@@@Z; CStdioFile::Open(char const *,uint,CFileException *)
00419CB4  85 c0                                         test    eax, eax
00419CB6  75 19                                         jnz     short loc_419CD1
00419CB8  84 db                                         test    bl, bl
00419CBA  74 0c                                         jz      short loc_419CC8
00419CBC  50                                            push    eax; unsigned int
00419CBD  50                                            push    eax; unsigned int
00419CBE  68 24 f6 41 00                                push    offset byte_41F624; char *
00419CC3  e8 4a 09 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00419CC8  c6 45 fc 05                                   mov     byte ptr [ebp+var_4], 5
00419CCC  e9 4f 01 00 00                                jmp     loc_419E20
00419CD1  8b 1d fc c2 41 00                             mov     ebx, ds:atoi; MSVCRT
00419CD7  c6 45 fc 06                                   mov     byte ptr [ebp+var_4], 6
00419CDB  33 f6                                         xor     esi, esi
00419CDD  83 fe 32                                      cmp     esi, 32h ; '2'
00419CE0  7d 4f                                         jge     short loc_419D31
00419CE2  8d 4d ec                                      lea     ecx, [ebp+String]
00419CE5  51                                            push    ecx; struct CString *
00419CE6  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419CE9  e8 1c 0b 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419CEE  85 c0                                         test    eax, eax
00419CF0  0f 84 a3 00 00 00                             jz      loc_419D99
00419CF6  8b 45 e8                                      mov     eax, [ebp+var_18]
00419CF9  8b 4d ec                                      mov     ecx, [ebp+String]
00419CFC  8d 14 76                                      lea     edx, [esi+esi*2]
00419CFF  51                                            push    ecx; String
00419D00  8d 3c 50                                      lea     edi, [eax+edx*2]
00419D03  ff d3                                         call    ebx ; atoi; MSVCRT
00419D05  83 c4 04                                      add     esp, 4
00419D08  8d 55 ec                                      lea     edx, [ebp+String]
00419D0B  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419D0E  89 87 44 11 00 00                             mov     [edi+1144h], eax
00419D14  52                                            push    edx; struct CString *
00419D15  e8 f0 0a 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419D1A  85 c0                                         test    eax, eax
00419D1C  74 7b                                         jz      short loc_419D99
00419D1E  8b 45 ec                                      mov     eax, [ebp+String]
00419D21  50                                            push    eax; String
00419D22  ff d3                                         call    ebx ; atoi; MSVCRT
00419D24  83 c4 04                                      add     esp, 4
00419D27  66 89 87 48 11 00 00                          mov     [edi+1148h], ax
00419D2E  46                                            inc     esi
00419D2F  eb ac                                         jmp     short loc_419CDD
00419D31  8b 4d e8                                      mov     ecx, [ebp+var_18]
00419D34  33 f6                                         xor     esi, esi
00419D36  c7 81 40 11 00 00 01 00 00 00                 mov     dword ptr [ecx+1140h], 1
00419D40  83 fe 32                                      cmp     esi, 32h ; '2'
00419D43  0f 8d c4 00 00 00                             jge     loc_419E0D
00419D49  8d 55 ec                                      lea     edx, [ebp+String]
00419D4C  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419D4F  52                                            push    edx; struct CString *
00419D50  e8 b5 0a 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419D55  85 c0                                         test    eax, eax
00419D57  74 40                                         jz      short loc_419D99
00419D59  8b 45 ec                                      mov     eax, [ebp+String]
00419D5C  50                                            push    eax; String
00419D5D  ff d3                                         call    ebx ; atoi; MSVCRT
00419D5F  83 c4 04                                      add     esp, 4
00419D62  8d 4d ec                                      lea     ecx, [ebp+String]
00419D65  89 04 f5 48 d9 42 00                          mov     dword_42D948[esi*8], eax
00419D6C  51                                            push    ecx; struct CString *
00419D6D  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419D70  e8 95 0a 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419D75  85 c0                                         test    eax, eax
00419D77  74 20                                         jz      short loc_419D99
00419D79  8b 55 ec                                      mov     edx, [ebp+String]
00419D7C  52                                            push    edx; String
00419D7D  ff d3                                         call    ebx ; atoi; MSVCRT
00419D7F  83 c4 04                                      add     esp, 4
00419D82  89 04 f5 4c d9 42 00                          mov     dword_42D94C[esi*8], eax
00419D89  8d 45 ec                                      lea     eax, [ebp+String]
00419D8C  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419D8F  50                                            push    eax; struct CString *
00419D90  e8 75 0a 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419D95  85 c0                                         test    eax, eax
00419D97  75 14                                         jnz     short loc_419DAD
00419D99  6a 00                                         push    0; unsigned int
00419D9B  6a 00                                         push    0; unsigned int
00419D9D  68 5c ee 42 00                                push    offset byte_42EE5C; char *
00419DA2  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
00419DA6  e8 67 08 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00419DAB  eb 67                                         jmp     short loc_419E14
00419DAD  8b 4d ec                                      mov     ecx, [ebp+String]
00419DB0  51                                            push    ecx; String
00419DB1  ff d3                                         call    ebx ; atoi; MSVCRT
00419DB3  83 c4 04                                      add     esp, 4
00419DB6  88 86 d8 da 42 00                             mov     byte_42DAD8[esi], al
00419DBC  46                                            inc     esi
00419DBD  eb 81                                         jmp     short loc_419D40
00419DBF  8b 55 cc                                      mov     edx, [ebp+var_34]
00419DC2  8b 45 c8                                      mov     eax, [ebp+var_38]
00419DC5  52                                            push    edx
00419DC6  50                                            push    eax
00419DC7  8d 4d ec                                      lea     ecx, [ebp+String]
00419DCA  68 40 ee 42 00                                push    offset byte_42EE40; char *
00419DCF  51                                            push    ecx; this
00419DD0  c6 45 fc 08                                   mov     byte ptr [ebp+var_4], 8
00419DD4  e8 33 08 00 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00419DD9  8b 55 ec                                      mov     edx, [ebp+String]
00419DDC  83 c4 10                                      add     esp, 10h
00419DDF  6a 00                                         push    0; unsigned int
00419DE1  6a 00                                         push    0; unsigned int
00419DE3  52                                            push    edx; char *
00419DE4  e8 29 08 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00419DE9  c7 45 c0 84 c5 41 00                          mov     [ebp+var_40], offset off_41C584
00419DF0  8d 4d d0                                      lea     ecx, [ebp+var_30]; this
00419DF3  c6 45 fc 09                                   mov     byte ptr [ebp+var_4], 9
00419DF7  e8 0a 08 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00419DFC  c6 45 fc 07                                   mov     byte ptr [ebp+var_4], 7
00419E00  c7 45 c0 70 c5 41 00                          mov     [ebp+var_40], offset off_41C570
00419E07  b8 14 9e 41 00                                mov     eax, offset loc_419E14
00419E0C  c3                                            retn
00419E0D  c7 45 fc 02 00 00 00                          mov     [ebp+var_4], 2
00419E14  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419E17  e8 32 08 00 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
00419E1C  c6 45 fc 0a                                   mov     byte ptr [ebp+var_4], 0Ah
00419E20  8d 8d 44 fe ff ff                             lea     ecx, [ebp+var_1BC]; this
00419E26  e8 db 07 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00419E2B  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
00419E31  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00419E35  e8 9c 07 00 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
00419E3A  8d 4d ec                                      lea     ecx, [ebp+String]; this
00419E3D  c6 45 fc 00                                   mov     byte ptr [ebp+var_4], 0
00419E41  e8 c0 07 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00419E46  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419E49  c7 45 fc ff ff ff ff                          mov     [ebp+var_4], 0FFFFFFFFh
00419E50  e8 f3 07 00 00                                call    ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
00419E55  8b 4d f4                                      mov     ecx, [ebp+var_C]
00419E58  5f                                            pop     edi
00419E59  5e                                            pop     esi
00419E5A  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00419E61  5b                                            pop     ebx
00419E62  8b e5                                         mov     esp, ebp
00419E64  5d                                            pop     ebp
00419E65  c2 04 00                                      retn    4
0041B230  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041B233  e9 10 f4 ff ff                                jmp     ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
0041B238  8d 4d ec                                      lea     ecx, [ebp+String]; this
0041B23B  e9 c6 f3 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B240  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041B246  e9 a5 66 fe ff                                jmp     sub_4018F0
0041B24B  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041B251  e9 0a 68 fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B256  8d 4d 08                                      lea     ecx, [ebp+arg_0]; this
0041B259  e9 a8 f3 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B25E  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041B264  e9 f7 67 fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B269  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041B26C  e9 5f 67 fe ff                                jmp     sub_4019D0
0041B271  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041B274  e9 27 67 fe ff                                jmp     sub_4019A0
0041B279  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041B27F  e9 dc 67 fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B284  b8 48 db 41 00                                mov     eax, offset stru_41DB48
0041B289  e9 8e f5 ff ff                                jmp     __CxxFrameHandler
