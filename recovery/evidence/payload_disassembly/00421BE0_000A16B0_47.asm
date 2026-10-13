; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421BE0; baseline game VA=0x000A16B0; size=71
; Relative branch annotations use the baseline game destination.
000A16B0 [00421BE0] 58                                           pop     eax
000A16B1 [00421BE1] c6 44 24 04 f0                               mov     byte ptr [esp+4], 0F0h
000A16B6 [00421BE6] b8 30 f3 46 00                               mov     eax, 46F330h
000A16BB [00421BEB] ff d0                                        call    eax
000A16BD [00421BED] 85 c0                                        test    eax, eax
000A16BF [00421BEF] 7e 2a                                        jle     short near ptr unk_421C1B ; game-relative-target=0x000A16EB
000A16C1 [00421BF1] 33 c0                                        xor     eax, eax
000A16C3 [00421BF3] 8b 49 04                                     mov     ecx, [ecx+4]
000A16C6 [00421BF6] 8b 51 08                                     mov     edx, [ecx+8]
000A16C9 [00421BF9] 03 42 30                                     add     eax, [edx+30h]
000A16CC [00421BFC] 8b 09                                        mov     ecx, [ecx]
000A16CE [00421BFE] 85 c9                                        test    ecx, ecx
000A16D0 [00421C00] 75 f4                                        jnz     short near ptr unk_421BF6 ; game-relative-target=0x000A16C6
000A16D2 [00421C02] 3b 46 30                                     cmp     eax, [esi+30h]
000A16D5 [00421C05] 7c 14                                        jl      short near ptr unk_421C1B ; game-relative-target=0x000A16EB
000A16D7 [00421C07] 56                                           push    esi
000A16D8 [00421C08] 8d 4c 24 24                                  lea     ecx, [esp+24h]
000A16DC [00421C0C] b8 50 ee 46 00                               mov     eax, 46EE50h
000A16E1 [00421C11] ff d0                                        call    eax
000A16E3 [00421C13] 8b 44 24 2c                                  mov     eax, [esp+2Ch]
000A16E7 [00421C17] 85 c0                                        test    eax, eax
000A16E9 [00421C19] 74 06                                        jz      short near ptr unk_421C21 ; game-relative-target=0x000A16F1
000A16EB [00421C1B] 68 56 26 4a 00                               push    4A2656h
000A16F0 [00421C20] c3                                           retn
000A16F1 [00421C21] 68 fa 26 4a 00                               push    4A26FAh
000A16F6 [00421C26] c3                                           retn
