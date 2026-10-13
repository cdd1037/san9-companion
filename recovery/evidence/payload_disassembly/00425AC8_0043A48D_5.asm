; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425AC8; baseline game VA=0x0043A48D; size=5
; Relative branch annotations use the baseline game destination.
0043A48D [00425AC8] e8 3e b2 c6 ff                               call    near ptr 90D0Bh ; game-relative-target=0x000A56D0
