; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429220; baseline game VA=0x000A7C20; size=154
; Relative branch annotations use the baseline game destination.
000A7C20 [00429220] 8b 85 4c 07 00 00                            mov     eax, [ebp+74Ch]
000A7C26 [00429226] 8a 40 04                                     mov     al, [eax+4]
000A7C29 [00429229] 33 c9                                        xor     ecx, ecx
000A7C2B [0042922B] 3c 00                                        cmp     al, 0
000A7C2D [0042922D] 74 1e                                        jz      short near ptr unk_42924D ; game-relative-target=0x000A7C4D
000A7C2F [0042922F] 3c 01                                        cmp     al, 1
000A7C31 [00429231] 74 1a                                        jz      short near ptr unk_42924D ; game-relative-target=0x000A7C4D
000A7C33 [00429233] 3c 03                                        cmp     al, 3
000A7C35 [00429235] 74 15                                        jz      short near ptr unk_42924C ; game-relative-target=0x000A7C4C
000A7C37 [00429237] 3c 04                                        cmp     al, 4
000A7C39 [00429239] 74 0f                                        jz      short near ptr unk_42924A ; game-relative-target=0x000A7C4A
000A7C3B [0042923B] 3c 06                                        cmp     al, 6
000A7C3D [0042923D] 74 0c                                        jz      short near ptr unk_42924B ; game-relative-target=0x000A7C4B
000A7C3F [0042923F] 3c 07                                        cmp     al, 7
000A7C41 [00429241] 74 06                                        jz      short near ptr unk_429249 ; game-relative-target=0x000A7C49
000A7C43 [00429243] 3c 08                                        cmp     al, 8
000A7C45 [00429245] 74 03                                        jz      short near ptr unk_42924A ; game-relative-target=0x000A7C4A
000A7C47 [00429247] eb 5f                                        jmp     short near ptr unk_4292A8 ; game-relative-target=0x000A7CA8
000A7C49 [00429249] 41                                           inc     ecx
000A7C4A [0042924A] 41                                           inc     ecx
000A7C4B [0042924B] 41                                           inc     ecx
000A7C4C [0042924C] 41                                           inc     ecx
000A7C4D [0042924D] 83 f9 04                                     cmp     ecx, 4
000A7C50 [00429250] 74 0d                                        jz      short near ptr unk_42925F ; game-relative-target=0x000A7C5F
000A7C52 [00429252] 8b 46 54                                     mov     eax, [esi+54h]
000A7C55 [00429255] 2b 46 4c                                     sub     eax, [esi+4Ch]
000A7C58 [00429258] 83 f8 0f                                     cmp     eax, 0Fh
000A7C5B [0042925B] 7e 02                                        jle     short near ptr unk_42925F ; game-relative-target=0x000A7C5F
000A7C5D [0042925D] b1 04                                        mov     cl, 4
000A7C5F [0042925F] 53                                           push    ebx
000A7C60 [00429260] 55                                           push    ebp
000A7C61 [00429261] 57                                           push    edi
000A7C62 [00429262] 8d 2c 49                                     lea     ebp, [ecx+ecx*2]
000A7C65 [00429265] bb 02 00 00 00                               mov     ebx, 2
000A7C6A [0042926A] 83 f9 04                                     cmp     ecx, 4
000A7C6D [0042926D] 75 02                                        jnz     short near ptr unk_429271 ; game-relative-target=0x000A7C71
000A7C6F [0042926F] b3 09                                        mov     bl, 9
000A7C71 [00429271] 83 fd 0c                                     cmp     ebp, 0Ch
000A7C74 [00429274] 75 0a                                        jnz     short near ptr unk_429280 ; game-relative-target=0x000A7C80
000A7C76 [00429276] 33 d2                                        xor     edx, edx
000A7C78 [00429278] 8a 93 ae 7c 0a 00                            mov     dl, [ebx+0A7CAEh]
000A7C7E [0042927E] eb 03                                        jmp     short near ptr unk_429283 ; game-relative-target=0x000A7C83
000A7C80 [00429280] 8d 14 2b                                     lea     edx, [ebx+ebp]
000A7C83 [00429283] 52                                           push    edx
000A7C84 [00429284] b8 20 37 45 00                               mov     eax, 453720h
000A7C89 [00429289] ff d0                                        call    eax
000A7C8B [0042928B] 89 04 24                                     mov     [esp], eax
000A7C8E [0042928E] 8b ce                                        mov     ecx, esi
000A7C90 [00429290] 8b f8                                        mov     edi, eax
000A7C92 [00429292] b8 70 e1 44 00                               mov     eax, 44E170h
000A7C97 [00429297] ff d0                                        call    eax
000A7C99 [00429299] 85 c0                                        test    eax, eax
000A7C9B [0042929B] 75 05                                        jnz     short near ptr unk_4292A2 ; game-relative-target=0x000A7CA2
000A7C9D [0042929D] 4b                                           dec     ebx
000A7C9E [0042929E] 7d d1                                        jge     short near ptr unk_429271 ; game-relative-target=0x000A7C71
000A7CA0 [004292A0] eb 03                                        jmp     short near ptr unk_4292A5 ; game-relative-target=0x000A7CA5
000A7CA2 [004292A2] 89 7e 08                                     mov     [esi+8], edi
000A7CA5 [004292A5] 5f                                           pop     edi
000A7CA6 [004292A6] 5d                                           pop     ebp
000A7CA7 [004292A7] 5b                                           pop     ebx
000A7CA8 [004292A8] 83 c3 08                                     add     ebx, 8
000A7CAB [004292AB] 85 ff                                        test    edi, edi
000A7CAD [004292AD] c3                                           retn
000A7CAE [004292AE] 1b 1c 15 17 18 16 19                         sbb     ebx, ds:19161817h[edx]
000A7CB5 [004292B5] 1d 1e 1a 1e 1a                               sbb     eax, 1A1E1A1Eh
