; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424CB8; baseline game VA=0x00539384; size=5
; Relative branch annotations use the baseline game destination.
00539384 [00424CB8] 83 c0 11                                     add     eax, 11h
00539387 [00424CBB] 8b f0                                        mov     esi, eax
