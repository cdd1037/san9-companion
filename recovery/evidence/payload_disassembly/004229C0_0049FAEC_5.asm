; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004229C0; baseline game VA=0x0049FAEC; size=5
; Relative branch annotations use the baseline game destination.
0049FAEC [004229C0] e8 3f 2b c0 ff                               call    near ptr 25504h ; game-relative-target=0x000A2630
