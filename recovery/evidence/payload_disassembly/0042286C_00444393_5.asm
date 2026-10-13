; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042286C; baseline game VA=0x00444393; size=5
; Relative branch annotations use the baseline game destination.
00444393 [0042286C] e8 a8 18 c6 ff                               call    near ptr 84119h ; game-relative-target=0x000A5C40
