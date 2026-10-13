; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426E14; baseline game VA=0x004339CC; size=6
; Relative branch annotations use the baseline game destination.
004339CC [00426E14] e8 1f 2b c7 ff                               call    near ptr 99938h ; game-relative-target=0x000A64F0
004339D1 [00426E19] 42                                           inc     edx
