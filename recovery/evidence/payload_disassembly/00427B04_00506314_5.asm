; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427B04; baseline game VA=0x00506314; size=5
; Relative branch annotations use the baseline game destination.
00506314 [00427B04] e8 e7 da b9 ff                               call    near ptr 0FFFC55F0h ; game-relative-target=0x000A3E00
