; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425C60; baseline game VA=0x00598BDA; size=5
; Relative branch annotations use the baseline game destination.
00598BDA [00425C60] e8 c1 ca b0 ff                               call    near ptr 0FFF32726h ; game-relative-target=0x000A56A0
