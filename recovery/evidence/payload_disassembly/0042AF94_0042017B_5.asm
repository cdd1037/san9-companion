; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042AF94; baseline game VA=0x0042017B; size=5
; Relative branch annotations use the baseline game destination.
0042017B [0042AF94] e8 90 d8 1a 00                               call    near ptr 5D8829h ; game-relative-target=0x005CDA10
