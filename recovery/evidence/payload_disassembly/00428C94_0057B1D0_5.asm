; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428C94; baseline game VA=0x0057B1D0; size=5
; Relative branch annotations use the baseline game destination.
0057B1D0 [00428C94] e9 6b c6 b2 ff                               jmp     near ptr 0FFF55304h ; game-relative-target=0x000A7840
