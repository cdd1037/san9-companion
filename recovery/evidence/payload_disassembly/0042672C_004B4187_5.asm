; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042672C; baseline game VA=0x004B4187; size=5
; Relative branch annotations use the baseline game destination.
004B4187 [0042672C] e8 24 e4 be ff                               call    near ptr 14B55h ; game-relative-target=0x000A25B0
