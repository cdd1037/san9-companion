; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420490; baseline game VA=0x00507924; size=6
; Relative branch annotations use the baseline game destination.
00507924 [00420490] e8 87 89 b9 ff                               call    near ptr 0FFFB8E1Ch ; game-relative-target=0x000A02B0
00507929 [00420495] 41                                           inc     ecx
