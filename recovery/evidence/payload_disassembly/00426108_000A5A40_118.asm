; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426108; baseline game VA=0x000A5A40; size=280
; Relative branch annotations use the baseline game destination.
000A5A40 [00426108] 8b 4c 24 04                                  mov     ecx, [esp+4]
000A5A44 [0042610C] 8b 81 cc 00 00 00                            mov     eax, [ecx+0CCh]
000A5A4A [00426112] 85 c0                                        test    eax, eax
000A5A4C [00426114] 75 05                                        jnz     short near ptr unk_42611B ; game-relative-target=0x000A5A53
000A5A4E [00426116] 33 c0                                        xor     eax, eax
000A5A50 [00426118] c2 04 00                                     retn    4
000A5A53 [0042611B] f6 40 34 04                                  test    byte ptr [eax+34h], 4
000A5A57 [0042611F] 74 09                                        jz      short near ptr unk_42612A ; game-relative-target=0x000A5A62
000A5A59 [00426121] 8b 81 88 00 00 00                            mov     eax, [ecx+88h]
000A5A5F [00426127] c2 04 00                                     retn    4
000A5A62 [0042612A] 56                                           push    esi
000A5A63 [0042612B] 57                                           push    edi
000A5A64 [0042612C] 53                                           push    ebx
000A5A65 [0042612D] 55                                           push    ebp
000A5A66 [0042612E] 8b d9                                        mov     ebx, ecx
000A5A68 [00426130] b8 90 19 0a 00                               mov     eax, 0A1990h
000A5A6D [00426135] ff d0                                        call    eax
000A5A6F [00426137] 03 83 88 00 00 00                            add     eax, [ebx+88h]
000A5A75 [0042613D] 8b f0                                        mov     esi, eax
000A5A77 [0042613F] 99                                           cdq
000A5A78 [00426140] b9 10 27 00 00                               mov     ecx, 2710h
000A5A7D [00426145] f7 f1                                        div     ecx
000A5A7F [00426147] 66 81 fa 88 13                               cmp     dx, 1388h
000A5A84 [0042614C] 7c 01                                        jl      short near ptr unk_42614F ; game-relative-target=0x000A5A87
000A5A86 [0042614E] 40                                           inc     eax
000A5A87 [0042614F] 85 c0                                        test    eax, eax
000A5A89 [00426151] 0f 84 9f 00 00 00                            jz      near ptr unk_4261F6 ; game-relative-target=0x000A5B2E
000A5A8F [00426157] 50                                           push    eax
000A5A90 [00426158] 33 c9                                        xor     ecx, ecx
000A5A92 [0042615A] ba e0 8e 25 01                               mov     edx, 1258EE0h
000A5A97 [0042615F] 33 ff                                        xor     edi, edi
000A5A99 [00426161] 8b 82 84 00 00 00                            mov     eax, [edx+84h]
000A5A9F [00426167] 85 c0                                        test    eax, eax
000A5AA1 [00426169] 7c 27                                        jl      short near ptr unk_426192 ; game-relative-target=0x000A5ACA
000A5AA3 [0042616B] 3c 03                                        cmp     al, 3
000A5AA5 [0042616D] 7f 23                                        jg      short near ptr unk_426192 ; game-relative-target=0x000A5ACA
000A5AA7 [0042616F] 8b aa f4 00 00 00                            mov     ebp, [edx+0F4h]
000A5AAD [00426175] 39 5d 64                                     cmp     [ebp+64h], ebx
000A5AB0 [00426178] 75 18                                        jnz     short near ptr unk_426192 ; game-relative-target=0x000A5ACA
000A5AB2 [0042617A] 8b 45 58                                     mov     eax, [ebp+58h]
000A5AB5 [0042617D] 83 f8 26                                     cmp     eax, 26h ; '&'
000A5AB8 [00426180] 7c 0f                                        jl      short near ptr unk_426191 ; game-relative-target=0x000A5AC9
000A5ABA [00426182] 83 f8 32                                     cmp     eax, 32h ; '2'
000A5ABD [00426185] 7f 0a                                        jg      short near ptr unk_426191 ; game-relative-target=0x000A5AC9
000A5ABF [00426187] 83 f8 27                                     cmp     eax, 27h ; '''
000A5AC2 [0042618A] 75 06                                        jnz     short near ptr unk_426192 ; game-relative-target=0x000A5ACA
000A5AC4 [0042618C] 39 5d 50                                     cmp     [ebp+50h], ebx
000A5AC7 [0042618F] 75 01                                        jnz     short near ptr unk_426192 ; game-relative-target=0x000A5ACA
000A5AC9 [00426191] 41                                           inc     ecx
000A5ACA [00426192] 81 c2 28 01 00 00                            add     edx, 128h
000A5AD0 [00426198] 47                                           inc     edi
000A5AD1 [00426199] 66 81 ff 52 03                               cmp     di, 352h
000A5AD6 [0042619E] 7c c1                                        jl      short near ptr unk_426161 ; game-relative-target=0x000A5A99
000A5AD8 [004261A0] 5d                                           pop     ebp
000A5AD9 [004261A1] 3b cd                                        cmp     ecx, ebp
000A5ADB [004261A3] 7f 1e                                        jg      short near ptr unk_4261C3 ; game-relative-target=0x000A5AFB
000A5ADD [004261A5] b8 ff ff ff 7f                               mov     eax, 7FFFFFFFh
000A5AE2 [004261AA] 99                                           cdq
000A5AE3 [004261AB] f7 f5                                        div     ebp
000A5AE5 [004261AD] f7 e9                                        imul    ecx
000A5AE7 [004261AF] 3d 99 99 99 59                               cmp     eax, 59999999h
000A5AEC [004261B4] 7d 05                                        jge     short near ptr unk_4261BB ; game-relative-target=0x000A5AF3
000A5AEE [004261B6] b8 99 99 99 59                               mov     eax, 59999999h
000A5AF3 [004261BB] f7 ee                                        imul    esi
000A5AF5 [004261BD] 8b f2                                        mov     esi, edx
000A5AF7 [004261BF] d1 e6                                        shl     esi, 1
000A5AF9 [004261C1] eb 33                                        jmp     short near ptr unk_4261F6 ; game-relative-target=0x000A5B2E
000A5AFB [004261C3] 2b cd                                        sub     ecx, ebp
000A5AFD [004261C5] 8b c1                                        mov     eax, ecx
000A5AFF [004261C7] 99                                           cdq
000A5B00 [004261C8] f7 f5                                        div     ebp
000A5B02 [004261CA] 66 3d 03 00                                  cmp     ax, 3
000A5B06 [004261CE] 7e 06                                        jle     short near ptr unk_4261D6 ; game-relative-target=0x000A5B0E
000A5B08 [004261D0] 66 b8 03 00                                  mov     ax, 3
000A5B0C [004261D4] 33 d2                                        xor     edx, edx
000A5B0E [004261D6] 50                                           push    eax
000A5B0F [004261D7] 52                                           push    edx
000A5B10 [004261D8] b8 ff ff ff 7f                               mov     eax, 7FFFFFFFh
000A5B15 [004261DD] 99                                           cdq
000A5B16 [004261DE] f7 f5                                        div     ebp
000A5B18 [004261E0] 5a                                           pop     edx
000A5B19 [004261E1] f7 ea                                        imul    edx
000A5B1B [004261E3] b9 33 33 33 33                               mov     ecx, 33333333h
000A5B20 [004261E8] f7 e9                                        imul    ecx
000A5B22 [004261EA] 58                                           pop     eax
000A5B23 [004261EB] d1 e9                                        shr     ecx, 1
000A5B25 [004261ED] 0f af c1                                     imul    eax, ecx
000A5B28 [004261F0] 03 c2                                        add     eax, edx
000A5B2A [004261F2] f7 ee                                        imul    esi
000A5B2C [004261F4] 03 f2                                        add     esi, edx
000A5B2E [004261F6] bf b0 93 4b 01                               mov     edi, 14B93B0h
000A5B33 [004261FB] 39 5f 64                                     cmp     [edi+64h], ebx
000A5B36 [004261FE] 75 09                                        jnz     short near ptr unk_426209 ; game-relative-target=0x000A5B41
000A5B38 [00426200] f6 47 20 0b                                  test    byte ptr [edi+20h], 0Bh
000A5B3C [00426204] 75 03                                        jnz     short near ptr unk_426209 ; game-relative-target=0x000A5B41
000A5B3E [00426206] 03 77 30                                     add     esi, [edi+30h]
000A5B41 [00426209] 81 c7 04 01 00 00                            add     edi, 104h
000A5B47 [0042620F] 66 81 7f 04 51 03                            cmp     word ptr [edi+4], 351h
000A5B4D [00426215] 7c e4                                        jl      short near ptr unk_4261FB ; game-relative-target=0x000A5B33
000A5B4F [00426217] 8b c6                                        mov     eax, esi
000A5B51 [00426219] 5d                                           pop     ebp
000A5B52 [0042621A] 5b                                           pop     ebx
000A5B53 [0042621B] 5f                                           pop     edi
000A5B54 [0042621C] 5e                                           pop     esi
000A5B55 [0042621D] c2 04 00                                     retn    4
