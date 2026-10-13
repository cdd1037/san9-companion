; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A18C; baseline game VA=0x00485E17; size=5
; Relative branch annotations use the baseline game destination.
00485E17 [0042A18C] e8 04 25 c2 ff                               call    near ptr 4C695h ; game-relative-target=0x000A8320
