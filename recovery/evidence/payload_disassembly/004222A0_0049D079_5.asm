; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004222A0; baseline game VA=0x0049D079; size=5
; Relative branch annotations use the baseline game destination.
0049D079 [004222A0] e8 82 4f c0 ff                               call    near ptr 27227h ; game-relative-target=0x000A2000
