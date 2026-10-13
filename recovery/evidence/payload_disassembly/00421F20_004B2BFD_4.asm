; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421F20; baseline game VA=0x004B2BFD; size=4
; Relative branch annotations use the baseline game destination.
004B2BFD [00421F20] e0 1d                                        loopne  near ptr off_421F3C+3 ; game-relative-target=0x004B2C1C
004B2BFF [00421F22] 0a 00                                        or      al, [eax]
