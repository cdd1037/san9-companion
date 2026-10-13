; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428B28; baseline game VA=0x000A7800; size=51
; Relative branch annotations use the baseline game destination.
000A7800 [00428B28] 8b 41 3c                                     mov     eax, [ecx+3Ch]
000A7803 [00428B2B] 8b 40 08                                     mov     eax, [eax+8]
000A7806 [00428B2E] f6 40 72 08                                  test    byte ptr [eax+72h], 8
000A780A [00428B32] 74 0e                                        jz      short near ptr unk_428B42 ; game-relative-target=0x000A781A
000A780C [00428B34] 80 60 72 f7                                  and     byte ptr [eax+72h], 0F7h
000A7810 [00428B38] 80 48 34 01                                  or      byte ptr [eax+34h], 1
000A7814 [00428B3C] c6 40 24 00                                  mov     byte ptr [eax+24h], 0
000A7818 [00428B40] eb 13                                        jmp     short near ptr unk_428B55 ; game-relative-target=0x000A782D
000A781A [00428B42] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A781E [00428B46] 74 0d                                        jz      short near ptr unk_428B55 ; game-relative-target=0x000A782D
000A7820 [00428B48] 80 48 72 08                                  or      byte ptr [eax+72h], 8
000A7824 [00428B4C] 80 60 34 fe                                  and     byte ptr [eax+34h], 0FEh
000A7828 [00428B50] c6 40 24 01                                  mov     byte ptr [eax+24h], 1
000A782C [00428B54] c3                                           retn
000A782D [00428B55] 68 10 ac 46 00                               push    46AC10h
000A7832 [00428B5A] c3                                           retn
