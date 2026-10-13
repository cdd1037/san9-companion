; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004222EC; baseline game VA=0x0052FA45; size=5
; Relative branch annotations use the baseline game destination.
0052FA45 [004222EC] e8 d6 1c b7 ff                               call    near ptr 0FFF93FC7h ; game-relative-target=0x000A1720
