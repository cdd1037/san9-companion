; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420A1C; baseline game VA=0x004B13B1; size=5
; Relative branch annotations use the baseline game destination.
004B13B1 [00420A1C] e8 4a f6 be ff                               call    near ptr 1006Bh ; game-relative-target=0x000A0A00
