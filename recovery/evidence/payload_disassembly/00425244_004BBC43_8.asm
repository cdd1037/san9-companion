; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425244; baseline game VA=0x004BBC43; size=8
; Relative branch annotations use the baseline game destination.
004BBC43 [00425244] e8 68 98 be ff                               call    near ptr 0EAB1h ; game-relative-target=0x000A54B0
004BBC48 [00425249] 33 c0                                        xor     eax, eax
004BBC4A [0042524B] 90                                           nop
