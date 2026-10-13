; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429FA8; baseline game VA=0x004DB3EB; size=5
; Relative branch annotations use the baseline game destination.
004DB3EB [00429FA8] e8 10 ce bc ff                               call    near ptr 0FFFF6DBDh ; game-relative-target=0x000A8200
