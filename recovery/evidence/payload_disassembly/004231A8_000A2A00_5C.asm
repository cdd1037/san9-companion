; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004231A8; baseline game VA=0x000A2A00; size=92
; Relative branch annotations use the baseline game destination.
000A2A00 [004231A8] 57                                           push    edi
000A2A01 [004231A9] 55                                           push    ebp
000A2A02 [004231AA] 53                                           push    ebx
000A2A03 [004231AB] 8b f8                                        mov     edi, eax
000A2A05 [004231AD] 0f b7 6e 04                                  movzx   ebp, word ptr [esi+4]
000A2A09 [004231B1] c1 e5 03                                     shl     ebp, 3
000A2A0C [004231B4] 81 c5 00 6e 0a 00                            add     ebp, 0A6E00h
000A2A12 [004231BA] 33 db                                        xor     ebx, ebx
000A2A14 [004231BC] 0f b6 45 00                                  movzx   eax, byte ptr [ebp+0]
000A2A18 [004231C0] 50                                           push    eax
000A2A19 [004231C1] b8 b0 d7 46 00                               mov     eax, 46D7B0h
000A2A1E [004231C6] ff d0                                        call    eax
000A2A20 [004231C8] 3b c6                                        cmp     eax, esi
000A2A22 [004231CA] 74 27                                        jz      short near ptr unk_4231F3 ; game-relative-target=0x000A2A4B
000A2A24 [004231CC] 50                                           push    eax
000A2A25 [004231CD] b8 40 58 40 00                               mov     eax, 405840h
000A2A2A [004231D2] ff d0                                        call    eax
000A2A2C [004231D4] 85 c0                                        test    eax, eax
000A2A2E [004231D6] 58                                           pop     eax
000A2A2F [004231D7] 74 1a                                        jz      short near ptr unk_4231F3 ; game-relative-target=0x000A2A4B
000A2A31 [004231D9] 50                                           push    eax
000A2A32 [004231DA] 50                                           push    eax
000A2A33 [004231DB] 8b cf                                        mov     ecx, edi
000A2A35 [004231DD] b8 60 eb 46 00                               mov     eax, 46EB60h
000A2A3A [004231E2] ff d0                                        call    eax
000A2A3C [004231E4] 85 c0                                        test    eax, eax
000A2A3E [004231E6] 58                                           pop     eax
000A2A3F [004231E7] 75 0a                                        jnz     short near ptr unk_4231F3 ; game-relative-target=0x000A2A4B
000A2A41 [004231E9] 50                                           push    eax
000A2A42 [004231EA] 8b cf                                        mov     ecx, edi
000A2A44 [004231EC] b8 70 ef 46 00                               mov     eax, 46EF70h
000A2A49 [004231F1] ff d0                                        call    eax
000A2A4B [004231F3] 45                                           inc     ebp
000A2A4C [004231F4] 43                                           inc     ebx
000A2A4D [004231F5] 80 fb 08                                     cmp     bl, 8
000A2A50 [004231F8] 7c c2                                        jl      short near ptr unk_4231BC ; game-relative-target=0x000A2A14
000A2A52 [004231FA] 5b                                           pop     ebx
000A2A53 [004231FB] 5d                                           pop     ebp
000A2A54 [004231FC] 5f                                           pop     edi
000A2A55 [004231FD] 58                                           pop     eax
000A2A56 [004231FE] 68 0b b0 43 00                               push    43B00Bh
000A2A5B [00423203] c3                                           retn
