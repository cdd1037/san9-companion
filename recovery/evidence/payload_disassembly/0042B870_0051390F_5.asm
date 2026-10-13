; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B870; baseline game VA=0x0051390F; size=5
; Relative branch annotations use the baseline game destination.
0051390F [0042B870] e8 dc fc ff ff                               call    near ptr dword_42B550+1 ; game-relative-target=0x005135F0
