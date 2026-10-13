; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421B08; baseline game VA=0x004A2C10; size=6
; Relative branch annotations use the baseline game destination.
004A2C10 [00421B08] e8 4b e0 bf ff                               call    near ptr 1FB58h ; game-relative-target=0x000A0C60
004A2C15 [00421B0D] 42                                           inc     edx
