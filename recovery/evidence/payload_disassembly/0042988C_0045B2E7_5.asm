; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042988C; baseline game VA=0x0045B2E7; size=5
; Relative branch annotations use the baseline game destination.
0045B2E7 [0042988C] e8 3c cc c4 ff                               call    near ptr 764CDh ; game-relative-target=0x000A7F28
