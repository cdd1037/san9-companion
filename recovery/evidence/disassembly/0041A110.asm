0041A110  51                                            push    ecx
0041A111  53                                            push    ebx
0041A112  55                                            push    ebp
0041A113  8b 2d 24 c0 41 00                             mov     ebp, ds:MultiByteToWideChar; KERNEL32
0041A119  56                                            push    esi
0041A11A  57                                            push    edi
0041A11B  8b 7c 24 18                                   mov     edi, [esp+14h+lpMultiByteStr]
0041A11F  6a 00                                         push    0; cchWideChar
0041A121  6a 00                                         push    0; lpWideCharStr
0041A123  6a ff                                         push    0FFFFFFFFh; cbMultiByte
0041A125  57                                            push    edi; lpMultiByteStr
0041A126  6a 00                                         push    0; dwFlags
0041A128  68 b6 03 00 00                                push    3B6h; CodePage
0041A12D  ff d5                                         call    ebp ; MultiByteToWideChar; KERNEL32
0041A12F  8b f0                                         mov     esi, eax
0041A131  8d 44 36 02                                   lea     eax, [esi+esi+2]
0041A135  50                                            push    eax; unsigned int
0041A136  e8 db 06 00 00                                call    ??2@YAPAXI@Z; operator new(uint)
0041A13B  83 c4 04                                      add     esp, 4
0041A13E  8b d8                                         mov     ebx, eax
0041A140  56                                            push    esi; cchWideChar
0041A141  53                                            push    ebx; lpWideCharStr
0041A142  6a ff                                         push    0FFFFFFFFh; cbMultiByte
0041A144  57                                            push    edi; lpMultiByteStr
0041A145  6a 00                                         push    0; dwFlags
0041A147  68 b6 03 00 00                                push    3B6h; CodePage
0041A14C  ff d5                                         call    ebp ; MultiByteToWideChar; KERNEL32
0041A14E  6a 00                                         push    0; lpUsedDefaultChar
0041A150  6a 00                                         push    0; lpDefaultChar
0041A152  6a 00                                         push    0; cbMultiByte
0041A154  6a 00                                         push    0; lpMultiByteStr
0041A156  6a ff                                         push    0FFFFFFFFh; cchWideChar
0041A158  53                                            push    ebx; lpWideCharStr
0041A159  6a 00                                         push    0; dwFlags
0041A15B  68 a8 03 00 00                                push    3A8h; CodePage
0041A160  ff 15 38 c0 41 00                             call    ds:WideCharToMultiByte; KERNEL32
0041A166  8b f0                                         mov     esi, eax
0041A168  8d 7e 01                                      lea     edi, [esi+1]
0041A16B  57                                            push    edi; unsigned int
0041A16C  e8 a5 06 00 00                                call    ??2@YAPAXI@Z; operator new(uint)
0041A171  57                                            push    edi; unsigned int
0041A172  8b e8                                         mov     ebp, eax
0041A174  e8 9d 06 00 00                                call    ??2@YAPAXI@Z; operator new(uint)
0041A179  83 c4 08                                      add     esp, 8
0041A17C  8b f8                                         mov     edi, eax
0041A17E  89 7c 24 10                                   mov     [esp+14h+var_4], edi
0041A182  6a 00                                         push    0; lpUsedDefaultChar
0041A184  6a 00                                         push    0; lpDefaultChar
0041A186  56                                            push    esi; cbMultiByte
0041A187  55                                            push    ebp; lpMultiByteStr
0041A188  6a ff                                         push    0FFFFFFFFh; cchWideChar
0041A18A  53                                            push    ebx; lpWideCharStr
0041A18B  6a 00                                         push    0; dwFlags
0041A18D  68 a8 03 00 00                                push    3A8h; CodePage
0041A192  ff 15 38 c0 41 00                             call    ds:WideCharToMultiByte; KERNEL32
0041A198  56                                            push    esi; cchDest
0041A199  57                                            push    edi; lpDestStr
0041A19A  6a ff                                         push    0FFFFFFFFh; cchSrc
0041A19C  55                                            push    ebp; lpSrcStr
0041A19D  68 00 00 00 02                                push    2000000h; dwMapFlags
0041A1A2  68 04 08 00 00                                push    804h; Locale
0041A1A7  ff 15 1c c0 41 00                             call    ds:LCMapStringA; KERNEL32
0041A1AD  83 c9 ff                                      or      ecx, 0FFFFFFFFh
0041A1B0  33 c0                                         xor     eax, eax
0041A1B2  f2 ae                                         repne scasb
0041A1B4  f7 d1                                         not     ecx
0041A1B6  2b f9                                         sub     edi, ecx
0041A1B8  53                                            push    ebx; void *
0041A1B9  8b d1                                         mov     edx, ecx
0041A1BB  8b f7                                         mov     esi, edi
0041A1BD  8b 7c 24 1c                                   mov     edi, [esp+18h+lpMultiByteStr]
0041A1C1  c1 e9 02                                      shr     ecx, 2
0041A1C4  f3 a5                                         rep movsd
0041A1C6  8b ca                                         mov     ecx, edx
0041A1C8  83 e1 03                                      and     ecx, 3
0041A1CB  f3 a4                                         rep movsb
0041A1CD  e8 16 04 00 00                                call    ??3@YAXPAX@Z; operator delete(void *)
0041A1D2  55                                            push    ebp; void *
0041A1D3  e8 10 04 00 00                                call    ??3@YAXPAX@Z; operator delete(void *)
0041A1D8  8b 44 24 18                                   mov     eax, [esp+1Ch+var_4]
0041A1DC  50                                            push    eax; void *
0041A1DD  e8 06 04 00 00                                call    ??3@YAXPAX@Z; operator delete(void *)
0041A1E2  83 c4 0c                                      add     esp, 0Ch
0041A1E5  5f                                            pop     edi
0041A1E6  5e                                            pop     esi
0041A1E7  5d                                            pop     ebp
0041A1E8  5b                                            pop     ebx
0041A1E9  59                                            pop     ecx
0041A1EA  c3                                            retn
