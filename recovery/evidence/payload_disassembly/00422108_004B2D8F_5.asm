; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422108; baseline game VA=0x004B2D8F; size=5
; Relative branch annotations use the baseline game destination.
004B2D8F [00422108] e8 dc ee be ff                               call    near ptr 10FE9h ; game-relative-target=0x000A1C70
