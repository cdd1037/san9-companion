; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004237C0; baseline game VA=0x004B432B; size=5
; Relative branch annotations use the baseline game destination.
004B432B [004237C0] e8 b8 e3 be ff                               call    near ptr 11B7Dh ; game-relative-target=0x000A26E8
