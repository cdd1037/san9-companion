; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422020; baseline game VA=0x000A1CA0; size=25
; Relative branch annotations use the baseline game destination.
000A1CA0 [00422020] 8b 41 04                                     mov     eax, [ecx+4]
000A1CA3 [00422023] 8b 40 08                                     mov     eax, [eax+8]
000A1CA6 [00422026] c3                                           retn
000A1CA7 [00422027] 51                                           push    ecx
000A1CA8 [00422028] 8d 4b 44                                     lea     ecx, [ebx+44h]
000A1CAB [0042202B] b8 10 82 51 00                               mov     eax, 518210h
000A1CB0 [00422030] ff d0                                        call    eax
000A1CB2 [00422032] 59                                           pop     ecx
000A1CB3 [00422033] 68 70 ef 46 00                               push    46EF70h
000A1CB8 [00422038] c3                                           retn
