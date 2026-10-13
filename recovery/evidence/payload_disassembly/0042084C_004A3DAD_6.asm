; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042084C; baseline game VA=0x004A3DAD; size=6
; Relative branch annotations use the baseline game destination.
004A3DAD [0042084C] e8 4e ca bf ff                               call    near ptr 1D29Fh ; game-relative-target=0x000A0800
004A3DB2 [00420851] 40                                           inc     eax
