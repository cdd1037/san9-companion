; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427A88; baseline game VA=0x000A3E00; size=122
; Relative branch annotations use the baseline game destination.
000A3E00 [00427A88] 53                                           push    ebx
000A3E01 [00427A89] 55                                           push    ebp
000A3E02 [00427A8A] 8b 59 04                                     mov     ebx, [ecx+4]
000A3E05 [00427A8D] 85 db                                        test    ebx, ebx
000A3E07 [00427A8F] 74 50                                        jz      short near ptr unk_427AE1 ; game-relative-target=0x000A3E59
000A3E09 [00427A91] 8b 4e 54                                     mov     ecx, [esi+54h]
000A3E0C [00427A94] 8b 6b 08                                     mov     ebp, [ebx+8]
000A3E0F [00427A97] 3b e9                                        cmp     ebp, ecx
000A3E11 [00427A99] 74 42                                        jz      short near ptr unk_427ADD ; game-relative-target=0x000A3E55
000A3E13 [00427A9B] 55                                           push    ebp
000A3E14 [00427A9C] b8 c0 ce 44 00                               mov     eax, 44CEC0h
000A3E19 [00427AA1] ff d0                                        call    eax
000A3E1B [00427AA3] 83 e8 05                                     sub     eax, 5
000A3E1E [00427AA6] f7 d8                                        neg     eax
000A3E20 [00427AA8] 85 c0                                        test    eax, eax
000A3E22 [00427AAA] 7f 04                                        jg      short near ptr unk_427AB0 ; game-relative-target=0x000A3E28
000A3E24 [00427AAC] 33 c0                                        xor     eax, eax
000A3E26 [00427AAE] eb 03                                        jmp     short near ptr unk_427AB3 ; game-relative-target=0x000A3E2B
000A3E28 [00427AB0] 6b c0 05                                     imul    eax, 5
000A3E2B [00427AB3] 50                                           push    eax
000A3E2C [00427AB4] ff 76 54                                     push    dword ptr [esi+54h]
000A3E2F [00427AB7] 55                                           push    ebp
000A3E30 [00427AB8] b8 70 f7 4f 00                               mov     eax, 4FF770h
000A3E35 [00427ABD] ff d0                                        call    eax
000A3E37 [00427ABF] 5a                                           pop     edx
000A3E38 [00427AC0] 5a                                           pop     edx
000A3E39 [00427AC1] 5a                                           pop     edx
000A3E3A [00427AC2] 03 c2                                        add     eax, edx
000A3E3C [00427AC4] 83 c0 19                                     add     eax, 19h
000A3E3F [00427AC7] 50                                           push    eax
000A3E40 [00427AC8] b8 f0 ef 4a 00                               mov     eax, 4AEFF0h
000A3E45 [00427ACD] ff d0                                        call    eax
000A3E47 [00427ACF] 85 c0                                        test    eax, eax
000A3E49 [00427AD1] 74 0a                                        jz      short near ptr unk_427ADD ; game-relative-target=0x000A3E55
000A3E4B [00427AD3] 55                                           push    ebp
000A3E4C [00427AD4] 8b cf                                        mov     ecx, edi
000A3E4E [00427AD6] b8 70 ef 46 00                               mov     eax, 46EF70h
000A3E53 [00427ADB] ff d0                                        call    eax
000A3E55 [00427ADD] 8b 1b                                        mov     ebx, [ebx]
000A3E57 [00427ADF] eb ac                                        jmp     short near ptr unk_427A8D ; game-relative-target=0x000A3E05
000A3E59 [00427AE1] 5d                                           pop     ebp
000A3E5A [00427AE2] 5b                                           pop     ebx
000A3E5B [00427AE3] 83 7f 0c 00                                  cmp     dword ptr [edi+0Ch], 0
000A3E5F [00427AE7] 75 08                                        jnz     short near ptr unk_427AF1 ; game-relative-target=0x000A3E69
000A3E61 [00427AE9] 68 11 64 50 00                               push    506411h
000A3E66 [00427AEE] c2 08 00                                     retn    8
000A3E69 [00427AF1] 8a 04 24                                     mov     al, [esp]
000A3E6C [00427AF4] 3c 19                                        cmp     al, 19h
000A3E6E [00427AF6] 75 02                                        jnz     short near ptr unk_427AFA ; game-relative-target=0x000A3E72
000A3E70 [00427AF8] 04 04                                        add     al, 4
000A3E72 [00427AFA] 04 27                                        add     al, 27h ; '''
000A3E74 [00427AFC] 88 04 24                                     mov     [esp], al
000A3E77 [00427AFF] c2 04 00                                     retn    4
