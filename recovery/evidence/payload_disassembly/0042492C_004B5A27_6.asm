; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042492C; baseline game VA=0x004B5A27; size=6
; Relative branch annotations use the baseline game destination.
004B5A27 [0042492C] e8 d4 df be ff                               call    near ptr 12905h ; game-relative-target=0x000A3A00
004B5A2C [00424931] 90                                           nop
