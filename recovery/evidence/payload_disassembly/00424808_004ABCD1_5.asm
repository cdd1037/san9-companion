; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424808; baseline game VA=0x004ABCD1; size=5
; Relative branch annotations use the baseline game destination.
004ABCD1 [00424808] e8 0a b0 bf ff                               call    near ptr 1F817h ; game-relative-target=0x000A6CE0
