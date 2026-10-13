; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042160C; baseline game VA=0x004538B6; size=9
; Relative branch annotations use the baseline game destination.
004538B6 [0042160C] 59                                           pop     ecx
004538B7 [0042160D] c1 e0 03                                     shl     eax, 3
004538BA [00421610] 6a 0b                                        push    0Bh
004538BC [00421612] 50                                           push    eax
004538BD [00421613] 51                                           push    ecx
004538BE [00421614] c3                                           retn
