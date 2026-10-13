; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425C94; baseline game VA=0x0058AE32; size=5
; Relative branch annotations use the baseline game destination.
0058AE32 [00425C94] e8 81 a8 b1 ff                               call    near ptr 0FFF4051Ah ; game-relative-target=0x000A56B8
