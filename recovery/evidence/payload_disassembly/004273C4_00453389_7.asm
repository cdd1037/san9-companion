; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004273C4; baseline game VA=0x00453389; size=7
; Relative branch annotations use the baseline game destination.
00453389 [004273C4] e8 b2 3c c5 ff                               call    near ptr 7B07Bh ; game-relative-target=0x000A7040
0045338E [004273C9] 40                                           inc     eax
0045338F [004273CA] 40                                           inc     eax
