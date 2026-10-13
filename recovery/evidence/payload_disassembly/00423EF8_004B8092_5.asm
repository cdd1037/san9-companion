; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423EF8; baseline game VA=0x004B8092; size=5
; Relative branch annotations use the baseline game destination.
004B8092 [00423EF8] e8 69 a1 be ff                               call    near ptr 0E066h ; game-relative-target=0x000A2200
