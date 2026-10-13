; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B3F0; baseline game VA=0x000A9400; size=236
; Relative branch annotations use the baseline game destination.
000A9400 [0042B3F0] 83 be 64 06 00 00 43                         cmp     dword ptr [esi+664h], 43h ; 'C'
000A9407 [0042B3F7] 74 0b                                        jz      short near ptr unk_42B404 ; game-relative-target=0x000A9414
000A9409 [0042B3F9] c7 86 84 06 00 00 00 00 00 00                mov     dword ptr [esi+684h], 0
000A9413 [0042B403] c3                                           retn
000A9414 [0042B404] ff b6 b4 11 00 00                            push    dword ptr [esi+11B4h]
000A941A [0042B40A] ff b6 b0 11 00 00                            push    dword ptr [esi+11B0h]
000A9420 [0042B410] ff d0                                        call    eax
000A9422 [0042B412] 83 c4 08                                     add     esp, 8
000A9425 [0042B415] 85 c0                                        test    eax, eax
000A9427 [0042B417] 74 11                                        jz      short near ptr unk_42B42A ; game-relative-target=0x000A943A
000A9429 [0042B419] c7 86 84 06 00 00 01 00 00 00                mov     dword ptr [esi+684h], 1
000A9433 [0042B423] 89 86 88 06 00 00                            mov     [esi+688h], eax
000A9439 [0042B429] c3                                           retn
000A943A [0042B42A] 57                                           push    edi
000A943B [0042B42B] 8d be e0 11 00 00                            lea     edi, [esi+11E0h]
000A9441 [0042B431] 8b 47 0c                                     mov     eax, [edi+0Ch]
000A9444 [0042B434] 85 c0                                        test    eax, eax
000A9446 [0042B436] 74 55                                        jz      short near ptr unk_42B48D ; game-relative-target=0x000A949D
000A9448 [0042B438] 6a 00                                        push    0
000A944A [0042B43A] 68 a0 fd 46 00                               push    46FDA0h
000A944F [0042B43F] 8b cf                                        mov     ecx, edi
000A9451 [0042B441] b8 10 f6 46 00                               mov     eax, 46F610h
000A9456 [0042B446] ff d0                                        call    eax
000A9458 [0042B448] 8b 7f 04                                     mov     edi, [edi+4]
000A945B [0042B44B] ff 77 08                                     push    dword ptr [edi+8]
000A945E [0042B44E] 6a ff                                        push    0FFFFFFFFh
000A9460 [0042B450] 6a 03                                        push    3
000A9462 [0042B452] ff b6 b8 11 00 00                            push    dword ptr [esi+11B8h]
000A9468 [0042B458] ff b6 b4 11 00 00                            push    dword ptr [esi+11B4h]
000A946E [0042B45E] ff b6 b0 11 00 00                            push    dword ptr [esi+11B0h]
000A9474 [0042B464] b8 70 f7 48 00                               mov     eax, 48F770h
000A9479 [0042B469] ff d0                                        call    eax
000A947B [0042B46B] 83 c4 18                                     add     esp, 18h
000A947E [0042B46E] 85 c0                                        test    eax, eax
000A9480 [0042B470] 74 15                                        jz      short near ptr unk_42B487 ; game-relative-target=0x000A9497
000A9482 [0042B472] c7 86 84 06 00 00 03 00 00 00                mov     dword ptr [esi+684h], 3
000A948C [0042B47C] 8b 47 08                                     mov     eax, [edi+8]
000A948F [0042B47F] 89 86 90 06 00 00                            mov     [esi+690h], eax
000A9495 [0042B485] 5f                                           pop     edi
000A9496 [0042B486] c3                                           retn
000A9497 [0042B487] 8b 3f                                        mov     edi, [edi]
000A9499 [0042B489] 85 ff                                        test    edi, edi
000A949B [0042B48B] 75 be                                        jnz     short near ptr unk_42B44B ; game-relative-target=0x000A945B
000A949D [0042B48D] ff b6 b8 11 00 00                            push    dword ptr [esi+11B8h]
000A94A3 [0042B493] ff b6 b4 11 00 00                            push    dword ptr [esi+11B4h]
000A94A9 [0042B499] ff b6 b0 11 00 00                            push    dword ptr [esi+11B0h]
000A94AF [0042B49F] b8 70 f5 48 00                               mov     eax, 48F570h
000A94B4 [0042B4A4] ff d0                                        call    eax
000A94B6 [0042B4A6] 8b f8                                        mov     edi, eax
000A94B8 [0042B4A8] 6a 00                                        push    0
000A94BA [0042B4AA] 57                                           push    edi
000A94BB [0042B4AB] 6a 02                                        push    2
000A94BD [0042B4AD] ff b6 b8 11 00 00                            push    dword ptr [esi+11B8h]
000A94C3 [0042B4B3] ff b6 b4 11 00 00                            push    dword ptr [esi+11B4h]
000A94C9 [0042B4B9] ff b6 b0 11 00 00                            push    dword ptr [esi+11B0h]
000A94CF [0042B4BF] b8 70 f7 48 00                               mov     eax, 48F770h
000A94D4 [0042B4C4] ff d0                                        call    eax
000A94D6 [0042B4C6] 83 c4 24                                     add     esp, 24h ; '$'
000A94D9 [0042B4C9] 03 c0                                        add     eax, eax
000A94DB [0042B4CB] 89 86 84 06 00 00                            mov     [esi+684h], eax
000A94E1 [0042B4D1] 48                                           dec     eax
000A94E2 [0042B4D2] 7c 06                                        jl      short near ptr unk_42B4DA ; game-relative-target=0x000A94EA
000A94E4 [0042B4D4] 89 be 8c 06 00 00                            mov     [esi+68Ch], edi
000A94EA [0042B4DA] 5f                                           pop     edi
000A94EB [0042B4DB] c3                                           retn
