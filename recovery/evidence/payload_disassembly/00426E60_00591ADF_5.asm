; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426E60; baseline game VA=0x00591ADF; size=5
; Relative branch annotations use the baseline game destination.
00591ADF [00426E60] e8 8c 20 ed ff                               call    near ptr 2F8EF1h ; game-relative-target=0x00463B70
