; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428B64; baseline game VA=0x0050ECDC; size=5
; Relative branch annotations use the baseline game destination.
0050ECDC [00428B64] e8 2f bf f5 ff                               call    near ptr 384A98h ; game-relative-target=0x0046AC10
