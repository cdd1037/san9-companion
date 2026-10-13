; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424CB0; baseline game VA=0x00539384; size=5
; Relative branch annotations use the baseline game destination.
00539384 [00424CB0] e8 5f 9d b6 ff                               call    near ptr 0FFF8EA14h ; game-relative-target=0x000A30E8
