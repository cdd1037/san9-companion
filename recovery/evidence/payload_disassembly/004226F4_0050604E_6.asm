; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004226F4; baseline game VA=0x0050604E; size=6
; Relative branch annotations use the baseline game destination.
0050604E [004226F4] e8 ad c0 b9 ff                               call    near ptr 0FFFBE7A6h ; game-relative-target=0x000A2100
00506053 [004226F9] 42                                           inc     edx
