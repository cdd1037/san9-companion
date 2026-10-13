; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C9F0; baseline game VA=0x005218BD; size=5
; Relative branch annotations use the baseline game destination.
005218BD [0042C9F0] e8 1e 83 b8 ff                               call    near ptr 0FFFB4D13h ; game-relative-target=0x000A9BE0
