; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042106C; baseline game VA=0x004B0379; size=7
; Relative branch annotations use the baseline game destination.
004B0379 [0042106C] e8 82 0b bf ff                               call    near ptr 11BF3h ; game-relative-target=0x000A0F00
004B037E [00421071] 42                                           inc     edx
004B037F [00421072] 42                                           inc     edx
