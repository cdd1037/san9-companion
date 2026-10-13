; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428F20; baseline game VA=0x0040BDCA; size=5
; Relative branch annotations use the baseline game destination.
0040BDCA [00428F20] e8 61 49 c9 ff                               call    near ptr 0BD886h ; game-relative-target=0x000A0730
