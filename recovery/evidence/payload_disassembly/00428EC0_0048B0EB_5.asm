; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428EC0; baseline game VA=0x0048B0EB; size=5
; Relative branch annotations use the baseline game destination.
0048B0EB [00428EC0] e8 10 56 c1 ff                               call    near ptr 3E4D5h ; game-relative-target=0x000A0700
