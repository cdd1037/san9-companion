; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424958; baseline game VA=0x000A3B00; size=208
; Relative branch annotations use the baseline game destination.
000A3B00 [00424958] 53                                           push    ebx
000A3B01 [00424959] b8 40 5a 0a 00                               mov     eax, 0A5A40h
000A3B06 [0042495E] ff d0                                        call    eax
000A3B08 [00424960] 8b 8b cc 00 00 00                            mov     ecx, [ebx+0CCh]
000A3B0E [00424966] 85 c9                                        test    ecx, ecx
000A3B10 [00424968] 75 03                                        jnz     short near ptr unk_42496D ; game-relative-target=0x000A3B15
000A3B12 [0042496A] c2 04 00                                     retn    4
000A3B15 [0042496D] 8b 89 b8 00 00 00                            mov     ecx, [ecx+0B8h]
000A3B1B [00424973] f6 41 34 01                                  test    byte ptr [ecx+34h], 1
000A3B1F [00424977] 74 f1                                        jz      short near ptr unk_42496A ; game-relative-target=0x000A3B12
000A3B21 [00424979] 57                                           push    edi
000A3B22 [0042497A] 55                                           push    ebp
000A3B23 [0042497B] 8b f0                                        mov     esi, eax
000A3B25 [0042497D] 8b e9                                        mov     ebp, ecx
000A3B27 [0042497F] bf b0 93 4b 01                               mov     edi, 14B93B0h
000A3B2C [00424984] 39 6f 74                                     cmp     [edi+74h], ebp
000A3B2F [00424987] 75 32                                        jnz     short near ptr unk_4249BB ; game-relative-target=0x000A3B63
000A3B31 [00424989] 8b 47 20                                     mov     eax, [edi+20h]
000A3B34 [0042498C] a9 06 00 70 00                               test    eax, 700006h
000A3B39 [00424991] 75 28                                        jnz     short near ptr unk_4249BB ; game-relative-target=0x000A3B63
000A3B3B [00424993] a8 08                                        test    al, 8
000A3B3D [00424995] 75 05                                        jnz     short near ptr unk_42499C ; game-relative-target=0x000A3B44
000A3B3F [00424997] 39 5f 64                                     cmp     [edi+64h], ebx
000A3B42 [0042499A] 74 1f                                        jz      short near ptr unk_4249BB ; game-relative-target=0x000A3B63
000A3B44 [0042499C] 8b cf                                        mov     ecx, edi
000A3B46 [0042499E] b8 90 e3 45 00                               mov     eax, 45E390h
000A3B4B [004249A3] ff d0                                        call    eax
000A3B4D [004249A5] 85 c0                                        test    eax, eax
000A3B4F [004249A7] 75 14                                        jnz     short near ptr unk_4249BD ; game-relative-target=0x000A3B65
000A3B51 [004249A9] 8b 4f 6c                                     mov     ecx, [edi+6Ch]
000A3B54 [004249AC] 8a 41 04                                     mov     al, [ecx+4]
000A3B57 [004249AF] 3c 0b                                        cmp     al, 0Bh
000A3B59 [004249B1] 74 0a                                        jz      short near ptr unk_4249BD ; game-relative-target=0x000A3B65
000A3B5B [004249B3] 3c 05                                        cmp     al, 5
000A3B5D [004249B5] 7f 04                                        jg      short near ptr unk_4249BB ; game-relative-target=0x000A3B63
000A3B5F [004249B7] 3c 04                                        cmp     al, 4
000A3B61 [004249B9] 75 02                                        jnz     short near ptr unk_4249BD ; game-relative-target=0x000A3B65
000A3B63 [004249BB] eb 43                                        jmp     short near ptr unk_424A00 ; game-relative-target=0x000A3BA8
000A3B65 [004249BD] 80 7f 52 03                                  cmp     byte ptr [edi+52h], 3
000A3B69 [004249C1] 75 1c                                        jnz     short near ptr unk_4249DF ; game-relative-target=0x000A3B87
000A3B6B [004249C3] 0f b7 47 50                                  movzx   eax, word ptr [edi+50h]
000A3B6F [004249C7] 50                                           push    eax
000A3B70 [004249C8] b8 c0 32 45 00                               mov     eax, 4532C0h
000A3B75 [004249CD] ff d0                                        call    eax
000A3B77 [004249CF] 59                                           pop     ecx
000A3B78 [004249D0] 50                                           push    eax
000A3B79 [004249D1] 8b cf                                        mov     ecx, edi
000A3B7B [004249D3] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A3B80 [004249D8] ff d0                                        call    eax
000A3B82 [004249DA] 83 f8 32                                     cmp     eax, 32h ; '2'
000A3B85 [004249DD] 7c 21                                        jl      short near ptr unk_424A00 ; game-relative-target=0x000A3BA8
000A3B87 [004249DF] 53                                           push    ebx
000A3B88 [004249E0] 8b cf                                        mov     ecx, edi
000A3B8A [004249E2] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A3B8F [004249E7] ff d0                                        call    eax
000A3B91 [004249E9] 83 f8 64                                     cmp     eax, 64h ; 'd'
000A3B94 [004249EC] 7d 12                                        jge     short near ptr unk_424A00 ; game-relative-target=0x000A3BA8
000A3B96 [004249EE] 53                                           push    ebx
000A3B97 [004249EF] 8b cf                                        mov     ecx, edi
000A3B99 [004249F1] b8 70 88 46 00                               mov     eax, 468870h
000A3B9E [004249F6] ff d0                                        call    eax
000A3BA0 [004249F8] 83 f8 14                                     cmp     eax, 14h
000A3BA3 [004249FB] 7d 03                                        jge     short near ptr unk_424A00 ; game-relative-target=0x000A3BA8
000A3BA5 [004249FD] 03 77 30                                     add     esi, [edi+30h]
000A3BA8 [00424A00] 81 c7 04 01 00 00                            add     edi, 104h
000A3BAE [00424A06] 66 81 7f 04 51 03                            cmp     word ptr [edi+4], 351h
000A3BB4 [00424A0C] 0f 8c 72 ff ff ff                            jl      near ptr unk_424984 ; game-relative-target=0x000A3B2C
000A3BBA [00424A12] 8b cb                                        mov     ecx, ebx
000A3BBC [00424A14] b8 78 68 0a 00                               mov     eax, 0A6878h
000A3BC1 [00424A19] ff d0                                        call    eax
000A3BC3 [00424A1B] 03 c6                                        add     eax, esi
000A3BC5 [00424A1D] 5d                                           pop     ebp
000A3BC6 [00424A1E] 5f                                           pop     edi
000A3BC7 [00424A1F] 89 85 28 04 00 00                            mov     [ebp+428h], eax
000A3BCD [00424A25] c2 04 00                                     retn    4
