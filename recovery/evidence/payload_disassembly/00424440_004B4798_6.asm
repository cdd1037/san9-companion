; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424440; baseline game VA=0x004B4798; size=6
; Relative branch annotations use the baseline game destination.
004B4798 [00424440] e8 b3 ea be ff                               call    near ptr 12EF8h ; game-relative-target=0x000A3250
004B479D [00424445] 40                                           inc     eax
