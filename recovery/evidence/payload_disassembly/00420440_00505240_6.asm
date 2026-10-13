; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420440; baseline game VA=0x00505240; size=6
; Relative branch annotations use the baseline game destination.
00505240 [00420440] e8 6b b0 b9 ff                               call    near ptr 0FFFBB4B0h ; game-relative-target=0x000A02B0
00505245 [00420445] 41                                           inc     ecx
