; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425B2C; baseline game VA=0x0048874F; size=5
; Relative branch annotations use the baseline game destination.
0048874F [00425B2C] e8 ac cf c1 ff                               call    near ptr 42ADDh ; game-relative-target=0x000A5700
