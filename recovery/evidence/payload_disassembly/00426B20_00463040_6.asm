; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426B20; baseline game VA=0x00463040; size=6
; Relative branch annotations use the baseline game destination.
00463040 [00426B20] 83 c0 f8                                     add     eax, 0FFFFFFF8h
00463043 [00426B23] 83 f8 12                                     cmp     eax, 12h
