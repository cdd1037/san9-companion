00405C70  56                                            push    esi
00405C71  8b f1                                         mov     esi, ecx
00405C73  e8 38 f4 ff ff                                call    sub_4050B0
00405C78  85 c0                                         test    eax, eax
00405C7A  74 14                                         jz      short loc_405C90
00405C7C  0f bf 86 44 01 00 00                          movsx   eax, word ptr [esi+144h]
00405C83  8b ce                                         mov     ecx, esi; this
00405C85  89 86 58 01 00 00                             mov     [esi+158h], eax
00405C8B  e8 a0 f4 ff ff                                call    sub_405130
00405C90  5e                                            pop     esi
00405C91  c3                                            retn
