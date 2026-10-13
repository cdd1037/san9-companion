; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427150; baseline game VA=0x0052951A; size=5
; Relative branch annotations use the baseline game destination.
0052951A [00427150] e8 71 da b7 ff                               call    near ptr 0FFFA4BC6h ; game-relative-target=0x000A6F90
