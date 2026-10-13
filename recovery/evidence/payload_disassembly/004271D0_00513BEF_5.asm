; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004271D0; baseline game VA=0x00513BEF; size=5
; Relative branch annotations use the baseline game destination.
00513BEF [004271D0] e8 7c 30 b9 ff                               call    near ptr 0FFFBA251h ; game-relative-target=0x000A6C70
