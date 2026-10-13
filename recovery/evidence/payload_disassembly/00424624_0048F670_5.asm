; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424624; baseline game VA=0x0048F670; size=5
; Relative branch annotations use the baseline game destination.
0048F670 [00424624] e8 b7 40 c1 ff                               call    near ptr 386E0h ; game-relative-target=0x000A372C
