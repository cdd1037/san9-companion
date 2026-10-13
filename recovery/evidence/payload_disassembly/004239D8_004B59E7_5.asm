; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004239D8; baseline game VA=0x004B59E7; size=5
; Relative branch annotations use the baseline game destination.
004B59E7 [004239D8] 8b c3                                        mov     eax, ebx
004B59E9 [004239DA] 99                                           cdq
004B59EA [004239DB] 2b c2                                        sub     eax, edx
