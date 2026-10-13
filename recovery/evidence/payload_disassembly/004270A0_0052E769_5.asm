; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004270A0; baseline game VA=0x0052E769; size=5
; Relative branch annotations use the baseline game destination.
0052E769 [004270A0] e8 92 85 b7 ff                               call    near ptr 0FFF9F637h ; game-relative-target=0x000A6D00
