; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429E90; baseline game VA=0x004ED0AE; size=5
; Relative branch annotations use the baseline game destination.
004ED0AE [00429E90] e8 4d b1 bb ff                               call    near ptr 0FFFE4FE2h ; game-relative-target=0x000A8200
