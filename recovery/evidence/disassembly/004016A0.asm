004016A0  56                                            push    esi
004016A1  8b f1                                         mov     esi, ecx
004016A3  e8 c8 fe ff ff                                call    sub_401570
004016A8  85 c0                                         test    eax, eax
004016AA  6a 00                                         push    0; lParam
004016AC  75 1d                                         jnz     short loc_4016CB
004016AE  8b 8e 80 00 00 00                             mov     ecx, [esi+80h]
004016B4  33 c0                                         xor     eax, eax
004016B6  8a 86 cd 00 00 00                             mov     al, [esi+0CDh]
004016BC  50                                            push    eax; wParam
004016BD  68 86 01 00 00                                push    186h; Msg
004016C2  51                                            push    ecx; hWnd
004016C3  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
004016C9  5e                                            pop     esi
004016CA  c3                                            retn
004016CB  8b 96 80 00 00 00                             mov     edx, [esi+80h]
004016D1  6a 00                                         push    0; wParam
004016D3  68 88 01 00 00                                push    188h; Msg
004016D8  52                                            push    edx; hWnd
004016D9  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
004016DF  8b ce                                         mov     ecx, esi
004016E1  88 86 cd 00 00 00                             mov     [esi+0CDh], al
004016E7  e8 b4 fd ff ff                                call    sub_4014A0
004016EC  5e                                            pop     esi
004016ED  c3                                            retn
