; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A130; baseline game VA=0x0049575D; size=5
; Relative branch annotations use the baseline game destination.
0049575D [0042A130] e8 4e 2b c1 ff                               call    near ptr 3CC83h ; game-relative-target=0x000A82B0
