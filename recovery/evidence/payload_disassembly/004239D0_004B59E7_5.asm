; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004239D0; baseline game VA=0x004B59E7; size=5
; Relative branch annotations use the baseline game destination.
004B59E7 [004239D0] e8 fc d5 be ff                               call    near ptr 10FD1h ; game-relative-target=0x000A2FE8
