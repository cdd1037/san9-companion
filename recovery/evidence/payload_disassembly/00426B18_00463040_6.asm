; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426B18; baseline game VA=0x00463040; size=6
; Relative branch annotations use the baseline game destination.
00463040 [00426B18] e8 3b 23 c4 ff                               call    near ptr 68E58h ; game-relative-target=0x000A5380
00463045 [00426B1D] 40                                           inc     eax
