; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426B40; baseline game VA=0x000A6878; size=224
; Relative branch annotations use the baseline game destination.
000A6878 [00426B40] 56                                           push    esi
000A6879 [00426B41] 57                                           push    edi
000A687A [00426B42] 53                                           push    ebx
000A687B [00426B43] 55                                           push    ebp
000A687C [00426B44] 51                                           push    ecx
000A687D [00426B45] 83 ec 44                                     sub     esp, 44h ; 'D'
000A6880 [00426B48] 8b cc                                        mov     ecx, esp
000A6882 [00426B4A] b8 70 c9 46 00                               mov     eax, 46C970h
000A6887 [00426B4F] ff d0                                        call    eax
000A6889 [00426B51] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A688D [00426B55] b8 70 c9 46 00                               mov     eax, 46C970h
000A6892 [00426B5A] ff d0                                        call    eax
000A6894 [00426B5C] 8b 54 24 44                                  mov     edx, [esp+44h]
000A6898 [00426B60] 52                                           push    edx
000A6899 [00426B61] 50                                           push    eax
000A689A [00426B62] b8 40 5c 47 00                               mov     eax, 475C40h
000A689F [00426B67] ff d0                                        call    eax
000A68A1 [00426B69] 33 f6                                        xor     esi, esi
000A68A3 [00426B6B] 8b 7c 24 24                                  mov     edi, [esp+24h]
000A68A7 [00426B6F] 85 ff                                        test    edi, edi
000A68A9 [00426B71] 0f 84 8b 00 00 00                            jz      near ptr unk_426C02 ; game-relative-target=0x000A693A
000A68AF [00426B77] 8b 5f 08                                     mov     ebx, [edi+8]
000A68B2 [00426B7A] 89 7c 24 40                                  mov     [esp+40h], edi
000A68B6 [00426B7E] 8b 4c 24 44                                  mov     ecx, [esp+44h]
000A68BA [00426B82] 53                                           push    ebx
000A68BB [00426B83] b8 b0 e1 45 00                               mov     eax, 45E1B0h
000A68C0 [00426B88] ff d0                                        call    eax
000A68C2 [00426B8A] 85 c0                                        test    eax, eax
000A68C4 [00426B8C] 74 66                                        jz      short near ptr unk_426BF4 ; game-relative-target=0x000A692C
000A68C6 [00426B8E] 8b 83 88 00 00 00                            mov     eax, [ebx+88h]
000A68CC [00426B94] 3d 88 13 00 00                               cmp     eax, 1388h
000A68D1 [00426B99] 7e 59                                        jle     short near ptr unk_426BF4 ; game-relative-target=0x000A692C
000A68D3 [00426B9B] 8b d4                                        mov     edx, esp
000A68D5 [00426B9D] 53                                           push    ebx
000A68D6 [00426B9E] 52                                           push    edx
000A68D7 [00426B9F] b8 40 5c 47 00                               mov     eax, 475C40h
000A68DC [00426BA4] ff d0                                        call    eax
000A68DE [00426BA6] 33 ed                                        xor     ebp, ebp
000A68E0 [00426BA8] 8b 7c 24 04                                  mov     edi, [esp+4]
000A68E4 [00426BAC] 85 ff                                        test    edi, edi
000A68E6 [00426BAE] 74 44                                        jz      short near ptr unk_426BF4 ; game-relative-target=0x000A692C
000A68E8 [00426BB0] 8b 57 08                                     mov     edx, [edi+8]
000A68EB [00426BB3] 8b cb                                        mov     ecx, ebx
000A68ED [00426BB5] b8 f8 3b 0a 00                               mov     eax, 0A3BF8h
000A68F2 [00426BBA] ff d0                                        call    eax
000A68F4 [00426BBC] 3b c5                                        cmp     eax, ebp
000A68F6 [00426BBE] 7e 02                                        jle     short near ptr unk_426BC2 ; game-relative-target=0x000A68FA
000A68F8 [00426BC0] 8b e8                                        mov     ebp, eax
000A68FA [00426BC2] 8b 3f                                        mov     edi, [edi]
000A68FC [00426BC4] 85 ff                                        test    edi, edi
000A68FE [00426BC6] 75 e8                                        jnz     short near ptr unk_426BB0 ; game-relative-target=0x000A68E8
000A6900 [00426BC8] 2b ab 88 00 00 00                            sub     ebp, [ebx+88h]
000A6906 [00426BCE] 7d 24                                        jge     short near ptr unk_426BF4 ; game-relative-target=0x000A692C
000A6908 [00426BD0] f7 dd                                        neg     ebp
000A690A [00426BD2] 8b 4c 24 44                                  mov     ecx, [esp+44h]
000A690E [00426BD6] 53                                           push    ebx
000A690F [00426BD7] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A6914 [00426BDC] ff d0                                        call    eax
000A6916 [00426BDE] 83 f8 4b                                     cmp     eax, 4Bh ; 'K'
000A6919 [00426BE1] 7f 11                                        jg      short near ptr unk_426BF4 ; game-relative-target=0x000A692C
000A691B [00426BE3] 83 e8 50                                     sub     eax, 50h ; 'P'
000A691E [00426BE6] f7 d8                                        neg     eax
000A6920 [00426BE8] f7 ed                                        imul    ebp
000A6922 [00426BEA] b9 3c 00 00 00                               mov     ecx, 3Ch ; '<'
000A6927 [00426BEF] 99                                           cdq
000A6928 [00426BF0] f7 f1                                        div     ecx
000A692A [00426BF2] 03 f0                                        add     esi, eax
000A692C [00426BF4] 8b 7c 24 40                                  mov     edi, [esp+40h]
000A6930 [00426BF8] 8b 3f                                        mov     edi, [edi]
000A6932 [00426BFA] 85 ff                                        test    edi, edi
000A6934 [00426BFC] 0f 85 75 ff ff ff                            jnz     near ptr unk_426B77 ; game-relative-target=0x000A68AF
000A693A [00426C02] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A693E [00426C06] b8 90 c9 46 00                               mov     eax, 46C990h
000A6943 [00426C0B] ff d0                                        call    eax
000A6945 [00426C0D] 8b cc                                        mov     ecx, esp
000A6947 [00426C0F] b8 90 c9 46 00                               mov     eax, 46C990h
000A694C [00426C14] ff d0                                        call    eax
000A694E [00426C16] 83 c4 48                                     add     esp, 48h ; 'H'
000A6951 [00426C19] 8b c6                                        mov     eax, esi
000A6953 [00426C1B] 5d                                           pop     ebp
000A6954 [00426C1C] 5b                                           pop     ebx
000A6955 [00426C1D] 5f                                           pop     edi
000A6956 [00426C1E] 5e                                           pop     esi
000A6957 [00426C1F] c3                                           retn
