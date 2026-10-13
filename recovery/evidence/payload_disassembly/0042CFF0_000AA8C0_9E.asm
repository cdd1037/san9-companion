; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042CFF0; baseline game VA=0x000AA8C0; size=158
; Relative branch annotations use the baseline game destination.
000AA8C0 [0042CFF0] 68 d0 49 43 00                               push    4349D0h
000AA8C5 [0042CFF5] b8 10 ec 50 00                               mov     eax, 50EC10h
000AA8CA [0042CFFA] ff d0                                        call    eax
000AA8CC [0042CFFC] 85 c0                                        test    eax, eax
000AA8CE [0042CFFE] 75 01                                        jnz     short near ptr dword_42CFF8+9 ; game-relative-target=0x000AA8D1
000AA8D0 [0042D000] c3                                           retn
000AA8D1 [0042D001] 57                                           push    edi
000AA8D2 [0042D002] 56                                           push    esi
000AA8D3 [0042D003] 53                                           push    ebx
000AA8D4 [0042D004] 8b d8                                        mov     ebx, eax
000AA8D6 [0042D006] 33 d2                                        xor     edx, edx
000AA8D8 [0042D008] 33 c9                                        xor     ecx, ecx
000AA8DA [0042D00A] 8a 44 24 10                                  mov     al, [esp+10h]
000AA8DE [0042D00E] 3c df                                        cmp     al, 0DFh
000AA8E0 [0042D010] 0f 95 c1                                     setnz   cl
000AA8E3 [0042D013] 80 c9 02                                     or      cl, 2
000AA8E6 [0042D016] 3c f0                                        cmp     al, 0F0h
000AA8E8 [0042D018] 0f 94 c5                                     setz    ch
000AA8EB [0042D01B] 33 f6                                        xor     esi, esi
000AA8ED [0042D01D] bf b0 93 4b 01                               mov     edi, 14B93B0h
000AA8F2 [0042D022] 8b 47 24                                     mov     eax, [edi+24h]
000AA8F5 [0042D025] 85 c0                                        test    eax, eax
000AA8F7 [0042D027] 74 2b                                        jz      short near ptr dword_42CFF8+5Ch ; game-relative-target=0x000AA924
000AA8F9 [0042D029] 83 e8 04                                     sub     eax, 4
000AA8FC [0042D02C] 83 f8 03                                     cmp     eax, 3
000AA8FF [0042D02F] 76 23                                        jbe     short near ptr dword_42CFF8+5Ch ; game-relative-target=0x000AA924
000AA901 [0042D031] 39 5f 74                                     cmp     [edi+74h], ebx
000AA904 [0042D034] 75 1e                                        jnz     short near ptr dword_42CFF8+5Ch ; game-relative-target=0x000AA924
000AA906 [0042D036] 8b 47 50                                     mov     eax, [edi+50h]
000AA909 [0042D039] 3b 45 04                                     cmp     eax, [ebp+4]
000AA90C [0042D03C] 75 16                                        jnz     short near ptr dword_42CFF8+5Ch ; game-relative-target=0x000AA924
000AA90E [0042D03E] 8b 47 58                                     mov     eax, [edi+58h]
000AA911 [0042D041] 83 e8 19                                     sub     eax, 19h
000AA914 [0042D044] 83 f8 03                                     cmp     eax, 3
000AA917 [0042D047] 77 03                                        ja      short near ptr dword_42CFF8+54h ; game-relative-target=0x000AA91C
000AA919 [0042D049] 80 ca 02                                     or      dl, 2
000AA91C [0042D04C] 83 f8 0d                                     cmp     eax, 0Dh
000AA91F [0042D04F] 75 03                                        jnz     short near ptr dword_42CFF8+5Ch ; game-relative-target=0x000AA924
000AA921 [0042D051] 80 ca 01                                     or      dl, 1
000AA924 [0042D054] 3a d1                                        cmp     dl, cl
000AA926 [0042D056] 74 0f                                        jz      short near ptr dword_42CFF8+6Fh ; game-relative-target=0x000AA937
000AA928 [0042D058] 81 c7 04 01 00 00                            add     edi, 104h
000AA92E [0042D05E] 46                                           inc     esi
000AA92F [0042D05F] 81 fe 51 03 00 00                            cmp     esi, 351h
000AA935 [0042D065] 7c bb                                        jl      short near ptr dword_42CFF8+2Ah ; game-relative-target=0x000AA8F2
000AA937 [0042D067] f6 c2 03                                     test    dl, 3
000AA93A [0042D06A] 74 1e                                        jz      short near ptr dword_42CFF8+92h ; game-relative-target=0x000AA95A
000AA93C [0042D06C] b8 e4 04 00 00                               mov     eax, 4E4h
000AA941 [0042D071] 80 fa 02                                     cmp     dl, 2
000AA944 [0042D074] 74 10                                        jz      short near ptr dword_42CFF8+8Eh ; game-relative-target=0x000AA956
000AA946 [0042D076] 83 e8 1f                                     sub     eax, 1Fh
000AA949 [0042D079] 80 fa 03                                     cmp     dl, 3
000AA94C [0042D07C] 74 08                                        jz      short near ptr dword_42CFF8+8Eh ; game-relative-target=0x000AA956
000AA94E [0042D07E] 48                                           dec     eax
000AA94F [0042D07F] 84 ed                                        test    ch, ch
000AA951 [0042D081] 74 03                                        jz      short near ptr dword_42CFF8+8Eh ; game-relative-target=0x000AA956
000AA953 [0042D083] 83 c0 12                                     add     eax, 12h
000AA956 [0042D086] 89 44 24 18                                  mov     [esp+18h], eax
000AA95A [0042D08A] 5b                                           pop     ebx
000AA95B [0042D08B] 5e                                           pop     esi
000AA95C [0042D08C] 5f                                           pop     edi
000AA95D [0042D08D] c3                                           retn
