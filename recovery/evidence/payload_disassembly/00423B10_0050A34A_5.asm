; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423B10; baseline game VA=0x0050A34A; size=5
; Relative branch annotations use the baseline game destination.
0050A34A [00423B10] e8 b1 90 b9 ff                               call    near ptr 0FFFBCBC6h ; game-relative-target=0x000A3400
