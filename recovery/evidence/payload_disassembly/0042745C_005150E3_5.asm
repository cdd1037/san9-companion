; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042745C; baseline game VA=0x005150E3; size=5
; Relative branch annotations use the baseline game destination.
005150E3 [0042745C] e8 78 9a f5 ff                               call    near ptr 380ED9h ; game-relative-target=0x0046EB60
