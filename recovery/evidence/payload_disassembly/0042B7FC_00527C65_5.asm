; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B7FC; baseline game VA=0x00527C65; size=5
; Relative branch annotations use the baseline game destination.
00527C65 [0042B7FC] e8 c6 1f b8 ff                               call    near ptr 0FFFAD7C7h ; game-relative-target=0x000A9C30
