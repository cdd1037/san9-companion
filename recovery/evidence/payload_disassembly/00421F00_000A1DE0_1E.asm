; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421F00; baseline game VA=0x000A1DE0; size=30
; Relative branch annotations use the baseline game destination.
000A1DE0 [00421F00] 56                                           push    esi
000A1DE1 [00421F01] 8b 74 24 08                                  mov     esi, [esp+8]
000A1DE5 [00421F05] 8b 0e                                        mov     ecx, [esi]
000A1DE7 [00421F07] 6a 00                                        push    0
000A1DE9 [00421F09] b8 90 d4 44 00                               mov     eax, 44D490h
000A1DEE [00421F0E] ff d0                                        call    eax
000A1DF0 [00421F10] 03 44 24 ec                                  add     eax, [esp-14h]
000A1DF4 [00421F14] 8b 0e                                        mov     ecx, [esi]
000A1DF6 [00421F16] 03 41 64                                     add     eax, [ecx+64h]
000A1DF9 [00421F19] 03 41 54                                     add     eax, [ecx+54h]
000A1DFC [00421F1C] 5e                                           pop     esi
000A1DFD [00421F1D] c3                                           retn
