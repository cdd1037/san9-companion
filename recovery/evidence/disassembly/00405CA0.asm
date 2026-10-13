00405CA0  56                                            push    esi
00405CA1  8b f1                                         mov     esi, ecx
00405CA3  e8 08 f4 ff ff                                call    sub_4050B0
00405CA8  85 c0                                         test    eax, eax
00405CAA  74 14                                         jz      short loc_405CC0
00405CAC  0f bf 86 46 01 00 00                          movsx   eax, word ptr [esi+146h]
00405CB3  8b ce                                         mov     ecx, esi; this
00405CB5  89 86 58 01 00 00                             mov     [esi+158h], eax
00405CBB  e8 70 f4 ff ff                                call    sub_405130
00405CC0  5e                                            pop     esi
00405CC1  c3                                            retn
