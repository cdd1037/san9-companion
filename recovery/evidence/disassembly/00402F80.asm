00402F80  53                                            push    ebx
00402F81  56                                            push    esi
00402F82  8b 74 24 0c                                   mov     esi, [esp+8+arg_0]
00402F86  57                                            push    edi
00402F87  8b f9                                         mov     edi, ecx
00402F89  8d 5f 60                                      lea     ebx, [edi+60h]
00402F8C  53                                            push    ebx; unsigned int *
00402F8D  68 03 04 00 00                                push    403h; int
00402F92  56                                            push    esi; struct CDataExchange *
00402F93  e8 62 76 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00402F98  8b 03                                         mov     eax, [ebx]
00402F9A  6a 7b                                         push    7Bh ; '{'; unsigned int
00402F9C  6a 01                                         push    1; unsigned int
00402F9E  50                                            push    eax; unsigned int
00402F9F  56                                            push    esi; struct CDataExchange *
00402FA0  e8 4f 76 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00402FA5  8d 5f 64                                      lea     ebx, [edi+64h]
00402FA8  53                                            push    ebx; unsigned int *
00402FA9  68 02 04 00 00                                push    402h; int
00402FAE  56                                            push    esi; struct CDataExchange *
00402FAF  e8 46 76 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00402FB4  8b 0b                                         mov     ecx, [ebx]
00402FB6  6a 7b                                         push    7Bh ; '{'; unsigned int
00402FB8  6a 01                                         push    1; unsigned int
00402FBA  51                                            push    ecx; unsigned int
00402FBB  56                                            push    esi; struct CDataExchange *
00402FBC  e8 33 76 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00402FC1  8d 5f 68                                      lea     ebx, [edi+68h]
00402FC4  53                                            push    ebx; unsigned int *
00402FC5  68 04 04 00 00                                push    404h; int
00402FCA  56                                            push    esi; struct CDataExchange *
00402FCB  e8 2a 76 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00402FD0  8b 13                                         mov     edx, [ebx]
00402FD2  6a 7b                                         push    7Bh ; '{'; unsigned int
00402FD4  6a 01                                         push    1; unsigned int
00402FD6  52                                            push    edx; unsigned int
00402FD7  56                                            push    esi; struct CDataExchange *
00402FD8  e8 17 76 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00402FDD  8d 5f 6c                                      lea     ebx, [edi+6Ch]
00402FE0  53                                            push    ebx; unsigned int *
00402FE1  68 ff 03 00 00                                push    3FFh; int
00402FE6  56                                            push    esi; struct CDataExchange *
00402FE7  e8 0e 76 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00402FEC  8b 03                                         mov     eax, [ebx]
00402FEE  6a 7b                                         push    7Bh ; '{'; unsigned int
00402FF0  6a 01                                         push    1; unsigned int
00402FF2  50                                            push    eax; unsigned int
00402FF3  56                                            push    esi; struct CDataExchange *
00402FF4  e8 fb 75 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00402FF9  8d 5f 70                                      lea     ebx, [edi+70h]
00402FFC  53                                            push    ebx; unsigned int *
00402FFD  68 00 04 00 00                                push    400h; int
00403002  56                                            push    esi; struct CDataExchange *
00403003  e8 f2 75 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403008  8b 0b                                         mov     ecx, [ebx]
0040300A  6a 7b                                         push    7Bh ; '{'; unsigned int
0040300C  6a 01                                         push    1; unsigned int
0040300E  51                                            push    ecx; unsigned int
0040300F  56                                            push    esi; struct CDataExchange *
00403010  e8 df 75 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403015  8d 5f 74                                      lea     ebx, [edi+74h]
00403018  53                                            push    ebx; unsigned int *
00403019  68 01 04 00 00                                push    401h; int
0040301E  56                                            push    esi; struct CDataExchange *
0040301F  e8 d6 75 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403024  8b 13                                         mov     edx, [ebx]
00403026  6a 7b                                         push    7Bh ; '{'; unsigned int
00403028  6a 01                                         push    1; unsigned int
0040302A  52                                            push    edx; unsigned int
0040302B  56                                            push    esi; struct CDataExchange *
0040302C  e8 c3 75 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403031  8d 5f 78                                      lea     ebx, [edi+78h]
00403034  53                                            push    ebx; unsigned int *
00403035  68 fc 03 00 00                                push    3FCh; int
0040303A  56                                            push    esi; struct CDataExchange *
0040303B  e8 ba 75 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403040  8b 03                                         mov     eax, [ebx]
00403042  6a 7b                                         push    7Bh ; '{'; unsigned int
00403044  6a 01                                         push    1; unsigned int
00403046  50                                            push    eax; unsigned int
00403047  56                                            push    esi; struct CDataExchange *
00403048  e8 a7 75 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
0040304D  8d 5f 7c                                      lea     ebx, [edi+7Ch]
00403050  53                                            push    ebx; unsigned int *
00403051  68 fd 03 00 00                                push    3FDh; int
00403056  56                                            push    esi; struct CDataExchange *
00403057  e8 9e 75 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
0040305C  8b 0b                                         mov     ecx, [ebx]
0040305E  6a 7b                                         push    7Bh ; '{'; unsigned int
00403060  6a 01                                         push    1; unsigned int
00403062  51                                            push    ecx; unsigned int
00403063  56                                            push    esi; struct CDataExchange *
00403064  e8 8b 75 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403069  8d 9f 80 00 00 00                             lea     ebx, [edi+80h]
0040306F  53                                            push    ebx; unsigned int *
00403070  68 fe 03 00 00                                push    3FEh; int
00403075  56                                            push    esi; struct CDataExchange *
00403076  e8 7f 75 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
0040307B  8b 13                                         mov     edx, [ebx]
0040307D  6a 7b                                         push    7Bh ; '{'; unsigned int
0040307F  6a 01                                         push    1; unsigned int
00403081  52                                            push    edx; unsigned int
00403082  56                                            push    esi; struct CDataExchange *
00403083  e8 6c 75 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403088  8d 87 84 00 00 00                             lea     eax, [edi+84h]
0040308E  50                                            push    eax; int *
0040308F  68 07 04 00 00                                push    407h; int
00403094  56                                            push    esi; struct CDataExchange *
00403095  e8 e4 75 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
0040309A  8d 8f 88 00 00 00                             lea     ecx, [edi+88h]
004030A0  51                                            push    ecx; int *
004030A1  68 f9 03 00 00                                push    3F9h; int
004030A6  56                                            push    esi; struct CDataExchange *
004030A7  e8 d2 75 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004030AC  8d 97 8c 00 00 00                             lea     edx, [edi+8Ch]
004030B2  52                                            push    edx; int *
004030B3  68 08 04 00 00                                push    408h; int
004030B8  56                                            push    esi; struct CDataExchange *
004030B9  e8 c0 75 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004030BE  8d 87 90 00 00 00                             lea     eax, [edi+90h]
004030C4  50                                            push    eax; int *
004030C5  68 05 04 00 00                                push    405h; int
004030CA  56                                            push    esi; struct CDataExchange *
004030CB  e8 ae 75 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004030D0  8d 8f 94 00 00 00                             lea     ecx, [edi+94h]
004030D6  51                                            push    ecx; int *
004030D7  68 fa 03 00 00                                push    3FAh; int
004030DC  56                                            push    esi; struct CDataExchange *
004030DD  e8 9c 75 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004030E2  8d 97 98 00 00 00                             lea     edx, [edi+98h]
004030E8  52                                            push    edx; int *
004030E9  68 f7 03 00 00                                push    3F7h; int
004030EE  56                                            push    esi; struct CDataExchange *
004030EF  e8 8a 75 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004030F4  8d 87 9c 00 00 00                             lea     eax, [edi+9Ch]
004030FA  50                                            push    eax; int *
004030FB  68 09 04 00 00                                push    409h; int
00403100  56                                            push    esi; struct CDataExchange *
00403101  e8 78 75 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403106  8d 8f a0 00 00 00                             lea     ecx, [edi+0A0h]
0040310C  51                                            push    ecx; int *
0040310D  68 06 04 00 00                                push    406h; int
00403112  56                                            push    esi; struct CDataExchange *
00403113  e8 66 75 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403118  8d 97 a4 00 00 00                             lea     edx, [edi+0A4h]
0040311E  52                                            push    edx; int *
0040311F  68 0d 04 00 00                                push    40Dh; int
00403124  56                                            push    esi; struct CDataExchange *
00403125  e8 54 75 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
0040312A  8d 9f a8 00 00 00                             lea     ebx, [edi+0A8h]
00403130  53                                            push    ebx; int *
00403131  68 0f 04 00 00                                push    40Fh; int
00403136  56                                            push    esi; struct CDataExchange *
00403137  e8 6c 75 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAH@Z; DDX_Text(CDataExchange *,int,int &)
0040313C  8b 03                                         mov     eax, [ebx]
0040313E  68 b8 0b 00 00                                push    0BB8h; int
00403143  68 48 f4 ff ff                                push    0FFFFF448h; int
00403148  50                                            push    eax; int
00403149  56                                            push    esi; struct CDataExchange *
0040314A  e8 53 75 01 00                                call    ?DDV_MinMaxInt@@YGXPAVCDataExchange@@HHH@Z; DDV_MinMaxInt(CDataExchange *,int,int,int)
0040314F  8d 8f ac 00 00 00                             lea     ecx, [edi+0ACh]
00403155  51                                            push    ecx; int *
00403156  68 0e 04 00 00                                push    40Eh; int
0040315B  56                                            push    esi; struct CDataExchange *
0040315C  e8 1d 75 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403161  8d 97 b0 00 00 00                             lea     edx, [edi+0B0h]
00403167  52                                            push    edx; int *
00403168  68 10 04 00 00                                push    410h; int
0040316D  56                                            push    esi; struct CDataExchange *
0040316E  e8 0b 75 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403173  8d 87 b4 00 00 00                             lea     eax, [edi+0B4h]
00403179  50                                            push    eax; int *
0040317A  68 12 04 00 00                                push    412h; int
0040317F  56                                            push    esi; struct CDataExchange *
00403180  e8 f9 74 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403185  8d 8f b8 00 00 00                             lea     ecx, [edi+0B8h]
0040318B  51                                            push    ecx; int *
0040318C  68 18 04 00 00                                push    418h; int
00403191  56                                            push    esi; struct CDataExchange *
00403192  e8 e7 74 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403197  8d 97 bc 00 00 00                             lea     edx, [edi+0BCh]
0040319D  52                                            push    edx; int *
0040319E  68 19 04 00 00                                push    419h; int
004031A3  56                                            push    esi; struct CDataExchange *
004031A4  e8 d5 74 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004031A9  8d 87 c0 00 00 00                             lea     eax, [edi+0C0h]
004031AF  50                                            push    eax; int *
004031B0  68 16 04 00 00                                push    416h; int
004031B5  56                                            push    esi; struct CDataExchange *
004031B6  e8 c3 74 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004031BB  8d 8f c4 00 00 00                             lea     ecx, [edi+0C4h]
004031C1  51                                            push    ecx; int *
004031C2  68 1a 04 00 00                                push    41Ah; int
004031C7  56                                            push    esi; struct CDataExchange *
004031C8  e8 b1 74 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004031CD  8d 97 c8 00 00 00                             lea     edx, [edi+0C8h]
004031D3  52                                            push    edx; int *
004031D4  68 1b 04 00 00                                push    41Bh; int
004031D9  56                                            push    esi; struct CDataExchange *
004031DA  e8 9f 74 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004031DF  8d 87 cc 00 00 00                             lea     eax, [edi+0CCh]
004031E5  50                                            push    eax; int *
004031E6  68 1c 04 00 00                                push    41Ch; int
004031EB  56                                            push    esi; struct CDataExchange *
004031EC  e8 8d 74 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004031F1  8d 8f d0 00 00 00                             lea     ecx, [edi+0D0h]
004031F7  51                                            push    ecx; int *
004031F8  68 0a 04 00 00                                push    40Ah; int
004031FD  56                                            push    esi; struct CDataExchange *
004031FE  e8 7b 74 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403203  8d 97 d4 00 00 00                             lea     edx, [edi+0D4h]
00403209  52                                            push    edx; int *
0040320A  68 1d 04 00 00                                push    41Dh; int
0040320F  56                                            push    esi; struct CDataExchange *
00403210  e8 69 74 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403215  8d 9f d8 00 00 00                             lea     ebx, [edi+0D8h]
0040321B  53                                            push    ebx; unsigned int *
0040321C  68 15 04 00 00                                push    415h; int
00403221  56                                            push    esi; struct CDataExchange *
00403222  e8 d3 73 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403227  8b 03                                         mov     eax, [ebx]
00403229  6a 0a                                         push    0Ah; unsigned int
0040322B  6a 05                                         push    5; unsigned int
0040322D  50                                            push    eax; unsigned int
0040322E  56                                            push    esi; struct CDataExchange *
0040322F  e8 c0 73 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403234  8d 8f dc 00 00 00                             lea     ecx, [edi+0DCh]
0040323A  51                                            push    ecx; int *
0040323B  68 11 04 00 00                                push    411h; int
00403240  56                                            push    esi; struct CDataExchange *
00403241  e8 38 74 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403246  8d 9f e0 00 00 00                             lea     ebx, [edi+0E0h]
0040324C  53                                            push    ebx; unsigned int *
0040324D  68 71 04 00 00                                push    471h; int
00403252  56                                            push    esi; struct CDataExchange *
00403253  e8 a2 73 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403258  8b 13                                         mov     edx, [ebx]
0040325A  6a 0a                                         push    0Ah; unsigned int
0040325C  6a 00                                         push    0; unsigned int
0040325E  52                                            push    edx; unsigned int
0040325F  56                                            push    esi; struct CDataExchange *
00403260  e8 8f 73 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403265  8d 9f e4 00 00 00                             lea     ebx, [edi+0E4h]
0040326B  53                                            push    ebx; unsigned int *
0040326C  68 72 04 00 00                                push    472h; int
00403271  56                                            push    esi; struct CDataExchange *
00403272  e8 83 73 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403277  8b 03                                         mov     eax, [ebx]
00403279  6a 32                                         push    32h ; '2'; unsigned int
0040327B  6a 00                                         push    0; unsigned int
0040327D  50                                            push    eax; unsigned int
0040327E  56                                            push    esi; struct CDataExchange *
0040327F  e8 70 73 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403284  8d 8f e8 00 00 00                             lea     ecx, [edi+0E8h]
0040328A  51                                            push    ecx; int *
0040328B  68 1e 04 00 00                                push    41Eh; int
00403290  56                                            push    esi; struct CDataExchange *
00403291  e8 e8 73 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403296  8d 97 ec 00 00 00                             lea     edx, [edi+0ECh]
0040329C  52                                            push    edx; int *
0040329D  68 14 04 00 00                                push    414h; int
004032A2  56                                            push    esi; struct CDataExchange *
004032A3  e8 d6 73 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004032A8  8d 87 f0 00 00 00                             lea     eax, [edi+0F0h]
004032AE  50                                            push    eax; int *
004032AF  68 13 04 00 00                                push    413h; int
004032B4  56                                            push    esi; struct CDataExchange *
004032B5  e8 c4 73 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004032BA  8d 8f f4 00 00 00                             lea     ecx, [edi+0F4h]
004032C0  51                                            push    ecx; int *
004032C1  68 17 04 00 00                                push    417h; int
004032C6  56                                            push    esi; struct CDataExchange *
004032C7  e8 b2 73 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004032CC  8d 97 f8 00 00 00                             lea     edx, [edi+0F8h]
004032D2  52                                            push    edx; int *
004032D3  68 1f 04 00 00                                push    41Fh; int
004032D8  56                                            push    esi; struct CDataExchange *
004032D9  e8 a0 73 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004032DE  8d 9f fc 00 00 00                             lea     ebx, [edi+0FCh]
004032E4  53                                            push    ebx; unsigned int *
004032E5  68 73 04 00 00                                push    473h; int
004032EA  56                                            push    esi; struct CDataExchange *
004032EB  e8 0a 73 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
004032F0  8b 03                                         mov     eax, [ebx]
004032F2  6a 0a                                         push    0Ah; unsigned int
004032F4  6a 00                                         push    0; unsigned int
004032F6  50                                            push    eax; unsigned int
004032F7  56                                            push    esi; struct CDataExchange *
004032F8  e8 f7 72 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
004032FD  8d 8f 00 01 00 00                             lea     ecx, [edi+100h]
00403303  51                                            push    ecx; int *
00403304  68 20 04 00 00                                push    420h; int
00403309  56                                            push    esi; struct CDataExchange *
0040330A  e8 6f 73 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
0040330F  8d 97 04 01 00 00                             lea     edx, [edi+104h]
00403315  52                                            push    edx; int *
00403316  68 21 04 00 00                                push    421h; int
0040331B  56                                            push    esi; struct CDataExchange *
0040331C  e8 5d 73 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403321  8d 87 08 01 00 00                             lea     eax, [edi+108h]
00403327  50                                            push    eax; int *
00403328  68 22 04 00 00                                push    422h; int
0040332D  56                                            push    esi; struct CDataExchange *
0040332E  e8 4b 73 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403333  8d 8f 0c 01 00 00                             lea     ecx, [edi+10Ch]
00403339  51                                            push    ecx; int *
0040333A  68 23 04 00 00                                push    423h; int
0040333F  56                                            push    esi; struct CDataExchange *
00403340  e8 39 73 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403345  8d 9f 10 01 00 00                             lea     ebx, [edi+110h]
0040334B  53                                            push    ebx; unsigned int *
0040334C  68 75 04 00 00                                push    475h; int
00403351  56                                            push    esi; struct CDataExchange *
00403352  e8 a3 72 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403357  8b 13                                         mov     edx, [ebx]
00403359  68 96 00 00 00                                push    96h; unsigned int
0040335E  6a 1e                                         push    1Eh; unsigned int
00403360  52                                            push    edx; unsigned int
00403361  56                                            push    esi; struct CDataExchange *
00403362  e8 8d 72 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403367  8d 9f 14 01 00 00                             lea     ebx, [edi+114h]
0040336D  53                                            push    ebx; unsigned int *
0040336E  68 76 04 00 00                                push    476h; int
00403373  56                                            push    esi; struct CDataExchange *
00403374  e8 81 72 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403379  8b 03                                         mov     eax, [ebx]
0040337B  6a 78                                         push    78h ; 'x'; unsigned int
0040337D  6a 14                                         push    14h; unsigned int
0040337F  50                                            push    eax; unsigned int
00403380  56                                            push    esi; struct CDataExchange *
00403381  e8 6e 72 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403386  8d 9f 18 01 00 00                             lea     ebx, [edi+118h]
0040338C  53                                            push    ebx; unsigned int *
0040338D  68 77 04 00 00                                push    477h; int
00403392  56                                            push    esi; struct CDataExchange *
00403393  e8 62 72 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403398  8b 0b                                         mov     ecx, [ebx]
0040339A  6a 5a                                         push    5Ah ; 'Z'; unsigned int
0040339C  6a 0a                                         push    0Ah; unsigned int
0040339E  51                                            push    ecx; unsigned int
0040339F  56                                            push    esi; struct CDataExchange *
004033A0  e8 4f 72 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
004033A5  8d 9f 1c 01 00 00                             lea     ebx, [edi+11Ch]
004033AB  53                                            push    ebx; unsigned int *
004033AC  68 78 04 00 00                                push    478h; int
004033B1  56                                            push    esi; struct CDataExchange *
004033B2  e8 43 72 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
004033B7  8b 13                                         mov     edx, [ebx]
004033B9  6a 32                                         push    32h ; '2'; unsigned int
004033BB  6a 00                                         push    0; unsigned int
004033BD  52                                            push    edx; unsigned int
004033BE  56                                            push    esi; struct CDataExchange *
004033BF  e8 30 72 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
004033C4  8d 9f 20 01 00 00                             lea     ebx, [edi+120h]
004033CA  53                                            push    ebx; unsigned int *
004033CB  68 74 04 00 00                                push    474h; int
004033D0  56                                            push    esi; struct CDataExchange *
004033D1  e8 24 72 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
004033D6  8b 03                                         mov     eax, [ebx]
004033D8  6a 0a                                         push    0Ah; unsigned int
004033DA  6a 00                                         push    0; unsigned int
004033DC  50                                            push    eax; unsigned int
004033DD  56                                            push    esi; struct CDataExchange *
004033DE  e8 11 72 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
004033E3  8d 9f 24 01 00 00                             lea     ebx, [edi+124h]
004033E9  53                                            push    ebx; unsigned int *
004033EA  68 7d 04 00 00                                push    47Dh; int
004033EF  56                                            push    esi; struct CDataExchange *
004033F0  e8 05 72 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
004033F5  8b 0b                                         mov     ecx, [ebx]
004033F7  6a 14                                         push    14h; unsigned int
004033F9  6a 08                                         push    8; unsigned int
004033FB  51                                            push    ecx; unsigned int
004033FC  56                                            push    esi; struct CDataExchange *
004033FD  e8 f2 71 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403402  8d 9f 28 01 00 00                             lea     ebx, [edi+128h]
00403408  53                                            push    ebx; unsigned int *
00403409  68 7c 04 00 00                                push    47Ch; int
0040340E  56                                            push    esi; struct CDataExchange *
0040340F  e8 e6 71 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403414  8b 13                                         mov     edx, [ebx]
00403416  6a 14                                         push    14h; unsigned int
00403418  6a 08                                         push    8; unsigned int
0040341A  52                                            push    edx; unsigned int
0040341B  56                                            push    esi; struct CDataExchange *
0040341C  e8 d3 71 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403421  8d 9f 2c 01 00 00                             lea     ebx, [edi+12Ch]
00403427  53                                            push    ebx; unsigned int *
00403428  68 79 04 00 00                                push    479h; int
0040342D  56                                            push    esi; struct CDataExchange *
0040342E  e8 c7 71 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403433  8b 03                                         mov     eax, [ebx]
00403435  6a 14                                         push    14h; unsigned int
00403437  6a 08                                         push    8; unsigned int
00403439  50                                            push    eax; unsigned int
0040343A  56                                            push    esi; struct CDataExchange *
0040343B  e8 b4 71 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403440  8d 9f 30 01 00 00                             lea     ebx, [edi+130h]
00403446  53                                            push    ebx; unsigned int *
00403447  68 7b 04 00 00                                push    47Bh; int
0040344C  56                                            push    esi; struct CDataExchange *
0040344D  e8 a8 71 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403452  8b 0b                                         mov     ecx, [ebx]
00403454  6a 14                                         push    14h; unsigned int
00403456  6a 08                                         push    8; unsigned int
00403458  51                                            push    ecx; unsigned int
00403459  56                                            push    esi; struct CDataExchange *
0040345A  e8 95 71 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
0040345F  8d 9f 34 01 00 00                             lea     ebx, [edi+134h]
00403465  53                                            push    ebx; unsigned int *
00403466  68 7a 04 00 00                                push    47Ah; int
0040346B  56                                            push    esi; struct CDataExchange *
0040346C  e8 89 71 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403471  8b 13                                         mov     edx, [ebx]
00403473  6a 14                                         push    14h; unsigned int
00403475  6a 08                                         push    8; unsigned int
00403477  52                                            push    edx; unsigned int
00403478  56                                            push    esi; struct CDataExchange *
00403479  e8 76 71 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
0040347E  8d 87 38 01 00 00                             lea     eax, [edi+138h]
00403484  50                                            push    eax; int *
00403485  68 24 04 00 00                                push    424h; int
0040348A  56                                            push    esi; struct CDataExchange *
0040348B  e8 ee 71 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403490  8d 8f 3c 01 00 00                             lea     ecx, [edi+13Ch]
00403496  51                                            push    ecx; int *
00403497  68 25 04 00 00                                push    425h; int
0040349C  56                                            push    esi; struct CDataExchange *
0040349D  e8 dc 71 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004034A2  8d 97 40 01 00 00                             lea     edx, [edi+140h]
004034A8  52                                            push    edx; int *
004034A9  68 26 04 00 00                                push    426h; int
004034AE  56                                            push    esi; struct CDataExchange *
004034AF  e8 ca 71 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004034B4  8d 87 44 01 00 00                             lea     eax, [edi+144h]
004034BA  50                                            push    eax; int *
004034BB  68 27 04 00 00                                push    427h; int
004034C0  56                                            push    esi; struct CDataExchange *
004034C1  e8 b8 71 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004034C6  8d 8f 48 01 00 00                             lea     ecx, [edi+148h]
004034CC  51                                            push    ecx; int *
004034CD  68 28 04 00 00                                push    428h; int
004034D2  56                                            push    esi; struct CDataExchange *
004034D3  e8 a6 71 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004034D8  8d 97 4c 01 00 00                             lea     edx, [edi+14Ch]
004034DE  52                                            push    edx; int *
004034DF  68 29 04 00 00                                push    429h; int
004034E4  56                                            push    esi; struct CDataExchange *
004034E5  e8 94 71 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004034EA  8d 9f 50 01 00 00                             lea     ebx, [edi+150h]
004034F0  53                                            push    ebx; unsigned int *
004034F1  68 7e 04 00 00                                push    47Eh; int
004034F6  56                                            push    esi; struct CDataExchange *
004034F7  e8 fe 70 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
004034FC  8b 03                                         mov     eax, [ebx]
004034FE  6a 0a                                         push    0Ah; unsigned int
00403500  6a 00                                         push    0; unsigned int
00403502  50                                            push    eax; unsigned int
00403503  56                                            push    esi; struct CDataExchange *
00403504  e8 eb 70 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403509  8d 9f 54 01 00 00                             lea     ebx, [edi+154h]
0040350F  53                                            push    ebx; unsigned int *
00403510  68 7f 04 00 00                                push    47Fh; int
00403515  56                                            push    esi; struct CDataExchange *
00403516  e8 df 70 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
0040351B  8b 0b                                         mov     ecx, [ebx]
0040351D  6a 0a                                         push    0Ah; unsigned int
0040351F  6a 00                                         push    0; unsigned int
00403521  51                                            push    ecx; unsigned int
00403522  56                                            push    esi; struct CDataExchange *
00403523  e8 cc 70 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403528  8d 97 58 01 00 00                             lea     edx, [edi+158h]
0040352E  52                                            push    edx; int *
0040352F  68 2a 04 00 00                                push    42Ah; int
00403534  56                                            push    esi; struct CDataExchange *
00403535  e8 44 71 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
0040353A  8d 87 5c 01 00 00                             lea     eax, [edi+15Ch]
00403540  50                                            push    eax; int *
00403541  68 2b 04 00 00                                push    42Bh; int
00403546  56                                            push    esi; struct CDataExchange *
00403547  e8 32 71 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
0040354C  8d 8f 60 01 00 00                             lea     ecx, [edi+160h]
00403552  51                                            push    ecx; int *
00403553  68 2c 04 00 00                                push    42Ch; int
00403558  56                                            push    esi; struct CDataExchange *
00403559  e8 20 71 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
0040355E  8d 97 64 01 00 00                             lea     edx, [edi+164h]
00403564  52                                            push    edx; int *
00403565  68 2d 04 00 00                                push    42Dh; int
0040356A  56                                            push    esi; struct CDataExchange *
0040356B  e8 0e 71 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403570  8d 9f 68 01 00 00                             lea     ebx, [edi+168h]
00403576  53                                            push    ebx; unsigned int *
00403577  68 80 04 00 00                                push    480h; int
0040357C  56                                            push    esi; struct CDataExchange *
0040357D  e8 78 70 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403582  8b 03                                         mov     eax, [ebx]
00403584  6a 0a                                         push    0Ah; unsigned int
00403586  6a 00                                         push    0; unsigned int
00403588  50                                            push    eax; unsigned int
00403589  56                                            push    esi; struct CDataExchange *
0040358A  e8 65 70 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
0040358F  8d 9f 6c 01 00 00                             lea     ebx, [edi+16Ch]
00403595  53                                            push    ebx; unsigned int *
00403596  68 81 04 00 00                                push    481h; int
0040359B  56                                            push    esi; struct CDataExchange *
0040359C  e8 59 70 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
004035A1  8b 0b                                         mov     ecx, [ebx]
004035A3  6a 7e                                         push    7Eh ; '~'; unsigned int
004035A5  6a 12                                         push    12h; unsigned int
004035A7  51                                            push    ecx; unsigned int
004035A8  56                                            push    esi; struct CDataExchange *
004035A9  e8 46 70 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
004035AE  8d 9f 70 01 00 00                             lea     ebx, [edi+170h]
004035B4  53                                            push    ebx; unsigned int *
004035B5  68 82 04 00 00                                push    482h; int
004035BA  56                                            push    esi; struct CDataExchange *
004035BB  e8 3a 70 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
004035C0  8b 13                                         mov     edx, [ebx]
004035C2  6a 0a                                         push    0Ah; unsigned int
004035C4  6a 00                                         push    0; unsigned int
004035C6  52                                            push    edx; unsigned int
004035C7  56                                            push    esi; struct CDataExchange *
004035C8  e8 27 70 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
004035CD  8d 87 74 01 00 00                             lea     eax, [edi+174h]
004035D3  50                                            push    eax; int *
004035D4  68 2e 04 00 00                                push    42Eh; int
004035D9  56                                            push    esi; struct CDataExchange *
004035DA  e8 9f 70 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004035DF  8d 8f 78 01 00 00                             lea     ecx, [edi+178h]
004035E5  51                                            push    ecx; int *
004035E6  68 2f 04 00 00                                push    42Fh; int
004035EB  56                                            push    esi; struct CDataExchange *
004035EC  e8 8d 70 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004035F1  8d 97 7c 01 00 00                             lea     edx, [edi+17Ch]
004035F7  52                                            push    edx; int *
004035F8  68 f8 03 00 00                                push    3F8h; int
004035FD  56                                            push    esi; struct CDataExchange *
004035FE  e8 7b 70 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403603  8d 87 80 01 00 00                             lea     eax, [edi+180h]
00403609  50                                            push    eax; int *
0040360A  68 f5 03 00 00                                push    3F5h; int
0040360F  56                                            push    esi; struct CDataExchange *
00403610  e8 69 70 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403615  8d 9f 84 01 00 00                             lea     ebx, [edi+184h]
0040361B  53                                            push    ebx; unsigned int *
0040361C  68 83 04 00 00                                push    483h; int
00403621  56                                            push    esi; struct CDataExchange *
00403622  e8 d3 6f 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403627  8b 0b                                         mov     ecx, [ebx]
00403629  6a 0a                                         push    0Ah; unsigned int
0040362B  6a 00                                         push    0; unsigned int
0040362D  51                                            push    ecx; unsigned int
0040362E  56                                            push    esi; struct CDataExchange *
0040362F  e8 c0 6f 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403634  8d 97 88 01 00 00                             lea     edx, [edi+188h]
0040363A  52                                            push    edx; int *
0040363B  68 30 04 00 00                                push    430h; int
00403640  56                                            push    esi; struct CDataExchange *
00403641  e8 38 70 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403646  8d 9f 8c 01 00 00                             lea     ebx, [edi+18Ch]
0040364C  53                                            push    ebx; unsigned int *
0040364D  68 84 04 00 00                                push    484h; int
00403652  56                                            push    esi; struct CDataExchange *
00403653  e8 a2 6f 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00403658  6a 64                                         push    64h ; 'd'; unsigned int
0040365A  6a 00                                         push    0; unsigned int
0040365C  8b 03                                         mov     eax, [ebx]
0040365E  50                                            push    eax; unsigned int
0040365F  56                                            push    esi; struct CDataExchange *
00403660  e8 8f 6f 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00403665  8d 8f 90 01 00 00                             lea     ecx, [edi+190h]
0040366B  51                                            push    ecx; int *
0040366C  68 31 04 00 00                                push    431h; int
00403671  56                                            push    esi; struct CDataExchange *
00403672  e8 07 70 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403677  8d 97 94 01 00 00                             lea     edx, [edi+194h]
0040367D  52                                            push    edx; int *
0040367E  68 fb 03 00 00                                push    3FBh; int
00403683  56                                            push    esi; struct CDataExchange *
00403684  e8 f5 6f 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403689  8d 87 98 01 00 00                             lea     eax, [edi+198h]
0040368F  50                                            push    eax; int *
00403690  68 32 04 00 00                                push    432h; int
00403695  56                                            push    esi; struct CDataExchange *
00403696  e8 e3 6f 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
0040369B  8d 9f 9c 01 00 00                             lea     ebx, [edi+19Ch]
004036A1  53                                            push    ebx; unsigned int *
004036A2  68 85 04 00 00                                push    485h; int
004036A7  56                                            push    esi; struct CDataExchange *
004036A8  e8 4d 6f 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
004036AD  8b 0b                                         mov     ecx, [ebx]
004036AF  6a 0a                                         push    0Ah; unsigned int
004036B1  6a 00                                         push    0; unsigned int
004036B3  51                                            push    ecx; unsigned int
004036B4  56                                            push    esi; struct CDataExchange *
004036B5  e8 3a 6f 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
004036BA  8d 97 a0 01 00 00                             lea     edx, [edi+1A0h]
004036C0  52                                            push    edx; int *
004036C1  68 86 04 00 00                                push    486h; int
004036C6  56                                            push    esi; struct CDataExchange *
004036C7  e8 b2 6f 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004036CC  8d 87 a4 01 00 00                             lea     eax, [edi+1A4h]
004036D2  50                                            push    eax; int *
004036D3  68 87 04 00 00                                push    487h; int
004036D8  56                                            push    esi; struct CDataExchange *
004036D9  e8 a0 6f 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004036DE  8d 8f a8 01 00 00                             lea     ecx, [edi+1A8h]
004036E4  51                                            push    ecx; int *
004036E5  68 88 04 00 00                                push    488h; int
004036EA  56                                            push    esi; struct CDataExchange *
004036EB  e8 8e 6f 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
004036F0  8d 97 ac 01 00 00                             lea     edx, [edi+1ACh]
004036F6  52                                            push    edx; int *
004036F7  68 89 04 00 00                                push    489h; int
004036FC  56                                            push    esi; struct CDataExchange *
004036FD  e8 7c 6f 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403702  8d 87 b0 01 00 00                             lea     eax, [edi+1B0h]
00403708  50                                            push    eax; int *
00403709  68 8a 04 00 00                                push    48Ah; int
0040370E  56                                            push    esi; struct CDataExchange *
0040370F  e8 6a 6f 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403714  8d 8f b4 01 00 00                             lea     ecx, [edi+1B4h]
0040371A  51                                            push    ecx; int *
0040371B  68 8b 04 00 00                                push    48Bh; int
00403720  56                                            push    esi; struct CDataExchange *
00403721  e8 58 6f 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403726  8d 97 b8 01 00 00                             lea     edx, [edi+1B8h]
0040372C  52                                            push    edx; int *
0040372D  68 8c 04 00 00                                push    48Ch; int
00403732  56                                            push    esi; struct CDataExchange *
00403733  e8 46 6f 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00403738  81 c7 bc 01 00 00                             add     edi, 1BCh
0040373E  57                                            push    edi; int *
0040373F  68 8d 04 00 00                                push    48Dh; int
00403744  56                                            push    esi; struct CDataExchange *
00403745  e8 34 6f 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
0040374A  5f                                            pop     edi
0040374B  5e                                            pop     esi
0040374C  5b                                            pop     ebx
0040374D  c2 04 00                                      retn    4
