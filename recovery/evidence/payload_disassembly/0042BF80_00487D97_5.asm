; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042BF80; baseline game VA=0x00487D97; size=5
; Relative branch annotations use the baseline game destination.
00487D97 [0042BF80] e8 c4 25 c2 ff                               call    near ptr 4E549h ; game-relative-target=0x000AA360
