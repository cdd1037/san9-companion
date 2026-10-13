; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004246C0; baseline game VA=0x00503525; size=5
; Relative branch annotations use the baseline game destination.
00503525 [004246C0] e8 e6 ff b9 ff                               call    near ptr 0FFFC46ABh ; game-relative-target=0x000A3510
