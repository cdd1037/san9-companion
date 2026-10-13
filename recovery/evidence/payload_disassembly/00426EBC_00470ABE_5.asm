; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426EBC; baseline game VA=0x00470ABE; size=5
; Relative branch annotations use the baseline game destination.
00470ABE [00426EBC] e8 1d 60 c3 ff                               call    near ptr 5CEDEh ; game-relative-target=0x000A6AE0
