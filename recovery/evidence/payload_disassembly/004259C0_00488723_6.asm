; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004259C0; baseline game VA=0x00488723; size=6
; Relative branch annotations use the baseline game destination.
00488723 [004259C0] e8 a8 98 c1 ff                               call    near ptr 3F26Dh ; game-relative-target=0x000A1FD0
00488728 [004259C5] 90                                           nop
