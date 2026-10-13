; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004278A8; baseline game VA=0x00505BEA; size=6
; Relative branch annotations use the baseline game destination.
00505BEA [004278A8] e8 c1 09 ba ff                               call    near ptr 0FFFC826Eh ; game-relative-target=0x000A65B0
00505BEF [004278AD] 40                                           inc     eax
