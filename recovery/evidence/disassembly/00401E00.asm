00401E00  64 a1 00 00 00 00                             mov     eax, large fs:0
00401E06  6a ff                                         push    0FFFFFFFFh
00401E08  68 2b ac 41 00                                push    offset SEH_401E00
00401E0D  50                                            push    eax
00401E0E  b8 e4 60 00 00                                mov     eax, 60E4h
00401E13  64 89 25 00 00 00 00                          mov     large fs:0, esp
00401E1A  e8 31 8a 01 00                                call    __alloca_probe
00401E1F  55                                            push    ebp
00401E20  56                                            push    esi
00401E21  8b f1                                         mov     esi, ecx
00401E23  e8 fc 87 01 00                                call    ?OnInitDialog@CDialog@@UAEHXZ; CDialog::OnInitDialog(void)
00401E28  8d 4c 24 08                                   lea     ecx, [esp+60F8h+lParam]; this
00401E2C  e8 ed 87 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
00401E31  33 ed                                         xor     ebp, ebp
00401E33  89 ac 24 f4 60 00 00                          mov     [esp+60F8h+var_4], ebp
00401E3A  e8 d9 87 01 00                                call    ?AfxGetModuleState@@YGPAVAFX_MODULE_STATE@@XZ; AfxGetModuleState(void)
00401E3F  8b 40 04                                      mov     eax, [eax+4]
00401E42  8b c8                                         mov     ecx, eax
00401E44  8b 10                                         mov     edx, [eax]
00401E46  ff 52 7c                                      call    dword ptr [edx+7Ch]
00401E49  8d 88 44 11 00 00                             lea     ecx, [eax+1144h]
00401E4F  89 86 f0 00 00 00                             mov     [esi+0F0h], eax
00401E55  89 8e ec 00 00 00                             mov     [esi+0ECh], ecx
00401E5B  8b 90 3c 11 00 00                             mov     edx, [eax+113Ch]
00401E61  89 96 c4 00 00 00                             mov     [esi+0C4h], edx
00401E67  c6 86 f4 00 00 00 00                          mov     byte ptr [esi+0F4h], 0
00401E6E  8b 40 70                                      mov     eax, [eax+70h]
00401E71  3b c5                                         cmp     eax, ebp
00401E73  0f 84 e6 01 00 00                             jz      loc_40205F
00401E79  55                                            push    ebp; lpNumberOfBytesRead
00401E7A  8d 4c 24 10                                   lea     ecx, [esp+60FCh+Buffer]
00401E7E  68 e0 60 00 00                                push    60E0h; nSize
00401E83  51                                            push    ecx; lpBuffer
00401E84  68 58 db 24 01                                push    124DB58h; lpBaseAddress
00401E89  50                                            push    eax; hProcess
00401E8A  ff 15 3c c0 41 00                             call    ds:ReadProcessMemory; KERNEL32
00401E90  3b c5                                         cmp     eax, ebp
00401E92  75 11                                         jnz     short loc_401EA5
00401E94  55                                            push    ebp; unsigned int
00401E95  55                                            push    ebp; unsigned int
00401E96  68 f0 f5 41 00                                push    offset byte_41F5F0; char *
00401E9B  e8 72 87 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00401EA0  e9 ba 01 00 00                                jmp     loc_40205F
00401EA5  53                                            push    ebx
00401EA6  57                                            push    edi
00401EA7  33 db                                         xor     ebx, ebx
00401EA9  8d 7c 24 34                                   lea     edi, [esp+6100h+MultiByteStr]
00401EAD  57                                            push    edi; lpMultiByteStr
00401EAE  e8 5d 82 01 00                                call    sub_41A110
00401EB3  57                                            push    edi
00401EB4  53                                            push    ebx
00401EB5  8d 54 24 1c                                   lea     edx, [esp+610Ch+lParam]
00401EB9  68 20 f5 41 00                                push    offset a02dS; "%02d %s"
00401EBE  52                                            push    edx; this
00401EBF  e8 48 87 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00401EC4  8b 44 24 24                                   mov     eax, [esp+6114h+lParam]
00401EC8  8b 8e 80 00 00 00                             mov     ecx, [esi+80h]
00401ECE  83 c4 14                                      add     esp, 14h
00401ED1  50                                            push    eax; lParam
00401ED2  6a ff                                         push    0FFFFFFFFh; wParam
00401ED4  68 81 01 00 00                                push    181h; Msg
00401ED9  51                                            push    ecx; hWnd
00401EDA  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
00401EE0  83 f8 ff                                      cmp     eax, 0FFFFFFFFh
00401EE3  0f 84 4b 01 00 00                             jz      loc_402034
00401EE9  83 f8 fe                                      cmp     eax, 0FFFFFFFEh
00401EEC  0f 84 42 01 00 00                             jz      loc_402034
00401EF2  8b 86 c4 00 00 00                             mov     eax, [esi+0C4h]
00401EF8  85 c0                                         test    eax, eax
00401EFA  0f 85 1c 01 00 00                             jnz     loc_40201C
00401F00  8b 96 f0 00 00 00                             mov     edx, [esi+0F0h]
00401F06  8b 82 40 11 00 00                             mov     eax, [edx+1140h]
00401F0C  85 c0                                         test    eax, eax
00401F0E  0f 85 08 01 00 00                             jnz     loc_40201C
00401F14  8b 47 31                                      mov     eax, [edi+31h]
00401F17  33 c9                                         xor     ecx, ecx
00401F19  a8 02                                         test    al, 2
00401F1B  89 86 a0 00 00 00                             mov     [esi+0A0h], eax
00401F21  75 38                                         jnz     short loc_401F5B
00401F23  a8 04                                         test    al, 4
00401F25  b9 01 00 00 00                                mov     ecx, 1
00401F2A  75 2f                                         jnz     short loc_401F5B
00401F2C  a8 08                                         test    al, 8
00401F2E  b9 02 00 00 00                                mov     ecx, 2
00401F33  75 26                                         jnz     short loc_401F5B
00401F35  c1 f8 0f                                      sar     eax, 0Fh
00401F38  89 86 a0 00 00 00                             mov     [esi+0A0h], eax
00401F3E  b9 03 00 00 00                                mov     ecx, 3
00401F43  8b 86 a0 00 00 00                             mov     eax, [esi+0A0h]
00401F49  a8 01                                         test    al, 1
00401F4B  75 0e                                         jnz     short loc_401F5B
00401F4D  d1 f8                                         sar     eax, 1
00401F4F  41                                            inc     ecx
00401F50  89 86 a0 00 00 00                             mov     [esi+0A0h], eax
00401F56  83 f9 0b                                      cmp     ecx, 0Bh
00401F59  7c e8                                         jl      short loc_401F43
00401F5B  8b 86 ec 00 00 00                             mov     eax, [esi+0ECh]
00401F61  88 0c 28                                      mov     [eax+ebp], cl
00401F64  8b 47 34                                      mov     eax, [edi+34h]
00401F67  a8 80                                         test    al, 80h
00401F69  89 86 a0 00 00 00                             mov     [esi+0A0h], eax
00401F6F  74 11                                         jz      short loc_401F82
00401F71  8b 8e ec 00 00 00                             mov     ecx, [esi+0ECh]
00401F77  8d 04 29                                      lea     eax, [ecx+ebp]
00401F7A  8a 0c 29                                      mov     cl, [ecx+ebp]
00401F7D  80 c9 10                                      or      cl, 10h
00401F80  88 08                                         mov     [eax], cl
00401F82  8b 86 a0 00 00 00                             mov     eax, [esi+0A0h]
00401F88  f6 c4 01                                      test    ah, 1
00401F8B  74 11                                         jz      short loc_401F9E
00401F8D  8b 96 ec 00 00 00                             mov     edx, [esi+0ECh]
00401F93  8a 0c 2a                                      mov     cl, [edx+ebp]
00401F96  8d 04 2a                                      lea     eax, [edx+ebp]
00401F99  80 c9 20                                      or      cl, 20h
00401F9C  88 08                                         mov     [eax], cl
00401F9E  8b 87 c0 01 00 00                             mov     eax, [edi+1C0h]
00401FA4  a8 01                                         test    al, 1
00401FA6  89 86 a0 00 00 00                             mov     [esi+0A0h], eax
00401FAC  74 0b                                         jz      short loc_401FB9
00401FAE  8b 86 ec 00 00 00                             mov     eax, [esi+0ECh]
00401FB4  03 c5                                         add     eax, ebp
00401FB6  80 08 80                                      or      byte ptr [eax], 80h
00401FB9  8b 8f a8 01 00 00                             mov     ecx, [edi+1A8h]
00401FBF  b8 1f 85 eb 51                                mov     eax, 51EB851Fh
00401FC4  f7 e9                                         imul    ecx
00401FC6  8b 86 ec 00 00 00                             mov     eax, [esi+0ECh]
00401FCC  c1 fa 05                                      sar     edx, 5
00401FCF  8b ca                                         mov     ecx, edx
00401FD1  c1 e9 1f                                      shr     ecx, 1Fh
00401FD4  03 d1                                         add     edx, ecx
00401FD6  88 54 28 02                                   mov     [eax+ebp+2], dl
00401FDA  8b 8f b4 01 00 00                             mov     ecx, [edi+1B4h]
00401FE0  b8 1f 85 eb 51                                mov     eax, 51EB851Fh
00401FE5  f7 e9                                         imul    ecx
00401FE7  8b 86 ec 00 00 00                             mov     eax, [esi+0ECh]
00401FED  c1 fa 05                                      sar     edx, 5
00401FF0  8b ca                                         mov     ecx, edx
00401FF2  c1 e9 1f                                      shr     ecx, 1Fh
00401FF5  03 d1                                         add     edx, ecx
00401FF7  88 54 28 04                                   mov     [eax+ebp+4], dl
00401FFB  8b 8f b8 01 00 00                             mov     ecx, [edi+1B8h]
00402001  b8 1f 85 eb 51                                mov     eax, 51EB851Fh
00402006  f7 e9                                         imul    ecx
00402008  8b 86 ec 00 00 00                             mov     eax, [esi+0ECh]
0040200E  c1 fa 05                                      sar     edx, 5
00402011  8b ca                                         mov     ecx, edx
00402013  c1 e9 1f                                      shr     ecx, 1Fh
00402016  03 d1                                         add     edx, ecx
00402018  88 54 28 05                                   mov     [eax+ebp+5], dl
0040201C  83 c5 06                                      add     ebp, 6
0040201F  43                                            inc     ebx
00402020  81 c7 f0 01 00 00                             add     edi, 1F0h
00402026  81 fd 2c 01 00 00                             cmp     ebp, 12Ch
0040202C  0f 8c 7b fe ff ff                             jl      loc_401EAD
00402032  eb 0e                                         jmp     short loc_402042
00402034  6a 00                                         push    0; unsigned int
00402036  6a 00                                         push    0; unsigned int
00402038  68 e0 f5 41 00                                push    offset byte_41F5E0; char *
0040203D  e8 d0 85 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00402042  88 9e f4 00 00 00                             mov     [esi+0F4h], bl
00402048  5f                                            pop     edi
00402049  80 fb 32                                      cmp     bl, 32h ; '2'
0040204C  5b                                            pop     ebx
0040204D  75 10                                         jnz     short loc_40205F
0040204F  8b 8e f0 00 00 00                             mov     ecx, [esi+0F0h]
00402055  c7 81 40 11 00 00 01 00 00 00                 mov     dword ptr [ecx+1140h], 1
0040205F  8b ce                                         mov     ecx, esi; this
00402061  c6 86 f5 00 00 00 00                          mov     byte ptr [esi+0F5h], 0
00402068  e8 33 00 00 00                                call    sub_4020A0
0040206D  8d 4c 24 08                                   lea     ecx, [esp+60F8h+lParam]; this
00402071  c7 84 24 f4 60 00 00 ff ff ff ff              mov     [esp+60F8h+var_4], 0FFFFFFFFh
0040207C  e8 85 85 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00402081  8b 8c 24 ec 60 00 00                          mov     ecx, [esp+60F8h+var_C]
00402088  5e                                            pop     esi
00402089  b8 01 00 00 00                                mov     eax, 1
0040208E  5d                                            pop     ebp
0040208F  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00402096  81 c4 f0 60 00 00                             add     esp, 60F0h
0040209C  c3                                            retn
0041AC20  8d 8d 10 9f ff ff                             lea     ecx, [ebp-60F0h]; this
0041AC26  e9 db f9 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AC2B  b8 40 d3 41 00                                mov     eax, offset stru_41D340
0041AC30  e9 e7 fb ff ff                                jmp     __CxxFrameHandler
