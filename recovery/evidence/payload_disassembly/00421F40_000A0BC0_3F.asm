; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421F40; baseline game VA=0x000A0BC0; size=63
; Relative branch annotations use the baseline game destination.
000A0BC0 [00421F40] 56                                           push    esi
000A0BC1 [00421F41] 8b 74 24 08                                  mov     esi, [esp+8]
000A0BC5 [00421F45] 8b 0e                                        mov     ecx, [esi]
000A0BC7 [00421F47] 8b 81 f4 00 00 00                            mov     eax, [ecx+0F4h]
000A0BCD [00421F4D] 8b 48 74                                     mov     ecx, [eax+74h]
000A0BD0 [00421F50] b8 e0 fd 43 00                               mov     eax, 43FDE0h
000A0BD5 [00421F55] ff d0                                        call    eax
000A0BD7 [00421F57] 50                                           push    eax
000A0BD8 [00421F58] 8b 0e                                        mov     ecx, [esi]
000A0BDA [00421F5A] b8 c0 ce 44 00                               mov     eax, 44CEC0h
000A0BDF [00421F5F] ff d0                                        call    eax
000A0BE1 [00421F61] 50                                           push    eax
000A0BE2 [00421F62] 8b 0e                                        mov     ecx, [esi]
000A0BE4 [00421F64] 6a 00                                        push    0
000A0BE6 [00421F66] b8 90 d4 44 00                               mov     eax, 44D490h
000A0BEB [00421F6B] ff d0                                        call    eax
000A0BED [00421F6D] 8b 0e                                        mov     ecx, [esi]
000A0BEF [00421F6F] 03 41 64                                     add     eax, [ecx+64h]
000A0BF2 [00421F72] d1 e0                                        shl     eax, 1
000A0BF4 [00421F74] 03 41 70                                     add     eax, [ecx+70h]
000A0BF7 [00421F77] 5a                                           pop     edx
000A0BF8 [00421F78] c1 ea 01                                     shr     edx, 1
000A0BFB [00421F7B] 2b c2                                        sub     eax, edx
000A0BFD [00421F7D] 5e                                           pop     esi
000A0BFE [00421F7E] c3                                           retn
