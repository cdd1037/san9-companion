; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004298F0; baseline game VA=0x0045B1E5; size=5
; Relative branch annotations use the baseline game destination.
0045B1E5 [004298F0] e8 5e 65 c4 ff                               call    near ptr 6FE53h ; game-relative-target=0x000A1748
