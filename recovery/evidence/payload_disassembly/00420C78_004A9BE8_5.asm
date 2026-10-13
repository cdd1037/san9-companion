; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420C78; baseline game VA=0x004A9BE8; size=5
; Relative branch annotations use the baseline game destination.
004A9BE8 [00420C78] e8 13 82 bf ff                               call    near ptr 18E90h ; game-relative-target=0x000A1E00
