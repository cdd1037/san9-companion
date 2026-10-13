; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004294A0; baseline game VA=0x004FFD51; size=7
; Relative branch annotations use the baseline game destination.
004FFD51 [004294A0] 56                                           push    esi
004FFD52 [004294A1] e8 29 80 ba ff                               call    near ptr 0FFFD14CFh ; game-relative-target=0x000A7D80
004FFD57 [004294A6] 5e                                           pop     esi
