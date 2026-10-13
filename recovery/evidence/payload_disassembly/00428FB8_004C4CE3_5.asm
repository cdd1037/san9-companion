; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428FB8; baseline game VA=0x004C4CE3; size=5
; Relative branch annotations use the baseline game destination.
004C4CE3 [00428FB8] e8 98 4f fc ff                               call    near ptr 3EDF55h ; game-relative-target=0x00489C80
