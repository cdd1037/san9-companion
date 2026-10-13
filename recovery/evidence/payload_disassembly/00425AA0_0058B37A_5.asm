; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425AA0; baseline game VA=0x0058B37A; size=5
; Relative branch annotations use the baseline game destination.
0058B37A [00425AA0] e8 51 a3 b1 ff                               call    near ptr 0FFF3FDF6h ; game-relative-target=0x000A56D0
