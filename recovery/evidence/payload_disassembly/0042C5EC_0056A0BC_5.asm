; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C5EC; baseline game VA=0x0056A0BC; size=5
; Relative branch annotations use the baseline game destination.
0056A0BC [0042C5EC] e8 3f 85 b3 ff                               call    near ptr 0FFF64B30h ; game-relative-target=0x000A2600
