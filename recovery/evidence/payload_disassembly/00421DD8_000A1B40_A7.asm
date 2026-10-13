; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421DD8; baseline game VA=0x000A1B40; size=167
; Relative branch annotations use the baseline game destination.
000A1B40 [00421DD8] 58                                           pop     eax
000A1B41 [00421DD9] b8 70 34 47 00                               mov     eax, 473470h
000A1B46 [00421DDE] ff d0                                        call    eax
000A1B48 [00421DE0] ff 73 08                                     push    dword ptr [ebx+8]
000A1B4B [00421DE3] 8b cb                                        mov     ecx, ebx
000A1B4D [00421DE5] b8 10 64 41 00                               mov     eax, 416410h
000A1B52 [00421DEA] ff d0                                        call    eax
000A1B54 [00421DEC] 8b ce                                        mov     ecx, esi
000A1B56 [00421DEE] b8 10 30 44 00                               mov     eax, 443010h
000A1B5B [00421DF3] ff d0                                        call    eax
000A1B5D [00421DF5] 50                                           push    eax
000A1B5E [00421DF6] 8b ce                                        mov     ecx, esi
000A1B60 [00421DF8] b8 a0 30 44 00                               mov     eax, 4430A0h
000A1B65 [00421DFD] ff d0                                        call    eax
000A1B67 [00421DFF] 6b c0 03                                     imul    eax, 3
000A1B6A [00421E02] 5a                                           pop     edx
000A1B6B [00421E03] 3b c2                                        cmp     eax, edx
000A1B6D [00421E05] 7c 0b                                        jl      short near ptr unk_421E12 ; game-relative-target=0x000A1B7A
000A1B6F [00421E07] 8b cb                                        mov     ecx, ebx
000A1B71 [00421E09] b8 e0 80 51 00                               mov     eax, 5180E0h
000A1B76 [00421E0E] ff d0                                        call    eax
000A1B78 [00421E10] eb 67                                        jmp     short near ptr unk_421E79 ; game-relative-target=0x000A1BE1
000A1B7A [00421E12] 8b 7c 24 24                                  mov     edi, [esp+24h]
000A1B7E [00421E16] 8b 4f 08                                     mov     ecx, [edi+8]
000A1B81 [00421E19] 8b 91 8c 00 00 00                            mov     edx, [ecx+8Ch]
000A1B87 [00421E1F] 85 d2                                        test    edx, edx
000A1B89 [00421E21] 7e 34                                        jle     short near ptr unk_421E57 ; game-relative-target=0x000A1BBF
000A1B8B [00421E23] 52                                           push    edx
000A1B8C [00421E24] b8 a0 37 45 00                               mov     eax, 4537A0h
000A1B91 [00421E29] ff d0                                        call    eax
000A1B93 [00421E2B] 5a                                           pop     edx
000A1B94 [00421E2C] 8b c8                                        mov     ecx, eax
000A1B96 [00421E2E] b8 c0 55 0a 00                               mov     eax, 0A55C0h
000A1B9B [00421E33] ff d0                                        call    eax
000A1B9D [00421E35] 3c 01                                        cmp     al, 1
000A1B9F [00421E37] 75 3a                                        jnz     short near ptr unk_421E73 ; game-relative-target=0x000A1BDB
000A1BA1 [00421E39] 8b 4f 08                                     mov     ecx, [edi+8]
000A1BA4 [00421E3C] b8 00 de 44 00                               mov     eax, 44DE00h
000A1BA9 [00421E41] ff d0                                        call    eax
000A1BAB [00421E43] 83 f8 50                                     cmp     eax, 50h ; 'P'
000A1BAE [00421E46] 7d 2b                                        jge     short near ptr unk_421E73 ; game-relative-target=0x000A1BDB
000A1BB0 [00421E48] 8b 4f 08                                     mov     ecx, [edi+8]
000A1BB3 [00421E4B] c7 81 8c 00 00 00 ff ff ff ff                mov     dword ptr [ecx+8Ch], 0FFFFFFFFh
000A1BBD [00421E55] eb 0c                                        jmp     short near ptr unk_421E63 ; game-relative-target=0x000A1BCB
000A1BBF [00421E57] b8 00 de 44 00                               mov     eax, 44DE00h
000A1BC4 [00421E5C] ff d0                                        call    eax
000A1BC6 [00421E5E] 83 f8 55                                     cmp     eax, 55h ; 'U'
000A1BC9 [00421E61] 7d 10                                        jge     short near ptr unk_421E73 ; game-relative-target=0x000A1BDB
000A1BCB [00421E63] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A1BCF [00421E67] 57                                           push    edi
000A1BD0 [00421E68] 8b 3f                                        mov     edi, [edi]
000A1BD2 [00421E6A] b8 10 64 41 00                               mov     eax, 416410h
000A1BD7 [00421E6F] ff d0                                        call    eax
000A1BD9 [00421E71] eb 02                                        jmp     short near ptr unk_421E75 ; game-relative-target=0x000A1BDD
000A1BDB [00421E73] 8b 3f                                        mov     edi, [edi]
000A1BDD [00421E75] 85 ff                                        test    edi, edi
000A1BDF [00421E77] 75 9d                                        jnz     short near ptr unk_421E16 ; game-relative-target=0x000A1B7E
000A1BE1 [00421E79] 68 b5 2f 4b 00                               push    4B2FB5h
000A1BE6 [00421E7E] c3                                           retn
