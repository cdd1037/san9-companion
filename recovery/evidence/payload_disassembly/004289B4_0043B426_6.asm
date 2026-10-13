; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004289B4; baseline game VA=0x0043B426; size=6
; Relative branch annotations use the baseline game destination.
0043B426 [004289B4] e8 15 9a c6 ff                               call    near ptr 923CEh ; game-relative-target=0x000A4E40
0043B42B [004289B9] 90                                           nop
