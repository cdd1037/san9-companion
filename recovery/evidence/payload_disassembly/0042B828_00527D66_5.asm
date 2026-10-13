; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B828; baseline game VA=0x00527D66; size=5
; Relative branch annotations use the baseline game destination.
00527D66 [0042B828] e8 c5 1e b8 ff                               call    near ptr 0FFFAD6F2h ; game-relative-target=0x000A9C30
