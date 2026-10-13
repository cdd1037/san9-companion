; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041F980; baseline game VA=0x0057B2C0; size=8
; Relative branch annotations use the baseline game destination.
0057B2C0 [0041F980] 03 f8                                        add     edi, eax
0057B2C2 [0041F982] 81 ff 40 0d 03 00                            cmp     edi, 30D40h
