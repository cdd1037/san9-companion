; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428168; baseline game VA=0x000A7300; size=457
; Relative branch annotations use the baseline game destination.
000A7300 [00428168] 8b 51 74                                     mov     edx, [ecx+74h]
000A7303 [0042816B] f6 42 34 01                                  test    byte ptr [edx+34h], 1
000A7307 [0042816F] 74 16                                        jz      short near ptr unk_428187 ; game-relative-target=0x000A731F
000A7309 [00428171] 83 79 54 ff                                  cmp     dword ptr [ecx+54h], 0FFFFFFFFh
000A730D [00428175] 75 10                                        jnz     short near ptr unk_428187 ; game-relative-target=0x000A731F
000A730F [00428177] 8b 44 24 04                                  mov     eax, [esp+4]
000A7313 [0042817B] 8b 80 cc 00 00 00                            mov     eax, [eax+0CCh]
000A7319 [00428181] f6 40 0d 01                                  test    byte ptr [eax+0Dh], 1
000A731D [00428185] 74 06                                        jz      short near ptr unk_42818D ; game-relative-target=0x000A7325
000A731F [00428187] 68 70 88 46 00                               push    468870h
000A7324 [0042818C] c3                                           retn
000A7325 [0042818D] 56                                           push    esi
000A7326 [0042818E] 57                                           push    edi
000A7327 [0042818F] 53                                           push    ebx
000A7328 [00428190] 55                                           push    ebp
000A7329 [00428191] 8b 6c 24 14                                  mov     ebp, [esp+14h]
000A732D [00428195] 81 ec d0 00 00 00                            sub     esp, 0D0h
000A7333 [0042819B] 8b f1                                        mov     esi, ecx
000A7335 [0042819D] ff 71 50                                     push    dword ptr [ecx+50h]
000A7338 [004281A0] b8 c0 37 45 00                               mov     eax, 4537C0h
000A733D [004281A5] ff d0                                        call    eax
000A733F [004281A7] 5a                                           pop     edx
000A7340 [004281A8] 85 c0                                        test    eax, eax
000A7342 [004281AA] bf 64 00 00 00                               mov     edi, 64h ; 'd'
000A7347 [004281AF] 0f 84 6d 01 00 00                            jz      near ptr unk_428322 ; game-relative-target=0x000A74BA
000A734D [004281B5] 8b c8                                        mov     ecx, eax
000A734F [004281B7] 8b 01                                        mov     eax, [ecx]
000A7351 [004281B9] ff 90 b8 00 00 00                            call    dword ptr [eax+0B8h]
000A7357 [004281BF] 8b f8                                        mov     edi, eax
000A7359 [004281C1] 8b cc                                        mov     ecx, esp
000A735B [004281C3] b8 b0 34 47 00                               mov     eax, 4734B0h
000A7360 [004281C8] ff d0                                        call    eax
000A7362 [004281CA] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A7366 [004281CE] b8 b0 34 47 00                               mov     eax, 4734B0h
000A736B [004281D3] ff d0                                        call    eax
000A736D [004281D5] 8b 9e 80 00 00 00                            mov     ebx, [esi+80h]
000A7373 [004281DB] 85 db                                        test    ebx, ebx
000A7375 [004281DD] 75 1b                                        jnz     short near ptr unk_4281FA ; game-relative-target=0x000A7392
000A7377 [004281DF] 8d 4c 24 40                                  lea     ecx, [esp+40h]
000A737B [004281E3] 57                                           push    edi
000A737C [004281E4] 56                                           push    esi
000A737D [004281E5] b8 30 a3 47 00                               mov     eax, 47A330h
000A7382 [004281EA] ff d0                                        call    eax
000A7384 [004281EC] 8d 4c 24 40                                  lea     ecx, [esp+40h]
000A7388 [004281F0] 54                                           push    esp
000A7389 [004281F1] b8 90 82 47 00                               mov     eax, 478290h
000A738E [004281F6] ff d0                                        call    eax
000A7390 [004281F8] eb 7b                                        jmp     short near ptr unk_428275 ; game-relative-target=0x000A740D
000A7392 [004281FA] 53                                           push    ebx
000A7393 [004281FB] ff 76 78                                     push    dword ptr [esi+78h]
000A7396 [004281FE] 8b cf                                        mov     ecx, edi
000A7398 [00428200] b8 70 d0 45 00                               mov     eax, 45D070h
000A739D [00428205] ff d0                                        call    eax
000A739F [00428207] 50                                           push    eax
000A73A0 [00428208] 56                                           push    esi
000A73A1 [00428209] 8d 4c 24 50                                  lea     ecx, [esp+50h]
000A73A5 [0042820D] b8 c0 a3 47 00                               mov     eax, 47A3C0h
000A73AA [00428212] ff d0                                        call    eax
000A73AC [00428214] 57                                           push    edi
000A73AD [00428215] 53                                           push    ebx
000A73AE [00428216] 8b cf                                        mov     ecx, edi
000A73B0 [00428218] b8 70 d0 45 00                               mov     eax, 45D070h
000A73B5 [0042821D] ff d0                                        call    eax
000A73B7 [0042821F] 50                                           push    eax
000A73B8 [00428220] 56                                           push    esi
000A73B9 [00428221] 8d 8c 24 90 00 00 00                         lea     ecx, [esp+90h]
000A73C0 [00428228] b8 c0 a3 47 00                               mov     eax, 47A3C0h
000A73C5 [0042822D] ff d0                                        call    eax
000A73C7 [0042822F] 8d 4c 24 40                                  lea     ecx, [esp+40h]
000A73CB [00428233] 54                                           push    esp
000A73CC [00428234] b8 90 82 47 00                               mov     eax, 478290h
000A73D1 [00428239] ff d0                                        call    eax
000A73D3 [0042823B] 8d 8c 24 80 00 00 00                         lea     ecx, [esp+80h]
000A73DA [00428242] 8d 44 24 20                                  lea     eax, [esp+20h]
000A73DE [00428246] 50                                           push    eax
000A73DF [00428247] b8 90 82 47 00                               mov     eax, 478290h
000A73E4 [0042824C] ff d0                                        call    eax
000A73E6 [0042824E] 8b cc                                        mov     ecx, esp
000A73E8 [00428250] b8 80 7b 43 00                               mov     eax, 437B80h
000A73ED [00428255] ff d0                                        call    eax
000A73EF [00428257] 8b cc                                        mov     ecx, esp
000A73F1 [00428259] 8d 44 24 20                                  lea     eax, [esp+20h]
000A73F5 [0042825D] 6a 30                                        push    30h ; '0'
000A73F7 [0042825F] 50                                           push    eax
000A73F8 [00428260] b8 80 ef 46 00                               mov     eax, 46EF80h
000A73FD [00428265] ff d0                                        call    eax
000A73FF [00428267] 8d 8c 24 80 00 00 00                         lea     ecx, [esp+80h]
000A7406 [0042826E] b8 20 9f 47 00                               mov     eax, 479F20h
000A740B [00428273] ff d0                                        call    eax
000A740D [00428275] 83 7c 24 0c 01                               cmp     dword ptr [esp+0Ch], 1
000A7412 [0042827A] 7e 09                                        jle     short near ptr unk_428285 ; game-relative-target=0x000A741D
000A7414 [0042827C] 8b cc                                        mov     ecx, esp
000A7416 [0042827E] b8 10 82 51 00                               mov     eax, 518210h
000A741B [00428283] ff d0                                        call    eax
000A741D [00428285] 8b cd                                        mov     ecx, ebp
000A741F [00428287] 8d bc 24 c0 00 00 00                         lea     edi, [esp+0C0h]
000A7426 [0042828E] 57                                           push    edi
000A7427 [0042828F] b8 40 a9 44 00                               mov     eax, 44A940h
000A742C [00428294] ff d0                                        call    eax
000A742E [00428296] 6a 02                                        push    2
000A7430 [00428298] 6a 02                                        push    2
000A7432 [0042829A] 57                                           push    edi
000A7433 [0042829B] ff 15 78 f3 5f 00                            call    dword ptr ds:5FF378h
000A7439 [004282A1] 33 ed                                        xor     ebp, ebp
000A743B [004282A3] 8b 5c 24 04                                  mov     ebx, [esp+4]
000A743F [004282A7] 45                                           inc     ebp
000A7440 [004282A8] 8b 4b 08                                     mov     ecx, [ebx+8]
000A7443 [004282AB] 0f b7 41 04                                  movzx   eax, word ptr [ecx+4]
000A7447 [004282AF] 99                                           cdq
000A7448 [004282B0] b9 c8 00 00 00                               mov     ecx, 0C8h
000A744D [004282B5] f7 f9                                        idiv    ecx
000A744F [004282B7] 50                                           push    eax
000A7450 [004282B8] 52                                           push    edx
000A7451 [004282B9] 57                                           push    edi
000A7452 [004282BA] ff 15 6c f3 5f 00                            call    dword ptr ds:5FF36Ch
000A7458 [004282C0] 85 c0                                        test    eax, eax
000A745A [004282C2] 75 12                                        jnz     short near ptr unk_4282D6 ; game-relative-target=0x000A746E
000A745C [004282C4] 83 fd 20                                     cmp     ebp, 20h ; ' '
000A745F [004282C7] 7d 06                                        jge     short near ptr unk_4282CF ; game-relative-target=0x000A7467
000A7461 [004282C9] 8b 1b                                        mov     ebx, [ebx]
000A7463 [004282CB] 85 db                                        test    ebx, ebx
000A7465 [004282CD] 75 d8                                        jnz     short near ptr unk_4282A7 ; game-relative-target=0x000A743F
000A7467 [004282CF] bf 64 00 00 00                               mov     edi, 64h ; 'd'
000A746C [004282D4] eb 2d                                        jmp     short near ptr unk_428303 ; game-relative-target=0x000A749B
000A746E [004282D6] 8b cc                                        mov     ecx, esp
000A7470 [004282D8] 55                                           push    ebp
000A7471 [004282D9] b8 b0 ee 46 00                               mov     eax, 46EEB0h
000A7476 [004282DE] ff d0                                        call    eax
000A7478 [004282E0] 8b fc                                        mov     edi, esp
000A747A [004282E2] 8b ce                                        mov     ecx, esi
000A747C [004282E4] b8 d0 47 46 00                               mov     eax, 4647D0h
000A7481 [004282E9] ff d0                                        call    eax
000A7483 [004282EB] 50                                           push    eax
000A7484 [004282EC] 8b ce                                        mov     ecx, esi
000A7486 [004282EE] b8 40 47 46 00                               mov     eax, 464740h
000A748B [004282F3] ff d0                                        call    eax
000A748D [004282F5] 50                                           push    eax
000A748E [004282F6] 57                                           push    edi
000A748F [004282F7] b8 c0 a4 44 00                               mov     eax, 44A4C0h
000A7494 [004282FC] ff d0                                        call    eax
000A7496 [004282FE] 83 c4 0c                                     add     esp, 0Ch
000A7499 [00428301] 8b f8                                        mov     edi, eax
000A749B [00428303] 8d 4c 24 40                                  lea     ecx, [esp+40h]
000A749F [00428307] b8 20 9f 47 00                               mov     eax, 479F20h
000A74A4 [0042830C] ff d0                                        call    eax
000A74A6 [0042830E] 8b cc                                        mov     ecx, esp
000A74A8 [00428310] b8 e0 80 51 00                               mov     eax, 5180E0h
000A74AD [00428315] ff d0                                        call    eax
000A74AF [00428317] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A74B3 [0042831B] b8 e0 80 51 00                               mov     eax, 5180E0h
000A74B8 [00428320] ff d0                                        call    eax
000A74BA [00428322] 8b c7                                        mov     eax, edi
000A74BC [00428324] 81 c4 d0 00 00 00                            add     esp, 0D0h
000A74C2 [0042832A] 5d                                           pop     ebp
000A74C3 [0042832B] 5b                                           pop     ebx
000A74C4 [0042832C] 5f                                           pop     edi
000A74C5 [0042832D] 5e                                           pop     esi
000A74C6 [0042832E] c2 04 00                                     retn    4
