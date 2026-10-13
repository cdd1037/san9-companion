; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004230E4; baseline game VA=0x004B5320; size=5
; Relative branch annotations use the baseline game destination.
004B5320 [004230E4] e8 db d5 be ff                               call    near ptr 106C4h ; game-relative-target=0x000A2900
