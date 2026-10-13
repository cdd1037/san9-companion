; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422684; baseline game VA=0x000A2100; size=110
; Relative branch annotations use the baseline game destination.
000A2100 [00422684] 56                                           push    esi
000A2101 [00422685] 57                                           push    edi
000A2102 [00422686] 53                                           push    ebx
000A2103 [00422687] 55                                           push    ebp
000A2104 [00422688] 52                                           push    edx
000A2105 [00422689] 8b 71 64                                     mov     esi, [ecx+64h]
000A2108 [0042268C] ba 03 00 00 00                               mov     edx, 3
000A210D [00422691] b9 50 00 00 00                               mov     ecx, 50h ; 'P'
000A2112 [00422696] bf 19 00 00 00                               mov     edi, 19h
000A2117 [0042269B] 3b 76 44                                     cmp     esi, [esi+44h]
000A211A [0042269E] 75 14                                        jnz     short near ptr unk_4226B4 ; game-relative-target=0x000A2130
000A211C [004226A0] f6 46 51 ff                                  test    byte ptr [esi+51h], 0FFh
000A2120 [004226A4] 75 0e                                        jnz     short near ptr unk_4226B4 ; game-relative-target=0x000A2130
000A2122 [004226A6] b2 07                                        mov     dl, 7
000A2124 [004226A8] b1 58                                        mov     cl, 58h ; 'X'
000A2126 [004226AA] d1 ef                                        shr     edi, 1
000A2128 [004226AC] f6 46 53 40                                  test    byte ptr [esi+53h], 40h ; '@'
000A212C [004226B0] 74 02                                        jz      short near ptr unk_4226B4 ; game-relative-target=0x000A2130
000A212E [004226B2] b2 08                                        mov     dl, 8
000A2130 [004226B4] 33 db                                        xor     ebx, ebx
000A2132 [004226B6] 8b b6 e0 00 00 00                            mov     esi, [esi+0E0h]
000A2138 [004226BC] 8b 6e 08                                     mov     ebp, [esi+8]
000A213B [004226BF] 83 bd 80 00 00 00 00                         cmp     dword ptr [ebp+80h], 0
000A2142 [004226C6] 7f 18                                        jg      short near ptr unk_4226E0 ; game-relative-target=0x000A215C
000A2144 [004226C8] 8b 44 0d 00                                  mov     eax, [ebp+ecx+0]
000A2148 [004226CC] 0f af c7                                     imul    eax, edi
000A214B [004226CF] 66 03 84 55 a4 00 00 00                      add     ax, [ebp+edx*2+0A4h]
000A2153 [004226D7] 3b c3                                        cmp     eax, ebx
000A2155 [004226D9] 7e 05                                        jle     short near ptr unk_4226E0 ; game-relative-target=0x000A215C
000A2157 [004226DB] 8b d8                                        mov     ebx, eax
000A2159 [004226DD] 89 2c 24                                     mov     [esp], ebp
000A215C [004226E0] 8b 36                                        mov     esi, [esi]
000A215E [004226E2] 85 f6                                        test    esi, esi
000A2160 [004226E4] 75 d6                                        jnz     short near ptr unk_4226BC ; game-relative-target=0x000A2138
000A2162 [004226E6] 58                                           pop     eax
000A2163 [004226E7] 85 db                                        test    ebx, ebx
000A2165 [004226E9] 75 02                                        jnz     short near ptr unk_4226ED ; game-relative-target=0x000A2169
000A2167 [004226EB] 8b c5                                        mov     eax, ebp
000A2169 [004226ED] 5d                                           pop     ebp
000A216A [004226EE] 5b                                           pop     ebx
000A216B [004226EF] 5f                                           pop     edi
000A216C [004226F0] 5e                                           pop     esi
000A216D [004226F1] c3                                           retn
