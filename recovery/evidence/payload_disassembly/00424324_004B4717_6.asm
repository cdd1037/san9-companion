; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424324; baseline game VA=0x004B4717; size=6
; Relative branch annotations use the baseline game destination.
004B4717 [00424324] e8 d0 ef be ff                               call    near ptr 132F9h ; game-relative-target=0x000A36EC
004B471C [00424329] 41                                           inc     ecx
