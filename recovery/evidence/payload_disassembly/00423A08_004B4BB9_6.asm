; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423A08; baseline game VA=0x004B4BB9; size=6
; Relative branch annotations use the baseline game destination.
004B4BB9 [00423A08] e8 22 b9 be ff                               call    near ptr 0F32Fh ; game-relative-target=0x000A04E0
004B4BBE [00423A0D] 41                                           inc     ecx
