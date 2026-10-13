; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420090; baseline game VA=0x0046522F; size=5
; Relative branch annotations use the baseline game destination.
0046522F [00420090] e8 8c e8 c3 ff                               call    near ptr 5E921h ; game-relative-target=0x000A3AC0
