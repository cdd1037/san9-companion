; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429E98; baseline game VA=0x004ED0AE; size=5
; Relative branch annotations use the baseline game destination.
004ED0AE [00429E98] e8 cd 32 08 00                               call    near ptr 4AD16Ah ; game-relative-target=0x00570380
