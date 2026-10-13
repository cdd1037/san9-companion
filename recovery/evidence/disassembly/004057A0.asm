004057A0  56                                            push    esi
004057A1  8b f1                                         mov     esi, ecx
004057A3  e8 08 f9 ff ff                                call    sub_4050B0
004057A8  85 c0                                         test    eax, eax
004057AA  74 22                                         jz      short loc_4057CE
004057AC  8b ce                                         mov     ecx, esi
004057AE  e8 cd fc ff ff                                call    sub_405480
004057B3  85 c0                                         test    eax, eax
004057B5  74 17                                         jz      short loc_4057CE
004057B7  8b 86 54 7b 00 00                             mov     eax, [esi+7B54h]
004057BD  66 8b 8e 50 01 00 00                          mov     cx, [esi+150h]
004057C4  66 89 08                                      mov     [eax], cx
004057C7  8b ce                                         mov     ecx, esi; this
004057C9  e8 aa 4e 01 00                                call    ?OnOK@CDialog@@MAEXXZ; CDialog::OnOK(void)
004057CE  5e                                            pop     esi
004057CF  c3                                            retn
004057D0  56                                            push    esi
004057D1  8b f1                                         mov     esi, ecx
004057D3  e8 d8 f8 ff ff                                call    sub_4050B0
004057D8  85 c0                                         test    eax, eax
004057DA  6a 00                                         push    0; lParam
004057DC  75 1b                                         jnz     short loc_4057F9
004057DE  8b 86 58 01 00 00                             mov     eax, [esi+158h]
004057E4  8b 8e 80 00 00 00                             mov     ecx, [esi+80h]
004057EA  50                                            push    eax; wParam
004057EB  68 86 01 00 00                                push    186h; Msg
004057F0  51                                            push    ecx; hWnd
004057F1  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
004057F7  5e                                            pop     esi
004057F8  c3                                            retn
004057F9  8b 96 80 00 00 00                             mov     edx, [esi+80h]
004057FF  6a 00                                         push    0; wParam
00405801  68 88 01 00 00                                push    188h; Msg
00405806  52                                            push    edx; hWnd
00405807  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
0040580D  8b ce                                         mov     ecx, esi; this
0040580F  89 86 58 01 00 00                             mov     [esi+158h], eax
00405815  e8 16 f9 ff ff                                call    sub_405130
0040581A  5e                                            pop     esi
0040581B  c3                                            retn
