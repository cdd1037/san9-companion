; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423E7C; baseline game VA=0x004B4E4B; size=5
; Relative branch annotations use the baseline game destination.
004B4E4B [00423E7C] e8 b0 e6 be ff                               call    near ptr 12531h ; game-relative-target=0x000A3500
