; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420520; baseline game VA=0x004897BD; size=6
; Relative branch annotations use the baseline game destination.
004897BD [00420520] e8 d1 58 fc ff                               call    near ptr 3E5DF6h ; game-relative-target=0x0044F093
004897C2 [00420525] 42                                           inc     edx
