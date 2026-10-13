; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A108; baseline game VA=0x00485DB6; size=5
; Relative branch annotations use the baseline game destination.
00485DB6 [0042A108] e8 f5 24 c2 ff                               call    near ptr 4C602h ; game-relative-target=0x000A82B0
