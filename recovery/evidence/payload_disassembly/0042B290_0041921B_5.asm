; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B290; baseline game VA=0x0041921B; size=5
; Relative branch annotations use the baseline game destination.
0041921B [0042B290] e8 56 00 c9 ff                               call    near ptr 0BB2EBh ; game-relative-target=0x000A9276
