; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423E70; baseline game VA=0x000A3500; size=12
; Relative branch annotations use the baseline game destination.
000A3500 [00423E70] 3b b7 88 00 00 00                            cmp     esi, [edi+88h]
000A3506 [00423E76] 75 01                                        jnz     short near ptr unk_423E79 ; game-relative-target=0x000A3509
000A3508 [00423E78] 4e                                           dec     esi
000A3509 [00423E79] 33 c0                                        xor     eax, eax
000A350B [00423E7B] c3                                           retn
