; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427DF0; baseline game VA=0x0044F3F7; size=5
; Relative branch annotations use the baseline game destination.
0044F3F7 [00427DF0] 8b f2                                        mov     esi, edx
0044F3F9 [00427DF2] 0f af f3                                     imul    esi, ebx
