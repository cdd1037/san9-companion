; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421504; baseline game VA=0x0050F16E; size=5
; Relative branch annotations use the baseline game destination.
0050F16E [00421504] e8 8d 1e b9 ff                               call    near ptr 0FFFB3396h ; game-relative-target=0x000A1000
