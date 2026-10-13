; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A000; baseline game VA=0x004E1F3B; size=5
; Relative branch annotations use the baseline game destination.
004E1F3B [0042A000] e8 40 e4 08 00                               call    near ptr 4B8445h ; game-relative-target=0x00570380
