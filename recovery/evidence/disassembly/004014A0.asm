004014A0  56                                            push    esi
004014A1  8b f1                                         mov     esi, ecx
004014A3  8a 8e cd 00 00 00                             mov     cl, [esi+0CDh]
004014A9  8a 86 cc 00 00 00                             mov     al, [esi+0CCh]
004014AF  3a c8                                         cmp     cl, al
004014B1  0f 83 a8 00 00 00                             jnb     loc_40155F
004014B7  8b 86 c4 00 00 00                             mov     eax, [esi+0C4h]
004014BD  81 e1 ff 00 00 00                             and     ecx, 0FFh
004014C3  6a 00                                         push    0; lParam
004014C5  51                                            push    ecx; wParam
004014C6  8b 14 c8                                      mov     edx, [eax+ecx*8]
004014C9  8d 04 c8                                      lea     eax, [eax+ecx*8]
004014CC  83 e2 3f                                      and     edx, 3Fh
004014CF  68 86 01 00 00                                push    186h; Msg
004014D4  89 96 b8 00 00 00                             mov     [esi+0B8h], edx
004014DA  8b 10                                         mov     edx, [eax]
004014DC  c1 ea 06                                      shr     edx, 6
004014DF  83 e2 3f                                      and     edx, 3Fh
004014E2  89 96 b4 00 00 00                             mov     [esi+0B4h], edx
004014E8  8b 10                                         mov     edx, [eax]
004014EA  c1 ea 0c                                      shr     edx, 0Ch
004014ED  83 e2 3f                                      and     edx, 3Fh
004014F0  89 96 b0 00 00 00                             mov     [esi+0B0h], edx
004014F6  8b 10                                         mov     edx, [eax]
004014F8  c1 ea 12                                      shr     edx, 12h
004014FB  83 e2 3f                                      and     edx, 3Fh
004014FE  89 96 a4 00 00 00                             mov     [esi+0A4h], edx
00401504  8b 10                                         mov     edx, [eax]
00401506  c1 ea 18                                      shr     edx, 18h
00401509  83 e2 3f                                      and     edx, 3Fh
0040150C  89 96 ac 00 00 00                             mov     [esi+0ACh], edx
00401512  8a 50 04                                      mov     dl, [eax+4]
00401515  83 e2 0f                                      and     edx, 0Fh
00401518  89 96 a0 00 00 00                             mov     [esi+0A0h], edx
0040151E  8a 50 04                                      mov     dl, [eax+4]
00401521  c1 ea 04                                      shr     edx, 4
00401524  83 e2 0f                                      and     edx, 0Fh
00401527  89 96 c0 00 00 00                             mov     [esi+0C0h], edx
0040152D  66 8b 50 04                                   mov     dx, [eax+4]
00401531  c1 ea 08                                      shr     edx, 8
00401534  83 e2 0f                                      and     edx, 0Fh
00401537  89 96 bc 00 00 00                             mov     [esi+0BCh], edx
0040153D  33 d2                                         xor     edx, edx
0040153F  66 8b 50 06                                   mov     dx, [eax+6]
00401543  89 96 a8 00 00 00                             mov     [esi+0A8h], edx
00401549  8b 86 80 00 00 00                             mov     eax, [esi+80h]
0040154F  50                                            push    eax; hWnd
00401550  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
00401556  6a 00                                         push    0; int
00401558  8b ce                                         mov     ecx, esi; this
0040155A  e8 cb 90 01 00                                call    ?UpdateData@CWnd@@QAEHH@Z; CWnd::UpdateData(int)
0040155F  5e                                            pop     esi
00401560  c3                                            retn
