; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429CC8; baseline game VA=0x004E11F2; size=5
; Relative branch annotations use the baseline game destination.
004E11F2 [00429CC8] e8 c9 6e bc ff                               call    near ptr 0FFFF0B96h ; game-relative-target=0x000A80C0
