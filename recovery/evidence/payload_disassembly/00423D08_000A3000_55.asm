; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423D08; baseline game VA=0x000A3000; size=85
; Relative branch annotations use the baseline game destination.
000A3000 [00423D08] 56                                           push    esi
000A3001 [00423D09] 57                                           push    edi
000A3002 [00423D0A] 55                                           push    ebp
000A3003 [00423D0B] 53                                           push    ebx
000A3004 [00423D0C] 8d 71 48                                     lea     esi, [ecx+48h]
000A3007 [00423D0F] 33 ff                                        xor     edi, edi
000A3009 [00423D11] 8b 69 18                                     mov     ebp, [ecx+18h]
000A300C [00423D14] 8b 5c 24 14                                  mov     ebx, [esp+14h]
000A3010 [00423D18] 8b 06                                        mov     eax, [esi]
000A3012 [00423D1A] 85 c0                                        test    eax, eax
000A3014 [00423D1C] 74 2c                                        jz      short near ptr unk_423D4A ; game-relative-target=0x000A3042
000A3016 [00423D1E] 39 58 54                                     cmp     [eax+54h], ebx
000A3019 [00423D21] 75 27                                        jnz     short near ptr unk_423D4A ; game-relative-target=0x000A3042
000A301B [00423D23] 0f b6 40 04                                  movzx   eax, byte ptr [eax+4]
000A301F [00423D27] 50                                           push    eax
000A3020 [00423D28] 8b 4d 08                                     mov     ecx, [ebp+8]
000A3023 [00423D2B] b8 60 30 0a 00                               mov     eax, 0A3060h
000A3028 [00423D30] ff d0                                        call    eax
000A302A [00423D32] 59                                           pop     ecx
000A302B [00423D33] 3b c1                                        cmp     eax, ecx
000A302D [00423D35] 74 13                                        jz      short near ptr unk_423D4A ; game-relative-target=0x000A3042
000A302F [00423D37] 47                                           inc     edi
000A3030 [00423D38] f6 44 24 18 01                               test    byte ptr [esp+18h], 1
000A3035 [00423D3D] 74 0b                                        jz      short near ptr unk_423D4A ; game-relative-target=0x000A3042
000A3037 [00423D3F] 50                                           push    eax
000A3038 [00423D40] b8 20 37 45 00                               mov     eax, 453720h
000A303D [00423D45] ff d0                                        call    eax
000A303F [00423D47] 89 06                                        mov     [esi], eax
000A3041 [00423D49] 58                                           pop     eax
000A3042 [00423D4A] 83 c6 04                                     add     esi, 4
000A3045 [00423D4D] 8b 6d 00                                     mov     ebp, [ebp+0]
000A3048 [00423D50] 85 ed                                        test    ebp, ebp
000A304A [00423D52] 75 c4                                        jnz     short near ptr unk_423D18 ; game-relative-target=0x000A3010
000A304C [00423D54] 8b c7                                        mov     eax, edi
000A304E [00423D56] 5b                                           pop     ebx
000A304F [00423D57] 5d                                           pop     ebp
000A3050 [00423D58] 5f                                           pop     edi
000A3051 [00423D59] 5e                                           pop     esi
000A3052 [00423D5A] c2 08 00                                     retn    8
