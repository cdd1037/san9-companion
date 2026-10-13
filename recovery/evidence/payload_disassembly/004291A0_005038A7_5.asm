; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004291A0; baseline game VA=0x005038A7; size=5
; Relative branch annotations use the baseline game destination.
005038A7 [004291A0] e8 64 43 ba ff                               call    near ptr 0FFFCD509h ; game-relative-target=0x000A7C10
