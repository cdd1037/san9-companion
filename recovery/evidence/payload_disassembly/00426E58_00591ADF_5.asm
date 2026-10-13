; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426E58; baseline game VA=0x00591ADF; size=5
; Relative branch annotations use the baseline game destination.
00591ADF [00426E58] e8 1c 4a b1 ff                               call    near ptr 0FFF3B879h ; game-relative-target=0x000A6500
