; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424844; baseline game VA=0x0049FB20; size=5
; Relative branch annotations use the baseline game destination.
0049FB20 [00424844] e8 c3 0a c0 ff                               call    near ptr 2530Ch ; game-relative-target=0x000A05E8
