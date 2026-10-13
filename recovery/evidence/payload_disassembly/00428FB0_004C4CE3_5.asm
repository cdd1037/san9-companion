; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428FB0; baseline game VA=0x004C4CE3; size=5
; Relative branch annotations use the baseline game destination.
004C4CE3 [00428FB0] e8 d8 12 be ff                               call    near ptr 0A28Dh ; game-relative-target=0x000A5FC0
