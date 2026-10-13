00405820  6a ff                                         push    0FFFFFFFFh
00405822  68 08 b1 41 00                                push    offset SEH_405820
00405827  64 a1 00 00 00 00                             mov     eax, large fs:0
0040582D  50                                            push    eax
0040582E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00405835  83 ec 14                                      sub     esp, 14h
00405838  53                                            push    ebx
00405839  55                                            push    ebp
0040583A  56                                            push    esi
0040583B  8b f1                                         mov     esi, ecx
0040583D  33 ed                                         xor     ebp, ebp
0040583F  57                                            push    edi
00405840  8d 4c 24 14                                   lea     ecx, [esp+30h+var_1C]; this
00405844  89 6c 24 10                                   mov     [esp+30h+var_20], ebp
00405848  e8 d1 4d 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
0040584D  8b ce                                         mov     ecx, esi
0040584F  89 6c 24 2c                                   mov     [esp+30h+var_4], ebp
00405853  89 6c 24 18                                   mov     [esp+30h+var_18], ebp
00405857  e8 54 f8 ff ff                                call    sub_4050B0
0040585C  85 c0                                         test    eax, eax
0040585E  0f 84 83 03 00 00                             jz      loc_405BE7
00405864  ff 15 24 c3 41 00                             call    ds:GetFocus; USER32
0040586A  50                                            push    eax; HWND
0040586B  e8 da 4e 01 00                                call    ?FromHandle@CWnd@@SGPAV1@PAUHWND__@@@Z; CWnd::FromHandle(HWND__ *)
00405870  8b c8                                         mov     ecx, eax; this
00405872  e8 cd 4e 01 00                                call    ?GetDlgCtrlID@CWnd@@QBEHXZ; CWnd::GetDlgCtrlID(void)
00405877  8b d8                                         mov     ebx, eax
00405879  81 fb 13 04 00 00                             cmp     ebx, 413h
0040587F  89 5c 24 1c                                   mov     [esp+30h+var_14], ebx
00405883  0f 85 d5 00 00 00                             jnz     loc_40595E
00405889  8b 86 48 7b 00 00                             mov     eax, [esi+7B48h]
0040588F  8b 1d 0c c3 41 00                             mov     ebx, ds:_mbscmp; MSVCRT
00405895  8d be 48 7b 00 00                             lea     edi, [esi+7B48h]
0040589B  68 48 ef 42 00                                push    offset Str2; Str2
004058A0  50                                            push    eax; Str1
004058A1  ff d3                                         call    ebx ; _mbscmp; MSVCRT
004058A3  83 c4 08                                      add     esp, 8
004058A6  85 c0                                         test    eax, eax
004058A8  74 6b                                         jz      short loc_405915
004058AA  57                                            push    edi
004058AB  8d 8e e0 00 00 00                             lea     ecx, [esi+0E0h]
004058B1  e8 88 4e 01 00                                call    ??4CString@@QAEABV0@ABV0@@Z; CString::operator=(CString const &)
004058B6  8b 5c 24 1c                                   mov     ebx, [esp+30h+var_14]
004058BA  8b 86 58 01 00 00                             mov     eax, [esi+158h]
004058C0  8b 8e 5c 01 00 00                             mov     ecx, [esi+15Ch]
004058C6  8d 78 01                                      lea     edi, [eax+1]
004058C9  3b f9                                         cmp     edi, ecx
004058CB  72 02                                         jb      short loc_4058CF
004058CD  33 ff                                         xor     edi, edi
004058CF  3b f8                                         cmp     edi, eax
004058D1  0f 84 fb 02 00 00                             jz      loc_405BD2
004058D7  81 fb 13 04 00 00                             cmp     ebx, 413h
004058DD  0f 85 c8 01 00 00                             jnz     loc_405AAB
004058E3  8d 14 bf                                      lea     edx, [edi+edi*4]
004058E6  8d 4c 24 14                                   lea     ecx, [esp+30h+var_1C]
004058EA  8d 84 56 60 01 00 00                          lea     eax, [esi+edx*2+160h]
004058F1  50                                            push    eax
004058F2  e8 f3 4d 01 00                                call    ??4CString@@QAEABV0@PBD@Z; CString::operator=(char const *)
004058F7  8b 86 e0 00 00 00                             mov     eax, [esi+0E0h]
004058FD  8d 4c 24 14                                   lea     ecx, [esp+30h+var_1C]; this
00405901  50                                            push    eax; char *
00405902  e8 31 4e 01 00                                call    ?Find@CString@@QBEHPBD@Z; CString::Find(char const *)
00405907  83 f8 ff                                      cmp     eax, 0FFFFFFFFh
0040590A  0f 85 60 02 00 00                             jnz     loc_405B70
00405910  e9 40 02 00 00                                jmp     loc_405B55
00405915  8d be e0 00 00 00                             lea     edi, [esi+0E0h]
0040591B  8d 44 24 20                                   lea     eax, [esp+30h+var_10]
0040591F  6a 04                                         push    4
00405921  50                                            push    eax
00405922  8b cf                                         mov     ecx, edi
00405924  e8 09 4e 01 00                                call    ?Left@CString@@QBE?AV1@H@Z; CString::Left(int)
00405929  50                                            push    eax
0040592A  8b cf                                         mov     ecx, edi
0040592C  c6 44 24 30 01                                mov     byte ptr [esp+34h+var_4], 1
00405931  e8 08 4e 01 00                                call    ??4CString@@QAEABV0@ABV0@@Z; CString::operator=(CString const &)
00405936  8d 4c 24 20                                   lea     ecx, [esp+30h+var_10]; this
0040593A  c6 44 24 2c 00                                mov     byte ptr [esp+30h+var_4], 0
0040593F  e8 c2 4c 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00405944  8b 3f                                         mov     edi, [edi]
00405946  68 48 ef 42 00                                push    offset Str2; Str2
0040594B  57                                            push    edi; Str1
0040594C  ff d3                                         call    ebx ; _mbscmp; MSVCRT
0040594E  83 c4 08                                      add     esp, 8
00405951  85 c0                                         test    eax, eax
00405953  0f 85 5d ff ff ff                             jnz     loc_4058B6
00405959  e9 89 02 00 00                                jmp     loc_405BE7
0040595E  81 fb 6f 04 00 00                             cmp     ebx, 46Fh
00405964  75 4d                                         jnz     short loc_4059B3
00405966  8d 4c 24 20                                   lea     ecx, [esp+30h+var_10]
0040596A  8d be 4c 01 00 00                             lea     edi, [esi+14Ch]
00405970  6a 04                                         push    4
00405972  51                                            push    ecx
00405973  8b cf                                         mov     ecx, edi
00405975  e8 b8 4d 01 00                                call    ?Left@CString@@QBE?AV1@H@Z; CString::Left(int)
0040597A  50                                            push    eax
0040597B  8b cf                                         mov     ecx, edi
0040597D  c6 44 24 30 02                                mov     byte ptr [esp+34h+var_4], 2
00405982  e8 b7 4d 01 00                                call    ??4CString@@QAEABV0@ABV0@@Z; CString::operator=(CString const &)
00405987  8d 4c 24 20                                   lea     ecx, [esp+30h+var_10]; this
0040598B  c6 44 24 2c 00                                mov     byte ptr [esp+30h+var_4], 0
00405990  e8 71 4c 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00405995  8b 3f                                         mov     edi, [edi]
00405997  68 48 ef 42 00                                push    offset Str2; Str2
0040599C  57                                            push    edi; Str1
0040599D  ff 15 0c c3 41 00                             call    ds:_mbscmp; MSVCRT
004059A3  83 c4 08                                      add     esp, 8
004059A6  85 c0                                         test    eax, eax
004059A8  0f 85 0c ff ff ff                             jnz     loc_4058BA
004059AE  e9 34 02 00 00                                jmp     loc_405BE7
004059B3  81 fb 44 04 00 00                             cmp     ebx, 444h
004059B9  74 1d                                         jz      short loc_4059D8
004059BB  81 fb 46 04 00 00                             cmp     ebx, 446h
004059C1  74 38                                         jz      short loc_4059FB
004059C3  81 fb 45 04 00 00                             cmp     ebx, 445h
004059C9  74 28                                         jz      short loc_4059F3
004059CB  81 fb 47 04 00 00                             cmp     ebx, 447h
004059D1  74 20                                         jz      short loc_4059F3
004059D3  e9 0f 02 00 00                                jmp     loc_405BE7
004059D8  8a 86 4c 7b 00 00                             mov     al, [esi+7B4Ch]
004059DE  3c ff                                         cmp     al, 0FFh
004059E0  75 06                                         jnz     short loc_4059E8
004059E2  8a 86 08 01 00 00                             mov     al, [esi+108h]
004059E8  25 ff 00 00 00                                and     eax, 0FFh
004059ED  89 44 24 10                                   mov     [esp+30h+var_20], eax
004059F1  eb 55                                         jmp     short loc_405A48
004059F3  81 fb 46 04 00 00                             cmp     ebx, 446h
004059F9  75 12                                         jnz     short loc_405A0D
004059FB  8a 86 4e 7b 00 00                             mov     al, [esi+7B4Eh]
00405A01  3c ff                                         cmp     al, 0FFh
00405A03  75 3a                                         jnz     short loc_405A3F
00405A05  8a 86 09 01 00 00                             mov     al, [esi+109h]
00405A0B  eb 32                                         jmp     short loc_405A3F
00405A0D  81 fb 45 04 00 00                             cmp     ebx, 445h
00405A13  75 12                                         jnz     short loc_405A27
00405A15  8a 86 4d 7b 00 00                             mov     al, [esi+7B4Dh]
00405A1B  3c ff                                         cmp     al, 0FFh
00405A1D  75 20                                         jnz     short loc_405A3F
00405A1F  8a 86 0a 01 00 00                             mov     al, [esi+10Ah]
00405A25  eb 18                                         jmp     short loc_405A3F
00405A27  81 fb 47 04 00 00                             cmp     ebx, 447h
00405A2D  75 6f                                         jnz     short loc_405A9E
00405A2F  8a 86 4f 7b 00 00                             mov     al, [esi+7B4Fh]
00405A35  3c ff                                         cmp     al, 0FFh
00405A37  75 06                                         jnz     short loc_405A3F
00405A39  8a 86 0b 01 00 00                             mov     al, [esi+10Bh]
00405A3F  25 ff 00 00 00                                and     eax, 0FFh
00405A44  89 44 24 10                                   mov     [esp+30h+var_20], eax
00405A48  83 f8 5a                                      cmp     eax, 5Ah ; 'Z'
00405A4B  76 0d                                         jbe     short loc_405A5A
00405A4D  c7 44 24 18 02 00 00 00                       mov     [esp+30h+var_18], 2
00405A55  e9 60 fe ff ff                                jmp     loc_4058BA
00405A5A  83 f8 50                                      cmp     eax, 50h ; 'P'
00405A5D  76 0d                                         jbe     short loc_405A6C
00405A5F  c7 44 24 18 01 00 00 00                       mov     [esp+30h+var_18], 1
00405A67  e9 4e fe ff ff                                jmp     loc_4058BA
00405A6C  83 f8 3c                                      cmp     eax, 3Ch ; '<'
00405A6F  76 09                                         jbe     short loc_405A7A
00405A71  89 6c 24 18                                   mov     [esp+30h+var_18], ebp
00405A75  e9 40 fe ff ff                                jmp     loc_4058BA
00405A7A  83 f8 32                                      cmp     eax, 32h ; '2'
00405A7D  76 0d                                         jbe     short loc_405A8C
00405A7F  c7 44 24 18 01 00 00 00                       mov     [esp+30h+var_18], 1
00405A87  e9 2e fe ff ff                                jmp     loc_4058BA
00405A8C  83 f8 1e                                      cmp     eax, 1Eh
00405A8F  76 0d                                         jbe     short loc_405A9E
00405A91  c7 44 24 18 02 00 00 00                       mov     [esp+30h+var_18], 2
00405A99  e9 1c fe ff ff                                jmp     loc_4058BA
00405A9E  c7 44 24 18 05 00 00 00                       mov     [esp+30h+var_18], 5
00405AA6  e9 0f fe ff ff                                jmp     loc_4058BA
00405AAB  81 fb 6f 04 00 00                             cmp     ebx, 46Fh
00405AB1  75 34                                         jnz     short loc_405AE7
00405AB3  0f be 8c 37 a0 20 00 00                       movsx   ecx, byte ptr [edi+esi+20A0h]
00405ABB  8d 14 cd 28 f7 41 00                          lea     edx, ds:41F728h[ecx*8]
00405AC2  8d 4c 24 14                                   lea     ecx, [esp+30h+var_1C]
00405AC6  52                                            push    edx
00405AC7  e8 1e 4c 01 00                                call    ??4CString@@QAEABV0@PBD@Z; CString::operator=(char const *)
00405ACC  8b 86 4c 01 00 00                             mov     eax, [esi+14Ch]
00405AD2  8d 4c 24 14                                   lea     ecx, [esp+30h+var_1C]; this
00405AD6  50                                            push    eax; char *
00405AD7  e8 5c 4c 01 00                                call    ?Find@CString@@QBEHPBD@Z; CString::Find(char const *)
00405ADC  83 f8 ff                                      cmp     eax, 0FFFFFFFFh
00405ADF  0f 85 ed 00 00 00                             jnz     loc_405BD2
00405AE5  eb 6e                                         jmp     short loc_405B55
00405AE7  81 fb 44 04 00 00                             cmp     ebx, 444h
00405AED  74 2a                                         jz      short loc_405B19
00405AEF  81 fb 46 04 00 00                             cmp     ebx, 446h
00405AF5  74 18                                         jz      short loc_405B0F
00405AF7  81 fb 45 04 00 00                             cmp     ebx, 445h
00405AFD  74 08                                         jz      short loc_405B07
00405AFF  81 fb 47 04 00 00                             cmp     ebx, 447h
00405B05  75 4e                                         jnz     short loc_405B55
00405B07  81 fb 46 04 00 00                             cmp     ebx, 446h
00405B0D  75 14                                         jnz     short loc_405B23
00405B0F  0f be ac 37 00 2a 00 00                       movsx   ebp, byte ptr [edi+esi+2A00h]
00405B17  eb 2c                                         jmp     short loc_405B45
00405B19  0f be ac 37 c0 23 00 00                       movsx   ebp, byte ptr [edi+esi+23C0h]
00405B21  eb 22                                         jmp     short loc_405B45
00405B23  81 fb 45 04 00 00                             cmp     ebx, 445h
00405B29  75 0a                                         jnz     short loc_405B35
00405B2B  0f be ac 37 e0 26 00 00                       movsx   ebp, byte ptr [edi+esi+26E0h]
00405B33  eb 10                                         jmp     short loc_405B45
00405B35  81 fb 47 04 00 00                             cmp     ebx, 447h
00405B3B  75 0c                                         jnz     short loc_405B49
00405B3D  0f be ac 37 20 2d 00 00                       movsx   ebp, byte ptr [edi+esi+2D20h]
00405B45  2b 6c 24 10                                   sub     ebp, [esp+30h+var_20]
00405B49  85 ed                                         test    ebp, ebp
00405B4B  7d 02                                         jge     short loc_405B4F
00405B4D  f7 dd                                         neg     ebp
00405B4F  3b 6c 24 18                                   cmp     ebp, [esp+30h+var_18]
00405B53  7e 2f                                         jle     short loc_405B84
00405B55  8b 86 5c 01 00 00                             mov     eax, [esi+15Ch]
00405B5B  47                                            inc     edi
00405B5C  3b f8                                         cmp     edi, eax
00405B5E  72 02                                         jb      short loc_405B62
00405B60  33 ff                                         xor     edi, edi
00405B62  3b be 58 01 00 00                             cmp     edi, [esi+158h]
00405B68  0f 85 69 fd ff ff                             jnz     loc_4058D7
00405B6E  eb 62                                         jmp     short loc_405BD2
00405B70  8d 86 e0 00 00 00                             lea     eax, [esi+0E0h]
00405B76  8d 8e 48 7b 00 00                             lea     ecx, [esi+7B48h]
00405B7C  50                                            push    eax
00405B7D  e8 bc 4b 01 00                                call    ??4CString@@QAEABV0@ABV0@@Z; CString::operator=(CString const &)
00405B82  eb 4e                                         jmp     short loc_405BD2
00405B84  81 fb 44 04 00 00                             cmp     ebx, 444h
00405B8A  75 0c                                         jnz     short loc_405B98
00405B8C  8a 4c 24 10                                   mov     cl, byte ptr [esp+30h+var_20]
00405B90  88 8e 4c 7b 00 00                             mov     [esi+7B4Ch], cl
00405B96  eb 3a                                         jmp     short loc_405BD2
00405B98  81 fb 46 04 00 00                             cmp     ebx, 446h
00405B9E  75 0c                                         jnz     short loc_405BAC
00405BA0  8a 54 24 10                                   mov     dl, byte ptr [esp+30h+var_20]
00405BA4  88 96 4e 7b 00 00                             mov     [esi+7B4Eh], dl
00405BAA  eb 26                                         jmp     short loc_405BD2
00405BAC  81 fb 45 04 00 00                             cmp     ebx, 445h
00405BB2  75 0c                                         jnz     short loc_405BC0
00405BB4  8a 44 24 10                                   mov     al, byte ptr [esp+30h+var_20]
00405BB8  88 86 4d 7b 00 00                             mov     [esi+7B4Dh], al
00405BBE  eb 12                                         jmp     short loc_405BD2
00405BC0  81 fb 47 04 00 00                             cmp     ebx, 447h
00405BC6  75 0a                                         jnz     short loc_405BD2
00405BC8  8a 4c 24 10                                   mov     cl, byte ptr [esp+30h+var_20]
00405BCC  88 8e 4f 7b 00 00                             mov     [esi+7B4Fh], cl
00405BD2  39 be 58 01 00 00                             cmp     [esi+158h], edi
00405BD8  74 0d                                         jz      short loc_405BE7
00405BDA  8b ce                                         mov     ecx, esi; this
00405BDC  89 be 58 01 00 00                             mov     [esi+158h], edi
00405BE2  e8 49 f5 ff ff                                call    sub_405130
00405BE7  8d 4c 24 14                                   lea     ecx, [esp+30h+var_1C]; this
00405BEB  c7 44 24 2c ff ff ff ff                       mov     [esp+30h+var_4], 0FFFFFFFFh
00405BF3  e8 0e 4a 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00405BF8  8b 4c 24 24                                   mov     ecx, [esp+30h+var_C]
00405BFC  5f                                            pop     edi
00405BFD  5e                                            pop     esi
00405BFE  5d                                            pop     ebp
00405BFF  5b                                            pop     ebx
00405C00  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00405C07  83 c4 20                                      add     esp, 20h
00405C0A  c3                                            retn
0041B0F0  8d 4d e4                                      lea     ecx, [ebp-1Ch]; this
0041B0F3  e9 0e f5 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B0F8  8d 4d f0                                      lea     ecx, [ebp-10h]; this
0041B0FB  e9 06 f5 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B100  8d 4d f0                                      lea     ecx, [ebp-10h]; this
0041B103  e9 fe f4 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B108  b8 48 d9 41 00                                mov     eax, offset stru_41D948
0041B10D  e9 0a f7 ff ff                                jmp     __CxxFrameHandler
