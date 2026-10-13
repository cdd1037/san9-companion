; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A5AC; baseline game VA=0x0051F097; size=5
; Relative branch annotations use the baseline game destination.
0051F097 [0042A5AC] e8 24 97 b8 ff                               call    near ptr 0FFFB3CD5h ; game-relative-target=0x000A87C0
