00402C10  56                                            push    esi
00402C11  8b f1                                         mov     esi, ecx
00402C13  e8 98 ff ff ff                                call    sub_402BB0
00402C18  85 c0                                         test    eax, eax
00402C1A  6a 00                                         push    0; lParam
00402C1C  75 1d                                         jnz     short loc_402C3B
00402C1E  8b 8e 80 00 00 00                             mov     ecx, [esi+80h]
00402C24  33 c0                                         xor     eax, eax
00402C26  8a 86 b5 00 00 00                             mov     al, [esi+0B5h]
00402C2C  50                                            push    eax; wParam
00402C2D  68 86 01 00 00                                push    186h; Msg
00402C32  51                                            push    ecx; hWnd
00402C33  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
00402C39  5e                                            pop     esi
00402C3A  c3                                            retn
00402C3B  8b 96 80 00 00 00                             mov     edx, [esi+80h]
00402C41  6a 00                                         push    0; wParam
00402C43  68 88 01 00 00                                push    188h; Msg
00402C48  52                                            push    edx; hWnd
00402C49  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
00402C4F  8b ce                                         mov     ecx, esi
00402C51  88 86 b5 00 00 00                             mov     [esi+0B5h], al
00402C57  e8 e4 fe ff ff                                call    sub_402B40
00402C5C  5e                                            pop     esi
00402C5D  c3                                            retn
