00402C60  56                                            push    esi
00402C61  8b f1                                         mov     esi, ecx
00402C63  e8 48 ff ff ff                                call    sub_402BB0
00402C68  85 c0                                         test    eax, eax
00402C6A  74 07                                         jz      short loc_402C73
00402C6C  8b ce                                         mov     ecx, esi; this
00402C6E  e8 05 7a 01 00                                call    ?OnOK@CDialog@@MAEXXZ; CDialog::OnOK(void)
00402C73  5e                                            pop     esi
00402C74  c3                                            retn
