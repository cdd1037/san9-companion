004029B0  64 a1 00 00 00 00                             mov     eax, large fs:0
004029B6  6a ff                                         push    0FFFFFFFFh
004029B8  68 8b ad 41 00                                push    offset SEH_4029B0
004029BD  50                                            push    eax
004029BE  b8 58 15 00 00                                mov     eax, 1558h
004029C3  64 89 25 00 00 00 00                          mov     large fs:0, esp
004029CA  e8 81 7e 01 00                                call    __alloca_probe
004029CF  53                                            push    ebx
004029D0  56                                            push    esi
004029D1  8b f1                                         mov     esi, ecx
004029D3  e8 4c 7c 01 00                                call    ?OnInitDialog@CDialog@@UAEHXZ; CDialog::OnInitDialog(void)
004029D8  8d 4c 24 08                                   lea     ecx, [esp+156Ch+lParam]; this
004029DC  e8 3d 7c 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
004029E1  33 db                                         xor     ebx, ebx
004029E3  89 9c 24 68 15 00 00                          mov     [esp+156Ch+var_4], ebx
004029EA  e8 29 7c 01 00                                call    ?AfxGetModuleState@@YGPAVAFX_MODULE_STATE@@XZ; AfxGetModuleState(void)
004029EF  8b 40 04                                      mov     eax, [eax+4]
004029F2  8b c8                                         mov     ecx, eax
004029F4  8b 10                                         mov     edx, [eax]
004029F6  ff 52 7c                                      call    dword ptr [edx+7Ch]
004029F9  8d 88 e6 12 00 00                             lea     ecx, [eax+12E6h]
004029FF  89 86 b0 00 00 00                             mov     [esi+0B0h], eax
00402A05  89 8e ac 00 00 00                             mov     [esi+0ACh], ecx
00402A0B  88 9e b4 00 00 00                             mov     [esi+0B4h], bl
00402A11  8b 40 70                                      mov     eax, [eax+70h]
00402A14  3b c3                                         cmp     eax, ebx
00402A16  0f 84 de 00 00 00                             jz      loc_402AFA
00402A1C  53                                            push    ebx; lpNumberOfBytesRead
00402A1D  8d 54 24 10                                   lea     edx, [esp+1570h+Buffer]
00402A21  68 54 15 00 00                                push    1554h; nSize
00402A26  52                                            push    edx; lpBuffer
00402A27  68 d0 da 4f 01                                push    14FDAD0h; lpBaseAddress
00402A2C  50                                            push    eax; hProcess
00402A2D  ff 15 3c c0 41 00                             call    ds:ReadProcessMemory; KERNEL32
00402A33  3b c3                                         cmp     eax, ebx
00402A35  75 11                                         jnz     short loc_402A48
00402A37  53                                            push    ebx; unsigned int
00402A38  53                                            push    ebx; unsigned int
00402A39  68 ac f6 41 00                                push    offset byte_41F6AC; char *
00402A3E  e8 cf 7b 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00402A43  e9 b2 00 00 00                                jmp     loc_402AFA
00402A48  55                                            push    ebp
00402A49  8b 2d 64 c3 41 00                             mov     ebp, ds:SendMessageA; USER32
00402A4F  57                                            push    edi
00402A50  8d 7c 24 24                                   lea     edi, [esp+1574h+MultiByteStr]
00402A54  57                                            push    edi; lpMultiByteStr
00402A55  e8 b6 76 01 00                                call    sub_41A110
00402A5A  57                                            push    edi
00402A5B  53                                            push    ebx
00402A5C  8d 44 24 1c                                   lea     eax, [esp+1580h+lParam]
00402A60  68 20 f5 41 00                                push    offset a02dS; "%02d %s"
00402A65  50                                            push    eax; this
00402A66  e8 a1 7b 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00402A6B  8b 4c 24 24                                   mov     ecx, [esp+1588h+lParam]
00402A6F  8b 96 80 00 00 00                             mov     edx, [esi+80h]
00402A75  83 c4 14                                      add     esp, 14h
00402A78  51                                            push    ecx; lParam
00402A79  6a ff                                         push    0FFFFFFFFh; wParam
00402A7B  68 81 01 00 00                                push    181h; Msg
00402A80  52                                            push    edx; hWnd
00402A81  ff d5                                         call    ebp ; SendMessageA; USER32
00402A83  8b 8e b0 00 00 00                             mov     ecx, [esi+0B0h]
00402A89  f6 81 e4 12 00 00 03                          test    byte ptr [ecx+12E4h], 3
00402A90  75 32                                         jnz     short loc_402AC4
00402A92  83 f8 ff                                      cmp     eax, 0FFFFFFFFh
00402A95  74 3b                                         jz      short loc_402AD2
00402A97  83 f8 fe                                      cmp     eax, 0FFFFFFFEh
00402A9A  74 36                                         jz      short loc_402AD2
00402A9C  8b 96 ac 00 00 00                             mov     edx, [esi+0ACh]
00402AA2  8a 47 54                                      mov     al, [edi+54h]
00402AA5  88 04 9a                                      mov     [edx+ebx*4], al
00402AA8  8b 8e ac 00 00 00                             mov     ecx, [esi+0ACh]
00402AAE  8a 57 6c                                      mov     dl, [edi+6Ch]
00402AB1  88 54 99 01                                   mov     [ecx+ebx*4+1], dl
00402AB5  8b 86 ac 00 00 00                             mov     eax, [esi+0ACh]
00402ABB  66 8b 4f 48                                   mov     cx, [edi+48h]
00402ABF  66 89 4c 98 02                                mov     [eax+ebx*4+2], cx
00402AC4  43                                            inc     ebx
00402AC5  81 c7 8c 00 00 00                             add     edi, 8Ch
00402ACB  83 fb 27                                      cmp     ebx, 27h ; '''
00402ACE  7c 84                                         jl      short loc_402A54
00402AD0  eb 0e                                         jmp     short loc_402AE0
00402AD2  6a 00                                         push    0; unsigned int
00402AD4  6a 00                                         push    0; unsigned int
00402AD6  68 9c f6 41 00                                push    offset byte_41F69C; char *
00402ADB  e8 32 7b 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00402AE0  5f                                            pop     edi
00402AE1  80 fb 27                                      cmp     bl, 27h ; '''
00402AE4  88 9e b4 00 00 00                             mov     [esi+0B4h], bl
00402AEA  5d                                            pop     ebp
00402AEB  75 0d                                         jnz     short loc_402AFA
00402AED  8b 86 b0 00 00 00                             mov     eax, [esi+0B0h]
00402AF3  80 88 e4 12 00 00 02                          or      byte ptr [eax+12E4h], 2
00402AFA  8b ce                                         mov     ecx, esi; this
00402AFC  c6 86 b5 00 00 00 00                          mov     byte ptr [esi+0B5h], 0
00402B03  e8 38 00 00 00                                call    sub_402B40
00402B08  8d 4c 24 08                                   lea     ecx, [esp+156Ch+lParam]; this
00402B0C  c7 84 24 68 15 00 00 ff ff ff ff              mov     [esp+156Ch+var_4], 0FFFFFFFFh
00402B17  e8 ea 7a 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00402B1C  8b 8c 24 60 15 00 00                          mov     ecx, [esp+156Ch+var_C]
00402B23  5e                                            pop     esi
00402B24  b8 01 00 00 00                                mov     eax, 1
00402B29  5b                                            pop     ebx
00402B2A  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00402B31  81 c4 64 15 00 00                             add     esp, 1564h
00402B37  c3                                            retn
0041AD80  8d 8d 9c ea ff ff                             lea     ecx, [ebp-1564h]; this
0041AD86  e9 7b f8 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AD8B  b8 18 d5 41 00                                mov     eax, offset stru_41D518
0041AD90  e9 87 fa ff ff                                jmp     __CxxFrameHandler
