; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426014; baseline game VA=0x00451A5C; size=5
; Relative branch annotations use the baseline game destination.
00451A5C [00426014] e8 ff 4e c5 ff                               call    near ptr 7AF18h ; game-relative-target=0x000A6960
