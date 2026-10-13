; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424A90; baseline game VA=0x0044E057; size=5
; Relative branch annotations use the baseline game destination.
0044E057 [00424A90] e8 24 46 c5 ff                               call    near ptr 790B9h ; game-relative-target=0x000A2680
