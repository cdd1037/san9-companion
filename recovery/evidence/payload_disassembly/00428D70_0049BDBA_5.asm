; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428D70; baseline game VA=0x0049BDBA; size=5
; Relative branch annotations use the baseline game destination.
0049BDBA [00428D70] e8 81 bb c0 ff                               call    near ptr 348F6h ; game-relative-target=0x000A7940
