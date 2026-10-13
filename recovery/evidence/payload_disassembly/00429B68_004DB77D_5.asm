; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429B68; baseline game VA=0x004DB77D; size=5
; Relative branch annotations use the baseline game destination.
004DB77D [00429B68] e8 6e 50 fb ff                               call    near ptr 3DEBDBh ; game-relative-target=0x004907F0
