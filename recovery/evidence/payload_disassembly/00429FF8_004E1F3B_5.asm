; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429FF8; baseline game VA=0x004E1F3B; size=5
; Relative branch annotations use the baseline game destination.
004E1F3B [00429FF8] e8 c0 62 bc ff                               call    near ptr 0FFFF02BDh ; game-relative-target=0x000A8200
