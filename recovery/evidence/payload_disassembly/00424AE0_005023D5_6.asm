; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424AE0; baseline game VA=0x005023D5; size=6
; Relative branch annotations use the baseline game destination.
005023D5 [00424AE0] e8 ae 0d ba ff                               call    near ptr 0FFFC5893h ; game-relative-target=0x000A3188
005023DA [00424AE5] 90                                           nop
