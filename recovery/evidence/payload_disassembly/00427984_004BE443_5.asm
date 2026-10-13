; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427984; baseline game VA=0x004BE443; size=5
; Relative branch annotations use the baseline game destination.
004BE443 [00427984] 03 c8                                        add     ecx, eax
004BE445 [00427986] 83 f9 04                                     cmp     ecx, 4
