00401BC0  53                                            push    ebx
00401BC1  56                                            push    esi
00401BC2  8b 74 24 0c                                   mov     esi, [esp+8+arg_0]
00401BC6  57                                            push    edi
00401BC7  8b f9                                         mov     edi, ecx
00401BC9  8d 47 60                                      lea     eax, [edi+60h]
00401BCC  50                                            push    eax; struct CWnd *
00401BCD  68 61 04 00 00                                push    461h; int
00401BD2  56                                            push    esi; struct CDataExchange *
00401BD3  e8 28 8a 01 00                                call    ?DDX_Control@@YGXPAVCDataExchange@@HAAVCWnd@@@Z; DDX_Control(CDataExchange *,int,CWnd &)
00401BD8  8d 8f a0 00 00 00                             lea     ecx, [edi+0A0h]
00401BDE  51                                            push    ecx; int *
00401BDF  68 62 04 00 00                                push    462h; int
00401BE4  56                                            push    esi; struct CDataExchange *
00401BE5  e8 9a 8a 01 00                                call    ?DDX_CBIndex@@YGXPAVCDataExchange@@HAAH@Z; DDX_CBIndex(CDataExchange *,int,int &)
00401BEA  8d 97 a4 00 00 00                             lea     edx, [edi+0A4h]
00401BF0  52                                            push    edx; int *
00401BF1  68 64 04 00 00                                push    464h; int
00401BF6  56                                            push    esi; struct CDataExchange *
00401BF7  e8 82 8a 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00401BFC  8d 87 a8 00 00 00                             lea     eax, [edi+0A8h]
00401C02  50                                            push    eax; int *
00401C03  68 63 04 00 00                                push    463h; int
00401C08  56                                            push    esi; struct CDataExchange *
00401C09  e8 70 8a 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00401C0E  8d 8f ac 00 00 00                             lea     ecx, [edi+0ACh]
00401C14  51                                            push    ecx; int *
00401C15  68 6a 04 00 00                                push    46Ah; int
00401C1A  56                                            push    esi; struct CDataExchange *
00401C1B  e8 5e 8a 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00401C20  8d 9f b0 00 00 00                             lea     ebx, [edi+0B0h]
00401C26  53                                            push    ebx; unsigned int *
00401C27  68 66 04 00 00                                push    466h; int
00401C2C  56                                            push    esi; struct CDataExchange *
00401C2D  e8 c8 89 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401C32  8b 13                                         mov     edx, [ebx]
00401C34  6a 14                                         push    14h; unsigned int
00401C36  6a 06                                         push    6; unsigned int
00401C38  52                                            push    edx; unsigned int
00401C39  56                                            push    esi; struct CDataExchange *
00401C3A  e8 b5 89 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401C3F  8d 9f b4 00 00 00                             lea     ebx, [edi+0B4h]
00401C45  53                                            push    ebx; unsigned int *
00401C46  68 68 04 00 00                                push    468h; int
00401C4B  56                                            push    esi; struct CDataExchange *
00401C4C  e8 a9 89 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401C51  8b 03                                         mov     eax, [ebx]
00401C53  6a 0f                                         push    0Fh; unsigned int
00401C55  6a 04                                         push    4; unsigned int
00401C57  50                                            push    eax; unsigned int
00401C58  56                                            push    esi; struct CDataExchange *
00401C59  e8 96 89 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401C5E  8d 9f b8 00 00 00                             lea     ebx, [edi+0B8h]
00401C64  53                                            push    ebx; unsigned int *
00401C65  68 67 04 00 00                                push    467h; int
00401C6A  56                                            push    esi; struct CDataExchange *
00401C6B  e8 8a 89 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401C70  8b 0b                                         mov     ecx, [ebx]
00401C72  6a 0f                                         push    0Fh; unsigned int
00401C74  6a 04                                         push    4; unsigned int
00401C76  51                                            push    ecx; unsigned int
00401C77  56                                            push    esi; struct CDataExchange *
00401C78  e8 77 89 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401C7D  8d 9f bc 00 00 00                             lea     ebx, [edi+0BCh]
00401C83  53                                            push    ebx; unsigned int *
00401C84  68 69 04 00 00                                push    469h; int
00401C89  56                                            push    esi; struct CDataExchange *
00401C8A  e8 6b 89 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401C8F  8b 13                                         mov     edx, [ebx]
00401C91  6a 0a                                         push    0Ah; unsigned int
00401C93  6a 04                                         push    4; unsigned int
00401C95  52                                            push    edx; unsigned int
00401C96  56                                            push    esi; struct CDataExchange *
00401C97  e8 58 89 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401C9C  8d 9f c0 00 00 00                             lea     ebx, [edi+0C0h]
00401CA2  53                                            push    ebx; unsigned int *
00401CA3  68 65 04 00 00                                push    465h; int
00401CA8  56                                            push    esi; struct CDataExchange *
00401CA9  e8 4c 89 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401CAE  6a 32                                         push    32h ; '2'; unsigned int
00401CB0  6a 0a                                         push    0Ah; unsigned int
00401CB2  8b 03                                         mov     eax, [ebx]
00401CB4  50                                            push    eax; unsigned int
00401CB5  56                                            push    esi; struct CDataExchange *
00401CB6  e8 39 89 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401CBB  8d 8f c4 00 00 00                             lea     ecx, [edi+0C4h]
00401CC1  51                                            push    ecx; int *
00401CC2  68 6d 04 00 00                                push    46Dh; int
00401CC7  56                                            push    esi; struct CDataExchange *
00401CC8  e8 b1 89 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00401CCD  8d 9f c8 00 00 00                             lea     ebx, [edi+0C8h]
00401CD3  53                                            push    ebx; unsigned int *
00401CD4  68 6e 04 00 00                                push    46Eh; int
00401CD9  56                                            push    esi; struct CDataExchange *
00401CDA  e8 1b 89 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401CDF  8b 13                                         mov     edx, [ebx]
00401CE1  6a 32                                         push    32h ; '2'; unsigned int
00401CE3  6a 00                                         push    0; unsigned int
00401CE5  52                                            push    edx; unsigned int
00401CE6  56                                            push    esi; struct CDataExchange *
00401CE7  e8 08 89 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401CEC  8d 9f cc 00 00 00                             lea     ebx, [edi+0CCh]
00401CF2  53                                            push    ebx; unsigned int *
00401CF3  68 6f 04 00 00                                push    46Fh; int
00401CF8  56                                            push    esi; struct CDataExchange *
00401CF9  e8 fc 88 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401CFE  8b 03                                         mov     eax, [ebx]
00401D00  6a 32                                         push    32h ; '2'; unsigned int
00401D02  6a 00                                         push    0; unsigned int
00401D04  50                                            push    eax; unsigned int
00401D05  56                                            push    esi; struct CDataExchange *
00401D06  e8 e9 88 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401D0B  8d 9f d0 00 00 00                             lea     ebx, [edi+0D0h]
00401D11  53                                            push    ebx; unsigned int *
00401D12  68 70 04 00 00                                push    470h; int
00401D17  56                                            push    esi; struct CDataExchange *
00401D18  e8 dd 88 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401D1D  8b 0b                                         mov     ecx, [ebx]
00401D1F  6a 32                                         push    32h ; '2'; unsigned int
00401D21  6a 00                                         push    0; unsigned int
00401D23  51                                            push    ecx; unsigned int
00401D24  56                                            push    esi; struct CDataExchange *
00401D25  e8 ca 88 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401D2A  8d 9f d4 00 00 00                             lea     ebx, [edi+0D4h]
00401D30  53                                            push    ebx; unsigned int *
00401D31  68 71 04 00 00                                push    471h; int
00401D36  56                                            push    esi; struct CDataExchange *
00401D37  e8 be 88 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401D3C  8b 13                                         mov     edx, [ebx]
00401D3E  6a 32                                         push    32h ; '2'; unsigned int
00401D40  6a 00                                         push    0; unsigned int
00401D42  52                                            push    edx; unsigned int
00401D43  56                                            push    esi; struct CDataExchange *
00401D44  e8 ab 88 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401D49  8d 9f d8 00 00 00                             lea     ebx, [edi+0D8h]
00401D4F  53                                            push    ebx; unsigned int *
00401D50  68 72 04 00 00                                push    472h; int
00401D55  56                                            push    esi; struct CDataExchange *
00401D56  e8 9f 88 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401D5B  8b 03                                         mov     eax, [ebx]
00401D5D  6a 32                                         push    32h ; '2'; unsigned int
00401D5F  6a 00                                         push    0; unsigned int
00401D61  50                                            push    eax; unsigned int
00401D62  56                                            push    esi; struct CDataExchange *
00401D63  e8 8c 88 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401D68  8d 9f dc 00 00 00                             lea     ebx, [edi+0DCh]
00401D6E  53                                            push    ebx; unsigned int *
00401D6F  68 73 04 00 00                                push    473h; int
00401D74  56                                            push    esi; struct CDataExchange *
00401D75  e8 80 88 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401D7A  8b 0b                                         mov     ecx, [ebx]
00401D7C  6a 32                                         push    32h ; '2'; unsigned int
00401D7E  6a 00                                         push    0; unsigned int
00401D80  51                                            push    ecx; unsigned int
00401D81  56                                            push    esi; struct CDataExchange *
00401D82  e8 6d 88 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401D87  8d 9f e0 00 00 00                             lea     ebx, [edi+0E0h]
00401D8D  53                                            push    ebx; unsigned int *
00401D8E  68 74 04 00 00                                push    474h; int
00401D93  56                                            push    esi; struct CDataExchange *
00401D94  e8 61 88 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401D99  6a 32                                         push    32h ; '2'; unsigned int
00401D9B  8b 13                                         mov     edx, [ebx]
00401D9D  6a 00                                         push    0; unsigned int
00401D9F  52                                            push    edx; unsigned int
00401DA0  56                                            push    esi; struct CDataExchange *
00401DA1  e8 4e 88 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401DA6  8d 9f e4 00 00 00                             lea     ebx, [edi+0E4h]
00401DAC  53                                            push    ebx; unsigned int *
00401DAD  68 75 04 00 00                                push    475h; int
00401DB2  56                                            push    esi; struct CDataExchange *
00401DB3  e8 42 88 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401DB8  8b 03                                         mov     eax, [ebx]
00401DBA  6a 32                                         push    32h ; '2'; unsigned int
00401DBC  6a 00                                         push    0; unsigned int
00401DBE  50                                            push    eax; unsigned int
00401DBF  56                                            push    esi; struct CDataExchange *
00401DC0  e8 2f 88 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401DC5  81 c7 e8 00 00 00                             add     edi, 0E8h
00401DCB  57                                            push    edi; unsigned int *
00401DCC  68 76 04 00 00                                push    476h; int
00401DD1  56                                            push    esi; struct CDataExchange *
00401DD2  e8 23 88 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00401DD7  8b 0f                                         mov     ecx, [edi]
00401DD9  6a 64                                         push    64h ; 'd'; unsigned int
00401DDB  6a 14                                         push    14h; unsigned int
00401DDD  51                                            push    ecx; unsigned int
00401DDE  56                                            push    esi; struct CDataExchange *
00401DDF  e8 10 88 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00401DE4  5f                                            pop     edi
00401DE5  5e                                            pop     esi
00401DE6  5b                                            pop     ebx
00401DE7  c2 04 00                                      retn    4
