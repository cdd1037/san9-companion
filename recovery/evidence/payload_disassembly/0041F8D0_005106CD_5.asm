; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041F8D0; baseline game VA=0x005106CD; size=5
; Relative branch annotations use the baseline game destination.
005106CD [0041F8D0] e8 90 f1 f2 ff                               call    near ptr 34EA65h ; game-relative-target=0x0043F862
