; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426FA0; baseline game VA=0x00474E73; size=5
; Relative branch annotations use the baseline game destination.
00474E73 [00426FA0] e8 28 d0 fc ff                               call    near ptr 3F3FCDh ; game-relative-target=0x00441EA0
