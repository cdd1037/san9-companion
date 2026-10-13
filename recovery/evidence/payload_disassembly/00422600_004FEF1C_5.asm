; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422600; baseline game VA=0x004FEF1C; size=5
; Relative branch annotations use the baseline game destination.
004FEF1C [00422600] e8 5f 29 ba ff                               call    near ptr 0FFFC4F64h ; game-relative-target=0x000A1880
