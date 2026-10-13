; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042721C; baseline game VA=0x00508BC5; size=5
; Relative branch annotations use the baseline game destination.
00508BC5 [0042721C] e8 b6 4c 02 00                               call    near ptr 44BED7h ; game-relative-target=0x0052D880
