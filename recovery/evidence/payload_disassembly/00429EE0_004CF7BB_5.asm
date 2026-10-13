; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429EE0; baseline game VA=0x004CF7BB; size=5
; Relative branch annotations use the baseline game destination.
004CF7BB [00429EE0] e8 40 8a bd ff                               call    near ptr 2925h ; game-relative-target=0x000A8200
