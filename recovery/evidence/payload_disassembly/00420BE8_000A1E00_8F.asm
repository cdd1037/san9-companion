; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420BE8; baseline game VA=0x000A1E00; size=143
; Relative branch annotations use the baseline game destination.
000A1E00 [00420BE8] 57                                           push    edi
000A1E01 [00420BE9] 8b 3d 24 05 0a 00                            mov     edi, ds:0A0524h
000A1E07 [00420BEF] 85 ff                                        test    edi, edi
000A1E09 [00420BF1] 74 2a                                        jz      short near ptr unk_420C1D ; game-relative-target=0x000A1E35
000A1E0B [00420BF3] 8b 4f 08                                     mov     ecx, [edi+8]
000A1E0E [00420BF6] 8b 3f                                        mov     edi, [edi]
000A1E10 [00420BF8] 80 79 58 33                                  cmp     byte ptr [ecx+58h], 33h ; '3'
000A1E14 [00420BFC] 75 10                                        jnz     short near ptr unk_420C0E ; game-relative-target=0x000A1E26
000A1E16 [00420BFE] f6 41 22 40                                  test    byte ptr [ecx+22h], 40h ; '@'
000A1E1A [00420C02] 75 0a                                        jnz     short near ptr unk_420C0E ; game-relative-target=0x000A1E26
000A1E1C [00420C04] 8b 46 04                                     mov     eax, [esi+4]
000A1E1F [00420C07] 3b 41 50                                     cmp     eax, [ecx+50h]
000A1E22 [00420C0A] 75 e3                                        jnz     short near ptr unk_420BEF ; game-relative-target=0x000A1E07
000A1E24 [00420C0C] eb 05                                        jmp     short near ptr unk_420C13 ; game-relative-target=0x000A1E2B
000A1E26 [00420C0E] 39 71 64                                     cmp     [ecx+64h], esi
000A1E29 [00420C11] 75 dc                                        jnz     short near ptr unk_420BEF ; game-relative-target=0x000A1E07
000A1E2B [00420C13] 8b 41 30                                     mov     eax, [ecx+30h]
000A1E2E [00420C16] 03 41 34                                     add     eax, [ecx+34h]
000A1E31 [00420C19] 03 e8                                        add     ebp, eax
000A1E33 [00420C1B] eb d2                                        jmp     short near ptr unk_420BEF ; game-relative-target=0x000A1E07
000A1E35 [00420C1D] 0f af 6c 24 20                               imul    ebp, [esp+20h]
000A1E3A [00420C22] 83 7c 24 40 00                               cmp     dword ptr [esp+40h], 0
000A1E3F [00420C27] 75 0c                                        jnz     short near ptr unk_420C35 ; game-relative-target=0x000A1E4D
000A1E41 [00420C29] b9 20 05 0a 00                               mov     ecx, 0A0520h
000A1E46 [00420C2E] b8 e0 80 51 00                               mov     eax, 5180E0h
000A1E4B [00420C33] ff d0                                        call    eax
000A1E4D [00420C35] 8b ce                                        mov     ecx, esi
000A1E4F [00420C37] 8b 01                                        mov     eax, [ecx]
000A1E51 [00420C39] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A1E54 [00420C3C] 0f b6 88 00 0d 0a 00                         movzx   ecx, byte ptr [eax+0A0D00h]
000A1E5B [00420C43] c1 e1 0b                                     shl     ecx, 0Bh
000A1E5E [00420C46] 3b 8e 88 00 00 00                            cmp     ecx, [esi+88h]
000A1E64 [00420C4C] 7e 27                                        jle     short near ptr unk_420C75 ; game-relative-target=0x000A1E8D
000A1E66 [00420C4E] 8b ce                                        mov     ecx, esi
000A1E68 [00420C50] b8 90 19 0a 00                               mov     eax, 0A1990h
000A1E6D [00420C55] ff d0                                        call    eax
000A1E6F [00420C57] 03 86 88 00 00 00                            add     eax, [esi+88h]
000A1E75 [00420C5D] 3d 50 46 00 00                               cmp     eax, 4650h
000A1E7A [00420C62] 7c 11                                        jl      short near ptr unk_420C75 ; game-relative-target=0x000A1E8D
000A1E7C [00420C64] 8b c3                                        mov     eax, ebx
000A1E7E [00420C66] 99                                           cdq
000A1E7F [00420C67] b9 0a 00 00 00                               mov     ecx, 0Ah
000A1E84 [00420C6C] f7 f1                                        div     ecx
000A1E86 [00420C6E] 0f af 44 24 20                               imul    eax, [esp+20h]
000A1E8B [00420C73] 03 e8                                        add     ebp, eax
000A1E8D [00420C75] 5f                                           pop     edi
000A1E8E [00420C76] c3                                           retn
