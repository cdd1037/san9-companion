; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B868; baseline game VA=0x0051390F; size=5
; Relative branch annotations use the baseline game destination.
0051390F [0042B868] e8 9c 63 b9 ff                               call    near ptr 0FFFC1C09h ; game-relative-target=0x000A9CB0
