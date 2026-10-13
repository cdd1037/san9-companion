00404910  6a ff                                         push    0FFFFFFFFh
00404912  64 a1 00 00 00 00                             mov     eax, large fs:0
00404918  68 5b b0 41 00                                push    offset loc_41B05B
0040491D  50                                            push    eax
0040491E  b8 50 9d 03 00                                mov     eax, 39D50h
00404923  64 89 25 00 00 00 00                          mov     large fs:0, esp
0040492A  e8 21 5f 01 00                                call    __alloca_probe
0040492F  53                                            push    ebx
00404930  55                                            push    ebp
00404931  56                                            push    esi
00404932  57                                            push    edi
00404933  8b f9                                         mov     edi, ecx
00404935  e8 ea 5c 01 00                                call    ?OnInitDialog@CDialog@@UAEHXZ; CDialog::OnInitDialog(void)
0040493A  8d 4c 24 14                                   lea     ecx, [esp+39D6Ch+lParam]; this
0040493E  e8 db 5c 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
00404943  33 db                                         xor     ebx, ebx
00404945  89 9c 24 68 9d 03 00                          mov     [esp+39D6Ch+var_4], ebx
0040494C  e8 c7 5c 01 00                                call    ?AfxGetModuleState@@YGPAVAFX_MODULE_STATE@@XZ; AfxGetModuleState(void)
00404951  8b 40 04                                      mov     eax, [eax+4]
00404954  8b c8                                         mov     ecx, eax
00404956  8b 10                                         mov     edx, [eax]
00404958  ff 52 7c                                      call    dword ptr [edx+7Ch]
0040495B  8b f0                                         mov     esi, eax
0040495D  89 9f 5c 01 00 00                             mov     [edi+15Ch], ebx
00404963  89 74 24 20                                   mov     [esp+39D6Ch+var_39D4C], esi
00404967  8d 86 f4 01 00 00                             lea     eax, [esi+1F4h]
0040496D  89 87 54 01 00 00                             mov     [edi+154h], eax
00404973  8b 46 70                                      mov     eax, [esi+70h]
00404976  3b c3                                         cmp     eax, ebx
00404978  0f 84 b1 01 00 00                             jz      loc_404B2F
0040497E  53                                            push    ebx; lpNumberOfBytesRead
0040497F  8d 4c 24 64                                   lea     ecx, [esp+39D70h+Buffer]
00404983  68 00 9d 03 00                                push    39D00h; nSize
00404988  51                                            push    ecx; lpBuffer
00404989  68 e0 8e 25 01                                push    1258EE0h; lpBaseAddress
0040498E  50                                            push    eax; hProcess
0040498F  ff 15 3c c0 41 00                             call    ds:ReadProcessMemory; KERNEL32
00404995  3b c3                                         cmp     eax, ebx
00404997  75 11                                         jnz     short loc_4049AA
00404999  53                                            push    ebx; unsigned int
0040499A  53                                            push    ebx; unsigned int
0040499B  68 98 f7 41 00                                push    offset byte_41F798; char *
004049A0  e8 6d 5c 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
004049A5  e9 85 01 00 00                                jmp     loc_404B2F
004049AA  8d 97 60 01 00 00                             lea     edx, [edi+160h]
004049B0  8d 87 c0 6e 00 00                             lea     eax, [edi+6EC0h]
004049B6  8d 8f 40 30 00 00                             lea     ecx, [edi+3040h]
004049BC  89 54 24 10                                   mov     [esp+39D6Ch+lpMultiByteStr], edx
004049C0  89 44 24 18                                   mov     [esp+39D6Ch+var_39D54], eax
004049C4  8d af 82 36 00 00                             lea     ebp, [edi+3682h]
004049CA  89 4c 24 1c                                   mov     [esp+39D6Ch+var_39D50], ecx
004049CE  8d b4 24 12 01 00 00                          lea     esi, [esp+39D6Ch+var_39C5A]
004049D5  8b 4c 24 10                                   mov     ecx, [esp+39D6Ch+lpMultiByteStr]
004049D9  8d 96 63 ff ff ff                             lea     edx, [esi-9Dh]
004049DF  8d 86 5e ff ff ff                             lea     eax, [esi-0A2h]
004049E5  52                                            push    edx
004049E6  50                                            push    eax
004049E7  68 20 f7 41 00                                push    offset Format; "%s%s"
004049EC  51                                            push    ecx; Buffer
004049ED  ff 15 08 c3 41 00                             call    ds:sprintf; MSVCRT
004049F3  8b 54 24 20                                   mov     edx, [esp+39D7Ch+lpMultiByteStr]
004049F7  52                                            push    edx; lpMultiByteStr
004049F8  e8 13 57 01 00                                call    sub_41A110
004049FD  8a 46 d2                                      mov     al, [esi-2Eh]
00404A00  83 c4 14                                      add     esp, 14h
00404A03  84 c0                                         test    al, al
00404A05  88 84 1f a0 20 00 00                          mov     [edi+ebx+20A0h], al
00404A0C  7c 04                                         jl      short loc_404A12
00404A0E  3c 0a                                         cmp     al, 0Ah
00404A10  7e 08                                         jle     short loc_404A1A
00404A12  c6 84 1f a0 20 00 00 0a                       mov     byte ptr [edi+ebx+20A0h], 0Ah
00404A1A  8a 46 b2                                      mov     al, [esi-4Eh]
00404A1D  8a 4e 9a                                      mov     cl, [esi-66h]
00404A20  8a 56 a2                                      mov     dl, [esi-5Eh]
00404A23  88 84 1f c0 23 00 00                          mov     [edi+ebx+23C0h], al
00404A2A  8a 46 aa                                      mov     al, [esi-56h]
00404A2D  88 8c 1f e0 26 00 00                          mov     [edi+ebx+26E0h], cl
00404A34  66 8b 4e 36                                   mov     cx, [esi+36h]
00404A38  88 94 1f 00 2a 00 00                          mov     [edi+ebx+2A00h], dl
00404A3F  8b 54 24 1c                                   mov     edx, [esp+39D6Ch+var_39D50]
00404A43  88 84 1f 20 2d 00 00                          mov     [edi+ebx+2D20h], al
00404A4A  66 8b 46 f2                                   mov     ax, [esi-0Eh]
00404A4E  66 c1 f9 03                                   sar     cx, 3
00404A52  66 89 0a                                      mov     [edx], cx
00404A55  66 8b 4e f4                                   mov     cx, [esi-0Ch]
00404A59  66 8b 56 f6                                   mov     dx, [esi-0Ah]
00404A5D  66 89 45 fe                                   mov     [ebp-2], ax
00404A61  66 8b 46 f8                                   mov     ax, [esi-8]
00404A65  66 89 4d 00                                   mov     [ebp+0], cx
00404A69  66 8b 4e fa                                   mov     cx, [esi-6]
00404A6D  66 89 55 02                                   mov     [ebp+2], dx
00404A71  66 8b 56 fc                                   mov     dx, [esi-4]
00404A75  66 89 45 04                                   mov     [ebp+4], ax
00404A79  66 8b 46 fe                                   mov     ax, [esi-2]
00404A7D  66 89 4d 06                                   mov     [ebp+6], cx
00404A81  66 8b 0e                                      mov     cx, [esi]
00404A84  66 89 55 08                                   mov     [ebp+8], dx
00404A88  66 8b 56 02                                   mov     dx, [esi+2]
00404A8C  66 89 45 0a                                   mov     [ebp+0Ah], ax
00404A90  8b 46 4e                                      mov     eax, [esi+4Eh]
00404A93  66 89 4d 0c                                   mov     [ebp+0Ch], cx
00404A97  8b 4c 24 18                                   mov     ecx, [esp+39D6Ch+var_39D54]
00404A9B  66 89 55 0e                                   mov     [ebp+0Eh], dx
00404A9F  8b 54 24 10                                   mov     edx, [esp+39D6Ch+lpMultiByteStr]
00404AA3  89 01                                         mov     [ecx], eax
00404AA5  52                                            push    edx
00404AA6  53                                            push    ebx
00404AA7  8d 44 24 1c                                   lea     eax, [esp+39D74h+lParam]
00404AAB  68 90 f7 41 00                                push    offset a03dS; "%03d %s"
00404AB0  50                                            push    eax; this
00404AB1  e8 56 5b 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00404AB6  8b 4c 24 24                                   mov     ecx, [esp+39D7Ch+lParam]
00404ABA  8b 97 80 00 00 00                             mov     edx, [edi+80h]
00404AC0  83 c4 10                                      add     esp, 10h
00404AC3  51                                            push    ecx; lParam
00404AC4  6a ff                                         push    0FFFFFFFFh; wParam
00404AC6  68 81 01 00 00                                push    181h; Msg
00404ACB  52                                            push    edx; hWnd
00404ACC  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
00404AD2  83 f8 ff                                      cmp     eax, 0FFFFFFFFh
00404AD5  74 3e                                         jz      short loc_404B15
00404AD7  83 f8 fe                                      cmp     eax, 0FFFFFFFEh
00404ADA  74 39                                         jz      short loc_404B15
00404ADC  8b 4c 24 18                                   mov     ecx, [esp+39D6Ch+var_39D54]
00404AE0  8b 54 24 1c                                   mov     edx, [esp+39D6Ch+var_39D50]
00404AE4  83 c1 04                                      add     ecx, 4
00404AE7  43                                            inc     ebx
00404AE8  89 4c 24 18                                   mov     [esp+39D6Ch+var_39D54], ecx
00404AEC  8b 4c 24 10                                   mov     ecx, [esp+39D6Ch+lpMultiByteStr]
00404AF0  83 c2 02                                      add     edx, 2
00404AF3  83 c5 12                                      add     ebp, 12h
00404AF6  81 c6 28 01 00 00                             add     esi, 128h
00404AFC  83 c1 0a                                      add     ecx, 0Ah
00404AFF  81 fb 20 03 00 00                             cmp     ebx, 320h
00404B05  89 54 24 1c                                   mov     [esp+39D6Ch+var_39D50], edx
00404B09  89 4c 24 10                                   mov     [esp+39D6Ch+lpMultiByteStr], ecx
00404B0D  0f 8c c2 fe ff ff                             jl      loc_4049D5
00404B13  eb 0e                                         jmp     short loc_404B23
00404B15  6a 00                                         push    0; unsigned int
00404B17  6a 00                                         push    0; unsigned int
00404B19  68 80 f7 41 00                                push    offset byte_41F780; char *
00404B1E  e8 ef 5a 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00404B23  8b 74 24 20                                   mov     esi, [esp+39D6Ch+var_39D4C]
00404B27  89 9f 5c 01 00 00                             mov     [edi+15Ch], ebx
00404B2D  33 db                                         xor     ebx, ebx
00404B2F  8b cf                                         mov     ecx, edi; this
00404B31  89 9f 58 01 00 00                             mov     [edi+158h], ebx
00404B37  e8 f4 05 00 00                                call    sub_405130
00404B3C  8d 86 38 11 00 00                             lea     eax, [esi+1138h]
00404B42  33 c9                                         xor     ecx, ecx
00404B44  89 87 54 7b 00 00                             mov     [edi+7B54h], eax
00404B4A  81 c6 78 0e 00 00                             add     esi, 0E78h
00404B50  66 8b 08                                      mov     cx, [eax]
00404B53  6a 01                                         push    1; bRedraw
00404B55  89 8f 50 01 00 00                             mov     [edi+150h], ecx
00404B5B  89 b7 50 7b 00 00                             mov     [edi+7B50h], esi
00404B61  8b 97 c0 00 00 00                             mov     edx, [edi+0C0h]
00404B67  6a 73                                         push    73h ; 's'; nMaxPos
00404B69  53                                            push    ebx; nMinPos
00404B6A  6a 02                                         push    2; nBar
00404B6C  52                                            push    edx; hWnd
00404B6D  ff 15 1c c3 41 00                             call    ds:SetScrollRange; USER32
00404B73  8b 87 48 01 00 00                             mov     eax, [edi+148h]
00404B79  6a 01                                         push    1; bRedraw
00404B7B  50                                            push    eax; nPos
00404B7C  8b 87 c0 00 00 00                             mov     eax, [edi+0C0h]
00404B82  6a 02                                         push    2; nBar
00404B84  50                                            push    eax; hWnd
00404B85  ff 15 18 c3 41 00                             call    ds:SetScrollPos; USER32
00404B8B  8b cf                                         mov     ecx, edi
00404B8D  e8 5e 09 00 00                                call    sub_4054F0
00404B92  68 13 04 00 00                                push    413h; int
00404B97  8b cf                                         mov     ecx, edi; this
00404B99  e8 1c 5b 01 00                                call    ?GetDlgItem@CWnd@@QBEPAV1@H@Z; CWnd::GetDlgItem(int)
00404B9E  8b 48 20                                      mov     ecx, [eax+20h]
00404BA1  8b 2d 64 c3 41 00                             mov     ebp, ds:SendMessageA; USER32
00404BA7  53                                            push    ebx; lParam
00404BA8  53                                            push    ebx; wParam
00404BA9  6a 31                                         push    31h ; '1'; Msg
00404BAB  51                                            push    ecx; hWnd
00404BAC  ff d5                                         call    ebp ; SendMessageA; USER32
00404BAE  50                                            push    eax; void *
00404BAF  e8 42 5b 01 00                                call    ?FromHandle@CGdiObject@@SGPAV1@PAX@Z; CGdiObject::FromHandle(void *)
00404BB4  8b 40 04                                      mov     eax, [eax+4]
00404BB7  8d 54 24 24                                   lea     edx, [esp+39D6Ch+pv]
00404BBB  52                                            push    edx; pv
00404BBC  6a 3c                                         push    3Ch ; '<'; c
00404BBE  50                                            push    eax; h
00404BBF  ff 15 04 c0 41 00                             call    ds:GetObjectA; GDI32
00404BC5  8d 4c 24 24                                   lea     ecx, [esp+39D6Ch+pv]
00404BC9  c7 44 24 24 f0 ff ff ff                       mov     [esp+39D6Ch+pv], 0FFFFFFF0h
00404BD1  51                                            push    ecx; lplf
00404BD2  c7 44 24 2c 08 00 00 00                       mov     [esp+39D70h+var_39D44], 8
00404BDA  8d b7 40 7b 00 00                             lea     esi, [edi+7B40h]
00404BE0  ff 15 00 c0 41 00                             call    ds:CreateFontIndirectA; GDI32
00404BE6  50                                            push    eax; void *
00404BE7  8b ce                                         mov     ecx, esi; this
00404BE9  e8 02 5b 01 00                                call    ?Attach@CGdiObject@@QAEHPAX@Z; CGdiObject::Attach(void *)
00404BEE  68 13 04 00 00                                push    413h; int
00404BF3  8b cf                                         mov     ecx, edi; this
00404BF5  e8 c0 5a 01 00                                call    ?GetDlgItem@CWnd@@QBEPAV1@H@Z; CWnd::GetDlgItem(int)
00404BFA  3b f3                                         cmp     esi, ebx
00404BFC  75 04                                         jnz     short loc_404C02
00404BFE  33 f6                                         xor     esi, esi
00404C00  eb 03                                         jmp     short loc_404C05
00404C02  8b 76 04                                      mov     esi, [esi+4]
00404C05  8b 50 20                                      mov     edx, [eax+20h]
00404C08  6a 01                                         push    1; lParam
00404C0A  56                                            push    esi; wParam
00404C0B  6a 30                                         push    30h ; '0'; Msg
00404C0D  52                                            push    edx; hWnd
00404C0E  ff d5                                         call    ebp ; SendMessageA; USER32
00404C10  68 48 ef 42 00                                push    offset Str2
00404C15  8d 8f 48 7b 00 00                             lea     ecx, [edi+7B48h]
00404C1B  e8 ca 5a 01 00                                call    ??4CString@@QAEABV0@PBD@Z; CString::operator=(char const *)
00404C20  8d 4c 24 14                                   lea     ecx, [esp+39D6Ch+lParam]; this
00404C24  c6 87 4d 7b 00 00 ff                          mov     byte ptr [edi+7B4Dh], 0FFh
00404C2B  c6 87 4c 7b 00 00 ff                          mov     byte ptr [edi+7B4Ch], 0FFh
00404C32  c6 87 4f 7b 00 00 ff                          mov     byte ptr [edi+7B4Fh], 0FFh
00404C39  c6 87 4e 7b 00 00 ff                          mov     byte ptr [edi+7B4Eh], 0FFh
00404C40  c7 84 24 68 9d 03 00 ff ff ff ff              mov     [esp+39D6Ch+var_4], 0FFFFFFFFh
00404C4B  e8 b6 59 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00404C50  8b 8c 24 60 9d 03 00                          mov     ecx, [esp+39D6Ch+var_C]
00404C57  5f                                            pop     edi
00404C58  5e                                            pop     esi
00404C59  5d                                            pop     ebp
00404C5A  b8 01 00 00 00                                mov     eax, 1
00404C5F  5b                                            pop     ebx
00404C60  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00404C67  81 c4 5c 9d 03 00                             add     esp, 39D5Ch
00404C6D  c3                                            retn
0041B050  8d 8d a8 62 fc ff                             lea     ecx, [ebp-39D58h]; this
0041B056  e9 ab f5 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B05B  b8 68 d8 41 00                                mov     eax, offset stru_41D868
0041B060  e9 b7 f7 ff ff                                jmp     __CxxFrameHandler
