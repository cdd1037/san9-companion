; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429F80; baseline game VA=0x004D134B; size=5
; Relative branch annotations use the baseline game destination.
004D134B [00429F80] e8 b0 6e bd ff                               call    near ptr 0E35h ; game-relative-target=0x000A8200
