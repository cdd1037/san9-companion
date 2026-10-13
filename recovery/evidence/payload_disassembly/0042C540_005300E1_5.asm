; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C540; baseline game VA=0x005300E1; size=5
; Relative branch annotations use the baseline game destination.
005300E1 [0042C540] e8 ca a6 b7 ff                               call    near ptr 0FFFA6C0Fh ; game-relative-target=0x000AA7B0
