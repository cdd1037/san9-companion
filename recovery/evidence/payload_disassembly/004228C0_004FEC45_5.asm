; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004228C0; baseline game VA=0x004FEC45; size=5
; Relative branch annotations use the baseline game destination.
004FEC45 [004228C0] e8 36 38 ba ff                               call    near ptr 0FFFC60FBh ; game-relative-target=0x000A2480
