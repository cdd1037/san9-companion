; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428868; baseline game VA=0x0047FBDB; size=6
; Relative branch annotations use the baseline game destination.
0047FBDB [00428868] e8 c8 7d c2 ff                               call    near ptr 50635h ; game-relative-target=0x000A79A8
0047FBE0 [0042886D] 41                                           inc     ecx
