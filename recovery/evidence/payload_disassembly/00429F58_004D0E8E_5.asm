; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429F58; baseline game VA=0x004D0E8E; size=5
; Relative branch annotations use the baseline game destination.
004D0E8E [00429F58] e8 6d 73 bd ff                               call    near ptr 12CAh ; game-relative-target=0x000A8200
