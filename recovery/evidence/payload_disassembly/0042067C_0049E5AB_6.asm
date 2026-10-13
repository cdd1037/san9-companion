; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042067C; baseline game VA=0x0049E5AB; size=6
; Relative branch annotations use the baseline game destination.
0049E5AB [0042067C] e8 50 1a c0 ff                               call    near ptr 220D1h ; game-relative-target=0x000A0000
0049E5B0 [00420681] 42                                           inc     edx
