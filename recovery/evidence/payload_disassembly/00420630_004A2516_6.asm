; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420630; baseline game VA=0x004A2516; size=6
; Relative branch annotations use the baseline game destination.
004A2516 [00420630] e8 55 e2 bf ff                               call    near ptr 1E88Ah ; game-relative-target=0x000A0770
004A251B [00420635] 40                                           inc     eax
