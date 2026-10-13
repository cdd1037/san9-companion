; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427B30; baseline game VA=0x005063AB; size=5
; Relative branch annotations use the baseline game destination.
005063AB [00427B30] e8 50 da b9 ff                               call    near ptr 0FFFC5585h ; game-relative-target=0x000A3E00
