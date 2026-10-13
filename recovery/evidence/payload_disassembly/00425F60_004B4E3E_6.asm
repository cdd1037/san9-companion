; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425F60; baseline game VA=0x004B4E3E; size=6
; Relative branch annotations use the baseline game destination.
004B4E3E [00425F60] e8 bd 0a bf ff                               call    near ptr 16A22h ; game-relative-target=0x000A5900
004B4E43 [00425F65] 41                                           inc     ecx
