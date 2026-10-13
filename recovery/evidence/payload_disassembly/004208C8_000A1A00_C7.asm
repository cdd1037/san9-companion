; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004208C8; baseline game VA=0x000A1A00; size=199
; Relative branch annotations use the baseline game destination.
000A1A00 [004208C8] 33 db                                        xor     ebx, ebx
000A1A02 [004208CA] b3 01                                        mov     bl, 1
000A1A04 [004208CC] 8b 7c 24 50                                  mov     edi, [esp+50h]
000A1A08 [004208D0] 85 ff                                        test    edi, edi
000A1A0A [004208D2] 74 6c                                        jz      short near ptr unk_420940 ; game-relative-target=0x000A1A78
000A1A0C [004208D4] ff 77 08                                     push    dword ptr [edi+8]
000A1A0F [004208D7] 8b cd                                        mov     ecx, ebp
000A1A11 [004208D9] b8 c0 ce 44 00                               mov     eax, 44CEC0h
000A1A16 [004208DE] ff d0                                        call    eax
000A1A18 [004208E0] 83 f8 03                                     cmp     eax, 3
000A1A1B [004208E3] 7f 2e                                        jg      short near ptr unk_420913 ; game-relative-target=0x000A1A4B
000A1A1D [004208E5] 8b 6f 08                                     mov     ebp, [edi+8]
000A1A20 [004208E8] 2b f3                                        sub     esi, ebx
000A1A22 [004208EA] ff 77 08                                     push    dword ptr [edi+8]
000A1A25 [004208ED] 8d 8c 24 14 01 00 00                         lea     ecx, [esp+114h]
000A1A2C [004208F4] b8 70 ef 46 00                               mov     eax, 46EF70h
000A1A31 [004208F9] ff d0                                        call    eax
000A1A33 [004208FB] 57                                           push    edi
000A1A34 [004208FC] 8b 7f 04                                     mov     edi, [edi+4]
000A1A37 [004208FF] 8d 4c 24 50                                  lea     ecx, [esp+50h]
000A1A3B [00420903] b8 10 64 41 00                               mov     eax, 416410h
000A1A40 [00420908] ff d0                                        call    eax
000A1A42 [0042090A] 4b                                           dec     ebx
000A1A43 [0042090B] 75 dd                                        jnz     short near ptr unk_4208EA ; game-relative-target=0x000A1A22
000A1A45 [0042090D] 85 f6                                        test    esi, esi
000A1A47 [0042090F] 75 b9                                        jnz     short near ptr unk_4208CA ; game-relative-target=0x000A1A02
000A1A49 [00420911] eb 2d                                        jmp     short near ptr unk_420940 ; game-relative-target=0x000A1A78
000A1A4B [00420913] 8b 07                                        mov     eax, [edi]
000A1A4D [00420915] 85 c0                                        test    eax, eax
000A1A4F [00420917] 74 17                                        jz      short near ptr unk_420930 ; game-relative-target=0x000A1A68
000A1A51 [00420919] ff 70 08                                     push    dword ptr [eax+8]
000A1A54 [0042091C] 8b 4f 08                                     mov     ecx, [edi+8]
000A1A57 [0042091F] b8 c0 ce 44 00                               mov     eax, 44CEC0h
000A1A5C [00420924] ff d0                                        call    eax
000A1A5E [00420926] 83 f8 03                                     cmp     eax, 3
000A1A61 [00420929] 7f 05                                        jg      short near ptr unk_420930 ; game-relative-target=0x000A1A68
000A1A63 [0042092B] 43                                           inc     ebx
000A1A64 [0042092C] 8b 3f                                        mov     edi, [edi]
000A1A66 [0042092E] eb e3                                        jmp     short near ptr unk_420913 ; game-relative-target=0x000A1A4B
000A1A68 [00420930] 3b de                                        cmp     ebx, esi
000A1A6A [00420932] 7e b1                                        jle     short near ptr unk_4208E5 ; game-relative-target=0x000A1A1D
000A1A6C [00420934] b3 01                                        mov     bl, 1
000A1A6E [00420936] 85 c0                                        test    eax, eax
000A1A70 [00420938] 75 f2                                        jnz     short near ptr unk_42092C ; game-relative-target=0x000A1A64
000A1A72 [0042093A] 8b 7c 24 50                                  mov     edi, [esp+50h]
000A1A76 [0042093E] eb a5                                        jmp     short near ptr unk_4208E5 ; game-relative-target=0x000A1A1D
000A1A78 [00420940] 5a                                           pop     edx
000A1A79 [00420941] 85 d2                                        test    edx, edx
000A1A7B [00420943] 74 3d                                        jz      short near ptr unk_420982 ; game-relative-target=0x000A1ABA
000A1A7D [00420945] 83 bc 24 18 01 00 00 04                      cmp     dword ptr [esp+118h], 4
000A1A85 [0042094D] 7d 33                                        jge     short near ptr unk_420982 ; game-relative-target=0x000A1ABA
000A1A87 [0042094F] 52                                           push    edx
000A1A88 [00420950] b8 a8 09 0a 00                               mov     eax, 0A09A8h
000A1A8D [00420955] ff d0                                        call    eax
000A1A8F [00420957] 5a                                           pop     edx
000A1A90 [00420958] 8b 7c 24 4c                                  mov     edi, [esp+4Ch]
000A1A94 [0042095C] 85 ff                                        test    edi, edi
000A1A96 [0042095E] 74 22                                        jz      short near ptr unk_420982 ; game-relative-target=0x000A1ABA
000A1A98 [00420960] ff 77 08                                     push    dword ptr [edi+8]
000A1A9B [00420963] 8b cd                                        mov     ecx, ebp
000A1A9D [00420965] b8 c0 ce 44 00                               mov     eax, 44CEC0h
000A1AA2 [0042096A] ff d0                                        call    eax
000A1AA4 [0042096C] 83 f8 03                                     cmp     eax, 3
000A1AA7 [0042096F] 7f 11                                        jg      short near ptr unk_420982 ; game-relative-target=0x000A1ABA
000A1AA9 [00420971] ff 77 08                                     push    dword ptr [edi+8]
000A1AAC [00420974] 8d 8c 24 10 01 00 00                         lea     ecx, [esp+110h]
000A1AB3 [0042097B] b8 70 ef 46 00                               mov     eax, 46EF70h
000A1AB8 [00420980] ff d0                                        call    eax
000A1ABA [00420982] 58                                           pop     eax
000A1ABB [00420983] 5d                                           pop     ebp
000A1ABC [00420984] 5b                                           pop     ebx
000A1ABD [00420985] 5f                                           pop     edi
000A1ABE [00420986] 5e                                           pop     esi
000A1ABF [00420987] 68 d8 3d 4a 00                               push    4A3DD8h
000A1AC4 [0042098C] c2 04 00                                     retn    4
