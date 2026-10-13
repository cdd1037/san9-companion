; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042017C; baseline game VA=0x00464F10; size=5
; Relative branch annotations use the baseline game destination.
00464F10 [0042017C] e8 1b b1 c3 ff                               call    near ptr 5B29Ch ; game-relative-target=0x000A0030
