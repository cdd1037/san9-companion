; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425B58; baseline game VA=0x0048879A; size=5
; Relative branch annotations use the baseline game destination.
0048879A [00425B58] e8 61 cf c1 ff                               call    near ptr 42ABEh ; game-relative-target=0x000A5700
