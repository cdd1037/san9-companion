; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B3D0; baseline game VA=0x00419000; size=5
; Relative branch annotations use the baseline game destination.
00419000 [0042B3D0] e8 6b fc 00 00                               call    near ptr 43B040h ; game-relative-target=0x00428C70
