; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423FAC; baseline game VA=0x004A1C00; size=5
; Relative branch annotations use the baseline game destination.
004A1C00 [00423FAC] e8 2b 06 c0 ff                               call    near ptr 245DCh ; game-relative-target=0x000A2230
