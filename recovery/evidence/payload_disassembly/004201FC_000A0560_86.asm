; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004201FC; baseline game VA=0x000A0560; size=134
; Relative branch annotations use the baseline game destination.
000A0560 [004201FC] 80 79 0c 05                                  cmp     byte ptr [ecx+0Ch], 5
000A0564 [00420200] 7c 2c                                        jl      short near ptr unk_42022E ; game-relative-target=0x000A0592
000A0566 [00420202] 56                                           push    esi
000A0567 [00420203] 57                                           push    edi
000A0568 [00420204] 33 f6                                        xor     esi, esi
000A056A [00420206] 8b 51 08                                     mov     edx, [ecx+8]
000A056D [00420209] 8b 4a 08                                     mov     ecx, [edx+8]
000A0570 [0042020C] 8b 41 58                                     mov     eax, [ecx+58h]
000A0573 [0042020F] 3c 40                                        cmp     al, 40h ; '@'
000A0575 [00420211] 7d 0f                                        jge     short near ptr unk_420222 ; game-relative-target=0x000A0586
000A0577 [00420213] 3b c6                                        cmp     eax, esi
000A0579 [00420215] 7e 04                                        jle     short near ptr unk_42021B ; game-relative-target=0x000A057F
000A057B [00420217] 8b f0                                        mov     esi, eax
000A057D [00420219] 8b fa                                        mov     edi, edx
000A057F [0042021B] 8b 52 04                                     mov     edx, [edx+4]
000A0582 [0042021E] 85 d2                                        test    edx, edx
000A0584 [00420220] 75 e7                                        jnz     short near ptr unk_420209 ; game-relative-target=0x000A056D
000A0586 [00420222] 85 d2                                        test    edx, edx
000A0588 [00420224] 75 02                                        jnz     short near ptr unk_420228 ; game-relative-target=0x000A058C
000A058A [00420226] 8b d7                                        mov     edx, edi
000A058C [00420228] 8b 42 08                                     mov     eax, [edx+8]
000A058F [0042022B] 5f                                           pop     edi
000A0590 [0042022C] 5e                                           pop     esi
000A0591 [0042022D] c3                                           retn
000A0592 [0042022E] 56                                           push    esi
000A0593 [0042022F] 57                                           push    edi
000A0594 [00420230] 53                                           push    ebx
000A0595 [00420231] 8b 71 04                                     mov     esi, [ecx+4]
000A0598 [00420234] bf 00 01 00 00                               mov     edi, 100h
000A059D [00420239] 8b 46 08                                     mov     eax, [esi+8]
000A05A0 [0042023C] ba b2 ef 46 00                               mov     edx, 46EFB2h
000A05A5 [00420241] ff d2                                        call    edx
000A05A7 [00420243] 85 c0                                        test    eax, eax
000A05A9 [00420245] 74 2e                                        jz      short near ptr unk_420275 ; game-relative-target=0x000A05D9
000A05AB [00420247] 33 c0                                        xor     eax, eax
000A05AD [00420249] 8b 4e 08                                     mov     ecx, [esi+8]
000A05B0 [0042024C] 8b 51 50                                     mov     edx, [ecx+50h]
000A05B3 [0042024F] 3b d0                                        cmp     edx, eax
000A05B5 [00420251] 7e 02                                        jle     short near ptr unk_420255 ; game-relative-target=0x000A05B9
000A05B7 [00420253] 8b c2                                        mov     eax, edx
000A05B9 [00420255] 8b 51 58                                     mov     edx, [ecx+58h]
000A05BC [00420258] 3b d0                                        cmp     edx, eax
000A05BE [0042025A] 7e 02                                        jle     short near ptr unk_42025E ; game-relative-target=0x000A05C2
000A05C0 [0042025C] 8b c2                                        mov     eax, edx
000A05C2 [0042025E] 8b 51 68                                     mov     edx, [ecx+68h]
000A05C5 [00420261] 3b d0                                        cmp     edx, eax
000A05C7 [00420263] 7e 02                                        jle     short near ptr unk_420267 ; game-relative-target=0x000A05CB
000A05C9 [00420265] 8b c2                                        mov     eax, edx
000A05CB [00420267] 3b c7                                        cmp     eax, edi
000A05CD [00420269] 7d 04                                        jge     short near ptr unk_42026F ; game-relative-target=0x000A05D3
000A05CF [0042026B] 8b f8                                        mov     edi, eax
000A05D1 [0042026D] 8b de                                        mov     ebx, esi
000A05D3 [0042026F] 8b 36                                        mov     esi, [esi]
000A05D5 [00420271] 85 f6                                        test    esi, esi
000A05D7 [00420273] 75 c4                                        jnz     short near ptr unk_420239 ; game-relative-target=0x000A059D
000A05D9 [00420275] 85 f6                                        test    esi, esi
000A05DB [00420277] 75 02                                        jnz     short near ptr unk_42027B ; game-relative-target=0x000A05DF
000A05DD [00420279] 8b f3                                        mov     esi, ebx
000A05DF [0042027B] 8b 46 08                                     mov     eax, [esi+8]
000A05E2 [0042027E] 5b                                           pop     ebx
000A05E3 [0042027F] 5f                                           pop     edi
000A05E4 [00420280] 5e                                           pop     esi
000A05E5 [00420281] c3                                           retn
