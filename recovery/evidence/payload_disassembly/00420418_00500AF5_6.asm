; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420418; baseline game VA=0x00500AF5; size=6
; Relative branch annotations use the baseline game destination.
00500AF5 [00420418] e8 b6 f7 b9 ff                               call    near ptr 0FFFBFBD3h ; game-relative-target=0x000A02B0
00500AFA [0042041D] 41                                           inc     ecx
