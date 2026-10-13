; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423A68; baseline game VA=0x000A3400; size=166
; Relative branch annotations use the baseline game destination.
000A3400 [00423A68] 57                                           push    edi
000A3401 [00423A69] 56                                           push    esi
000A3402 [00423A6A] fe 0d 15 ff 43 00                            dec     byte ptr ds:43FF15h
000A3408 [00423A70] 33 c0                                        xor     eax, eax
000A340A [00423A72] b9 32 00 00 00                               mov     ecx, 32h ; '2'
000A340F [00423A77] bf 00 79 0a 00                               mov     edi, 0A7900h
000A3414 [00423A7C] f3 aa                                        rep stosb
000A3416 [00423A7E] 80 3d 1b ff 43 00 00                         cmp     byte ptr ds:43FF1Bh, 0
000A341D [00423A85] 74 7e                                        jz      short near ptr unk_423B05 ; game-relative-target=0x000A349D
000A341F [00423A87] 33 ff                                        xor     edi, edi
000A3421 [00423A89] 57                                           push    edi
000A3422 [00423A8A] b8 00 71 47 00                               mov     eax, 477100h
000A3427 [00423A8F] ff d0                                        call    eax
000A3429 [00423A91] 85 c0                                        test    eax, eax
000A342B [00423A93] 74 67                                        jz      short near ptr unk_423AFC ; game-relative-target=0x000A3494
000A342D [00423A95] 8b f0                                        mov     esi, eax
000A342F [00423A97] 8b c8                                        mov     ecx, eax
000A3431 [00423A99] b8 20 54 43 00                               mov     eax, 435420h
000A3436 [00423A9E] ff d0                                        call    eax
000A3438 [00423AA0] 85 c0                                        test    eax, eax
000A343A [00423AA2] 74 58                                        jz      short near ptr unk_423AFC ; game-relative-target=0x000A3494
000A343C [00423AA4] f6 46 7a 40                                  test    byte ptr [esi+7Ah], 40h ; '@'
000A3440 [00423AA8] 74 52                                        jz      short near ptr unk_423AFC ; game-relative-target=0x000A3494
000A3442 [00423AAA] 80 7e 7c 01                                  cmp     byte ptr [esi+7Ch], 1
000A3446 [00423AAE] 75 4c                                        jnz     short near ptr unk_423AFC ; game-relative-target=0x000A3494
000A3448 [00423AB0] 0f b7 46 3c                                  movzx   eax, word ptr [esi+3Ch]
000A344C [00423AB4] 6b c0 05                                     imul    eax, 5
000A344F [00423AB7] 8b 4e 48                                     mov     ecx, [esi+48h]
000A3452 [00423ABA] 3b 41 24                                     cmp     eax, [ecx+24h]
000A3455 [00423ABD] 7d 3d                                        jge     short near ptr unk_423AFC ; game-relative-target=0x000A3494
000A3457 [00423ABF] 8b 86 e0 00 00 00                            mov     eax, [esi+0E0h]
000A345D [00423AC5] 85 c0                                        test    eax, eax
000A345F [00423AC7] 74 06                                        jz      short near ptr unk_423ACF ; game-relative-target=0x000A3467
000A3461 [00423AC9] 8b 48 08                                     mov     ecx, [eax+8]
000A3464 [00423ACC] 8b 41 68                                     mov     eax, [ecx+68h]
000A3467 [00423ACF] c1 e8 01                                     shr     eax, 1
000A346A [00423AD2] 83 e8 3c                                     sub     eax, 3Ch ; '<'
000A346D [00423AD5] f7 d8                                        neg     eax
000A346F [00423AD7] 50                                           push    eax
000A3470 [00423AD8] b8 f0 ef 4a 00                               mov     eax, 4AEFF0h
000A3475 [00423ADD] ff d0                                        call    eax
000A3477 [00423ADF] 85 c0                                        test    eax, eax
000A3479 [00423AE1] 74 19                                        jz      short near ptr unk_423AFC ; game-relative-target=0x000A3494
000A347B [00423AE3] 6a 78                                        push    78h ; 'x'
000A347D [00423AE5] 58                                           pop     eax
000A347E [00423AE6] 2b 86 90 00 00 00                            sub     eax, [esi+90h]
000A3484 [00423AEC] 99                                           cdq
000A3485 [00423AED] 6a 14                                        push    14h
000A3487 [00423AEF] 59                                           pop     ecx
000A3488 [00423AF0] f7 f1                                        div     ecx
000A348A [00423AF2] 88 86 80 00 00 00                            mov     [esi+80h], al
000A3490 [00423AF8] c6 46 7c 06                                  mov     byte ptr [esi+7Ch], 6
000A3494 [00423AFC] 47                                           inc     edi
000A3495 [00423AFD] 81 ff fa 00 00 00                            cmp     edi, 0FAh
000A349B [00423B03] 7c 84                                        jl      short near ptr unk_423A89 ; game-relative-target=0x000A3421
000A349D [00423B05] 5e                                           pop     esi
000A349E [00423B06] 5f                                           pop     edi
000A349F [00423B07] 68 50 2e 45 00                               push    452E50h
000A34A4 [00423B0C] c3                                           retn
000A34A5 [00423B0D] 90                                           nop
