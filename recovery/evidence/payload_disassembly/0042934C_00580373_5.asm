; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042934C; baseline game VA=0x00580373; size=5
; Relative branch annotations use the baseline game destination.
00580373 [0042934C] e8 50 79 b2 ff                               call    near ptr 0FFF50CA1h ; game-relative-target=0x000A7CC8
