; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422FD4; baseline game VA=0x0046B9F1; size=15
; Relative branch annotations use the baseline game destination.
0046B9F1 [00422FD4] 6a 01                                        push    1
0046B9F3 [00422FD6] 6a 00                                        push    0
0046B9F5 [00422FD8] 52                                           push    edx
0046B9F6 [00422FD9] 8b ce                                        mov     ecx, esi
0046B9F8 [00422FDB] b8 c0 b1 43 00                               mov     eax, 43B1C0h
0046B9FD [00422FE0] ff d0                                        call    eax
0046B9FF [00422FE2] c3                                           retn
