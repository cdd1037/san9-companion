; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004245D0; baseline game VA=0x00525BDD; size=5
; Relative branch annotations use the baseline game destination.
00525BDD [004245D0] e8 fe a5 b7 ff                               call    near ptr 0FFF9EBD3h ; game-relative-target=0x000A01E0
