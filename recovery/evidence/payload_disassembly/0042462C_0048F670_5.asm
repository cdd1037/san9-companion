; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042462C; baseline game VA=0x0048F670; size=5
; Relative branch annotations use the baseline game destination.
0048F670 [0042462C] 83 c4 0c                                     add     esp, 0Ch
0048F673 [0042462F] 3b c8                                        cmp     ecx, eax
