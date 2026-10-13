; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042337C; baseline game VA=0x004B65B4; size=6
; Relative branch annotations use the baseline game destination.
004B65B4 [0042337C] e8 47 b7 be ff                               call    near ptr 0EAC8h ; game-relative-target=0x000A1D00
004B65B9 [00423381] 90                                           nop
