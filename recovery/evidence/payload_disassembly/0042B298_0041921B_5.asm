; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B298; baseline game VA=0x0041921B; size=5
; Relative branch annotations use the baseline game destination.
0041921B [0042B298] e8 50 fa 00 00                               call    near ptr 43ACEDh ; game-relative-target=0x00428C70
