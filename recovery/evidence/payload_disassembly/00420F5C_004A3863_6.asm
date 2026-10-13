; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420F5C; baseline game VA=0x004A3863; size=6
; Relative branch annotations use the baseline game destination.
004A3863 [00420F5C] e8 e8 cb bf ff                               call    near ptr 1DB49h ; game-relative-target=0x000A0450
004A3868 [00420F61] 42                                           inc     edx
