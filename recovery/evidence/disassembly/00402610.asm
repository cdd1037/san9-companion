00402610  56                                            push    esi
00402611  8b f1                                         mov     esi, ecx
00402613  6a 01                                         push    1
00402615  8b 8e f0 00 00 00                             mov     ecx, [esi+0F0h]
0040261B  e8 c0 75 01 00                                call    sub_419BE0
00402620  8b 86 f0 00 00 00                             mov     eax, [esi+0F0h]
00402626  8b 88 3c 11 00 00                             mov     ecx, [eax+113Ch]
0040262C  c6 86 f5 00 00 00 00                          mov     byte ptr [esi+0F5h], 0
00402633  89 8e c4 00 00 00                             mov     [esi+0C4h], ecx
00402639  8b ce                                         mov     ecx, esi; this
0040263B  e8 60 fa ff ff                                call    sub_4020A0
00402640  5e                                            pop     esi
00402641  c3                                            retn
