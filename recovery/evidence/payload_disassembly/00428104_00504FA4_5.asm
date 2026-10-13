; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428104; baseline game VA=0x00504FA4; size=5
; Relative branch annotations use the baseline game destination.
00504FA4 [00428104] e8 97 fd b9 ff                               call    near ptr 0FFFC7EA0h ; game-relative-target=0x000A4D40
