; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428AD0; baseline game VA=0x0048312D; size=6
; Relative branch annotations use the baseline game destination.
0048312D [00428AD0] 5e                                           pop     esi
0048312E [00428AD1] e9 5d cd ff ff                               jmp     near ptr off_425830+3 ; game-relative-target=0x0047FE90
