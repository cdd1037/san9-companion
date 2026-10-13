; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004245D8; baseline game VA=0x00525BDD; size=5
; Relative branch annotations use the baseline game destination.
00525BDD [004245D8] e8 e5 de 0a 00                               call    near ptr 4D24C2h ; game-relative-target=0x005D3AC7
