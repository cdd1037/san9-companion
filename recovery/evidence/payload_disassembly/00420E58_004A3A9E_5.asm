; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420E58; baseline game VA=0x004A3A9E; size=5
; Relative branch annotations use the baseline game destination.
004A3A9E [00420E58] e8 5d c8 bf ff                               call    near ptr 1D6BAh ; game-relative-target=0x000A0300
