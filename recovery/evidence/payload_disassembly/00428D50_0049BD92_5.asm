; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428D50; baseline game VA=0x0049BD92; size=5
; Relative branch annotations use the baseline game destination.
0049BD92 [00428D50] e8 a9 bb c0 ff                               call    near ptr 348FEh ; game-relative-target=0x000A7940
