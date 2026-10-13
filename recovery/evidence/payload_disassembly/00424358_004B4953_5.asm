; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424358; baseline game VA=0x004B4953; size=5
; Relative branch annotations use the baseline game destination.
004B4953 [00424358] 99                                           cdq
004B4954 [00424359] 2b c2                                        sub     eax, edx
004B4956 [0042435B] 8b f0                                        mov     esi, eax
