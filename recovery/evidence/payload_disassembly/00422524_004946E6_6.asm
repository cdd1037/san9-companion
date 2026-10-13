; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422524; baseline game VA=0x004946E6; size=6
; Relative branch annotations use the baseline game destination.
004946E6 [00422524] e8 b5 d8 c0 ff                               call    near ptr 2FDDEh ; game-relative-target=0x000A1FA0
004946EB [00422529] 42                                           inc     edx
