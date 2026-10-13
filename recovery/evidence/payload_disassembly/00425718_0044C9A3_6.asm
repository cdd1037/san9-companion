; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425718; baseline game VA=0x0044C9A3; size=6
; Relative branch annotations use the baseline game destination.
0044C9A3 [00425718] e8 e8 57 c5 ff                               call    near ptr 7AF05h ; game-relative-target=0x000A2190
0044C9A8 [0042571D] 41                                           inc     ecx
