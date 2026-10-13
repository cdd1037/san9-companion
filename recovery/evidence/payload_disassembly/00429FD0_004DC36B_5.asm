; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429FD0; baseline game VA=0x004DC36B; size=5
; Relative branch annotations use the baseline game destination.
004DC36B [00429FD0] e8 90 be bc ff                               call    near ptr 0FFFF5E65h ; game-relative-target=0x000A8200
