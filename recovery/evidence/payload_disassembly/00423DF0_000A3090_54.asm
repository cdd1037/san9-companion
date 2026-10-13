; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423DF0; baseline game VA=0x000A3090; size=84
; Relative branch annotations use the baseline game destination.
000A3090 [00423DF0] 51                                           push    ecx
000A3091 [00423DF1] b8 d0 95 4b 00                               mov     eax, 4B95D0h
000A3096 [00423DF6] ff d0                                        call    eax
000A3098 [00423DF8] 85 db                                        test    ebx, ebx
000A309A [00423DFA] 74 09                                        jz      short near ptr unk_423E05 ; game-relative-target=0x000A30A5
000A309C [00423DFC] 8b 4e 38                                     mov     ecx, [esi+38h]
000A309F [00423DFF] f6 41 34 04                                  test    byte ptr [ecx+34h], 4
000A30A3 [00423E03] 74 02                                        jz      short near ptr unk_423E07 ; game-relative-target=0x000A30A7
000A30A5 [00423E05] 59                                           pop     ecx
000A30A6 [00423E06] c3                                           retn
000A30A7 [00423E07] 59                                           pop     ecx
000A30A8 [00423E08] 8b 43 44                                     mov     eax, [ebx+44h]
000A30AB [00423E0B] 8a 40 04                                     mov     al, [eax+4]
000A30AE [00423E0E] 3c 00                                        cmp     al, 0
000A30B0 [00423E10] 74 29                                        jz      short near ptr unk_423E3B ; game-relative-target=0x000A30DB
000A30B2 [00423E12] 3c 0b                                        cmp     al, 0Bh
000A30B4 [00423E14] 74 25                                        jz      short near ptr unk_423E3B ; game-relative-target=0x000A30DB
000A30B6 [00423E16] 3c 0f                                        cmp     al, 0Fh
000A30B8 [00423E18] 7d 21                                        jge     short near ptr unk_423E3B ; game-relative-target=0x000A30DB
000A30BA [00423E1A] 3c 02                                        cmp     al, 2
000A30BC [00423E1C] 75 25                                        jnz     short near ptr unk_423E43 ; game-relative-target=0x000A30E3
000A30BE [00423E1E] 83 c1 2c                                     add     ecx, 2Ch ; ','
000A30C1 [00423E21] 51                                           push    ecx
000A30C2 [00423E22] 6a 01                                        push    1
000A30C4 [00423E24] b8 60 bb 48 00                               mov     eax, 48BB60h
000A30C9 [00423E29] ff d0                                        call    eax
000A30CB [00423E2B] 8b f8                                        mov     edi, eax
000A30CD [00423E2D] 59                                           pop     ecx
000A30CE [00423E2E] 6a 02                                        push    2
000A30D0 [00423E30] b8 60 bb 48 00                               mov     eax, 48BB60h
000A30D5 [00423E35] ff d0                                        call    eax
000A30D7 [00423E37] 3b f8                                        cmp     edi, eax
000A30D9 [00423E39] 7c 08                                        jl      short near ptr unk_423E43 ; game-relative-target=0x000A30E3
000A30DB [00423E3B] b0 01                                        mov     al, 1
000A30DD [00423E3D] 88 83 a4 00 00 00                            mov     [ebx+0A4h], al
000A30E3 [00423E43] c3                                           retn
