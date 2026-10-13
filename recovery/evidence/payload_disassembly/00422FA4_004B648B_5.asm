; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422FA4; baseline game VA=0x004B648B; size=5
; Relative branch annotations use the baseline game destination.
004B648B [00422FA4] e8 48 d9 be ff                               call    near ptr 108F1h ; game-relative-target=0x000A3DD8
