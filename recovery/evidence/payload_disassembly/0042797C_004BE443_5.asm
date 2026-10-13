; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042797C; baseline game VA=0x004BE443; size=5
; Relative branch annotations use the baseline game destination.
004BE443 [0042797C] e8 18 78 be ff                               call    near ptr 0F199h ; game-relative-target=0x000A5C60
