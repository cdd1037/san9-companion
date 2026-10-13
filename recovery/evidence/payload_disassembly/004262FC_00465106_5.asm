; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004262FC; baseline game VA=0x00465106; size=5
; Relative branch annotations use the baseline game destination.
00465106 [004262FC] e8 15 0b c4 ff                               call    near ptr 66E16h ; game-relative-target=0x000A5C20
