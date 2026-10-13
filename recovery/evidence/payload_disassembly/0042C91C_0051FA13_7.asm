; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C91C; baseline game VA=0x0051FA13; size=7
; Relative branch annotations use the baseline game destination.
0051FA13 [0042C91C] e8 38 a0 b8 ff                               call    near ptr 0FFFB6959h ; game-relative-target=0x000A9A50
0051FA18 [0042C921] 33 d2                                        xor     edx, edx
