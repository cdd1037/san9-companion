; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429BD8; baseline game VA=0x004D0DFA; size=5
; Relative branch annotations use the baseline game destination.
004D0DFA [00429BD8] e8 01 73 bd ff                               call    near ptr 0EDEh ; game-relative-target=0x000A8100
