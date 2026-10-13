; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424494; baseline game VA=0x004B49B8; size=6
; Relative branch annotations use the baseline game destination.
004B49B8 [00424494] e8 13 ce be ff                               call    near ptr 112ACh ; game-relative-target=0x000A17D0
004B49BD [00424499] 41                                           inc     ecx
