; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427F10; baseline game VA=0x0044B235; size=5
; Relative branch annotations use the baseline game destination.
0044B235 [00427F10] e8 ae 55 c5 ff                               call    near ptr 7D4C3h ; game-relative-target=0x000A07E8
