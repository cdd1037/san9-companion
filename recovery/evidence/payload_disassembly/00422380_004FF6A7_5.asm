; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422380; baseline game VA=0x004FF6A7; size=5
; Relative branch annotations use the baseline game destination.
004FF6A7 [00422380] e8 84 26 ba ff                               call    near ptr 0FFFC4A09h ; game-relative-target=0x000A1D30
