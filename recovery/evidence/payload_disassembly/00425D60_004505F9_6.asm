; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425D60; baseline game VA=0x004505F9; size=6
; Relative branch annotations use the baseline game destination.
004505F9 [00425D60] e8 72 4f c5 ff                               call    near ptr 7ACD7h ; game-relative-target=0x000A5570
004505FE [00425D65] 41                                           inc     ecx
