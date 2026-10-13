; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428490; baseline game VA=0x000A7500; size=164
; Relative branch annotations use the baseline game destination.
000A7500 [00428490] 56                                           push    esi
000A7501 [00428491] 57                                           push    edi
000A7502 [00428492] 53                                           push    ebx
000A7503 [00428493] 55                                           push    ebp
000A7504 [00428494] 8b f1                                        mov     esi, ecx
000A7506 [00428496] 8b 5e 30                                     mov     ebx, [esi+30h]
000A7509 [00428499] bf b0 93 4b 01                               mov     edi, 14B93B0h
000A750E [0042849E] 8b 6c 24 14                                  mov     ebp, [esp+14h]
000A7512 [004284A2] 8b 46 74                                     mov     eax, [esi+74h]
000A7515 [004284A5] 39 47 74                                     cmp     [edi+74h], eax
000A7518 [004284A8] 75 6f                                        jnz     short near ptr unk_428519 ; game-relative-target=0x000A7589
000A751A [004284AA] f6 47 20 02                                  test    byte ptr [edi+20h], 2
000A751E [004284AE] 75 69                                        jnz     short near ptr unk_428519 ; game-relative-target=0x000A7589
000A7520 [004284B0] 3b fe                                        cmp     edi, esi
000A7522 [004284B2] 74 65                                        jz      short near ptr unk_428519 ; game-relative-target=0x000A7589
000A7524 [004284B4] 8b 47 6c                                     mov     eax, [edi+6Ch]
000A7527 [004284B7] 80 78 04 07                                  cmp     byte ptr [eax+4], 7
000A752B [004284BB] 7f 5c                                        jg      short near ptr unk_428519 ; game-relative-target=0x000A7589
000A752D [004284BD] 8b cf                                        mov     ecx, edi
000A752F [004284BF] 56                                           push    esi
000A7530 [004284C0] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A7535 [004284C5] ff d0                                        call    eax
000A7537 [004284C7] 83 f8 28                                     cmp     eax, 28h ; '('
000A753A [004284CA] 7f 4d                                        jg      short near ptr unk_428519 ; game-relative-target=0x000A7589
000A753C [004284CC] f6 47 21 10                                  test    byte ptr [edi+21h], 10h
000A7540 [004284D0] 75 44                                        jnz     short near ptr unk_428516 ; game-relative-target=0x000A7586
000A7542 [004284D2] f6 46 22 08                                  test    byte ptr [esi+22h], 8
000A7546 [004284D6] 74 3e                                        jz      short near ptr unk_428516 ; game-relative-target=0x000A7586
000A7548 [004284D8] 80 7f 56 03                                  cmp     byte ptr [edi+56h], 3
000A754C [004284DC] 75 19                                        jnz     short near ptr unk_4284F7 ; game-relative-target=0x000A7567
000A754E [004284DE] ff 77 54                                     push    dword ptr [edi+54h]
000A7551 [004284E1] b8 c0 37 45 00                               mov     eax, 4537C0h
000A7556 [004284E6] ff d0                                        call    eax
000A7558 [004284E8] 5a                                           pop     edx
000A7559 [004284E9] 50                                           push    eax
000A755A [004284EA] 8b cd                                        mov     ecx, ebp
000A755C [004284EC] b8 60 eb 46 00                               mov     eax, 46EB60h
000A7561 [004284F1] ff d0                                        call    eax
000A7563 [004284F3] 85 c0                                        test    eax, eax
000A7565 [004284F5] 75 1f                                        jnz     short near ptr unk_428516 ; game-relative-target=0x000A7586
000A7567 [004284F7] 80 7f 52 03                                  cmp     byte ptr [edi+52h], 3
000A756B [004284FB] 75 1c                                        jnz     short near ptr unk_428519 ; game-relative-target=0x000A7589
000A756D [004284FD] ff 77 50                                     push    dword ptr [edi+50h]
000A7570 [00428500] b8 c0 37 45 00                               mov     eax, 4537C0h
000A7575 [00428505] ff d0                                        call    eax
000A7577 [00428507] 5a                                           pop     edx
000A7578 [00428508] 50                                           push    eax
000A7579 [00428509] 8b cd                                        mov     ecx, ebp
000A757B [0042850B] b8 60 eb 46 00                               mov     eax, 46EB60h
000A7580 [00428510] ff d0                                        call    eax
000A7582 [00428512] 85 c0                                        test    eax, eax
000A7584 [00428514] 74 03                                        jz      short near ptr unk_428519 ; game-relative-target=0x000A7589
000A7586 [00428516] 03 5f 30                                     add     ebx, [edi+30h]
000A7589 [00428519] 81 c7 04 01 00 00                            add     edi, 104h
000A758F [0042851F] 81 ff f8 f2 4e 01                            cmp     edi, 14EF2F8h
000A7595 [00428525] 0f 8c 77 ff ff ff                            jl      near ptr unk_4284A2 ; game-relative-target=0x000A7512
000A759B [0042852B] 8b c3                                        mov     eax, ebx
000A759D [0042852D] 5d                                           pop     ebp
000A759E [0042852E] 5b                                           pop     ebx
000A759F [0042852F] 5f                                           pop     edi
000A75A0 [00428530] 5e                                           pop     esi
000A75A1 [00428531] c2 04 00                                     retn    4
