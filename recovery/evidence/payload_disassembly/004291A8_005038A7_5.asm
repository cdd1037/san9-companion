; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004291A8; baseline game VA=0x005038A7; size=5
; Relative branch annotations use the baseline game destination.
005038A7 [004291A8] 83 f8 17                                     cmp     eax, 17h
005038AA [004291AB] 74 04                                        jz      short near ptr dword_4291B0+1 ; game-relative-target=0x005038B0
