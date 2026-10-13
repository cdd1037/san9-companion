; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425430; baseline game VA=0x0045DDA1; size=6
; Relative branch annotations use the baseline game destination.
0045DDA1 [00425430] e8 12 59 c4 ff                               call    near ptr 6AD47h ; game-relative-target=0x000A36B8
0045DDA6 [00425435] 90                                           nop
