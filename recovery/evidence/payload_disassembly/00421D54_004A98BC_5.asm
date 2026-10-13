; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421D54; baseline game VA=0x004A98BC; size=5
; Relative branch annotations use the baseline game destination.
004A98BC [00421D54] e8 1f 84 bf ff                               call    near ptr 1A178h ; game-relative-target=0x000A1CE0
