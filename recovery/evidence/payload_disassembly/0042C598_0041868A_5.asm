; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C598; baseline game VA=0x0041868A; size=5
; Relative branch annotations use the baseline game destination.
0041868A [0042C598] e8 41 9f c8 ff                               call    near ptr 0B64DEh ; game-relative-target=0x000A25D0
