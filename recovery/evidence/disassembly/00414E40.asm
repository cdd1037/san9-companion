00414E40  51                                            push    ecx
00414E41  55                                            push    ebp
00414E42  33 ed                                         xor     ebp, ebp
00414E44  56                                            push    esi
00414E45  55                                            push    ebp; lpWindowName
00414E46  8b f1                                         mov     esi, ecx
00414E48  68 d4 ed 42 00                                push    offset ClassName; "KOEI_SAN9WINDOW"
00414E4D  89 6c 24 10                                   mov     [esp+14h+Buffer], ebp
00414E51  ff 15 30 c3 41 00                             call    ds:FindWindowA; USER32
00414E57  3b c5                                         cmp     eax, ebp
00414E59  0f 84 88 38 00 00                             jz      loc_4186E7
00414E5F  39 46 6c                                      cmp     [esi+6Ch], eax
00414E62  0f 85 7f 38 00 00                             jnz     loc_4186E7
00414E68  39 ae 28 01 00 00                             cmp     [esi+128h], ebp
00414E6E  74 08                                         jz      short loc_414E78
00414E70  55                                            push    ebp
00414E71  8b ce                                         mov     ecx, esi
00414E73  e8 78 53 00 00                                call    sub_41A1F0
00414E78  8b 86 30 11 00 00                             mov     eax, [esi+1130h]
00414E7E  8b 4e 70                                      mov     ecx, [esi+70h]
00414E81  53                                            push    ebx
00414E82  57                                            push    edi
00414E83  8b 3d 40 c0 41 00                             mov     edi, ds:WriteProcessMemory; KERNEL32
00414E89  55                                            push    ebp; lpNumberOfBytesWritten
00414E8A  68 b8 02 00 00                                push    2B8h; nSize
00414E8F  68 28 db 42 00                                push    offset unk_42DB28; lpBuffer
00414E94  50                                            push    eax; lpBaseAddress
00414E95  51                                            push    ecx; hProcess
00414E96  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414E98  8b 86 a8 1d 00 00                             mov     eax, [esi+1DA8h]
00414E9E  8b 4e 70                                      mov     ecx, [esi+70h]
00414EA1  55                                            push    ebp; lpNumberOfBytesWritten
00414EA2  8d 96 b0 1d 00 00                             lea     edx, [esi+1DB0h]
00414EA8  6a 04                                         push    4; nSize
00414EAA  52                                            push    edx; lpBuffer
00414EAB  50                                            push    eax; lpBaseAddress
00414EAC  51                                            push    ecx; hProcess
00414EAD  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414EAF  8b 86 b4 1d 00 00                             mov     eax, [esi+1DB4h]
00414EB5  8b 4e 70                                      mov     ecx, [esi+70h]
00414EB8  55                                            push    ebp; lpNumberOfBytesWritten
00414EB9  8d 96 bc 1d 00 00                             lea     edx, [esi+1DBCh]
00414EBF  6a 04                                         push    4; nSize
00414EC1  52                                            push    edx; lpBuffer
00414EC2  50                                            push    eax; lpBaseAddress
00414EC3  51                                            push    ecx; hProcess
00414EC4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414EC6  8b 86 9c 1d 00 00                             mov     eax, [esi+1D9Ch]
00414ECC  8b 4e 70                                      mov     ecx, [esi+70h]
00414ECF  55                                            push    ebp; lpNumberOfBytesWritten
00414ED0  8d 96 a4 1d 00 00                             lea     edx, [esi+1DA4h]
00414ED6  6a 01                                         push    1; nSize
00414ED8  52                                            push    edx; lpBuffer
00414ED9  50                                            push    eax; lpBaseAddress
00414EDA  51                                            push    ecx; hProcess
00414EDB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414EDD  8b 86 6c 1d 00 00                             mov     eax, [esi+1D6Ch]
00414EE3  8b 4e 70                                      mov     ecx, [esi+70h]
00414EE6  55                                            push    ebp; lpNumberOfBytesWritten
00414EE7  8d 96 74 1d 00 00                             lea     edx, [esi+1D74h]
00414EED  6a 01                                         push    1; nSize
00414EEF  52                                            push    edx; lpBuffer
00414EF0  50                                            push    eax; lpBaseAddress
00414EF1  51                                            push    ecx; hProcess
00414EF2  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414EF4  8b 86 78 1d 00 00                             mov     eax, [esi+1D78h]
00414EFA  8b 4e 70                                      mov     ecx, [esi+70h]
00414EFD  55                                            push    ebp; lpNumberOfBytesWritten
00414EFE  8d 96 80 1d 00 00                             lea     edx, [esi+1D80h]
00414F04  6a 04                                         push    4; nSize
00414F06  52                                            push    edx; lpBuffer
00414F07  50                                            push    eax; lpBaseAddress
00414F08  51                                            push    ecx; hProcess
00414F09  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414F0B  8b 86 84 1d 00 00                             mov     eax, [esi+1D84h]
00414F11  8b 4e 70                                      mov     ecx, [esi+70h]
00414F14  55                                            push    ebp; lpNumberOfBytesWritten
00414F15  8d 96 8c 1d 00 00                             lea     edx, [esi+1D8Ch]
00414F1B  6a 01                                         push    1; nSize
00414F1D  52                                            push    edx; lpBuffer
00414F1E  50                                            push    eax; lpBaseAddress
00414F1F  51                                            push    ecx; hProcess
00414F20  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414F22  8b 86 90 1d 00 00                             mov     eax, [esi+1D90h]
00414F28  8b 4e 70                                      mov     ecx, [esi+70h]
00414F2B  55                                            push    ebp; lpNumberOfBytesWritten
00414F2C  8d 96 98 1d 00 00                             lea     edx, [esi+1D98h]
00414F32  6a 02                                         push    2; nSize
00414F34  52                                            push    edx; lpBuffer
00414F35  50                                            push    eax; lpBaseAddress
00414F36  51                                            push    ecx; hProcess
00414F37  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414F39  8b 86 60 1d 00 00                             mov     eax, [esi+1D60h]
00414F3F  8b 4e 70                                      mov     ecx, [esi+70h]
00414F42  55                                            push    ebp; lpNumberOfBytesWritten
00414F43  8d 96 68 1d 00 00                             lea     edx, [esi+1D68h]
00414F49  6a 01                                         push    1; nSize
00414F4B  52                                            push    edx; lpBuffer
00414F4C  50                                            push    eax; lpBaseAddress
00414F4D  51                                            push    ecx; hProcess
00414F4E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414F50  8b 96 44 1d 00 00                             mov     edx, [esi+1D44h]
00414F56  8b 46 70                                      mov     eax, [esi+70h]
00414F59  8d 9e 54 1d 00 00                             lea     ebx, [esi+1D54h]
00414F5F  55                                            push    ebp; lpNumberOfBytesWritten
00414F60  6a 01                                         push    1; nSize
00414F62  53                                            push    ebx; lpBuffer
00414F63  52                                            push    edx; lpBaseAddress
00414F64  50                                            push    eax; hProcess
00414F65  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414F67  8b 8e 48 1d 00 00                             mov     ecx, [esi+1D48h]
00414F6D  8b 56 70                                      mov     edx, [esi+70h]
00414F70  55                                            push    ebp; lpNumberOfBytesWritten
00414F71  6a 01                                         push    1; nSize
00414F73  53                                            push    ebx; lpBuffer
00414F74  51                                            push    ecx; lpBaseAddress
00414F75  52                                            push    edx; hProcess
00414F76  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414F78  8b 8e 4c 1d 00 00                             mov     ecx, [esi+1D4Ch]
00414F7E  8b 56 70                                      mov     edx, [esi+70h]
00414F81  55                                            push    ebp; lpNumberOfBytesWritten
00414F82  8d 86 5c 1d 00 00                             lea     eax, [esi+1D5Ch]
00414F88  6a 01                                         push    1; nSize
00414F8A  50                                            push    eax; lpBuffer
00414F8B  51                                            push    ecx; lpBaseAddress
00414F8C  52                                            push    edx; hProcess
00414F8D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414F8F  8b 8e 38 1d 00 00                             mov     ecx, [esi+1D38h]
00414F95  8b 56 70                                      mov     edx, [esi+70h]
00414F98  55                                            push    ebp; lpNumberOfBytesWritten
00414F99  8d 86 40 1d 00 00                             lea     eax, [esi+1D40h]
00414F9F  6a 01                                         push    1; nSize
00414FA1  50                                            push    eax; lpBuffer
00414FA2  51                                            push    ecx; lpBaseAddress
00414FA3  52                                            push    edx; hProcess
00414FA4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414FA6  bb 24 c6 42 00                                mov     ebx, offset unk_42C624
00414FAB  8b 43 f8                                      mov     eax, [ebx-8]
00414FAE  8b 4b f4                                      mov     ecx, [ebx-0Ch]
00414FB1  8b 56 70                                      mov     edx, [esi+70h]
00414FB4  55                                            push    ebp; lpNumberOfBytesWritten
00414FB5  50                                            push    eax; nSize
00414FB6  53                                            push    ebx; lpBuffer
00414FB7  51                                            push    ecx; lpBaseAddress
00414FB8  52                                            push    edx; hProcess
00414FB9  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414FBB  83 c3 10                                      add     ebx, 10h
00414FBE  81 fb d4 c7 42 00                             cmp     ebx, offset dword_42C7D4
00414FC4  7c e5                                         jl      short loc_414FAB
00414FC6  bb 5c c2 42 00                                mov     ebx, offset unk_42C25C
00414FCB  8b 43 f8                                      mov     eax, [ebx-8]
00414FCE  8b 4b f4                                      mov     ecx, [ebx-0Ch]
00414FD1  8b 56 70                                      mov     edx, [esi+70h]
00414FD4  55                                            push    ebp; lpNumberOfBytesWritten
00414FD5  50                                            push    eax; nSize
00414FD6  53                                            push    ebx; lpBuffer
00414FD7  51                                            push    ecx; lpBaseAddress
00414FD8  52                                            push    edx; hProcess
00414FD9  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414FDB  83 c3 10                                      add     ebx, 10h
00414FDE  81 fb fc c4 42 00                             cmp     ebx, offset dword_42C4FC
00414FE4  7c e5                                         jl      short loc_414FCB
00414FE6  8b 86 fc 1c 00 00                             mov     eax, [esi+1CFCh]
00414FEC  8b 4e 70                                      mov     ecx, [esi+70h]
00414FEF  8d 9e 08 1d 00 00                             lea     ebx, [esi+1D08h]
00414FF5  55                                            push    ebp; lpNumberOfBytesWritten
00414FF6  6a 01                                         push    1; nSize
00414FF8  53                                            push    ebx; lpBuffer
00414FF9  50                                            push    eax; lpBaseAddress
00414FFA  51                                            push    ecx; hProcess
00414FFB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00414FFD  8b 96 00 1d 00 00                             mov     edx, [esi+1D00h]
00415003  8b 46 70                                      mov     eax, [esi+70h]
00415006  55                                            push    ebp; lpNumberOfBytesWritten
00415007  6a 01                                         push    1; nSize
00415009  53                                            push    ebx; lpBuffer
0041500A  52                                            push    edx; lpBaseAddress
0041500B  50                                            push    eax; hProcess
0041500C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041500E  8b 8e f0 1c 00 00                             mov     ecx, [esi+1CF0h]
00415014  8b 56 70                                      mov     edx, [esi+70h]
00415017  8d 9e f8 1c 00 00                             lea     ebx, [esi+1CF8h]
0041501D  55                                            push    ebp; lpNumberOfBytesWritten
0041501E  6a 01                                         push    1; nSize
00415020  53                                            push    ebx; lpBuffer
00415021  51                                            push    ecx; lpBaseAddress
00415022  52                                            push    edx; hProcess
00415023  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415025  8b 86 ec 1c 00 00                             mov     eax, [esi+1CECh]
0041502B  8b 4e 70                                      mov     ecx, [esi+70h]
0041502E  55                                            push    ebp; lpNumberOfBytesWritten
0041502F  6a 01                                         push    1; nSize
00415031  53                                            push    ebx; lpBuffer
00415032  50                                            push    eax; lpBaseAddress
00415033  51                                            push    ecx; hProcess
00415034  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415036  8b 96 e8 1c 00 00                             mov     edx, [esi+1CE8h]
0041503C  8b 46 70                                      mov     eax, [esi+70h]
0041503F  55                                            push    ebp; lpNumberOfBytesWritten
00415040  6a 01                                         push    1; nSize
00415042  53                                            push    ebx; lpBuffer
00415043  52                                            push    edx; lpBaseAddress
00415044  50                                            push    eax; hProcess
00415045  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415047  8b 96 dc 1c 00 00                             mov     edx, [esi+1CDCh]
0041504D  8b 46 70                                      mov     eax, [esi+70h]
00415050  55                                            push    ebp; lpNumberOfBytesWritten
00415051  8d 8e e4 1c 00 00                             lea     ecx, [esi+1CE4h]
00415057  6a 01                                         push    1; nSize
00415059  51                                            push    ecx; lpBuffer
0041505A  52                                            push    edx; lpBaseAddress
0041505B  50                                            push    eax; hProcess
0041505C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041505E  8b 8e d8 19 00 00                             mov     ecx, [esi+19D8h]
00415064  8b 56 70                                      mov     edx, [esi+70h]
00415067  8d 9e e8 19 00 00                             lea     ebx, [esi+19E8h]
0041506D  55                                            push    ebp; lpNumberOfBytesWritten
0041506E  6a 01                                         push    1; nSize
00415070  53                                            push    ebx; lpBuffer
00415071  51                                            push    ecx; lpBaseAddress
00415072  52                                            push    edx; hProcess
00415073  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415075  8b 86 dc 19 00 00                             mov     eax, [esi+19DCh]
0041507B  8b 4e 70                                      mov     ecx, [esi+70h]
0041507E  55                                            push    ebp; lpNumberOfBytesWritten
0041507F  6a 01                                         push    1; nSize
00415081  53                                            push    ebx; lpBuffer
00415082  50                                            push    eax; lpBaseAddress
00415083  51                                            push    ecx; hProcess
00415084  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415086  8b 96 e0 19 00 00                             mov     edx, [esi+19E0h]
0041508C  8b 46 70                                      mov     eax, [esi+70h]
0041508F  55                                            push    ebp; lpNumberOfBytesWritten
00415090  6a 01                                         push    1; nSize
00415092  53                                            push    ebx; lpBuffer
00415093  52                                            push    edx; lpBaseAddress
00415094  50                                            push    eax; hProcess
00415095  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415097  8b 8e d8 1c 00 00                             mov     ecx, [esi+1CD8h]
0041509D  8d 9e d4 1c 00 00                             lea     ebx, [esi+1CD4h]
004150A3  55                                            push    ebp; lpNumberOfBytesWritten
004150A4  6a 01                                         push    1; nSize
004150A6  53                                            push    ebx; lpBuffer
004150A7  8b 56 70                                      mov     edx, [esi+70h]
004150AA  51                                            push    ecx; lpBaseAddress
004150AB  52                                            push    edx; hProcess
004150AC  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004150AE  8b 86 cc 1c 00 00                             mov     eax, [esi+1CCCh]
004150B4  8b 4e 70                                      mov     ecx, [esi+70h]
004150B7  55                                            push    ebp; lpNumberOfBytesWritten
004150B8  6a 01                                         push    1; nSize
004150BA  53                                            push    ebx; lpBuffer
004150BB  50                                            push    eax; lpBaseAddress
004150BC  51                                            push    ecx; hProcess
004150BD  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004150BF  8b 86 c4 1c 00 00                             mov     eax, [esi+1CC4h]
004150C5  8b 4e 70                                      mov     ecx, [esi+70h]
004150C8  55                                            push    ebp; lpNumberOfBytesWritten
004150C9  8d 96 c8 1c 00 00                             lea     edx, [esi+1CC8h]
004150CF  6a 01                                         push    1; nSize
004150D1  52                                            push    edx; lpBuffer
004150D2  50                                            push    eax; lpBaseAddress
004150D3  51                                            push    ecx; hProcess
004150D4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004150D6  8b 86 b4 1c 00 00                             mov     eax, [esi+1CB4h]
004150DC  8b 4e 70                                      mov     ecx, [esi+70h]
004150DF  55                                            push    ebp; lpNumberOfBytesWritten
004150E0  8d 96 bc 1c 00 00                             lea     edx, [esi+1CBCh]
004150E6  6a 01                                         push    1; nSize
004150E8  52                                            push    edx; lpBuffer
004150E9  50                                            push    eax; lpBaseAddress
004150EA  51                                            push    ecx; hProcess
004150EB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004150ED  8b 86 ac 1c 00 00                             mov     eax, [esi+1CACh]
004150F3  8b 4e 70                                      mov     ecx, [esi+70h]
004150F6  55                                            push    ebp; lpNumberOfBytesWritten
004150F7  8d 96 b0 1c 00 00                             lea     edx, [esi+1CB0h]
004150FD  6a 01                                         push    1; nSize
004150FF  52                                            push    edx; lpBuffer
00415100  50                                            push    eax; lpBaseAddress
00415101  51                                            push    ecx; hProcess
00415102  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415104  8b 86 a0 1c 00 00                             mov     eax, [esi+1CA0h]
0041510A  8b 4e 70                                      mov     ecx, [esi+70h]
0041510D  55                                            push    ebp; lpNumberOfBytesWritten
0041510E  8d 96 a8 1c 00 00                             lea     edx, [esi+1CA8h]
00415114  6a 01                                         push    1; nSize
00415116  52                                            push    edx; lpBuffer
00415117  50                                            push    eax; lpBaseAddress
00415118  51                                            push    ecx; hProcess
00415119  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041511B  8b 86 94 1c 00 00                             mov     eax, [esi+1C94h]
00415121  8b 4e 70                                      mov     ecx, [esi+70h]
00415124  55                                            push    ebp; lpNumberOfBytesWritten
00415125  8d 96 9c 1c 00 00                             lea     edx, [esi+1C9Ch]
0041512B  6a 01                                         push    1; nSize
0041512D  52                                            push    edx; lpBuffer
0041512E  50                                            push    eax; lpBaseAddress
0041512F  51                                            push    ecx; hProcess
00415130  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415132  8b 96 88 1c 00 00                             mov     edx, [esi+1C88h]
00415138  8b 46 70                                      mov     eax, [esi+70h]
0041513B  8d 9e 90 1c 00 00                             lea     ebx, [esi+1C90h]
00415141  55                                            push    ebp; lpNumberOfBytesWritten
00415142  6a 01                                         push    1; nSize
00415144  53                                            push    ebx; lpBuffer
00415145  52                                            push    edx; lpBaseAddress
00415146  50                                            push    eax; hProcess
00415147  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415149  8b 8e 88 1c 00 00                             mov     ecx, [esi+1C88h]
0041514F  8b 56 70                                      mov     edx, [esi+70h]
00415152  55                                            push    ebp; lpNumberOfBytesWritten
00415153  6a 01                                         push    1; nSize
00415155  83 e9 20                                      sub     ecx, 20h ; ' '
00415158  53                                            push    ebx; lpBuffer
00415159  51                                            push    ecx; lpBaseAddress
0041515A  52                                            push    edx; hProcess
0041515B  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041515D  8b 8e 7c 1c 00 00                             mov     ecx, [esi+1C7Ch]
00415163  55                                            push    ebp; lpNumberOfBytesWritten
00415164  8d 86 84 1c 00 00                             lea     eax, [esi+1C84h]
0041516A  6a 04                                         push    4; nSize
0041516C  50                                            push    eax; lpBuffer
0041516D  51                                            push    ecx; lpBaseAddress
0041516E  8b 56 70                                      mov     edx, [esi+70h]
00415171  52                                            push    edx; hProcess
00415172  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415174  8b 8e 70 1c 00 00                             mov     ecx, [esi+1C70h]
0041517A  8b 56 70                                      mov     edx, [esi+70h]
0041517D  55                                            push    ebp; lpNumberOfBytesWritten
0041517E  8d 86 78 1c 00 00                             lea     eax, [esi+1C78h]
00415184  6a 01                                         push    1; nSize
00415186  50                                            push    eax; lpBuffer
00415187  51                                            push    ecx; lpBaseAddress
00415188  52                                            push    edx; hProcess
00415189  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041518B  8b 8e 64 1c 00 00                             mov     ecx, [esi+1C64h]
00415191  8b 56 70                                      mov     edx, [esi+70h]
00415194  55                                            push    ebp; lpNumberOfBytesWritten
00415195  8d 86 6c 1c 00 00                             lea     eax, [esi+1C6Ch]
0041519B  6a 01                                         push    1; nSize
0041519D  50                                            push    eax; lpBuffer
0041519E  51                                            push    ecx; lpBaseAddress
0041519F  52                                            push    edx; hProcess
004151A0  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004151A2  8b 8e c0 1c 00 00                             mov     ecx, [esi+1CC0h]
004151A8  8b 56 70                                      mov     edx, [esi+70h]
004151AB  55                                            push    ebp; lpNumberOfBytesWritten
004151AC  8d 44 24 14                                   lea     eax, [esp+18h+Buffer]
004151B0  6a 01                                         push    1; nSize
004151B2  50                                            push    eax; lpBuffer
004151B3  51                                            push    ecx; lpBaseAddress
004151B4  52                                            push    edx; hProcess
004151B5  c7 44 24 24 14 00 00 00                       mov     [esp+28h+Buffer], 14h
004151BD  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004151BF  8b 8e c0 1c 00 00                             mov     ecx, [esi+1CC0h]
004151C5  8b 56 70                                      mov     edx, [esi+70h]
004151C8  55                                            push    ebp; lpNumberOfBytesWritten
004151C9  8d 44 24 14                                   lea     eax, [esp+18h+Buffer]
004151CD  6a 01                                         push    1; nSize
004151CF  83 c1 08                                      add     ecx, 8
004151D2  50                                            push    eax; lpBuffer
004151D3  51                                            push    ecx; lpBaseAddress
004151D4  52                                            push    edx; hProcess
004151D5  c7 44 24 24 0e 00 00 00                       mov     [esp+28h+Buffer], 0Eh
004151DD  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004151DF  8b 8e c0 1c 00 00                             mov     ecx, [esi+1CC0h]
004151E5  8b 56 70                                      mov     edx, [esi+70h]
004151E8  55                                            push    ebp; lpNumberOfBytesWritten
004151E9  8d 44 24 14                                   lea     eax, [esp+18h+Buffer]
004151ED  6a 01                                         push    1; nSize
004151EF  83 c1 10                                      add     ecx, 10h
004151F2  50                                            push    eax; lpBuffer
004151F3  51                                            push    ecx; lpBaseAddress
004151F4  52                                            push    edx; hProcess
004151F5  c7 44 24 24 0a 00 00 00                       mov     [esp+28h+Buffer], 0Ah
004151FD  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004151FF  8b 8e c0 1c 00 00                             mov     ecx, [esi+1CC0h]
00415205  8b 56 70                                      mov     edx, [esi+70h]
00415208  55                                            push    ebp; lpNumberOfBytesWritten
00415209  8d 44 24 14                                   lea     eax, [esp+18h+Buffer]
0041520D  6a 01                                         push    1; nSize
0041520F  83 c1 18                                      add     ecx, 18h
00415212  50                                            push    eax; lpBuffer
00415213  51                                            push    ecx; lpBaseAddress
00415214  52                                            push    edx; hProcess
00415215  c7 44 24 24 09 00 00 00                       mov     [esp+28h+Buffer], 9
0041521D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041521F  8b 8e c0 1c 00 00                             mov     ecx, [esi+1CC0h]
00415225  8b 56 70                                      mov     edx, [esi+70h]
00415228  55                                            push    ebp; lpNumberOfBytesWritten
00415229  8d 44 24 14                                   lea     eax, [esp+18h+Buffer]
0041522D  6a 01                                         push    1; nSize
0041522F  83 c1 20                                      add     ecx, 20h ; ' '
00415232  50                                            push    eax; lpBuffer
00415233  51                                            push    ecx; lpBaseAddress
00415234  52                                            push    edx; hProcess
00415235  c7 44 24 24 08 00 00 00                       mov     [esp+28h+Buffer], 8
0041523D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041523F  8b 8e 58 1c 00 00                             mov     ecx, [esi+1C58h]
00415245  55                                            push    ebp; lpNumberOfBytesWritten
00415246  8d 86 60 1c 00 00                             lea     eax, [esi+1C60h]
0041524C  6a 01                                         push    1; nSize
0041524E  50                                            push    eax; lpBuffer
0041524F  51                                            push    ecx; lpBaseAddress
00415250  8b 56 70                                      mov     edx, [esi+70h]
00415253  52                                            push    edx; hProcess
00415254  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415256  8b 8e 4c 1c 00 00                             mov     ecx, [esi+1C4Ch]
0041525C  8b 56 70                                      mov     edx, [esi+70h]
0041525F  55                                            push    ebp; lpNumberOfBytesWritten
00415260  8d 86 54 1c 00 00                             lea     eax, [esi+1C54h]
00415266  6a 01                                         push    1; nSize
00415268  50                                            push    eax; lpBuffer
00415269  51                                            push    ecx; lpBaseAddress
0041526A  52                                            push    edx; hProcess
0041526B  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041526D  8b 8e 40 1c 00 00                             mov     ecx, [esi+1C40h]
00415273  8b 56 70                                      mov     edx, [esi+70h]
00415276  55                                            push    ebp; lpNumberOfBytesWritten
00415277  8d 86 48 1c 00 00                             lea     eax, [esi+1C48h]
0041527D  6a 01                                         push    1; nSize
0041527F  50                                            push    eax; lpBuffer
00415280  51                                            push    ecx; lpBaseAddress
00415281  52                                            push    edx; hProcess
00415282  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415284  8b 8e 34 1c 00 00                             mov     ecx, [esi+1C34h]
0041528A  8b 56 70                                      mov     edx, [esi+70h]
0041528D  55                                            push    ebp; lpNumberOfBytesWritten
0041528E  8d 86 3c 1c 00 00                             lea     eax, [esi+1C3Ch]
00415294  6a 01                                         push    1; nSize
00415296  50                                            push    eax; lpBuffer
00415297  51                                            push    ecx; lpBaseAddress
00415298  52                                            push    edx; hProcess
00415299  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041529B  8b 86 28 1c 00 00                             mov     eax, [esi+1C28h]
004152A1  8b 4e 70                                      mov     ecx, [esi+70h]
004152A4  8d 9e 30 1c 00 00                             lea     ebx, [esi+1C30h]
004152AA  55                                            push    ebp; lpNumberOfBytesWritten
004152AB  6a 01                                         push    1; nSize
004152AD  53                                            push    ebx; lpBuffer
004152AE  50                                            push    eax; lpBaseAddress
004152AF  51                                            push    ecx; hProcess
004152B0  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004152B2  8b 96 24 1c 00 00                             mov     edx, [esi+1C24h]
004152B8  8b 46 70                                      mov     eax, [esi+70h]
004152BB  55                                            push    ebp; lpNumberOfBytesWritten
004152BC  6a 01                                         push    1; nSize
004152BE  53                                            push    ebx; lpBuffer
004152BF  52                                            push    edx; lpBaseAddress
004152C0  50                                            push    eax; hProcess
004152C1  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004152C3  8b 96 18 1c 00 00                             mov     edx, [esi+1C18h]
004152C9  8b 46 70                                      mov     eax, [esi+70h]
004152CC  55                                            push    ebp; lpNumberOfBytesWritten
004152CD  8d 8e 20 1c 00 00                             lea     ecx, [esi+1C20h]
004152D3  6a 01                                         push    1; nSize
004152D5  51                                            push    ecx; lpBuffer
004152D6  52                                            push    edx; lpBaseAddress
004152D7  50                                            push    eax; hProcess
004152D8  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004152DA  8b 96 0c 1c 00 00                             mov     edx, [esi+1C0Ch]
004152E0  8b 46 70                                      mov     eax, [esi+70h]
004152E3  55                                            push    ebp; lpNumberOfBytesWritten
004152E4  8d 8e 14 1c 00 00                             lea     ecx, [esi+1C14h]
004152EA  6a 04                                         push    4; nSize
004152EC  51                                            push    ecx; lpBuffer
004152ED  52                                            push    edx; lpBaseAddress
004152EE  50                                            push    eax; hProcess
004152EF  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004152F1  8b 96 00 1c 00 00                             mov     edx, [esi+1C00h]
004152F7  8b 46 70                                      mov     eax, [esi+70h]
004152FA  55                                            push    ebp; lpNumberOfBytesWritten
004152FB  8d 8e 08 1c 00 00                             lea     ecx, [esi+1C08h]
00415301  6a 01                                         push    1; nSize
00415303  51                                            push    ecx; lpBuffer
00415304  52                                            push    edx; lpBaseAddress
00415305  50                                            push    eax; hProcess
00415306  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415308  8b 96 f4 1b 00 00                             mov     edx, [esi+1BF4h]
0041530E  8b 46 70                                      mov     eax, [esi+70h]
00415311  55                                            push    ebp; lpNumberOfBytesWritten
00415312  8d 8e fc 1b 00 00                             lea     ecx, [esi+1BFCh]
00415318  6a 01                                         push    1; nSize
0041531A  51                                            push    ecx; lpBuffer
0041531B  52                                            push    edx; lpBaseAddress
0041531C  50                                            push    eax; hProcess
0041531D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041531F  8b 96 e8 1b 00 00                             mov     edx, [esi+1BE8h]
00415325  8b 46 70                                      mov     eax, [esi+70h]
00415328  55                                            push    ebp; lpNumberOfBytesWritten
00415329  8d 8e f0 1b 00 00                             lea     ecx, [esi+1BF0h]
0041532F  6a 01                                         push    1; nSize
00415331  51                                            push    ecx; lpBuffer
00415332  52                                            push    edx; lpBaseAddress
00415333  50                                            push    eax; hProcess
00415334  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415336  8b 96 8c 1b 00 00                             mov     edx, [esi+1B8Ch]
0041533C  8b 46 70                                      mov     eax, [esi+70h]
0041533F  55                                            push    ebp; lpNumberOfBytesWritten
00415340  8d 8e 94 1b 00 00                             lea     ecx, [esi+1B94h]
00415346  6a 01                                         push    1; nSize
00415348  51                                            push    ecx; lpBuffer
00415349  52                                            push    edx; lpBaseAddress
0041534A  50                                            push    eax; hProcess
0041534B  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041534D  8b 96 dc 1b 00 00                             mov     edx, [esi+1BDCh]
00415353  8b 46 70                                      mov     eax, [esi+70h]
00415356  55                                            push    ebp; lpNumberOfBytesWritten
00415357  8d 8e e4 1b 00 00                             lea     ecx, [esi+1BE4h]
0041535D  6a 04                                         push    4; nSize
0041535F  51                                            push    ecx; lpBuffer
00415360  52                                            push    edx; lpBaseAddress
00415361  50                                            push    eax; hProcess
00415362  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415364  8b 96 d0 1b 00 00                             mov     edx, [esi+1BD0h]
0041536A  8b 46 70                                      mov     eax, [esi+70h]
0041536D  55                                            push    ebp; lpNumberOfBytesWritten
0041536E  8d 8e d8 1b 00 00                             lea     ecx, [esi+1BD8h]
00415374  6a 01                                         push    1; nSize
00415376  51                                            push    ecx; lpBuffer
00415377  52                                            push    edx; lpBaseAddress
00415378  50                                            push    eax; hProcess
00415379  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041537B  8b 96 c4 1b 00 00                             mov     edx, [esi+1BC4h]
00415381  8b 46 70                                      mov     eax, [esi+70h]
00415384  55                                            push    ebp; lpNumberOfBytesWritten
00415385  8d 8e cc 1b 00 00                             lea     ecx, [esi+1BCCh]
0041538B  6a 01                                         push    1; nSize
0041538D  51                                            push    ecx; lpBuffer
0041538E  52                                            push    edx; lpBaseAddress
0041538F  50                                            push    eax; hProcess
00415390  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415392  8b 96 bc 1b 00 00                             mov     edx, [esi+1BBCh]
00415398  8b 46 70                                      mov     eax, [esi+70h]
0041539B  55                                            push    ebp; lpNumberOfBytesWritten
0041539C  8d 8e c0 1b 00 00                             lea     ecx, [esi+1BC0h]
004153A2  6a 01                                         push    1; nSize
004153A4  51                                            push    ecx; lpBuffer
004153A5  52                                            push    edx; lpBaseAddress
004153A6  50                                            push    eax; hProcess
004153A7  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004153A9  8b 96 b0 1b 00 00                             mov     edx, [esi+1BB0h]
004153AF  8b 46 70                                      mov     eax, [esi+70h]
004153B2  55                                            push    ebp; lpNumberOfBytesWritten
004153B3  8d 8e b8 1b 00 00                             lea     ecx, [esi+1BB8h]
004153B9  6a 04                                         push    4; nSize
004153BB  51                                            push    ecx; lpBuffer
004153BC  52                                            push    edx; lpBaseAddress
004153BD  50                                            push    eax; hProcess
004153BE  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004153C0  8b 96 a4 1b 00 00                             mov     edx, [esi+1BA4h]
004153C6  8b 46 70                                      mov     eax, [esi+70h]
004153C9  55                                            push    ebp; lpNumberOfBytesWritten
004153CA  8d 8e ac 1b 00 00                             lea     ecx, [esi+1BACh]
004153D0  6a 01                                         push    1; nSize
004153D2  51                                            push    ecx; lpBuffer
004153D3  52                                            push    edx; lpBaseAddress
004153D4  50                                            push    eax; hProcess
004153D5  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004153D7  8b 96 98 1b 00 00                             mov     edx, [esi+1B98h]
004153DD  8b 46 70                                      mov     eax, [esi+70h]
004153E0  55                                            push    ebp; lpNumberOfBytesWritten
004153E1  8d 8e a0 1b 00 00                             lea     ecx, [esi+1BA0h]
004153E7  6a 01                                         push    1; nSize
004153E9  51                                            push    ecx; lpBuffer
004153EA  52                                            push    edx; lpBaseAddress
004153EB  50                                            push    eax; hProcess
004153EC  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004153EE  8b 96 80 1b 00 00                             mov     edx, [esi+1B80h]
004153F4  8b 46 70                                      mov     eax, [esi+70h]
004153F7  55                                            push    ebp; lpNumberOfBytesWritten
004153F8  8d 8e 88 1b 00 00                             lea     ecx, [esi+1B88h]
004153FE  6a 01                                         push    1; nSize
00415400  51                                            push    ecx; lpBuffer
00415401  52                                            push    edx; lpBaseAddress
00415402  50                                            push    eax; hProcess
00415403  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415405  8b 96 74 1b 00 00                             mov     edx, [esi+1B74h]
0041540B  8b 46 70                                      mov     eax, [esi+70h]
0041540E  55                                            push    ebp; lpNumberOfBytesWritten
0041540F  8d 8e 7c 1b 00 00                             lea     ecx, [esi+1B7Ch]
00415415  6a 01                                         push    1; nSize
00415417  51                                            push    ecx; lpBuffer
00415418  52                                            push    edx; lpBaseAddress
00415419  50                                            push    eax; hProcess
0041541A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041541C  8b 96 68 1b 00 00                             mov     edx, [esi+1B68h]
00415422  8b 46 70                                      mov     eax, [esi+70h]
00415425  55                                            push    ebp; lpNumberOfBytesWritten
00415426  8d 8e 70 1b 00 00                             lea     ecx, [esi+1B70h]
0041542C  6a 04                                         push    4; nSize
0041542E  51                                            push    ecx; lpBuffer
0041542F  52                                            push    edx; lpBaseAddress
00415430  50                                            push    eax; hProcess
00415431  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415433  8b 96 64 1b 00 00                             mov     edx, [esi+1B64h]
00415439  8b 46 70                                      mov     eax, [esi+70h]
0041543C  55                                            push    ebp; lpNumberOfBytesWritten
0041543D  8d 8e 6c 1b 00 00                             lea     ecx, [esi+1B6Ch]
00415443  6a 04                                         push    4; nSize
00415445  51                                            push    ecx; lpBuffer
00415446  52                                            push    edx; lpBaseAddress
00415447  50                                            push    eax; hProcess
00415448  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041544A  8b 96 58 1b 00 00                             mov     edx, [esi+1B58h]
00415450  8b 46 70                                      mov     eax, [esi+70h]
00415453  55                                            push    ebp; lpNumberOfBytesWritten
00415454  8d 8e 60 1b 00 00                             lea     ecx, [esi+1B60h]
0041545A  6a 01                                         push    1; nSize
0041545C  51                                            push    ecx; lpBuffer
0041545D  52                                            push    edx; lpBaseAddress
0041545E  50                                            push    eax; hProcess
0041545F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415461  8b 96 4c 1b 00 00                             mov     edx, [esi+1B4Ch]
00415467  8b 46 70                                      mov     eax, [esi+70h]
0041546A  55                                            push    ebp; lpNumberOfBytesWritten
0041546B  8d 8e 54 1b 00 00                             lea     ecx, [esi+1B54h]
00415471  6a 04                                         push    4; nSize
00415473  51                                            push    ecx; lpBuffer
00415474  52                                            push    edx; lpBaseAddress
00415475  50                                            push    eax; hProcess
00415476  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415478  8b 96 40 1b 00 00                             mov     edx, [esi+1B40h]
0041547E  8b 46 70                                      mov     eax, [esi+70h]
00415481  55                                            push    ebp; lpNumberOfBytesWritten
00415482  8d 8e 48 1b 00 00                             lea     ecx, [esi+1B48h]
00415488  6a 01                                         push    1; nSize
0041548A  51                                            push    ecx; lpBuffer
0041548B  52                                            push    edx; lpBaseAddress
0041548C  50                                            push    eax; hProcess
0041548D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041548F  8b 96 34 1b 00 00                             mov     edx, [esi+1B34h]
00415495  8b 46 70                                      mov     eax, [esi+70h]
00415498  55                                            push    ebp; lpNumberOfBytesWritten
00415499  8d 8e 3c 1b 00 00                             lea     ecx, [esi+1B3Ch]
0041549F  6a 04                                         push    4; nSize
004154A1  51                                            push    ecx; lpBuffer
004154A2  52                                            push    edx; lpBaseAddress
004154A3  50                                            push    eax; hProcess
004154A4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004154A6  8b 96 28 1b 00 00                             mov     edx, [esi+1B28h]
004154AC  8b 46 70                                      mov     eax, [esi+70h]
004154AF  55                                            push    ebp; lpNumberOfBytesWritten
004154B0  8d 8e 30 1b 00 00                             lea     ecx, [esi+1B30h]
004154B6  6a 01                                         push    1; nSize
004154B8  51                                            push    ecx; lpBuffer
004154B9  52                                            push    edx; lpBaseAddress
004154BA  50                                            push    eax; hProcess
004154BB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004154BD  8b 96 1c 1b 00 00                             mov     edx, [esi+1B1Ch]
004154C3  8b 46 70                                      mov     eax, [esi+70h]
004154C6  55                                            push    ebp; lpNumberOfBytesWritten
004154C7  8d 8e 24 1b 00 00                             lea     ecx, [esi+1B24h]
004154CD  6a 01                                         push    1; nSize
004154CF  51                                            push    ecx; lpBuffer
004154D0  52                                            push    edx; lpBaseAddress
004154D1  50                                            push    eax; hProcess
004154D2  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004154D4  8b 96 10 1b 00 00                             mov     edx, [esi+1B10h]
004154DA  8b 46 70                                      mov     eax, [esi+70h]
004154DD  55                                            push    ebp; lpNumberOfBytesWritten
004154DE  8d 8e 18 1b 00 00                             lea     ecx, [esi+1B18h]
004154E4  6a 01                                         push    1; nSize
004154E6  51                                            push    ecx; lpBuffer
004154E7  52                                            push    edx; lpBaseAddress
004154E8  50                                            push    eax; hProcess
004154E9  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004154EB  8b 96 00 1b 00 00                             mov     edx, [esi+1B00h]
004154F1  8b 46 70                                      mov     eax, [esi+70h]
004154F4  55                                            push    ebp; lpNumberOfBytesWritten
004154F5  8d 8e 08 1b 00 00                             lea     ecx, [esi+1B08h]
004154FB  6a 01                                         push    1; nSize
004154FD  51                                            push    ecx; lpBuffer
004154FE  52                                            push    edx; lpBaseAddress
004154FF  50                                            push    eax; hProcess
00415500  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415502  8b 96 f4 1a 00 00                             mov     edx, [esi+1AF4h]
00415508  8b 46 70                                      mov     eax, [esi+70h]
0041550B  55                                            push    ebp; lpNumberOfBytesWritten
0041550C  8d 8e fc 1a 00 00                             lea     ecx, [esi+1AFCh]
00415512  6a 01                                         push    1; nSize
00415514  51                                            push    ecx; lpBuffer
00415515  52                                            push    edx; lpBaseAddress
00415516  50                                            push    eax; hProcess
00415517  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415519  8b 96 e8 1a 00 00                             mov     edx, [esi+1AE8h]
0041551F  8b 46 70                                      mov     eax, [esi+70h]
00415522  55                                            push    ebp; lpNumberOfBytesWritten
00415523  8d 8e f0 1a 00 00                             lea     ecx, [esi+1AF0h]
00415529  6a 01                                         push    1; nSize
0041552B  51                                            push    ecx; lpBuffer
0041552C  52                                            push    edx; lpBaseAddress
0041552D  50                                            push    eax; hProcess
0041552E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415530  8b 96 0c 1d 00 00                             mov     edx, [esi+1D0Ch]
00415536  8b 46 70                                      mov     eax, [esi+70h]
00415539  55                                            push    ebp; lpNumberOfBytesWritten
0041553A  8d 8e 14 1d 00 00                             lea     ecx, [esi+1D14h]
00415540  6a 01                                         push    1; nSize
00415542  51                                            push    ecx; lpBuffer
00415543  52                                            push    edx; lpBaseAddress
00415544  50                                            push    eax; hProcess
00415545  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415547  8b 96 dc 1a 00 00                             mov     edx, [esi+1ADCh]
0041554D  8b 46 70                                      mov     eax, [esi+70h]
00415550  55                                            push    ebp; lpNumberOfBytesWritten
00415551  8d 8e e4 1a 00 00                             lea     ecx, [esi+1AE4h]
00415557  6a 01                                         push    1; nSize
00415559  51                                            push    ecx; lpBuffer
0041555A  52                                            push    edx; lpBaseAddress
0041555B  50                                            push    eax; hProcess
0041555C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041555E  8b 96 d0 1a 00 00                             mov     edx, [esi+1AD0h]
00415564  8b 46 70                                      mov     eax, [esi+70h]
00415567  55                                            push    ebp; lpNumberOfBytesWritten
00415568  8d 8e d8 1a 00 00                             lea     ecx, [esi+1AD8h]
0041556E  6a 01                                         push    1; nSize
00415570  51                                            push    ecx; lpBuffer
00415571  52                                            push    edx; lpBaseAddress
00415572  50                                            push    eax; hProcess
00415573  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415575  8b 96 c4 1a 00 00                             mov     edx, [esi+1AC4h]
0041557B  8b 46 70                                      mov     eax, [esi+70h]
0041557E  55                                            push    ebp; lpNumberOfBytesWritten
0041557F  8d 8e cc 1a 00 00                             lea     ecx, [esi+1ACCh]
00415585  6a 01                                         push    1; nSize
00415587  51                                            push    ecx; lpBuffer
00415588  52                                            push    edx; lpBaseAddress
00415589  50                                            push    eax; hProcess
0041558A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041558C  8b 8e b4 1a 00 00                             mov     ecx, [esi+1AB4h]
00415592  8b 56 70                                      mov     edx, [esi+70h]
00415595  8d 9e c0 1a 00 00                             lea     ebx, [esi+1AC0h]
0041559B  55                                            push    ebp; lpNumberOfBytesWritten
0041559C  6a 01                                         push    1; nSize
0041559E  53                                            push    ebx; lpBuffer
0041559F  51                                            push    ecx; lpBaseAddress
004155A0  52                                            push    edx; hProcess
004155A1  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004155A3  8b 86 b8 1a 00 00                             mov     eax, [esi+1AB8h]
004155A9  8b 4e 70                                      mov     ecx, [esi+70h]
004155AC  55                                            push    ebp; lpNumberOfBytesWritten
004155AD  6a 01                                         push    1; nSize
004155AF  53                                            push    ebx; lpBuffer
004155B0  50                                            push    eax; lpBaseAddress
004155B1  51                                            push    ecx; hProcess
004155B2  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004155B4  8b 86 a8 1a 00 00                             mov     eax, [esi+1AA8h]
004155BA  8b 4e 70                                      mov     ecx, [esi+70h]
004155BD  55                                            push    ebp; lpNumberOfBytesWritten
004155BE  8d 96 b0 1a 00 00                             lea     edx, [esi+1AB0h]
004155C4  6a 01                                         push    1; nSize
004155C6  52                                            push    edx; lpBuffer
004155C7  50                                            push    eax; lpBaseAddress
004155C8  51                                            push    ecx; hProcess
004155C9  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004155CB  8b 86 9c 1a 00 00                             mov     eax, [esi+1A9Ch]
004155D1  8b 4e 70                                      mov     ecx, [esi+70h]
004155D4  55                                            push    ebp; lpNumberOfBytesWritten
004155D5  8d 96 a4 1a 00 00                             lea     edx, [esi+1AA4h]
004155DB  6a 01                                         push    1; nSize
004155DD  52                                            push    edx; lpBuffer
004155DE  50                                            push    eax; lpBaseAddress
004155DF  51                                            push    ecx; hProcess
004155E0  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004155E2  8b 86 90 1a 00 00                             mov     eax, [esi+1A90h]
004155E8  8b 4e 70                                      mov     ecx, [esi+70h]
004155EB  55                                            push    ebp; lpNumberOfBytesWritten
004155EC  8d 96 98 1a 00 00                             lea     edx, [esi+1A98h]
004155F2  6a 01                                         push    1; nSize
004155F4  52                                            push    edx; lpBuffer
004155F5  50                                            push    eax; lpBaseAddress
004155F6  51                                            push    ecx; hProcess
004155F7  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004155F9  8b 86 84 1a 00 00                             mov     eax, [esi+1A84h]
004155FF  8b 4e 70                                      mov     ecx, [esi+70h]
00415602  55                                            push    ebp; lpNumberOfBytesWritten
00415603  8d 96 8c 1a 00 00                             lea     edx, [esi+1A8Ch]
00415609  6a 02                                         push    2; nSize
0041560B  52                                            push    edx; lpBuffer
0041560C  50                                            push    eax; lpBaseAddress
0041560D  51                                            push    ecx; hProcess
0041560E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415610  8b 86 78 1a 00 00                             mov     eax, [esi+1A78h]
00415616  8b 4e 70                                      mov     ecx, [esi+70h]
00415619  55                                            push    ebp; lpNumberOfBytesWritten
0041561A  8d 96 80 1a 00 00                             lea     edx, [esi+1A80h]
00415620  6a 01                                         push    1; nSize
00415622  52                                            push    edx; lpBuffer
00415623  50                                            push    eax; lpBaseAddress
00415624  51                                            push    ecx; hProcess
00415625  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415627  8b 86 6c 1a 00 00                             mov     eax, [esi+1A6Ch]
0041562D  8b 4e 70                                      mov     ecx, [esi+70h]
00415630  55                                            push    ebp; lpNumberOfBytesWritten
00415631  8d 96 74 1a 00 00                             lea     edx, [esi+1A74h]
00415637  6a 04                                         push    4; nSize
00415639  52                                            push    edx; lpBuffer
0041563A  50                                            push    eax; lpBaseAddress
0041563B  51                                            push    ecx; hProcess
0041563C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041563E  8b 86 60 1a 00 00                             mov     eax, [esi+1A60h]
00415644  8b 4e 70                                      mov     ecx, [esi+70h]
00415647  55                                            push    ebp; lpNumberOfBytesWritten
00415648  8d 96 68 1a 00 00                             lea     edx, [esi+1A68h]
0041564E  6a 01                                         push    1; nSize
00415650  52                                            push    edx; lpBuffer
00415651  50                                            push    eax; lpBaseAddress
00415652  51                                            push    ecx; hProcess
00415653  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415655  8b 86 54 1a 00 00                             mov     eax, [esi+1A54h]
0041565B  8b 4e 70                                      mov     ecx, [esi+70h]
0041565E  55                                            push    ebp; lpNumberOfBytesWritten
0041565F  8d 96 5c 1a 00 00                             lea     edx, [esi+1A5Ch]
00415665  6a 01                                         push    1; nSize
00415667  52                                            push    edx; lpBuffer
00415668  50                                            push    eax; lpBaseAddress
00415669  51                                            push    ecx; hProcess
0041566A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041566C  8b 86 48 1a 00 00                             mov     eax, [esi+1A48h]
00415672  8b 4e 70                                      mov     ecx, [esi+70h]
00415675  55                                            push    ebp; lpNumberOfBytesWritten
00415676  8d 96 50 1a 00 00                             lea     edx, [esi+1A50h]
0041567C  6a 01                                         push    1; nSize
0041567E  52                                            push    edx; lpBuffer
0041567F  50                                            push    eax; lpBaseAddress
00415680  51                                            push    ecx; hProcess
00415681  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415683  8b 86 3c 1a 00 00                             mov     eax, [esi+1A3Ch]
00415689  8b 4e 70                                      mov     ecx, [esi+70h]
0041568C  55                                            push    ebp; lpNumberOfBytesWritten
0041568D  8d 96 44 1a 00 00                             lea     edx, [esi+1A44h]
00415693  6a 01                                         push    1; nSize
00415695  52                                            push    edx; lpBuffer
00415696  50                                            push    eax; lpBaseAddress
00415697  51                                            push    ecx; hProcess
00415698  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041569A  8b 96 38 1a 00 00                             mov     edx, [esi+1A38h]
004156A0  8b 46 70                                      mov     eax, [esi+70h]
004156A3  8d 9e 34 1a 00 00                             lea     ebx, [esi+1A34h]
004156A9  55                                            push    ebp; lpNumberOfBytesWritten
004156AA  6a 01                                         push    1; nSize
004156AC  53                                            push    ebx; lpBuffer
004156AD  52                                            push    edx; lpBaseAddress
004156AE  50                                            push    eax; hProcess
004156AF  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004156B1  8b 8e 2c 1a 00 00                             mov     ecx, [esi+1A2Ch]
004156B7  8b 56 70                                      mov     edx, [esi+70h]
004156BA  55                                            push    ebp; lpNumberOfBytesWritten
004156BB  6a 01                                         push    1; nSize
004156BD  53                                            push    ebx; lpBuffer
004156BE  51                                            push    ecx; lpBaseAddress
004156BF  52                                            push    edx; hProcess
004156C0  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004156C2  8b 86 2c 1a 00 00                             mov     eax, [esi+1A2Ch]
004156C8  8b 4e 70                                      mov     ecx, [esi+70h]
004156CB  55                                            push    ebp; lpNumberOfBytesWritten
004156CC  6a 01                                         push    1; nSize
004156CE  83 c0 30                                      add     eax, 30h ; '0'
004156D1  53                                            push    ebx; lpBuffer
004156D2  50                                            push    eax; lpBaseAddress
004156D3  51                                            push    ecx; hProcess
004156D4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004156D6  8b 96 2c 1a 00 00                             mov     edx, [esi+1A2Ch]
004156DC  8b 46 70                                      mov     eax, [esi+70h]
004156DF  55                                            push    ebp; lpNumberOfBytesWritten
004156E0  6a 01                                         push    1; nSize
004156E2  83 c2 60                                      add     edx, 60h ; '`'
004156E5  53                                            push    ebx; lpBuffer
004156E6  52                                            push    edx; lpBaseAddress
004156E7  50                                            push    eax; hProcess
004156E8  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004156EA  8b 8e 2c 1a 00 00                             mov     ecx, [esi+1A2Ch]
004156F0  8b 56 70                                      mov     edx, [esi+70h]
004156F3  55                                            push    ebp; lpNumberOfBytesWritten
004156F4  6a 01                                         push    1; nSize
004156F6  81 c1 90 00 00 00                             add     ecx, 90h
004156FC  53                                            push    ebx; lpBuffer
004156FD  51                                            push    ecx; lpBaseAddress
004156FE  52                                            push    edx; hProcess
004156FF  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415701  8b 86 c4 19 00 00                             mov     eax, [esi+19C4h]
00415707  8b 4e 70                                      mov     ecx, [esi+70h]
0041570A  8d 9e d4 19 00 00                             lea     ebx, [esi+19D4h]
00415710  55                                            push    ebp; lpNumberOfBytesWritten
00415711  6a 01                                         push    1; nSize
00415713  53                                            push    ebx; lpBuffer
00415714  50                                            push    eax; lpBaseAddress
00415715  51                                            push    ecx; hProcess
00415716  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415718  8b 96 c8 19 00 00                             mov     edx, [esi+19C8h]
0041571E  8b 46 70                                      mov     eax, [esi+70h]
00415721  55                                            push    ebp; lpNumberOfBytesWritten
00415722  6a 01                                         push    1; nSize
00415724  53                                            push    ebx; lpBuffer
00415725  52                                            push    edx; lpBaseAddress
00415726  50                                            push    eax; hProcess
00415727  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415729  8b 8e cc 19 00 00                             mov     ecx, [esi+19CCh]
0041572F  8b 56 70                                      mov     edx, [esi+70h]
00415732  55                                            push    ebp; lpNumberOfBytesWritten
00415733  6a 01                                         push    1; nSize
00415735  53                                            push    ebx; lpBuffer
00415736  51                                            push    ecx; lpBaseAddress
00415737  52                                            push    edx; hProcess
00415738  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041573A  8b 8e 1c 1a 00 00                             mov     ecx, [esi+1A1Ch]
00415740  8b 56 70                                      mov     edx, [esi+70h]
00415743  55                                            push    ebp; lpNumberOfBytesWritten
00415744  8d 86 24 1a 00 00                             lea     eax, [esi+1A24h]
0041574A  6a 01                                         push    1; nSize
0041574C  50                                            push    eax; lpBuffer
0041574D  51                                            push    ecx; lpBaseAddress
0041574E  52                                            push    edx; hProcess
0041574F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415751  8b 8e 10 1a 00 00                             mov     ecx, [esi+1A10h]
00415757  8b 56 70                                      mov     edx, [esi+70h]
0041575A  55                                            push    ebp; lpNumberOfBytesWritten
0041575B  8d 86 18 1a 00 00                             lea     eax, [esi+1A18h]
00415761  6a 04                                         push    4; nSize
00415763  50                                            push    eax; lpBuffer
00415764  51                                            push    ecx; lpBaseAddress
00415765  52                                            push    edx; hProcess
00415766  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415768  8b 8e 04 1a 00 00                             mov     ecx, [esi+1A04h]
0041576E  8b 56 70                                      mov     edx, [esi+70h]
00415771  55                                            push    ebp; lpNumberOfBytesWritten
00415772  8d 86 0c 1a 00 00                             lea     eax, [esi+1A0Ch]
00415778  6a 01                                         push    1; nSize
0041577A  50                                            push    eax; lpBuffer
0041577B  51                                            push    ecx; lpBaseAddress
0041577C  52                                            push    edx; hProcess
0041577D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041577F  8b 8e f8 19 00 00                             mov     ecx, [esi+19F8h]
00415785  8b 56 70                                      mov     edx, [esi+70h]
00415788  55                                            push    ebp; lpNumberOfBytesWritten
00415789  8d 86 00 1a 00 00                             lea     eax, [esi+1A00h]
0041578F  6a 01                                         push    1; nSize
00415791  50                                            push    eax; lpBuffer
00415792  51                                            push    ecx; lpBaseAddress
00415793  52                                            push    edx; hProcess
00415794  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415796  8b 8e ec 19 00 00                             mov     ecx, [esi+19ECh]
0041579C  8b 56 70                                      mov     edx, [esi+70h]
0041579F  55                                            push    ebp; lpNumberOfBytesWritten
004157A0  8d 86 f4 19 00 00                             lea     eax, [esi+19F4h]
004157A6  6a 01                                         push    1; nSize
004157A8  50                                            push    eax; lpBuffer
004157A9  51                                            push    ecx; lpBaseAddress
004157AA  52                                            push    edx; hProcess
004157AB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004157AD  8b 8e b8 19 00 00                             mov     ecx, [esi+19B8h]
004157B3  8b 56 70                                      mov     edx, [esi+70h]
004157B6  55                                            push    ebp; lpNumberOfBytesWritten
004157B7  8d 86 c0 19 00 00                             lea     eax, [esi+19C0h]
004157BD  6a 01                                         push    1; nSize
004157BF  50                                            push    eax; lpBuffer
004157C0  51                                            push    ecx; lpBaseAddress
004157C1  52                                            push    edx; hProcess
004157C2  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004157C4  8b 8e b0 19 00 00                             mov     ecx, [esi+19B0h]
004157CA  8b 56 70                                      mov     edx, [esi+70h]
004157CD  55                                            push    ebp; lpNumberOfBytesWritten
004157CE  8d 86 b4 19 00 00                             lea     eax, [esi+19B4h]
004157D4  6a 01                                         push    1; nSize
004157D6  50                                            push    eax; lpBuffer
004157D7  51                                            push    ecx; lpBaseAddress
004157D8  52                                            push    edx; hProcess
004157D9  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004157DB  55                                            push    ebp; lpNumberOfBytesWritten
004157DC  6a 04                                         push    4; nSize
004157DE  8b 8e a4 19 00 00                             mov     ecx, [esi+19A4h]
004157E4  8b 56 70                                      mov     edx, [esi+70h]
004157E7  8d 86 ac 19 00 00                             lea     eax, [esi+19ACh]
004157ED  50                                            push    eax; lpBuffer
004157EE  51                                            push    ecx; lpBaseAddress
004157EF  52                                            push    edx; hProcess
004157F0  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004157F2  8b 8e 98 19 00 00                             mov     ecx, [esi+1998h]
004157F8  8b 56 70                                      mov     edx, [esi+70h]
004157FB  55                                            push    ebp; lpNumberOfBytesWritten
004157FC  8d 86 a0 19 00 00                             lea     eax, [esi+19A0h]
00415802  6a 01                                         push    1; nSize
00415804  50                                            push    eax; lpBuffer
00415805  51                                            push    ecx; lpBaseAddress
00415806  52                                            push    edx; hProcess
00415807  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415809  8b 8e 04 19 00 00                             mov     ecx, [esi+1904h]
0041580F  8b 56 70                                      mov     edx, [esi+70h]
00415812  55                                            push    ebp; lpNumberOfBytesWritten
00415813  8d 86 0c 19 00 00                             lea     eax, [esi+190Ch]
00415819  6a 01                                         push    1; nSize
0041581B  50                                            push    eax; lpBuffer
0041581C  51                                            push    ecx; lpBaseAddress
0041581D  52                                            push    edx; hProcess
0041581E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415820  8b 8e 74 19 00 00                             mov     ecx, [esi+1974h]
00415826  8b 56 70                                      mov     edx, [esi+70h]
00415829  55                                            push    ebp; lpNumberOfBytesWritten
0041582A  8d 86 7c 19 00 00                             lea     eax, [esi+197Ch]
00415830  6a 04                                         push    4; nSize
00415832  50                                            push    eax; lpBuffer
00415833  51                                            push    ecx; lpBaseAddress
00415834  52                                            push    edx; hProcess
00415835  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415837  8b 8e 8c 19 00 00                             mov     ecx, [esi+198Ch]
0041583D  8b 56 70                                      mov     edx, [esi+70h]
00415840  55                                            push    ebp; lpNumberOfBytesWritten
00415841  8d 86 94 19 00 00                             lea     eax, [esi+1994h]
00415847  6a 01                                         push    1; nSize
00415849  50                                            push    eax; lpBuffer
0041584A  51                                            push    ecx; lpBaseAddress
0041584B  52                                            push    edx; hProcess
0041584C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041584E  8b 8e 68 19 00 00                             mov     ecx, [esi+1968h]
00415854  8b 56 70                                      mov     edx, [esi+70h]
00415857  55                                            push    ebp; lpNumberOfBytesWritten
00415858  8d 86 70 19 00 00                             lea     eax, [esi+1970h]
0041585E  6a 04                                         push    4; nSize
00415860  50                                            push    eax; lpBuffer
00415861  51                                            push    ecx; lpBaseAddress
00415862  52                                            push    edx; hProcess
00415863  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415865  8b 8e 80 19 00 00                             mov     ecx, [esi+1980h]
0041586B  8b 56 70                                      mov     edx, [esi+70h]
0041586E  55                                            push    ebp; lpNumberOfBytesWritten
0041586F  8d 86 88 19 00 00                             lea     eax, [esi+1988h]
00415875  6a 01                                         push    1; nSize
00415877  50                                            push    eax; lpBuffer
00415878  51                                            push    ecx; lpBaseAddress
00415879  52                                            push    edx; hProcess
0041587A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041587C  8b 8e 5c 19 00 00                             mov     ecx, [esi+195Ch]
00415882  8b 56 70                                      mov     edx, [esi+70h]
00415885  55                                            push    ebp; lpNumberOfBytesWritten
00415886  8d 86 64 19 00 00                             lea     eax, [esi+1964h]
0041588C  6a 04                                         push    4; nSize
0041588E  50                                            push    eax; lpBuffer
0041588F  51                                            push    ecx; lpBaseAddress
00415890  52                                            push    edx; hProcess
00415891  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415893  8b 8e bc 18 00 00                             mov     ecx, [esi+18BCh]
00415899  8b 56 70                                      mov     edx, [esi+70h]
0041589C  55                                            push    ebp; lpNumberOfBytesWritten
0041589D  8d 86 c4 18 00 00                             lea     eax, [esi+18C4h]
004158A3  6a 01                                         push    1; nSize
004158A5  50                                            push    eax; lpBuffer
004158A6  51                                            push    ecx; lpBaseAddress
004158A7  52                                            push    edx; hProcess
004158A8  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004158AA  55                                            push    ebp; lpNumberOfBytesWritten
004158AB  6a 01                                         push    1; nSize
004158AD  8b 8e f8 18 00 00                             mov     ecx, [esi+18F8h]
004158B3  8b 56 70                                      mov     edx, [esi+70h]
004158B6  8d 86 00 19 00 00                             lea     eax, [esi+1900h]
004158BC  50                                            push    eax; lpBuffer
004158BD  51                                            push    ecx; lpBaseAddress
004158BE  52                                            push    edx; hProcess
004158BF  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004158C1  8b 8e ec 18 00 00                             mov     ecx, [esi+18ECh]
004158C7  8b 56 70                                      mov     edx, [esi+70h]
004158CA  55                                            push    ebp; lpNumberOfBytesWritten
004158CB  8d 86 f4 18 00 00                             lea     eax, [esi+18F4h]
004158D1  6a 01                                         push    1; nSize
004158D3  50                                            push    eax; lpBuffer
004158D4  51                                            push    ecx; lpBaseAddress
004158D5  52                                            push    edx; hProcess
004158D6  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004158D8  8b 8e e0 18 00 00                             mov     ecx, [esi+18E0h]
004158DE  8b 56 70                                      mov     edx, [esi+70h]
004158E1  55                                            push    ebp; lpNumberOfBytesWritten
004158E2  8d 86 e8 18 00 00                             lea     eax, [esi+18E8h]
004158E8  6a 01                                         push    1; nSize
004158EA  50                                            push    eax; lpBuffer
004158EB  51                                            push    ecx; lpBaseAddress
004158EC  52                                            push    edx; hProcess
004158ED  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004158EF  8b 8e d4 18 00 00                             mov     ecx, [esi+18D4h]
004158F5  8b 56 70                                      mov     edx, [esi+70h]
004158F8  55                                            push    ebp; lpNumberOfBytesWritten
004158F9  8d 86 dc 18 00 00                             lea     eax, [esi+18DCh]
004158FF  6a 01                                         push    1; nSize
00415901  50                                            push    eax; lpBuffer
00415902  51                                            push    ecx; lpBaseAddress
00415903  52                                            push    edx; hProcess
00415904  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415906  8b 8e c8 18 00 00                             mov     ecx, [esi+18C8h]
0041590C  8b 56 70                                      mov     edx, [esi+70h]
0041590F  55                                            push    ebp; lpNumberOfBytesWritten
00415910  8d 86 d0 18 00 00                             lea     eax, [esi+18D0h]
00415916  6a 01                                         push    1; nSize
00415918  50                                            push    eax; lpBuffer
00415919  51                                            push    ecx; lpBaseAddress
0041591A  52                                            push    edx; hProcess
0041591B  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041591D  8b 86 44 19 00 00                             mov     eax, [esi+1944h]
00415923  8b 4e 70                                      mov     ecx, [esi+70h]
00415926  8d 9e 4c 19 00 00                             lea     ebx, [esi+194Ch]
0041592C  55                                            push    ebp; lpNumberOfBytesWritten
0041592D  6a 01                                         push    1; nSize
0041592F  53                                            push    ebx; lpBuffer
00415930  50                                            push    eax; lpBaseAddress
00415931  51                                            push    ecx; hProcess
00415932  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415934  8b 86 50 19 00 00                             mov     eax, [esi+1950h]
0041593A  8b 4e 70                                      mov     ecx, [esi+70h]
0041593D  55                                            push    ebp; lpNumberOfBytesWritten
0041593E  8d 96 58 19 00 00                             lea     edx, [esi+1958h]
00415944  6a 01                                         push    1; nSize
00415946  52                                            push    edx; lpBuffer
00415947  50                                            push    eax; lpBaseAddress
00415948  51                                            push    ecx; hProcess
00415949  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041594B  8b 96 40 19 00 00                             mov     edx, [esi+1940h]
00415951  8b 46 70                                      mov     eax, [esi+70h]
00415954  55                                            push    ebp; lpNumberOfBytesWritten
00415955  6a 01                                         push    1; nSize
00415957  53                                            push    ebx; lpBuffer
00415958  52                                            push    edx; lpBaseAddress
00415959  50                                            push    eax; hProcess
0041595A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041595C  8b 96 34 19 00 00                             mov     edx, [esi+1934h]
00415962  8b 46 70                                      mov     eax, [esi+70h]
00415965  55                                            push    ebp; lpNumberOfBytesWritten
00415966  8d 8e 3c 19 00 00                             lea     ecx, [esi+193Ch]
0041596C  6a 04                                         push    4; nSize
0041596E  51                                            push    ecx; lpBuffer
0041596F  52                                            push    edx; lpBaseAddress
00415970  50                                            push    eax; hProcess
00415971  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415973  55                                            push    ebp; lpNumberOfBytesWritten
00415974  6a 01                                         push    1; nSize
00415976  8d 8e 24 19 00 00                             lea     ecx, [esi+1924h]
0041597C  8b 96 1c 19 00 00                             mov     edx, [esi+191Ch]
00415982  8b 46 70                                      mov     eax, [esi+70h]
00415985  51                                            push    ecx; lpBuffer
00415986  52                                            push    edx; lpBaseAddress
00415987  50                                            push    eax; hProcess
00415988  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041598A  8b 96 10 19 00 00                             mov     edx, [esi+1910h]
00415990  8b 46 70                                      mov     eax, [esi+70h]
00415993  55                                            push    ebp; lpNumberOfBytesWritten
00415994  8d 8e 18 19 00 00                             lea     ecx, [esi+1918h]
0041599A  6a 01                                         push    1; nSize
0041599C  51                                            push    ecx; lpBuffer
0041599D  52                                            push    edx; lpBaseAddress
0041599E  50                                            push    eax; hProcess
0041599F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004159A1  8b 96 5c 18 00 00                             mov     edx, [esi+185Ch]
004159A7  8b 46 70                                      mov     eax, [esi+70h]
004159AA  55                                            push    ebp; lpNumberOfBytesWritten
004159AB  8d 8e 64 18 00 00                             lea     ecx, [esi+1864h]
004159B1  6a 01                                         push    1; nSize
004159B3  51                                            push    ecx; lpBuffer
004159B4  52                                            push    edx; lpBaseAddress
004159B5  50                                            push    eax; hProcess
004159B6  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004159B8  8b 96 b0 18 00 00                             mov     edx, [esi+18B0h]
004159BE  8b 46 70                                      mov     eax, [esi+70h]
004159C1  55                                            push    ebp; lpNumberOfBytesWritten
004159C2  8d 8e b8 18 00 00                             lea     ecx, [esi+18B8h]
004159C8  6a 04                                         push    4; nSize
004159CA  51                                            push    ecx; lpBuffer
004159CB  52                                            push    edx; lpBaseAddress
004159CC  50                                            push    eax; hProcess
004159CD  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004159CF  8b 96 a4 18 00 00                             mov     edx, [esi+18A4h]
004159D5  8b 46 70                                      mov     eax, [esi+70h]
004159D8  55                                            push    ebp; lpNumberOfBytesWritten
004159D9  8d 8e ac 18 00 00                             lea     ecx, [esi+18ACh]
004159DF  6a 04                                         push    4; nSize
004159E1  51                                            push    ecx; lpBuffer
004159E2  52                                            push    edx; lpBaseAddress
004159E3  50                                            push    eax; hProcess
004159E4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004159E6  8b 96 98 18 00 00                             mov     edx, [esi+1898h]
004159EC  8b 46 70                                      mov     eax, [esi+70h]
004159EF  55                                            push    ebp; lpNumberOfBytesWritten
004159F0  8d 8e a0 18 00 00                             lea     ecx, [esi+18A0h]
004159F6  6a 04                                         push    4; nSize
004159F8  51                                            push    ecx; lpBuffer
004159F9  52                                            push    edx; lpBaseAddress
004159FA  50                                            push    eax; hProcess
004159FB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004159FD  8b 96 8c 18 00 00                             mov     edx, [esi+188Ch]
00415A03  8b 46 70                                      mov     eax, [esi+70h]
00415A06  55                                            push    ebp; lpNumberOfBytesWritten
00415A07  8d 8e 94 18 00 00                             lea     ecx, [esi+1894h]
00415A0D  6a 04                                         push    4; nSize
00415A0F  51                                            push    ecx; lpBuffer
00415A10  52                                            push    edx; lpBaseAddress
00415A11  50                                            push    eax; hProcess
00415A12  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415A14  8b 96 80 18 00 00                             mov     edx, [esi+1880h]
00415A1A  8b 46 70                                      mov     eax, [esi+70h]
00415A1D  55                                            push    ebp; lpNumberOfBytesWritten
00415A1E  8d 8e 88 18 00 00                             lea     ecx, [esi+1888h]
00415A24  6a 04                                         push    4; nSize
00415A26  51                                            push    ecx; lpBuffer
00415A27  52                                            push    edx; lpBaseAddress
00415A28  50                                            push    eax; hProcess
00415A29  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415A2B  8b 96 74 18 00 00                             mov     edx, [esi+1874h]
00415A31  8b 46 70                                      mov     eax, [esi+70h]
00415A34  55                                            push    ebp; lpNumberOfBytesWritten
00415A35  8d 8e 7c 18 00 00                             lea     ecx, [esi+187Ch]
00415A3B  6a 01                                         push    1; nSize
00415A3D  51                                            push    ecx; lpBuffer
00415A3E  52                                            push    edx; lpBaseAddress
00415A3F  50                                            push    eax; hProcess
00415A40  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415A42  55                                            push    ebp; lpNumberOfBytesWritten
00415A43  6a 01                                         push    1; nSize
00415A45  8d 8e 70 18 00 00                             lea     ecx, [esi+1870h]
00415A4B  8b 96 68 18 00 00                             mov     edx, [esi+1868h]
00415A51  8b 46 70                                      mov     eax, [esi+70h]
00415A54  51                                            push    ecx; lpBuffer
00415A55  52                                            push    edx; lpBaseAddress
00415A56  50                                            push    eax; hProcess
00415A57  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415A59  8b 8e 50 18 00 00                             mov     ecx, [esi+1850h]
00415A5F  8b 56 70                                      mov     edx, [esi+70h]
00415A62  8d 9e 58 18 00 00                             lea     ebx, [esi+1858h]
00415A68  55                                            push    ebp; lpNumberOfBytesWritten
00415A69  6a 01                                         push    1; nSize
00415A6B  53                                            push    ebx; lpBuffer
00415A6C  51                                            push    ecx; lpBaseAddress
00415A6D  52                                            push    edx; hProcess
00415A6E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415A70  8b 86 54 18 00 00                             mov     eax, [esi+1854h]
00415A76  8b 4e 70                                      mov     ecx, [esi+70h]
00415A79  55                                            push    ebp; lpNumberOfBytesWritten
00415A7A  6a 01                                         push    1; nSize
00415A7C  53                                            push    ebx; lpBuffer
00415A7D  50                                            push    eax; lpBaseAddress
00415A7E  51                                            push    ecx; hProcess
00415A7F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415A81  8b 15 c0 b5 42 00                             mov     edx, dword_42B5C0
00415A87  a1 c4 b5 42 00                                mov     eax, off_42B5C4
00415A8C  8b 0d bc b5 42 00                             mov     ecx, dword_42B5BC
00415A92  55                                            push    ebp; lpNumberOfBytesWritten
00415A93  52                                            push    edx; nSize
00415A94  8b 56 70                                      mov     edx, [esi+70h]
00415A97  50                                            push    eax; lpBuffer
00415A98  51                                            push    ecx; lpBaseAddress
00415A99  52                                            push    edx; hProcess
00415A9A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415A9C  a1 f8 85 42 00                                mov     eax, dword_4285F8
00415AA1  8b 0d fc 85 42 00                             mov     ecx, off_4285FC
00415AA7  8b 15 f4 85 42 00                             mov     edx, dword_4285F4
00415AAD  55                                            push    ebp; lpNumberOfBytesWritten
00415AAE  50                                            push    eax; nSize
00415AAF  8b 46 70                                      mov     eax, [esi+70h]
00415AB2  51                                            push    ecx; lpBuffer
00415AB3  52                                            push    edx; lpBaseAddress
00415AB4  50                                            push    eax; hProcess
00415AB5  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415AB7  8b 0d 98 71 42 00                             mov     ecx, dword_427198
00415ABD  8b 15 9c 71 42 00                             mov     edx, off_42719C
00415AC3  a1 94 71 42 00                                mov     eax, dword_427194
00415AC8  55                                            push    ebp; lpNumberOfBytesWritten
00415AC9  51                                            push    ecx; nSize
00415ACA  8b 4e 70                                      mov     ecx, [esi+70h]
00415ACD  52                                            push    edx; lpBuffer
00415ACE  50                                            push    eax; lpBaseAddress
00415ACF  51                                            push    ecx; hProcess
00415AD0  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415AD2  8b 15 b8 53 42 00                             mov     edx, dword_4253B8
00415AD8  a1 bc 53 42 00                                mov     eax, off_4253BC
00415ADD  8b 0d b4 53 42 00                             mov     ecx, dword_4253B4
00415AE3  55                                            push    ebp; lpNumberOfBytesWritten
00415AE4  52                                            push    edx; nSize
00415AE5  8b 56 70                                      mov     edx, [esi+70h]
00415AE8  50                                            push    eax; lpBuffer
00415AE9  51                                            push    ecx; lpBaseAddress
00415AEA  52                                            push    edx; hProcess
00415AEB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415AED  a1 18 44 42 00                                mov     eax, dword_424418
00415AF2  8b 0d 1c 44 42 00                             mov     ecx, off_42441C
00415AF8  8b 15 14 44 42 00                             mov     edx, dword_424414
00415AFE  55                                            push    ebp; lpNumberOfBytesWritten
00415AFF  50                                            push    eax; nSize
00415B00  8b 46 70                                      mov     eax, [esi+70h]
00415B03  51                                            push    ecx; lpBuffer
00415B04  52                                            push    edx; lpBaseAddress
00415B05  50                                            push    eax; hProcess
00415B06  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415B08  8b 0d f0 43 42 00                             mov     ecx, dword_4243F0
00415B0E  8b 15 f4 43 42 00                             mov     edx, off_4243F4
00415B14  a1 ec 43 42 00                                mov     eax, dword_4243EC
00415B19  55                                            push    ebp; lpNumberOfBytesWritten
00415B1A  51                                            push    ecx; nSize
00415B1B  8b 4e 70                                      mov     ecx, [esi+70h]
00415B1E  52                                            push    edx; lpBuffer
00415B1F  50                                            push    eax; lpBaseAddress
00415B20  51                                            push    ecx; hProcess
00415B21  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415B23  8b 15 70 43 42 00                             mov     edx, dword_424370
00415B29  a1 74 43 42 00                                mov     eax, off_424374
00415B2E  8b 0d 6c 43 42 00                             mov     ecx, dword_42436C
00415B34  55                                            push    ebp; lpNumberOfBytesWritten
00415B35  52                                            push    edx; nSize
00415B36  8b 56 70                                      mov     edx, [esi+70h]
00415B39  50                                            push    eax; lpBuffer
00415B3A  51                                            push    ecx; lpBaseAddress
00415B3B  52                                            push    edx; hProcess
00415B3C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415B3E  a1 50 42 42 00                                mov     eax, dword_424250
00415B43  8b 0d 54 42 42 00                             mov     ecx, off_424254
00415B49  8b 15 4c 42 42 00                             mov     edx, dword_42424C
00415B4F  55                                            push    ebp; lpNumberOfBytesWritten
00415B50  50                                            push    eax; nSize
00415B51  8b 46 70                                      mov     eax, [esi+70h]
00415B54  51                                            push    ecx; lpBuffer
00415B55  52                                            push    edx; lpBaseAddress
00415B56  50                                            push    eax; hProcess
00415B57  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415B59  8b 0d f8 17 42 00                             mov     ecx, dword_4217F8
00415B5F  8b 15 fc 17 42 00                             mov     edx, off_4217FC
00415B65  a1 f4 17 42 00                                mov     eax, dword_4217F4
00415B6A  55                                            push    ebp; lpNumberOfBytesWritten
00415B6B  51                                            push    ecx; nSize
00415B6C  8b 4e 70                                      mov     ecx, [esi+70h]
00415B6F  52                                            push    edx; lpBuffer
00415B70  50                                            push    eax; lpBaseAddress
00415B71  51                                            push    ecx; hProcess
00415B72  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415B74  8b 15 c8 17 42 00                             mov     edx, dword_4217C8
00415B7A  a1 cc 17 42 00                                mov     eax, off_4217CC
00415B7F  8b 0d c4 17 42 00                             mov     ecx, dword_4217C4
00415B85  55                                            push    ebp; lpNumberOfBytesWritten
00415B86  52                                            push    edx; nSize
00415B87  8b 56 70                                      mov     edx, [esi+70h]
00415B8A  50                                            push    eax; lpBuffer
00415B8B  51                                            push    ecx; lpBaseAddress
00415B8C  52                                            push    edx; hProcess
00415B8D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415B8F  a1 98 17 42 00                                mov     eax, dword_421798
00415B94  8b 0d 9c 17 42 00                             mov     ecx, off_42179C
00415B9A  8b 15 94 17 42 00                             mov     edx, dword_421794
00415BA0  55                                            push    ebp; lpNumberOfBytesWritten
00415BA1  50                                            push    eax; nSize
00415BA2  8b 46 70                                      mov     eax, [esi+70h]
00415BA5  51                                            push    ecx; lpBuffer
00415BA6  52                                            push    edx; lpBaseAddress
00415BA7  50                                            push    eax; hProcess
00415BA8  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415BAA  8b 0d 98 f9 41 00                             mov     ecx, dword_41F998
00415BB0  8b 15 9c f9 41 00                             mov     edx, off_41F99C
00415BB6  a1 94 f9 41 00                                mov     eax, dword_41F994
00415BBB  55                                            push    ebp; lpNumberOfBytesWritten
00415BBC  51                                            push    ecx; nSize
00415BBD  8b 4e 70                                      mov     ecx, [esi+70h]
00415BC0  52                                            push    edx; lpBuffer
00415BC1  50                                            push    eax; lpBaseAddress
00415BC2  51                                            push    ecx; hProcess
00415BC3  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415BC5  8b 15 c8 f8 41 00                             mov     edx, dword_41F8C8
00415BCB  a1 cc f8 41 00                                mov     eax, off_41F8CC
00415BD0  8b 0d c4 f8 41 00                             mov     ecx, dword_41F8C4
00415BD6  55                                            push    ebp; lpNumberOfBytesWritten
00415BD7  52                                            push    edx; nSize
00415BD8  8b 56 70                                      mov     edx, [esi+70h]
00415BDB  50                                            push    eax; lpBuffer
00415BDC  51                                            push    ecx; lpBaseAddress
00415BDD  52                                            push    edx; hProcess
00415BDE  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415BE0  a1 18 f9 41 00                                mov     eax, dword_41F918
00415BE5  8b 0d 1c f9 41 00                             mov     ecx, off_41F91C
00415BEB  8b 15 14 f9 41 00                             mov     edx, dword_41F914
00415BF1  55                                            push    ebp; lpNumberOfBytesWritten
00415BF2  50                                            push    eax; nSize
00415BF3  8b 46 70                                      mov     eax, [esi+70h]
00415BF6  51                                            push    ecx; lpBuffer
00415BF7  52                                            push    edx; lpBaseAddress
00415BF8  50                                            push    eax; hProcess
00415BF9  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415BFB  8b 0d f0 f8 41 00                             mov     ecx, dword_41F8F0
00415C01  8b 15 f4 f8 41 00                             mov     edx, off_41F8F4
00415C07  a1 ec f8 41 00                                mov     eax, dword_41F8EC
00415C0C  55                                            push    ebp; lpNumberOfBytesWritten
00415C0D  51                                            push    ecx; nSize
00415C0E  8b 4e 70                                      mov     ecx, [esi+70h]
00415C11  52                                            push    edx; lpBuffer
00415C12  50                                            push    eax; lpBaseAddress
00415C13  51                                            push    ecx; hProcess
00415C14  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415C16  8b 15 98 b3 42 00                             mov     edx, dword_42B398
00415C1C  a1 9c b3 42 00                                mov     eax, off_42B39C
00415C21  8b 0d 94 b3 42 00                             mov     ecx, off_42B394
00415C27  55                                            push    ebp; lpNumberOfBytesWritten
00415C28  52                                            push    edx; nSize
00415C29  8b 56 70                                      mov     edx, [esi+70h]
00415C2C  50                                            push    eax; lpBuffer
00415C2D  51                                            push    ecx; lpBaseAddress
00415C2E  52                                            push    edx; hProcess
00415C2F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415C31  a1 c0 b3 42 00                                mov     eax, dword_42B3C0
00415C36  8b 0d c4 b3 42 00                             mov     ecx, off_42B3C4
00415C3C  8b 15 bc b3 42 00                             mov     edx, off_42B3BC
00415C42  55                                            push    ebp; lpNumberOfBytesWritten
00415C43  50                                            push    eax; nSize
00415C44  8b 46 70                                      mov     eax, [esi+70h]
00415C47  51                                            push    ecx; lpBuffer
00415C48  52                                            push    edx; lpBaseAddress
00415C49  50                                            push    eax; hProcess
00415C4A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415C4C  8b 0d e8 b3 42 00                             mov     ecx, dword_42B3E8
00415C52  8b 15 ec b3 42 00                             mov     edx, off_42B3EC
00415C58  a1 e4 b3 42 00                                mov     eax, off_42B3E4
00415C5D  55                                            push    ebp; lpNumberOfBytesWritten
00415C5E  51                                            push    ecx; nSize
00415C5F  8b 4e 70                                      mov     ecx, [esi+70h]
00415C62  52                                            push    edx; lpBuffer
00415C63  50                                            push    eax; lpBaseAddress
00415C64  51                                            push    ecx; hProcess
00415C65  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415C67  8b 15 88 b2 42 00                             mov     edx, dword_42B288
00415C6D  a1 8c b2 42 00                                mov     eax, off_42B28C
00415C72  8b 0d 84 b2 42 00                             mov     ecx, off_42B284
00415C78  55                                            push    ebp; lpNumberOfBytesWritten
00415C79  52                                            push    edx; nSize
00415C7A  8b 56 70                                      mov     edx, [esi+70h]
00415C7D  50                                            push    eax; lpBuffer
00415C7E  51                                            push    ecx; lpBaseAddress
00415C7F  52                                            push    edx; hProcess
00415C80  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415C82  a1 b0 b2 42 00                                mov     eax, dword_42B2B0
00415C87  8b 0d b4 b2 42 00                             mov     ecx, off_42B2B4
00415C8D  8b 15 ac b2 42 00                             mov     edx, off_42B2AC
00415C93  55                                            push    ebp; lpNumberOfBytesWritten
00415C94  50                                            push    eax; nSize
00415C95  8b 46 70                                      mov     eax, [esi+70h]
00415C98  51                                            push    ecx; lpBuffer
00415C99  52                                            push    edx; lpBaseAddress
00415C9A  50                                            push    eax; hProcess
00415C9B  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415C9D  8b 0d c0 b1 42 00                             mov     ecx, dword_42B1C0
00415CA3  8b 15 c4 b1 42 00                             mov     edx, off_42B1C4
00415CA9  a1 bc b1 42 00                                mov     eax, dword_42B1BC
00415CAE  55                                            push    ebp; lpNumberOfBytesWritten
00415CAF  51                                            push    ecx; nSize
00415CB0  8b 4e 70                                      mov     ecx, [esi+70h]
00415CB3  52                                            push    edx; lpBuffer
00415CB4  50                                            push    eax; lpBaseAddress
00415CB5  51                                            push    ecx; hProcess
00415CB6  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415CB8  8b 15 b0 af 42 00                             mov     edx, dword_42AFB0
00415CBE  a1 b4 af 42 00                                mov     eax, off_42AFB4
00415CC3  8b 0d ac af 42 00                             mov     ecx, off_42AFAC
00415CC9  55                                            push    ebp; lpNumberOfBytesWritten
00415CCA  52                                            push    edx; nSize
00415CCB  8b 56 70                                      mov     edx, [esi+70h]
00415CCE  50                                            push    eax; lpBuffer
00415CCF  51                                            push    ecx; lpBaseAddress
00415CD0  52                                            push    edx; hProcess
00415CD1  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415CD3  a1 90 a7 42 00                                mov     eax, dword_42A790
00415CD8  8b 0d 94 a7 42 00                             mov     ecx, off_42A794
00415CDE  8b 15 8c a7 42 00                             mov     edx, dword_42A78C
00415CE4  55                                            push    ebp; lpNumberOfBytesWritten
00415CE5  50                                            push    eax; nSize
00415CE6  8b 46 70                                      mov     eax, [esi+70h]
00415CE9  51                                            push    ecx; lpBuffer
00415CEA  52                                            push    edx; lpBaseAddress
00415CEB  50                                            push    eax; hProcess
00415CEC  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415CEE  8b 0d d0 a5 42 00                             mov     ecx, dword_42A5D0
00415CF4  8b 15 d4 a5 42 00                             mov     edx, off_42A5D4
00415CFA  a1 cc a5 42 00                                mov     eax, dword_42A5CC
00415CFF  55                                            push    ebp; lpNumberOfBytesWritten
00415D00  51                                            push    ecx; nSize
00415D01  8b 4e 70                                      mov     ecx, [esi+70h]
00415D04  52                                            push    edx; lpBuffer
00415D05  50                                            push    eax; lpBaseAddress
00415D06  51                                            push    ecx; hProcess
00415D07  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415D09  8b 15 70 a5 42 00                             mov     edx, dword_42A570
00415D0F  a1 74 a5 42 00                                mov     eax, off_42A574
00415D14  8b 0d 6c a5 42 00                             mov     ecx, dword_42A56C
00415D1A  55                                            push    ebp; lpNumberOfBytesWritten
00415D1B  52                                            push    edx; nSize
00415D1C  8b 56 70                                      mov     edx, [esi+70h]
00415D1F  50                                            push    eax; lpBuffer
00415D20  51                                            push    ecx; lpBaseAddress
00415D21  52                                            push    edx; hProcess
00415D22  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415D24  a1 c0 9d 42 00                                mov     eax, dword_429DC0
00415D29  8b 0d c4 9d 42 00                             mov     ecx, off_429DC4
00415D2F  8b 15 bc 9d 42 00                             mov     edx, dword_429DBC
00415D35  55                                            push    ebp; lpNumberOfBytesWritten
00415D36  50                                            push    eax; nSize
00415D37  8b 46 70                                      mov     eax, [esi+70h]
00415D3A  51                                            push    ecx; lpBuffer
00415D3B  52                                            push    edx; lpBaseAddress
00415D3C  50                                            push    eax; hProcess
00415D3D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415D3F  8b 0d 10 9d 42 00                             mov     ecx, dword_429D10
00415D45  8b 15 14 9d 42 00                             mov     edx, off_429D14
00415D4B  a1 0c 9d 42 00                                mov     eax, dword_429D0C
00415D50  55                                            push    ebp; lpNumberOfBytesWritten
00415D51  51                                            push    ecx; nSize
00415D52  8b 4e 70                                      mov     ecx, [esi+70h]
00415D55  52                                            push    edx; lpBuffer
00415D56  50                                            push    eax; lpBaseAddress
00415D57  51                                            push    ecx; hProcess
00415D58  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415D5A  8b 15 e8 9c 42 00                             mov     edx, dword_429CE8
00415D60  a1 ec 9c 42 00                                mov     eax, off_429CEC
00415D65  8b 0d e4 9c 42 00                             mov     ecx, dword_429CE4
00415D6B  55                                            push    ebp; lpNumberOfBytesWritten
00415D6C  52                                            push    edx; nSize
00415D6D  8b 56 70                                      mov     edx, [esi+70h]
00415D70  50                                            push    eax; lpBuffer
00415D71  51                                            push    ecx; lpBaseAddress
00415D72  52                                            push    edx; hProcess
00415D73  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415D75  a1 c0 9c 42 00                                mov     eax, dword_429CC0
00415D7A  8b 0d c4 9c 42 00                             mov     ecx, off_429CC4
00415D80  8b 15 bc 9c 42 00                             mov     edx, dword_429CBC
00415D86  55                                            push    ebp; lpNumberOfBytesWritten
00415D87  50                                            push    eax; nSize
00415D88  8b 46 70                                      mov     eax, [esi+70h]
00415D8B  51                                            push    ecx; lpBuffer
00415D8C  52                                            push    edx; lpBaseAddress
00415D8D  50                                            push    eax; hProcess
00415D8E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415D90  8b 0d 98 9c 42 00                             mov     ecx, dword_429C98
00415D96  8b 15 9c 9c 42 00                             mov     edx, off_429C9C
00415D9C  a1 94 9c 42 00                                mov     eax, dword_429C94
00415DA1  55                                            push    ebp; lpNumberOfBytesWritten
00415DA2  51                                            push    ecx; nSize
00415DA3  8b 4e 70                                      mov     ecx, [esi+70h]
00415DA6  52                                            push    edx; lpBuffer
00415DA7  50                                            push    eax; lpBaseAddress
00415DA8  51                                            push    ecx; hProcess
00415DA9  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415DAB  55                                            push    ebp; lpNumberOfBytesWritten
00415DAC  8b 15 70 9c 42 00                             mov     edx, dword_429C70
00415DB2  a1 74 9c 42 00                                mov     eax, off_429C74
00415DB7  8b 0d 6c 9c 42 00                             mov     ecx, dword_429C6C
00415DBD  52                                            push    edx; nSize
00415DBE  8b 56 70                                      mov     edx, [esi+70h]
00415DC1  50                                            push    eax; lpBuffer
00415DC2  51                                            push    ecx; lpBaseAddress
00415DC3  52                                            push    edx; hProcess
00415DC4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415DC6  a1 48 9c 42 00                                mov     eax, dword_429C48
00415DCB  8b 0d 4c 9c 42 00                             mov     ecx, off_429C4C
00415DD1  8b 15 44 9c 42 00                             mov     edx, dword_429C44
00415DD7  55                                            push    ebp; lpNumberOfBytesWritten
00415DD8  50                                            push    eax; nSize
00415DD9  8b 46 70                                      mov     eax, [esi+70h]
00415DDC  51                                            push    ecx; lpBuffer
00415DDD  52                                            push    edx; lpBaseAddress
00415DDE  50                                            push    eax; hProcess
00415DDF  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415DE1  8b 0d 20 9c 42 00                             mov     ecx, dword_429C20
00415DE7  8b 15 24 9c 42 00                             mov     edx, off_429C24
00415DED  a1 1c 9c 42 00                                mov     eax, dword_429C1C
00415DF2  55                                            push    ebp; lpNumberOfBytesWritten
00415DF3  51                                            push    ecx; nSize
00415DF4  8b 4e 70                                      mov     ecx, [esi+70h]
00415DF7  52                                            push    edx; lpBuffer
00415DF8  50                                            push    eax; lpBaseAddress
00415DF9  51                                            push    ecx; hProcess
00415DFA  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415DFC  8b 15 f8 9b 42 00                             mov     edx, dword_429BF8
00415E02  a1 fc 9b 42 00                                mov     eax, off_429BFC
00415E07  8b 0d f4 9b 42 00                             mov     ecx, dword_429BF4
00415E0D  55                                            push    ebp; lpNumberOfBytesWritten
00415E0E  52                                            push    edx; nSize
00415E0F  8b 56 70                                      mov     edx, [esi+70h]
00415E12  50                                            push    eax; lpBuffer
00415E13  51                                            push    ecx; lpBaseAddress
00415E14  52                                            push    edx; hProcess
00415E15  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415E17  a1 d0 9b 42 00                                mov     eax, dword_429BD0
00415E1C  8b 0d d4 9b 42 00                             mov     ecx, off_429BD4
00415E22  8b 15 cc 9b 42 00                             mov     edx, dword_429BCC
00415E28  55                                            push    ebp; lpNumberOfBytesWritten
00415E29  50                                            push    eax; nSize
00415E2A  8b 46 70                                      mov     eax, [esi+70h]
00415E2D  51                                            push    ecx; lpBuffer
00415E2E  52                                            push    edx; lpBaseAddress
00415E2F  50                                            push    eax; hProcess
00415E30  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415E32  8b 0d a8 9b 42 00                             mov     ecx, dword_429BA8
00415E38  8b 15 ac 9b 42 00                             mov     edx, off_429BAC
00415E3E  a1 a4 9b 42 00                                mov     eax, dword_429BA4
00415E43  55                                            push    ebp; lpNumberOfBytesWritten
00415E44  51                                            push    ecx; nSize
00415E45  8b 4e 70                                      mov     ecx, [esi+70h]
00415E48  52                                            push    edx; lpBuffer
00415E49  50                                            push    eax; lpBaseAddress
00415E4A  51                                            push    ecx; hProcess
00415E4B  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415E4D  8b 15 80 9b 42 00                             mov     edx, dword_429B80
00415E53  a1 84 9b 42 00                                mov     eax, off_429B84
00415E58  8b 0d 7c 9b 42 00                             mov     ecx, dword_429B7C
00415E5E  55                                            push    ebp; lpNumberOfBytesWritten
00415E5F  52                                            push    edx; nSize
00415E60  8b 56 70                                      mov     edx, [esi+70h]
00415E63  50                                            push    eax; lpBuffer
00415E64  51                                            push    ecx; lpBaseAddress
00415E65  52                                            push    edx; hProcess
00415E66  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415E68  a1 58 9b 42 00                                mov     eax, dword_429B58
00415E6D  8b 0d 5c 9b 42 00                             mov     ecx, off_429B5C
00415E73  8b 15 54 9b 42 00                             mov     edx, dword_429B54
00415E79  55                                            push    ebp; lpNumberOfBytesWritten
00415E7A  50                                            push    eax; nSize
00415E7B  8b 46 70                                      mov     eax, [esi+70h]
00415E7E  51                                            push    ecx; lpBuffer
00415E7F  52                                            push    edx; lpBaseAddress
00415E80  50                                            push    eax; hProcess
00415E81  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415E83  8b 0d 30 9b 42 00                             mov     ecx, dword_429B30
00415E89  55                                            push    ebp; lpNumberOfBytesWritten
00415E8A  8b 15 34 9b 42 00                             mov     edx, off_429B34
00415E90  a1 2c 9b 42 00                                mov     eax, dword_429B2C
00415E95  51                                            push    ecx; nSize
00415E96  8b 4e 70                                      mov     ecx, [esi+70h]
00415E99  52                                            push    edx; lpBuffer
00415E9A  50                                            push    eax; lpBaseAddress
00415E9B  51                                            push    ecx; hProcess
00415E9C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415E9E  8b 15 08 9b 42 00                             mov     edx, dword_429B08
00415EA4  a1 0c 9b 42 00                                mov     eax, off_429B0C
00415EA9  8b 0d 04 9b 42 00                             mov     ecx, dword_429B04
00415EAF  55                                            push    ebp; lpNumberOfBytesWritten
00415EB0  52                                            push    edx; nSize
00415EB1  8b 56 70                                      mov     edx, [esi+70h]
00415EB4  50                                            push    eax; lpBuffer
00415EB5  51                                            push    ecx; lpBaseAddress
00415EB6  52                                            push    edx; hProcess
00415EB7  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415EB9  a1 e0 9a 42 00                                mov     eax, dword_429AE0
00415EBE  8b 0d e4 9a 42 00                             mov     ecx, off_429AE4
00415EC4  8b 15 dc 9a 42 00                             mov     edx, dword_429ADC
00415ECA  55                                            push    ebp; lpNumberOfBytesWritten
00415ECB  50                                            push    eax; nSize
00415ECC  8b 46 70                                      mov     eax, [esi+70h]
00415ECF  51                                            push    ecx; lpBuffer
00415ED0  52                                            push    edx; lpBaseAddress
00415ED1  50                                            push    eax; hProcess
00415ED2  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415ED4  8b 0d b8 9a 42 00                             mov     ecx, dword_429AB8
00415EDA  8b 15 bc 9a 42 00                             mov     edx, off_429ABC
00415EE0  a1 b4 9a 42 00                                mov     eax, dword_429AB4
00415EE5  55                                            push    ebp; lpNumberOfBytesWritten
00415EE6  51                                            push    ecx; nSize
00415EE7  8b 4e 70                                      mov     ecx, [esi+70h]
00415EEA  52                                            push    edx; lpBuffer
00415EEB  50                                            push    eax; lpBaseAddress
00415EEC  51                                            push    ecx; hProcess
00415EED  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415EEF  8b 15 40 a0 42 00                             mov     edx, dword_42A040
00415EF5  a1 44 a0 42 00                                mov     eax, off_42A044
00415EFA  8b 0d 3c a0 42 00                             mov     ecx, dword_42A03C
00415F00  55                                            push    ebp; lpNumberOfBytesWritten
00415F01  52                                            push    edx; nSize
00415F02  8b 56 70                                      mov     edx, [esi+70h]
00415F05  50                                            push    eax; lpBuffer
00415F06  51                                            push    ecx; lpBaseAddress
00415F07  52                                            push    edx; hProcess
00415F08  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415F0A  a1 18 a0 42 00                                mov     eax, dword_42A018
00415F0F  8b 0d 1c a0 42 00                             mov     ecx, off_42A01C
00415F15  8b 15 14 a0 42 00                             mov     edx, dword_42A014
00415F1B  55                                            push    ebp; lpNumberOfBytesWritten
00415F1C  50                                            push    eax; nSize
00415F1D  8b 46 70                                      mov     eax, [esi+70h]
00415F20  51                                            push    ecx; lpBuffer
00415F21  52                                            push    edx; lpBaseAddress
00415F22  50                                            push    eax; hProcess
00415F23  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415F25  8b 0d f0 9f 42 00                             mov     ecx, dword_429FF0
00415F2B  8b 15 f4 9f 42 00                             mov     edx, off_429FF4
00415F31  a1 ec 9f 42 00                                mov     eax, dword_429FEC
00415F36  55                                            push    ebp; lpNumberOfBytesWritten
00415F37  51                                            push    ecx; nSize
00415F38  8b 4e 70                                      mov     ecx, [esi+70h]
00415F3B  52                                            push    edx; lpBuffer
00415F3C  50                                            push    eax; lpBaseAddress
00415F3D  51                                            push    ecx; hProcess
00415F3E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415F40  8b 15 c8 9f 42 00                             mov     edx, dword_429FC8
00415F46  a1 cc 9f 42 00                                mov     eax, off_429FCC
00415F4B  8b 0d c4 9f 42 00                             mov     ecx, dword_429FC4
00415F51  55                                            push    ebp; lpNumberOfBytesWritten
00415F52  52                                            push    edx; nSize
00415F53  8b 56 70                                      mov     edx, [esi+70h]
00415F56  50                                            push    eax; lpBuffer
00415F57  51                                            push    ecx; lpBaseAddress
00415F58  52                                            push    edx; hProcess
00415F59  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415F5B  a1 a0 9f 42 00                                mov     eax, dword_429FA0
00415F60  55                                            push    ebp; lpNumberOfBytesWritten
00415F61  50                                            push    eax; nSize
00415F62  8b 0d a4 9f 42 00                             mov     ecx, off_429FA4
00415F68  8b 15 9c 9f 42 00                             mov     edx, dword_429F9C
00415F6E  8b 46 70                                      mov     eax, [esi+70h]
00415F71  51                                            push    ecx; lpBuffer
00415F72  52                                            push    edx; lpBaseAddress
00415F73  50                                            push    eax; hProcess
00415F74  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415F76  8b 0d 78 9f 42 00                             mov     ecx, dword_429F78
00415F7C  8b 15 7c 9f 42 00                             mov     edx, off_429F7C
00415F82  a1 74 9f 42 00                                mov     eax, dword_429F74
00415F87  55                                            push    ebp; lpNumberOfBytesWritten
00415F88  51                                            push    ecx; nSize
00415F89  8b 4e 70                                      mov     ecx, [esi+70h]
00415F8C  52                                            push    edx; lpBuffer
00415F8D  50                                            push    eax; lpBaseAddress
00415F8E  51                                            push    ecx; hProcess
00415F8F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415F91  8b 15 50 9f 42 00                             mov     edx, dword_429F50
00415F97  a1 54 9f 42 00                                mov     eax, off_429F54
00415F9C  8b 0d 4c 9f 42 00                             mov     ecx, dword_429F4C
00415FA2  55                                            push    ebp; lpNumberOfBytesWritten
00415FA3  52                                            push    edx; nSize
00415FA4  8b 56 70                                      mov     edx, [esi+70h]
00415FA7  50                                            push    eax; lpBuffer
00415FA8  51                                            push    ecx; lpBaseAddress
00415FA9  52                                            push    edx; hProcess
00415FAA  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415FAC  a1 28 9f 42 00                                mov     eax, dword_429F28
00415FB1  8b 0d 2c 9f 42 00                             mov     ecx, off_429F2C
00415FB7  8b 15 24 9f 42 00                             mov     edx, dword_429F24
00415FBD  55                                            push    ebp; lpNumberOfBytesWritten
00415FBE  50                                            push    eax; nSize
00415FBF  8b 46 70                                      mov     eax, [esi+70h]
00415FC2  51                                            push    ecx; lpBuffer
00415FC3  52                                            push    edx; lpBaseAddress
00415FC4  50                                            push    eax; hProcess
00415FC5  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415FC7  8b 0d 00 9f 42 00                             mov     ecx, dword_429F00
00415FCD  8b 15 04 9f 42 00                             mov     edx, off_429F04
00415FD3  a1 fc 9e 42 00                                mov     eax, dword_429EFC
00415FD8  55                                            push    ebp; lpNumberOfBytesWritten
00415FD9  51                                            push    ecx; nSize
00415FDA  8b 4e 70                                      mov     ecx, [esi+70h]
00415FDD  52                                            push    edx; lpBuffer
00415FDE  50                                            push    eax; lpBaseAddress
00415FDF  51                                            push    ecx; hProcess
00415FE0  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415FE2  8b 15 d8 9e 42 00                             mov     edx, dword_429ED8
00415FE8  a1 dc 9e 42 00                                mov     eax, off_429EDC
00415FED  8b 0d d4 9e 42 00                             mov     ecx, dword_429ED4
00415FF3  55                                            push    ebp; lpNumberOfBytesWritten
00415FF4  52                                            push    edx; nSize
00415FF5  8b 56 70                                      mov     edx, [esi+70h]
00415FF8  50                                            push    eax; lpBuffer
00415FF9  51                                            push    ecx; lpBaseAddress
00415FFA  52                                            push    edx; hProcess
00415FFB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00415FFD  a1 b0 9e 42 00                                mov     eax, dword_429EB0
00416002  8b 0d b4 9e 42 00                             mov     ecx, off_429EB4
00416008  8b 15 ac 9e 42 00                             mov     edx, dword_429EAC
0041600E  55                                            push    ebp; lpNumberOfBytesWritten
0041600F  50                                            push    eax; nSize
00416010  8b 46 70                                      mov     eax, [esi+70h]
00416013  51                                            push    ecx; lpBuffer
00416014  52                                            push    edx; lpBaseAddress
00416015  50                                            push    eax; hProcess
00416016  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416018  8b 0d 88 9e 42 00                             mov     ecx, dword_429E88
0041601E  8b 15 8c 9e 42 00                             mov     edx, off_429E8C
00416024  a1 84 9e 42 00                                mov     eax, dword_429E84
00416029  55                                            push    ebp; lpNumberOfBytesWritten
0041602A  51                                            push    ecx; nSize
0041602B  8b 4e 70                                      mov     ecx, [esi+70h]
0041602E  52                                            push    edx; lpBuffer
0041602F  50                                            push    eax; lpBaseAddress
00416030  51                                            push    ecx; hProcess
00416031  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416033  8b 15 b0 a1 42 00                             mov     edx, dword_42A1B0
00416039  a1 b4 a1 42 00                                mov     eax, off_42A1B4
0041603E  55                                            push    ebp; lpNumberOfBytesWritten
0041603F  52                                            push    edx; nSize
00416040  8b 0d ac a1 42 00                             mov     ecx, dword_42A1AC
00416046  8b 56 70                                      mov     edx, [esi+70h]
00416049  50                                            push    eax; lpBuffer
0041604A  51                                            push    ecx; lpBaseAddress
0041604B  52                                            push    edx; hProcess
0041604C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041604E  a1 50 a1 42 00                                mov     eax, dword_42A150
00416053  8b 0d 54 a1 42 00                             mov     ecx, off_42A154
00416059  8b 15 4c a1 42 00                             mov     edx, dword_42A14C
0041605F  55                                            push    ebp; lpNumberOfBytesWritten
00416060  50                                            push    eax; nSize
00416061  8b 46 70                                      mov     eax, [esi+70h]
00416064  51                                            push    ecx; lpBuffer
00416065  52                                            push    edx; lpBaseAddress
00416066  50                                            push    eax; hProcess
00416067  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416069  8b 0d 28 a1 42 00                             mov     ecx, dword_42A128
0041606F  8b 15 2c a1 42 00                             mov     edx, off_42A12C
00416075  a1 24 a1 42 00                                mov     eax, dword_42A124
0041607A  55                                            push    ebp; lpNumberOfBytesWritten
0041607B  51                                            push    ecx; nSize
0041607C  8b 4e 70                                      mov     ecx, [esi+70h]
0041607F  52                                            push    edx; lpBuffer
00416080  50                                            push    eax; lpBaseAddress
00416081  51                                            push    ecx; hProcess
00416082  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416084  8b 15 90 a0 42 00                             mov     edx, dword_42A090
0041608A  a1 94 a0 42 00                                mov     eax, off_42A094
0041608F  8b 0d 8c a0 42 00                             mov     ecx, dword_42A08C
00416095  55                                            push    ebp; lpNumberOfBytesWritten
00416096  52                                            push    edx; nSize
00416097  8b 56 70                                      mov     edx, [esi+70h]
0041609A  50                                            push    eax; lpBuffer
0041609B  51                                            push    ecx; lpBaseAddress
0041609C  52                                            push    edx; hProcess
0041609D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041609F  bb 90 d8 42 00                                mov     ebx, offset off_42D890
004160A4  8b 43 fc                                      mov     eax, [ebx-4]
004160A7  8b 0b                                         mov     ecx, [ebx]
004160A9  8b 53 f8                                      mov     edx, [ebx-8]
004160AC  55                                            push    ebp; lpNumberOfBytesWritten
004160AD  50                                            push    eax; nSize
004160AE  8b 46 70                                      mov     eax, [esi+70h]
004160B1  51                                            push    ecx; lpBuffer
004160B2  52                                            push    edx; lpBaseAddress
004160B3  50                                            push    eax; hProcess
004160B4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004160B6  83 c3 0c                                      add     ebx, 0Ch
004160B9  81 fb 50 d9 42 00                             cmp     ebx, offset dword_42D950
004160BF  7c e3                                         jl      short loc_4160A4
004160C1  bb f8 d4 42 00                                mov     ebx, offset off_42D4F8
004160C6  8b 4b fc                                      mov     ecx, [ebx-4]
004160C9  8b 13                                         mov     edx, [ebx]
004160CB  8b 43 f8                                      mov     eax, [ebx-8]
004160CE  55                                            push    ebp; lpNumberOfBytesWritten
004160CF  51                                            push    ecx; nSize
004160D0  8b 4e 70                                      mov     ecx, [esi+70h]
004160D3  52                                            push    edx; lpBuffer
004160D4  50                                            push    eax; lpBaseAddress
004160D5  51                                            push    ecx; hProcess
004160D6  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004160D8  83 c3 0c                                      add     ebx, 0Ch
004160DB  81 fb 70 d5 42 00                             cmp     ebx, offset dword_42D570
004160E1  7c e3                                         jl      short loc_4160C6
004160E3  8b 15 d8 d1 42 00                             mov     edx, dword_42D1D8
004160E9  a1 dc d1 42 00                                mov     eax, off_42D1DC
004160EE  8b 0d d4 d1 42 00                             mov     ecx, dword_42D1D4
004160F4  55                                            push    ebp; lpNumberOfBytesWritten
004160F5  52                                            push    edx; nSize
004160F6  8b 56 70                                      mov     edx, [esi+70h]
004160F9  50                                            push    eax; lpBuffer
004160FA  51                                            push    ecx; lpBaseAddress
004160FB  52                                            push    edx; hProcess
004160FC  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004160FE  a1 b0 d1 42 00                                mov     eax, dword_42D1B0
00416103  8b 0d b4 d1 42 00                             mov     ecx, off_42D1B4
00416109  8b 15 ac d1 42 00                             mov     edx, dword_42D1AC
0041610F  55                                            push    ebp; lpNumberOfBytesWritten
00416110  50                                            push    eax; nSize
00416111  8b 46 70                                      mov     eax, [esi+70h]
00416114  51                                            push    ecx; lpBuffer
00416115  52                                            push    edx; lpBaseAddress
00416116  50                                            push    eax; hProcess
00416117  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416119  bb f0 d0 42 00                                mov     ebx, offset off_42D0F0
0041611E  8b 4b fc                                      mov     ecx, [ebx-4]
00416121  8b 13                                         mov     edx, [ebx]
00416123  8b 43 f8                                      mov     eax, [ebx-8]
00416126  55                                            push    ebp; lpNumberOfBytesWritten
00416127  51                                            push    ecx; nSize
00416128  8b 4e 70                                      mov     ecx, [esi+70h]
0041612B  52                                            push    edx; lpBuffer
0041612C  50                                            push    eax; lpBaseAddress
0041612D  51                                            push    ecx; hProcess
0041612E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416130  83 c3 0c                                      add     ebx, 0Ch
00416133  81 fb 14 d1 42 00                             cmp     ebx, offset dword_42D114
00416139  7c e3                                         jl      short loc_41611E
0041613B  bb c8 cf 42 00                                mov     ebx, offset off_42CFC8
00416140  8b 53 fc                                      mov     edx, [ebx-4]
00416143  8b 03                                         mov     eax, [ebx]
00416145  8b 4b f8                                      mov     ecx, [ebx-8]
00416148  55                                            push    ebp; lpNumberOfBytesWritten
00416149  52                                            push    edx; nSize
0041614A  8b 56 70                                      mov     edx, [esi+70h]
0041614D  50                                            push    eax; lpBuffer
0041614E  51                                            push    ecx; lpBaseAddress
0041614F  52                                            push    edx; hProcess
00416150  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416152  83 c3 0c                                      add     ebx, 0Ch
00416155  81 fb f8 cf 42 00                             cmp     ebx, offset dword_42CFF8
0041615B  7c e3                                         jl      short loc_416140
0041615D  bb 70 cd 42 00                                mov     ebx, offset off_42CD70
00416162  8b 43 fc                                      mov     eax, [ebx-4]
00416165  8b 0b                                         mov     ecx, [ebx]
00416167  8b 53 f8                                      mov     edx, [ebx-8]
0041616A  55                                            push    ebp; lpNumberOfBytesWritten
0041616B  50                                            push    eax; nSize
0041616C  8b 46 70                                      mov     eax, [esi+70h]
0041616F  51                                            push    ecx; lpBuffer
00416170  52                                            push    edx; lpBaseAddress
00416171  50                                            push    eax; hProcess
00416172  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416174  83 c3 0c                                      add     ebx, 0Ch
00416177  81 fb 94 cd 42 00                             cmp     ebx, offset dword_42CD94
0041617D  7c e3                                         jl      short loc_416162
0041617F  8b 0d 88 cc 42 00                             mov     ecx, dword_42CC88
00416185  8b 15 8c cc 42 00                             mov     edx, off_42CC8C
0041618B  a1 84 cc 42 00                                mov     eax, dword_42CC84
00416190  55                                            push    ebp; lpNumberOfBytesWritten
00416191  51                                            push    ecx; nSize
00416192  8b 4e 70                                      mov     ecx, [esi+70h]
00416195  52                                            push    edx; lpBuffer
00416196  50                                            push    eax; lpBaseAddress
00416197  51                                            push    ecx; hProcess
00416198  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041619A  33 db                                         xor     ebx, ebx
0041619C  8b 83 94 cb 42 00                             mov     eax, dword_42CB94[ebx]
004161A2  8b 93 84 cb 42 00                             mov     edx, dword_42CB84[ebx]
004161A8  8b 8b 74 cb 42 00                             mov     ecx, dword_42CB74[ebx]
004161AE  55                                            push    ebp; lpNumberOfBytesWritten
004161AF  05 dc cb 42 00                                add     eax, offset unk_42CBDC
004161B4  52                                            push    edx; nSize
004161B5  8b 56 70                                      mov     edx, [esi+70h]
004161B8  50                                            push    eax; lpBuffer
004161B9  51                                            push    ecx; lpBaseAddress
004161BA  52                                            push    edx; hProcess
004161BB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004161BD  83 c3 04                                      add     ebx, 4
004161C0  83 fb 10                                      cmp     ebx, 10h
004161C3  7c d7                                         jl      short loc_41619C
004161C5  33 db                                         xor     ebx, ebx
004161C7  8b 8b fc ca 42 00                             mov     ecx, dword_42CAFC[ebx]
004161CD  8b 83 ec ca 42 00                             mov     eax, dword_42CAEC[ebx]
004161D3  8b 93 dc ca 42 00                             mov     edx, dword_42CADC[ebx]
004161D9  55                                            push    ebp; lpNumberOfBytesWritten
004161DA  81 c1 40 cb 42 00                             add     ecx, offset unk_42CB40
004161E0  50                                            push    eax; nSize
004161E1  8b 46 70                                      mov     eax, [esi+70h]
004161E4  51                                            push    ecx; lpBuffer
004161E5  52                                            push    edx; lpBaseAddress
004161E6  50                                            push    eax; hProcess
004161E7  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004161E9  83 c3 04                                      add     ebx, 4
004161EC  83 fb 10                                      cmp     ebx, 10h
004161EF  7c d6                                         jl      short loc_4161C7
004161F1  33 db                                         xor     ebx, ebx
004161F3  8b 93 90 ca 42 00                             mov     edx, dword_42CA90[ebx]
004161F9  8b 8b 84 ca 42 00                             mov     ecx, dword_42CA84[ebx]
004161FF  8b 83 78 ca 42 00                             mov     eax, dword_42CA78[ebx]
00416205  55                                            push    ebp; lpNumberOfBytesWritten
00416206  81 c2 bc ca 42 00                             add     edx, offset unk_42CABC
0041620C  51                                            push    ecx; nSize
0041620D  8b 4e 70                                      mov     ecx, [esi+70h]
00416210  52                                            push    edx; lpBuffer
00416211  50                                            push    eax; lpBaseAddress
00416212  51                                            push    ecx; hProcess
00416213  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416215  83 c3 04                                      add     ebx, 4
00416218  83 fb 0c                                      cmp     ebx, 0Ch
0041621B  7c d6                                         jl      short loc_4161F3
0041621D  8b 15 70 ca 42 00                             mov     edx, dword_42CA70
00416223  a1 74 ca 42 00                                mov     eax, off_42CA74
00416228  8b 0d 6c ca 42 00                             mov     ecx, dword_42CA6C
0041622E  55                                            push    ebp; lpNumberOfBytesWritten
0041622F  52                                            push    edx; nSize
00416230  8b 56 70                                      mov     edx, [esi+70h]
00416233  50                                            push    eax; lpBuffer
00416234  51                                            push    ecx; lpBaseAddress
00416235  52                                            push    edx; hProcess
00416236  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416238  a1 40 c9 42 00                                mov     eax, dword_42C940
0041623D  8b 0d 44 c9 42 00                             mov     ecx, off_42C944
00416243  8b 15 3c c9 42 00                             mov     edx, dword_42C93C
00416249  55                                            push    ebp; lpNumberOfBytesWritten
0041624A  50                                            push    eax; nSize
0041624B  8b 46 70                                      mov     eax, [esi+70h]
0041624E  51                                            push    ecx; lpBuffer
0041624F  52                                            push    edx; lpBaseAddress
00416250  50                                            push    eax; hProcess
00416251  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416253  8b 0d 10 ca 42 00                             mov     ecx, dword_42CA10
00416259  8b 15 14 ca 42 00                             mov     edx, off_42CA14
0041625F  a1 0c ca 42 00                                mov     eax, dword_42CA0C
00416264  55                                            push    ebp; lpNumberOfBytesWritten
00416265  51                                            push    ecx; nSize
00416266  8b 4e 70                                      mov     ecx, [esi+70h]
00416269  52                                            push    edx; lpBuffer
0041626A  50                                            push    eax; lpBaseAddress
0041626B  51                                            push    ecx; hProcess
0041626C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041626E  8b 15 c8 c9 42 00                             mov     edx, dword_42C9C8
00416274  a1 cc c9 42 00                                mov     eax, off_42C9CC
00416279  8b 0d c4 c9 42 00                             mov     ecx, dword_42C9C4
0041627F  55                                            push    ebp; lpNumberOfBytesWritten
00416280  52                                            push    edx; nSize
00416281  8b 56 70                                      mov     edx, [esi+70h]
00416284  50                                            push    eax; lpBuffer
00416285  51                                            push    ecx; lpBaseAddress
00416286  52                                            push    edx; hProcess
00416287  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416289  a1 10 c6 42 00                                mov     eax, dword_42C610
0041628E  8b 0d 14 c6 42 00                             mov     ecx, off_42C614
00416294  8b 15 0c c6 42 00                             mov     edx, dword_42C60C
0041629A  55                                            push    ebp; lpNumberOfBytesWritten
0041629B  50                                            push    eax; nSize
0041629C  8b 46 70                                      mov     eax, [esi+70h]
0041629F  51                                            push    ecx; lpBuffer
004162A0  52                                            push    edx; lpBaseAddress
004162A1  50                                            push    eax; hProcess
004162A2  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004162A4  8b 0d b8 c5 42 00                             mov     ecx, dword_42C5B8
004162AA  8b 15 bc c5 42 00                             mov     edx, off_42C5BC
004162B0  a1 b4 c5 42 00                                mov     eax, off_42C5B4
004162B5  55                                            push    ebp; lpNumberOfBytesWritten
004162B6  51                                            push    ecx; nSize
004162B7  8b 4e 70                                      mov     ecx, [esi+70h]
004162BA  52                                            push    edx; lpBuffer
004162BB  50                                            push    eax; lpBaseAddress
004162BC  51                                            push    ecx; hProcess
004162BD  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004162BF  8b 15 60 c5 42 00                             mov     edx, dword_42C560
004162C5  a1 64 c5 42 00                                mov     eax, off_42C564
004162CA  8b 0d 5c c5 42 00                             mov     ecx, dword_42C55C
004162D0  55                                            push    ebp; lpNumberOfBytesWritten
004162D1  52                                            push    edx; nSize
004162D2  8b 56 70                                      mov     edx, [esi+70h]
004162D5  50                                            push    eax; lpBuffer
004162D6  51                                            push    ecx; lpBaseAddress
004162D7  52                                            push    edx; hProcess
004162D8  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004162DA  33 db                                         xor     ebx, ebx
004162DC  8b 8b 64 c1 42 00                             mov     ecx, dword_42C164[ebx]
004162E2  8b 83 4c c1 42 00                             mov     eax, dword_42C14C[ebx]
004162E8  8b 93 34 c1 42 00                             mov     edx, dword_42C134[ebx]
004162EE  55                                            push    ebp; lpNumberOfBytesWritten
004162EF  81 c1 e4 c1 42 00                             add     ecx, offset unk_42C1E4
004162F5  50                                            push    eax; nSize
004162F6  8b 46 70                                      mov     eax, [esi+70h]
004162F9  51                                            push    ecx; lpBuffer
004162FA  52                                            push    edx; lpBaseAddress
004162FB  50                                            push    eax; hProcess
004162FC  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004162FE  83 c3 04                                      add     ebx, 4
00416301  83 fb 18                                      cmp     ebx, 18h
00416304  7c d6                                         jl      short loc_4162DC
00416306  8b 0d 68 c0 42 00                             mov     ecx, dword_42C068
0041630C  8b 15 6c c0 42 00                             mov     edx, off_42C06C
00416312  a1 64 c0 42 00                                mov     eax, dword_42C064
00416317  55                                            push    ebp; lpNumberOfBytesWritten
00416318  51                                            push    ecx; nSize
00416319  8b 4e 70                                      mov     ecx, [esi+70h]
0041631C  52                                            push    edx; lpBuffer
0041631D  50                                            push    eax; lpBaseAddress
0041631E  51                                            push    ecx; hProcess
0041631F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416321  8b 15 a0 bf 42 00                             mov     edx, dword_42BFA0
00416327  a1 a4 bf 42 00                                mov     eax, off_42BFA4
0041632C  8b 0d 9c bf 42 00                             mov     ecx, dword_42BF9C
00416332  55                                            push    ebp; lpNumberOfBytesWritten
00416333  52                                            push    edx; nSize
00416334  8b 56 70                                      mov     edx, [esi+70h]
00416337  50                                            push    eax; lpBuffer
00416338  51                                            push    ecx; lpBaseAddress
00416339  52                                            push    edx; hProcess
0041633A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041633C  a1 d8 bd 42 00                                mov     eax, dword_42BDD8
00416341  8b 0d dc bd 42 00                             mov     ecx, off_42BDDC
00416347  8b 15 d4 bd 42 00                             mov     edx, dword_42BDD4
0041634D  55                                            push    ebp; lpNumberOfBytesWritten
0041634E  50                                            push    eax; nSize
0041634F  8b 46 70                                      mov     eax, [esi+70h]
00416352  51                                            push    ecx; lpBuffer
00416353  52                                            push    edx; lpBaseAddress
00416354  50                                            push    eax; hProcess
00416355  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416357  33 db                                         xor     ebx, ebx
00416359  8b 93 00 ba 42 00                             mov     edx, dword_42BA00[ebx]
0041635F  8b 8b e8 b9 42 00                             mov     ecx, dword_42B9E8[ebx]
00416365  8b 83 d0 b9 42 00                             mov     eax, dword_42B9D0[ebx]
0041636B  55                                            push    ebp; lpNumberOfBytesWritten
0041636C  81 c2 30 ba 42 00                             add     edx, offset unk_42BA30
00416372  51                                            push    ecx; nSize
00416373  8b 4e 70                                      mov     ecx, [esi+70h]
00416376  52                                            push    edx; lpBuffer
00416377  50                                            push    eax; lpBaseAddress
00416378  51                                            push    ecx; hProcess
00416379  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041637B  83 c3 04                                      add     ebx, 4
0041637E  83 fb 18                                      cmp     ebx, 18h
00416381  7c d6                                         jl      short loc_416359
00416383  33 db                                         xor     ebx, ebx
00416385  8b 83 28 b9 42 00                             mov     eax, dword_42B928[ebx]
0041638B  8b 93 18 b9 42 00                             mov     edx, dword_42B918[ebx]
00416391  8b 8b 08 b9 42 00                             mov     ecx, dword_42B908[ebx]
00416397  55                                            push    ebp; lpNumberOfBytesWritten
00416398  05 54 b9 42 00                                add     eax, offset unk_42B954
0041639D  52                                            push    edx; nSize
0041639E  8b 56 70                                      mov     edx, [esi+70h]
004163A1  50                                            push    eax; lpBuffer
004163A2  51                                            push    ecx; lpBaseAddress
004163A3  52                                            push    edx; hProcess
004163A4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004163A6  83 c3 04                                      add     ebx, 4
004163A9  83 fb 10                                      cmp     ebx, 10h
004163AC  7c d7                                         jl      short loc_416385
004163AE  33 db                                         xor     ebx, ebx
004163B0  8b 8b b0 b8 42 00                             mov     ecx, dword_42B8B0[ebx]
004163B6  8b 83 a0 b8 42 00                             mov     eax, dword_42B8A0[ebx]
004163BC  8b 93 90 b8 42 00                             mov     edx, dword_42B890[ebx]
004163C2  55                                            push    ebp; lpNumberOfBytesWritten
004163C3  81 c1 e4 b8 42 00                             add     ecx, offset unk_42B8E4
004163C9  50                                            push    eax; nSize
004163CA  8b 46 70                                      mov     eax, [esi+70h]
004163CD  51                                            push    ecx; lpBuffer
004163CE  52                                            push    edx; lpBaseAddress
004163CF  50                                            push    eax; hProcess
004163D0  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004163D2  83 c3 04                                      add     ebx, 4
004163D5  83 fb 10                                      cmp     ebx, 10h
004163D8  7c d6                                         jl      short loc_4163B0
004163DA  8b 0d 88 b8 42 00                             mov     ecx, dword_42B888
004163E0  8b 15 8c b8 42 00                             mov     edx, off_42B88C
004163E6  a1 84 b8 42 00                                mov     eax, dword_42B884
004163EB  55                                            push    ebp; lpNumberOfBytesWritten
004163EC  51                                            push    ecx; nSize
004163ED  8b 4e 70                                      mov     ecx, [esi+70h]
004163F0  52                                            push    edx; lpBuffer
004163F1  50                                            push    eax; lpBaseAddress
004163F2  51                                            push    ecx; hProcess
004163F3  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004163F5  8b 15 20 b8 42 00                             mov     edx, dword_42B820
004163FB  a1 24 b8 42 00                                mov     eax, off_42B824
00416400  8b 0d 1c b8 42 00                             mov     ecx, dword_42B81C
00416406  55                                            push    ebp; lpNumberOfBytesWritten
00416407  52                                            push    edx; nSize
00416408  8b 56 70                                      mov     edx, [esi+70h]
0041640B  50                                            push    eax; lpBuffer
0041640C  51                                            push    ecx; lpBaseAddress
0041640D  52                                            push    edx; hProcess
0041640E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416410  a1 48 b8 42 00                                mov     eax, dword_42B848
00416415  8b 0d 4c b8 42 00                             mov     ecx, off_42B84C
0041641B  8b 15 44 b8 42 00                             mov     edx, dword_42B844
00416421  55                                            push    ebp; lpNumberOfBytesWritten
00416422  50                                            push    eax; nSize
00416423  8b 46 70                                      mov     eax, [esi+70h]
00416426  51                                            push    ecx; lpBuffer
00416427  52                                            push    edx; lpBaseAddress
00416428  50                                            push    eax; hProcess
00416429  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041642B  8b 0d 88 b7 42 00                             mov     ecx, dword_42B788
00416431  8b 15 8c b7 42 00                             mov     edx, off_42B78C
00416437  a1 84 b7 42 00                                mov     eax, dword_42B784
0041643C  55                                            push    ebp; lpNumberOfBytesWritten
0041643D  51                                            push    ecx; nSize
0041643E  8b 4e 70                                      mov     ecx, [esi+70h]
00416441  52                                            push    edx; lpBuffer
00416442  50                                            push    eax; lpBaseAddress
00416443  51                                            push    ecx; hProcess
00416444  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416446  8b 15 10 b7 42 00                             mov     edx, dword_42B710
0041644C  a1 14 b7 42 00                                mov     eax, off_42B714
00416451  8b 0d 0c b7 42 00                             mov     ecx, dword_42B70C
00416457  55                                            push    ebp; lpNumberOfBytesWritten
00416458  52                                            push    edx; nSize
00416459  8b 56 70                                      mov     edx, [esi+70h]
0041645C  50                                            push    eax; lpBuffer
0041645D  51                                            push    ecx; lpBaseAddress
0041645E  52                                            push    edx; hProcess
0041645F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416461  bb c0 b6 42 00                                mov     ebx, offset off_42B6C0
00416466  8b 43 fc                                      mov     eax, [ebx-4]
00416469  8b 0b                                         mov     ecx, [ebx]
0041646B  8b 53 f8                                      mov     edx, [ebx-8]
0041646E  55                                            push    ebp; lpNumberOfBytesWritten
0041646F  50                                            push    eax; nSize
00416470  8b 46 70                                      mov     eax, [esi+70h]
00416473  51                                            push    ecx; lpBuffer
00416474  52                                            push    edx; lpBaseAddress
00416475  50                                            push    eax; hProcess
00416476  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416478  83 c3 0c                                      add     ebx, 0Ch
0041647B  81 fb e4 b6 42 00                             cmp     ebx, offset dword_42B6E4
00416481  7c e3                                         jl      short loc_416466
00416483  8b 0d 78 b5 42 00                             mov     ecx, dword_42B578
00416489  8b 15 7c b5 42 00                             mov     edx, off_42B57C
0041648F  a1 74 b5 42 00                                mov     eax, dword_42B574
00416494  55                                            push    ebp; lpNumberOfBytesWritten
00416495  51                                            push    ecx; nSize
00416496  8b 4e 70                                      mov     ecx, [esi+70h]
00416499  52                                            push    edx; lpBuffer
0041649A  50                                            push    eax; lpBaseAddress
0041649B  51                                            push    ecx; hProcess
0041649C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041649E  8b 15 50 b5 42 00                             mov     edx, dword_42B550
004164A4  a1 54 b5 42 00                                mov     eax, off_42B554
004164A9  8b 0d 4c b5 42 00                             mov     ecx, dword_42B54C
004164AF  55                                            push    ebp; lpNumberOfBytesWritten
004164B0  52                                            push    edx; nSize
004164B1  8b 56 70                                      mov     edx, [esi+70h]
004164B4  50                                            push    eax; lpBuffer
004164B5  51                                            push    ecx; lpBaseAddress
004164B6  52                                            push    edx; hProcess
004164B7  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004164B9  a1 38 b5 42 00                                mov     eax, dword_42B538
004164BE  8b 0d 3c b5 42 00                             mov     ecx, off_42B53C
004164C4  8b 15 34 b5 42 00                             mov     edx, dword_42B534
004164CA  55                                            push    ebp; lpNumberOfBytesWritten
004164CB  50                                            push    eax; nSize
004164CC  8b 46 70                                      mov     eax, [esi+70h]
004164CF  51                                            push    ecx; lpBuffer
004164D0  52                                            push    edx; lpBaseAddress
004164D1  50                                            push    eax; hProcess
004164D2  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004164D4  8b 0d 10 b5 42 00                             mov     ecx, dword_42B510
004164DA  8b 15 14 b5 42 00                             mov     edx, off_42B514
004164E0  a1 0c b5 42 00                                mov     eax, dword_42B50C
004164E5  55                                            push    ebp; lpNumberOfBytesWritten
004164E6  51                                            push    ecx; nSize
004164E7  8b 4e 70                                      mov     ecx, [esi+70h]
004164EA  52                                            push    edx; lpBuffer
004164EB  50                                            push    eax; lpBaseAddress
004164EC  51                                            push    ecx; hProcess
004164ED  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004164EF  8b 15 b0 98 42 00                             mov     edx, dword_4298B0
004164F5  a1 b4 98 42 00                                mov     eax, off_4298B4
004164FA  8b 0d ac 98 42 00                             mov     ecx, dword_4298AC
00416500  55                                            push    ebp; lpNumberOfBytesWritten
00416501  52                                            push    edx; nSize
00416502  8b 56 70                                      mov     edx, [esi+70h]
00416505  50                                            push    eax; lpBuffer
00416506  51                                            push    ecx; lpBaseAddress
00416507  52                                            push    edx; hProcess
00416508  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041650A  a1 90 97 42 00                                mov     eax, dword_429790
0041650F  8b 0d 94 97 42 00                             mov     ecx, off_429794
00416515  8b 15 8c 97 42 00                             mov     edx, dword_42978C
0041651B  55                                            push    ebp; lpNumberOfBytesWritten
0041651C  50                                            push    eax; nSize
0041651D  8b 46 70                                      mov     eax, [esi+70h]
00416520  51                                            push    ecx; lpBuffer
00416521  52                                            push    edx; lpBaseAddress
00416522  50                                            push    eax; hProcess
00416523  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416525  8b 0d 20 97 42 00                             mov     ecx, dword_429720
0041652B  8b 15 24 97 42 00                             mov     edx, off_429724
00416531  a1 1c 97 42 00                                mov     eax, dword_42971C
00416536  55                                            push    ebp; lpNumberOfBytesWritten
00416537  51                                            push    ecx; nSize
00416538  8b 4e 70                                      mov     ecx, [esi+70h]
0041653B  52                                            push    edx; lpBuffer
0041653C  50                                            push    eax; lpBaseAddress
0041653D  51                                            push    ecx; hProcess
0041653E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416540  8b 15 88 96 42 00                             mov     edx, dword_429688
00416546  a1 8c 96 42 00                                mov     eax, off_42968C
0041654B  8b 0d 84 96 42 00                             mov     ecx, dword_429684
00416551  55                                            push    ebp; lpNumberOfBytesWritten
00416552  52                                            push    edx; nSize
00416553  8b 56 70                                      mov     edx, [esi+70h]
00416556  50                                            push    eax; lpBuffer
00416557  51                                            push    ecx; lpBaseAddress
00416558  52                                            push    edx; hProcess
00416559  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041655B  55                                            push    ebp; lpNumberOfBytesWritten
0041655C  a1 08 96 42 00                                mov     eax, dword_429608
00416561  8b 0d 0c 96 42 00                             mov     ecx, off_42960C
00416567  8b 15 04 96 42 00                             mov     edx, dword_429604
0041656D  50                                            push    eax; nSize
0041656E  8b 46 70                                      mov     eax, [esi+70h]
00416571  51                                            push    ecx; lpBuffer
00416572  52                                            push    edx; lpBaseAddress
00416573  50                                            push    eax; hProcess
00416574  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416576  8b 0d e8 94 42 00                             mov     ecx, dword_4294E8
0041657C  8b 15 ec 94 42 00                             mov     edx, off_4294EC
00416582  a1 e4 94 42 00                                mov     eax, dword_4294E4
00416587  55                                            push    ebp; lpNumberOfBytesWritten
00416588  51                                            push    ecx; nSize
00416589  8b 4e 70                                      mov     ecx, [esi+70h]
0041658C  52                                            push    edx; lpBuffer
0041658D  50                                            push    eax; lpBaseAddress
0041658E  51                                            push    ecx; hProcess
0041658F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416591  8b 15 c0 94 42 00                             mov     edx, dword_4294C0
00416597  a1 c4 94 42 00                                mov     eax, off_4294C4
0041659C  8b 0d bc 94 42 00                             mov     ecx, dword_4294BC
004165A2  55                                            push    ebp; lpNumberOfBytesWritten
004165A3  52                                            push    edx; nSize
004165A4  8b 56 70                                      mov     edx, [esi+70h]
004165A7  50                                            push    eax; lpBuffer
004165A8  51                                            push    ecx; lpBaseAddress
004165A9  52                                            push    edx; hProcess
004165AA  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004165AC  a1 98 94 42 00                                mov     eax, dword_429498
004165B1  8b 0d 9c 94 42 00                             mov     ecx, off_42949C
004165B7  8b 15 94 94 42 00                             mov     edx, dword_429494
004165BD  55                                            push    ebp; lpNumberOfBytesWritten
004165BE  50                                            push    eax; nSize
004165BF  8b 46 70                                      mov     eax, [esi+70h]
004165C2  51                                            push    ecx; lpBuffer
004165C3  52                                            push    edx; lpBaseAddress
004165C4  50                                            push    eax; hProcess
004165C5  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004165C7  8b 0d 08 94 42 00                             mov     ecx, dword_429408
004165CD  8b 15 0c 94 42 00                             mov     edx, off_42940C
004165D3  a1 04 94 42 00                                mov     eax, dword_429404
004165D8  55                                            push    ebp; lpNumberOfBytesWritten
004165D9  51                                            push    ecx; nSize
004165DA  8b 4e 70                                      mov     ecx, [esi+70h]
004165DD  52                                            push    edx; lpBuffer
004165DE  50                                            push    eax; lpBaseAddress
004165DF  51                                            push    ecx; hProcess
004165E0  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004165E2  8b 15 c8 93 42 00                             mov     edx, dword_4293C8
004165E8  a1 cc 93 42 00                                mov     eax, off_4293CC
004165ED  8b 0d c4 93 42 00                             mov     ecx, dword_4293C4
004165F3  55                                            push    ebp; lpNumberOfBytesWritten
004165F4  52                                            push    edx; nSize
004165F5  8b 56 70                                      mov     edx, [esi+70h]
004165F8  50                                            push    eax; lpBuffer
004165F9  51                                            push    ecx; lpBaseAddress
004165FA  52                                            push    edx; hProcess
004165FB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004165FD  a1 70 93 42 00                                mov     eax, dword_429370
00416602  8b 0d 74 93 42 00                             mov     ecx, off_429374
00416608  8b 15 6c 93 42 00                             mov     edx, dword_42936C
0041660E  55                                            push    ebp; lpNumberOfBytesWritten
0041660F  50                                            push    eax; nSize
00416610  8b 46 70                                      mov     eax, [esi+70h]
00416613  51                                            push    ecx; lpBuffer
00416614  52                                            push    edx; lpBaseAddress
00416615  50                                            push    eax; hProcess
00416616  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416618  8b 0d e0 92 42 00                             mov     ecx, dword_4292E0
0041661E  8b 15 e4 92 42 00                             mov     edx, off_4292E4
00416624  a1 dc 92 42 00                                mov     eax, dword_4292DC
00416629  55                                            push    ebp; lpNumberOfBytesWritten
0041662A  51                                            push    ecx; nSize
0041662B  8b 4e 70                                      mov     ecx, [esi+70h]
0041662E  52                                            push    edx; lpBuffer
0041662F  50                                            push    eax; lpBaseAddress
00416630  51                                            push    ecx; hProcess
00416631  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416633  8b 15 18 92 42 00                             mov     edx, dword_429218
00416639  55                                            push    ebp; lpNumberOfBytesWritten
0041663A  a1 1c 92 42 00                                mov     eax, off_42921C
0041663F  8b 0d 14 92 42 00                             mov     ecx, dword_429214
00416645  52                                            push    edx; nSize
00416646  8b 56 70                                      mov     edx, [esi+70h]
00416649  50                                            push    eax; lpBuffer
0041664A  51                                            push    ecx; lpBaseAddress
0041664B  52                                            push    edx; hProcess
0041664C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041664E  a1 c0 91 42 00                                mov     eax, dword_4291C0
00416653  8b 0d c4 91 42 00                             mov     ecx, off_4291C4
00416659  8b 15 bc 91 42 00                             mov     edx, dword_4291BC
0041665F  55                                            push    ebp; lpNumberOfBytesWritten
00416660  50                                            push    eax; nSize
00416661  8b 46 70                                      mov     eax, [esi+70h]
00416664  51                                            push    ecx; lpBuffer
00416665  52                                            push    edx; lpBaseAddress
00416666  50                                            push    eax; hProcess
00416667  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416669  8b 0d 88 91 42 00                             mov     ecx, dword_429188
0041666F  8b 15 8c 91 42 00                             mov     edx, off_42918C
00416675  a1 84 91 42 00                                mov     eax, dword_429184
0041667A  55                                            push    ebp; lpNumberOfBytesWritten
0041667B  51                                            push    ecx; nSize
0041667C  8b 4e 70                                      mov     ecx, [esi+70h]
0041667F  52                                            push    edx; lpBuffer
00416680  50                                            push    eax; lpBaseAddress
00416681  51                                            push    ecx; hProcess
00416682  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416684  8b 15 e0 90 42 00                             mov     edx, dword_4290E0
0041668A  a1 e4 90 42 00                                mov     eax, off_4290E4
0041668F  8b 0d dc 90 42 00                             mov     ecx, dword_4290DC
00416695  55                                            push    ebp; lpNumberOfBytesWritten
00416696  52                                            push    edx; nSize
00416697  8b 56 70                                      mov     edx, [esi+70h]
0041669A  50                                            push    eax; lpBuffer
0041669B  51                                            push    ecx; lpBaseAddress
0041669C  52                                            push    edx; hProcess
0041669D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041669F  a1 a0 90 42 00                                mov     eax, dword_4290A0
004166A4  8b 0d a4 90 42 00                             mov     ecx, off_4290A4
004166AA  8b 15 9c 90 42 00                             mov     edx, dword_42909C
004166B0  55                                            push    ebp; lpNumberOfBytesWritten
004166B1  50                                            push    eax; nSize
004166B2  8b 46 70                                      mov     eax, [esi+70h]
004166B5  51                                            push    ecx; lpBuffer
004166B6  52                                            push    edx; lpBaseAddress
004166B7  50                                            push    eax; hProcess
004166B8  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004166BA  8b 0d 48 90 42 00                             mov     ecx, dword_429048
004166C0  8b 15 4c 90 42 00                             mov     edx, off_42904C
004166C6  a1 44 90 42 00                                mov     eax, dword_429044
004166CB  55                                            push    ebp; lpNumberOfBytesWritten
004166CC  51                                            push    ecx; nSize
004166CD  8b 4e 70                                      mov     ecx, [esi+70h]
004166D0  52                                            push    edx; lpBuffer
004166D1  50                                            push    eax; lpBaseAddress
004166D2  51                                            push    ecx; hProcess
004166D3  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004166D5  8b 15 d0 8f 42 00                             mov     edx, dword_428FD0
004166DB  a1 d4 8f 42 00                                mov     eax, off_428FD4
004166E0  8b 0d cc 8f 42 00                             mov     ecx, dword_428FCC
004166E6  55                                            push    ebp; lpNumberOfBytesWritten
004166E7  52                                            push    edx; nSize
004166E8  8b 56 70                                      mov     edx, [esi+70h]
004166EB  50                                            push    eax; lpBuffer
004166EC  51                                            push    ecx; lpBaseAddress
004166ED  52                                            push    edx; hProcess
004166EE  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004166F0  a1 40 8f 42 00                                mov     eax, dword_428F40
004166F5  8b 0d 44 8f 42 00                             mov     ecx, off_428F44
004166FB  8b 15 3c 8f 42 00                             mov     edx, off_428F3C
00416701  55                                            push    ebp; lpNumberOfBytesWritten
00416702  50                                            push    eax; nSize
00416703  8b 46 70                                      mov     eax, [esi+70h]
00416706  51                                            push    ecx; lpBuffer
00416707  52                                            push    edx; lpBaseAddress
00416708  50                                            push    eax; hProcess
00416709  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041670B  8b 0d d0 8b 42 00                             mov     ecx, dword_428BD0
00416711  55                                            push    ebp; lpNumberOfBytesWritten
00416712  51                                            push    ecx; nSize
00416713  8b 15 d4 8b 42 00                             mov     edx, off_428BD4
00416719  a1 cc 8b 42 00                                mov     eax, dword_428BCC
0041671E  8b 4e 70                                      mov     ecx, [esi+70h]
00416721  52                                            push    edx; lpBuffer
00416722  50                                            push    eax; lpBaseAddress
00416723  51                                            push    ecx; hProcess
00416724  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416726  8b 15 e0 8e 42 00                             mov     edx, dword_428EE0
0041672C  a1 e4 8e 42 00                                mov     eax, off_428EE4
00416731  8b 0d dc 8e 42 00                             mov     ecx, dword_428EDC
00416737  55                                            push    ebp; lpNumberOfBytesWritten
00416738  52                                            push    edx; nSize
00416739  8b 56 70                                      mov     edx, [esi+70h]
0041673C  50                                            push    eax; lpBuffer
0041673D  51                                            push    ecx; lpBaseAddress
0041673E  52                                            push    edx; hProcess
0041673F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416741  a1 88 8e 42 00                                mov     eax, dword_428E88
00416746  8b 0d 8c 8e 42 00                             mov     ecx, off_428E8C
0041674C  8b 15 84 8e 42 00                             mov     edx, dword_428E84
00416752  55                                            push    ebp; lpNumberOfBytesWritten
00416753  50                                            push    eax; nSize
00416754  8b 46 70                                      mov     eax, [esi+70h]
00416757  51                                            push    ecx; lpBuffer
00416758  52                                            push    edx; lpBaseAddress
00416759  50                                            push    eax; hProcess
0041675A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041675C  8b 0d 30 3b 42 00                             mov     ecx, dword_423B30
00416762  8b 15 34 3b 42 00                             mov     edx, off_423B34
00416768  a1 2c 3b 42 00                                mov     eax, dword_423B2C
0041676D  55                                            push    ebp; lpNumberOfBytesWritten
0041676E  51                                            push    ecx; nSize
0041676F  8b 4e 70                                      mov     ecx, [esi+70h]
00416772  52                                            push    edx; lpBuffer
00416773  50                                            push    eax; lpBaseAddress
00416774  51                                            push    ecx; hProcess
00416775  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416777  8b 15 88 8d 42 00                             mov     edx, dword_428D88
0041677D  a1 8c 8d 42 00                                mov     eax, off_428D8C
00416782  8b 0d 84 8d 42 00                             mov     ecx, dword_428D84
00416788  55                                            push    ebp; lpNumberOfBytesWritten
00416789  52                                            push    edx; nSize
0041678A  8b 56 70                                      mov     edx, [esi+70h]
0041678D  50                                            push    eax; lpBuffer
0041678E  51                                            push    ecx; lpBaseAddress
0041678F  52                                            push    edx; hProcess
00416790  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416792  a1 68 8d 42 00                                mov     eax, dword_428D68
00416797  8b 0d 6c 8d 42 00                             mov     ecx, off_428D6C
0041679D  8b 15 64 8d 42 00                             mov     edx, dword_428D64
004167A3  55                                            push    ebp; lpNumberOfBytesWritten
004167A4  50                                            push    eax; nSize
004167A5  8b 46 70                                      mov     eax, [esi+70h]
004167A8  51                                            push    ecx; lpBuffer
004167A9  52                                            push    edx; lpBaseAddress
004167AA  50                                            push    eax; hProcess
004167AB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004167AD  8b 0d 48 8d 42 00                             mov     ecx, dword_428D48
004167B3  8b 15 4c 8d 42 00                             mov     edx, off_428D4C
004167B9  a1 44 8d 42 00                                mov     eax, dword_428D44
004167BE  55                                            push    ebp; lpNumberOfBytesWritten
004167BF  51                                            push    ecx; nSize
004167C0  8b 4e 70                                      mov     ecx, [esi+70h]
004167C3  52                                            push    edx; lpBuffer
004167C4  50                                            push    eax; lpBaseAddress
004167C5  51                                            push    ecx; hProcess
004167C6  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004167C8  8b 15 b8 8c 42 00                             mov     edx, dword_428CB8
004167CE  a1 bc 8c 42 00                                mov     eax, off_428CBC
004167D3  8b 0d b4 8c 42 00                             mov     ecx, dword_428CB4
004167D9  55                                            push    ebp; lpNumberOfBytesWritten
004167DA  52                                            push    edx; nSize
004167DB  8b 56 70                                      mov     edx, [esi+70h]
004167DE  50                                            push    eax; lpBuffer
004167DF  51                                            push    ecx; lpBaseAddress
004167E0  52                                            push    edx; hProcess
004167E1  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004167E3  a1 80 8b 42 00                                mov     eax, dword_428B80
004167E8  8b 0d 84 8b 42 00                             mov     ecx, off_428B84
004167EE  55                                            push    ebp; lpNumberOfBytesWritten
004167EF  50                                            push    eax; nSize
004167F0  8b 15 7c 8b 42 00                             mov     edx, dword_428B7C
004167F6  8b 46 70                                      mov     eax, [esi+70h]
004167F9  51                                            push    ecx; lpBuffer
004167FA  52                                            push    edx; lpBaseAddress
004167FB  50                                            push    eax; hProcess
004167FC  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004167FE  8b 0d 20 8b 42 00                             mov     ecx, dword_428B20
00416804  8b 15 24 8b 42 00                             mov     edx, off_428B24
0041680A  a1 1c 8b 42 00                                mov     eax, dword_428B1C
0041680F  55                                            push    ebp; lpNumberOfBytesWritten
00416810  51                                            push    ecx; nSize
00416811  8b 4e 70                                      mov     ecx, [esi+70h]
00416814  52                                            push    edx; lpBuffer
00416815  50                                            push    eax; lpBaseAddress
00416816  51                                            push    ecx; hProcess
00416817  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416819  8b 15 e8 8a 42 00                             mov     edx, dword_428AE8
0041681F  a1 ec 8a 42 00                                mov     eax, off_428AEC
00416824  8b 0d e4 8a 42 00                             mov     ecx, dword_428AE4
0041682A  55                                            push    ebp; lpNumberOfBytesWritten
0041682B  52                                            push    edx; nSize
0041682C  8b 56 70                                      mov     edx, [esi+70h]
0041682F  50                                            push    eax; lpBuffer
00416830  51                                            push    ecx; lpBaseAddress
00416831  52                                            push    edx; hProcess
00416832  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416834  a1 28 8a 42 00                                mov     eax, dword_428A28
00416839  8b 0d 2c 8a 42 00                             mov     ecx, off_428A2C
0041683F  8b 15 24 8a 42 00                             mov     edx, dword_428A24
00416845  55                                            push    ebp; lpNumberOfBytesWritten
00416846  50                                            push    eax; nSize
00416847  8b 46 70                                      mov     eax, [esi+70h]
0041684A  51                                            push    ecx; lpBuffer
0041684B  52                                            push    edx; lpBaseAddress
0041684C  50                                            push    eax; hProcess
0041684D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041684F  8b 0d d8 89 42 00                             mov     ecx, dword_4289D8
00416855  8b 15 dc 89 42 00                             mov     edx, off_4289DC
0041685B  a1 d4 89 42 00                                mov     eax, dword_4289D4
00416860  55                                            push    ebp; lpNumberOfBytesWritten
00416861  51                                            push    ecx; nSize
00416862  8b 4e 70                                      mov     ecx, [esi+70h]
00416865  52                                            push    edx; lpBuffer
00416866  50                                            push    eax; lpBaseAddress
00416867  51                                            push    ecx; hProcess
00416868  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041686A  8b 15 c8 88 42 00                             mov     edx, dword_4288C8
00416870  a1 cc 88 42 00                                mov     eax, off_4288CC
00416875  8b 0d c4 88 42 00                             mov     ecx, dword_4288C4
0041687B  55                                            push    ebp; lpNumberOfBytesWritten
0041687C  52                                            push    edx; nSize
0041687D  8b 56 70                                      mov     edx, [esi+70h]
00416880  50                                            push    eax; lpBuffer
00416881  51                                            push    ecx; lpBaseAddress
00416882  52                                            push    edx; hProcess
00416883  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416885  a1 f0 88 42 00                                mov     eax, dword_4288F0
0041688A  8b 0d f4 88 42 00                             mov     ecx, off_4288F4
00416890  8b 15 ec 88 42 00                             mov     edx, dword_4288EC
00416896  55                                            push    ebp; lpNumberOfBytesWritten
00416897  50                                            push    eax; nSize
00416898  8b 46 70                                      mov     eax, [esi+70h]
0041689B  51                                            push    ecx; lpBuffer
0041689C  52                                            push    edx; lpBaseAddress
0041689D  50                                            push    eax; hProcess
0041689E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004168A0  8b 0d a0 88 42 00                             mov     ecx, dword_4288A0
004168A6  8b 15 a4 88 42 00                             mov     edx, off_4288A4
004168AC  a1 9c 88 42 00                                mov     eax, dword_42889C
004168B1  55                                            push    ebp; lpNumberOfBytesWritten
004168B2  51                                            push    ecx; nSize
004168B3  8b 4e 70                                      mov     ecx, [esi+70h]
004168B6  52                                            push    edx; lpBuffer
004168B7  50                                            push    eax; lpBaseAddress
004168B8  51                                            push    ecx; hProcess
004168B9  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004168BB  8b 15 80 88 42 00                             mov     edx, dword_428880
004168C1  a1 84 88 42 00                                mov     eax, off_428884
004168C6  55                                            push    ebp; lpNumberOfBytesWritten
004168C7  52                                            push    edx; nSize
004168C8  50                                            push    eax; lpBuffer
004168C9  8b 0d 7c 88 42 00                             mov     ecx, dword_42887C
004168CF  8b 56 70                                      mov     edx, [esi+70h]
004168D2  51                                            push    ecx; lpBaseAddress
004168D3  52                                            push    edx; hProcess
004168D4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004168D6  a1 60 88 42 00                                mov     eax, dword_428860
004168DB  8b 0d 64 88 42 00                             mov     ecx, off_428864
004168E1  8b 15 5c 88 42 00                             mov     edx, dword_42885C
004168E7  55                                            push    ebp; lpNumberOfBytesWritten
004168E8  50                                            push    eax; nSize
004168E9  8b 46 70                                      mov     eax, [esi+70h]
004168EC  51                                            push    ecx; lpBuffer
004168ED  52                                            push    edx; lpBaseAddress
004168EE  50                                            push    eax; hProcess
004168EF  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004168F1  8b 0d 40 88 42 00                             mov     ecx, dword_428840
004168F7  8b 15 44 88 42 00                             mov     edx, off_428844
004168FD  a1 3c 88 42 00                                mov     eax, dword_42883C
00416902  55                                            push    ebp; lpNumberOfBytesWritten
00416903  51                                            push    ecx; nSize
00416904  8b 4e 70                                      mov     ecx, [esi+70h]
00416907  52                                            push    edx; lpBuffer
00416908  50                                            push    eax; lpBaseAddress
00416909  51                                            push    ecx; hProcess
0041690A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041690C  8b 15 c0 87 42 00                             mov     edx, dword_4287C0
00416912  a1 c4 87 42 00                                mov     eax, off_4287C4
00416917  8b 0d bc 87 42 00                             mov     ecx, dword_4287BC
0041691D  55                                            push    ebp; lpNumberOfBytesWritten
0041691E  52                                            push    edx; nSize
0041691F  8b 56 70                                      mov     edx, [esi+70h]
00416922  50                                            push    eax; lpBuffer
00416923  51                                            push    ecx; lpBaseAddress
00416924  52                                            push    edx; hProcess
00416925  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416927  a1 20 87 42 00                                mov     eax, dword_428720
0041692C  8b 0d 24 87 42 00                             mov     ecx, off_428724
00416932  8b 15 1c 87 42 00                             mov     edx, dword_42871C
00416938  55                                            push    ebp; lpNumberOfBytesWritten
00416939  50                                            push    eax; nSize
0041693A  8b 46 70                                      mov     eax, [esi+70h]
0041693D  51                                            push    ecx; lpBuffer
0041693E  52                                            push    edx; lpBaseAddress
0041693F  50                                            push    eax; hProcess
00416940  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416942  8b 0d 88 86 42 00                             mov     ecx, dword_428688
00416948  8b 15 8c 86 42 00                             mov     edx, off_42868C
0041694E  a1 84 86 42 00                                mov     eax, dword_428684
00416953  55                                            push    ebp; lpNumberOfBytesWritten
00416954  51                                            push    ecx; nSize
00416955  8b 4e 70                                      mov     ecx, [esi+70h]
00416958  52                                            push    edx; lpBuffer
00416959  50                                            push    eax; lpBaseAddress
0041695A  51                                            push    ecx; hProcess
0041695B  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041695D  8b 15 68 86 42 00                             mov     edx, dword_428668
00416963  a1 6c 86 42 00                                mov     eax, off_42866C
00416968  8b 0d 64 86 42 00                             mov     ecx, dword_428664
0041696E  55                                            push    ebp; lpNumberOfBytesWritten
0041696F  52                                            push    edx; nSize
00416970  8b 56 70                                      mov     edx, [esi+70h]
00416973  50                                            push    eax; lpBuffer
00416974  51                                            push    ecx; lpBaseAddress
00416975  52                                            push    edx; hProcess
00416976  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416978  a1 88 84 42 00                                mov     eax, dword_428488
0041697D  8b 0d 8c 84 42 00                             mov     ecx, off_42848C
00416983  8b 15 84 84 42 00                             mov     edx, dword_428484
00416989  55                                            push    ebp; lpNumberOfBytesWritten
0041698A  50                                            push    eax; nSize
0041698B  8b 46 70                                      mov     eax, [esi+70h]
0041698E  51                                            push    ecx; lpBuffer
0041698F  52                                            push    edx; lpBaseAddress
00416990  50                                            push    eax; hProcess
00416991  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416993  8b 0d 30 84 42 00                             mov     ecx, dword_428430
00416999  8b 15 34 84 42 00                             mov     edx, off_428434
0041699F  a1 2c 84 42 00                                mov     eax, dword_42842C
004169A4  55                                            push    ebp; lpNumberOfBytesWritten
004169A5  51                                            push    ecx; nSize
004169A6  52                                            push    edx; lpBuffer
004169A7  8b 4e 70                                      mov     ecx, [esi+70h]
004169AA  50                                            push    eax; lpBaseAddress
004169AB  51                                            push    ecx; hProcess
004169AC  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004169AE  8b 15 58 83 42 00                             mov     edx, dword_428358
004169B4  a1 5c 83 42 00                                mov     eax, off_42835C
004169B9  8b 0d 54 83 42 00                             mov     ecx, dword_428354
004169BF  55                                            push    ebp; lpNumberOfBytesWritten
004169C0  52                                            push    edx; nSize
004169C1  8b 56 70                                      mov     edx, [esi+70h]
004169C4  50                                            push    eax; lpBuffer
004169C5  51                                            push    ecx; lpBaseAddress
004169C6  52                                            push    edx; hProcess
004169C7  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004169C9  a1 60 81 42 00                                mov     eax, dword_428160
004169CE  8b 0d 64 81 42 00                             mov     ecx, off_428164
004169D4  8b 15 5c 81 42 00                             mov     edx, dword_42815C
004169DA  55                                            push    ebp; lpNumberOfBytesWritten
004169DB  50                                            push    eax; nSize
004169DC  8b 46 70                                      mov     eax, [esi+70h]
004169DF  51                                            push    ecx; lpBuffer
004169E0  52                                            push    edx; lpBaseAddress
004169E1  50                                            push    eax; hProcess
004169E2  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004169E4  8b 0d 28 81 42 00                             mov     ecx, dword_428128
004169EA  8b 15 2c 81 42 00                             mov     edx, off_42812C
004169F0  a1 24 81 42 00                                mov     eax, dword_428124
004169F5  55                                            push    ebp; lpNumberOfBytesWritten
004169F6  51                                            push    ecx; nSize
004169F7  8b 4e 70                                      mov     ecx, [esi+70h]
004169FA  52                                            push    edx; lpBuffer
004169FB  50                                            push    eax; lpBaseAddress
004169FC  51                                            push    ecx; hProcess
004169FD  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004169FF  33 db                                         xor     ebx, ebx
00416A01  8b 83 28 80 42 00                             mov     eax, dword_428028[ebx]
00416A07  8b 93 14 80 42 00                             mov     edx, dword_428014[ebx]
00416A0D  8b 8b 00 80 42 00                             mov     ecx, dword_428000[ebx]
00416A13  55                                            push    ebp; lpNumberOfBytesWritten
00416A14  05 80 80 42 00                                add     eax, offset unk_428080
00416A19  52                                            push    edx; nSize
00416A1A  8b 56 70                                      mov     edx, [esi+70h]
00416A1D  50                                            push    eax; lpBuffer
00416A1E  51                                            push    ecx; lpBaseAddress
00416A1F  52                                            push    edx; hProcess
00416A20  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416A22  83 c3 04                                      add     ebx, 4
00416A25  83 fb 14                                      cmp     ebx, 14h
00416A28  7c d7                                         jl      short loc_416A01
00416A2A  a1 78 74 42 00                                mov     eax, dword_427478
00416A2F  8b 0d 7c 74 42 00                             mov     ecx, off_42747C
00416A35  8b 15 74 74 42 00                             mov     edx, dword_427474
00416A3B  55                                            push    ebp; lpNumberOfBytesWritten
00416A3C  50                                            push    eax; nSize
00416A3D  8b 46 70                                      mov     eax, [esi+70h]
00416A40  51                                            push    ecx; lpBuffer
00416A41  52                                            push    edx; lpBaseAddress
00416A42  50                                            push    eax; hProcess
00416A43  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416A45  8b 0d e8 73 42 00                             mov     ecx, dword_4273E8
00416A4B  8b 15 ec 73 42 00                             mov     edx, off_4273EC
00416A51  a1 e4 73 42 00                                mov     eax, dword_4273E4
00416A56  55                                            push    ebp; lpNumberOfBytesWritten
00416A57  51                                            push    ecx; nSize
00416A58  8b 4e 70                                      mov     ecx, [esi+70h]
00416A5B  52                                            push    edx; lpBuffer
00416A5C  50                                            push    eax; lpBaseAddress
00416A5D  51                                            push    ecx; hProcess
00416A5E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416A60  8b 15 80 73 42 00                             mov     edx, dword_427380
00416A66  a1 84 73 42 00                                mov     eax, off_427384
00416A6B  8b 0d 7c 73 42 00                             mov     ecx, dword_42737C
00416A71  55                                            push    ebp; lpNumberOfBytesWritten
00416A72  52                                            push    edx; nSize
00416A73  8b 56 70                                      mov     edx, [esi+70h]
00416A76  50                                            push    eax; lpBuffer
00416A77  51                                            push    ecx; lpBaseAddress
00416A78  52                                            push    edx; hProcess
00416A79  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416A7B  a1 58 73 42 00                                mov     eax, dword_427358
00416A80  8b 0d 5c 73 42 00                             mov     ecx, off_42735C
00416A86  8b 15 54 73 42 00                             mov     edx, dword_427354
00416A8C  55                                            push    ebp; lpNumberOfBytesWritten
00416A8D  50                                            push    eax; nSize
00416A8E  8b 46 70                                      mov     eax, [esi+70h]
00416A91  51                                            push    ecx; lpBuffer
00416A92  52                                            push    edx; lpBaseAddress
00416A93  50                                            push    eax; hProcess
00416A94  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416A96  8b 0d 18 73 42 00                             mov     ecx, dword_427318
00416A9C  8b 15 1c 73 42 00                             mov     edx, off_42731C
00416AA2  a1 14 73 42 00                                mov     eax, dword_427314
00416AA7  55                                            push    ebp; lpNumberOfBytesWritten
00416AA8  51                                            push    ecx; nSize
00416AA9  8b 4e 70                                      mov     ecx, [esi+70h]
00416AAC  52                                            push    edx; lpBuffer
00416AAD  50                                            push    eax; lpBaseAddress
00416AAE  51                                            push    ecx; hProcess
00416AAF  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416AB1  8b 15 f8 7f 42 00                             mov     edx, dword_427FF8
00416AB7  a1 fc 7f 42 00                                mov     eax, off_427FFC
00416ABC  8b 0d f4 7f 42 00                             mov     ecx, dword_427FF4
00416AC2  55                                            push    ebp; lpNumberOfBytesWritten
00416AC3  52                                            push    edx; nSize
00416AC4  8b 56 70                                      mov     edx, [esi+70h]
00416AC7  50                                            push    eax; lpBuffer
00416AC8  51                                            push    ecx; lpBaseAddress
00416AC9  52                                            push    edx; hProcess
00416ACA  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416ACC  a1 d8 72 42 00                                mov     eax, dword_4272D8
00416AD1  8b 0d dc 72 42 00                             mov     ecx, off_4272DC
00416AD7  8b 15 d4 72 42 00                             mov     edx, dword_4272D4
00416ADD  55                                            push    ebp; lpNumberOfBytesWritten
00416ADE  50                                            push    eax; nSize
00416ADF  8b 46 70                                      mov     eax, [esi+70h]
00416AE2  51                                            push    ecx; lpBuffer
00416AE3  52                                            push    edx; lpBaseAddress
00416AE4  50                                            push    eax; hProcess
00416AE5  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416AE7  8b 0d 98 72 42 00                             mov     ecx, dword_427298
00416AED  8b 15 9c 72 42 00                             mov     edx, off_42729C
00416AF3  a1 94 72 42 00                                mov     eax, dword_427294
00416AF8  55                                            push    ebp; lpNumberOfBytesWritten
00416AF9  51                                            push    ecx; nSize
00416AFA  8b 4e 70                                      mov     ecx, [esi+70h]
00416AFD  52                                            push    edx; lpBuffer
00416AFE  50                                            push    eax; lpBaseAddress
00416AFF  51                                            push    ecx; hProcess
00416B00  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416B02  55                                            push    ebp; lpNumberOfBytesWritten
00416B03  8b 15 38 72 42 00                             mov     edx, dword_427238
00416B09  a1 3c 72 42 00                                mov     eax, off_42723C
00416B0E  8b 0d 34 72 42 00                             mov     ecx, dword_427234
00416B14  52                                            push    edx; nSize
00416B15  8b 56 70                                      mov     edx, [esi+70h]
00416B18  50                                            push    eax; lpBuffer
00416B19  51                                            push    ecx; lpBaseAddress
00416B1A  52                                            push    edx; hProcess
00416B1B  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416B1D  a1 f0 71 42 00                                mov     eax, dword_4271F0
00416B22  8b 0d f4 71 42 00                             mov     ecx, off_4271F4
00416B28  8b 15 ec 71 42 00                             mov     edx, dword_4271EC
00416B2E  55                                            push    ebp; lpNumberOfBytesWritten
00416B2F  50                                            push    eax; nSize
00416B30  8b 46 70                                      mov     eax, [esi+70h]
00416B33  51                                            push    ecx; lpBuffer
00416B34  52                                            push    edx; lpBaseAddress
00416B35  50                                            push    eax; hProcess
00416B36  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416B38  8b 0d 08 6f 42 00                             mov     ecx, dword_426F08
00416B3E  8b 15 0c 6f 42 00                             mov     edx, off_426F0C
00416B44  a1 04 6f 42 00                                mov     eax, dword_426F04
00416B49  55                                            push    ebp; lpNumberOfBytesWritten
00416B4A  51                                            push    ecx; nSize
00416B4B  8b 4e 70                                      mov     ecx, [esi+70h]
00416B4E  52                                            push    edx; lpBuffer
00416B4F  50                                            push    eax; lpBaseAddress
00416B50  51                                            push    ecx; hProcess
00416B51  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416B53  8b 15 48 00 42 00                             mov     edx, dword_420048
00416B59  a1 4c 00 42 00                                mov     eax, off_42004C
00416B5E  8b 0d 44 00 42 00                             mov     ecx, dword_420044
00416B64  55                                            push    ebp; lpNumberOfBytesWritten
00416B65  52                                            push    edx; nSize
00416B66  8b 56 70                                      mov     edx, [esi+70h]
00416B69  50                                            push    eax; lpBuffer
00416B6A  51                                            push    ecx; lpBaseAddress
00416B6B  52                                            push    edx; hProcess
00416B6C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416B6E  a1 70 71 42 00                                mov     eax, dword_427170
00416B73  8b 0d 74 71 42 00                             mov     ecx, off_427174
00416B79  8b 15 6c 71 42 00                             mov     edx, dword_42716C
00416B7F  55                                            push    ebp; lpNumberOfBytesWritten
00416B80  50                                            push    eax; nSize
00416B81  8b 46 70                                      mov     eax, [esi+70h]
00416B84  51                                            push    ecx; lpBuffer
00416B85  52                                            push    edx; lpBaseAddress
00416B86  50                                            push    eax; hProcess
00416B87  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416B89  8b 0d 48 71 42 00                             mov     ecx, dword_427148
00416B8F  8b 15 4c 71 42 00                             mov     edx, off_42714C
00416B95  a1 44 71 42 00                                mov     eax, dword_427144
00416B9A  55                                            push    ebp; lpNumberOfBytesWritten
00416B9B  51                                            push    ecx; nSize
00416B9C  8b 4e 70                                      mov     ecx, [esi+70h]
00416B9F  52                                            push    edx; lpBuffer
00416BA0  50                                            push    eax; lpBaseAddress
00416BA1  51                                            push    ecx; hProcess
00416BA2  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416BA4  8b 15 c0 70 42 00                             mov     edx, dword_4270C0
00416BAA  a1 c4 70 42 00                                mov     eax, off_4270C4
00416BAF  8b 0d bc 70 42 00                             mov     ecx, dword_4270BC
00416BB5  55                                            push    ebp; lpNumberOfBytesWritten
00416BB6  52                                            push    edx; nSize
00416BB7  8b 56 70                                      mov     edx, [esi+70h]
00416BBA  50                                            push    eax; lpBuffer
00416BBB  51                                            push    ecx; lpBaseAddress
00416BBC  52                                            push    edx; hProcess
00416BBD  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416BBF  a1 b8 6f 42 00                                mov     eax, dword_426FB8
00416BC4  8b 0d bc 6f 42 00                             mov     ecx, off_426FBC
00416BCA  8b 15 b4 6f 42 00                             mov     edx, dword_426FB4
00416BD0  55                                            push    ebp; lpNumberOfBytesWritten
00416BD1  50                                            push    eax; nSize
00416BD2  8b 46 70                                      mov     eax, [esi+70h]
00416BD5  51                                            push    ecx; lpBuffer
00416BD6  52                                            push    edx; lpBaseAddress
00416BD7  50                                            push    eax; hProcess
00416BD8  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416BDA  8b 0d e0 6e 42 00                             mov     ecx, dword_426EE0
00416BE0  55                                            push    ebp; lpNumberOfBytesWritten
00416BE1  8b 15 e4 6e 42 00                             mov     edx, off_426EE4
00416BE7  a1 dc 6e 42 00                                mov     eax, dword_426EDC
00416BEC  51                                            push    ecx; nSize
00416BED  8b 4e 70                                      mov     ecx, [esi+70h]
00416BF0  52                                            push    edx; lpBuffer
00416BF1  50                                            push    eax; lpBaseAddress
00416BF2  51                                            push    ecx; hProcess
00416BF3  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416BF5  8b 15 80 7a 42 00                             mov     edx, dword_427A80
00416BFB  a1 84 7a 42 00                                mov     eax, off_427A84
00416C00  8b 0d 7c 7a 42 00                             mov     ecx, dword_427A7C
00416C06  55                                            push    ebp; lpNumberOfBytesWritten
00416C07  52                                            push    edx; nSize
00416C08  8b 56 70                                      mov     edx, [esi+70h]
00416C0B  50                                            push    eax; lpBuffer
00416C0C  51                                            push    ecx; lpBaseAddress
00416C0D  52                                            push    edx; hProcess
00416C0E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416C10  a1 38 79 42 00                                mov     eax, dword_427938
00416C15  8b 0d 3c 79 42 00                             mov     ecx, off_42793C
00416C1B  8b 15 34 79 42 00                             mov     edx, dword_427934
00416C21  55                                            push    ebp; lpNumberOfBytesWritten
00416C22  50                                            push    eax; nSize
00416C23  8b 46 70                                      mov     eax, [esi+70h]
00416C26  51                                            push    ecx; lpBuffer
00416C27  52                                            push    edx; lpBaseAddress
00416C28  50                                            push    eax; hProcess
00416C29  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416C2B  8b 0d c8 7f 42 00                             mov     ecx, dword_427FC8
00416C31  8b 15 cc 7f 42 00                             mov     edx, off_427FCC
00416C37  a1 c4 7f 42 00                                mov     eax, dword_427FC4
00416C3C  55                                            push    ebp; lpNumberOfBytesWritten
00416C3D  51                                            push    ecx; nSize
00416C3E  8b 4e 70                                      mov     ecx, [esi+70h]
00416C41  52                                            push    edx; lpBuffer
00416C42  50                                            push    eax; lpBaseAddress
00416C43  51                                            push    ecx; hProcess
00416C44  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416C46  8b 15 d0 7c 42 00                             mov     edx, dword_427CD0
00416C4C  a1 d4 7c 42 00                                mov     eax, off_427CD4
00416C51  8b 0d cc 7c 42 00                             mov     ecx, dword_427CCC
00416C57  55                                            push    ebp; lpNumberOfBytesWritten
00416C58  52                                            push    edx; nSize
00416C59  8b 56 70                                      mov     edx, [esi+70h]
00416C5C  50                                            push    eax; lpBuffer
00416C5D  51                                            push    ecx; lpBaseAddress
00416C5E  52                                            push    edx; hProcess
00416C5F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416C61  a1 30 7f 42 00                                mov     eax, dword_427F30
00416C66  8b 0d 34 7f 42 00                             mov     ecx, off_427F34
00416C6C  8b 15 2c 7f 42 00                             mov     edx, dword_427F2C
00416C72  55                                            push    ebp; lpNumberOfBytesWritten
00416C73  50                                            push    eax; nSize
00416C74  8b 46 70                                      mov     eax, [esi+70h]
00416C77  51                                            push    ecx; lpBuffer
00416C78  52                                            push    edx; lpBaseAddress
00416C79  50                                            push    eax; hProcess
00416C7A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416C7C  8b 0d f0 7e 42 00                             mov     ecx, dword_427EF0
00416C82  8b 15 f4 7e 42 00                             mov     edx, off_427EF4
00416C88  a1 ec 7e 42 00                                mov     eax, dword_427EEC
00416C8D  55                                            push    ebp; lpNumberOfBytesWritten
00416C8E  51                                            push    ecx; nSize
00416C8F  8b 4e 70                                      mov     ecx, [esi+70h]
00416C92  52                                            push    edx; lpBuffer
00416C93  50                                            push    eax; lpBaseAddress
00416C94  51                                            push    ecx; hProcess
00416C95  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416C97  8b 15 08 7e 42 00                             mov     edx, dword_427E08
00416C9D  a1 0c 7e 42 00                                mov     eax, off_427E0C
00416CA2  8b 0d 04 7e 42 00                             mov     ecx, dword_427E04
00416CA8  55                                            push    ebp; lpNumberOfBytesWritten
00416CA9  52                                            push    edx; nSize
00416CAA  8b 56 70                                      mov     edx, [esi+70h]
00416CAD  50                                            push    eax; lpBuffer
00416CAE  51                                            push    ecx; lpBaseAddress
00416CAF  52                                            push    edx; hProcess
00416CB0  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416CB2  a1 78 7d 42 00                                mov     eax, dword_427D78
00416CB7  55                                            push    ebp; lpNumberOfBytesWritten
00416CB8  50                                            push    eax; nSize
00416CB9  8b 0d 7c 7d 42 00                             mov     ecx, off_427D7C
00416CBF  8b 15 74 7d 42 00                             mov     edx, dword_427D74
00416CC5  8b 46 70                                      mov     eax, [esi+70h]
00416CC8  51                                            push    ecx; lpBuffer
00416CC9  52                                            push    edx; lpBaseAddress
00416CCA  50                                            push    eax; hProcess
00416CCB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416CCD  8b 0d 80 7c 42 00                             mov     ecx, dword_427C80
00416CD3  8b 15 84 7c 42 00                             mov     edx, off_427C84
00416CD9  a1 7c 7c 42 00                                mov     eax, dword_427C7C
00416CDE  55                                            push    ebp; lpNumberOfBytesWritten
00416CDF  51                                            push    ecx; nSize
00416CE0  8b 4e 70                                      mov     ecx, [esi+70h]
00416CE3  52                                            push    edx; lpBuffer
00416CE4  50                                            push    eax; lpBaseAddress
00416CE5  51                                            push    ecx; hProcess
00416CE6  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416CE8  8b 15 98 7b 42 00                             mov     edx, dword_427B98
00416CEE  a1 9c 7b 42 00                                mov     eax, off_427B9C
00416CF3  8b 0d 94 7b 42 00                             mov     ecx, dword_427B94
00416CF9  55                                            push    ebp; lpNumberOfBytesWritten
00416CFA  52                                            push    edx; nSize
00416CFB  8b 56 70                                      mov     edx, [esi+70h]
00416CFE  50                                            push    eax; lpBuffer
00416CFF  51                                            push    ecx; lpBaseAddress
00416D00  52                                            push    edx; hProcess
00416D01  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416D03  a1 50 7b 42 00                                mov     eax, dword_427B50
00416D08  8b 0d 54 7b 42 00                             mov     ecx, off_427B54
00416D0E  8b 15 4c 7b 42 00                             mov     edx, dword_427B4C
00416D14  55                                            push    ebp; lpNumberOfBytesWritten
00416D15  50                                            push    eax; nSize
00416D16  8b 46 70                                      mov     eax, [esi+70h]
00416D19  51                                            push    ecx; lpBuffer
00416D1A  52                                            push    edx; lpBaseAddress
00416D1B  50                                            push    eax; hProcess
00416D1C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416D1E  8b 0d 28 7b 42 00                             mov     ecx, dword_427B28
00416D24  8b 15 2c 7b 42 00                             mov     edx, off_427B2C
00416D2A  a1 24 7b 42 00                                mov     eax, dword_427B24
00416D2F  55                                            push    ebp; lpNumberOfBytesWritten
00416D30  51                                            push    ecx; nSize
00416D31  8b 4e 70                                      mov     ecx, [esi+70h]
00416D34  52                                            push    edx; lpBuffer
00416D35  50                                            push    eax; lpBaseAddress
00416D36  51                                            push    ecx; hProcess
00416D37  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416D39  8b 15 08 7a 42 00                             mov     edx, dword_427A08
00416D3F  a1 0c 7a 42 00                                mov     eax, off_427A0C
00416D44  8b 0d 04 7a 42 00                             mov     ecx, dword_427A04
00416D4A  55                                            push    ebp; lpNumberOfBytesWritten
00416D4B  52                                            push    edx; nSize
00416D4C  8b 56 70                                      mov     edx, [esi+70h]
00416D4F  50                                            push    eax; lpBuffer
00416D50  51                                            push    ecx; lpBaseAddress
00416D51  52                                            push    edx; hProcess
00416D52  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416D54  a1 50 99 42 00                                mov     eax, dword_429950
00416D59  8b 0d 54 99 42 00                             mov     ecx, off_429954
00416D5F  8b 15 4c 99 42 00                             mov     edx, dword_42994C
00416D65  55                                            push    ebp; lpNumberOfBytesWritten
00416D66  50                                            push    eax; nSize
00416D67  8b 46 70                                      mov     eax, [esi+70h]
00416D6A  51                                            push    ecx; lpBuffer
00416D6B  52                                            push    edx; lpBaseAddress
00416D6C  50                                            push    eax; hProcess
00416D6D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416D6F  8b 0d 10 99 42 00                             mov     ecx, dword_429910
00416D75  8b 15 14 99 42 00                             mov     edx, off_429914
00416D7B  a1 0c 99 42 00                                mov     eax, dword_42990C
00416D80  55                                            push    ebp; lpNumberOfBytesWritten
00416D81  51                                            push    ecx; nSize
00416D82  8b 4e 70                                      mov     ecx, [esi+70h]
00416D85  52                                            push    edx; lpBuffer
00416D86  50                                            push    eax; lpBaseAddress
00416D87  51                                            push    ecx; hProcess
00416D88  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416D8A  8b 15 a0 79 42 00                             mov     edx, dword_4279A0
00416D90  a1 a4 79 42 00                                mov     eax, off_4279A4
00416D95  55                                            push    ebp; lpNumberOfBytesWritten
00416D96  52                                            push    edx; nSize
00416D97  8b 0d 9c 79 42 00                             mov     ecx, dword_42799C
00416D9D  8b 56 70                                      mov     edx, [esi+70h]
00416DA0  50                                            push    eax; lpBuffer
00416DA1  51                                            push    ecx; lpBaseAddress
00416DA2  52                                            push    edx; hProcess
00416DA3  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416DA5  a1 f0 78 42 00                                mov     eax, dword_4278F0
00416DAA  8b 0d f4 78 42 00                             mov     ecx, off_4278F4
00416DB0  8b 15 ec 78 42 00                             mov     edx, dword_4278EC
00416DB6  55                                            push    ebp; lpNumberOfBytesWritten
00416DB7  50                                            push    eax; nSize
00416DB8  8b 46 70                                      mov     eax, [esi+70h]
00416DBB  51                                            push    ecx; lpBuffer
00416DBC  52                                            push    edx; lpBaseAddress
00416DBD  50                                            push    eax; hProcess
00416DBE  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416DC0  8b 0d c8 78 42 00                             mov     ecx, dword_4278C8
00416DC6  8b 15 cc 78 42 00                             mov     edx, off_4278CC
00416DCC  a1 c4 78 42 00                                mov     eax, dword_4278C4
00416DD1  55                                            push    ebp; lpNumberOfBytesWritten
00416DD2  51                                            push    ecx; nSize
00416DD3  8b 4e 70                                      mov     ecx, [esi+70h]
00416DD6  52                                            push    edx; lpBuffer
00416DD7  50                                            push    eax; lpBaseAddress
00416DD8  51                                            push    ecx; hProcess
00416DD9  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416DDB  8b 15 a0 78 42 00                             mov     edx, dword_4278A0
00416DE1  a1 a4 78 42 00                                mov     eax, off_4278A4
00416DE6  8b 0d 9c 78 42 00                             mov     ecx, dword_42789C
00416DEC  55                                            push    ebp; lpNumberOfBytesWritten
00416DED  52                                            push    edx; nSize
00416DEE  8b 56 70                                      mov     edx, [esi+70h]
00416DF1  50                                            push    eax; lpBuffer
00416DF2  51                                            push    ecx; lpBaseAddress
00416DF3  52                                            push    edx; hProcess
00416DF4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416DF6  a1 c0 74 42 00                                mov     eax, dword_4274C0
00416DFB  8b 0d c4 74 42 00                             mov     ecx, off_4274C4
00416E01  8b 15 bc 74 42 00                             mov     edx, dword_4274BC
00416E07  55                                            push    ebp; lpNumberOfBytesWritten
00416E08  50                                            push    eax; nSize
00416E09  8b 46 70                                      mov     eax, [esi+70h]
00416E0C  51                                            push    ecx; lpBuffer
00416E0D  52                                            push    edx; lpBaseAddress
00416E0E  50                                            push    eax; hProcess
00416E0F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416E11  8b 0d e0 6f 42 00                             mov     ecx, dword_426FE0
00416E17  8b 15 e4 6f 42 00                             mov     edx, off_426FE4
00416E1D  a1 dc 6f 42 00                                mov     eax, dword_426FDC
00416E22  55                                            push    ebp; lpNumberOfBytesWritten
00416E23  51                                            push    ecx; nSize
00416E24  8b 4e 70                                      mov     ecx, [esi+70h]
00416E27  52                                            push    edx; lpBuffer
00416E28  50                                            push    eax; lpBaseAddress
00416E29  51                                            push    ecx; hProcess
00416E2A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416E2C  8b 15 78 6e 42 00                             mov     edx, dword_426E78
00416E32  a1 7c 6e 42 00                                mov     eax, off_426E7C
00416E37  8b 0d 74 6e 42 00                             mov     ecx, dword_426E74
00416E3D  55                                            push    ebp; lpNumberOfBytesWritten
00416E3E  52                                            push    edx; nSize
00416E3F  8b 56 70                                      mov     edx, [esi+70h]
00416E42  50                                            push    eax; lpBuffer
00416E43  51                                            push    ecx; lpBaseAddress
00416E44  52                                            push    edx; hProcess
00416E45  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416E47  a1 38 6e 42 00                                mov     eax, dword_426E38
00416E4C  8b 0d 3c 6e 42 00                             mov     ecx, off_426E3C
00416E52  8b 15 34 6e 42 00                             mov     edx, dword_426E34
00416E58  55                                            push    ebp; lpNumberOfBytesWritten
00416E59  50                                            push    eax; nSize
00416E5A  8b 46 70                                      mov     eax, [esi+70h]
00416E5D  51                                            push    ecx; lpBuffer
00416E5E  52                                            push    edx; lpBaseAddress
00416E5F  50                                            push    eax; hProcess
00416E60  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416E62  8b 0d b0 6c 42 00                             mov     ecx, dword_426CB0
00416E68  8b 15 b4 6c 42 00                             mov     edx, off_426CB4
00416E6E  55                                            push    ebp; lpNumberOfBytesWritten
00416E6F  51                                            push    ecx; nSize
00416E70  52                                            push    edx; lpBuffer
00416E71  a1 ac 6c 42 00                                mov     eax, dword_426CAC
00416E76  8b 4e 70                                      mov     ecx, [esi+70h]
00416E79  50                                            push    eax; lpBaseAddress
00416E7A  51                                            push    ecx; hProcess
00416E7B  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416E7D  8b 15 38 6b 42 00                             mov     edx, dword_426B38
00416E83  a1 3c 6b 42 00                                mov     eax, off_426B3C
00416E88  8b 0d 34 6b 42 00                             mov     ecx, dword_426B34
00416E8E  55                                            push    ebp; lpNumberOfBytesWritten
00416E8F  52                                            push    edx; nSize
00416E90  8b 56 70                                      mov     edx, [esi+70h]
00416E93  50                                            push    eax; lpBuffer
00416E94  51                                            push    ecx; lpBaseAddress
00416E95  52                                            push    edx; hProcess
00416E96  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416E98  a1 50 67 42 00                                mov     eax, dword_426750
00416E9D  8b 0d 54 67 42 00                             mov     ecx, off_426754
00416EA3  8b 15 4c 67 42 00                             mov     edx, dword_42674C
00416EA9  55                                            push    ebp; lpNumberOfBytesWritten
00416EAA  50                                            push    eax; nSize
00416EAB  8b 46 70                                      mov     eax, [esi+70h]
00416EAE  51                                            push    ecx; lpBuffer
00416EAF  52                                            push    edx; lpBaseAddress
00416EB0  50                                            push    eax; hProcess
00416EB1  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416EB3  bb d8 66 42 00                                mov     ebx, offset off_4266D8
00416EB8  8b 4b fc                                      mov     ecx, [ebx-4]
00416EBB  8b 13                                         mov     edx, [ebx]
00416EBD  8b 43 f8                                      mov     eax, [ebx-8]
00416EC0  55                                            push    ebp; lpNumberOfBytesWritten
00416EC1  51                                            push    ecx; nSize
00416EC2  8b 4e 70                                      mov     ecx, [esi+70h]
00416EC5  52                                            push    edx; lpBuffer
00416EC6  50                                            push    eax; lpBaseAddress
00416EC7  51                                            push    ecx; hProcess
00416EC8  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416ECA  83 c3 0c                                      add     ebx, 0Ch
00416ECD  81 fb 14 67 42 00                             cmp     ebx, offset dword_426714
00416ED3  7c e3                                         jl      short loc_416EB8
00416ED5  8b 15 38 65 42 00                             mov     edx, dword_426538
00416EDB  a1 3c 65 42 00                                mov     eax, off_42653C
00416EE0  8b 0d 34 65 42 00                             mov     ecx, dword_426534
00416EE6  55                                            push    ebp; lpNumberOfBytesWritten
00416EE7  52                                            push    edx; nSize
00416EE8  8b 56 70                                      mov     edx, [esi+70h]
00416EEB  50                                            push    eax; lpBuffer
00416EEC  51                                            push    ecx; lpBaseAddress
00416EED  52                                            push    edx; hProcess
00416EEE  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416EF0  a1 e0 64 42 00                                mov     eax, dword_4264E0
00416EF5  8b 0d e4 64 42 00                             mov     ecx, off_4264E4
00416EFB  8b 15 dc 64 42 00                             mov     edx, dword_4264DC
00416F01  55                                            push    ebp; lpNumberOfBytesWritten
00416F02  50                                            push    eax; nSize
00416F03  8b 46 70                                      mov     eax, [esi+70h]
00416F06  51                                            push    ecx; lpBuffer
00416F07  52                                            push    edx; lpBaseAddress
00416F08  50                                            push    eax; hProcess
00416F09  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416F0B  8b 0d 20 63 42 00                             mov     ecx, dword_426320
00416F11  8b 15 24 63 42 00                             mov     edx, off_426324
00416F17  a1 1c 63 42 00                                mov     eax, dword_42631C
00416F1C  55                                            push    ebp; lpNumberOfBytesWritten
00416F1D  51                                            push    ecx; nSize
00416F1E  8b 4e 70                                      mov     ecx, [esi+70h]
00416F21  52                                            push    edx; lpBuffer
00416F22  50                                            push    eax; lpBaseAddress
00416F23  51                                            push    ecx; hProcess
00416F24  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416F26  8b 15 00 61 42 00                             mov     edx, dword_426100
00416F2C  a1 04 61 42 00                                mov     eax, off_426104
00416F31  8b 0d fc 60 42 00                             mov     ecx, dword_4260FC
00416F37  55                                            push    ebp; lpNumberOfBytesWritten
00416F38  52                                            push    edx; nSize
00416F39  8b 56 70                                      mov     edx, [esi+70h]
00416F3C  50                                            push    eax; lpBuffer
00416F3D  51                                            push    ecx; lpBaseAddress
00416F3E  52                                            push    edx; hProcess
00416F3F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416F41  a1 98 60 42 00                                mov     eax, dword_426098
00416F46  8b 0d 9c 60 42 00                             mov     ecx, off_42609C
00416F4C  8b 15 94 60 42 00                             mov     edx, dword_426094
00416F52  55                                            push    ebp; lpNumberOfBytesWritten
00416F53  50                                            push    eax; nSize
00416F54  8b 46 70                                      mov     eax, [esi+70h]
00416F57  51                                            push    ecx; lpBuffer
00416F58  52                                            push    edx; lpBaseAddress
00416F59  50                                            push    eax; hProcess
00416F5A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416F5C  8b 0d 38 60 42 00                             mov     ecx, dword_426038
00416F62  8b 15 3c 60 42 00                             mov     edx, off_42603C
00416F68  a1 34 60 42 00                                mov     eax, dword_426034
00416F6D  55                                            push    ebp; lpNumberOfBytesWritten
00416F6E  51                                            push    ecx; nSize
00416F6F  8b 4e 70                                      mov     ecx, [esi+70h]
00416F72  52                                            push    edx; lpBuffer
00416F73  50                                            push    eax; lpBaseAddress
00416F74  51                                            push    ecx; hProcess
00416F75  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416F77  8b 15 80 5f 42 00                             mov     edx, dword_425F80
00416F7D  a1 84 5f 42 00                                mov     eax, off_425F84
00416F82  8b 0d 7c 5f 42 00                             mov     ecx, dword_425F7C
00416F88  55                                            push    ebp; lpNumberOfBytesWritten
00416F89  52                                            push    edx; nSize
00416F8A  8b 56 70                                      mov     edx, [esi+70h]
00416F8D  50                                            push    eax; lpBuffer
00416F8E  51                                            push    ecx; lpBaseAddress
00416F8F  52                                            push    edx; hProcess
00416F90  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416F92  a1 98 5e 42 00                                mov     eax, dword_425E98
00416F97  8b 0d 9c 5e 42 00                             mov     ecx, off_425E9C
00416F9D  8b 15 94 5e 42 00                             mov     edx, dword_425E94
00416FA3  55                                            push    ebp; lpNumberOfBytesWritten
00416FA4  50                                            push    eax; nSize
00416FA5  8b 46 70                                      mov     eax, [esi+70h]
00416FA8  51                                            push    ecx; lpBuffer
00416FA9  52                                            push    edx; lpBaseAddress
00416FAA  50                                            push    eax; hProcess
00416FAB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416FAD  55                                            push    ebp; lpNumberOfBytesWritten
00416FAE  8b 0d 80 5d 42 00                             mov     ecx, dword_425D80
00416FB4  8b 15 84 5d 42 00                             mov     edx, off_425D84
00416FBA  a1 7c 5d 42 00                                mov     eax, dword_425D7C
00416FBF  51                                            push    ecx; nSize
00416FC0  8b 4e 70                                      mov     ecx, [esi+70h]
00416FC3  52                                            push    edx; lpBuffer
00416FC4  50                                            push    eax; lpBaseAddress
00416FC5  51                                            push    ecx; hProcess
00416FC6  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416FC8  8b 15 10 5d 42 00                             mov     edx, dword_425D10
00416FCE  a1 14 5d 42 00                                mov     eax, off_425D14
00416FD3  8b 0d 0c 5d 42 00                             mov     ecx, dword_425D0C
00416FD9  55                                            push    ebp; lpNumberOfBytesWritten
00416FDA  52                                            push    edx; nSize
00416FDB  8b 56 70                                      mov     edx, [esi+70h]
00416FDE  50                                            push    eax; lpBuffer
00416FDF  51                                            push    ecx; lpBaseAddress
00416FE0  52                                            push    edx; hProcess
00416FE1  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416FE3  a1 d0 5c 42 00                                mov     eax, dword_425CD0
00416FE8  8b 0d d4 5c 42 00                             mov     ecx, off_425CD4
00416FEE  8b 15 cc 5c 42 00                             mov     edx, dword_425CCC
00416FF4  55                                            push    ebp; lpNumberOfBytesWritten
00416FF5  50                                            push    eax; nSize
00416FF6  8b 46 70                                      mov     eax, [esi+70h]
00416FF9  51                                            push    ecx; lpBuffer
00416FFA  52                                            push    edx; lpBaseAddress
00416FFB  50                                            push    eax; hProcess
00416FFC  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00416FFE  8b 0d b0 5c 42 00                             mov     ecx, dword_425CB0
00417004  8b 15 b4 5c 42 00                             mov     edx, off_425CB4
0041700A  a1 ac 5c 42 00                                mov     eax, dword_425CAC
0041700F  55                                            push    ebp; lpNumberOfBytesWritten
00417010  51                                            push    ecx; nSize
00417011  8b 4e 70                                      mov     ecx, [esi+70h]
00417014  52                                            push    edx; lpBuffer
00417015  50                                            push    eax; lpBaseAddress
00417016  51                                            push    ecx; hProcess
00417017  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417019  8b 15 78 5c 42 00                             mov     edx, dword_425C78
0041701F  a1 7c 5c 42 00                                mov     eax, off_425C7C
00417024  8b 0d 74 5c 42 00                             mov     ecx, dword_425C74
0041702A  55                                            push    ebp; lpNumberOfBytesWritten
0041702B  52                                            push    edx; nSize
0041702C  8b 56 70                                      mov     edx, [esi+70h]
0041702F  50                                            push    eax; lpBuffer
00417030  51                                            push    ecx; lpBaseAddress
00417031  52                                            push    edx; hProcess
00417032  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417034  a1 58 5c 42 00                                mov     eax, dword_425C58
00417039  8b 0d 5c 5c 42 00                             mov     ecx, off_425C5C
0041703F  8b 15 54 5c 42 00                             mov     edx, dword_425C54
00417045  55                                            push    ebp; lpNumberOfBytesWritten
00417046  50                                            push    eax; nSize
00417047  8b 46 70                                      mov     eax, [esi+70h]
0041704A  51                                            push    ecx; lpBuffer
0041704B  52                                            push    edx; lpBaseAddress
0041704C  50                                            push    eax; hProcess
0041704D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041704F  8b 0d 20 5c 42 00                             mov     ecx, dword_425C20
00417055  8b 15 24 5c 42 00                             mov     edx, off_425C24
0041705B  a1 1c 5c 42 00                                mov     eax, dword_425C1C
00417060  55                                            push    ebp; lpNumberOfBytesWritten
00417061  51                                            push    ecx; nSize
00417062  8b 4e 70                                      mov     ecx, [esi+70h]
00417065  52                                            push    edx; lpBuffer
00417066  50                                            push    eax; lpBaseAddress
00417067  51                                            push    ecx; hProcess
00417068  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041706A  8b 15 f8 5b 42 00                             mov     edx, dword_425BF8
00417070  a1 fc 5b 42 00                                mov     eax, off_425BFC
00417075  8b 0d f4 5b 42 00                             mov     ecx, dword_425BF4
0041707B  55                                            push    ebp; lpNumberOfBytesWritten
0041707C  52                                            push    edx; nSize
0041707D  8b 56 70                                      mov     edx, [esi+70h]
00417080  50                                            push    eax; lpBuffer
00417081  51                                            push    ecx; lpBaseAddress
00417082  52                                            push    edx; hProcess
00417083  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417085  a1 b8 5b 42 00                                mov     eax, dword_425BB8
0041708A  55                                            push    ebp; lpNumberOfBytesWritten
0041708B  8b 0d bc 5b 42 00                             mov     ecx, off_425BBC
00417091  8b 15 b4 5b 42 00                             mov     edx, dword_425BB4
00417097  50                                            push    eax; nSize
00417098  8b 46 70                                      mov     eax, [esi+70h]
0041709B  51                                            push    ecx; lpBuffer
0041709C  52                                            push    edx; lpBaseAddress
0041709D  50                                            push    eax; hProcess
0041709E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004170A0  8b 0d 78 5b 42 00                             mov     ecx, dword_425B78
004170A6  8b 15 7c 5b 42 00                             mov     edx, off_425B7C
004170AC  a1 74 5b 42 00                                mov     eax, dword_425B74
004170B1  55                                            push    ebp; lpNumberOfBytesWritten
004170B2  51                                            push    ecx; nSize
004170B3  8b 4e 70                                      mov     ecx, [esi+70h]
004170B6  52                                            push    edx; lpBuffer
004170B7  50                                            push    eax; lpBaseAddress
004170B8  51                                            push    ecx; hProcess
004170B9  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004170BB  8b 15 50 5b 42 00                             mov     edx, dword_425B50
004170C1  a1 54 5b 42 00                                mov     eax, off_425B54
004170C6  8b 0d 4c 5b 42 00                             mov     ecx, dword_425B4C
004170CC  55                                            push    ebp; lpNumberOfBytesWritten
004170CD  52                                            push    edx; nSize
004170CE  8b 56 70                                      mov     edx, [esi+70h]
004170D1  50                                            push    eax; lpBuffer
004170D2  51                                            push    ecx; lpBaseAddress
004170D3  52                                            push    edx; hProcess
004170D4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004170D6  a1 10 5b 42 00                                mov     eax, dword_425B10
004170DB  8b 0d 14 5b 42 00                             mov     ecx, off_425B14
004170E1  8b 15 0c 5b 42 00                             mov     edx, dword_425B0C
004170E7  55                                            push    ebp; lpNumberOfBytesWritten
004170E8  50                                            push    eax; nSize
004170E9  8b 46 70                                      mov     eax, [esi+70h]
004170EC  51                                            push    ecx; lpBuffer
004170ED  52                                            push    edx; lpBaseAddress
004170EE  50                                            push    eax; hProcess
004170EF  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004170F1  8b 0d e8 5a 42 00                             mov     ecx, dword_425AE8
004170F7  8b 15 ec 5a 42 00                             mov     edx, off_425AEC
004170FD  a1 e4 5a 42 00                                mov     eax, dword_425AE4
00417102  55                                            push    ebp; lpNumberOfBytesWritten
00417103  51                                            push    ecx; nSize
00417104  8b 4e 70                                      mov     ecx, [esi+70h]
00417107  52                                            push    edx; lpBuffer
00417108  50                                            push    eax; lpBaseAddress
00417109  51                                            push    ecx; hProcess
0041710A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041710C  8b 15 c0 5a 42 00                             mov     edx, dword_425AC0
00417112  a1 c4 5a 42 00                                mov     eax, off_425AC4
00417117  8b 0d bc 5a 42 00                             mov     ecx, dword_425ABC
0041711D  55                                            push    ebp; lpNumberOfBytesWritten
0041711E  52                                            push    edx; nSize
0041711F  8b 56 70                                      mov     edx, [esi+70h]
00417122  50                                            push    eax; lpBuffer
00417123  51                                            push    ecx; lpBaseAddress
00417124  52                                            push    edx; hProcess
00417125  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417127  a1 98 5a 42 00                                mov     eax, dword_425A98
0041712C  8b 0d 9c 5a 42 00                             mov     ecx, off_425A9C
00417132  8b 15 94 5a 42 00                             mov     edx, dword_425A94
00417138  55                                            push    ebp; lpNumberOfBytesWritten
00417139  50                                            push    eax; nSize
0041713A  8b 46 70                                      mov     eax, [esi+70h]
0041713D  51                                            push    ecx; lpBuffer
0041713E  52                                            push    edx; lpBaseAddress
0041713F  50                                            push    eax; hProcess
00417140  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417142  8b 0d 48 5a 42 00                             mov     ecx, dword_425A48
00417148  8b 15 4c 5a 42 00                             mov     edx, off_425A4C
0041714E  a1 44 5a 42 00                                mov     eax, dword_425A44
00417153  55                                            push    ebp; lpNumberOfBytesWritten
00417154  51                                            push    ecx; nSize
00417155  8b 4e 70                                      mov     ecx, [esi+70h]
00417158  52                                            push    edx; lpBuffer
00417159  50                                            push    eax; lpBaseAddress
0041715A  51                                            push    ecx; hProcess
0041715B  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041715D  8b 15 08 5a 42 00                             mov     edx, dword_425A08
00417163  55                                            push    ebp; lpNumberOfBytesWritten
00417164  52                                            push    edx; nSize
00417165  a1 0c 5a 42 00                                mov     eax, off_425A0C
0041716A  8b 0d 04 5a 42 00                             mov     ecx, dword_425A04
00417170  8b 56 70                                      mov     edx, [esi+70h]
00417173  50                                            push    eax; lpBuffer
00417174  51                                            push    ecx; lpBaseAddress
00417175  52                                            push    edx; hProcess
00417176  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417178  a1 e0 59 42 00                                mov     eax, dword_4259E0
0041717D  8b 0d e4 59 42 00                             mov     ecx, off_4259E4
00417183  8b 15 dc 59 42 00                             mov     edx, dword_4259DC
00417189  55                                            push    ebp; lpNumberOfBytesWritten
0041718A  50                                            push    eax; nSize
0041718B  8b 46 70                                      mov     eax, [esi+70h]
0041718E  51                                            push    ecx; lpBuffer
0041718F  52                                            push    edx; lpBaseAddress
00417190  50                                            push    eax; hProcess
00417191  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417193  8b 0d b8 59 42 00                             mov     ecx, dword_4259B8
00417199  8b 15 bc 59 42 00                             mov     edx, off_4259BC
0041719F  a1 b4 59 42 00                                mov     eax, dword_4259B4
004171A4  55                                            push    ebp; lpNumberOfBytesWritten
004171A5  51                                            push    ecx; nSize
004171A6  8b 4e 70                                      mov     ecx, [esi+70h]
004171A9  52                                            push    edx; lpBuffer
004171AA  50                                            push    eax; lpBaseAddress
004171AB  51                                            push    ecx; hProcess
004171AC  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004171AE  8b 15 90 59 42 00                             mov     edx, dword_425990
004171B4  a1 94 59 42 00                                mov     eax, off_425994
004171B9  8b 0d 8c 59 42 00                             mov     ecx, dword_42598C
004171BF  55                                            push    ebp; lpNumberOfBytesWritten
004171C0  52                                            push    edx; nSize
004171C1  8b 56 70                                      mov     edx, [esi+70h]
004171C4  50                                            push    eax; lpBuffer
004171C5  51                                            push    ecx; lpBaseAddress
004171C6  52                                            push    edx; hProcess
004171C7  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004171C9  33 db                                         xor     ebx, ebx
004171CB  8b 8b f8 58 42 00                             mov     ecx, dword_4258F8[ebx]
004171D1  8b 83 f0 58 42 00                             mov     eax, dword_4258F0[ebx]
004171D7  8b 93 e8 58 42 00                             mov     edx, dword_4258E8[ebx]
004171DD  55                                            push    ebp; lpNumberOfBytesWritten
004171DE  81 c1 2c 59 42 00                             add     ecx, offset unk_42592C
004171E4  50                                            push    eax; nSize
004171E5  8b 46 70                                      mov     eax, [esi+70h]
004171E8  51                                            push    ecx; lpBuffer
004171E9  52                                            push    edx; lpBaseAddress
004171EA  50                                            push    eax; hProcess
004171EB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004171ED  83 c3 04                                      add     ebx, 4
004171F0  83 fb 08                                      cmp     ebx, 8
004171F3  7c d6                                         jl      short loc_4171CB
004171F5  8b 0d 38 58 42 00                             mov     ecx, dword_425838
004171FB  8b 15 3c 58 42 00                             mov     edx, off_42583C
00417201  a1 34 58 42 00                                mov     eax, dword_425834
00417206  55                                            push    ebp; lpNumberOfBytesWritten
00417207  51                                            push    ecx; nSize
00417208  8b 4e 70                                      mov     ecx, [esi+70h]
0041720B  52                                            push    edx; lpBuffer
0041720C  50                                            push    eax; lpBaseAddress
0041720D  51                                            push    ecx; hProcess
0041720E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417210  8b 15 e8 57 42 00                             mov     edx, dword_4257E8
00417216  a1 ec 57 42 00                                mov     eax, off_4257EC
0041721B  8b 0d e4 57 42 00                             mov     ecx, dword_4257E4
00417221  55                                            push    ebp; lpNumberOfBytesWritten
00417222  52                                            push    edx; nSize
00417223  8b 56 70                                      mov     edx, [esi+70h]
00417226  50                                            push    eax; lpBuffer
00417227  51                                            push    ecx; lpBaseAddress
00417228  52                                            push    edx; hProcess
00417229  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041722B  a1 a8 57 42 00                                mov     eax, dword_4257A8
00417230  8b 0d ac 57 42 00                             mov     ecx, off_4257AC
00417236  8b 15 a4 57 42 00                             mov     edx, dword_4257A4
0041723C  55                                            push    ebp; lpNumberOfBytesWritten
0041723D  50                                            push    eax; nSize
0041723E  8b 46 70                                      mov     eax, [esi+70h]
00417241  51                                            push    ecx; lpBuffer
00417242  52                                            push    edx; lpBaseAddress
00417243  50                                            push    eax; hProcess
00417244  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417246  8b 0d 38 57 42 00                             mov     ecx, dword_425738
0041724C  8b 15 3c 57 42 00                             mov     edx, off_42573C
00417252  a1 34 57 42 00                                mov     eax, dword_425734
00417257  55                                            push    ebp; lpNumberOfBytesWritten
00417258  51                                            push    ecx; nSize
00417259  8b 4e 70                                      mov     ecx, [esi+70h]
0041725C  52                                            push    edx; lpBuffer
0041725D  50                                            push    eax; lpBaseAddress
0041725E  51                                            push    ecx; hProcess
0041725F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417261  8b 15 30 4d 42 00                             mov     edx, dword_424D30
00417267  a1 34 4d 42 00                                mov     eax, off_424D34
0041726C  8b 0d 2c 4d 42 00                             mov     ecx, dword_424D2C
00417272  55                                            push    ebp; lpNumberOfBytesWritten
00417273  52                                            push    edx; nSize
00417274  8b 56 70                                      mov     edx, [esi+70h]
00417277  50                                            push    eax; lpBuffer
00417278  51                                            push    ecx; lpBaseAddress
00417279  52                                            push    edx; hProcess
0041727A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041727C  a1 b0 56 42 00                                mov     eax, dword_4256B0
00417281  8b 0d b4 56 42 00                             mov     ecx, off_4256B4
00417287  8b 15 ac 56 42 00                             mov     edx, dword_4256AC
0041728D  55                                            push    ebp; lpNumberOfBytesWritten
0041728E  50                                            push    eax; nSize
0041728F  8b 46 70                                      mov     eax, [esi+70h]
00417292  51                                            push    ecx; lpBuffer
00417293  52                                            push    edx; lpBaseAddress
00417294  50                                            push    eax; hProcess
00417295  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417297  8b 0d 20 56 42 00                             mov     ecx, dword_425620
0041729D  8b 15 24 56 42 00                             mov     edx, off_425624
004172A3  a1 1c 56 42 00                                mov     eax, dword_42561C
004172A8  55                                            push    ebp; lpNumberOfBytesWritten
004172A9  51                                            push    ecx; nSize
004172AA  8b 4e 70                                      mov     ecx, [esi+70h]
004172AD  52                                            push    edx; lpBuffer
004172AE  50                                            push    eax; lpBaseAddress
004172AF  51                                            push    ecx; hProcess
004172B0  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004172B2  8b 15 e0 55 42 00                             mov     edx, dword_4255E0
004172B8  a1 e4 55 42 00                                mov     eax, off_4255E4
004172BD  8b 0d dc 55 42 00                             mov     ecx, dword_4255DC
004172C3  55                                            push    ebp; lpNumberOfBytesWritten
004172C4  52                                            push    edx; nSize
004172C5  8b 56 70                                      mov     edx, [esi+70h]
004172C8  50                                            push    eax; lpBuffer
004172C9  51                                            push    ecx; lpBaseAddress
004172CA  52                                            push    edx; hProcess
004172CB  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004172CD  55                                            push    ebp; lpNumberOfBytesWritten
004172CE  a1 28 55 42 00                                mov     eax, dword_425528
004172D3  8b 0d 2c 55 42 00                             mov     ecx, off_42552C
004172D9  8b 15 24 55 42 00                             mov     edx, dword_425524
004172DF  50                                            push    eax; nSize
004172E0  8b 46 70                                      mov     eax, [esi+70h]
004172E3  51                                            push    ecx; lpBuffer
004172E4  52                                            push    edx; lpBaseAddress
004172E5  50                                            push    eax; hProcess
004172E6  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004172E8  8b 0d 50 54 42 00                             mov     ecx, dword_425450
004172EE  8b 15 54 54 42 00                             mov     edx, off_425454
004172F4  a1 4c 54 42 00                                mov     eax, dword_42544C
004172F9  55                                            push    ebp; lpNumberOfBytesWritten
004172FA  51                                            push    ecx; nSize
004172FB  8b 4e 70                                      mov     ecx, [esi+70h]
004172FE  52                                            push    edx; lpBuffer
004172FF  50                                            push    eax; lpBaseAddress
00417300  51                                            push    ecx; hProcess
00417301  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417303  8b 15 28 48 42 00                             mov     edx, dword_424828
00417309  a1 2c 48 42 00                                mov     eax, off_42482C
0041730E  8b 0d 24 48 42 00                             mov     ecx, dword_424824
00417314  55                                            push    ebp; lpNumberOfBytesWritten
00417315  52                                            push    edx; nSize
00417316  8b 56 70                                      mov     edx, [esi+70h]
00417319  50                                            push    eax; lpBuffer
0041731A  51                                            push    ecx; lpBaseAddress
0041731B  52                                            push    edx; hProcess
0041731C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041731E  a1 00 48 42 00                                mov     eax, dword_424800
00417323  8b 0d 04 48 42 00                             mov     ecx, off_424804
00417329  8b 15 fc 47 42 00                             mov     edx, dword_4247FC
0041732F  55                                            push    ebp; lpNumberOfBytesWritten
00417330  50                                            push    eax; nSize
00417331  8b 46 70                                      mov     eax, [esi+70h]
00417334  51                                            push    ecx; lpBuffer
00417335  52                                            push    edx; lpBaseAddress
00417336  50                                            push    eax; hProcess
00417337  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417339  8b 0d d8 47 42 00                             mov     ecx, dword_4247D8
0041733F  8b 15 dc 47 42 00                             mov     edx, off_4247DC
00417345  a1 d4 47 42 00                                mov     eax, dword_4247D4
0041734A  55                                            push    ebp; lpNumberOfBytesWritten
0041734B  51                                            push    ecx; nSize
0041734C  8b 4e 70                                      mov     ecx, [esi+70h]
0041734F  52                                            push    edx; lpBuffer
00417350  50                                            push    eax; lpBaseAddress
00417351  51                                            push    ecx; hProcess
00417352  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417354  8b 15 b0 47 42 00                             mov     edx, dword_4247B0
0041735A  a1 b4 47 42 00                                mov     eax, off_4247B4
0041735F  8b 0d ac 47 42 00                             mov     ecx, dword_4247AC
00417365  55                                            push    ebp; lpNumberOfBytesWritten
00417366  52                                            push    edx; nSize
00417367  8b 56 70                                      mov     edx, [esi+70h]
0041736A  50                                            push    eax; lpBuffer
0041736B  51                                            push    ecx; lpBaseAddress
0041736C  52                                            push    edx; hProcess
0041736D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041736F  a1 88 47 42 00                                mov     eax, dword_424788
00417374  8b 0d 8c 47 42 00                             mov     ecx, off_42478C
0041737A  8b 15 84 47 42 00                             mov     edx, dword_424784
00417380  55                                            push    ebp; lpNumberOfBytesWritten
00417381  50                                            push    eax; nSize
00417382  8b 46 70                                      mov     eax, [esi+70h]
00417385  51                                            push    ecx; lpBuffer
00417386  52                                            push    edx; lpBaseAddress
00417387  50                                            push    eax; hProcess
00417388  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041738A  8b 0d 38 53 42 00                             mov     ecx, dword_425338
00417390  8b 15 3c 53 42 00                             mov     edx, off_42533C
00417396  a1 34 53 42 00                                mov     eax, dword_425334
0041739B  55                                            push    ebp; lpNumberOfBytesWritten
0041739C  51                                            push    ecx; nSize
0041739D  8b 4e 70                                      mov     ecx, [esi+70h]
004173A0  52                                            push    edx; lpBuffer
004173A1  50                                            push    eax; lpBaseAddress
004173A2  51                                            push    ecx; hProcess
004173A3  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004173A5  8b 15 f0 52 42 00                             mov     edx, dword_4252F0
004173AB  55                                            push    ebp; lpNumberOfBytesWritten
004173AC  a1 f4 52 42 00                                mov     eax, off_4252F4
004173B1  8b 0d ec 52 42 00                             mov     ecx, dword_4252EC
004173B7  52                                            push    edx; nSize
004173B8  8b 56 70                                      mov     edx, [esi+70h]
004173BB  50                                            push    eax; lpBuffer
004173BC  51                                            push    ecx; lpBaseAddress
004173BD  52                                            push    edx; hProcess
004173BE  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004173C0  a1 68 52 42 00                                mov     eax, dword_425268
004173C5  8b 0d 6c 52 42 00                             mov     ecx, off_42526C
004173CB  8b 15 64 52 42 00                             mov     edx, dword_425264
004173D1  55                                            push    ebp; lpNumberOfBytesWritten
004173D2  50                                            push    eax; nSize
004173D3  8b 46 70                                      mov     eax, [esi+70h]
004173D6  51                                            push    ecx; lpBuffer
004173D7  52                                            push    edx; lpBaseAddress
004173D8  50                                            push    eax; hProcess
004173D9  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004173DB  8b 0d 68 51 42 00                             mov     ecx, dword_425168
004173E1  8b 15 6c 51 42 00                             mov     edx, off_42516C
004173E7  a1 64 51 42 00                                mov     eax, dword_425164
004173EC  55                                            push    ebp; lpNumberOfBytesWritten
004173ED  51                                            push    ecx; nSize
004173EE  8b 4e 70                                      mov     ecx, [esi+70h]
004173F1  52                                            push    edx; lpBuffer
004173F2  50                                            push    eax; lpBaseAddress
004173F3  51                                            push    ecx; hProcess
004173F4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004173F6  8b 15 e8 4d 42 00                             mov     edx, dword_424DE8
004173FC  a1 ec 4d 42 00                                mov     eax, off_424DEC
00417401  8b 0d e4 4d 42 00                             mov     ecx, dword_424DE4
00417407  55                                            push    ebp; lpNumberOfBytesWritten
00417408  52                                            push    edx; nSize
00417409  8b 56 70                                      mov     edx, [esi+70h]
0041740C  50                                            push    eax; lpBuffer
0041740D  51                                            push    ecx; lpBaseAddress
0041740E  52                                            push    edx; hProcess
0041740F  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417411  a1 a0 55 42 00                                mov     eax, dword_4255A0
00417416  8b 0d a4 55 42 00                             mov     ecx, off_4255A4
0041741C  8b 15 9c 55 42 00                             mov     edx, dword_42559C
00417422  55                                            push    ebp; lpNumberOfBytesWritten
00417423  50                                            push    eax; nSize
00417424  8b 46 70                                      mov     eax, [esi+70h]
00417427  51                                            push    ecx; lpBuffer
00417428  52                                            push    edx; lpBaseAddress
00417429  50                                            push    eax; hProcess
0041742A  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041742C  8b 0d 80 4d 42 00                             mov     ecx, dword_424D80
00417432  8b 15 84 4d 42 00                             mov     edx, off_424D84
00417438  a1 7c 4d 42 00                                mov     eax, dword_424D7C
0041743D  55                                            push    ebp; lpNumberOfBytesWritten
0041743E  51                                            push    ecx; nSize
0041743F  8b 4e 70                                      mov     ecx, [esi+70h]
00417442  52                                            push    edx; lpBuffer
00417443  50                                            push    eax; lpBaseAddress
00417444  51                                            push    ecx; hProcess
00417445  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417447  8b 15 d0 4c 42 00                             mov     edx, dword_424CD0
0041744D  a1 d4 4c 42 00                                mov     eax, off_424CD4
00417452  8b 0d cc 4c 42 00                             mov     ecx, dword_424CCC
00417458  55                                            push    ebp; lpNumberOfBytesWritten
00417459  52                                            push    edx; nSize
0041745A  8b 56 70                                      mov     edx, [esi+70h]
0041745D  50                                            push    eax; lpBuffer
0041745E  51                                            push    ecx; lpBaseAddress
0041745F  52                                            push    edx; hProcess
00417460  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417462  a1 90 4c 42 00                                mov     eax, dword_424C90
00417467  8b 0d 94 4c 42 00                             mov     ecx, off_424C94
0041746D  8b 15 8c 4c 42 00                             mov     edx, dword_424C8C
00417473  55                                            push    ebp; lpNumberOfBytesWritten
00417474  50                                            push    eax; nSize
00417475  8b 46 70                                      mov     eax, [esi+70h]
00417478  51                                            push    ecx; lpBuffer
00417479  52                                            push    edx; lpBaseAddress
0041747A  50                                            push    eax; hProcess
0041747B  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041747D  8b 0d 40 4c 42 00                             mov     ecx, dword_424C40
00417483  55                                            push    ebp; lpNumberOfBytesWritten
00417484  51                                            push    ecx; nSize
00417485  8b 15 44 4c 42 00                             mov     edx, off_424C44
0041748B  a1 3c 4c 42 00                                mov     eax, dword_424C3C
00417490  8b 4e 70                                      mov     ecx, [esi+70h]
00417493  52                                            push    edx; lpBuffer
00417494  50                                            push    eax; lpBaseAddress
00417495  51                                            push    ecx; hProcess
00417496  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417498  8b 15 e0 46 42 00                             mov     edx, dword_4246E0
0041749E  a1 e4 46 42 00                                mov     eax, off_4246E4
004174A3  8b 0d dc 46 42 00                             mov     ecx, dword_4246DC
004174A9  55                                            push    ebp; lpNumberOfBytesWritten
004174AA  52                                            push    edx; nSize
004174AB  8b 56 70                                      mov     edx, [esi+70h]
004174AE  50                                            push    eax; lpBuffer
004174AF  51                                            push    ecx; lpBaseAddress
004174B0  52                                            push    edx; hProcess
004174B1  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004174B3  a1 40 4b 42 00                                mov     eax, dword_424B40
004174B8  8b 0d 44 4b 42 00                             mov     ecx, off_424B44
004174BE  8b 15 3c 4b 42 00                             mov     edx, dword_424B3C
004174C4  55                                            push    ebp; lpNumberOfBytesWritten
004174C5  50                                            push    eax; nSize
004174C6  8b 46 70                                      mov     eax, [esi+70h]
004174C9  51                                            push    ecx; lpBuffer
004174CA  52                                            push    edx; lpBaseAddress
004174CB  50                                            push    eax; hProcess
004174CC  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004174CE  8b 0d 98 46 42 00                             mov     ecx, dword_424698
004174D4  8b 15 9c 46 42 00                             mov     edx, off_42469C
004174DA  a1 94 46 42 00                                mov     eax, dword_424694
004174DF  55                                            push    ebp; lpNumberOfBytesWritten
004174E0  51                                            push    ecx; nSize
004174E1  8b 4e 70                                      mov     ecx, [esi+70h]
004174E4  52                                            push    edx; lpBuffer
004174E5  50                                            push    eax; lpBaseAddress
004174E6  51                                            push    ecx; hProcess
004174E7  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004174E9  8b 15 00 4b 42 00                             mov     edx, dword_424B00
004174EF  a1 04 4b 42 00                                mov     eax, off_424B04
004174F4  8b 0d fc 4a 42 00                             mov     ecx, dword_424AFC
004174FA  55                                            push    ebp; lpNumberOfBytesWritten
004174FB  52                                            push    edx; nSize
004174FC  8b 56 70                                      mov     edx, [esi+70h]
004174FF  50                                            push    eax; lpBuffer
00417500  51                                            push    ecx; lpBaseAddress
00417501  52                                            push    edx; hProcess
00417502  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417504  a1 b0 4a 42 00                                mov     eax, dword_424AB0
00417509  8b 0d b4 4a 42 00                             mov     ecx, off_424AB4
0041750F  8b 15 ac 4a 42 00                             mov     edx, dword_424AAC
00417515  55                                            push    ebp; lpNumberOfBytesWritten
00417516  50                                            push    eax; nSize
00417517  8b 46 70                                      mov     eax, [esi+70h]
0041751A  51                                            push    ecx; lpBuffer
0041751B  52                                            push    edx; lpBaseAddress
0041751C  50                                            push    eax; hProcess
0041751D  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041751F  8b 0d 68 35 42 00                             mov     ecx, dword_423568
00417525  8b 15 6c 35 42 00                             mov     edx, off_42356C
0041752B  a1 64 35 42 00                                mov     eax, dword_423564
00417530  55                                            push    ebp; lpNumberOfBytesWritten
00417531  51                                            push    ecx; nSize
00417532  8b 4e 70                                      mov     ecx, [esi+70h]
00417535  52                                            push    edx; lpBuffer
00417536  50                                            push    eax; lpBaseAddress
00417537  51                                            push    ecx; hProcess
00417538  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041753A  8b 15 08 35 42 00                             mov     edx, dword_423508
00417540  a1 0c 35 42 00                                mov     eax, off_42350C
00417545  8b 0d 04 35 42 00                             mov     ecx, dword_423504
0041754B  55                                            push    ebp; lpNumberOfBytesWritten
0041754C  52                                            push    edx; nSize
0041754D  8b 56 70                                      mov     edx, [esi+70h]
00417550  50                                            push    eax; lpBuffer
00417551  51                                            push    ecx; lpBaseAddress
00417552  52                                            push    edx; hProcess
00417553  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417555  a1 90 34 42 00                                mov     eax, dword_423490
0041755A  8b 0d 94 34 42 00                             mov     ecx, off_423494
00417560  55                                            push    ebp; lpNumberOfBytesWritten
00417561  50                                            push    eax; nSize
00417562  8b 15 8c 34 42 00                             mov     edx, dword_42348C
00417568  8b 46 70                                      mov     eax, [esi+70h]
0041756B  51                                            push    ecx; lpBuffer
0041756C  52                                            push    edx; lpBaseAddress
0041756D  50                                            push    eax; hProcess
0041756E  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417570  8b 0d 80 32 42 00                             mov     ecx, dword_423280
00417576  8b 15 84 32 42 00                             mov     edx, off_423284
0041757C  a1 7c 32 42 00                                mov     eax, dword_42327C
00417581  55                                            push    ebp; lpNumberOfBytesWritten
00417582  51                                            push    ecx; nSize
00417583  8b 4e 70                                      mov     ecx, [esi+70h]
00417586  52                                            push    edx; lpBuffer
00417587  50                                            push    eax; lpBaseAddress
00417588  51                                            push    ecx; hProcess
00417589  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041758B  8b 15 90 2d 42 00                             mov     edx, dword_422D90
00417591  a1 94 2d 42 00                                mov     eax, off_422D94
00417596  8b 0d 8c 2d 42 00                             mov     ecx, dword_422D8C
0041759C  55                                            push    ebp; lpNumberOfBytesWritten
0041759D  52                                            push    edx; nSize
0041759E  8b 56 70                                      mov     edx, [esi+70h]
004175A1  50                                            push    eax; lpBuffer
004175A2  51                                            push    ecx; lpBaseAddress
004175A3  52                                            push    edx; hProcess
004175A4  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004175A6  a1 60 3a 42 00                                mov     eax, dword_423A60
004175AB  8b 0d 64 3a 42 00                             mov     ecx, off_423A64
004175B1  8b 15 5c 3a 42 00                             mov     edx, dword_423A5C
004175B7  55                                            push    ebp; lpNumberOfBytesWritten
004175B8  50                                            push    eax; nSize
004175B9  8b 46 70                                      mov     eax, [esi+70h]
004175BC  51                                            push    ecx; lpBuffer
004175BD  52                                            push    edx; lpBaseAddress
004175BE  50                                            push    eax; hProcess
004175BF  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004175C1  8b 0d 28 3a 42 00                             mov     ecx, dword_423A28
004175C7  8b 15 2c 3a 42 00                             mov     edx, off_423A2C
004175CD  a1 24 3a 42 00                                mov     eax, dword_423A24
004175D2  55                                            push    ebp; lpNumberOfBytesWritten
004175D3  51                                            push    ecx; nSize
004175D4  8b 4e 70                                      mov     ecx, [esi+70h]
004175D7  52                                            push    edx; lpBuffer
004175D8  50                                            push    eax; lpBaseAddress
004175D9  51                                            push    ecx; hProcess
004175DA  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004175DC  8b 15 f0 39 42 00                             mov     edx, dword_4239F0
004175E2  a1 f4 39 42 00                                mov     eax, off_4239F4
004175E7  8b 0d ec 39 42 00                             mov     ecx, dword_4239EC
004175ED  55                                            push    ebp; lpNumberOfBytesWritten
004175EE  52                                            push    edx; nSize
004175EF  8b 56 70                                      mov     edx, [esi+70h]
004175F2  50                                            push    eax; lpBuffer
004175F3  51                                            push    ecx; lpBaseAddress
004175F4  52                                            push    edx; hProcess
004175F5  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004175F7  a1 48 43 42 00                                mov     eax, dword_424348
004175FC  8b 0d 4c 43 42 00                             mov     ecx, off_42434C
00417602  8b 15 44 43 42 00                             mov     edx, dword_424344
00417608  55                                            push    ebp; lpNumberOfBytesWritten
00417609  50                                            push    eax; nSize
0041760A  8b 46 70                                      mov     eax, [esi+70h]
0041760D  51                                            push    ecx; lpBuffer
0041760E  52                                            push    edx; lpBaseAddress
0041760F  50                                            push    eax; hProcess
00417610  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417612  8b 0d 48 4a 42 00                             mov     ecx, dword_424A48
00417618  8b 15 4c 4a 42 00                             mov     edx, off_424A4C
0041761E  a1 44 4a 42 00                                mov     eax, dword_424A44
00417623  55                                            push    ebp; lpNumberOfBytesWritten
00417624  51                                            push    ecx; nSize
00417625  8b 4e 70                                      mov     ecx, [esi+70h]
00417628  52                                            push    edx; lpBuffer
00417629  50                                            push    eax; lpBaseAddress
0041762A  51                                            push    ecx; hProcess
0041762B  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041762D  8b 15 50 49 42 00                             mov     edx, dword_424950
00417633  a1 54 49 42 00                                mov     eax, off_424954
00417638  55                                            push    ebp; lpNumberOfBytesWritten
00417639  52                                            push    edx; nSize
0041763A  50                                            push    eax; lpBuffer
0041763B  8b 0d 4c 49 42 00                             mov     ecx, dword_42494C
00417641  8b 56 70                                      mov     edx, [esi+70h]
00417644  51                                            push    ecx; lpBaseAddress
00417645  52                                            push    edx; hProcess
00417646  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417648  a1 68 48 42 00                                mov     eax, dword_424868
0041764D  8b 0d 6c 48 42 00                             mov     ecx, off_42486C
00417653  8b 15 64 48 42 00                             mov     edx, dword_424864
00417659  55                                            push    ebp; lpNumberOfBytesWritten
0041765A  50                                            push    eax; nSize
0041765B  8b 46 70                                      mov     eax, [esi+70h]
0041765E  51                                            push    ecx; lpBuffer
0041765F  52                                            push    edx; lpBaseAddress
00417660  50                                            push    eax; hProcess
00417661  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417663  8b 0d 48 47 42 00                             mov     ecx, dword_424748
00417669  8b 15 4c 47 42 00                             mov     edx, off_42474C
0041766F  a1 44 47 42 00                                mov     eax, dword_424744
00417674  55                                            push    ebp; lpNumberOfBytesWritten
00417675  51                                            push    ecx; nSize
00417676  8b 4e 70                                      mov     ecx, [esi+70h]
00417679  52                                            push    edx; lpBuffer
0041767A  50                                            push    eax; lpBaseAddress
0041767B  51                                            push    ecx; hProcess
0041767C  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
0041767E  8b 15 48 46 42 00                             mov     edx, dword_424648
00417684  a1 4c 46 42 00                                mov     eax, off_42464C
00417689  8b 0d 44 46 42 00                             mov     ecx, dword_424644
0041768F  55                                            push    ebp; lpNumberOfBytesWritten
00417690  52                                            push    edx; nSize
00417691  8b 56 70                                      mov     edx, [esi+70h]
00417694  50                                            push    eax; lpBuffer
00417695  51                                            push    ecx; lpBaseAddress
00417696  52                                            push    edx; hProcess
00417697  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
00417699  a1 f0 45 42 00                                mov     eax, dword_4245F0
0041769E  8b 0d f4 45 42 00                             mov     ecx, off_4245F4
004176A4  8b 15 ec 45 42 00                             mov     edx, dword_4245EC
004176AA  55                                            push    ebp; lpNumberOfBytesWritten
004176AB  50                                            push    eax; nSize
004176AC  8b 46 70                                      mov     eax, [esi+70h]
004176AF  51                                            push    ecx; lpBuffer
004176B0  52                                            push    edx; lpBaseAddress
004176B1  50                                            push    eax; hProcess
004176B2  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004176B4  8b 0d 78 3f 42 00                             mov     ecx, dword_423F78
004176BA  8b 15 7c 3f 42 00                             mov     edx, off_423F7C
004176C0  a1 74 3f 42 00                                mov     eax, dword_423F74
004176C5  55                                            push    ebp; lpNumberOfBytesWritten
004176C6  51                                            push    ecx; nSize
004176C7  8b 4e 70                                      mov     ecx, [esi+70h]
004176CA  52                                            push    edx; lpBuffer
004176CB  50                                            push    eax; lpBaseAddress
004176CC  51                                            push    ecx; hProcess
004176CD  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004176CF  8b 15 a8 45 42 00                             mov     edx, dword_4245A8
004176D5  a1 ac 45 42 00                                mov     eax, off_4245AC
004176DA  8b 0d a4 45 42 00                             mov     ecx, dword_4245A4
004176E0  55                                            push    ebp; lpNumberOfBytesWritten
004176E1  52                                            push    edx; nSize
004176E2  8b 56 70                                      mov     edx, [esi+70h]
004176E5  50                                            push    eax; lpBuffer
004176E6  51                                            push    ecx; lpBaseAddress
004176E7  52                                            push    edx; hProcess
004176E8  ff d7                                         call    edi ; WriteProcessMemory; KERNEL32
004176EA  a1 58 40 42 00                                mov     eax, dword_424058
004176EF  8b 0d 5c 40 42 00                             mov     ecx, off_42405C
004176F5  8b 15 54 40 42 00                             mov     edx, dword_424054
004176FB  55                                            push    ebp
004176FC  50                                            push    eax
004176FD  8b 46 70                                      mov     eax, [esi+70h]
00417700  51                                            push    ecx
00417701  52                                            push    edx
00417702  50                                            push    eax
00417704  d7 8b 0d d0 3f 42 00 8b 15 d4 3f 42 00 a1 cc 3f 42 00 55 51 52 8b 4e 70 50 51 ff d7 8b 15 18 3f 42 00 a1 1c 3f 42 00 8b 0d 14 3f 42 00 55 52 8b 56 70 50 51 52 ff d7 a1 a0 3e 42 00 8b 0d a4 3e 42 00 8b 15 9c 3e 42 00 55 50 8b 46 70 51 52 50 ff d7 8b 0d 28 42 42 00 8b 15 2c 42 42 00 a1 24 42 42 00 55 51 8b 4e 70 52 50 51 ff d7 8b 15 08 42 42 00 a1 0c 42 42 00 8b 0d 04 42 42 00 55 52 8b 56 70 50 51 52 ff d7 a1 58 45 42 00 8b 0d 5c 45 42 00 8b 15 54 45 42 00 55 50 8b 46 70 51 52 50 ff d7 8b 0d f8 44 42 00 8b 15 fc 44 42 00 a1 f4 44 42 00 55 51 8b 4e 70 52 50 51 ff d7 8b 15 18 41 42 00 a1 1c 41 42 00 8b 0d 14 41 42 00 55 52 8b 56 70 50 51 52 ff d7 a1 20 38 42 00 8b 0d 24 38 42 00 8b 15 1c 38 42 00 55 50 51 52 8b 46 70 50 ff d7 8b 0d b8 44 42 00 8b 15 bc 44 42 00 a1 b4 44 42 00 55 51 8b 4e 70 52 50 51 ff d7 8b 15 60 44 42 00 a1 64 44 42 00 8b 0d 5c 44 42 00 55 52 8b 56 70 50 51 52 ff d7 a1 08 43 42 00 8b 0d 0c 43 42 00 8b 15 04 43 42 00 55 50 8b 46 70 51 52 50 ff d7 8b 0d 90 42 42 00 8b 15 94 42 42 00 a1 8c 42 42 00 55 51 8b 4e 70 52 50 51 ff d7 8b 15 f0 40 42 00 a1 f4 40 42 00 8b 0d ec 40 42 00 55 52 8b 56 70 50 51 52 ff d7 a1 68 3e 42 00 8b 0d 6c 3e 42 00 8b 15 64 3e 42 00 55 50 8b 46 70 51 52 50 ff d7 8b 0d 00 3d 42 00 8b 15 04 3d 42 00 a1 fc 3c 42 00 55 51 8b 4e 70 52 50 51 ff d7 8b 15 b0 39 42 00 a1 b4 39 42 00 8b 0d ac 39 42 00 55 52 8b 56 70 50 51 52 ff d7 a1 08 39 42 00 8b 0d 0c 39 42 00 8b 15 04 39 42 00 55 50 8b 46 70 51 52 50 ff d7 8b 0d b8 38 42 00 8b 15 bc 38 42 00 a1 b4 38 42 00 55 51 8b 4e 70 52 50 51 ff d7 8b 15 80 38 42 00 a1 84 38 42 00 8b 0d 7c 38 42 00 55 52 8b 56 70 50 51 52 ff d7 a1 e0 37 42 00 8b 0d e4 37 42 00 8b 15 dc 37 42 00 55 50 8b 46 70 51 52 50 ff d7 8b 0d a0 37 42 00 8b 15 a4 37 42 00 a1 9c 37 42 00 55 51 8b 4e 70 52 50 51 ff d7 8b 15 40 37 42 00 a1 44 37 42 00 8b 0d 3c 37 42 00 55 52 8b 56 70 50 51 52 ff d7 a1 a0 33 42 00 8b 0d a4 33 42 00 8b 15 9c 33 42 00 55 50 8b 46 70 51 52 50 ff d7 8b 0d e8 3d 42 00 8b 15 ec 3d 42 00 a1 e4 3d 42 00 55 51 8b 4e 70 52 50 51 ff d7 bb 58 ce 42 00 8b 53 fc 8b 03 8b 4b f8 55 52 8b 56 70 50 51 52 ff d7 83 c3 0c 81 fb 70 ce 42 00 7c e3 a1 48 33 42 00 8b 0d 4c 33 42 00 8b 15 44 33 42 00 55 50 8b 46 70 51 52 50 ff d7 8b 0d 28 32 42 00 8b 15 2c 32 42 00 a1 24 32 42 00 55 51 8b 4e 70 52 50 51 ff d7 8b 15 a0 31 42 00 a1 a4 31 42 00 8b 0d 9c 31 42 00 55 52 8b 56 70 50 51 52 ff d7 a1 08 31 42 00 8b 0d 0c 31 42 00 8b 15 04 31 42 00 55 50 8b 46 70 51 52 50 ff d7 8b 0d 08 30 42 00 8b 15 0c 30 42 00 a1 04 30 42 00 55 51 8b 4e 70 52 50 51 ff d7 8b 15 c8 2f 42 00 a1 cc 2f 42 00 8b 0d c4 2f 42 00 55 52 8b 56 70 50 51 52 ff d7 a1 d8 2e 42 00 8b 0d dc 2e 42 00 8b 15 d4 2e 42 00 55 50 8b 46 70 51 52 50 ff d7 8b 0d 78 2f 42 00 8b 15 7c 2f 42 00 a1 74 2f 42 00 55 51 8b 4e 70 52 50 51 ff d7 55 8b 15 18 2f 42 00 a1 1c 2f 42 00 8b 0d 14 2f 42 00 52 8b 56 70 50 51 52 ff d7 a1 88 2e 42 00 8b 0d 8c 2e 42 00 8b 15 84 2e 42 00 55 50 8b 46 70 51 52 50 ff d7 8b 0d 58 2d  dd 0D00D8BD7h, 8B00423Fh, 423FD415h, 3FCCA100h, 51550042h
00417ADC  42                                            inc     edx
00417ADD  00 8b 15 5c 2d 42                             add     [ebx+422D5C15h], cl
00417AE3  00 a1 54 2d 42 00                             add     byte_422D54[ecx], ah
00417AE9  55                                            push    ebp
00417AEA  51                                            push    ecx
00417AEB  8b 4e 70                                      mov     ecx, [esi+70h]
00417AEE  52                                            push    edx
00417AEF  50                                            push    eax
00417AF0  51                                            push    ecx
00417AF1  ff d7                                         call    edi
00417AF3  8b 15 d0 2c 42 00                             mov     edx, dword_422CD0
00417AF9  a1 d4 2c 42 00                                mov     eax, off_422CD4
00417AFE  8b 0d cc 2c 42 00                             mov     ecx, dword_422CCC
00417B04  55                                            push    ebp
00417B05  52                                            push    edx
00417B06  8b 56 70                                      mov     edx, [esi+70h]
00417B09  50                                            push    eax
00417B0A  51                                            push    ecx
00417B0B  52                                            push    edx
00417B0C  ff d7                                         call    edi
00417B0E  a1 d0 2a 42 00                                mov     eax, dword_422AD0
00417B13  8b 0d d4 2a 42 00                             mov     ecx, off_422AD4
00417B19  8b 15 cc 2a 42 00                             mov     edx, dword_422ACC
00417B1F  55                                            push    ebp
00417B20  50                                            push    eax
00417B21  8b 46 70                                      mov     eax, [esi+70h]
00417B24  51                                            push    ecx
00417B25  52                                            push    edx
00417B26  50                                            push    eax
00417B27  ff d7                                         call    edi
00417B29  8b 0d 80 2a 42 00                             mov     ecx, dword_422A80
00417B2F  8b 15 84 2a 42 00                             mov     edx, off_422A84
00417B35  a1 7c 2a 42 00                                mov     eax, dword_422A7C
00417B3A  55                                            push    ebp
00417B3B  51                                            push    ecx
00417B3C  8b 4e 70                                      mov     ecx, [esi+70h]
00417B3F  52                                            push    edx
00417B40  50                                            push    eax
00417B41  51                                            push    ecx
00417B42  ff d7                                         call    edi
00417B44  8b 15 e0 29 42 00                             mov     edx, dword_4229E0
00417B4A  a1 e4 29 42 00                                mov     eax, off_4229E4
00417B4F  8b 0d dc 29 42 00                             mov     ecx, dword_4229DC
00417B55  55                                            push    ebp
00417B56  52                                            push    edx
00417B57  8b 56 70                                      mov     edx, [esi+70h]
00417B5A  50                                            push    eax
00417B5B  51                                            push    ecx
00417B5C  52                                            push    edx
00417B5D  ff d7                                         call    edi
00417B5F  a1 a8 29 42 00                                mov     eax, dword_4229A8
00417B64  8b 0d ac 29 42 00                             mov     ecx, off_4229AC
00417B6A  8b 15 a4 29 42 00                             mov     edx, dword_4229A4
00417B70  55                                            push    ebp
00417B71  50                                            push    eax
00417B72  8b 46 70                                      mov     eax, [esi+70h]
00417B75  51                                            push    ecx
00417B76  52                                            push    edx
00417B77  50                                            push    eax
00417B78  ff d7                                         call    edi
00417B7A  bb 1c 29 42 00                                mov     ebx, offset unk_42291C
00417B7F  8b 0b                                         mov     ecx, [ebx]
00417B81  8b 56 70                                      mov     edx, [esi+70h]
00417B84  55                                            push    ebp
00417B85  6a 04                                         push    4
00417B87  68 14 29 42 00                                push    offset unk_422914
00417B8C  51                                            push    ecx
00417B8D  52                                            push    edx
00417B8E  ff d7                                         call    edi
00417B90  83 c3 04                                      add     ebx, 4
00417B93  81 fb 48 29 42 00                             cmp     ebx, offset dword_422948
00417B99  7c e4                                         jl      short loc_417B7F
00417B9B  a1 68 29 42 00                                mov     eax, dword_422968
00417BA0  8b 0d 6c 29 42 00                             mov     ecx, off_42296C
00417BA6  8b 15 64 29 42 00                             mov     edx, dword_422964
00417BAC  55                                            push    ebp
00417BAD  50                                            push    eax
00417BAE  8b 46 70                                      mov     eax, [esi+70h]
00417BB1  51                                            push    ecx
00417BB2  52                                            push    edx
00417BB3  50                                            push    eax
00417BB4  ff d7                                         call    edi
00417BB6  8b 0d 08 29 42 00                             mov     ecx, dword_422908
00417BBC  8b 15 0c 29 42 00                             mov     edx, off_42290C
00417BC2  a1 04 29 42 00                                mov     eax, dword_422904
00417BC7  55                                            push    ebp
00417BC8  51                                            push    ecx
00417BC9  8b 4e 70                                      mov     ecx, [esi+70h]
00417BCC  52                                            push    edx
00417BCD  50                                            push    eax
00417BCE  51                                            push    ecx
00417BCF  ff d7                                         call    edi
00417BD1  8b 15 e0 28 42 00                             mov     edx, dword_4228E0
00417BD7  a1 e4 28 42 00                                mov     eax, off_4228E4
00417BDC  8b 0d dc 28 42 00                             mov     ecx, dword_4228DC
00417BE2  55                                            push    ebp
00417BE3  52                                            push    edx
00417BE4  8b 56 70                                      mov     edx, [esi+70h]
00417BE7  50                                            push    eax
00417BE8  51                                            push    ecx
00417BE9  52                                            push    edx
00417BEA  ff d7                                         call    edi
00417BEC  a1 48 28 42 00                                mov     eax, dword_422848
00417BF1  8b 0d 4c 28 42 00                             mov     ecx, off_42284C
00417BF7  8b 15 44 28 42 00                             mov     edx, dword_422844
00417BFD  55                                            push    ebp
00417BFE  50                                            push    eax
00417BFF  8b 46 70                                      mov     eax, [esi+70h]
00417C02  51                                            push    ecx
00417C03  52                                            push    edx
00417C04  50                                            push    eax
00417C05  ff d7                                         call    edi
00417C07  8b 0d 28 12 42 00                             mov     ecx, dword_421228
00417C0D  8b 15 2c 12 42 00                             mov     edx, off_42122C
00417C13  a1 24 12 42 00                                mov     eax, dword_421224
00417C18  55                                            push    ebp
00417C19  51                                            push    ecx
00417C1A  8b 4e 70                                      mov     ecx, [esi+70h]
00417C1D  52                                            push    edx
00417C1E  50                                            push    eax
00417C1F  51                                            push    ecx
00417C20  ff d7                                         call    edi
00417C22  8b 15 10 12 42 00                             mov     edx, dword_421210
00417C28  a1 14 12 42 00                                mov     eax, off_421214
00417C2D  8b 0d 0c 12 42 00                             mov     ecx, dword_42120C
00417C33  55                                            push    ebp
00417C34  52                                            push    edx
00417C35  8b 56 70                                      mov     edx, [esi+70h]
00417C38  50                                            push    eax
00417C39  51                                            push    ecx
00417C3A  52                                            push    edx
00417C3B  ff d7                                         call    edi
00417C3D  a1 f8 11 42 00                                mov     eax, dword_4211F8
00417C42  8b 0d fc 11 42 00                             mov     ecx, off_4211FC
00417C48  8b 15 f4 11 42 00                             mov     edx, dword_4211F4
00417C4E  55                                            push    ebp
00417C4F  50                                            push    eax
00417C50  8b 46 70                                      mov     eax, [esi+70h]
00417C53  51                                            push    ecx
00417C54  52                                            push    edx
00417C55  50                                            push    eax
00417C56  ff d7                                         call    edi
00417C58  8b 0d e0 11 42 00                             mov     ecx, dword_4211E0
00417C5E  8b 15 e4 11 42 00                             mov     edx, off_4211E4
00417C64  a1 dc 11 42 00                                mov     eax, dword_4211DC
00417C69  55                                            push    ebp
00417C6A  51                                            push    ecx
00417C6B  8b 4e 70                                      mov     ecx, [esi+70h]
00417C6E  52                                            push    edx
00417C6F  50                                            push    eax
00417C70  51                                            push    ecx
00417C71  ff d7                                         call    edi
00417C73  55                                            push    ebp
00417C74  8b 15 c8 11 42 00                             mov     edx, dword_4211C8
00417C7A  a1 cc 11 42 00                                mov     eax, off_4211CC
00417C7F  8b 0d c4 11 42 00                             mov     ecx, dword_4211C4
00417C85  52                                            push    edx
00417C86  8b 56 70                                      mov     edx, [esi+70h]
00417C89  50                                            push    eax
00417C8A  51                                            push    ecx
00417C8B  52                                            push    edx
00417C8C  ff d7                                         call    edi
00417C8E  a1 b0 11 42 00                                mov     eax, dword_4211B0
00417C93  8b 0d b4 11 42 00                             mov     ecx, off_4211B4
00417C99  8b 15 ac 11 42 00                             mov     edx, dword_4211AC
00417C9F  55                                            push    ebp
00417CA0  50                                            push    eax
00417CA1  8b 46 70                                      mov     eax, [esi+70h]
00417CA4  51                                            push    ecx
00417CA5  52                                            push    edx
00417CA6  50                                            push    eax
00417CA7  ff d7                                         call    edi
00417CA9  8b 0d 90 28 42 00                             mov     ecx, dword_422890
00417CAF  8b 15 94 28 42 00                             mov     edx, off_422894
00417CB5  a1 8c 28 42 00                                mov     eax, dword_42288C
00417CBA  55                                            push    ebp
00417CBB  51                                            push    ecx
00417CBC  8b 4e 70                                      mov     ecx, [esi+70h]
00417CBF  52                                            push    edx
00417CC0  50                                            push    eax
00417CC1  51                                            push    ecx
00417CC2  ff d7                                         call    edi
00417CC4  8b 15 b8 27 42 00                             mov     edx, dword_4227B8
00417CCA  a1 bc 27 42 00                                mov     eax, off_4227BC
00417CCF  8b 0d b4 27 42 00                             mov     ecx, dword_4227B4
00417CD5  55                                            push    ebp
00417CD6  52                                            push    edx
00417CD7  8b 56 70                                      mov     edx, [esi+70h]
00417CDA  50                                            push    eax
00417CDB  51                                            push    ecx
00417CDC  52                                            push    edx
00417CDD  ff d7                                         call    edi
00417CDF  a1 58 27 42 00                                mov     eax, dword_422758
00417CE4  8b 0d 5c 27 42 00                             mov     ecx, off_42275C
00417CEA  8b 15 54 27 42 00                             mov     edx, dword_422754
00417CF0  55                                            push    ebp
00417CF1  50                                            push    eax
00417CF2  8b 46 70                                      mov     eax, [esi+70h]
00417CF5  51                                            push    ecx
00417CF6  52                                            push    edx
00417CF7  50                                            push    eax
00417CF8  ff d7                                         call    edi
00417CFA  8b 0d 18 27 42 00                             mov     ecx, dword_422718
00417D00  8b 15 1c 27 42 00                             mov     edx, off_42271C
00417D06  a1 14 27 42 00                                mov     eax, dword_422714
00417D0B  55                                            push    ebp
00417D0C  51                                            push    ecx
00417D0D  8b 4e 70                                      mov     ecx, [esi+70h]
00417D10  52                                            push    edx
00417D11  50                                            push    eax
00417D12  51                                            push    ecx
00417D13  ff d7                                         call    edi
00417D15  8b 15 20 26 42 00                             mov     edx, dword_422620
00417D1B  a1 24 26 42 00                                mov     eax, off_422624
00417D20  8b 0d 1c 26 42 00                             mov     ecx, dword_42261C
00417D26  55                                            push    ebp
00417D27  52                                            push    edx
00417D28  8b 56 70                                      mov     edx, [esi+70h]
00417D2B  50                                            push    eax
00417D2C  51                                            push    ecx
00417D2D  52                                            push    edx
00417D2E  ff d7                                         call    edi
00417D30  a1 c8 25 42 00                                mov     eax, dword_4225C8
00417D35  8b 0d cc 25 42 00                             mov     ecx, off_4225CC
00417D3B  8b 15 c4 25 42 00                             mov     edx, dword_4225C4
00417D41  55                                            push    ebp
00417D42  50                                            push    eax
00417D43  8b 46 70                                      mov     eax, [esi+70h]
00417D46  51                                            push    ecx
00417D47  52                                            push    edx
00417D48  50                                            push    eax
00417D49  ff d7                                         call    edi
00417D4B  8b 0d 90 25 42 00                             mov     ecx, dword_422590
00417D51  55                                            push    ebp
00417D52  8b 15 94 25 42 00                             mov     edx, off_422594
00417D58  a1 8c 25 42 00                                mov     eax, dword_42258C
00417D5D  51                                            push    ecx
00417D5E  8b 4e 70                                      mov     ecx, [esi+70h]
00417D61  52                                            push    edx
00417D62  50                                            push    eax
00417D63  51                                            push    ecx
00417D64  ff d7                                         call    edi
00417D66  8b 15 48 25 42 00                             mov     edx, dword_422548
00417D6C  a1 4c 25 42 00                                mov     eax, off_42254C
00417D71  8b 0d 44 25 42 00                             mov     ecx, dword_422544
00417D77  55                                            push    ebp
00417D78  52                                            push    edx
00417D79  8b 56 70                                      mov     edx, [esi+70h]
00417D7C  50                                            push    eax
00417D7D  51                                            push    ecx
00417D7E  52                                            push    edx
00417D7F  ff d7                                         call    edi
00417D81  a1 f0 24 42 00                                mov     eax, dword_4224F0
00417D86  8b 0d f4 24 42 00                             mov     ecx, off_4224F4
00417D8C  8b 15 ec 24 42 00                             mov     edx, dword_4224EC
00417D92  55                                            push    ebp
00417D93  50                                            push    eax
00417D94  8b 46 70                                      mov     eax, [esi+70h]
00417D97  51                                            push    ecx
00417D98  52                                            push    edx
00417D99  50                                            push    eax
00417D9A  ff d7                                         call    edi
00417D9C  8b 0d 78 24 42 00                             mov     ecx, dword_422478
00417DA2  8b 15 7c 24 42 00                             mov     edx, off_42247C
00417DA8  a1 74 24 42 00                                mov     eax, dword_422474
00417DAD  55                                            push    ebp
00417DAE  51                                            push    ecx
00417DAF  8b 4e 70                                      mov     ecx, [esi+70h]
00417DB2  52                                            push    edx
00417DB3  50                                            push    eax
00417DB4  51                                            push    ecx
00417DB5  ff d7                                         call    edi
00417DB7  8b 15 d8 23 42 00                             mov     edx, dword_4223D8
00417DBD  a1 dc 23 42 00                                mov     eax, off_4223DC
00417DC2  8b 0d d4 23 42 00                             mov     ecx, dword_4223D4
00417DC8  55                                            push    ebp
00417DC9  52                                            push    edx
00417DCA  8b 56 70                                      mov     edx, [esi+70h]
00417DCD  50                                            push    eax
00417DCE  51                                            push    ecx
00417DCF  52                                            push    edx
00417DD0  ff d7                                         call    edi
00417DD2  a1 30 91 42 00                                mov     eax, dword_429130
00417DD7  8b 0d 34 91 42 00                             mov     ecx, off_429134
00417DDD  8b 15 2c 91 42 00                             mov     edx, dword_42912C
00417DE3  55                                            push    ebp
00417DE4  50                                            push    eax
00417DE5  8b 46 70                                      mov     eax, [esi+70h]
00417DE8  51                                            push    ecx
00417DE9  52                                            push    edx
00417DEA  50                                            push    eax
00417DEB  ff d7                                         call    edi
00417DED  8b 0d 38 1f 42 00                             mov     ecx, dword_421F38
00417DF3  8b 15 3c 1f 42 00                             mov     edx, off_421F3C
00417DF9  a1 34 1f 42 00                                mov     eax, dword_421F34
00417DFE  55                                            push    ebp
00417DFF  51                                            push    ecx
00417E00  8b 4e 70                                      mov     ecx, [esi+70h]
00417E03  52                                            push    edx
00417E04  50                                            push    eax
00417E05  51                                            push    ecx
00417E06  ff d7                                         call    edi
00417E08  8b 15 c0 22 42 00                             mov     edx, dword_4222C0
00417E0E  a1 c4 22 42 00                                mov     eax, off_4222C4
00417E13  8b 0d bc 22 42 00                             mov     ecx, dword_4222BC
00417E19  55                                            push    ebp
00417E1A  52                                            push    edx
00417E1B  8b 56 70                                      mov     edx, [esi+70h]
00417E1E  50                                            push    eax
00417E1F  51                                            push    ecx
00417E20  52                                            push    edx
00417E21  ff d7                                         call    edi
00417E23  a1 10 23 42 00                                mov     eax, dword_422310
00417E28  55                                            push    ebp
00417E29  50                                            push    eax
00417E2A  8b 0d 14 23 42 00                             mov     ecx, off_422314
00417E30  8b 15 0c 23 42 00                             mov     edx, dword_42230C
00417E36  8b 46 70                                      mov     eax, [esi+70h]
00417E39  51                                            push    ecx
00417E3A  52                                            push    edx
00417E3B  50                                            push    eax
00417E3C  ff d7                                         call    edi
00417E3E  8b 0d d0 1d 42 00                             mov     ecx, dword_421DD0
00417E44  8b 15 d4 1d 42 00                             mov     edx, off_421DD4
00417E4A  a1 cc 1d 42 00                                mov     eax, dword_421DCC
00417E4F  55                                            push    ebp
00417E50  51                                            push    ecx
00417E51  8b 4e 70                                      mov     ecx, [esi+70h]
00417E54  52                                            push    edx
00417E55  50                                            push    eax
00417E56  51                                            push    ecx
00417E57  ff d7                                         call    edi
00417E59  8b 15 78 1d 42 00                             mov     edx, dword_421D78
00417E5F  a1 7c 1d 42 00                                mov     eax, off_421D7C
00417E64  8b 0d 74 1d 42 00                             mov     ecx, dword_421D74
00417E6A  55                                            push    ebp
00417E6B  52                                            push    edx
00417E6C  8b 56 70                                      mov     edx, [esi+70h]
00417E6F  50                                            push    eax
00417E70  51                                            push    ecx
00417E71  52                                            push    edx
00417E72  ff d7                                         call    edi
00417E74  a1 18 22 42 00                                mov     eax, dword_422218
00417E79  8b 0d 1c 22 42 00                             mov     ecx, off_42221C
00417E7F  8b 15 14 22 42 00                             mov     edx, dword_422214
00417E85  55                                            push    ebp
00417E86  50                                            push    eax
00417E87  8b 46 70                                      mov     eax, [esi+70h]
00417E8A  51                                            push    ecx
00417E8B  52                                            push    edx
00417E8C  50                                            push    eax
00417E8D  ff d7                                         call    edi
00417E8F  8b 0d 68 21 42 00                             mov     ecx, dword_422168
00417E95  8b 15 6c 21 42 00                             mov     edx, off_42216C
00417E9B  a1 64 21 42 00                                mov     eax, dword_422164
00417EA0  55                                            push    ebp
00417EA1  51                                            push    ecx
00417EA2  8b 4e 70                                      mov     ecx, [esi+70h]
00417EA5  52                                            push    edx
00417EA6  50                                            push    eax
00417EA7  51                                            push    ecx
00417EA8  ff d7                                         call    edi
00417EAA  8b 15 d8 20 42 00                             mov     edx, dword_4220D8
00417EB0  a1 dc 20 42 00                                mov     eax, off_4220DC
00417EB5  8b 0d d4 20 42 00                             mov     ecx, dword_4220D4
00417EBB  55                                            push    ebp
00417EBC  52                                            push    edx
00417EBD  8b 56 70                                      mov     edx, [esi+70h]
00417EC0  50                                            push    eax
00417EC1  51                                            push    ecx
00417EC2  52                                            push    edx
00417EC3  ff d7                                         call    edi
00417EC5  a1 b0 20 42 00                                mov     eax, dword_4220B0
00417ECA  8b 0d b4 20 42 00                             mov     ecx, off_4220B4
00417ED0  8b 15 ac 20 42 00                             mov     edx, dword_4220AC
00417ED6  55                                            push    ebp
00417ED7  50                                            push    eax
00417ED8  8b 46 70                                      mov     eax, [esi+70h]
00417EDB  51                                            push    ecx
00417EDC  52                                            push    edx
00417EDD  50                                            push    eax
00417EDE  ff d7                                         call    edi
00417EE0  8b 0d 28 21 42 00                             mov     ecx, dword_422128
00417EE6  8b 15 2c 21 42 00                             mov     edx, off_42212C
00417EEC  a1 24 21 42 00                                mov     eax, dword_422124
00417EF1  55                                            push    ebp
00417EF2  51                                            push    ecx
00417EF3  8b 4e 70                                      mov     ecx, [esi+70h]
00417EF6  52                                            push    edx
00417EF7  50                                            push    eax
00417EF8  51                                            push    ecx
00417EF9  ff d7                                         call    edi
00417EFB  8b 15 88 20 42 00                             mov     edx, dword_422088
00417F01  a1 8c 20 42 00                                mov     eax, off_42208C
00417F06  55                                            push    ebp
00417F07  52                                            push    edx
00417F08  8b 0d 84 20 42 00                             mov     ecx, dword_422084
00417F0E  8b 56 70                                      mov     edx, [esi+70h]
00417F11  50                                            push    eax
00417F12  51                                            push    ecx
00417F13  52                                            push    edx
00417F14  ff d7                                         call    edi
00417F16  a1 60 20 42 00                                mov     eax, dword_422060
00417F1B  8b 0d 64 20 42 00                             mov     ecx, off_422064
00417F21  8b 15 5c 20 42 00                             mov     edx, dword_42205C
00417F27  55                                            push    ebp
00417F28  50                                            push    eax
00417F29  8b 46 70                                      mov     eax, [esi+70h]
00417F2C  51                                            push    ecx
00417F2D  52                                            push    edx
00417F2E  50                                            push    eax
00417F2F  ff d7                                         call    edi
00417F31  8b 0d 18 20 42 00                             mov     ecx, dword_422018
00417F37  8b 15 1c 20 42 00                             mov     edx, off_42201C
00417F3D  a1 14 20 42 00                                mov     eax, dword_422014
00417F42  55                                            push    ebp
00417F43  51                                            push    ecx
00417F44  8b 4e 70                                      mov     ecx, [esi+70h]
00417F47  52                                            push    edx
00417F48  50                                            push    eax
00417F49  51                                            push    ecx
00417F4A  ff d7                                         call    edi
00417F4C  8b 15 98 1f 42 00                             mov     edx, dword_421F98
00417F52  a1 9c 1f 42 00                                mov     eax, off_421F9C
00417F57  8b 0d 94 1f 42 00                             mov     ecx, dword_421F94
00417F5D  55                                            push    ebp
00417F5E  52                                            push    edx
00417F5F  8b 56 70                                      mov     edx, [esi+70h]
00417F62  50                                            push    eax
00417F63  51                                            push    ecx
00417F64  52                                            push    edx
00417F65  ff d7                                         call    edi
00417F67  a1 f8 1e 42 00                                mov     eax, dword_421EF8
00417F6C  8b 0d fc 1e 42 00                             mov     ecx, off_421EFC
00417F72  8b 15 f4 1e 42 00                             mov     edx, dword_421EF4
00417F78  55                                            push    ebp
00417F79  50                                            push    eax
00417F7A  8b 46 70                                      mov     eax, [esi+70h]
00417F7D  51                                            push    ecx
00417F7E  52                                            push    edx
00417F7F  50                                            push    eax
00417F80  ff d7                                         call    edi
00417F82  8b 0d a0 1e 42 00                             mov     ecx, dword_421EA0
00417F88  8b 15 a4 1e 42 00                             mov     edx, off_421EA4
00417F8E  a1 9c 1e 42 00                                mov     eax, dword_421E9C
00417F93  55                                            push    ebp
00417F94  51                                            push    ecx
00417F95  8b 4e 70                                      mov     ecx, [esi+70h]
00417F98  52                                            push    edx
00417F99  50                                            push    eax
00417F9A  51                                            push    ecx
00417F9B  ff d7                                         call    edi
00417F9D  8b 15 58 2b 42 00                             mov     edx, dword_422B58
00417FA3  a1 5c 2b 42 00                                mov     eax, off_422B5C
00417FA8  8b 0d 54 2b 42 00                             mov     ecx, dword_422B54
00417FAE  55                                            push    ebp
00417FAF  52                                            push    edx
00417FB0  8b 56 70                                      mov     edx, [esi+70h]
00417FB3  50                                            push    eax
00417FB4  51                                            push    ecx
00417FB5  52                                            push    edx
00417FB6  ff d7                                         call    edi
00417FB8  a1 48 1c 42 00                                mov     eax, dword_421C48
00417FBD  8b 0d 4c 1c 42 00                             mov     ecx, off_421C4C
00417FC3  8b 15 44 1c 42 00                             mov     edx, dword_421C44
00417FC9  55                                            push    ebp
00417FCA  50                                            push    eax
00417FCB  8b 46 70                                      mov     eax, [esi+70h]
00417FCE  51                                            push    ecx
00417FCF  52                                            push    edx
00417FD0  50                                            push    eax
00417FD1  ff d7                                         call    edi
00417FD3  8b 0d d8 1b 42 00                             mov     ecx, dword_421BD8
00417FD9  8b 15 dc 1b 42 00                             mov     edx, off_421BDC
00417FDF  55                                            push    ebp
00417FE0  51                                            push    ecx
00417FE1  52                                            push    edx
00417FE2  a1 d4 1b 42 00                                mov     eax, dword_421BD4
00417FE7  8b 4e 70                                      mov     ecx, [esi+70h]
00417FEA  50                                            push    eax
00417FEB  51                                            push    ecx
00417FEC  ff d7                                         call    edi
00417FEE  8b 15 80 1b 42 00                             mov     edx, dword_421B80
00417FF4  a1 84 1b 42 00                                mov     eax, off_421B84
00417FF9  8b 0d 7c 1b 42 00                             mov     ecx, dword_421B7C
00417FFF  55                                            push    ebp
00418000  52                                            push    edx
00418001  8b 56 70                                      mov     edx, [esi+70h]
00418004  50                                            push    eax
00418005  51                                            push    ecx
00418006  52                                            push    edx
00418007  ff d7                                         call    edi
00418009  a1 78 1a 42 00                                mov     eax, dword_421A78
0041800E  8b 0d 7c 1a 42 00                             mov     ecx, off_421A7C
00418014  8b 15 74 1a 42 00                             mov     edx, dword_421A74
0041801A  55                                            push    ebp
0041801B  50                                            push    eax
0041801C  8b 46 70                                      mov     eax, [esi+70h]
0041801F  51                                            push    ecx
00418020  52                                            push    edx
00418021  50                                            push    eax
00418022  ff d7                                         call    edi
00418024  8b 0d 28 1b 42 00                             mov     ecx, dword_421B28
0041802A  8b 15 2c 1b 42 00                             mov     edx, off_421B2C
00418030  a1 24 1b 42 00                                mov     eax, dword_421B24
00418035  55                                            push    ebp
00418036  51                                            push    ecx
00418037  8b 4e 70                                      mov     ecx, [esi+70h]
0041803A  52                                            push    edx
0041803B  50                                            push    eax
0041803C  51                                            push    ecx
0041803D  ff d7                                         call    edi
0041803F  8b 15 a0 18 42 00                             mov     edx, dword_4218A0
00418045  a1 a4 18 42 00                                mov     eax, off_4218A4
0041804A  8b 0d 9c 18 42 00                             mov     ecx, dword_42189C
00418050  55                                            push    ebp
00418051  52                                            push    edx
00418052  8b 56 70                                      mov     edx, [esi+70h]
00418055  50                                            push    eax
00418056  51                                            push    ecx
00418057  52                                            push    edx
00418058  ff d7                                         call    edi
0041805A  a1 78 18 42 00                                mov     eax, dword_421878
0041805F  8b 0d 7c 18 42 00                             mov     ecx, off_42187C
00418065  8b 15 74 18 42 00                             mov     edx, dword_421874
0041806B  55                                            push    ebp
0041806C  50                                            push    eax
0041806D  8b 46 70                                      mov     eax, [esi+70h]
00418070  51                                            push    ecx
00418071  52                                            push    edx
00418072  50                                            push    eax
00418073  ff d7                                         call    edi
00418075  8b 0d 50 17 42 00                             mov     ecx, dword_421750
0041807B  8b 15 54 17 42 00                             mov     edx, off_421754
00418081  a1 4c 17 42 00                                mov     eax, dword_42174C
00418086  55                                            push    ebp
00418087  51                                            push    ecx
00418088  8b 4e 70                                      mov     ecx, [esi+70h]
0041808B  52                                            push    edx
0041808C  50                                            push    eax
0041808D  51                                            push    ecx
0041808E  ff d7                                         call    edi
00418090  8b 15 78 16 42 00                             mov     edx, dword_421678
00418096  a1 7c 16 42 00                                mov     eax, off_42167C
0041809B  8b 0d 74 16 42 00                             mov     ecx, dword_421674
004180A1  55                                            push    ebp
004180A2  52                                            push    edx
004180A3  8b 56 70                                      mov     edx, [esi+70h]
004180A6  50                                            push    eax
004180A7  51                                            push    ecx
004180A8  52                                            push    edx
004180A9  ff d7                                         call    edi
004180AB  a1 38 16 42 00                                mov     eax, dword_421638
004180B0  8b 0d 3c 16 42 00                             mov     ecx, off_42163C
004180B6  8b 15 34 16 42 00                             mov     edx, dword_421634
004180BC  55                                            push    ebp
004180BD  50                                            push    eax
004180BE  51                                            push    ecx
004180BF  8b 46 70                                      mov     eax, [esi+70h]
004180C2  52                                            push    edx
004180C3  50                                            push    eax
004180C4  ff d7                                         call    edi
004180C6  8b 0d 00 16 42 00                             mov     ecx, dword_421600
004180CC  8b 15 04 16 42 00                             mov     edx, off_421604
004180D2  a1 fc 15 42 00                                mov     eax, dword_4215FC
004180D7  55                                            push    ebp
004180D8  51                                            push    ecx
004180D9  8b 4e 70                                      mov     ecx, [esi+70h]
004180DC  52                                            push    edx
004180DD  50                                            push    eax
004180DE  51                                            push    ecx
004180DF  ff d7                                         call    edi
004180E1  8b 15 90 10 42 00                             mov     edx, dword_421090
004180E7  a1 94 10 42 00                                mov     eax, off_421094
004180EC  8b 0d 8c 10 42 00                             mov     ecx, dword_42108C
004180F2  55                                            push    ebp
004180F3  52                                            push    edx
004180F4  8b 56 70                                      mov     edx, [esi+70h]
004180F7  50                                            push    eax
004180F8  51                                            push    ecx
004180F9  52                                            push    edx
004180FA  ff d7                                         call    edi
004180FC  a1 90 11 42 00                                mov     eax, dword_421190
00418101  8b 0d 94 11 42 00                             mov     ecx, off_421194
00418107  8b 15 8c 11 42 00                             mov     edx, dword_42118C
0041810D  55                                            push    ebp
0041810E  50                                            push    eax
0041810F  8b 46 70                                      mov     eax, [esi+70h]
00418112  51                                            push    ecx
00418113  52                                            push    edx
00418114  50                                            push    eax
00418115  ff d7                                         call    edi
00418117  8b 0d 78 11 42 00                             mov     ecx, dword_421178
0041811D  8b 15 7c 11 42 00                             mov     edx, off_42117C
00418123  a1 74 11 42 00                                mov     eax, dword_421174
00418128  55                                            push    ebp
00418129  51                                            push    ecx
0041812A  8b 4e 70                                      mov     ecx, [esi+70h]
0041812D  52                                            push    edx
0041812E  50                                            push    eax
0041812F  51                                            push    ecx
00418130  ff d7                                         call    edi
00418132  8b 15 e8 10 42 00                             mov     edx, dword_4210E8
00418138  a1 ec 10 42 00                                mov     eax, off_4210EC
0041813D  8b 0d e4 10 42 00                             mov     ecx, dword_4210E4
00418143  55                                            push    ebp
00418144  52                                            push    edx
00418145  8b 56 70                                      mov     edx, [esi+70h]
00418148  50                                            push    eax
00418149  51                                            push    ecx
0041814A  52                                            push    edx
0041814B  ff d7                                         call    edi
0041814D  a1 f0 0f 42 00                                mov     eax, dword_420FF0
00418152  8b 0d f4 0f 42 00                             mov     ecx, off_420FF4
00418158  8b 15 ec 0f 42 00                             mov     edx, dword_420FEC
0041815E  55                                            push    ebp
0041815F  50                                            push    eax
00418160  8b 46 70                                      mov     eax, [esi+70h]
00418163  51                                            push    ecx
00418164  52                                            push    edx
00418165  50                                            push    eax
00418166  ff d7                                         call    edi
00418168  8b 0d 80 0f 42 00                             mov     ecx, dword_420F80
0041816E  8b 15 84 0f 42 00                             mov     edx, off_420F84
00418174  a1 7c 0f 42 00                                mov     eax, dword_420F7C
00418179  55                                            push    ebp
0041817A  51                                            push    ecx
0041817B  8b 4e 70                                      mov     ecx, [esi+70h]
0041817E  52                                            push    edx
0041817F  50                                            push    eax
00418180  51                                            push    ecx
00418181  ff d7                                         call    edi
00418183  8b 15 c8 0e 42 00                             mov     edx, dword_420EC8
00418189  a1 cc 0e 42 00                                mov     eax, off_420ECC
0041818E  8b 0d c4 0e 42 00                             mov     ecx, dword_420EC4
00418194  55                                            push    ebp
00418195  52                                            push    edx
00418196  50                                            push    eax
00418197  51                                            push    ecx
00418198  8b 56 70                                      mov     edx, [esi+70h]
0041819B  52                                            push    edx
0041819C  ff d7                                         call    edi
0041819E  a1 78 0e 42 00                                mov     eax, dword_420E78
004181A3  8b 0d 7c 0e 42 00                             mov     ecx, off_420E7C
004181A9  8b 15 74 0e 42 00                             mov     edx, dword_420E74
004181AF  55                                            push    ebp
004181B0  50                                            push    eax
004181B1  8b 46 70                                      mov     eax, [esi+70h]
004181B4  51                                            push    ecx
004181B5  52                                            push    edx
004181B6  50                                            push    eax
004181B7  ff d7                                         call    edi
004181B9  8b 0d 08 0d 42 00                             mov     ecx, dword_420D08
004181BF  8b 15 0c 0d 42 00                             mov     edx, off_420D0C
004181C5  a1 04 0d 42 00                                mov     eax, dword_420D04
004181CA  55                                            push    ebp
004181CB  51                                            push    ecx
004181CC  8b 4e 70                                      mov     ecx, [esi+70h]
004181CF  52                                            push    edx
004181D0  50                                            push    eax
004181D1  51                                            push    ecx
004181D2  ff d7                                         call    edi
004181D4  8b 15 c0 4b 42 00                             mov     edx, dword_424BC0
004181DA  a1 c4 4b 42 00                                mov     eax, off_424BC4
004181DF  8b 0d bc 4b 42 00                             mov     ecx, dword_424BBC
004181E5  55                                            push    ebp
004181E6  52                                            push    edx
004181E7  8b 56 70                                      mov     edx, [esi+70h]
004181EA  50                                            push    eax
004181EB  51                                            push    ecx
004181EC  52                                            push    edx
004181ED  ff d7                                         call    edi
004181EF  a1 98 0c 42 00                                mov     eax, dword_420C98
004181F4  8b 0d 9c 0c 42 00                             mov     ecx, off_420C9C
004181FA  8b 15 94 0c 42 00                             mov     edx, dword_420C94
00418200  55                                            push    ebp
00418201  50                                            push    eax
00418202  8b 46 70                                      mov     eax, [esi+70h]
00418205  51                                            push    ecx
00418206  52                                            push    edx
00418207  50                                            push    eax
00418208  ff d7                                         call    edi
0041820A  8b 0d e0 0b 42 00                             mov     ecx, dword_420BE0
00418210  8b 15 e4 0b 42 00                             mov     edx, off_420BE4
00418216  a1 dc 0b 42 00                                mov     eax, dword_420BDC
0041821B  55                                            push    ebp
0041821C  51                                            push    ecx
0041821D  8b 4e 70                                      mov     ecx, [esi+70h]
00418220  52                                            push    edx
00418221  50                                            push    eax
00418222  51                                            push    ecx
00418223  ff d7                                         call    edi
00418225  8b 15 78 0b 42 00                             mov     edx, dword_420B78
0041822B  a1 7c 0b 42 00                                mov     eax, off_420B7C
00418230  8b 0d 74 0b 42 00                             mov     ecx, dword_420B74
00418236  55                                            push    ebp
00418237  52                                            push    edx
00418238  8b 56 70                                      mov     edx, [esi+70h]
0041823B  50                                            push    eax
0041823C  51                                            push    ecx
0041823D  52                                            push    edx
0041823E  ff d7                                         call    edi
00418240  a1 40 0a 42 00                                mov     eax, dword_420A40
00418245  8b 0d 44 0a 42 00                             mov     ecx, off_420A44
0041824B  8b 15 3c 0a 42 00                             mov     edx, dword_420A3C
00418251  55                                            push    ebp
00418252  50                                            push    eax
00418253  8b 46 70                                      mov     eax, [esi+70h]
00418256  51                                            push    ecx
00418257  52                                            push    edx
00418258  50                                            push    eax
00418259  ff d7                                         call    edi
0041825B  8b 0d 70 08 42 00                             mov     ecx, dword_420870
00418261  8b 15 74 08 42 00                             mov     edx, off_420874
00418267  a1 6c 08 42 00                                mov     eax, dword_42086C
0041826C  55                                            push    ebp
0041826D  51                                            push    ecx
0041826E  8b 4e 70                                      mov     ecx, [esi+70h]
00418271  52                                            push    edx
00418272  50                                            push    eax
00418273  51                                            push    ecx
00418274  ff d7                                         call    edi
00418276  8b 15 08 0b 42 00                             mov     edx, dword_420B08
0041827C  a1 0c 0b 42 00                                mov     eax, off_420B0C
00418281  8b 0d 04 0b 42 00                             mov     ecx, dword_420B04
00418287  55                                            push    ebp
00418288  52                                            push    edx
00418289  8b 56 70                                      mov     edx, [esi+70h]
0041828C  50                                            push    eax
0041828D  51                                            push    ecx
0041828E  52                                            push    edx
0041828F  ff d7                                         call    edi
00418291  a1 50 06 42 00                                mov     eax, dword_420650
00418296  8b 0d 54 06 42 00                             mov     ecx, off_420654
0041829C  8b 15 4c 06 42 00                             mov     edx, dword_42064C
004182A2  55                                            push    ebp
004182A3  50                                            push    eax
004182A4  8b 46 70                                      mov     eax, [esi+70h]
004182A7  51                                            push    ecx
004182A8  52                                            push    edx
004182A9  50                                            push    eax
004182AA  ff d7                                         call    edi
004182AC  8b 0d 40 05 42 00                             mov     ecx, dword_420540
004182B2  8b 15 44 05 42 00                             mov     edx, off_420544
004182B8  a1 3c 05 42 00                                mov     eax, dword_42053C
004182BD  55                                            push    ebp
004182BE  51                                            push    ecx
004182BF  8b 4e 70                                      mov     ecx, [esi+70h]
004182C2  52                                            push    edx
004182C3  50                                            push    eax
004182C4  51                                            push    ecx
004182C5  ff d7                                         call    edi
004182C7  8b 15 b0 05 42 00                             mov     edx, dword_4205B0
004182CD  a1 b4 05 42 00                                mov     eax, off_4205B4
004182D2  8b 0d ac 05 42 00                             mov     ecx, dword_4205AC
004182D8  55                                            push    ebp
004182D9  52                                            push    edx
004182DA  8b 56 70                                      mov     edx, [esi+70h]
004182DD  50                                            push    eax
004182DE  51                                            push    ecx
004182DF  52                                            push    edx
004182E0  ff d7                                         call    edi
004182E2  a1 a8 02 42 00                                mov     eax, dword_4202A8
004182E7  8b 0d ac 02 42 00                             mov     ecx, off_4202AC
004182ED  8b 15 a4 02 42 00                             mov     edx, dword_4202A4
004182F3  55                                            push    ebp
004182F4  50                                            push    eax
004182F5  8b 46 70                                      mov     eax, [esi+70h]
004182F8  51                                            push    ecx
004182F9  52                                            push    edx
004182FA  50                                            push    eax
004182FB  ff d7                                         call    edi
004182FD  8b 0d b0 04 42 00                             mov     ecx, dword_4204B0
00418303  8b 15 b4 04 42 00                             mov     edx, off_4204B4
00418309  a1 ac 04 42 00                                mov     eax, dword_4204AC
0041830E  55                                            push    ebp
0041830F  51                                            push    ecx
00418310  8b 4e 70                                      mov     ecx, [esi+70h]
00418313  52                                            push    edx
00418314  50                                            push    eax
00418315  51                                            push    ecx
00418316  ff d7                                         call    edi
00418318  8b 15 88 04 42 00                             mov     edx, dword_420488
0041831E  a1 8c 04 42 00                                mov     eax, off_42048C
00418323  8b 0d 84 04 42 00                             mov     ecx, dword_420484
00418329  55                                            push    ebp
0041832A  52                                            push    edx
0041832B  8b 56 70                                      mov     edx, [esi+70h]
0041832E  50                                            push    eax
0041832F  51                                            push    ecx
00418330  52                                            push    edx
00418331  ff d7                                         call    edi
00418333  a1 60 04 42 00                                mov     eax, dword_420460
00418338  8b 0d 64 04 42 00                             mov     ecx, off_420464
0041833E  8b 15 5c 04 42 00                             mov     edx, dword_42045C
00418344  55                                            push    ebp
00418345  50                                            push    eax
00418346  8b 46 70                                      mov     eax, [esi+70h]
00418349  51                                            push    ecx
0041834A  52                                            push    edx
0041834B  50                                            push    eax
0041834C  ff d7                                         call    edi
0041834E  8b 0d 38 04 42 00                             mov     ecx, dword_420438
00418354  8b 15 3c 04 42 00                             mov     edx, off_42043C
0041835A  a1 34 04 42 00                                mov     eax, dword_420434
0041835F  55                                            push    ebp
00418360  51                                            push    ecx
00418361  8b 4e 70                                      mov     ecx, [esi+70h]
00418364  52                                            push    edx
00418365  50                                            push    eax
00418366  51                                            push    ecx
00418367  ff d7                                         call    edi
00418369  8b 15 10 04 42 00                             mov     edx, dword_420410
0041836F  a1 14 04 42 00                                mov     eax, off_420414
00418374  8b 0d 0c 04 42 00                             mov     ecx, dword_42040C
0041837A  55                                            push    ebp
0041837B  52                                            push    edx
0041837C  8b 56 70                                      mov     edx, [esi+70h]
0041837F  50                                            push    eax
00418380  51                                            push    ecx
00418381  52                                            push    edx
00418382  ff d7                                         call    edi
00418384  a1 08 05 42 00                                mov     eax, dword_420508
00418389  8b 0d 0c 05 42 00                             mov     ecx, off_42050C
0041838F  8b 15 04 05 42 00                             mov     edx, dword_420504
00418395  55                                            push    ebp
00418396  50                                            push    eax
00418397  8b 46 70                                      mov     eax, [esi+70h]
0041839A  51                                            push    ecx
0041839B  52                                            push    edx
0041839C  50                                            push    eax
0041839D  ff d7                                         call    edi
0041839F  8b 0d a0 01 42 00                             mov     ecx, dword_4201A0
004183A5  8b 15 a4 01 42 00                             mov     edx, off_4201A4
004183AB  a1 9c 01 42 00                                mov     eax, dword_42019C
004183B0  55                                            push    ebp
004183B1  51                                            push    ecx
004183B2  8b 4e 70                                      mov     ecx, [esi+70h]
004183B5  52                                            push    edx
004183B6  50                                            push    eax
004183B7  51                                            push    ecx
004183B8  ff d7                                         call    edi
004183BA  8b 15 a0 06 42 00                             mov     edx, dword_4206A0
004183C0  a1 a4 06 42 00                                mov     eax, off_4206A4
004183C5  8b 0d 9c 06 42 00                             mov     ecx, dword_42069C
004183CB  55                                            push    ebp
004183CC  52                                            push    edx
004183CD  8b 56 70                                      mov     edx, [esi+70h]
004183D0  50                                            push    eax
004183D1  51                                            push    ecx
004183D2  52                                            push    edx
004183D3  ff d7                                         call    edi
004183D5  a1 d8 00 42 00                                mov     eax, dword_4200D8
004183DA  8b 0d dc 00 42 00                             mov     ecx, off_4200DC
004183E0  8b 15 d4 00 42 00                             mov     edx, dword_4200D4
004183E6  55                                            push    ebp
004183E7  50                                            push    eax
004183E8  8b 46 70                                      mov     eax, [esi+70h]
004183EB  51                                            push    ecx
004183EC  52                                            push    edx
004183ED  50                                            push    eax
004183EE  ff d7                                         call    edi
004183F0  8b 0d b0 00 42 00                             mov     ecx, dword_4200B0
004183F6  8b 15 b4 00 42 00                             mov     edx, off_4200B4
004183FC  a1 ac 00 42 00                                mov     eax, dword_4200AC
00418401  55                                            push    ebp
00418402  51                                            push    ecx
00418403  8b 4e 70                                      mov     ecx, [esi+70h]
00418406  52                                            push    edx
00418407  50                                            push    eax
00418408  51                                            push    ecx
00418409  ff d7                                         call    edi
0041840B  8b 15 00 00 42 00                             mov     edx, dword_420000
00418411  a1 04 00 42 00                                mov     eax, off_420004
00418416  8b 0d fc ff 41 00                             mov     ecx, dword_41FFFC
0041841C  55                                            push    ebp
0041841D  52                                            push    edx
0041841E  8b 56 70                                      mov     edx, [esi+70h]
00418421  50                                            push    eax
00418422  51                                            push    ecx
00418423  52                                            push    edx
00418424  ff d7                                         call    edi
00418426  a1 a8 ff 41 00                                mov     eax, dword_41FFA8
0041842B  8b 0d ac ff 41 00                             mov     ecx, off_41FFAC
00418431  8b 15 a4 ff 41 00                             mov     edx, dword_41FFA4
00418437  55                                            push    ebp
00418438  50                                            push    eax
00418439  8b 46 70                                      mov     eax, [esi+70h]
0041843C  51                                            push    ecx
0041843D  52                                            push    edx
0041843E  50                                            push    eax
0041843F  ff d7                                         call    edi
00418441  8b 0d 30 1d 42 00                             mov     ecx, dword_421D30
00418447  8b 15 34 1d 42 00                             mov     edx, off_421D34
0041844D  a1 2c 1d 42 00                                mov     eax, dword_421D2C
00418452  55                                            push    ebp
00418453  51                                            push    ecx
00418454  8b 4e 70                                      mov     ecx, [esi+70h]
00418457  52                                            push    edx
00418458  50                                            push    eax
00418459  51                                            push    ecx
0041845A  ff d7                                         call    edi
0041845C  8b 15 10 17 42 00                             mov     edx, dword_421710
00418462  a1 14 17 42 00                                mov     eax, off_421714
00418467  8b 0d 0c 17 42 00                             mov     ecx, dword_42170C
0041846D  55                                            push    ebp
0041846E  52                                            push    edx
0041846F  8b 56 70                                      mov     edx, [esi+70h]
00418472  50                                            push    eax
00418473  51                                            push    ecx
00418474  52                                            push    edx
00418475  ff d7                                         call    edi
00418477  a1 28 15 42 00                                mov     eax, dword_421528
0041847C  8b 0d 2c 15 42 00                             mov     ecx, off_42152C
00418482  8b 15 24 15 42 00                             mov     edx, dword_421524
00418488  55                                            push    ebp
00418489  50                                            push    eax
0041848A  8b 46 70                                      mov     eax, [esi+70h]
0041848D  51                                            push    ecx
0041848E  52                                            push    edx
0041848F  50                                            push    eax
00418490  ff d7                                         call    edi
00418492  8b 0d 10 ff 41 00                             mov     ecx, dword_41FF10
00418498  8b 15 14 ff 41 00                             mov     edx, off_41FF14
0041849E  a1 0c ff 41 00                                mov     eax, dword_41FF0C
004184A3  55                                            push    ebp
004184A4  51                                            push    ecx
004184A5  8b 4e 70                                      mov     ecx, [esi+70h]
004184A8  52                                            push    edx
004184A9  50                                            push    eax
004184AA  51                                            push    ecx
004184AB  ff d7                                         call    edi
004184AD  8b 15 80 fe 41 00                             mov     edx, dword_41FE80
004184B3  a1 84 fe 41 00                                mov     eax, off_41FE84
004184B8  8b 0d 7c fe 41 00                             mov     ecx, dword_41FE7C
004184BE  55                                            push    ebp
004184BF  52                                            push    edx
004184C0  8b 56 70                                      mov     edx, [esi+70h]
004184C3  50                                            push    eax
004184C4  51                                            push    ecx
004184C5  52                                            push    edx
004184C6  ff d7                                         call    edi
004184C8  a1 28 fe 41 00                                mov     eax, dword_41FE28
004184CD  8b 0d 2c fe 41 00                             mov     ecx, off_41FE2C
004184D3  8b 15 24 fe 41 00                             mov     edx, dword_41FE24
004184D9  55                                            push    ebp
004184DA  50                                            push    eax
004184DB  8b 46 70                                      mov     eax, [esi+70h]
004184DE  51                                            push    ecx
004184DF  52                                            push    edx
004184E0  50                                            push    eax
004184E1  ff d7                                         call    edi
004184E3  8b 0d d0 fd 41 00                             mov     ecx, dword_41FDD0
004184E9  8b 15 d4 fd 41 00                             mov     edx, off_41FDD4
004184EF  a1 cc fd 41 00                                mov     eax, dword_41FDCC
004184F4  55                                            push    ebp
004184F5  51                                            push    ecx
004184F6  8b 4e 70                                      mov     ecx, [esi+70h]
004184F9  52                                            push    edx
004184FA  50                                            push    eax
004184FB  51                                            push    ecx
004184FC  ff d7                                         call    edi
004184FE  55                                            push    ebp
004184FF  8b 15 28 fd 41 00                             mov     edx, dword_41FD28
00418505  a1 2c fd 41 00                                mov     eax, off_41FD2C
0041850A  8b 0d 24 fd 41 00                             mov     ecx, dword_41FD24
00418510  52                                            push    edx
00418511  8b 56 70                                      mov     edx, [esi+70h]
00418514  50                                            push    eax
00418515  51                                            push    ecx
00418516  52                                            push    edx
00418517  ff d7                                         call    edi
00418519  a1 a0 fc 41 00                                mov     eax, dword_41FCA0
0041851E  8b 0d a4 fc 41 00                             mov     ecx, off_41FCA4
00418524  8b 15 9c fc 41 00                             mov     edx, dword_41FC9C
0041852A  55                                            push    ebp
0041852B  50                                            push    eax
0041852C  8b 46 70                                      mov     eax, [esi+70h]
0041852F  51                                            push    ecx
00418530  52                                            push    edx
00418531  50                                            push    eax
00418532  ff d7                                         call    edi
00418534  8b 0d 60 fc 41 00                             mov     ecx, dword_41FC60
0041853A  8b 15 64 fc 41 00                             mov     edx, off_41FC64
00418540  a1 5c fc 41 00                                mov     eax, dword_41FC5C
00418545  55                                            push    ebp
00418546  51                                            push    ecx
00418547  8b 4e 70                                      mov     ecx, [esi+70h]
0041854A  52                                            push    edx
0041854B  50                                            push    eax
0041854C  51                                            push    ecx
0041854D  ff d7                                         call    edi
0041854F  8b 15 20 fc 41 00                             mov     edx, dword_41FC20
00418555  a1 24 fc 41 00                                mov     eax, off_41FC24
0041855A  8b 0d 1c fc 41 00                             mov     ecx, dword_41FC1C
00418560  55                                            push    ebp
00418561  52                                            push    edx
00418562  8b 56 70                                      mov     edx, [esi+70h]
00418565  50                                            push    eax
00418566  51                                            push    ecx
00418567  52                                            push    edx
00418568  ff d7                                         call    edi
0041856A  a1 e0 fb 41 00                                mov     eax, dword_41FBE0
0041856F  8b 0d e4 fb 41 00                             mov     ecx, off_41FBE4
00418575  8b 15 dc fb 41 00                             mov     edx, dword_41FBDC
0041857B  55                                            push    ebp
0041857C  50                                            push    eax
0041857D  8b 46 70                                      mov     eax, [esi+70h]
00418580  51                                            push    ecx
00418581  52                                            push    edx
00418582  50                                            push    eax
00418583  ff d7                                         call    edi
00418585  8b 0d b8 fb 41 00                             mov     ecx, dword_41FBB8
0041858B  8b 15 bc fb 41 00                             mov     edx, off_41FBBC
00418591  a1 b4 fb 41 00                                mov     eax, dword_41FBB4
00418596  55                                            push    ebp
00418597  51                                            push    ecx
00418598  8b 4e 70                                      mov     ecx, [esi+70h]
0041859B  52                                            push    edx
0041859C  50                                            push    eax
0041859D  51                                            push    ecx
0041859E  ff d7                                         call    edi
004185A0  8b 15 78 23 42 00                             mov     edx, dword_422378
004185A6  a1 7c 23 42 00                                mov     eax, off_42237C
004185AB  8b 0d 74 23 42 00                             mov     ecx, dword_422374
004185B1  55                                            push    ebp
004185B2  52                                            push    edx
004185B3  8b 56 70                                      mov     edx, [esi+70h]
004185B6  50                                            push    eax
004185B7  51                                            push    ecx
004185B8  52                                            push    edx
004185B9  ff d7                                         call    edi
004185BB  a1 a0 23 42 00                                mov     eax, dword_4223A0
004185C0  8b 0d a4 23 42 00                             mov     ecx, off_4223A4
004185C6  8b 15 9c 23 42 00                             mov     edx, dword_42239C
004185CC  55                                            push    ebp
004185CD  50                                            push    eax
004185CE  8b 46 70                                      mov     eax, [esi+70h]
004185D1  51                                            push    ecx
004185D2  52                                            push    edx
004185D3  50                                            push    eax
004185D4  ff d7                                         call    edi
004185D6  8b 0d 78 fb 41 00                             mov     ecx, dword_41FB78
004185DC  55                                            push    ebp
004185DD  8b 15 7c fb 41 00                             mov     edx, off_41FB7C
004185E3  a1 74 fb 41 00                                mov     eax, dword_41FB74
004185E8  51                                            push    ecx
004185E9  8b 4e 70                                      mov     ecx, [esi+70h]
004185EC  52                                            push    edx
004185ED  50                                            push    eax
004185EE  51                                            push    ecx
004185EF  ff d7                                         call    edi
004185F1  8b 15 70 f9 41 00                             mov     edx, dword_41F970
004185F7  a1 74 f9 41 00                                mov     eax, off_41F974
004185FC  8b 0d 6c f9 41 00                             mov     ecx, dword_41F96C
00418602  55                                            push    ebp
00418603  52                                            push    edx
00418604  8b 56 70                                      mov     edx, [esi+70h]
00418607  50                                            push    eax
00418608  51                                            push    ecx
00418609  52                                            push    edx
0041860A  ff d7                                         call    edi
0041860C  bb a8 fa 41 00                                mov     ebx, offset off_41FAA8
00418611  8b 43 fc                                      mov     eax, [ebx-4]
00418614  8b 0b                                         mov     ecx, [ebx]
00418616  8b 53 f8                                      mov     edx, [ebx-8]
00418619  55                                            push    ebp
0041861A  50                                            push    eax
0041861B  8b 46 70                                      mov     eax, [esi+70h]
0041861E  51                                            push    ecx
0041861F  52                                            push    edx
00418620  50                                            push    eax
00418621  ff d7                                         call    edi
00418623  83 c3 0c                                      add     ebx, 0Ch
00418626  81 fb e4 fa 41 00                             cmp     ebx, offset unk_41FAE4
0041862C  7c e3                                         jl      short loc_418611
0041862E  8b 0d f0 f9 41 00                             mov     ecx, dword_41F9F0
00418634  8b 15 f4 f9 41 00                             mov     edx, off_41F9F4
0041863A  a1 ec f9 41 00                                mov     eax, dword_41F9EC
0041863F  55                                            push    ebp
00418640  51                                            push    ecx
00418641  8b 4e 70                                      mov     ecx, [esi+70h]
00418644  52                                            push    edx
00418645  50                                            push    eax
00418646  51                                            push    ecx
00418647  ff d7                                         call    edi
00418649  8b 96 30 1d 00 00                             mov     edx, [esi+1D30h]
0041864F  8b 86 2c 1d 00 00                             mov     eax, [esi+1D2Ch]
00418655  8b 4e 70                                      mov     ecx, [esi+70h]
00418658  8b 1d 0c c0 41 00                             mov     ebx, ds:VirtualProtectEx; KERNEL32
0041865E  8d 7e 74                                      lea     edi, [esi+74h]
00418661  57                                            push    edi; lpflOldProtect
00418662  6a 20                                         push    20h ; ' '; flNewProtect
00418664  52                                            push    edx; dwSize
00418665  50                                            push    eax; lpAddress
00418666  51                                            push    ecx; hProcess
00418667  ff d3                                         call    ebx ; VirtualProtectEx; KERNEL32
00418669  8b 96 30 1d 00 00                             mov     edx, [esi+1D30h]
0041866F  8b 86 20 1d 00 00                             mov     eax, [esi+1D20h]
00418675  8b 4e 70                                      mov     ecx, [esi+70h]
00418678  57                                            push    edi; lpflOldProtect
00418679  6a 02                                         push    2; flNewProtect
0041867B  52                                            push    edx; dwSize
0041867C  50                                            push    eax; lpAddress
0041867D  51                                            push    ecx; hProcess
0041867E  ff d3                                         call    ebx ; VirtualProtectEx; KERNEL32
00418680  8b 96 30 1d 00 00                             mov     edx, [esi+1D30h]
00418686  8b 86 1c 1d 00 00                             mov     eax, [esi+1D1Ch]
0041868C  8b 4e 70                                      mov     ecx, [esi+70h]
0041868F  57                                            push    edi; lpflOldProtect
00418690  6a 02                                         push    2; flNewProtect
00418692  52                                            push    edx; dwSize
00418693  50                                            push    eax; lpAddress
00418694  51                                            push    ecx; hProcess
00418695  ff d3                                         call    ebx ; VirtualProtectEx; KERNEL32
00418697  8b 96 30 1d 00 00                             mov     edx, [esi+1D30h]
0041869D  8b 86 18 1d 00 00                             mov     eax, [esi+1D18h]
004186A3  8b 4e 70                                      mov     ecx, [esi+70h]
004186A6  57                                            push    edi; lpflOldProtect
004186A7  6a 20                                         push    20h ; ' '; flNewProtect
004186A9  52                                            push    edx; dwSize
004186AA  50                                            push    eax; lpAddress
004186AB  51                                            push    ecx; hProcess
004186AC  ff d3                                         call    ebx ; VirtualProtectEx; KERNEL32
004186AE  8b 96 34 1d 00 00                             mov     edx, [esi+1D34h]
004186B4  a1 50 00 42 00                                mov     eax, lpAddress
004186B9  0f af 96 30 1d 00 00                          imul    edx, [esi+1D30h]
004186C0  8b 4e 70                                      mov     ecx, [esi+70h]
004186C3  68 00 40 00 00                                push    4000h; dwFreeType
004186C8  52                                            push    edx; dwSize
004186C9  50                                            push    eax; lpAddress
004186CA  51                                            push    ecx; hProcess
004186CB  ff 15 18 c0 41 00                             call    ds:VirtualFreeEx; KERNEL32
004186D1  8b 56 70                                      mov     edx, [esi+70h]
004186D4  52                                            push    edx; hObject
004186D5  ff 15 10 c0 41 00                             call    ds:CloseHandle; KERNEL32
004186DB  89 6e 70                                      mov     [esi+70h], ebp
004186DE  5f                                            pop     edi
004186DF  89 6e 6c                                      mov     [esi+6Ch], ebp
004186E2  5b                                            pop     ebx
004186E3  5e                                            pop     esi
004186E4  5d                                            pop     ebp
004186E5  59                                            pop     ecx
004186E6  c3                                            retn
004186E7  89 6e 6c                                      mov     [esi+6Ch], ebp
004186EA  89 6e 70                                      mov     [esi+70h], ebp
004186ED  5e                                            pop     esi
004186EE  5d                                            pop     ebp
004186EF  59                                            pop     ecx
004186F0  c3                                            retn
004186F1  90 90 90 90 90 90 90 90 90 90 90 90 90 90 90  align 10h
