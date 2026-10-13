; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424A28; baseline game VA=0x004B5A66; size=5
; Relative branch annotations use the baseline game destination.
004B5A66 [00424A28] e8 95 e0 be ff                               call    near ptr 12AC2h ; game-relative-target=0x000A3B00
