; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427FA4; baseline game VA=0x0045869C; size=5
; Relative branch annotations use the baseline game destination.
0045869C [00427FA4] e8 5f f4 c4 ff                               call    near ptr 77408h ; game-relative-target=0x000A7B00
