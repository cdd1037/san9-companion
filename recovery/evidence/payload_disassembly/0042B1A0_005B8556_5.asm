; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B1A0; baseline game VA=0x005B8556; size=5
; Relative branch annotations use the baseline game destination.
005B8556 [0042B1A0] e8 b5 0b af ff                               call    near ptr 0FFF1BD5Ah ; game-relative-target=0x000A9110
