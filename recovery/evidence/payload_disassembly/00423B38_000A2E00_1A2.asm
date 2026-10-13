; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423B38; baseline game VA=0x000A2E00; size=418
; Relative branch annotations use the baseline game destination.
000A2E00 [00423B38] 58                                           pop     eax
000A2E01 [00423B39] b8 60 bb 48 00                               mov     eax, 48BB60h
000A2E06 [00423B3E] ff d0                                        call    eax
000A2E08 [00423B40] 8b d8                                        mov     ebx, eax
000A2E0A [00423B42] 6a 01                                        push    1
000A2E0C [00423B44] 8b ce                                        mov     ecx, esi
000A2E0E [00423B46] b8 60 bb 48 00                               mov     eax, 48BB60h
000A2E13 [00423B4B] ff d0                                        call    eax
000A2E15 [00423B4D] 8b e8                                        mov     ebp, eax
000A2E17 [00423B4F] 85 db                                        test    ebx, ebx
000A2E19 [00423B51] 74 54                                        jz      short near ptr unk_423BA7 ; game-relative-target=0x000A2E6F
000A2E1B [00423B53] 85 ff                                        test    edi, edi
000A2E1D [00423B55] 74 4c                                        jz      short near ptr unk_423BA3 ; game-relative-target=0x000A2E6B
000A2E1F [00423B57] 6a 00                                        push    0
000A2E21 [00423B59] 6a 03                                        push    3
000A2E23 [00423B5B] 8b ce                                        mov     ecx, esi
000A2E25 [00423B5D] b8 00 30 0a 00                               mov     eax, 0A3000h
000A2E2A [00423B62] ff d0                                        call    eax
000A2E2C [00423B64] 3b c3                                        cmp     eax, ebx
000A2E2E [00423B66] 75 13                                        jnz     short near ptr unk_423B7B ; game-relative-target=0x000A2E43
000A2E30 [00423B68] 6a 01                                        push    1
000A2E32 [00423B6A] 6a 03                                        push    3
000A2E34 [00423B6C] 8b ce                                        mov     ecx, esi
000A2E36 [00423B6E] b8 00 30 0a 00                               mov     eax, 0A3000h
000A2E3B [00423B73] ff d0                                        call    eax
000A2E3D [00423B75] 03 fb                                        add     edi, ebx
000A2E3F [00423B77] 33 db                                        xor     ebx, ebx
000A2E41 [00423B79] eb 2c                                        jmp     short near ptr unk_423BA7 ; game-relative-target=0x000A2E6F
000A2E43 [00423B7B] 85 ff                                        test    edi, edi
000A2E45 [00423B7D] 74 28                                        jz      short near ptr unk_423BA7 ; game-relative-target=0x000A2E6F
000A2E47 [00423B7F] 6a 00                                        push    0
000A2E49 [00423B81] 6a 02                                        push    2
000A2E4B [00423B83] 8b ce                                        mov     ecx, esi
000A2E4D [00423B85] b8 00 30 0a 00                               mov     eax, 0A3000h
000A2E52 [00423B8A] ff d0                                        call    eax
000A2E54 [00423B8C] 3b c7                                        cmp     eax, edi
000A2E56 [00423B8E] 75 11                                        jnz     short near ptr unk_423BA1 ; game-relative-target=0x000A2E69
000A2E58 [00423B90] 6a 01                                        push    1
000A2E5A [00423B92] 6a 02                                        push    2
000A2E5C [00423B94] 8b ce                                        mov     ecx, esi
000A2E5E [00423B96] b8 00 30 0a 00                               mov     eax, 0A3000h
000A2E63 [00423B9B] ff d0                                        call    eax
000A2E65 [00423B9D] 03 df                                        add     ebx, edi
000A2E67 [00423B9F] 33 ff                                        xor     edi, edi
000A2E69 [00423BA1] eb 04                                        jmp     short near ptr unk_423BA7 ; game-relative-target=0x000A2E6F
000A2E6B [00423BA3] 85 ed                                        test    ebp, ebp
000A2E6D [00423BA5] 75 b0                                        jnz     short near ptr unk_423B57 ; game-relative-target=0x000A2E1F
000A2E6F [00423BA7] 6a 00                                        push    0
000A2E71 [00423BA9] 8b ce                                        mov     ecx, esi
000A2E73 [00423BAB] b8 60 bb 48 00                               mov     eax, 48BB60h
000A2E78 [00423BB0] ff d0                                        call    eax
000A2E7A [00423BB2] 85 c0                                        test    eax, eax
000A2E7C [00423BB4] 74 7d                                        jz      short near ptr unk_423C33 ; game-relative-target=0x000A2EFB
000A2E7E [00423BB6] 53                                           push    ebx
000A2E7F [00423BB7] 8b d8                                        mov     ebx, eax
000A2E81 [00423BB9] 85 ff                                        test    edi, edi
000A2E83 [00423BBB] 74 1d                                        jz      short near ptr unk_423BDA ; game-relative-target=0x000A2EA2
000A2E85 [00423BBD] 6a 00                                        push    0
000A2E87 [00423BBF] 6a 00                                        push    0
000A2E89 [00423BC1] 8b ce                                        mov     ecx, esi
000A2E8B [00423BC3] b8 00 30 0a 00                               mov     eax, 0A3000h
000A2E90 [00423BC8] ff d0                                        call    eax
000A2E92 [00423BCA] 85 c0                                        test    eax, eax
000A2E94 [00423BCC] 74 36                                        jz      short near ptr unk_423C04 ; game-relative-target=0x000A2ECC
000A2E96 [00423BCE] d1 e0                                        shl     eax, 1
000A2E98 [00423BD0] 03 c7                                        add     eax, edi
000A2E9A [00423BD2] 03 c5                                        add     eax, ebp
000A2E9C [00423BD4] 3b c3                                        cmp     eax, ebx
000A2E9E [00423BD6] 7c 2c                                        jl      short near ptr unk_423C04 ; game-relative-target=0x000A2ECC
000A2EA0 [00423BD8] eb 17                                        jmp     short near ptr unk_423BF1 ; game-relative-target=0x000A2EB9
000A2EA2 [00423BDA] 6a 00                                        push    0
000A2EA4 [00423BDC] 6a 00                                        push    0
000A2EA6 [00423BDE] 8b ce                                        mov     ecx, esi
000A2EA8 [00423BE0] b8 00 30 0a 00                               mov     eax, 0A3000h
000A2EAD [00423BE5] ff d0                                        call    eax
000A2EAF [00423BE7] 85 c0                                        test    eax, eax
000A2EB1 [00423BE9] 74 19                                        jz      short near ptr unk_423C04 ; game-relative-target=0x000A2ECC
000A2EB3 [00423BEB] 03 c5                                        add     eax, ebp
000A2EB5 [00423BED] 3b c3                                        cmp     eax, ebx
000A2EB7 [00423BEF] 7e 13                                        jle     short near ptr unk_423C04 ; game-relative-target=0x000A2ECC
000A2EB9 [00423BF1] 6a 01                                        push    1
000A2EBB [00423BF3] 6a 00                                        push    0
000A2EBD [00423BF5] 8b ce                                        mov     ecx, esi
000A2EBF [00423BF7] b8 00 30 0a 00                               mov     eax, 0A3000h
000A2EC4 [00423BFC] ff d0                                        call    eax
000A2EC6 [00423BFE] 03 e8                                        add     ebp, eax
000A2EC8 [00423C00] 2b d8                                        sub     ebx, eax
000A2ECA [00423C02] eb 2c                                        jmp     short near ptr unk_423C30 ; game-relative-target=0x000A2EF8
000A2ECC [00423C04] 85 ed                                        test    ebp, ebp
000A2ECE [00423C06] 74 28                                        jz      short near ptr unk_423C30 ; game-relative-target=0x000A2EF8
000A2ED0 [00423C08] 6a 00                                        push    0
000A2ED2 [00423C0A] 6a 01                                        push    1
000A2ED4 [00423C0C] 8b ce                                        mov     ecx, esi
000A2ED6 [00423C0E] b8 00 30 0a 00                               mov     eax, 0A3000h
000A2EDB [00423C13] ff d0                                        call    eax
000A2EDD [00423C15] 85 c0                                        test    eax, eax
000A2EDF [00423C17] 74 17                                        jz      short near ptr unk_423C30 ; game-relative-target=0x000A2EF8
000A2EE1 [00423C19] 03 c3                                        add     eax, ebx
000A2EE3 [00423C1B] 3b c5                                        cmp     eax, ebp
000A2EE5 [00423C1D] 7e 11                                        jle     short near ptr unk_423C30 ; game-relative-target=0x000A2EF8
000A2EE7 [00423C1F] 6a 01                                        push    1
000A2EE9 [00423C21] 6a 01                                        push    1
000A2EEB [00423C23] 8b ce                                        mov     ecx, esi
000A2EED [00423C25] b8 00 30 0a 00                               mov     eax, 0A3000h
000A2EF2 [00423C2A] ff d0                                        call    eax
000A2EF4 [00423C2C] 03 d8                                        add     ebx, eax
000A2EF6 [00423C2E] 2b e8                                        sub     ebp, eax
000A2EF8 [00423C30] 8b c3                                        mov     eax, ebx
000A2EFA [00423C32] 5b                                           pop     ebx
000A2EFB [00423C33] f6 44 24 34 01                               test    byte ptr [esp+34h], 1
000A2F00 [00423C38] 75 51                                        jnz     short near ptr unk_423C8B ; game-relative-target=0x000A2F53
000A2F02 [00423C3A] 03 ef                                        add     ebp, edi
000A2F04 [00423C3C] 8b d3                                        mov     edx, ebx
000A2F06 [00423C3E] 03 d7                                        add     edx, edi
000A2F08 [00423C40] 3b c5                                        cmp     eax, ebp
000A2F0A [00423C42] 7d 02                                        jge     short near ptr unk_423C46 ; game-relative-target=0x000A2F0E
000A2F0C [00423C44] 8b c5                                        mov     eax, ebp
000A2F0E [00423C46] 3b c2                                        cmp     eax, edx
000A2F10 [00423C48] 7d 02                                        jge     short near ptr unk_423C4C ; game-relative-target=0x000A2F14
000A2F12 [00423C4A] 8b c2                                        mov     eax, edx
000A2F14 [00423C4C] 85 c0                                        test    eax, eax
000A2F16 [00423C4E] 75 16                                        jnz     short near ptr unk_423C66 ; game-relative-target=0x000A2F2E
000A2F18 [00423C50] f6 44 24 24 01                               test    byte ptr [esp+24h], 1
000A2F1D [00423C55] 74 04                                        jz      short near ptr unk_423C5B ; game-relative-target=0x000A2F23
000A2F1F [00423C57] 6a 08                                        push    8
000A2F21 [00423C59] eb 32                                        jmp     short near ptr unk_423C8D ; game-relative-target=0x000A2F55
000A2F23 [00423C5B] f6 44 24 1c 01                               test    byte ptr [esp+1Ch], 1
000A2F28 [00423C60] 74 25                                        jz      short near ptr unk_423C87 ; game-relative-target=0x000A2F4F
000A2F2A [00423C62] 6a 0a                                        push    0Ah
000A2F2C [00423C64] eb 27                                        jmp     short near ptr unk_423C8D ; game-relative-target=0x000A2F55
000A2F2E [00423C66] 3b d0                                        cmp     edx, eax
000A2F30 [00423C68] 7c 35                                        jl      short near ptr unk_423C9F ; game-relative-target=0x000A2F67
000A2F32 [00423C6A] 85 db                                        test    ebx, ebx
000A2F34 [00423C6C] 75 04                                        jnz     short near ptr unk_423C72 ; game-relative-target=0x000A2F3A
000A2F36 [00423C6E] 6a 02                                        push    2
000A2F38 [00423C70] eb 48                                        jmp     short near ptr unk_423CBA ; game-relative-target=0x000A2F82
000A2F3A [00423C72] 85 ff                                        test    edi, edi
000A2F3C [00423C74] 74 04                                        jz      short near ptr unk_423C7A ; game-relative-target=0x000A2F42
000A2F3E [00423C76] 6a 05                                        push    5
000A2F40 [00423C78] eb 13                                        jmp     short near ptr unk_423C8D ; game-relative-target=0x000A2F55
000A2F42 [00423C7A] f6 44 24 24 01                               test    byte ptr [esp+24h], 1
000A2F47 [00423C7F] 75 d6                                        jnz     short near ptr unk_423C57 ; game-relative-target=0x000A2F1F
000A2F49 [00423C81] f6 46 19 01                                  test    byte ptr [esi+19h], 1
000A2F4D [00423C85] 75 ef                                        jnz     short near ptr unk_423C76 ; game-relative-target=0x000A2F3E
000A2F4F [00423C87] 6a 04                                        push    4
000A2F51 [00423C89] eb 02                                        jmp     short near ptr unk_423C8D ; game-relative-target=0x000A2F55
000A2F53 [00423C8B] 6a 0b                                        push    0Bh
000A2F55 [00423C8D] b8 90 38 45 00                               mov     eax, 453890h
000A2F5A [00423C92] ff d0                                        call    eax
000A2F5C [00423C94] 83 c4 04                                     add     esp, 4
000A2F5F [00423C97] 8b d8                                        mov     ebx, eax
000A2F61 [00423C99] 68 93 88 4b 00                               push    4B8893h
000A2F66 [00423C9E] c3                                           retn
000A2F67 [00423C9F] 3b e8                                        cmp     ebp, eax
000A2F69 [00423CA1] 7d cb                                        jge     short near ptr unk_423C6E ; game-relative-target=0x000A2F36
000A2F6B [00423CA3] 6a 00                                        push    0
000A2F6D [00423CA5] 2b ef                                        sub     ebp, edi
000A2F6F [00423CA7] 85 ed                                        test    ebp, ebp
000A2F71 [00423CA9] 74 e2                                        jz      short near ptr unk_423C8D ; game-relative-target=0x000A2F55
000A2F73 [00423CAB] 6a 01                                        push    1
000A2F75 [00423CAD] 6a 01                                        push    1
000A2F77 [00423CAF] 8b ce                                        mov     ecx, esi
000A2F79 [00423CB1] b8 00 30 0a 00                               mov     eax, 0A3000h
000A2F7E [00423CB6] ff d0                                        call    eax
000A2F80 [00423CB8] eb d3                                        jmp     short near ptr unk_423C8D ; game-relative-target=0x000A2F55
000A2F82 [00423CBA] 85 db                                        test    ebx, ebx
000A2F84 [00423CBC] 74 0d                                        jz      short near ptr unk_423CCB ; game-relative-target=0x000A2F93
000A2F86 [00423CBE] 6a 01                                        push    1
000A2F88 [00423CC0] 6a 03                                        push    3
000A2F8A [00423CC2] 8b ce                                        mov     ecx, esi
000A2F8C [00423CC4] b8 00 30 0a 00                               mov     eax, 0A3000h
000A2F91 [00423CC9] ff d0                                        call    eax
000A2F93 [00423CCB] 6a 01                                        push    1
000A2F95 [00423CCD] 6a 00                                        push    0
000A2F97 [00423CCF] 8b ce                                        mov     ecx, esi
000A2F99 [00423CD1] b8 00 30 0a 00                               mov     eax, 0A3000h
000A2F9E [00423CD6] ff d0                                        call    eax
000A2FA0 [00423CD8] eb b3                                        jmp     short near ptr unk_423C8D ; game-relative-target=0x000A2F55
