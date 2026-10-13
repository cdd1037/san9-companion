; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425BD4; baseline game VA=0x0058B437; size=5
; Relative branch annotations use the baseline game destination.
0058B437 [00425BD4] e8 f4 a2 b1 ff                               call    near ptr 0FFF3FECDh ; game-relative-target=0x000A5730
