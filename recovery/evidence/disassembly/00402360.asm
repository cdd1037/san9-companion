00402360  56                                            push    esi
00402361  8b f1                                         mov     esi, ecx
00402363  e8 58 fe ff ff                                call    sub_4021C0
00402368  85 c0                                         test    eax, eax
0040236A  74 19                                         jz      short loc_402385
0040236C  8b 86 f0 00 00 00                             mov     eax, [esi+0F0h]
00402372  8b 8e c4 00 00 00                             mov     ecx, [esi+0C4h]
00402378  89 88 3c 11 00 00                             mov     [eax+113Ch], ecx
0040237E  8b ce                                         mov     ecx, esi; this
00402380  e8 f3 82 01 00                                call    ?OnOK@CDialog@@MAEXXZ; CDialog::OnOK(void)
00402385  5e                                            pop     esi
00402386  c3                                            retn
