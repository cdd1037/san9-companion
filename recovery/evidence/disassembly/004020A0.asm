004020A0  56                                            push    esi
004020A1  8b f1                                         mov     esi, ecx
004020A3  8a 8e f5 00 00 00                             mov     cl, [esi+0F5h]
004020A9  8a 86 f4 00 00 00                             mov     al, [esi+0F4h]
004020AF  3a c8                                         cmp     cl, al
004020B1  0f 83 fe 00 00 00                             jnb     loc_4021B5
004020B7  8b 96 ec 00 00 00                             mov     edx, [esi+0ECh]
004020BD  81 e1 ff 00 00 00                             and     ecx, 0FFh
004020C3  6a 00                                         push    0; lParam
004020C5  51                                            push    ecx; wParam
004020C6  8d 04 49                                      lea     eax, [ecx+ecx*2]
004020C9  68 86 01 00 00                                push    186h; Msg
004020CE  8d 04 42                                      lea     eax, [edx+eax*2]
004020D1  8a 10                                         mov     dl, [eax]
004020D3  83 e2 0f                                      and     edx, 0Fh
004020D6  89 96 a0 00 00 00                             mov     [esi+0A0h], edx
004020DC  8a 10                                         mov     dl, [eax]
004020DE  c1 ea 04                                      shr     edx, 4
004020E1  83 e2 01                                      and     edx, 1
004020E4  89 96 a8 00 00 00                             mov     [esi+0A8h], edx
004020EA  8a 10                                         mov     dl, [eax]
004020EC  c1 ea 05                                      shr     edx, 5
004020EF  83 e2 01                                      and     edx, 1
004020F2  89 96 a4 00 00 00                             mov     [esi+0A4h], edx
004020F8  33 d2                                         xor     edx, edx
004020FA  8a 10                                         mov     dl, [eax]
004020FC  c1 ea 07                                      shr     edx, 7
004020FF  89 96 ac 00 00 00                             mov     [esi+0ACh], edx
00402105  33 d2                                         xor     edx, edx
00402107  8a 50 01                                      mov     dl, [eax+1]
0040210A  89 96 c0 00 00 00                             mov     [esi+0C0h], edx
00402110  33 d2                                         xor     edx, edx
00402112  8a 50 02                                      mov     dl, [eax+2]
00402115  89 96 b0 00 00 00                             mov     [esi+0B0h], edx
0040211B  33 d2                                         xor     edx, edx
0040211D  8a 50 03                                      mov     dl, [eax+3]
00402120  89 96 bc 00 00 00                             mov     [esi+0BCh], edx
00402126  33 d2                                         xor     edx, edx
00402128  8a 50 04                                      mov     dl, [eax+4]
0040212B  89 96 b8 00 00 00                             mov     [esi+0B8h], edx
00402131  33 d2                                         xor     edx, edx
00402133  8a 50 05                                      mov     dl, [eax+5]
00402136  8d 04 cd 48 d9 42 00                          lea     eax, ds:42D948h[ecx*8]
0040213D  89 96 b4 00 00 00                             mov     [esi+0B4h], edx
00402143  33 d2                                         xor     edx, edx
00402145  8a 10                                         mov     dl, [eax]
00402147  40                                            inc     eax
00402148  89 96 c8 00 00 00                             mov     [esi+0C8h], edx
0040214E  33 d2                                         xor     edx, edx
00402150  8a 10                                         mov     dl, [eax]
00402152  40                                            inc     eax
00402153  89 96 cc 00 00 00                             mov     [esi+0CCh], edx
00402159  33 d2                                         xor     edx, edx
0040215B  8a 10                                         mov     dl, [eax]
0040215D  40                                            inc     eax
0040215E  89 96 d0 00 00 00                             mov     [esi+0D0h], edx
00402164  33 d2                                         xor     edx, edx
00402166  8a 10                                         mov     dl, [eax]
00402168  40                                            inc     eax
00402169  89 96 d4 00 00 00                             mov     [esi+0D4h], edx
0040216F  33 d2                                         xor     edx, edx
00402171  8a 10                                         mov     dl, [eax]
00402173  40                                            inc     eax
00402174  89 96 d8 00 00 00                             mov     [esi+0D8h], edx
0040217A  33 d2                                         xor     edx, edx
0040217C  8a 10                                         mov     dl, [eax]
0040217E  40                                            inc     eax
0040217F  89 96 dc 00 00 00                             mov     [esi+0DCh], edx
00402185  33 d2                                         xor     edx, edx
00402187  8a 10                                         mov     dl, [eax]
00402189  89 96 e0 00 00 00                             mov     [esi+0E0h], edx
0040218F  33 d2                                         xor     edx, edx
00402191  8a 50 01                                      mov     dl, [eax+1]
00402194  33 c0                                         xor     eax, eax
00402196  89 96 e4 00 00 00                             mov     [esi+0E4h], edx
0040219C  8a 81 d8 da 42 00                             mov     al, byte_42DAD8[ecx]
004021A2  89 86 e8 00 00 00                             mov     [esi+0E8h], eax
004021A8  8b 8e 80 00 00 00                             mov     ecx, [esi+80h]
004021AE  51                                            push    ecx; hWnd
004021AF  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
004021B5  6a 00                                         push    0; int
004021B7  8b ce                                         mov     ecx, esi; this
004021B9  e8 6c 84 01 00                                call    ?UpdateData@CWnd@@QAEHH@Z; CWnd::UpdateData(int)
004021BE  5e                                            pop     esi
004021BF  c3                                            retn
