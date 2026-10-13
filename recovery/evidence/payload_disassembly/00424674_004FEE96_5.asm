; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424674; baseline game VA=0x004FEE96; size=5
; Relative branch annotations use the baseline game destination.
004FEE96 [00424674] e8 41 4b ba ff                               call    near ptr 0FFFC91BAh ; game-relative-target=0x000A39DC
