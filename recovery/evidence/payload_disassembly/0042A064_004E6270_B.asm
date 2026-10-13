; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A064; baseline game VA=0x004E6270; size=11
; Relative branch annotations use the baseline game destination.
004E6270 [0042A064] e8 1b 20 bc ff                               call    near ptr 0FFFEC084h ; game-relative-target=0x000A8290
004E6275 [0042A069] 68 a0 b4 4c 00                               push    4CB4A0h
004E627A [0042A06E] c3                                           retn
