; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425A78; baseline game VA=0x004CA548; size=5
; Relative branch annotations use the baseline game destination.
004CA548 [00425A78] e8 83 b1 bd ff                               call    near ptr 0C00h ; game-relative-target=0x000A56D0
