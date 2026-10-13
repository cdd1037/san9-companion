; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422720; baseline game VA=0x000A2170; size=19
; Relative branch annotations use the baseline game destination.
000A2170 [00422720] 85 f6                                        test    esi, esi
000A2172 [00422722] 74 06                                        jz      short near ptr unk_42272A ; game-relative-target=0x000A217A
000A2174 [00422724] f6 46 34 01                                  test    byte ptr [esi+34h], 1
000A2178 [00422728] 75 06                                        jnz     short near ptr unk_422730 ; game-relative-target=0x000A2180
000A217A [0042272A] 68 40 58 40 00                               push    405840h
000A217F [0042272F] c3                                           retn
000A2180 [00422730] b0 01                                        mov     al, 1
000A2182 [00422732] c3                                           retn
