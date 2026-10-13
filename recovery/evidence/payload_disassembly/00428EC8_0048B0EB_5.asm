; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428EC8; baseline game VA=0x0048B0EB; size=5
; Relative branch annotations use the baseline game destination.
0048B0EB [00428EC8] e8 e0 bd 0d 00                               call    near ptr 504CADh ; game-relative-target=0x00566ED0
