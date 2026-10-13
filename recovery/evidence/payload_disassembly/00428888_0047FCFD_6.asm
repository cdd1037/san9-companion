; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428888; baseline game VA=0x0047FCFD; size=6
; Relative branch annotations use the baseline game destination.
0047FCFD [00428888] e8 a6 7c c2 ff                               call    near ptr 50533h ; game-relative-target=0x000A79A8
0047FD02 [0042888D] 41                                           inc     ecx
