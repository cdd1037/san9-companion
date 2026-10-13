00401120  53                                            push    ebx
00401121  56                                            push    esi
00401122  8b 74 24 0c                                   mov     esi, [esp+8+arg_0]
00401126  57                                            push    edi
00401127  8b f9                                         mov     edi, ecx
00401129  8d 47 60                                      lea     eax, [edi+60h]
0040112C  50                                            push    eax; struct CWnd *
0040112D  68 7d 04 00 00                                push    47Dh; int
00401132  56                                            push    esi; struct CDataExchange *
00401133  e8 c8 94 01 00                                call    ?DDX_Control@@YGXPAVCDataExchange@@HAAVCWnd@@@Z; DDX_Control(CDataExchange *,int,CWnd &)
00401138  8d 9f a0 00 00 00                             lea     ebx, [edi+0A0h]
0040113E  53                                            push    ebx; unsigned int *
0040113F  68 80 04 00 00                                push    480h; int
00401144  56                                            push    esi; struct CDataExchange *
00401145  e8 b0 94 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
0040114A  8b 0b                                         mov     ecx, [ebx]
0040114C  6a 05                                         push    5; unsigned int
0040114E  6a 01                                         push    1; unsigned int
00401150  51                                            push    ecx; unsigned int
00401151  56                                            push    esi; struct CDataExchange *
00401152  e8 9d 94 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401157  8d 9f a4 00 00 00                             lea     ebx, [edi+0A4h]
0040115D  53                                            push    ebx; unsigned int *
0040115E  68 7a 04 00 00                                push    47Ah; int
00401163  56                                            push    esi; struct CDataExchange *
00401164  e8 91 94 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401169  8b 13                                         mov     edx, [ebx]
0040116B  6a 1e                                         push    1Eh; unsigned int
0040116D  6a 05                                         push    5; unsigned int
0040116F  52                                            push    edx; unsigned int
00401170  56                                            push    esi; struct CDataExchange *
00401171  e8 7e 94 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401176  8d 9f a8 00 00 00                             lea     ebx, [edi+0A8h]
0040117C  53                                            push    ebx; unsigned int *
0040117D  68 7c 04 00 00                                push    47Ch; int
00401182  56                                            push    esi; struct CDataExchange *
00401183  e8 72 94 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401188  8b 03                                         mov     eax, [ebx]
0040118A  68 10 27 00 00                                push    2710h; unsigned int
0040118F  6a 00                                         push    0; unsigned int
00401191  50                                            push    eax; unsigned int
00401192  56                                            push    esi; struct CDataExchange *
00401193  e8 5c 94 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401198  8d 9f ac 00 00 00                             lea     ebx, [edi+0ACh]
0040119E  53                                            push    ebx; unsigned int *
0040119F  68 7b 04 00 00                                push    47Bh; int
004011A4  56                                            push    esi; struct CDataExchange *
004011A5  e8 50 94 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
004011AA  8b 0b                                         mov     ecx, [ebx]
004011AC  6a 32                                         push    32h ; '2'; unsigned int
004011AE  6a 05                                         push    5; unsigned int
004011B0  51                                            push    ecx; unsigned int
004011B1  56                                            push    esi; struct CDataExchange *
004011B2  e8 3d 94 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
004011B7  8d 9f b0 00 00 00                             lea     ebx, [edi+0B0h]
004011BD  53                                            push    ebx; unsigned int *
004011BE  68 79 04 00 00                                push    479h; int
004011C3  56                                            push    esi; struct CDataExchange *
004011C4  e8 31 94 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
004011C9  8b 13                                         mov     edx, [ebx]
004011CB  6a 3c                                         push    3Ch ; '<'; unsigned int
004011CD  6a 05                                         push    5; unsigned int
004011CF  52                                            push    edx; unsigned int
004011D0  56                                            push    esi; struct CDataExchange *
004011D1  e8 1e 94 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
004011D6  8d 9f b4 00 00 00                             lea     ebx, [edi+0B4h]
004011DC  53                                            push    ebx; unsigned int *
004011DD  68 78 04 00 00                                push    478h; int
004011E2  56                                            push    esi; struct CDataExchange *
004011E3  e8 12 94 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
004011E8  8b 03                                         mov     eax, [ebx]
004011EA  6a 32                                         push    32h ; '2'; unsigned int
004011EC  6a 05                                         push    5; unsigned int
004011EE  50                                            push    eax; unsigned int
004011EF  56                                            push    esi; struct CDataExchange *
004011F0  e8 ff 93 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
004011F5  8d 9f b8 00 00 00                             lea     ebx, [edi+0B8h]
004011FB  53                                            push    ebx; unsigned int *
004011FC  68 77 04 00 00                                push    477h; int
00401201  56                                            push    esi; struct CDataExchange *
00401202  e8 f3 93 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401207  8b 0b                                         mov     ecx, [ebx]
00401209  6a 32                                         push    32h ; '2'; unsigned int
0040120B  6a 05                                         push    5; unsigned int
0040120D  51                                            push    ecx; unsigned int
0040120E  56                                            push    esi; struct CDataExchange *
0040120F  e8 e0 93 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401214  8d 9f bc 00 00 00                             lea     ebx, [edi+0BCh]
0040121A  53                                            push    ebx; unsigned int *
0040121B  68 7f 04 00 00                                push    47Fh; int
00401220  56                                            push    esi; struct CDataExchange *
00401221  e8 d4 93 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401226  8b 13                                         mov     edx, [ebx]
00401228  6a 08                                         push    8; unsigned int
0040122A  6a 01                                         push    1; unsigned int
0040122C  52                                            push    edx; unsigned int
0040122D  56                                            push    esi; struct CDataExchange *
0040122E  e8 c1 93 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401233  81 c7 c0 00 00 00                             add     edi, 0C0h
00401239  57                                            push    edi; unsigned int *
0040123A  68 7e 04 00 00                                push    47Eh; int
0040123F  56                                            push    esi; struct CDataExchange *
00401240  e8 b5 93 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401245  8b 07                                         mov     eax, [edi]
00401247  6a 0a                                         push    0Ah; unsigned int
00401249  6a 00                                         push    0; unsigned int
0040124B  50                                            push    eax; unsigned int
0040124C  56                                            push    esi; struct CDataExchange *
0040124D  e8 a2 93 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401252  5f                                            pop     edi
00401253  5e                                            pop     esi
00401254  5b                                            pop     ebx
00401255  c2 04 00                                      retn    4
