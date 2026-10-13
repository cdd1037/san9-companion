; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428650; baseline game VA=0x004869AA; size=5
; Relative branch annotations use the baseline game destination.
004869AA [00428650] e8 01 0c c2 ff                               call    near ptr 49256h ; game-relative-target=0x000A75B0
