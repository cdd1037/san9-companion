; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428848; baseline game VA=0x0043B419; size=6
; Relative branch annotations use the baseline game destination.
0043B419 [00428848] e8 8a c5 c6 ff                               call    near ptr 94DD7h ; game-relative-target=0x000A79A8
0043B41E [0042884D] 41                                           inc     ecx
