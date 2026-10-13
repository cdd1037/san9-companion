; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042426C; baseline game VA=0x004587F4; size=5
; Relative branch annotations use the baseline game destination.
004587F4 [0042426C] e8 b7 ad c4 ff                               call    near ptr 6F028h ; game-relative-target=0x000A35B0
