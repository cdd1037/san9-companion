; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423780; baseline game VA=0x004B4AF2; size=5
; Relative branch annotations use the baseline game destination.
004B4AF2 [00423780] e8 01 f4 be ff                               call    near ptr 12B86h ; game-relative-target=0x000A3EF8
