; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429F30; baseline game VA=0x004E122B; size=5
; Relative branch annotations use the baseline game destination.
004E122B [00429F30] e8 d0 6f bc ff                               call    near ptr 0FFFF0F05h ; game-relative-target=0x000A8200
