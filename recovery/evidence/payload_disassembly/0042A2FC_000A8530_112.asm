; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A2FC; baseline game VA=0x000A8530; size=274
; Relative branch annotations use the baseline game destination.
000A8530 [0042A2FC] b8 10 ec 50 00                               mov     eax, 50EC10h
000A8535 [0042A301] ff d0                                        call    eax
000A8537 [0042A303] 85 c0                                        test    eax, eax
000A8539 [0042A305] 75 01                                        jnz     short near ptr unk_42A308 ; game-relative-target=0x000A853C
000A853B [0042A307] c3                                           retn
000A853C [0042A308] 56                                           push    esi
000A853D [0042A309] 57                                           push    edi
000A853E [0042A30A] 55                                           push    ebp
000A853F [0042A30B] 53                                           push    ebx
000A8540 [0042A30C] 33 ed                                        xor     ebp, ebp
000A8542 [0042A30E] 50                                           push    eax
000A8543 [0042A30F] 55                                           push    ebp
000A8544 [0042A310] b8 00 71 47 00                               mov     eax, 477100h
000A8549 [0042A315] ff d0                                        call    eax
000A854B [0042A317] 50                                           push    eax
000A854C [0042A318] b8 10 f2 4a 00                               mov     eax, 4AF210h
000A8551 [0042A31D] ff d0                                        call    eax
000A8553 [0042A31F] 5e                                           pop     esi
000A8554 [0042A320] 85 c0                                        test    eax, eax
000A8556 [0042A322] 0f 84 c5 00 00 00                            jz      near ptr unk_42A3ED ; game-relative-target=0x000A8621
000A855C [0042A328] 8b ce                                        mov     ecx, esi
000A855E [0042A32A] 8b 16                                        mov     edx, [esi]
000A8560 [0042A32C] ff 52 34                                     call    dword ptr [edx+34h]
000A8563 [0042A32F] 3b 04 24                                     cmp     eax, [esp]
000A8566 [0042A332] 0f 85 b5 00 00 00                            jnz     near ptr unk_42A3ED ; game-relative-target=0x000A8621
000A856C [0042A338] 83 7e 7c 01                                  cmp     dword ptr [esi+7Ch], 1
000A8570 [0042A33C] 0f 85 ab 00 00 00                            jnz     near ptr unk_42A3ED ; game-relative-target=0x000A8621
000A8576 [0042A342] 8a 85 00 0d 0a 00                            mov     al, [ebp+0A0D00h]
000A857C [0042A348] 84 c0                                        test    al, al
000A857E [0042A34A] 0f 85 9d 00 00 00                            jnz     near ptr unk_42A3ED ; game-relative-target=0x000A8621
000A8584 [0042A350] 8b 86 e8 00 00 00                            mov     eax, [esi+0E8h]
000A858A [0042A356] 48                                           dec     eax
000A858B [0042A357] 0f 8e 90 00 00 00                            jle     near ptr unk_42A3ED ; game-relative-target=0x000A8621
000A8591 [0042A35D] 8b 9e e0 00 00 00                            mov     ebx, [esi+0E0h]
000A8597 [0042A363] 8b 7b 08                                     mov     edi, [ebx+8]
000A859A [0042A366] 8b 1b                                        mov     ebx, [ebx]
000A859C [0042A368] 8d 87 e8 00 00 00                            lea     eax, [edi+0E8h]
000A85A2 [0042A36E] f7 00 04 10 00 00                            test    dword ptr [eax], 1004h
000A85A8 [0042A374] 75 6f                                        jnz     short near ptr unk_42A3E5 ; game-relative-target=0x000A8619
000A85AA [0042A376] 81 08 00 10 00 00                            or      dword ptr [eax], 1000h
000A85B0 [0042A37C] b9 ac 55 54 01                               mov     ecx, 15455ACh
000A85B5 [0042A381] b8 e0 80 51 00                               mov     eax, 5180E0h
000A85BA [0042A386] ff d0                                        call    eax
000A85BC [0042A388] 57                                           push    edi
000A85BD [0042A389] b9 ac 55 54 01                               mov     ecx, 15455ACh
000A85C2 [0042A38E] b8 70 ef 46 00                               mov     eax, 46EF70h
000A85C7 [0042A393] ff d0                                        call    eax
000A85C9 [0042A395] b8 50 60 48 00                               mov     eax, 486050h
000A85CE [0042A39A] ff d0                                        call    eax
000A85D0 [0042A39C] c7 40 44 0a 00 00 00                         mov     dword ptr [eax+44h], 0Ah
000A85D7 [0042A3A3] c7 40 4c 34 60 60 00                         mov     dword ptr [eax+4Ch], 606034h
000A85DE [0042A3AA] 8b 56 04                                     mov     edx, [esi+4]
000A85E1 [0042A3AD] 89 50 50                                     mov     [eax+50h], edx
000A85E4 [0042A3B0] c7 40 54 ff ff ff ff                         mov     dword ptr [eax+54h], 0FFFFFFFFh
000A85EB [0042A3B7] c7 40 58 17 00 00 00                         mov     dword ptr [eax+58h], 17h
000A85F2 [0042A3BE] c7 40 60 00 00 00 00                         mov     dword ptr [eax+60h], 0
000A85F9 [0042A3C5] 6a 00                                        push    0
000A85FB [0042A3C7] 57                                           push    edi
000A85FC [0042A3C8] 56                                           push    esi
000A85FD [0042A3C9] 8b f8                                        mov     edi, eax
000A85FF [0042A3CB] 6a 01                                        push    1
000A8601 [0042A3CD] b8 a0 d4 41 00                               mov     eax, 41D4A0h
000A8606 [0042A3D2] ff d0                                        call    eax
000A8608 [0042A3D4] 50                                           push    eax
000A8609 [0042A3D5] 6a 00                                        push    0
000A860B [0042A3D7] 6a 64                                        push    64h ; 'd'
000A860D [0042A3D9] ff 15 18 f3 5f 00                            call    dword ptr ds:5FF318h
000A8613 [0042A3DF] 83 c4 1c                                     add     esp, 1Ch
000A8616 [0042A3E2] 89 47 5c                                     mov     [edi+5Ch], eax
000A8619 [0042A3E5] 85 db                                        test    ebx, ebx
000A861B [0042A3E7] 0f 85 76 ff ff ff                            jnz     near ptr unk_42A363 ; game-relative-target=0x000A8597
000A8621 [0042A3ED] 45                                           inc     ebp
000A8622 [0042A3EE] 81 fd fa 00 00 00                            cmp     ebp, 0FAh
000A8628 [0042A3F4] 0f 8c 15 ff ff ff                            jl      near ptr unk_42A30F ; game-relative-target=0x000A8543
000A862E [0042A3FA] b9 ac 55 54 01                               mov     ecx, 15455ACh
000A8633 [0042A3FF] b8 e0 80 51 00                               mov     eax, 5180E0h
000A8638 [0042A404] ff d0                                        call    eax
000A863A [0042A406] 83 c4 04                                     add     esp, 4
000A863D [0042A409] 5b                                           pop     ebx
000A863E [0042A40A] 5d                                           pop     ebp
000A863F [0042A40B] 5f                                           pop     edi
000A8640 [0042A40C] 5e                                           pop     esi
000A8641 [0042A40D] c3                                           retn
