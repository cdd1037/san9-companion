00418700  56                                            push    esi
00418701  8b f1                                         mov     esi, ecx
00418703  e8 38 c7 ff ff                                call    sub_414E40
00418708  8b 46 68                                      mov     eax, [esi+68h]
0041870B  85 c0                                         test    eax, eax
0041870D  74 0b                                         jz      short loc_41871A
0041870F  50                                            push    eax; uIDEvent
00418710  8b 46 20                                      mov     eax, [esi+20h]
00418713  50                                            push    eax; hWnd
00418714  ff 15 54 c3 41 00                             call    ds:KillTimer; USER32
0041871A  8b ce                                         mov     ecx, esi; this
0041871C  e8 b3 1d 00 00                                call    ?OnCancel@CDialog@@MAEXXZ; CDialog::OnCancel(void)
00418721  5e                                            pop     esi
00418722  c3                                            retn
