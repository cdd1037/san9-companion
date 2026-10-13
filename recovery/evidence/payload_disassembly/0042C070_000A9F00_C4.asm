; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C070; baseline game VA=0x000A9F00; size=196
; Relative branch annotations use the baseline game destination.
000A9F00 [0042C070] 8b e9                                        mov     ebp, ecx
000A9F02 [0042C072] 8b 5c 24 04                                  mov     ebx, [esp+4]
000A9F06 [0042C076] 8b d3                                        mov     edx, ebx
000A9F08 [0042C078] e8 13 00 00 00                               call    near ptr unk_42C090 ; game-relative-target=0x000A9F20
000A9F0D [0042C07D] 8b f8                                        mov     edi, eax
000A9F0F [0042C07F] 53                                           push    ebx
000A9F10 [0042C080] 8b cd                                        mov     ecx, ebp
000A9F12 [0042C082] b8 60 14 44 00                               mov     eax, 441460h
000A9F17 [0042C087] ff d0                                        call    eax
000A9F19 [0042C089] 2b c7                                        sub     eax, edi
000A9F1B [0042C08B] c2 04 00                                     retn    4
000A9F1E [0042C08E] 90                                           nop
000A9F1F [0042C08F] 90                                           nop
000A9F20 [0042C090] 8b 92 bc 00 00 00                            mov     edx, [edx+0BCh]
000A9F26 [0042C096] 8b 89 bc 00 00 00                            mov     ecx, [ecx+0BCh]
000A9F2C [0042C09C] 8b 52 6c                                     mov     edx, [edx+6Ch]
000A9F2F [0042C09F] 8b 49 6c                                     mov     ecx, [ecx+6Ch]
000A9F32 [0042C0A2] 2b ca                                        sub     ecx, edx
000A9F34 [0042C0A4] 79 02                                        jns     short near ptr unk_42C0A8 ; game-relative-target=0x000A9F38
000A9F36 [0042C0A6] f7 d9                                        neg     ecx
000A9F38 [0042C0A8] b8 4b 00 00 00                               mov     eax, 4Bh ; 'K'
000A9F3D [0042C0AD] 3b c8                                        cmp     ecx, eax
000A9F3F [0042C0AF] 7e 05                                        jle     short near ptr unk_42C0B6 ; game-relative-target=0x000A9F46
000A9F41 [0042C0B1] f7 d9                                        neg     ecx
000A9F43 [0042C0B3] 8d 0c 41                                     lea     ecx, [ecx+eax*2]
000A9F46 [0042C0B6] b8 67 66 66 66                               mov     eax, 66666667h
000A9F4B [0042C0BB] f7 e9                                        imul    ecx
000A9F4D [0042C0BD] d1 fa                                        sar     edx, 1
000A9F4F [0042C0BF] 8b c2                                        mov     eax, edx
000A9F51 [0042C0C1] c1 e8 1f                                     shr     eax, 1Fh
000A9F54 [0042C0C4] 03 c2                                        add     eax, edx
000A9F56 [0042C0C6] c3                                           retn
000A9F57 [0042C0C7] 90                                           nop
000A9F58 [0042C0C8] 33 ed                                        xor     ebp, ebp
000A9F5A [0042C0CA] 55                                           push    ebp
000A9F5B [0042C0CB] 55                                           push    ebp
000A9F5C [0042C0CC] 55                                           push    ebp
000A9F5D [0042C0CD] b8 30 33 45 00                               mov     eax, 453330h
000A9F62 [0042C0D2] ff d0                                        call    eax
000A9F64 [0042C0D4] 83 c4 04                                     add     esp, 4
000A9F67 [0042C0D7] 85 c0                                        test    eax, eax
000A9F69 [0042C0D9] 74 4d                                        jz      short near ptr unk_42C128 ; game-relative-target=0x000A9FB8
000A9F6B [0042C0DB] 8b d8                                        mov     ebx, eax
000A9F6D [0042C0DD] 8b 00                                        mov     eax, [eax]
000A9F6F [0042C0DF] 85 c0                                        test    eax, eax
000A9F71 [0042C0E1] 74 45                                        jz      short near ptr unk_42C128 ; game-relative-target=0x000A9FB8
000A9F73 [0042C0E3] 8b cb                                        mov     ecx, ebx
000A9F75 [0042C0E5] ff 50 10                                     call    dword ptr [eax+10h]
000A9F78 [0042C0E8] 85 c0                                        test    eax, eax
000A9F7A [0042C0EA] 74 3c                                        jz      short near ptr unk_42C128 ; game-relative-target=0x000A9FB8
000A9F7C [0042C0EC] f6 43 20 02                                  test    byte ptr [ebx+20h], 2
000A9F80 [0042C0F0] 75 36                                        jnz     short near ptr unk_42C128 ; game-relative-target=0x000A9FB8
000A9F82 [0042C0F2] 8b cb                                        mov     ecx, ebx
000A9F84 [0042C0F4] b8 00 27 46 00                               mov     eax, 462700h
000A9F89 [0042C0F9] ff d0                                        call    eax
000A9F8B [0042C0FB] 8d 4c 24 40                                  lea     ecx, [esp+40h]
000A9F8F [0042C0FF] 6a 00                                        push    0
000A9F91 [0042C101] 50                                           push    eax
000A9F92 [0042C102] b8 f0 5c 41 00                               mov     eax, 415CF0h
000A9F97 [0042C107] ff d0                                        call    eax
000A9F99 [0042C109] 85 c0                                        test    eax, eax
000A9F9B [0042C10B] 74 1b                                        jz      short near ptr unk_42C128 ; game-relative-target=0x000A9FB8
000A9F9D [0042C10D] 8b cb                                        mov     ecx, ebx
000A9F9F [0042C10F] 8b 13                                        mov     edx, [ebx]
000A9FA1 [0042C111] ff 52 30                                     call    dword ptr [edx+30h]
000A9FA4 [0042C114] 33 c9                                        xor     ecx, ecx
000A9FA6 [0042C116] 3b c6                                        cmp     eax, esi
000A9FA8 [0042C118] 74 05                                        jz      short near ptr unk_42C11F ; game-relative-target=0x000A9FAF
000A9FAA [0042C11A] 3b c7                                        cmp     eax, edi
000A9FAC [0042C11C] 75 0a                                        jnz     short near ptr unk_42C128 ; game-relative-target=0x000A9FB8
000A9FAE [0042C11E] 41                                           inc     ecx
000A9FAF [0042C11F] 8b 43 30                                     mov     eax, [ebx+30h]
000A9FB2 [0042C122] 03 43 34                                     add     eax, [ebx+34h]
000A9FB5 [0042C125] 01 04 8c                                     add     [esp+ecx*4], eax
000A9FB8 [0042C128] 45                                           inc     ebp
000A9FB9 [0042C129] 81 fd 4c 04 00 00                            cmp     ebp, 44Ch
000A9FBF [0042C12F] 7c 9b                                        jl      short near ptr unk_42C0CC ; game-relative-target=0x000A9F5C
000A9FC1 [0042C131] 5d                                           pop     ebp
000A9FC2 [0042C132] 5b                                           pop     ebx
000A9FC3 [0042C133] c3                                           retn
