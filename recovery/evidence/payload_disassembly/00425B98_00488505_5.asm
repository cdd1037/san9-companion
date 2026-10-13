; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425B98; baseline game VA=0x00488505; size=5
; Relative branch annotations use the baseline game destination.
00488505 [00425B98] e8 0e d2 c1 ff                               call    near ptr 42DABh ; game-relative-target=0x000A5718
