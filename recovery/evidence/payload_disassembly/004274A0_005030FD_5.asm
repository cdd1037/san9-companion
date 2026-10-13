; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004274A0; baseline game VA=0x005030FD; size=5
; Relative branch annotations use the baseline game destination.
005030FD [004274A0] e8 1e 34 ba ff                               call    near ptr 0FFFCA8C3h ; game-relative-target=0x000A6520
