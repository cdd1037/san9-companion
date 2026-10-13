; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422EB8; baseline game VA=0x004B419A; size=6
; Relative branch annotations use the baseline game destination.
004B419A [00422EB8] e8 31 e7 be ff                               call    near ptr 115EEh ; game-relative-target=0x000A28D0
004B419F [00422EBD] 90                                           nop
