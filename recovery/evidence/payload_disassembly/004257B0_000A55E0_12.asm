; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004257B0; baseline game VA=0x000A55E0; size=18
; Relative branch annotations use the baseline game destination.
000A55E0 [004257B0] 51                                           push    ecx
000A55E1 [004257B1] 8d 4b 64                                     lea     ecx, [ebx+64h]
000A55E4 [004257B4] b8 10 82 51 00                               mov     eax, 518210h
000A55E9 [004257B9] ff d0                                        call    eax
000A55EB [004257BB] 59                                           pop     ecx
000A55EC [004257BC] 68 70 ef 46 00                               push    46EF70h
000A55F1 [004257C1] c3                                           retn
