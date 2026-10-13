; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004224D4; baseline game VA=0x004B6C29; size=4
; Relative branch annotations use the baseline game destination.
004B6C29 [004224D4] 70 1d                                        jo      short near ptr dword_4224F0+3 ; game-relative-target=0x004B6C48
004B6C2B [004224D6] 0a 00                                        or      al, [eax]
