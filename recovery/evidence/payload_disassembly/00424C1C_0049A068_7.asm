; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424C1C; baseline game VA=0x0049A068; size=7
; Relative branch annotations use the baseline game destination.
0049A068 [00424C1C] e8 c2 94 c0 ff                               call    near ptr 2E0E3h ; game-relative-target=0x000A352F
0049A06D [00424C21] 90                                           nop
0049A06E [00424C22] 90                                           nop
