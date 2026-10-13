; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423544; baseline game VA=0x004B4DF2; size=7
; Relative branch annotations use the baseline game destination.
004B4DF2 [00423544] 90                                           nop
004B4DF3 [00423545] 90                                           nop
004B4DF4 [00423546] e8 b7 e6 be ff                               call    near ptr 11C02h ; game-relative-target=0x000A34B0
