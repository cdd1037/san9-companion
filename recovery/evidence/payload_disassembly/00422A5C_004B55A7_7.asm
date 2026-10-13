; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422A5C; baseline game VA=0x004B55A7; size=7
; Relative branch annotations use the baseline game destination.
004B55A7 [00422A5C] e8 fc ce be ff                               call    near ptr 0F95Dh ; game-relative-target=0x000A24A8
004B55AC [00422A61] 90                                           nop
004B55AD [00422A62] 90                                           nop
