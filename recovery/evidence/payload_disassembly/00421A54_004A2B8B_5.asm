; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421A54; baseline game VA=0x004A2B8B; size=5
; Relative branch annotations use the baseline game destination.
004A2B8B [00421A54] e8 70 e9 bf ff                               call    near ptr 203C9h ; game-relative-target=0x000A1500
