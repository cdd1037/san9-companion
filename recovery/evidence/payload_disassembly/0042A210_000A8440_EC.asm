; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A210; baseline game VA=0x000A8440; size=236
; Relative branch annotations use the baseline game destination.
000A8440 [0042A210] b8 10 ec 50 00                               mov     eax, 50EC10h
000A8445 [0042A215] ff d0                                        call    eax
000A8447 [0042A217] 85 c0                                        test    eax, eax
000A8449 [0042A219] 75 01                                        jnz     short near ptr unk_42A21C ; game-relative-target=0x000A844C
000A844B [0042A21B] c3                                           retn
000A844C [0042A21C] 8b 48 14                                     mov     ecx, [eax+14h]
000A844F [0042A21F] 83 f9 64                                     cmp     ecx, 64h ; 'd'
000A8452 [0042A222] 7d 01                                        jge     short near ptr unk_42A225 ; game-relative-target=0x000A8455
000A8454 [0042A224] c3                                           retn
000A8455 [0042A225] 57                                           push    edi
000A8456 [0042A226] 56                                           push    esi
000A8457 [0042A227] bf ac 55 54 01                               mov     edi, 15455ACh
000A845C [0042A22C] 83 ec 24                                     sub     esp, 24h ; '$'
000A845F [0042A22F] 89 44 24 20                                  mov     [esp+20h], eax
000A8463 [0042A233] b8 1f 85 eb 51                               mov     eax, 51EB851Fh
000A8468 [0042A238] f7 e9                                        imul    ecx
000A846A [0042A23A] c1 fa 05                                     sar     edx, 5
000A846D [0042A23D] 8b ca                                        mov     ecx, edx
000A846F [0042A23F] c1 e9 1f                                     shr     ecx, 1Fh
000A8472 [0042A242] 8d 74 11 ec                                  lea     esi, [ecx+edx-14h]
000A8476 [0042A246] 85 f6                                        test    esi, esi
000A8478 [0042A248] 7d 02                                        jge     short near ptr unk_42A24C ; game-relative-target=0x000A847C
000A847A [0042A24A] 33 f6                                        xor     esi, esi
000A847C [0042A24C] 8b cc                                        mov     ecx, esp
000A847E [0042A24E] b8 f0 0d 47 00                               mov     eax, 470DF0h
000A8483 [0042A253] ff d0                                        call    eax
000A8485 [0042A255] 50                                           push    eax
000A8486 [0042A256] 8d 4c 24 ec                                  lea     ecx, [esp-14h]
000A848A [0042A25A] b8 20 6f 4a 00                               mov     eax, 4A6F20h
000A848F [0042A25F] ff d0                                        call    eax
000A8491 [0042A261] 85 c0                                        test    eax, eax
000A8493 [0042A263] 74 7f                                        jz      short near ptr unk_42A2E4 ; game-relative-target=0x000A8514
000A8495 [0042A265] 8b d4                                        mov     edx, esp
000A8497 [0042A267] 6a 00                                        push    0
000A8499 [0042A269] 68 60 2c 47 00                               push    472C60h
000A849E [0042A26E] 52                                           push    edx
000A849F [0042A26F] 8b cf                                        mov     ecx, edi
000A84A1 [0042A271] b8 c0 f3 46 00                               mov     eax, 46F3C0h
000A84A6 [0042A276] ff d0                                        call    eax
000A84A8 [0042A278] 85 c0                                        test    eax, eax
000A84AA [0042A27A] 74 68                                        jz      short near ptr unk_42A2E4 ; game-relative-target=0x000A8514
000A84AC [0042A27C] 3b f0                                        cmp     esi, eax
000A84AE [0042A27E] 7e 02                                        jle     short near ptr unk_42A282 ; game-relative-target=0x000A84B2
000A84B0 [0042A280] 8b f0                                        mov     esi, eax
000A84B2 [0042A282] 8b cc                                        mov     ecx, esp
000A84B4 [0042A284] 57                                           push    edi
000A84B5 [0042A285] b8 00 f2 46 00                               mov     eax, 46F200h
000A84BA [0042A28A] ff d0                                        call    eax
000A84BC [0042A28C] 8b cc                                        mov     ecx, esp
000A84BE [0042A28E] 6a 01                                        push    1
000A84C0 [0042A290] 6a 51                                        push    51h ; 'Q'
000A84C2 [0042A292] b8 40 f6 46 00                               mov     eax, 46F640h
000A84C7 [0042A297] ff d0                                        call    eax
000A84C9 [0042A299] 8b cf                                        mov     ecx, edi
000A84CB [0042A29B] 6a 00                                        push    0
000A84CD [0042A29D] 68 30 70 4a 00                               push    4A7030h
000A84D2 [0042A2A2] b8 10 f6 46 00                               mov     eax, 46F610h
000A84D7 [0042A2A7] ff d0                                        call    eax
000A84D9 [0042A2A9] 8b cf                                        mov     ecx, edi
000A84DB [0042A2AB] 56                                           push    esi
000A84DC [0042A2AC] b8 b0 ee 46 00                               mov     eax, 46EEB0h
000A84E1 [0042A2B1] ff d0                                        call    eax
000A84E3 [0042A2B3] 8b cc                                        mov     ecx, esp
000A84E5 [0042A2B5] 8b 51 0c                                     mov     edx, [ecx+0Ch]
000A84E8 [0042A2B8] 68 80 3e 4d 00                               push    4D3E80h
000A84ED [0042A2BD] 6a 01                                        push    1
000A84EF [0042A2BF] 68 ec c5 66 00                               push    66C5ECh
000A84F4 [0042A2C4] 68 66 1f 00 00                               push    1F66h
000A84F9 [0042A2C9] 52                                           push    edx
000A84FA [0042A2CA] 51                                           push    ecx
000A84FB [0042A2CB] 57                                           push    edi
000A84FC [0042A2CC] b8 00 05 57 00                               mov     eax, 570500h
000A8501 [0042A2D1] ff d0                                        call    eax
000A8503 [0042A2D3] 83 c4 1c                                     add     esp, 1Ch
000A8506 [0042A2D6] 85 c0                                        test    eax, eax
000A8508 [0042A2D8] 74 0a                                        jz      short near ptr unk_42A2E4 ; game-relative-target=0x000A8514
000A850A [0042A2DA] 8d 4f c0                                     lea     ecx, [edi-40h]
000A850D [0042A2DD] b8 00 76 48 00                               mov     eax, 487600h
000A8512 [0042A2E2] ff d0                                        call    eax
000A8514 [0042A2E4] 8b cf                                        mov     ecx, edi
000A8516 [0042A2E6] b8 e0 80 51 00                               mov     eax, 5180E0h
000A851B [0042A2EB] ff d0                                        call    eax
000A851D [0042A2ED] 8b cc                                        mov     ecx, esp
000A851F [0042A2EF] b8 10 0e 47 00                               mov     eax, 470E10h
000A8524 [0042A2F4] ff d0                                        call    eax
000A8526 [0042A2F6] 83 c4 24                                     add     esp, 24h ; '$'
000A8529 [0042A2F9] 5e                                           pop     esi
000A852A [0042A2FA] 5f                                           pop     edi
000A852B [0042A2FB] c3                                           retn
