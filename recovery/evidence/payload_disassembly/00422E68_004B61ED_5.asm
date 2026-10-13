; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422E68; baseline game VA=0x004B61ED; size=5
; Relative branch annotations use the baseline game destination.
004B61ED [00422E68] e8 0e c6 be ff                               call    near ptr 0F47Bh ; game-relative-target=0x000A2800
