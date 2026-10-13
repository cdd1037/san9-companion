; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429CF0; baseline game VA=0x004DC2D8; size=5
; Relative branch annotations use the baseline game destination.
004DC2D8 [00429CF0] e8 4b be bc ff                               call    near ptr 0FFFF5B40h ; game-relative-target=0x000A8128
