; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422AB0; baseline game VA=0x00493D47; size=5
; Relative branch annotations use the baseline game destination.
00493D47 [00422AB0] e8 14 e9 c0 ff                               call    near ptr 313C9h ; game-relative-target=0x000A2660
