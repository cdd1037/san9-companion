; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427124; baseline game VA=0x00528CAF; size=5
; Relative branch annotations use the baseline game destination.
00528CAF [00427124] e8 dc e2 b7 ff                               call    near ptr 0FFFA5405h ; game-relative-target=0x000A6F90
