00402BB0  56                                            push    esi
00402BB1  8b f1                                         mov     esi, ecx
00402BB3  6a 01                                         push    1; int
00402BB5  e8 70 7a 01 00                                call    ?UpdateData@CWnd@@QAEHH@Z; CWnd::UpdateData(int)
00402BBA  85 c0                                         test    eax, eax
00402BBC  75 02                                         jnz     short loc_402BC0
00402BBE  5e                                            pop     esi
00402BBF  c3                                            retn
00402BC0  8b 8e ac 00 00 00                             mov     ecx, [esi+0ACh]
00402BC6  8a 96 a8 00 00 00                             mov     dl, [esi+0A8h]
00402BCC  33 c0                                         xor     eax, eax
00402BCE  8a 86 b5 00 00 00                             mov     al, [esi+0B5h]
00402BD4  88 14 81                                      mov     [ecx+eax*4], dl
00402BD7  8b 8e ac 00 00 00                             mov     ecx, [esi+0ACh]
00402BDD  8a 96 a0 00 00 00                             mov     dl, [esi+0A0h]
00402BE3  33 c0                                         xor     eax, eax
00402BE5  8a 86 b5 00 00 00                             mov     al, [esi+0B5h]
00402BEB  88 54 81 01                                   mov     [ecx+eax*4+1], dl
00402BEF  8b 8e ac 00 00 00                             mov     ecx, [esi+0ACh]
00402BF5  66 8b 96 a4 00 00 00                          mov     dx, [esi+0A4h]
00402BFC  33 c0                                         xor     eax, eax
00402BFE  8a 86 b5 00 00 00                             mov     al, [esi+0B5h]
00402C04  5e                                            pop     esi
00402C05  66 89 54 81 02                                mov     [ecx+eax*4+2], dx
00402C0A  b8 01 00 00 00                                mov     eax, 1
00402C0F  c3                                            retn
