; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424870; baseline game VA=0x000A3A00; size=186
; Relative branch annotations use the baseline game destination.
000A3A00 [00424870] 3b ca                                        cmp     ecx, edx
000A3A02 [00424872] 7d 02                                        jge     short near ptr unk_424876 ; game-relative-target=0x000A3A06
000A3A04 [00424874] 8b ca                                        mov     ecx, edx
000A3A06 [00424876] 89 4c 24 04                                  mov     [esp+4], ecx
000A3A0A [0042487A] 8b 74 24 40                                  mov     esi, [esp+40h]
000A3A0E [0042487E] 8b 9e 88 00 00 00                            mov     ebx, [esi+88h]
000A3A14 [00424884] 2b d9                                        sub     ebx, ecx
000A3A16 [00424886] 81 fb 88 13 00 00                            cmp     ebx, 1388h
000A3A1C [0042488C] 7d 15                                        jge     short near ptr unk_4248A3 ; game-relative-target=0x000A3A33
000A3A1E [0042488E] 56                                           push    esi
000A3A1F [0042488F] 8d 8d 38 08 00 00                            lea     ecx, [ebp+838h]
000A3A25 [00424895] b8 50 ee 46 00                               mov     eax, 46EE50h
000A3A2A [0042489A] ff d0                                        call    eax
000A3A2C [0042489C] 8b 86 88 00 00 00                            mov     eax, [esi+88h]
000A3A32 [004248A2] c3                                           retn
000A3A33 [004248A3] 8b 45 38                                     mov     eax, [ebp+38h]
000A3A36 [004248A6] f6 40 34 04                                  test    byte ptr [eax+34h], 4
000A3A3A [004248AA] 74 03                                        jz      short near ptr unk_4248AF ; game-relative-target=0x000A3A3F
000A3A3C [004248AC] 8b c1                                        mov     eax, ecx
000A3A3E [004248AE] c3                                           retn
000A3A3F [004248AF] 8b 86 e8 00 00 00                            mov     eax, [esi+0E8h]
000A3A45 [004248B5] 85 c0                                        test    eax, eax
000A3A47 [004248B7] 74 d5                                        jz      short near ptr unk_42488E ; game-relative-target=0x000A3A1E
000A3A49 [004248B9] 50                                           push    eax
000A3A4A [004248BA] 8b ce                                        mov     ecx, esi
000A3A4C [004248BC] b8 d0 53 43 00                               mov     eax, 4353D0h
000A3A51 [004248C1] ff d0                                        call    eax
000A3A53 [004248C3] 59                                           pop     ecx
000A3A54 [004248C4] 3c 02                                        cmp     al, 2
000A3A56 [004248C6] 7f 05                                        jg      short near ptr unk_4248CD ; game-relative-target=0x000A3A5D
000A3A58 [004248C8] 3c 01                                        cmp     al, 1
000A3A5A [004248CA] 74 01                                        jz      short near ptr unk_4248CD ; game-relative-target=0x000A3A5D
000A3A5C [004248CC] 49                                           dec     ecx
000A3A5D [004248CD] 51                                           push    ecx
000A3A5E [004248CE] 8b c3                                        mov     eax, ebx
000A3A60 [004248D0] 99                                           cdq
000A3A61 [004248D1] b9 10 27 00 00                               mov     ecx, 2710h
000A3A66 [004248D6] f7 f1                                        div     ecx
000A3A68 [004248D8] 81 fa 88 13 00 00                            cmp     edx, 1388h
000A3A6E [004248DE] 7c 01                                        jl      short near ptr unk_4248E1 ; game-relative-target=0x000A3A71
000A3A70 [004248E0] 40                                           inc     eax
000A3A71 [004248E1] 8b d0                                        mov     edx, eax
000A3A73 [004248E3] 58                                           pop     eax
000A3A74 [004248E4] 3b c2                                        cmp     eax, edx
000A3A76 [004248E6] 7f 05                                        jg      short near ptr unk_4248ED ; game-relative-target=0x000A3A7D
000A3A78 [004248E8] 8b 44 24 04                                  mov     eax, [esp+4]
000A3A7C [004248EC] c3                                           retn
000A3A7D [004248ED] 2b c2                                        sub     eax, edx
000A3A7F [004248EF] 8b ca                                        mov     ecx, edx
000A3A81 [004248F1] 99                                           cdq
000A3A82 [004248F2] f7 f1                                        div     ecx
000A3A84 [004248F4] 66 3d 03 00                                  cmp     ax, 3
000A3A88 [004248F8] 7c 06                                        jl      short near ptr unk_424900 ; game-relative-target=0x000A3A90
000A3A8A [004248FA] 66 b8 03 00                                  mov     ax, 3
000A3A8E [004248FE] 33 d2                                        xor     edx, edx
000A3A90 [00424900] 50                                           push    eax
000A3A91 [00424901] 52                                           push    edx
000A3A92 [00424902] b8 ff ff ff 7f                               mov     eax, 7FFFFFFFh
000A3A97 [00424907] 99                                           cdq
000A3A98 [00424908] f7 f1                                        div     ecx
000A3A9A [0042490A] 5a                                           pop     edx
000A3A9B [0042490B] f7 ea                                        imul    edx
000A3A9D [0042490D] b9 33 33 33 33                               mov     ecx, 33333333h
000A3AA2 [00424912] f7 e9                                        imul    ecx
000A3AA4 [00424914] d1 e9                                        shr     ecx, 1
000A3AA6 [00424916] 58                                           pop     eax
000A3AA7 [00424917] 0f af c1                                     imul    eax, ecx
000A3AAA [0042491A] 03 c2                                        add     eax, edx
000A3AAC [0042491C] f7 eb                                        imul    ebx
000A3AAE [0042491E] 03 da                                        add     ebx, edx
000A3AB0 [00424920] 8b 86 88 00 00 00                            mov     eax, [esi+88h]
000A3AB6 [00424926] 2b c3                                        sub     eax, ebx
000A3AB8 [00424928] c3                                           retn
000A3AB9 [00424929] cc                                           int     3
