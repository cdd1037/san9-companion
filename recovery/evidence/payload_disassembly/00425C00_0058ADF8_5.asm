; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425C00; baseline game VA=0x0058ADF8; size=5
; Relative branch annotations use the baseline game destination.
0058ADF8 [00425C00] e8 33 a9 b1 ff                               call    near ptr 0FFF40538h ; game-relative-target=0x000A5730
