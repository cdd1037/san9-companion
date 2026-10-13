; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004295E4; baseline game VA=0x0048C030; size=5
; Relative branch annotations use the baseline game destination.
0048C030 [004295E4] e8 db c7 c1 ff                               call    near ptr 45DC4h ; game-relative-target=0x000A8810
