; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425998; baseline game VA=0x0048865F; size=5
; Relative branch annotations use the baseline game destination.
0048865F [00425998] e8 6c 99 c1 ff                               call    near ptr 3F309h ; game-relative-target=0x000A1FD0
