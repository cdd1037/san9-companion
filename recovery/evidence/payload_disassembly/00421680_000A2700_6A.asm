; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421680; baseline game VA=0x000A2700; size=106
; Relative branch annotations use the baseline game destination.
000A2700 [00421680] 33 c0                                        xor     eax, eax
000A2702 [00421682] 80 3d 14 ff 43 00 01                         cmp     byte ptr ds:43FF14h, 1
000A2709 [00421689] 75 01                                        jnz     short near ptr unk_42168C ; game-relative-target=0x000A270C
000A270B [0042168B] c3                                           retn
000A270C [0042168C] 57                                           push    edi
000A270D [0042168D] 8b be cc 00 00 00                            mov     edi, [esi+0CCh]
000A2713 [00421693] 83 7f 24 01                                  cmp     dword ptr [edi+24h], 1
000A2717 [00421697] 75 04                                        jnz     short near ptr unk_42169D ; game-relative-target=0x000A271D
000A2719 [00421699] 33 d2                                        xor     edx, edx
000A271B [0042169B] eb 2d                                        jmp     short near ptr unk_4216CA ; game-relative-target=0x000A274A
000A271D [0042169D] 8b cf                                        mov     ecx, edi
000A271F [0042169F] b8 b0 d9 43 00                               mov     eax, 43D9B0h
000A2724 [004216A4] ff d0                                        call    eax
000A2726 [004216A6] 8b 57 14                                     mov     edx, [edi+14h]
000A2729 [004216A9] 2b d0                                        sub     edx, eax
000A272B [004216AB] 85 d2                                        test    edx, edx
000A272D [004216AD] 7e 1b                                        jle     short near ptr unk_4216CA ; game-relative-target=0x000A274A
000A272F [004216AF] 8b 87 84 00 00 00                            mov     eax, [edi+84h]
000A2735 [004216B5] 3c 14                                        cmp     al, 14h
000A2737 [004216B7] 7e 02                                        jle     short near ptr unk_4216BB ; game-relative-target=0x000A273B
000A2739 [004216B9] b0 14                                        mov     al, 14h
000A273B [004216BB] 69 c0 dc 05 00 00                            imul    eax, 5DCh
000A2741 [004216C1] 8b c8                                        mov     ecx, eax
000A2743 [004216C3] 8b c2                                        mov     eax, edx
000A2745 [004216C5] 99                                           cdq
000A2746 [004216C6] f7 f1                                        div     ecx
000A2748 [004216C8] 8b d0                                        mov     edx, eax
000A274A [004216CA] 8b 86 d4 01 00 00                            mov     eax, [esi+1D4h]
000A2750 [004216D0] 85 d2                                        test    edx, edx
000A2752 [004216D2] 7e 14                                        jle     short near ptr unk_4216E8 ; game-relative-target=0x000A2768
000A2754 [004216D4] 66 83 fa 08                                  cmp     dx, 8
000A2758 [004216D8] 7e 04                                        jle     short near ptr unk_4216DE ; game-relative-target=0x000A275E
000A275A [004216DA] 66 ba 08 00                                  mov     dx, 8
000A275E [004216DE] f7 da                                        neg     edx
000A2760 [004216E0] 83 c2 09                                     add     edx, 9
000A2763 [004216E3] f7 ea                                        imul    edx
000A2765 [004216E5] c1 e8 03                                     shr     eax, 3
000A2768 [004216E8] 5f                                           pop     edi
000A2769 [004216E9] c3                                           retn
