00402740  53                                            push    ebx
00402741  56                                            push    esi
00402742  8b 74 24 0c                                   mov     esi, [esp+8+arg_0]
00402746  57                                            push    edi
00402747  8b f9                                         mov     edi, ecx
00402749  8d 47 60                                      lea     eax, [edi+60h]
0040274C  50                                            push    eax; struct CWnd *
0040274D  68 72 04 00 00                                push    472h; int
00402752  56                                            push    esi; struct CDataExchange *
00402753  e8 a8 7e 01 00                                call    ?DDX_Control@@YGXPAVCDataExchange@@HAAVCWnd@@@Z; DDX_Control(CDataExchange *,int,CWnd &)
00402758  8d 9f a0 00 00 00                             lea     ebx, [edi+0A0h]
0040275E  53                                            push    ebx; unsigned int *
0040275F  68 74 04 00 00                                push    474h; int
00402764  56                                            push    esi; struct CDataExchange *
00402765  e8 90 7e 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
0040276A  8b 0b                                         mov     ecx, [ebx]
0040276C  6a 1e                                         push    1Eh; unsigned int
0040276E  6a 00                                         push    0; unsigned int
00402770  51                                            push    ecx; unsigned int
00402771  56                                            push    esi; struct CDataExchange *
00402772  e8 7d 7e 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00402777  8d 9f a4 00 00 00                             lea     ebx, [edi+0A4h]
0040277D  53                                            push    ebx; unsigned int *
0040277E  68 75 04 00 00                                push    475h; int
00402783  56                                            push    esi; struct CDataExchange *
00402784  e8 71 7e 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00402789  8b 13                                         mov     edx, [ebx]
0040278B  68 c4 09 00 00                                push    9C4h; unsigned int
00402790  6a 00                                         push    0; unsigned int
00402792  52                                            push    edx; unsigned int
00402793  56                                            push    esi; struct CDataExchange *
00402794  e8 5b 7e 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00402799  81 c7 a8 00 00 00                             add     edi, 0A8h
0040279F  57                                            push    edi; unsigned int *
004027A0  68 73 04 00 00                                push    473h; int
004027A5  56                                            push    esi; struct CDataExchange *
004027A6  e8 4f 7e 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
004027AB  8b 07                                         mov     eax, [edi]
004027AD  6a 64                                         push    64h ; 'd'; unsigned int
004027AF  6a 00                                         push    0; unsigned int
004027B1  50                                            push    eax; unsigned int
004027B2  56                                            push    esi; struct CDataExchange *
004027B3  e8 3c 7e 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
004027B8  5f                                            pop     edi
004027B9  5e                                            pop     esi
004027BA  5b                                            pop     ebx
004027BB  c2 04 00                                      retn    4
