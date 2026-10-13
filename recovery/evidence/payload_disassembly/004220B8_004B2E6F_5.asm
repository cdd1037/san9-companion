; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004220B8; baseline game VA=0x004B2E6F; size=5
; Relative branch annotations use the baseline game destination.
004B2E6F [004220B8] e8 33 ee be ff                               call    near ptr 10EF0h ; game-relative-target=0x000A1CA7
