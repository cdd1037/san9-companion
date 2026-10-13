; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428438; baseline game VA=0x000A74D0; size=47
; Relative branch annotations use the baseline game destination.
000A74D0 [00428438] 8b 46 74                                     mov     eax, [esi+74h]
000A74D3 [0042843B] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A74D7 [0042843F] 74 13                                        jz      short near ptr unk_428454 ; game-relative-target=0x000A74EC
000A74D9 [00428441] 8b 84 24 fc 00 00 00                         mov     eax, [esp+0FCh]
000A74E0 [00428448] 8b 80 cc 00 00 00                            mov     eax, [eax+0CCh]
000A74E6 [0042844E] f6 40 0d 01                                  test    byte ptr [eax+0Dh], 1
000A74EA [00428452] 74 04                                        jz      short near ptr unk_428458 ; game-relative-target=0x000A74F0
000A74EC [00428454] 8b 46 30                                     mov     eax, [esi+30h]
000A74EF [00428457] c3                                           retn
000A74F0 [00428458] 8d 44 24 60                                  lea     eax, [esp+60h]
000A74F4 [0042845C] 50                                           push    eax
000A74F5 [0042845D] 8b ce                                        mov     ecx, esi
000A74F7 [0042845F] b8 00 75 0a 00                               mov     eax, 0A7500h
000A74FC [00428464] ff d0                                        call    eax
000A74FE [00428466] c3                                           retn
