00402310  56                                            push    esi
00402311  8b f1                                         mov     esi, ecx
00402313  e8 a8 fe ff ff                                call    sub_4021C0
00402318  85 c0                                         test    eax, eax
0040231A  6a 00                                         push    0; lParam
0040231C  75 1d                                         jnz     short loc_40233B
0040231E  8b 8e 80 00 00 00                             mov     ecx, [esi+80h]
00402324  33 c0                                         xor     eax, eax
00402326  8a 86 f5 00 00 00                             mov     al, [esi+0F5h]
0040232C  50                                            push    eax; wParam
0040232D  68 86 01 00 00                                push    186h; Msg
00402332  51                                            push    ecx; hWnd
00402333  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
00402339  5e                                            pop     esi
0040233A  c3                                            retn
0040233B  8b 96 80 00 00 00                             mov     edx, [esi+80h]
00402341  6a 00                                         push    0; wParam
00402343  68 88 01 00 00                                push    188h; Msg
00402348  52                                            push    edx; hWnd
00402349  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
0040234F  8b ce                                         mov     ecx, esi; this
00402351  88 86 f5 00 00 00                             mov     [esi+0F5h], al
00402357  e8 44 fd ff ff                                call    sub_4020A0
0040235C  5e                                            pop     esi
0040235D  c3                                            retn
