; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004240F8; baseline game VA=0x0047937E; size=5
; Relative branch annotations use the baseline game destination.
0047937E [004240F8] e8 0d 9f c2 ff                               call    near ptr 4E00Ah ; game-relative-target=0x000A3290
