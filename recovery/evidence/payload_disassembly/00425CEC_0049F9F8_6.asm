; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425CEC; baseline game VA=0x0049F9F8; size=6
; Relative branch annotations use the baseline game destination.
0049F9F8 [00425CEC] e8 4b 5d c0 ff                               call    near ptr 2BA3Ch ; game-relative-target=0x000A5748
0049F9FD [00425CF1] 90                                           nop
