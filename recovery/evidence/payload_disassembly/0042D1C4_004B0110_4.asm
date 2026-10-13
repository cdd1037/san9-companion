; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042D1C4; baseline game VA=0x004B0110; size=4
; Relative branch annotations use the baseline game destination.
004B0110 [0042D1C4] 03 c6                                        add     eax, esi
004B0112 [0042D1C6] 5e                                           pop     esi
004B0113 [0042D1C7] c3                                           retn
