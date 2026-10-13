; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042203C; baseline game VA=0x004B2D1F; size=5
; Relative branch annotations use the baseline game destination.
004B2D1F [0042203C] e8 7c ef be ff                               call    near ptr 10FBDh ; game-relative-target=0x000A1CA0
