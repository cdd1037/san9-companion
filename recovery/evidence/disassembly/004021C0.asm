004021C0  56                                            push    esi
004021C1  8b f1                                         mov     esi, ecx
004021C3  6a 01                                         push    1; int
004021C5  e8 60 84 01 00                                call    ?UpdateData@CWnd@@QAEHH@Z; CWnd::UpdateData(int)
004021CA  85 c0                                         test    eax, eax
004021CC  75 02                                         jnz     short loc_4021D0
004021CE  5e                                            pop     esi
004021CF  c3                                            retn
004021D0  8a 8e ac 00 00 00                             mov     cl, [esi+0ACh]
004021D6  8a 86 a4 00 00 00                             mov     al, [esi+0A4h]
004021DC  c0 e1 02                                      shl     cl, 2
004021DF  02 c8                                         add     cl, al
004021E1  8a 86 a8 00 00 00                             mov     al, [esi+0A8h]
004021E7  d0 e1                                         shl     cl, 1
004021E9  02 c8                                         add     cl, al
004021EB  8a 86 a0 00 00 00                             mov     al, [esi+0A0h]
004021F1  c0 e1 04                                      shl     cl, 4
004021F4  02 c8                                         add     cl, al
004021F6  33 c0                                         xor     eax, eax
004021F8  8a 86 f5 00 00 00                             mov     al, [esi+0F5h]
004021FE  8d 14 40                                      lea     edx, [eax+eax*2]
00402201  8b 86 ec 00 00 00                             mov     eax, [esi+0ECh]
00402207  88 0c 50                                      mov     [eax+edx*2], cl
0040220A  8b 96 ec 00 00 00                             mov     edx, [esi+0ECh]
00402210  33 c0                                         xor     eax, eax
00402212  8a 86 f5 00 00 00                             mov     al, [esi+0F5h]
00402218  8d 0c 40                                      lea     ecx, [eax+eax*2]
0040221B  8a 86 c0 00 00 00                             mov     al, [esi+0C0h]
00402221  88 44 4a 01                                   mov     [edx+ecx*2+1], al
00402225  8b 96 ec 00 00 00                             mov     edx, [esi+0ECh]
0040222B  33 c0                                         xor     eax, eax
0040222D  8a 86 f5 00 00 00                             mov     al, [esi+0F5h]
00402233  8d 0c 40                                      lea     ecx, [eax+eax*2]
00402236  8a 86 b0 00 00 00                             mov     al, [esi+0B0h]
0040223C  88 44 4a 02                                   mov     [edx+ecx*2+2], al
00402240  8b 96 ec 00 00 00                             mov     edx, [esi+0ECh]
00402246  33 c0                                         xor     eax, eax
00402248  8a 86 f5 00 00 00                             mov     al, [esi+0F5h]
0040224E  8d 0c 40                                      lea     ecx, [eax+eax*2]
00402251  8a 86 bc 00 00 00                             mov     al, [esi+0BCh]
00402257  88 44 4a 03                                   mov     [edx+ecx*2+3], al
0040225B  8b 96 ec 00 00 00                             mov     edx, [esi+0ECh]
00402261  33 c0                                         xor     eax, eax
00402263  8a 86 f5 00 00 00                             mov     al, [esi+0F5h]
00402269  8d 0c 40                                      lea     ecx, [eax+eax*2]
0040226C  8a 86 b8 00 00 00                             mov     al, [esi+0B8h]
00402272  88 44 4a 04                                   mov     [edx+ecx*2+4], al
00402276  8b 96 ec 00 00 00                             mov     edx, [esi+0ECh]
0040227C  33 c0                                         xor     eax, eax
0040227E  8a 86 f5 00 00 00                             mov     al, [esi+0F5h]
00402284  8d 0c 40                                      lea     ecx, [eax+eax*2]
00402287  8a 86 b4 00 00 00                             mov     al, [esi+0B4h]
0040228D  88 44 4a 05                                   mov     [edx+ecx*2+5], al
00402291  8a 96 c8 00 00 00                             mov     dl, [esi+0C8h]
00402297  33 c9                                         xor     ecx, ecx
00402299  8a 8e f5 00 00 00                             mov     cl, [esi+0F5h]
0040229F  88 14 cd 48 d9 42 00                          mov     byte ptr dword_42D948[ecx*8], dl
004022A6  8d 04 cd 48 d9 42 00                          lea     eax, ds:42D948h[ecx*8]
004022AD  8a 8e cc 00 00 00                             mov     cl, [esi+0CCh]
004022B3  40                                            inc     eax
004022B4  88 08                                         mov     [eax], cl
004022B6  8a 96 d0 00 00 00                             mov     dl, [esi+0D0h]
004022BC  40                                            inc     eax
004022BD  88 10                                         mov     [eax], dl
004022BF  8a 8e d4 00 00 00                             mov     cl, [esi+0D4h]
004022C5  40                                            inc     eax
004022C6  88 08                                         mov     [eax], cl
004022C8  8a 96 d8 00 00 00                             mov     dl, [esi+0D8h]
004022CE  40                                            inc     eax
004022CF  88 10                                         mov     [eax], dl
004022D1  8a 8e dc 00 00 00                             mov     cl, [esi+0DCh]
004022D7  40                                            inc     eax
004022D8  88 08                                         mov     [eax], cl
004022DA  8a 96 e0 00 00 00                             mov     dl, [esi+0E0h]
004022E0  40                                            inc     eax
004022E1  88 10                                         mov     [eax], dl
004022E3  8a 8e e4 00 00 00                             mov     cl, [esi+0E4h]
004022E9  33 d2                                         xor     edx, edx
004022EB  88 48 01                                      mov     [eax+1], cl
004022EE  8a 96 f5 00 00 00                             mov     dl, [esi+0F5h]
004022F4  8a 86 e8 00 00 00                             mov     al, [esi+0E8h]
004022FA  5e                                            pop     esi
004022FB  88 82 d8 da 42 00                             mov     byte_42DAD8[edx], al
00402301  b8 01 00 00 00                                mov     eax, 1
00402306  c3                                            retn
