; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042596C; baseline game VA=0x004C1A05; size=5
; Relative branch annotations use the baseline game destination.
004C1A05 [0042596C] e8 c6 05 be ff                               call    near ptr 5F37h ; game-relative-target=0x000A1FD0
