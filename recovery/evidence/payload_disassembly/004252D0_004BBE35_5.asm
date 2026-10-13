; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004252D0; baseline game VA=0x004BBE35; size=5
; Relative branch annotations use the baseline game destination.
004BBE35 [004252D0] e8 26 91 be ff                               call    near ptr 0E3FBh ; game-relative-target=0x000A4F60
