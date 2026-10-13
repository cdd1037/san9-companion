; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042354C; baseline game VA=0x004B4DF2; size=7
; Relative branch annotations use the baseline game destination.
004B4DF2 [0042354C] 8b e8                                        mov     ebp, eax
004B4DF4 [0042354E] e8 d7 05 f8 ff                               call    near ptr 3A3B2Ah ; game-relative-target=0x004353D0
