; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426328; baseline game VA=0x000A5E00; size=408
; Relative branch annotations use the baseline game destination.
000A5E00 [00426328] bf b5 f4 43 00                               mov     edi, 43F4B5h
000A5E05 [0042632D] 8b 4e 38                                     mov     ecx, [esi+38h]
000A5E08 [00426330] 8b 49 08                                     mov     ecx, [ecx+8]
000A5E0B [00426333] 3b 4f fc                                     cmp     ecx, [edi-4]
000A5E0E [00426336] 75 64                                        jnz     short near ptr unk_42639C ; game-relative-target=0x000A5E74
000A5E10 [00426338] 8b 1f                                        mov     ebx, [edi]
000A5E12 [0042633A] 85 db                                        test    ebx, ebx
000A5E14 [0042633C] 74 41                                        jz      short near ptr unk_42637F ; game-relative-target=0x000A5E57
000A5E16 [0042633E] 0f b6 47 04                                  movzx   eax, byte ptr [edi+4]
000A5E1A [00426342] 40                                           inc     eax
000A5E1B [00426343] 88 47 04                                     mov     [edi+4], al
000A5E1E [00426346] 83 c0 05                                     add     eax, 5
000A5E21 [00426349] 0f b6 04 38                                  movzx   eax, byte ptr [eax+edi]
000A5E25 [0042634D] 50                                           push    eax
000A5E26 [0042634E] b8 f0 ef 4a 00                               mov     eax, 4AEFF0h
000A5E2B [00426353] ff d0                                        call    eax
000A5E2D [00426355] 0f b6 d3                                     movzx   edx, bl
000A5E30 [00426358] c1 eb 08                                     shr     ebx, 8
000A5E33 [0042635B] 85 c0                                        test    eax, eax
000A5E35 [0042635D] 74 db                                        jz      short near ptr unk_42633A ; game-relative-target=0x000A5E12
000A5E37 [0042635F] 4a                                           dec     edx
000A5E38 [00426360] 52                                           push    edx
000A5E39 [00426361] b8 20 37 45 00                               mov     eax, 453720h
000A5E3E [00426366] ff d0                                        call    eax
000A5E40 [00426368] 5a                                           pop     edx
000A5E41 [00426369] 89 1f                                        mov     [edi], ebx
000A5E43 [0042636B] 8b 4f fc                                     mov     ecx, [edi-4]
000A5E46 [0042636E] 8b 99 f8 00 00 00                            mov     ebx, [ecx+0F8h]
000A5E4C [00426374] 89 81 f8 00 00 00                            mov     [ecx+0F8h], eax
000A5E52 [0042637A] e9 e8 00 00 00                               jmp     near ptr unk_426467 ; game-relative-target=0x000A5F3F
000A5E57 [0042637F] 8d 4e 34                                     lea     ecx, [esi+34h]
000A5E5A [00426382] b8 10 82 51 00                               mov     eax, 518210h
000A5E5F [00426387] ff d0                                        call    eax
000A5E61 [00426389] 83 7e 40 00                                  cmp     dword ptr [esi+40h], 0
000A5E65 [0042638D] 75 9e                                        jnz     short near ptr unk_42632D ; game-relative-target=0x000A5E05
000A5E67 [0042638F] 33 c0                                        xor     eax, eax
000A5E69 [00426391] 89 47 fc                                     mov     [edi-4], eax
000A5E6C [00426394] 68 35 64 50 00                               push    506435h
000A5E71 [00426399] c2 04 00                                     retn    4
000A5E74 [0042639C] 89 4f fc                                     mov     [edi-4], ecx
000A5E77 [0042639F] 33 db                                        xor     ebx, ebx
000A5E79 [004263A1] 89 1f                                        mov     [edi], ebx
000A5E7B [004263A3] 88 5f 04                                     mov     [edi+4], bl
000A5E7E [004263A6] 8b 81 f8 00 00 00                            mov     eax, [ecx+0F8h]
000A5E84 [004263AC] 85 c0                                        test    eax, eax
000A5E86 [004263AE] 74 cf                                        jz      short near ptr unk_42637F ; game-relative-target=0x000A5E57
000A5E88 [004263B0] 8b 40 54                                     mov     eax, [eax+54h]
000A5E8B [004263B3] 83 f8 03                                     cmp     eax, 3
000A5E8E [004263B6] 7e 5a                                        jle     short near ptr unk_426412 ; game-relative-target=0x000A5EEA
000A5E90 [004263B8] 83 f8 08                                     cmp     eax, 8
000A5E93 [004263BB] 7f c2                                        jg      short near ptr unk_42637F ; game-relative-target=0x000A5E57
000A5E95 [004263BD] 83 f8 06                                     cmp     eax, 6
000A5E98 [004263C0] 7c bd                                        jl      short near ptr unk_42637F ; game-relative-target=0x000A5E57
000A5E9A [004263C2] 8b 41 50                                     mov     eax, [ecx+50h]
000A5E9D [004263C5] 6b c0 03                                     imul    eax, 3
000A5EA0 [004263C8] d1 e8                                        shr     eax, 1
000A5EA2 [004263CA] 3b 41 58                                     cmp     eax, [ecx+58h]
000A5EA5 [004263CD] 7c 41                                        jl      short near ptr unk_426410 ; game-relative-target=0x000A5EE8
000A5EA7 [004263CF] 8b 81 00 01 00 00                            mov     eax, [ecx+100h]
000A5EAD [004263D5] 51                                           push    ecx
000A5EAE [004263D6] 33 c9                                        xor     ecx, ecx
000A5EB0 [004263D8] 41                                           inc     ecx
000A5EB1 [004263D9] 8b 96 84 00 00 00                            mov     edx, [esi+84h]
000A5EB7 [004263DF] f6 42 20 01                                  test    byte ptr [edx+20h], 1
000A5EBB [004263E3] ba 00 00 00 00                               mov     edx, 0
000A5EC0 [004263E8] 74 06                                        jz      short near ptr unk_4263F0 ; game-relative-target=0x000A5EC8
000A5EC2 [004263EA] c1 e8 06                                     shr     eax, 6
000A5EC5 [004263ED] 83 c1 06                                     add     ecx, 6
000A5EC8 [004263F0] a8 01                                        test    al, 1
000A5ECA [004263F2] 74 05                                        jz      short near ptr unk_4263F9 ; game-relative-target=0x000A5ED1
000A5ECC [004263F4] 88 0c 1f                                     mov     [edi+ebx], cl
000A5ECF [004263F7] b6 01                                        mov     dh, 1
000A5ED1 [004263F9] d1 e8                                        shr     eax, 1
000A5ED3 [004263FB] 42                                           inc     edx
000A5ED4 [004263FC] 80 fa 03                                     cmp     dl, 3
000A5ED7 [004263FF] 7c 08                                        jl      short near ptr unk_426409 ; game-relative-target=0x000A5EE1
000A5ED9 [00426401] f6 c6 01                                     test    dh, 1
000A5EDC [00426404] 74 01                                        jz      short near ptr unk_426407 ; game-relative-target=0x000A5EDF
000A5EDE [00426406] 43                                           inc     ebx
000A5EDF [00426407] 33 d2                                        xor     edx, edx
000A5EE1 [00426409] 41                                           inc     ecx
000A5EE2 [0042640A] 80 f9 0c                                     cmp     cl, 0Ch
000A5EE5 [0042640D] 7e e1                                        jle     short near ptr unk_4263F0 ; game-relative-target=0x000A5EC8
000A5EE7 [0042640F] 59                                           pop     ecx
000A5EE8 [00426410] eb 55                                        jmp     short near ptr unk_426467 ; game-relative-target=0x000A5F3F
000A5EEA [00426412] 8b 41 58                                     mov     eax, [ecx+58h]
000A5EED [00426415] 6b c0 03                                     imul    eax, 3
000A5EF0 [00426418] d1 e8                                        shr     eax, 1
000A5EF2 [0042641A] 3b 41 50                                     cmp     eax, [ecx+50h]
000A5EF5 [0042641D] 7c f1                                        jl      short near ptr unk_426410 ; game-relative-target=0x000A5EE8
000A5EF7 [0042641F] 8b 81 02 01 00 00                            mov     eax, [ecx+102h]
000A5EFD [00426425] 8b 96 84 00 00 00                            mov     edx, [esi+84h]
000A5F03 [0042642B] f6 42 20 01                                  test    byte ptr [edx+20h], 1
000A5F07 [0042642F] 75 0a                                        jnz     short near ptr unk_42643B ; game-relative-target=0x000A5F13
000A5F09 [00426431] f6 c4 01                                     test    ah, 1
000A5F0C [00426434] 74 05                                        jz      short near ptr unk_42643B ; game-relative-target=0x000A5F13
000A5F0E [00426436] c6 04 1f 19                                  mov     byte ptr [edi+ebx], 19h
000A5F12 [0042643A] 43                                           inc     ebx
000A5F13 [0042643B] f6 c4 02                                     test    ah, 2
000A5F16 [0042643E] 74 05                                        jz      short near ptr unk_426445 ; game-relative-target=0x000A5F1D
000A5F18 [00426440] c6 04 1f 1a                                  mov     byte ptr [edi+ebx], 1Ah
000A5F1C [00426444] 43                                           inc     ebx
000A5F1D [00426445] a8 80                                        test    al, 80h
000A5F1F [00426447] 74 05                                        jz      short near ptr unk_42644E ; game-relative-target=0x000A5F26
000A5F21 [00426449] c6 04 1f 18                                  mov     byte ptr [edi+ebx], 18h
000A5F25 [0042644D] 43                                           inc     ebx
000A5F26 [0042644E] f6 c4 08                                     test    ah, 8
000A5F29 [00426451] 74 05                                        jz      short near ptr unk_426458 ; game-relative-target=0x000A5F30
000A5F2B [00426453] c6 04 1f 1c                                  mov     byte ptr [edi+ebx], 1Ch
000A5F2F [00426457] 43                                           inc     ebx
000A5F30 [00426458] 80 fb 04                                     cmp     bl, 4
000A5F33 [0042645B] 7d 0a                                        jge     short near ptr unk_426467 ; game-relative-target=0x000A5F3F
000A5F35 [0042645D] f6 c4 10                                     test    ah, 10h
000A5F38 [00426460] 74 05                                        jz      short near ptr unk_426467 ; game-relative-target=0x000A5F3F
000A5F3A [00426462] c6 04 1f 1d                                  mov     byte ptr [edi+ebx], 1Dh
000A5F3E [00426466] 43                                           inc     ebx
000A5F3F [00426467] 83 fb 7f                                     cmp     ebx, 7Fh
000A5F42 [0042646A] 7f 29                                        jg      short near ptr unk_426495 ; game-relative-target=0x000A5F6D
000A5F44 [0042646C] 85 db                                        test    ebx, ebx
000A5F46 [0042646E] 74 25                                        jz      short near ptr unk_426495 ; game-relative-target=0x000A5F6D
000A5F48 [00426470] 51                                           push    ecx
000A5F49 [00426471] 8b 89 f8 00 00 00                            mov     ecx, [ecx+0F8h]
000A5F4F [00426477] 8b 86 80 00 00 00                            mov     eax, [esi+80h]
000A5F55 [0042647D] ff 70 6c                                     push    dword ptr [eax+6Ch]
000A5F58 [00426480] b8 00 31 0a 00                               mov     eax, 0A3100h
000A5F5D [00426485] ff d0                                        call    eax
000A5F5F [00426487] c1 e8 1d                                     shr     eax, 1Dh
000A5F62 [0042648A] 88 47 05                                     mov     [edi+5], al
000A5F65 [0042648D] 59                                           pop     ecx
000A5F66 [0042648E] c7 47 06 32 3c 4b 5f                         mov     dword ptr [edi+6], 5F4B3C32h
000A5F6D [00426495] 89 4e 54                                     mov     [esi+54h], ecx
000A5F70 [00426498] 51                                           push    ecx
000A5F71 [00426499] 8b ce                                        mov     ecx, esi
000A5F73 [0042649B] b8 b0 14 50 00                               mov     eax, 5014B0h
000A5F78 [004264A0] ff d0                                        call    eax
000A5F7A [004264A2] 83 fb 7f                                     cmp     ebx, 7Fh
000A5F7D [004264A5] 7c 09                                        jl      short near ptr unk_4264B0 ; game-relative-target=0x000A5F88
000A5F7F [004264A7] 8b 4f fc                                     mov     ecx, [edi-4]
000A5F82 [004264AA] 89 99 f8 00 00 00                            mov     [ecx+0F8h], ebx
000A5F88 [004264B0] 85 c0                                        test    eax, eax
000A5F8A [004264B2] 0f 84 c7 fe ff ff                            jz      near ptr unk_42637F ; game-relative-target=0x000A5E57
000A5F90 [004264B8] 68 70 64 50 00                               push    506470h
000A5F95 [004264BD] c2 04 00                                     retn    4
