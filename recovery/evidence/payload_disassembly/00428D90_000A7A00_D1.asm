; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428D90; baseline game VA=0x000A7A00; size=209
; Relative branch annotations use the baseline game destination.
000A7A00 [00428D90] 57                                           push    edi
000A7A01 [00428D91] 55                                           push    ebp
000A7A02 [00428D92] 53                                           push    ebx
000A7A03 [00428D93] 80 78 06 03                                  cmp     byte ptr [eax+6], 3
000A7A07 [00428D97] 74 09                                        jz      short near ptr unk_428DA2 ; game-relative-target=0x000A7A12
000A7A09 [00428D99] 83 c0 58                                     add     eax, 58h ; 'X'
000A7A0C [00428D9C] f6 40 22 40                                  test    byte ptr [eax+22h], 40h ; '@'
000A7A10 [00428DA0] 74 3f                                        jz      short near ptr unk_428DE1 ; game-relative-target=0x000A7A51
000A7A12 [00428DA2] 83 78 38 46                                  cmp     dword ptr [eax+38h], 46h ; 'F'
000A7A16 [00428DA6] 7d 39                                        jge     short near ptr unk_428DE1 ; game-relative-target=0x000A7A51
000A7A18 [00428DA8] 83 78 24 01                                  cmp     dword ptr [eax+24h], 1
000A7A1C [00428DAC] 75 33                                        jnz     short near ptr unk_428DE1 ; game-relative-target=0x000A7A51
000A7A1E [00428DAE] 8b e8                                        mov     ebp, eax
000A7A20 [00428DB0] 8b da                                        mov     ebx, edx
000A7A22 [00428DB2] 8b c8                                        mov     ecx, eax
000A7A24 [00428DB4] 8b 01                                        mov     eax, [ecx]
000A7A26 [00428DB6] ff 90 bc 00 00 00                            call    dword ptr [eax+0BCh]
000A7A2C [00428DBC] 85 c0                                        test    eax, eax
000A7A2E [00428DBE] 74 21                                        jz      short near ptr unk_428DE1 ; game-relative-target=0x000A7A51
000A7A30 [00428DC0] 83 b8 84 00 00 00 01                         cmp     dword ptr [eax+84h], 1
000A7A37 [00428DC7] 7f 18                                        jg      short near ptr unk_428DE1 ; game-relative-target=0x000A7A51
000A7A39 [00428DC9] 83 b8 80 00 00 00 00                         cmp     dword ptr [eax+80h], 0
000A7A40 [00428DD0] 75 0f                                        jnz     short near ptr unk_428DE1 ; game-relative-target=0x000A7A51
000A7A42 [00428DD2] 8b f8                                        mov     edi, eax
000A7A44 [00428DD4] 6a 04                                        push    4
000A7A46 [00428DD6] b8 f0 ef 4a 00                               mov     eax, 4AEFF0h
000A7A4B [00428DDB] ff d0                                        call    eax
000A7A4D [00428DDD] 85 c0                                        test    eax, eax
000A7A4F [00428DDF] 75 02                                        jnz     short near ptr unk_428DE3 ; game-relative-target=0x000A7A53
000A7A51 [00428DE1] eb 73                                        jmp     short near ptr unk_428E56 ; game-relative-target=0x000A7AC6
000A7A53 [00428DE3] 8b cf                                        mov     ecx, edi
000A7A55 [00428DE5] b8 a0 d3 44 00                               mov     eax, 44D3A0h
000A7A5A [00428DEA] ff d0                                        call    eax
000A7A5C [00428DEC] 99                                           cdq
000A7A5D [00428DED] 6a 18                                        push    18h
000A7A5F [00428DEF] 59                                           pop     ecx
000A7A60 [00428DF0] f7 f1                                        div     ecx
000A7A62 [00428DF2] 3c 06                                        cmp     al, 6
000A7A64 [00428DF4] 7d 02                                        jge     short near ptr unk_428DF8 ; game-relative-target=0x000A7A68
000A7A66 [00428DF6] b0 06                                        mov     al, 6
000A7A68 [00428DF8] 01 45 38                                     add     [ebp+38h], eax
000A7A6B [00428DFB] 8b 45 74                                     mov     eax, [ebp+74h]
000A7A6E [00428DFE] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A7A72 [00428E02] 75 16                                        jnz     short near ptr unk_428E1A ; game-relative-target=0x000A7A8A
000A7A74 [00428E04] 80 7b 06 03                                  cmp     byte ptr [ebx+6], 3
000A7A78 [00428E08] 74 03                                        jz      short near ptr unk_428E0D ; game-relative-target=0x000A7A7D
000A7A7A [00428E0A] 83 c3 58                                     add     ebx, 58h ; 'X'
000A7A7D [00428E0D] 8b 43 74                                     mov     eax, [ebx+74h]
000A7A80 [00428E10] 85 c0                                        test    eax, eax
000A7A82 [00428E12] 74 35                                        jz      short near ptr unk_428E49 ; game-relative-target=0x000A7AB9
000A7A84 [00428E14] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A7A88 [00428E18] 74 2f                                        jz      short near ptr unk_428E49 ; game-relative-target=0x000A7AB9
000A7A8A [00428E1A] 55                                           push    ebp
000A7A8B [00428E1B] 55                                           push    ebp
000A7A8C [00428E1C] 8b ce                                        mov     ecx, esi
000A7A8E [00428E1E] b8 e0 86 50 00                               mov     eax, 5086E0h
000A7A93 [00428E23] ff d0                                        call    eax
000A7A95 [00428E25] 57                                           push    edi
000A7A96 [00428E26] 6a 01                                        push    1
000A7A98 [00428E28] 68 b4 1a 00 00                               push    1AB4h
000A7A9D [00428E2D] b8 d0 6e 56 00                               mov     eax, 566ED0h
000A7AA2 [00428E32] ff d0                                        call    eax
000A7AA4 [00428E34] 6a 01                                        push    1
000A7AA6 [00428E36] 6a 00                                        push    0
000A7AA8 [00428E38] 68 aa 00 00 00                               push    0AAh
000A7AAD [00428E3D] 50                                           push    eax
000A7AAE [00428E3E] 57                                           push    edi
000A7AAF [00428E3F] b8 70 ee 47 00                               mov     eax, 47EE70h
000A7AB4 [00428E44] ff d0                                        call    eax
000A7AB6 [00428E46] 83 c4 20                                     add     esp, 20h ; ' '
000A7AB9 [00428E49] 6a 1c                                        push    1Ch
000A7ABB [00428E4B] 55                                           push    ebp
000A7ABC [00428E4C] 55                                           push    ebp
000A7ABD [00428E4D] 8b ce                                        mov     ecx, esi
000A7ABF [00428E4F] b8 30 87 50 00                               mov     eax, 508730h
000A7AC4 [00428E54] ff d0                                        call    eax
000A7AC6 [00428E56] 5b                                           pop     ebx
000A7AC7 [00428E57] 5d                                           pop     ebp
000A7AC8 [00428E58] 5f                                           pop     edi
000A7AC9 [00428E59] 8b ce                                        mov     ecx, esi
000A7ACB [00428E5B] 68 f0 af 49 00                               push    49AFF0h
000A7AD0 [00428E60] c3                                           retn
