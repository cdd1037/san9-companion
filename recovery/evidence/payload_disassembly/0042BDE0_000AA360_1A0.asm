; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042BDE0; baseline game VA=0x000AA360; size=416
; Relative branch annotations use the baseline game destination.
000AA360 [0042BDE0] 8b cf                                        mov     ecx, edi
000AA362 [0042BDE2] ff 50 14                                     call    dword ptr [eax+14h]
000AA365 [0042BDE5] 57                                           push    edi
000AA366 [0042BDE6] 56                                           push    esi
000AA367 [0042BDE7] 83 ec 78                                     sub     esp, 78h ; 'x'
000AA36A [0042BDEA] 8b cc                                        mov     ecx, esp
000AA36C [0042BDEC] b8 70 c9 46 00                               mov     eax, 46C970h
000AA371 [0042BDF1] ff d0                                        call    eax
000AA373 [0042BDF3] 33 c0                                        xor     eax, eax
000AA375 [0042BDF5] 8d 7c 24 44                                  lea     edi, [esp+44h]
000AA379 [0042BDF9] b9 0d 00 00 00                               mov     ecx, 0Dh
000AA37E [0042BDFE] f3 ab                                        rep stosd
000AA380 [0042BE00] 8b ac 24 94 00 00 00                         mov     ebp, [esp+94h]
000AA387 [0042BE07] 8b 85 bc 00 00 00                            mov     eax, [ebp+0BCh]
000AA38D [0042BE0D] 8b 80 f4 00 00 00                            mov     eax, [eax+0F4h]
000AA393 [0042BE13] 8b 40 64                                     mov     eax, [eax+64h]
000AA396 [0042BE16] 89 44 24 40                                  mov     [esp+40h], eax
000AA39A [0042BE1A] 8b 55 7c                                     mov     edx, [ebp+7Ch]
000AA39D [0042BE1D] 8b 4a 08                                     mov     ecx, [edx+8]
000AA3A0 [0042BE20] 0f b6 41 04                                  movzx   eax, byte ptr [ecx+4]
000AA3A4 [0042BE24] 80 4c 04 44 01                               or      byte ptr [esp+eax+44h], 1
000AA3A9 [0042BE29] 8b 12                                        mov     edx, [edx]
000AA3AB [0042BE2B] 85 d2                                        test    edx, edx
000AA3AD [0042BE2D] 75 ee                                        jnz     short near ptr unk_42BE1D ; game-relative-target=0x000AA39D
000AA3AF [0042BE2F] 8b 56 4c                                     mov     edx, [esi+4Ch]
000AA3B2 [0042BE32] 8b 4a 08                                     mov     ecx, [edx+8]
000AA3B5 [0042BE35] 0f b6 41 04                                  movzx   eax, byte ptr [ecx+4]
000AA3B9 [0042BE39] 80 4c 04 44 02                               or      byte ptr [esp+eax+44h], 2
000AA3BE [0042BE3E] 8b 12                                        mov     edx, [edx]
000AA3C0 [0042BE40] 85 d2                                        test    edx, edx
000AA3C2 [0042BE42] 75 ee                                        jnz     short near ptr unk_42BE32 ; game-relative-target=0x000AA3B2
000AA3C4 [0042BE44] be 78 80 23 01                               mov     esi, 1238078h
000AA3C9 [0042BE49] bf c8 00 00 00                               mov     edi, 0C8h
000AA3CE [0042BE4E] 56                                           push    esi
000AA3CF [0042BE4F] b8 10 f2 4a 00                               mov     eax, 4AF210h
000AA3D4 [0042BE54] ff d0                                        call    eax
000AA3D6 [0042BE56] 83 c4 04                                     add     esp, 4
000AA3D9 [0042BE59] 85 c0                                        test    eax, eax
000AA3DB [0042BE5B] 74 4d                                        jz      short near ptr unk_42BEAA ; game-relative-target=0x000AA42A
000AA3DD [0042BE5D] 39 74 24 40                                  cmp     [esp+40h], esi
000AA3E1 [0042BE61] 74 47                                        jz      short near ptr unk_42BEAA ; game-relative-target=0x000AA42A
000AA3E3 [0042BE63] 39 ae cc 00 00 00                            cmp     [esi+0CCh], ebp
000AA3E9 [0042BE69] 75 3f                                        jnz     short near ptr unk_42BEAA ; game-relative-target=0x000AA42A
000AA3EB [0042BE6B] 8b 4e 44                                     mov     ecx, [esi+44h]
000AA3EE [0042BE6E] 8b 81 cc 00 00 00                            mov     eax, [ecx+0CCh]
000AA3F4 [0042BE74] 39 a8 b8 00 00 00                            cmp     [eax+0B8h], ebp
000AA3FA [0042BE7A] 74 2e                                        jz      short near ptr unk_42BEAA ; game-relative-target=0x000AA42A
000AA3FC [0042BE7C] 8d 55 78                                     lea     edx, [ebp+78h]
000AA3FF [0042BE7F] 8b 8e d0 00 00 00                            mov     ecx, [esi+0D0h]
000AA405 [0042BE85] 52                                           push    edx
000AA406 [0042BE86] 51                                           push    ecx
000AA407 [0042BE87] b8 70 fc 43 00                               mov     eax, 43FC70h
000AA40C [0042BE8C] ff d0                                        call    eax
000AA40E [0042BE8E] 83 c4 08                                     add     esp, 8
000AA411 [0042BE91] 85 c0                                        test    eax, eax
000AA413 [0042BE93] 74 15                                        jz      short near ptr unk_42BEAA ; game-relative-target=0x000AA42A
000AA415 [0042BE95] 0f b6 40 04                                  movzx   eax, byte ptr [eax+4]
000AA419 [0042BE99] f6 44 04 44 02                               test    byte ptr [esp+eax+44h], 2
000AA41E [0042BE9E] 74 0a                                        jz      short near ptr unk_42BEAA ; game-relative-target=0x000AA42A
000AA420 [0042BEA0] 8b cc                                        mov     ecx, esp
000AA422 [0042BEA2] 56                                           push    esi
000AA423 [0042BEA3] b8 70 82 51 00                               mov     eax, 518270h
000AA428 [0042BEA8] ff d0                                        call    eax
000AA42A [0042BEAA] 81 c6 bc 01 00 00                            add     esi, 1BCh
000AA430 [0042BEB0] 4f                                           dec     edi
000AA431 [0042BEB1] 75 9b                                        jnz     short near ptr unk_42BE4E ; game-relative-target=0x000AA3CE
000AA433 [0042BEB3] 8b d4                                        mov     edx, esp
000AA435 [0042BEB5] 8b 42 0c                                     mov     eax, [edx+0Ch]
000AA438 [0042BEB8] 85 c0                                        test    eax, eax
000AA43A [0042BEBA] 0f 84 b0 00 00 00                            jz      near ptr unk_42BF70 ; game-relative-target=0x000AA4F0
000AA440 [0042BEC0] 8d 8c 24 b8 00 00 00                         lea     ecx, [esp+0B8h]
000AA447 [0042BEC7] 50                                           push    eax
000AA448 [0042BEC8] 52                                           push    edx
000AA449 [0042BEC9] b8 80 ef 46 00                               mov     eax, 46EF80h
000AA44E [0042BECE] ff d0                                        call    eax
000AA450 [0042BED0] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000AA454 [0042BED4] b8 f0 0d 47 00                               mov     eax, 470DF0h
000AA459 [0042BED9] ff d0                                        call    eax
000AA45B [0042BEDB] 8b 7c 24 04                                  mov     edi, [esp+4]
000AA45F [0042BEDF] 8b 57 08                                     mov     edx, [edi+8]
000AA462 [0042BEE2] 81 c2 dc 00 00 00                            add     edx, 0DCh
000AA468 [0042BEE8] 8b 42 0c                                     mov     eax, [edx+0Ch]
000AA46B [0042BEEB] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000AA46F [0042BEEF] 50                                           push    eax
000AA470 [0042BEF0] 52                                           push    edx
000AA471 [0042BEF1] b8 80 ef 46 00                               mov     eax, 46EF80h
000AA476 [0042BEF6] ff d0                                        call    eax
000AA478 [0042BEF8] 8b 3f                                        mov     edi, [edi]
000AA47A [0042BEFA] 85 ff                                        test    edi, edi
000AA47C [0042BEFC] 75 e1                                        jnz     short near ptr unk_42BEDF ; game-relative-target=0x000AA45F
000AA47E [0042BEFE] 8b bd 9c 00 00 00                            mov     edi, [ebp+9Ch]
000AA484 [0042BF04] 85 ff                                        test    edi, edi
000AA486 [0042BF06] 74 30                                        jz      short near ptr unk_42BF38 ; game-relative-target=0x000AA4B8
000AA488 [0042BF08] 8b 77 08                                     mov     esi, [edi+8]
000AA48B [0042BF0B] 8b 46 64                                     mov     eax, [esi+64h]
000AA48E [0042BF0E] 8b cc                                        mov     ecx, esp
000AA490 [0042BF10] 6a 00                                        push    0
000AA492 [0042BF12] 50                                           push    eax
000AA493 [0042BF13] b8 f0 5c 41 00                               mov     eax, 415CF0h
000AA498 [0042BF18] ff d0                                        call    eax
000AA49A [0042BF1A] 85 c0                                        test    eax, eax
000AA49C [0042BF1C] 74 16                                        jz      short near ptr unk_42BF34 ; game-relative-target=0x000AA4B4
000AA49E [0042BF1E] 8d 96 84 00 00 00                            lea     edx, [esi+84h]
000AA4A4 [0042BF24] 8b 42 0c                                     mov     eax, [edx+0Ch]
000AA4A7 [0042BF27] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000AA4AB [0042BF2B] 50                                           push    eax
000AA4AC [0042BF2C] 52                                           push    edx
000AA4AD [0042BF2D] b8 80 ef 46 00                               mov     eax, 46EF80h
000AA4B2 [0042BF32] ff d0                                        call    eax
000AA4B4 [0042BF34] 8b 3f                                        mov     edi, [edi]
000AA4B6 [0042BF36] eb cc                                        jmp     short near ptr unk_42BF04 ; game-relative-target=0x000AA484
000AA4B8 [0042BF38] 8b 44 24 2c                                  mov     eax, [esp+2Ch]
000AA4BC [0042BF3C] 85 c0                                        test    eax, eax
000AA4BE [0042BF3E] 74 25                                        jz      short near ptr unk_42BF65 ; game-relative-target=0x000AA4E5
000AA4C0 [0042BF40] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000AA4C4 [0042BF44] 53                                           push    ebx
000AA4C5 [0042BF45] b8 70 82 51 00                               mov     eax, 518270h
000AA4CA [0042BF4A] ff d0                                        call    eax
000AA4CC [0042BF4C] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000AA4D0 [0042BF50] 6a 00                                        push    0
000AA4D2 [0042BF52] 68 a0 1c 47 00                               push    471CA0h
000AA4D7 [0042BF57] b8 10 f6 46 00                               mov     eax, 46F610h
000AA4DC [0042BF5C] ff d0                                        call    eax
000AA4DE [0042BF5E] 8b 4c 24 24                                  mov     ecx, [esp+24h]
000AA4E2 [0042BF62] 8b 59 08                                     mov     ebx, [ecx+8]
000AA4E5 [0042BF65] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000AA4E9 [0042BF69] b8 10 0e 47 00                               mov     eax, 470E10h
000AA4EE [0042BF6E] ff d0                                        call    eax
000AA4F0 [0042BF70] 8b cc                                        mov     ecx, esp
000AA4F2 [0042BF72] b8 90 c9 46 00                               mov     eax, 46C990h
000AA4F7 [0042BF77] ff d0                                        call    eax
000AA4F9 [0042BF79] 83 c4 78                                     add     esp, 78h ; 'x'
000AA4FC [0042BF7C] 5e                                           pop     esi
000AA4FD [0042BF7D] 5f                                           pop     edi
000AA4FE [0042BF7E] c3                                           retn
000AA4FF [0042BF7F] 90                                           nop
