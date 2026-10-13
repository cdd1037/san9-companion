; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422570; baseline game VA=0x0049530E; size=5
; Relative branch annotations use the baseline game destination.
0049530E [00422570] e8 6d cc c0 ff                               call    near ptr 2F1E2h ; game-relative-target=0x000A1F80
