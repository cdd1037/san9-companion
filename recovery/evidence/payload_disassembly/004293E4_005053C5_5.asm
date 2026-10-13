; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004293E4; baseline game VA=0x005053C5; size=5
; Relative branch annotations use the baseline game destination.
005053C5 [004293E4] e8 8e 29 ba ff                               call    near ptr 0FFFCBD77h ; game-relative-target=0x000A7D58
