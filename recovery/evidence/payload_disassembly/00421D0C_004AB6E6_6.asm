; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421D0C; baseline game VA=0x004AB6E6; size=6
; Relative branch annotations use the baseline game destination.
004AB6E6 [00421D0C] e8 15 82 bf ff                               call    near ptr 19F26h ; game-relative-target=0x000A3900
004AB6EB [00421D11] 42                                           inc     edx
