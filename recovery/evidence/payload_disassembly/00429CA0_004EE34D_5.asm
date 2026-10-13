; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429CA0; baseline game VA=0x004EE34D; size=5
; Relative branch annotations use the baseline game destination.
004EE34D [00429CA0] e8 8e 9d bb ff                               call    near ptr 0FFFE3A33h ; game-relative-target=0x000A80E0
