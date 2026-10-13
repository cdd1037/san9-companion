; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041FEE8; baseline game VA=0x0049F9E6; size=9
; Relative branch annotations use the baseline game destination.
0049F9E6 [0041FEE8] 33 d2                                        xor     edx, edx
0049F9E8 [0041FEEA] e8 38 24 fc ff                               call    near ptr 3E2327h ; game-relative-target=0x00461E25
0049F9ED [0041FEEF] 3b c2                                        cmp     eax, edx
