; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421B30; baseline game VA=0x000A2770; size=47
; Relative branch annotations use the baseline game destination.
000A2770 [00421B30] 50                                           push    eax
000A2771 [00421B31] 8b 4e 40                                     mov     ecx, [esi+40h]
000A2774 [00421B34] 8b 51 6c                                     mov     edx, [ecx+6Ch]
000A2777 [00421B37] 8b 42 78                                     mov     eax, [edx+78h]
000A277A [00421B3A] 8b 51 70                                     mov     edx, [ecx+70h]
000A277D [00421B3D] 03 42 78                                     add     eax, [edx+78h]
000A2780 [00421B40] 69 c0 b8 0b 00 00                            imul    eax, 0BB8h
000A2786 [00421B46] c1 e8 0e                                     shr     eax, 0Eh
000A2789 [00421B49] 59                                           pop     ecx
000A278A [00421B4A] 8b 51 14                                     mov     edx, [ecx+14h]
000A278D [00421B4D] 2b d0                                        sub     edx, eax
000A278F [00421B4F] 85 d2                                        test    edx, edx
000A2791 [00421B51] 7d 02                                        jge     short near ptr unk_421B55 ; game-relative-target=0x000A2795
000A2793 [00421B53] 33 d2                                        xor     edx, edx
000A2795 [00421B55] 89 51 14                                     mov     [ecx+14h], edx
000A2798 [00421B58] 8b 41 34                                     mov     eax, [ecx+34h]
000A279B [00421B5B] 83 e0 01                                     and     eax, 1
000A279E [00421B5E] c3                                           retn
