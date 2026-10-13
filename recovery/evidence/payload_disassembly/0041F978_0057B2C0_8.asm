; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041F978; baseline game VA=0x0057B2C0; size=8
; Relative branch annotations use the baseline game destination.
0057B2C0 [0041F978] 8b d0                                        mov     edx, eax
0057B2C2 [0041F97A] 81 ff 20 bf 02 00                            cmp     edi, 2BF20h
