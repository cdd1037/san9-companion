; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041FE60; baseline game VA=0x00460ABA; size=5
; Relative branch annotations use the baseline game destination.
00460ABA [0041FE60] e8 45 e8 01 00                               call    near ptr 43E6AAh ; game-relative-target=0x0047F304
