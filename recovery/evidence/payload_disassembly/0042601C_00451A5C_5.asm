; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042601C; baseline game VA=0x00451A5C; size=5
; Relative branch annotations use the baseline game destination.
00451A5C [0042601C] 8b 17                                        mov     edx, [edi]
00451A5E [0042601E] 8b 42 f8                                     mov     eax, [edx-8]
