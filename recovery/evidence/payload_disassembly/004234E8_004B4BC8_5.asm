; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004234E8; baseline game VA=0x004B4BC8; size=5
; Relative branch annotations use the baseline game destination.
004B4BC8 [004234E8] e8 73 b5 be ff                               call    near ptr 0EA60h ; game-relative-target=0x000A0140
