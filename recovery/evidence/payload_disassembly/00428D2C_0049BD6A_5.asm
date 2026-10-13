; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428D2C; baseline game VA=0x0049BD6A; size=5
; Relative branch annotations use the baseline game destination.
0049BD6A [00428D2C] e8 d1 bb c0 ff                               call    near ptr 34902h ; game-relative-target=0x000A7940
