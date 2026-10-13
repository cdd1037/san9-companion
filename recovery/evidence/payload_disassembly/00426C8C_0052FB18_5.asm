; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426C8C; baseline game VA=0x0052FB18; size=5
; Relative branch annotations use the baseline game destination.
0052FB18 [00426C8C] e8 e3 76 b7 ff                               call    near ptr 0FFF9E374h ; game-relative-target=0x000A7200
