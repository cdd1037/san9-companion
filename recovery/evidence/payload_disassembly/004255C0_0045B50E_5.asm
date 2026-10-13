; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004255C0; baseline game VA=0x0045B50E; size=5
; Relative branch annotations use the baseline game destination.
0045B50E [004255C0] e8 d5 9a c4 ff                               call    near ptr 6F09Ah ; game-relative-target=0x000A4FE8
