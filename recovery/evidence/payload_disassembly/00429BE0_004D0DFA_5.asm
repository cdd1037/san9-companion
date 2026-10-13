; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429BE0; baseline game VA=0x004D0DFA; size=5
; Relative branch annotations use the baseline game destination.
004D0DFA [00429BE0] e8 21 d6 fb ff                               call    near ptr 3E7206h ; game-relative-target=0x0048E420
