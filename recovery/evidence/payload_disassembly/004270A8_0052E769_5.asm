; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004270A8; baseline game VA=0x0052E769; size=5
; Relative branch annotations use the baseline game destination.
0052E769 [004270A8] 8b f9                                        mov     edi, ecx
0052E76B [004270AA] 8b 4e 54                                     mov     ecx, [esi+54h]
