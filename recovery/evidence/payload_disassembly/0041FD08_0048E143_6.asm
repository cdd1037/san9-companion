; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041FD08; baseline game VA=0x0048E143; size=6
; Relative branch annotations use the baseline game destination.
0048E143 [0041FD08] e8 dc 38 fd ff                               call    near ptr 3F35E9h ; game-relative-target=0x00461A24
0048E148 [0041FD0D] 90                                           nop
