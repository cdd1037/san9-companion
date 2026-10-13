; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427B74; baseline game VA=0x004A188C; size=5
; Relative branch annotations use the baseline game destination.
004A188C [00427B74] e8 ef 25 c0 ff                               call    near ptr 2A168h ; game-relative-target=0x000A3E80
