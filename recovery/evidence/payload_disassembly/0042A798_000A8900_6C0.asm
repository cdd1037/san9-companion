; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A798; baseline game VA=0x000A8900; size=1728
; Relative branch annotations use the baseline game destination.
000A8900 [0042A798] 81 fa c0 00 00 00                            cmp     edx, 0C0h
000A8906 [0042A79E] 75 06                                        jnz     short near ptr unk_42A7A6 ; game-relative-target=0x000A890E
000A8908 [0042A7A0] 68 c0 89 0a 00                               push    0A89C0h
000A890D [0042A7A5] c3                                           retn
000A890E [0042A7A6] 8b 81 4c 07 00 00                            mov     eax, [ecx+74Ch]
000A8914 [0042A7AC] 85 c0                                        test    eax, eax
000A8916 [0042A7AE] 75 01                                        jnz     short near ptr unk_42A7B1 ; game-relative-target=0x000A8919
000A8918 [0042A7B0] c3                                           retn
000A8919 [0042A7B1] 8d 42 cf                                     lea     eax, [edx-31h]
000A891C [0042A7B4] 83 f8 05                                     cmp     eax, 5
000A891F [0042A7B7] 77 06                                        ja      short near ptr unk_42A7BF ; game-relative-target=0x000A8927
000A8921 [0042A7B9] 68 d0 8d 0a 00                               push    0A8DD0h
000A8926 [0042A7BE] c3                                           retn
000A8927 [0042A7BF] 83 fa 59                                     cmp     edx, 59h ; 'Y'
000A892A [0042A7C2] 75 06                                        jnz     short near ptr unk_42A7CA ; game-relative-target=0x000A8932
000A892C [0042A7C4] 68 5c 8e 0a 00                               push    0A8E5Ch
000A8931 [0042A7C9] c3                                           retn
000A8932 [0042A7CA] 33 c0                                        xor     eax, eax
000A8934 [0042A7CC] 83 fa 51                                     cmp     edx, 51h ; 'Q'
000A8937 [0042A7CF] 74 18                                        jz      short near ptr unk_42A7E9 ; game-relative-target=0x000A8951
000A8939 [0042A7D1] 40                                           inc     eax
000A893A [0042A7D2] 83 fa 57                                     cmp     edx, 57h ; 'W'
000A893D [0042A7D5] 74 12                                        jz      short near ptr unk_42A7E9 ; game-relative-target=0x000A8951
000A893F [0042A7D7] 40                                           inc     eax
000A8940 [0042A7D8] 83 fa 45                                     cmp     edx, 45h ; 'E'
000A8943 [0042A7DB] 74 0c                                        jz      short near ptr unk_42A7E9 ; game-relative-target=0x000A8951
000A8945 [0042A7DD] 40                                           inc     eax
000A8946 [0042A7DE] 83 fa 52                                     cmp     edx, 52h ; 'R'
000A8949 [0042A7E1] 74 06                                        jz      short near ptr unk_42A7E9 ; game-relative-target=0x000A8951
000A894B [0042A7E3] 40                                           inc     eax
000A894C [0042A7E4] 83 fa 54                                     cmp     edx, 54h ; 'T'
000A894F [0042A7E7] 75 06                                        jnz     short near ptr unk_42A7EF ; game-relative-target=0x000A8957
000A8951 [0042A7E9] 68 f4 8c 0a 00                               push    0A8CF4h
000A8956 [0042A7EE] c3                                           retn
000A8957 [0042A7EF] 33 c0                                        xor     eax, eax
000A8959 [0042A7F1] 83 fa 41                                     cmp     edx, 41h ; 'A'
000A895C [0042A7F4] 74 12                                        jz      short near ptr unk_42A808 ; game-relative-target=0x000A8970
000A895E [0042A7F6] 40                                           inc     eax
000A895F [0042A7F7] 83 fa 53                                     cmp     edx, 53h ; 'S'
000A8962 [0042A7FA] 74 0c                                        jz      short near ptr unk_42A808 ; game-relative-target=0x000A8970
000A8964 [0042A7FC] 40                                           inc     eax
000A8965 [0042A7FD] 83 fa 44                                     cmp     edx, 44h ; 'D'
000A8968 [0042A800] 74 06                                        jz      short near ptr unk_42A808 ; game-relative-target=0x000A8970
000A896A [0042A802] 40                                           inc     eax
000A896B [0042A803] 83 fa 46                                     cmp     edx, 46h ; 'F'
000A896E [0042A806] 75 06                                        jnz     short near ptr unk_42A80E ; game-relative-target=0x000A8976
000A8970 [0042A808] 68 30 8c 0a 00                               push    0A8C30h
000A8975 [0042A80D] c3                                           retn
000A8976 [0042A80E] 33 c0                                        xor     eax, eax
000A8978 [0042A810] 83 fa 5a                                     cmp     edx, 5Ah ; 'Z'
000A897B [0042A813] 74 12                                        jz      short near ptr unk_42A827 ; game-relative-target=0x000A898F
000A897D [0042A815] 40                                           inc     eax
000A897E [0042A816] 83 fa 58                                     cmp     edx, 58h ; 'X'
000A8981 [0042A819] 74 0c                                        jz      short near ptr unk_42A827 ; game-relative-target=0x000A898F
000A8983 [0042A81B] 40                                           inc     eax
000A8984 [0042A81C] 83 fa 43                                     cmp     edx, 43h ; 'C'
000A8987 [0042A81F] 74 06                                        jz      short near ptr unk_42A827 ; game-relative-target=0x000A898F
000A8989 [0042A821] 40                                           inc     eax
000A898A [0042A822] 83 fa 56                                     cmp     edx, 56h ; 'V'
000A898D [0042A825] 75 06                                        jnz     short near ptr unk_42A82D ; game-relative-target=0x000A8995
000A898F [0042A827] 68 a0 8e 0a 00                               push    0A8EA0h
000A8994 [0042A82C] c3                                           retn
000A8995 [0042A82D] c3                                           retn
000A8996 [0042A82E] 8b 44 24 04                                  mov     eax, [esp+4]
000A899A [0042A832] 8b 08                                        mov     ecx, [eax]
000A899C [0042A834] 33 c0                                        xor     eax, eax
000A899E [0042A836] 0f b7 91 04 01 00 00                         movzx   edx, word ptr [ecx+104h]
000A89A5 [0042A83D] 85 d2                                        test    edx, edx
000A89A7 [0042A83F] 74 06                                        jz      short near ptr unk_42A847 ; game-relative-target=0x000A89AF
000A89A9 [0042A841] f6 c6 80                                     test    dh, 80h
000A89AC [0042A844] 0f 95 c0                                     setnz   al
000A89AF [0042A847] c3                                           retn
000A89B0 [0042A848] 8b 54 24 04                                  mov     edx, [esp+4]
000A89B4 [0042A84C] 8b 0a                                        mov     ecx, [edx]
000A89B6 [0042A84E] 8b 81 04 01 00 00                            mov     eax, [ecx+104h]
000A89BC [0042A854] 83 e0 07                                     and     eax, 7
000A89BF [0042A857] c3                                           retn
000A89C0 [0042A858] 55                                           push    ebp
000A89C1 [0042A859] 53                                           push    ebx
000A89C2 [0042A85A] 57                                           push    edi
000A89C3 [0042A85B] 56                                           push    esi
000A89C4 [0042A85C] 8b e9                                        mov     ebp, ecx
000A89C6 [0042A85E] 8d b9 2c 07 00 00                            lea     edi, [ecx+72Ch]
000A89CC [0042A864] 83 ec 20                                     sub     esp, 20h ; ' '
000A89CF [0042A867] 8b cc                                        mov     ecx, esp
000A89D1 [0042A869] b8 f0 0d 47 00                               mov     eax, 470DF0h
000A89D6 [0042A86E] ff d0                                        call    eax
000A89D8 [0042A870] 6a 00                                        push    0
000A89DA [0042A872] 68 96 89 0a 00                               push    0A8996h
000A89DF [0042A877] 8d 57 e0                                     lea     edx, [edi-20h]
000A89E2 [0042A87A] 52                                           push    edx
000A89E3 [0042A87B] 8b c8                                        mov     ecx, eax
000A89E5 [0042A87D] b8 c0 f3 46 00                               mov     eax, 46F3C0h
000A89EA [0042A882] ff d0                                        call    eax
000A89EC [0042A884] 48                                           dec     eax
000A89ED [0042A885] 0f 8c 7c 01 00 00                            jl      near ptr unk_42AA07 ; game-relative-target=0x000A8B6F
000A89F3 [0042A88B] 74 2b                                        jz      short near ptr unk_42A8B8 ; game-relative-target=0x000A8A20
000A89F5 [0042A88D] 8b cc                                        mov     ecx, esp
000A89F7 [0042A88F] 6a 00                                        push    0
000A89F9 [0042A891] 68 50 7e 0a 00                               push    0A7E50h
000A89FE [0042A896] b8 10 f6 46 00                               mov     eax, 46F610h
000A8A03 [0042A89B] ff d0                                        call    eax
000A8A05 [0042A89D] 8b 77 04                                     mov     esi, [edi+4]
000A8A08 [0042A8A0] 85 f6                                        test    esi, esi
000A8A0A [0042A8A2] 74 14                                        jz      short near ptr unk_42A8B8 ; game-relative-target=0x000A8A20
000A8A0C [0042A8A4] 8d 56 08                                     lea     edx, [esi+8]
000A8A0F [0042A8A7] 52                                           push    edx
000A8A10 [0042A8A8] b8 96 89 0a 00                               mov     eax, 0A8996h
000A8A15 [0042A8AD] ff d0                                        call    eax
000A8A17 [0042A8AF] 5a                                           pop     edx
000A8A18 [0042A8B0] 85 c0                                        test    eax, eax
000A8A1A [0042A8B2] 75 0d                                        jnz     short near ptr unk_42A8C1 ; game-relative-target=0x000A8A29
000A8A1C [0042A8B4] 8b 36                                        mov     esi, [esi]
000A8A1E [0042A8B6] eb e8                                        jmp     short near ptr unk_42A8A0 ; game-relative-target=0x000A8A08
000A8A20 [0042A8B8] 8b 44 24 04                                  mov     eax, [esp+4]
000A8A24 [0042A8BC] 8b 40 08                                     mov     eax, [eax+8]
000A8A27 [0042A8BF] eb 0b                                        jmp     short near ptr unk_42A8CC ; game-relative-target=0x000A8A34
000A8A29 [0042A8C1] 8b 12                                        mov     edx, [edx]
000A8A2B [0042A8C3] 8b cc                                        mov     ecx, esp
000A8A2D [0042A8C5] b8 f0 8b 0a 00                               mov     eax, 0A8BF0h
000A8A32 [0042A8CA] ff d0                                        call    eax
000A8A34 [0042A8CC] 8b d8                                        mov     ebx, eax
000A8A36 [0042A8CE] 8b c8                                        mov     ecx, eax
000A8A38 [0042A8D0] b8 70 7e 0a 00                               mov     eax, 0A7E70h
000A8A3D [0042A8D5] ff d0                                        call    eax
000A8A3F [0042A8D7] 6a 00                                        push    0
000A8A41 [0042A8D9] 50                                           push    eax
000A8A42 [0042A8DA] 68 e0 7d 0a 00                               push    0A7DE0h
000A8A47 [0042A8DF] 8d 57 e0                                     lea     edx, [edi-20h]
000A8A4A [0042A8E2] 52                                           push    edx
000A8A4B [0042A8E3] 8b cf                                        mov     ecx, edi
000A8A4D [0042A8E5] b8 f0 f3 46 00                               mov     eax, 46F3F0h
000A8A52 [0042A8EA] ff d0                                        call    eax
000A8A54 [0042A8EC] 8b cf                                        mov     ecx, edi
000A8A56 [0042A8EE] 6a 01                                        push    1
000A8A58 [0042A8F0] 68 b0 89 0a 00                               push    0A89B0h
000A8A5D [0042A8F5] b8 10 f6 46 00                               mov     eax, 46F610h
000A8A62 [0042A8FA] ff d0                                        call    eax
000A8A64 [0042A8FC] 6a 05                                        push    5
000A8A66 [0042A8FE] 8b cf                                        mov     ecx, edi
000A8A68 [0042A900] b8 b0 ee 46 00                               mov     eax, 46EEB0h
000A8A6D [0042A905] ff d0                                        call    eax
000A8A6F [0042A907] 53                                           push    ebx
000A8A70 [0042A908] 8b cf                                        mov     ecx, edi
000A8A72 [0042A90A] b8 60 eb 46 00                               mov     eax, 46EB60h
000A8A77 [0042A90F] ff d0                                        call    eax
000A8A79 [0042A911] 85 c0                                        test    eax, eax
000A8A7B [0042A913] 75 13                                        jnz     short near ptr unk_42A928 ; game-relative-target=0x000A8A90
000A8A7D [0042A915] 8b cf                                        mov     ecx, edi
000A8A7F [0042A917] b8 80 7b 43 00                               mov     eax, 437B80h
000A8A84 [0042A91C] ff d0                                        call    eax
000A8A86 [0042A91E] 53                                           push    ebx
000A8A87 [0042A91F] 8b cf                                        mov     ecx, edi
000A8A89 [0042A921] b8 70 82 51 00                               mov     eax, 518270h
000A8A8E [0042A926] ff d0                                        call    eax
000A8A90 [0042A928] 57                                           push    edi
000A8A91 [0042A929] 8b cd                                        mov     ecx, ebp
000A8A93 [0042A92B] b8 50 83 4e 00                               mov     eax, 4E8350h
000A8A98 [0042A930] ff d0                                        call    eax
000A8A9A [0042A932] 8b 9b 04 01 00 00                            mov     ebx, [ebx+104h]
000A8AA0 [0042A938] 8b c3                                        mov     eax, ebx
000A8AA2 [0042A93A] c1 e8 04                                     shr     eax, 4
000A8AA5 [0042A93D] 83 e0 1f                                     and     eax, 1Fh
000A8AA8 [0042A940] 50                                           push    eax
000A8AA9 [0042A941] ba 90 38 45 00                               mov     edx, 453890h
000A8AAE [0042A946] ff d2                                        call    edx
000A8AB0 [0042A948] 8b f0                                        mov     esi, eax
000A8AB2 [0042A94A] 89 04 24                                     mov     [esp], eax
000A8AB5 [0042A94D] 8d 4f 24                                     lea     ecx, [edi+24h]
000A8AB8 [0042A950] b8 60 eb 46 00                               mov     eax, 46EB60h
000A8ABD [0042A955] ff d0                                        call    eax
000A8ABF [0042A957] 85 c0                                        test    eax, eax
000A8AC1 [0042A959] 75 05                                        jnz     short near ptr unk_42A960 ; game-relative-target=0x000A8AC8
000A8AC3 [0042A95B] be a0 0e 50 01                               mov     esi, 1500EA0h
000A8AC8 [0042A960] 89 77 20                                     mov     [edi+20h], esi
000A8ACB [0042A963] 33 c0                                        xor     eax, eax
000A8ACD [0042A965] 83 7f 0c 04                                  cmp     dword ptr [edi+0Ch], 4
000A8AD1 [0042A969] 7f 06                                        jg      short near ptr unk_42A971 ; game-relative-target=0x000A8AD9
000A8AD3 [0042A96B] f6 c3 08                                     test    bl, 8
000A8AD6 [0042A96E] 0f 95 c0                                     setnz   al
000A8AD9 [0042A971] 53                                           push    ebx
000A8ADA [0042A972] 8b d8                                        mov     ebx, eax
000A8ADC [0042A974] 33 f6                                        xor     esi, esi
000A8ADE [0042A976] 56                                           push    esi
000A8ADF [0042A977] 8b 4f 20                                     mov     ecx, [edi+20h]
000A8AE2 [0042A97A] b8 f0 87 44 00                               mov     eax, 4487F0h
000A8AE7 [0042A97F] ff d0                                        call    eax
000A8AE9 [0042A981] 89 84 f5 80 23 00 00                         mov     [ebp+esi*8+2380h], eax
000A8AF0 [0042A988] 8b d6                                        mov     edx, esi
000A8AF2 [0042A98A] 2b d3                                        sub     edx, ebx
000A8AF4 [0042A98C] 52                                           push    edx
000A8AF5 [0042A98D] 8b cf                                        mov     ecx, edi
000A8AF7 [0042A98F] b8 e0 e8 46 00                               mov     eax, 46E8E0h
000A8AFC [0042A994] ff d0                                        call    eax
000A8AFE [0042A996] 89 84 f5 7c 23 00 00                         mov     [ebp+esi*8+237Ch], eax
000A8B05 [0042A99D] 46                                           inc     esi
000A8B06 [0042A99E] 83 fe 05                                     cmp     esi, 5
000A8B09 [0042A9A1] 7c d3                                        jl      short near ptr unk_42A976 ; game-relative-target=0x000A8ADE
000A8B0B [0042A9A3] 5b                                           pop     ebx
000A8B0C [0042A9A4] 8b c3                                        mov     eax, ebx
000A8B0E [0042A9A6] c1 e8 09                                     shr     eax, 9
000A8B11 [0042A9A9] 83 e0 07                                     and     eax, 7
000A8B14 [0042A9AC] 83 c0 14                                     add     eax, 14h
000A8B17 [0042A9AF] 50                                           push    eax
000A8B18 [0042A9B0] ba 90 38 45 00                               mov     edx, 453890h
000A8B1D [0042A9B5] ff d2                                        call    edx
000A8B1F [0042A9B7] 8b f0                                        mov     esi, eax
000A8B21 [0042A9B9] 89 04 24                                     mov     [esp], eax
000A8B24 [0042A9BC] 8d 4f 48                                     lea     ecx, [edi+48h]
000A8B27 [0042A9BF] b8 60 eb 46 00                               mov     eax, 46EB60h
000A8B2C [0042A9C4] ff d0                                        call    eax
000A8B2E [0042A9C6] 85 c0                                        test    eax, eax
000A8B30 [0042A9C8] 75 05                                        jnz     short near ptr unk_42A9CF ; game-relative-target=0x000A8B37
000A8B32 [0042A9CA] be 10 16 50 01                               mov     esi, 1501610h
000A8B37 [0042A9CF] 89 77 44                                     mov     [edi+44h], esi
000A8B3A [0042A9D2] 8b cd                                        mov     ecx, ebp
000A8B3C [0042A9D4] b8 00 84 4e 00                               mov     eax, 4E8400h
000A8B41 [0042A9D9] ff d0                                        call    eax
000A8B43 [0042A9DB] 8b cd                                        mov     ecx, ebp
000A8B45 [0042A9DD] b8 90 83 4e 00                               mov     eax, 4E8390h
000A8B4A [0042A9E2] ff d0                                        call    eax
000A8B4C [0042A9E4] c1 eb 0c                                     shr     ebx, 0Ch
000A8B4F [0042A9E7] 83 e3 07                                     and     ebx, 7
000A8B52 [0042A9EA] 74 0f                                        jz      short near ptr unk_42A9FB ; game-relative-target=0x000A8B63
000A8B54 [0042A9EC] 43                                           inc     ebx
000A8B55 [0042A9ED] 69 c3 88 13 00 00                            imul    eax, ebx, 1388h
000A8B5B [0042A9F3] 3b 47 6c                                     cmp     eax, [edi+6Ch]
000A8B5E [0042A9F6] 7d 03                                        jge     short near ptr unk_42A9FB ; game-relative-target=0x000A8B63
000A8B60 [0042A9F8] 89 47 68                                     mov     [edi+68h], eax
000A8B63 [0042A9FB] 8b cd                                        mov     ecx, ebp
000A8B65 [0042A9FD] 8b 01                                        mov     eax, [ecx]
000A8B67 [0042A9FF] 6a 01                                        push    1
000A8B69 [0042AA01] ff 90 ec 00 00 00                            call    dword ptr [eax+0ECh]
000A8B6F [0042AA07] 8b cc                                        mov     ecx, esp
000A8B71 [0042AA09] b8 10 0e 47 00                               mov     eax, 470E10h
000A8B76 [0042AA0E] ff d0                                        call    eax
000A8B78 [0042AA10] 83 c4 20                                     add     esp, 20h ; ' '
000A8B7B [0042AA13] 5e                                           pop     esi
000A8B7C [0042AA14] 5f                                           pop     edi
000A8B7D [0042AA15] 5b                                           pop     ebx
000A8B7E [0042AA16] 5d                                           pop     ebp
000A8B7F [0042AA17] c3                                           retn
000A8B80 [0042AA18] 00    db 0x00
000A8B81 [0042AA19] 00    db 0x00
000A8B82 [0042AA1A] 00    db 0x00
000A8B83 [0042AA1B] 00    db 0x00
000A8B84 [0042AA1C] 00    db 0x00
000A8B85 [0042AA1D] 00    db 0x00
000A8B86 [0042AA1E] 00    db 0x00
000A8B87 [0042AA1F] 00    db 0x00
000A8B88 [0042AA20] 00    db 0x00
000A8B89 [0042AA21] 00    db 0x00
000A8B8A [0042AA22] 00    db 0x00
000A8B8B [0042AA23] 00    db 0x00
000A8B8C [0042AA24] 00    db 0x00
000A8B8D [0042AA25] 00    db 0x00
000A8B8E [0042AA26] 00    db 0x00
000A8B8F [0042AA27] 00 88 13 00 00 78                            add     [eax+78000013h], cl
000A8B95 [0042AA2D] ec                                           in      al, dx
000A8B96 [0042AA2E] FF    db 0xFF
000A8B97 [0042AA2F] FF    db 0xFF
000A8B98 [0042AA30] b8 0b 00 00 48                               mov     eax, 4800000Bh
000A8B9D [0042AA35] f4                                           hlt
000A8B9E [0042AA36] FF    db 0xFF
000A8B9F [0042AA37] ff 98 3a 00 00 20                            call    fword ptr [eax+2000003Ah]
000A8BA5 [0042AA3D] 4e                                           dec     esi
000A8BA6 [0042AA3E] 00    db 0x00
000A8BA7 [0042AA3F] 00 a8 61 00 00 30                            add     [eax+30000061h], ch
000A8BAD [0042AA45] 75 00                                        jnz     short $+2 ; game-relative-target=0x000A8BAF
000A8BAF [0042AA47] 00 ce                                        add     dh, cl
000A8BB1 [0042AA49] 8b 0a                                        mov     ecx, [edx]
000A8BB3 [0042AA4B] 00 d3                                        add     bl, dl
000A8BB5 [0042AA4D] 8b 0a                                        mov     ecx, [edx]
000A8BB7 [0042AA4F] 00 d7                                        add     bh, dl
000A8BB9 [0042AA51] 8b 0a                                        mov     ecx, [edx]
000A8BBB [0042AA53] 00 db                                        add     bl, bl
000A8BBD [0042AA55] 8b 0a                                        mov     ecx, [edx]
000A8BBF [0042AA57] 00 de                                        add     dh, bl
000A8BC1 [0042AA59] 8b 0a                                        mov     ecx, [edx]
000A8BC3 [0042AA5B] 00 e0                                        add     al, ah
000A8BC5 [0042AA5D] 8b 0a                                        mov     ecx, [edx]
000A8BC7 [0042AA5F] 00 05 04 04 03 02                            add     ds:2030404h, al
000A8BCD [0042AA65] 04 00                                        add     al, 0
000A8BCF [0042AA67] 01 0f                                        add     [edi], ecx
000A8BD1 [0042AA69] 12 13                                        adc     dl, [ebx]
000A8BD3 [0042AA6B] 02 03                                        add     al, [ebx]
000A8BD5 [0042AA6D] 10 11                                        adc     [ecx], dl
000A8BD7 [0042AA6F] 05 02 10 06 04                               add     eax, 4061002h
000A8BDC [0042AA74] 05 08 06 07 08                               add     eax, 8070608h
000A8BE1 [0042AA79] 09 0a                                        or      [edx], ecx
000A8BE3 [0042AA7B] 0b 00                                        or      eax, [eax]
000A8BE5 [0042AA7D] 02 03                                        add     al, [ebx]
000A8BE7 [0042AA7F] 05 06 08 09 0b                               add     eax, 0B090806h
000A8BEC [0042AA84] 15 1e cc cc 56                               adc     eax, 56CCCC1Eh
000A8BF1 [0042AA89] 57                                           push    edi
000A8BF2 [0042AA8A] 8b f9                                        mov     edi, ecx
000A8BF4 [0042AA8C] 6a 00                                        push    0
000A8BF6 [0042AA8E] 52                                           push    edx
000A8BF7 [0042AA8F] b8 f0 5c 41 00                               mov     eax, 415CF0h
000A8BFC [0042AA94] ff d0                                        call    eax
000A8BFE [0042AA96] 85 c0                                        test    eax, eax
000A8C00 [0042AA98] 74 20                                        jz      short near ptr unk_42AABA ; game-relative-target=0x000A8C22
000A8C02 [0042AA9A] 8b f0                                        mov     esi, eax
000A8C04 [0042AA9C] 6a 20                                        push    20h ; ' '
000A8C06 [0042AA9E] ff 15 5c f3 5f 00                            call    dword ptr ds:5FF35Ch
000A8C0C [0042AAA4] 84 e4                                        test    ah, ah
000A8C0E [0042AAA6] 79 0c                                        jns     short near ptr unk_42AAB4 ; game-relative-target=0x000A8C1C
000A8C10 [0042AAA8] 8b 4e 04                                     mov     ecx, [esi+4]
000A8C13 [0042AAAB] 85 c9                                        test    ecx, ecx
000A8C15 [0042AAAD] 75 0e                                        jnz     short near ptr unk_42AABD ; game-relative-target=0x000A8C25
000A8C17 [0042AAAF] 8b 4f 08                                     mov     ecx, [edi+8]
000A8C1A [0042AAB2] eb 09                                        jmp     short near ptr unk_42AABD ; game-relative-target=0x000A8C25
000A8C1C [0042AAB4] 8b 0e                                        mov     ecx, [esi]
000A8C1E [0042AAB6] 85 c9                                        test    ecx, ecx
000A8C20 [0042AAB8] 75 03                                        jnz     short near ptr unk_42AABD ; game-relative-target=0x000A8C25
000A8C22 [0042AABA] 8b 4f 04                                     mov     ecx, [edi+4]
000A8C25 [0042AABD] 8b 41 08                                     mov     eax, [ecx+8]
000A8C28 [0042AAC0] 5f                                           pop     edi
000A8C29 [0042AAC1] 5e                                           pop     esi
000A8C2A [0042AAC2] c3                                           retn
000A8C2B [0042AAC3] 90                                           nop
000A8C2C [0042AAC4] 00    db 0x00
000A8C2D [0042AAC5] 00    db 0x00
000A8C2E [0042AAC6] 00    db 0x00
000A8C2F [0042AAC7] 00 56 57                                     add     [esi+57h], dl
000A8C32 [0042AACA] 55                                           push    ebp
000A8C33 [0042AACB] 8b f9                                        mov     edi, ecx
000A8C35 [0042AACD] 8b e8                                        mov     ebp, eax
000A8C37 [0042AACF] 8d b1 94 07 00 00                            lea     esi, [ecx+794h]
000A8C3D [0042AAD5] 6a 20                                        push    20h ; ' '
000A8C3F [0042AAD7] ff 15 5c f3 5f 00                            call    dword ptr ds:5FF35Ch
000A8C45 [0042AADD] 84 e4                                        test    ah, ah
000A8C47 [0042AADF] 79 11                                        jns     short near ptr unk_42AAF2 ; game-relative-target=0x000A8C5A
000A8C49 [0042AAE1] 8b 04 ad a0 8b 0a 00                         mov     eax, ds:0A8BA0h[ebp*4]
000A8C50 [0042AAE8] 3b 46 04                                     cmp     eax, [esi+4]
000A8C53 [0042AAEB] 7e 38                                        jle     short near ptr unk_42AB25 ; game-relative-target=0x000A8C8D
000A8C55 [0042AAED] 8b 46 04                                     mov     eax, [esi+4]
000A8C58 [0042AAF0] eb 33                                        jmp     short near ptr unk_42AB25 ; game-relative-target=0x000A8C8D
000A8C5A [0042AAF2] 8b 2c ad 90 8b 0a 00                         mov     ebp, ds:0A8B90h[ebp*4]
000A8C61 [0042AAF9] 6a 10                                        push    10h
000A8C63 [0042AAFB] ff 15 5c f3 5f 00                            call    dword ptr ds:5FF35Ch
000A8C69 [0042AB01] 84 e4                                        test    ah, ah
000A8C6B [0042AB03] 78 02                                        js      short near ptr unk_42AB07 ; game-relative-target=0x000A8C6F
000A8C6D [0042AB05] f7 dd                                        neg     ebp
000A8C6F [0042AB07] 8b 0e                                        mov     ecx, [esi]
000A8C71 [0042AB09] 8d 04 29                                     lea     eax, [ecx+ebp]
000A8C74 [0042AB0C] 85 c0                                        test    eax, eax
000A8C76 [0042AB0E] 7e 12                                        jle     short near ptr unk_42AB22 ; game-relative-target=0x000A8C8A
000A8C78 [0042AB10] 85 ed                                        test    ebp, ebp
000A8C7A [0042AB12] 78 09                                        js      short near ptr unk_42AB1D ; game-relative-target=0x000A8C85
000A8C7C [0042AB14] 3b 4e 04                                     cmp     ecx, [esi+4]
000A8C7F [0042AB17] 75 04                                        jnz     short near ptr unk_42AB1D ; game-relative-target=0x000A8C85
000A8C81 [0042AB19] 8b c5                                        mov     eax, ebp
000A8C83 [0042AB1B] eb 08                                        jmp     short near ptr unk_42AB25 ; game-relative-target=0x000A8C8D
000A8C85 [0042AB1D] 3b 46 04                                     cmp     eax, [esi+4]
000A8C88 [0042AB20] 7c 03                                        jl      short near ptr unk_42AB25 ; game-relative-target=0x000A8C8D
000A8C8A [0042AB22] 8b 46 04                                     mov     eax, [esi+4]
000A8C8D [0042AB25] 89 06                                        mov     [esi], eax
000A8C8F [0042AB27] 8b cf                                        mov     ecx, edi
000A8C91 [0042AB29] 8b 07                                        mov     eax, [edi]
000A8C93 [0042AB2B] 6a 01                                        push    1
000A8C95 [0042AB2D] ff 90 ec 00 00 00                            call    dword ptr [eax+0ECh]
000A8C9B [0042AB33] 5d                                           pop     ebp
000A8C9C [0042AB34] 5f                                           pop     edi
000A8C9D [0042AB35] 5e                                           pop     esi
000A8C9E [0042AB36] c3                                           retn
000A8C9F [0042AB37] cc                                           int     3
000A8CA0 [0042AB38] 53                                           push    ebx
000A8CA1 [0042AB39] 55                                           push    ebp
000A8CA2 [0042AB3A] 57                                           push    edi
000A8CA3 [0042AB3B] 56                                           push    esi
000A8CA4 [0042AB3C] 8b f9                                        mov     edi, ecx
000A8CA6 [0042AB3E] b8 e0 80 51 00                               mov     eax, 5180E0h
000A8CAB [0042AB43] ff d0                                        call    eax
000A8CAD [0042AB45] 8b 74 24 14                                  mov     esi, [esp+14h]
000A8CB1 [0042AB49] 8b 44 24 18                                  mov     eax, [esp+18h]
000A8CB5 [0042AB4D] 8b 04 45 e4 8b 0a 00                         mov     eax, ds:0A8BE4h[eax*2]
000A8CBC [0042AB54] 0f b6 ec                                     movzx   ebp, ah
000A8CBF [0042AB57] 0f b6 d8                                     movzx   ebx, al
000A8CC2 [0042AB5A] 8b ce                                        mov     ecx, esi
000A8CC4 [0042AB5C] 55                                           push    ebp
000A8CC5 [0042AB5D] b8 70 f7 44 00                               mov     eax, 44F770h
000A8CCA [0042AB62] ff d0                                        call    eax
000A8CCC [0042AB64] 85 c0                                        test    eax, eax
000A8CCE [0042AB66] 74 15                                        jz      short near ptr unk_42AB7D ; game-relative-target=0x000A8CE5
000A8CD0 [0042AB68] 55                                           push    ebp
000A8CD1 [0042AB69] b8 20 37 45 00                               mov     eax, 453720h
000A8CD6 [0042AB6E] ff d0                                        call    eax
000A8CD8 [0042AB70] 83 c4 04                                     add     esp, 4
000A8CDB [0042AB73] 50                                           push    eax
000A8CDC [0042AB74] 8b cf                                        mov     ecx, edi
000A8CDE [0042AB76] b8 70 ef 46 00                               mov     eax, 46EF70h
000A8CE3 [0042AB7B] ff d0                                        call    eax
000A8CE5 [0042AB7D] 4d                                           dec     ebp
000A8CE6 [0042AB7E] 3b eb                                        cmp     ebp, ebx
000A8CE8 [0042AB80] 7d d8                                        jge     short near ptr unk_42AB5A ; game-relative-target=0x000A8CC2
000A8CEA [0042AB82] 8b 47 0c                                     mov     eax, [edi+0Ch]
000A8CED [0042AB85] 5e                                           pop     esi
000A8CEE [0042AB86] 5f                                           pop     edi
000A8CEF [0042AB87] 5d                                           pop     ebp
000A8CF0 [0042AB88] 5b                                           pop     ebx
000A8CF1 [0042AB89] c2 08 00                                     retn    8
000A8CF4 [0042AB8C] 56                                           push    esi
000A8CF5 [0042AB8D] 57                                           push    edi
000A8CF6 [0042AB8E] 53                                           push    ebx
000A8CF7 [0042AB8F] 55                                           push    ebp
000A8CF8 [0042AB90] 8b e8                                        mov     ebp, eax
000A8CFA [0042AB92] 8b f9                                        mov     edi, ecx
000A8CFC [0042AB94] 33 db                                        xor     ebx, ebx
000A8CFE [0042AB96] 8d 91 60 21 00 00                            lea     edx, [ecx+2160h]
000A8D04 [0042AB9C] 8b 02                                        mov     eax, [edx]
000A8D06 [0042AB9E] 85 c0                                        test    eax, eax
000A8D08 [0042ABA0] 74 07                                        jz      short near ptr unk_42ABA9 ; game-relative-target=0x000A8D11
000A8D0A [0042ABA2] 8b 72 f4                                     mov     esi, [edx-0Ch]
000A8D0D [0042ABA5] 85 f6                                        test    esi, esi
000A8D0F [0042ABA7] 75 36                                        jnz     short near ptr unk_42ABDF ; game-relative-target=0x000A8D47
000A8D11 [0042ABA9] 43                                           inc     ebx
000A8D12 [0042ABAA] 83 c2 70                                     add     edx, 70h ; 'p'
000A8D15 [0042ABAD] 83 fb 04                                     cmp     ebx, 4
000A8D18 [0042ABB0] 7e ea                                        jle     short near ptr unk_42AB9C ; game-relative-target=0x000A8D04
000A8D1A [0042ABB2] 8b cf                                        mov     ecx, edi
000A8D1C [0042ABB4] 8b b9 30 07 00 00                            mov     edi, [ecx+730h]
000A8D22 [0042ABBA] 85 ff                                        test    edi, edi
000A8D24 [0042ABBC] 74 1c                                        jz      short near ptr unk_42ABDA ; game-relative-target=0x000A8D42
000A8D26 [0042ABBE] 51                                           push    ecx
000A8D27 [0042ABBF] 8b 77 08                                     mov     esi, [edi+8]
000A8D2A [0042ABC2] 8b 3f                                        mov     edi, [edi]
000A8D2C [0042ABC4] 8b cd                                        mov     ecx, ebp
000A8D2E [0042ABC6] b8 4d 7c 0a 00                               mov     eax, 0A7C4Dh
000A8D33 [0042ABCB] ff d0                                        call    eax
000A8D35 [0042ABCD] 75 f0                                        jnz     short near ptr unk_42ABBF ; game-relative-target=0x000A8D27
000A8D37 [0042ABCF] 59                                           pop     ecx
000A8D38 [0042ABD0] 8b 01                                        mov     eax, [ecx]
000A8D3A [0042ABD2] 6a 01                                        push    1
000A8D3C [0042ABD4] ff 90 ec 00 00 00                            call    dword ptr [eax+0ECh]
000A8D42 [0042ABDA] 5d                                           pop     ebp
000A8D43 [0042ABDB] 5b                                           pop     ebx
000A8D44 [0042ABDC] 5f                                           pop     edi
000A8D45 [0042ABDD] 5e                                           pop     esi
000A8D46 [0042ABDE] c3                                           retn
000A8D47 [0042ABDF] 83 ec 20                                     sub     esp, 20h ; ' '
000A8D4A [0042ABE2] 8b cc                                        mov     ecx, esp
000A8D4C [0042ABE4] b8 b0 fa 46 00                               mov     eax, 46FAB0h
000A8D51 [0042ABE9] ff d0                                        call    eax
000A8D53 [0042ABEB] 55                                           push    ebp
000A8D54 [0042ABEC] 56                                           push    esi
000A8D55 [0042ABED] 8b c8                                        mov     ecx, eax
000A8D57 [0042ABEF] b8 a0 8c 0a 00                               mov     eax, 0A8CA0h
000A8D5C [0042ABF4] ff d0                                        call    eax
000A8D5E [0042ABF6] 85 c0                                        test    eax, eax
000A8D60 [0042ABF8] 74 1b                                        jz      short near ptr unk_42AC15 ; game-relative-target=0x000A8D7D
000A8D62 [0042ABFA] 8b 56 08                                     mov     edx, [esi+8]
000A8D65 [0042ABFD] 8b cc                                        mov     ecx, esp
000A8D67 [0042ABFF] b8 f0 8b 0a 00                               mov     eax, 0A8BF0h
000A8D6C [0042AC04] ff d0                                        call    eax
000A8D6E [0042AC06] 89 46 08                                     mov     [esi+8], eax
000A8D71 [0042AC09] 8b cf                                        mov     ecx, edi
000A8D73 [0042AC0B] 8b 07                                        mov     eax, [edi]
000A8D75 [0042AC0D] 6a 01                                        push    1
000A8D77 [0042AC0F] ff 90 ec 00 00 00                            call    dword ptr [eax+0ECh]
000A8D7D [0042AC15] 8b cc                                        mov     ecx, esp
000A8D7F [0042AC17] b8 d0 fa 46 00                               mov     eax, 46FAD0h
000A8D84 [0042AC1C] ff d0                                        call    eax
000A8D86 [0042AC1E] 83 c4 20                                     add     esp, 20h ; ' '
000A8D89 [0042AC21] 5d                                           pop     ebp
000A8D8A [0042AC22] 5b                                           pop     ebx
000A8D8B [0042AC23] 5f                                           pop     edi
000A8D8C [0042AC24] 5e                                           pop     esi
000A8D8D [0042AC25] c3                                           retn
000A8D8E [0042AC26] 00    db 0x00
000A8D8F [0042AC27] 00 57 56                                     add     [edi+56h], dl
000A8D92 [0042AC2A] 55                                           push    ebp
000A8D93 [0042AC2B] 53                                           push    ebx
000A8D94 [0042AC2C] 8b 7c 24 14                                  mov     edi, [esp+14h]
000A8D98 [0042AC30] 8b 17                                        mov     edx, [edi]
000A8D9A [0042AC32] 8a 5a 04                                     mov     bl, [edx+4]
000A8D9D [0042AC35] 8b 77 04                                     mov     esi, [edi+4]
000A8DA0 [0042AC38] 0f b6 ae c8 8b 0a 00                         movzx   ebp, byte ptr [esi+0A8BC8h]
000A8DA7 [0042AC3F] 8b 3c b5 b0 8b 0a 00                         mov     edi, ds:0A8BB0h[esi*4]
000A8DAE [0042AC46] 33 c0                                        xor     eax, eax
000A8DB0 [0042AC48] 33 d2                                        xor     edx, edx
000A8DB2 [0042AC4A] 8b 0f                                        mov     ecx, [edi]
000A8DB4 [0042AC4C] 3a d9                                        cmp     bl, cl
000A8DB6 [0042AC4E] 75 03                                        jnz     short near ptr unk_42AC53 ; game-relative-target=0x000A8DBB
000A8DB8 [0042AC50] 40                                           inc     eax
000A8DB9 [0042AC51] eb 10                                        jmp     short near ptr unk_42AC63 ; game-relative-target=0x000A8DCB
000A8DBB [0042AC53] 42                                           inc     edx
000A8DBC [0042AC54] c1 e9 08                                     shr     ecx, 8
000A8DBF [0042AC57] 83 fa 03                                     cmp     edx, 3
000A8DC2 [0042AC5A] 7e 03                                        jle     short near ptr unk_42AC5F ; game-relative-target=0x000A8DC7
000A8DC4 [0042AC5C] 8b 4f 04                                     mov     ecx, [edi+4]
000A8DC7 [0042AC5F] 3b d5                                        cmp     edx, ebp
000A8DC9 [0042AC61] 7c e9                                        jl      short near ptr unk_42AC4C ; game-relative-target=0x000A8DB4
000A8DCB [0042AC63] 5b                                           pop     ebx
000A8DCC [0042AC64] 5d                                           pop     ebp
000A8DCD [0042AC65] 5e                                           pop     esi
000A8DCE [0042AC66] 5f                                           pop     edi
000A8DCF [0042AC67] c3                                           retn
000A8DD0 [0042AC68] 53                                           push    ebx
000A8DD1 [0042AC69] 55                                           push    ebp
000A8DD2 [0042AC6A] 56                                           push    esi
000A8DD3 [0042AC6B] 57                                           push    edi
000A8DD4 [0042AC6C] 8b e9                                        mov     ebp, ecx
000A8DD6 [0042AC6E] 8b f8                                        mov     edi, eax
000A8DD8 [0042AC70] 8d 99 4c 07 00 00                            lea     ebx, [ecx+74Ch]
000A8DDE [0042AC76] 83 ec 20                                     sub     esp, 20h ; ' '
000A8DE1 [0042AC79] 8b cc                                        mov     ecx, esp
000A8DE3 [0042AC7B] b8 60 ff 46 00                               mov     eax, 46FF60h
000A8DE8 [0042AC80] ff d0                                        call    eax
000A8DEA [0042AC82] 6a 00                                        push    0
000A8DEC [0042AC84] 57                                           push    edi
000A8DED [0042AC85] 68 90 8d 0a 00                               push    0A8D90h
000A8DF2 [0042AC8A] 8d 53 04                                     lea     edx, [ebx+4]
000A8DF5 [0042AC8D] 52                                           push    edx
000A8DF6 [0042AC8E] 8b c8                                        mov     ecx, eax
000A8DF8 [0042AC90] b8 f0 f3 46 00                               mov     eax, 46F3F0h
000A8DFD [0042AC95] ff d0                                        call    eax
000A8DFF [0042AC97] 85 c0                                        test    eax, eax
000A8E01 [0042AC99] 7e 46                                        jle     short near ptr unk_42ACE1 ; game-relative-target=0x000A8E49
000A8E03 [0042AC9B] 8b 13                                        mov     edx, [ebx]
000A8E05 [0042AC9D] 8b cc                                        mov     ecx, esp
000A8E07 [0042AC9F] b8 f0 8b 0a 00                               mov     eax, 0A8BF0h
000A8E0C [0042ACA4] ff d0                                        call    eax
000A8E0E [0042ACA6] 89 03                                        mov     [ebx], eax
000A8E10 [0042ACA8] 33 ff                                        xor     edi, edi
000A8E12 [0042ACAA] 8d b5 80 23 00 00                            lea     esi, [ebp+2380h]
000A8E18 [0042ACB0] c7 06 09 00 00 00                            mov     dword ptr [esi], 9
000A8E1E [0042ACB6] 8b 0b                                        mov     ecx, [ebx]
000A8E20 [0042ACB8] 57                                           push    edi
000A8E21 [0042ACB9] b8 f0 87 44 00                               mov     eax, 4487F0h
000A8E26 [0042ACBE] ff d0                                        call    eax
000A8E28 [0042ACC0] 89 06                                        mov     [esi], eax
000A8E2A [0042ACC2] 47                                           inc     edi
000A8E2B [0042ACC3] 83 c6 08                                     add     esi, 8
000A8E2E [0042ACC6] 83 ff 05                                     cmp     edi, 5
000A8E31 [0042ACC9] 7c e5                                        jl      short near ptr unk_42ACB0 ; game-relative-target=0x000A8E18
000A8E33 [0042ACCB] 8b cd                                        mov     ecx, ebp
000A8E35 [0042ACCD] b8 00 84 4e 00                               mov     eax, 4E8400h
000A8E3A [0042ACD2] ff d0                                        call    eax
000A8E3C [0042ACD4] 8b cd                                        mov     ecx, ebp
000A8E3E [0042ACD6] 8b 45 00                                     mov     eax, [ebp+0]
000A8E41 [0042ACD9] 6a 01                                        push    1
000A8E43 [0042ACDB] ff 90 ec 00 00 00                            call    dword ptr [eax+0ECh]
000A8E49 [0042ACE1] 8b cc                                        mov     ecx, esp
000A8E4B [0042ACE3] b8 80 ff 46 00                               mov     eax, 46FF80h
000A8E50 [0042ACE8] ff d0                                        call    eax
000A8E52 [0042ACEA] 83 c4 20                                     add     esp, 20h ; ' '
000A8E55 [0042ACED] 5f                                           pop     edi
000A8E56 [0042ACEE] 5e                                           pop     esi
000A8E57 [0042ACEF] 5d                                           pop     ebp
000A8E58 [0042ACF0] 5b                                           pop     ebx
000A8E59 [0042ACF1] c3                                           retn
000A8E5A [0042ACF2] 00    db 0x00
000A8E5B [0042ACF3] 00 57 56                                     add     [edi+56h], dl
000A8E5E [0042ACF6] 8b f9                                        mov     edi, ecx
000A8E60 [0042ACF8] 8d b1 70 07 00 00                            lea     esi, [ecx+770h]
000A8E66 [0042ACFE] 8b 46 10                                     mov     eax, [esi+10h]
000A8E69 [0042AD01] 85 c0                                        test    eax, eax
000A8E6B [0042AD03] 7e 30                                        jle     short near ptr unk_42AD35 ; game-relative-target=0x000A8E9D
000A8E6D [0042AD05] 8b 16                                        mov     edx, [esi]
000A8E6F [0042AD07] 8d 4e 04                                     lea     ecx, [esi+4]
000A8E72 [0042AD0A] b8 f0 8b 0a 00                               mov     eax, 0A8BF0h
000A8E77 [0042AD0F] ff d0                                        call    eax
000A8E79 [0042AD11] 89 06                                        mov     [esi], eax
000A8E7B [0042AD13] 8b c8                                        mov     ecx, eax
000A8E7D [0042AD15] 6a 00                                        push    0
000A8E7F [0042AD17] b8 40 8a 44 00                               mov     eax, 448A40h
000A8E84 [0042AD1C] ff d0                                        call    eax
000A8E86 [0042AD1E] 05 c8 03 00 00                               add     eax, 3C8h
000A8E8B [0042AD23] 89 87 d8 20 00 00                            mov     [edi+20D8h], eax
000A8E91 [0042AD29] 8b cf                                        mov     ecx, edi
000A8E93 [0042AD2B] 8b 07                                        mov     eax, [edi]
000A8E95 [0042AD2D] 6a 01                                        push    1
000A8E97 [0042AD2F] ff 90 ec 00 00 00                            call    dword ptr [eax+0ECh]
000A8E9D [0042AD35] 5e                                           pop     esi
000A8E9E [0042AD36] 5f                                           pop     edi
000A8E9F [0042AD37] c3                                           retn
000A8EA0 [0042AD38] 83 b9 38 07 00 00 05                         cmp     dword ptr [ecx+738h], 5
000A8EA7 [0042AD3F] 7e 01                                        jle     short near ptr unk_42AD42 ; game-relative-target=0x000A8EAA
000A8EA9 [0042AD41] c3                                           retn
000A8EAA [0042AD42] 56                                           push    esi
000A8EAB [0042AD43] 57                                           push    edi
000A8EAC [0042AD44] 55                                           push    ebp
000A8EAD [0042AD45] 53                                           push    ebx
000A8EAE [0042AD46] 8b f1                                        mov     esi, ecx
000A8EB0 [0042AD48] 8b e8                                        mov     ebp, eax
000A8EB2 [0042AD4A] 83 ec 50                                     sub     esp, 50h ; 'P'
000A8EB5 [0042AD4D] 8d 7c 24 20                                  lea     edi, [esp+20h]
000A8EB9 [0042AD51] b9 0c 00 00 00                               mov     ecx, 0Ch
000A8EBE [0042AD56] 33 c0                                        xor     eax, eax
000A8EC0 [0042AD58] f3 ab                                        rep stosd
000A8EC2 [0042AD5A] 33 db                                        xor     ebx, ebx
000A8EC4 [0042AD5C] 33 c9                                        xor     ecx, ecx
000A8EC6 [0042AD5E] 33 d2                                        xor     edx, edx
000A8EC8 [0042AD60] 8d be 7c 23 00 00                            lea     edi, [esi+237Ch]
000A8ECE [0042AD66] 89 7c 8c 20                                  mov     [esp+ecx*4+20h], edi
000A8ED2 [0042AD6A] 8b 07                                        mov     eax, [edi]
000A8ED4 [0042AD6C] 85 c0                                        test    eax, eax
000A8ED6 [0042AD6E] 74 01                                        jz      short near ptr unk_42AD71 ; game-relative-target=0x000A8ED9
000A8ED8 [0042AD70] 42                                           inc     edx
000A8ED9 [0042AD71] 83 7f 04 02                                  cmp     dword ptr [edi+4], 2
000A8EDD [0042AD75] 7e 05                                        jle     short near ptr unk_42AD7C ; game-relative-target=0x000A8EE4
000A8EDF [0042AD77] 89 7c 9c 34                                  mov     [esp+ebx*4+34h], edi
000A8EE3 [0042AD7B] 43                                           inc     ebx
000A8EE4 [0042AD7C] 41                                           inc     ecx
000A8EE5 [0042AD7D] 83 c7 08                                     add     edi, 8
000A8EE8 [0042AD80] 83 f9 05                                     cmp     ecx, 5
000A8EEB [0042AD83] 7c e1                                        jl      short near ptr unk_42AD66 ; game-relative-target=0x000A8ECE
000A8EED [0042AD85] 83 fd 03                                     cmp     ebp, 3
000A8EF0 [0042AD88] 75 12                                        jnz     short near ptr unk_42AD9C ; game-relative-target=0x000A8F04
000A8EF2 [0042AD8A] b8 14 00 00 00                               mov     eax, 14h
000A8EF7 [0042AD8F] 3b da                                        cmp     ebx, edx
000A8EF9 [0042AD91] 7d 05                                        jge     short near ptr unk_42AD98 ; game-relative-target=0x000A8F00
000A8EFB [0042AD93] f7 da                                        neg     edx
000A8EFD [0042AD95] 8d 04 90                                     lea     eax, [eax+edx*4]
000A8F00 [0042AD98] 89 44 24 4c                                  mov     [esp+4Ch], eax
000A8F04 [0042AD9C] 8b cc                                        mov     ecx, esp
000A8F06 [0042AD9E] b8 f0 0d 47 00                               mov     eax, 470DF0h
000A8F0B [0042ADA3] ff d0                                        call    eax
000A8F0D [0042ADA5] 33 db                                        xor     ebx, ebx
000A8F0F [0042ADA7] 8d be 7c 23 00 00                            lea     edi, [esi+237Ch]
000A8F15 [0042ADAD] 33 c0                                        xor     eax, eax
000A8F17 [0042ADAF] 87 07                                        xchg    eax, [edi]
000A8F19 [0042ADB1] 85 c0                                        test    eax, eax
000A8F1B [0042ADB3] 74 0a                                        jz      short near ptr unk_42ADBF ; game-relative-target=0x000A8F27
000A8F1D [0042ADB5] 8b cc                                        mov     ecx, esp
000A8F1F [0042ADB7] 50                                           push    eax
000A8F20 [0042ADB8] b8 70 ef 46 00                               mov     eax, 46EF70h
000A8F25 [0042ADBD] ff d0                                        call    eax
000A8F27 [0042ADBF] 43                                           inc     ebx
000A8F28 [0042ADC0] 83 c7 08                                     add     edi, 8
000A8F2B [0042ADC3] 83 fb 05                                     cmp     ebx, 5
000A8F2E [0042ADC6] 7c e5                                        jl      short near ptr unk_42ADAD ; game-relative-target=0x000A8F15
000A8F30 [0042ADC8] 33 db                                        xor     ebx, ebx
000A8F32 [0042ADCA] 83 fd 01                                     cmp     ebp, 1
000A8F35 [0042ADCD] 7f 11                                        jg      short near ptr unk_42ADE0 ; game-relative-target=0x000A8F48
000A8F37 [0042ADCF] 8d 55 1c                                     lea     edx, [ebp+1Ch]
000A8F3A [0042ADD2] 8b cc                                        mov     ecx, esp
000A8F3C [0042ADD4] 6a 00                                        push    0
000A8F3E [0042ADD6] 52                                           push    edx
000A8F3F [0042ADD7] b8 40 f6 46 00                               mov     eax, 46F640h
000A8F44 [0042ADDC] ff d0                                        call    eax
000A8F46 [0042ADDE] eb 27                                        jmp     short near ptr unk_42AE07 ; game-relative-target=0x000A8F6F
000A8F48 [0042ADE0] 83 fd 02                                     cmp     ebp, 2
000A8F4B [0042ADE3] 75 22                                        jnz     short near ptr unk_42AE07 ; game-relative-target=0x000A8F6F
000A8F4D [0042ADE5] 8b cc                                        mov     ecx, esp
000A8F4F [0042ADE7] 8d 54 24 48                                  lea     edx, [esp+48h]
000A8F53 [0042ADEB] 6a 01                                        push    1
000A8F55 [0042ADED] 6a 1d                                        push    1Dh
000A8F57 [0042ADEF] 52                                           push    edx
000A8F58 [0042ADF0] b8 30 31 47 00                               mov     eax, 473130h
000A8F5D [0042ADF5] ff d0                                        call    eax
000A8F5F [0042ADF7] 8b 5c 24 34                                  mov     ebx, [esp+34h]
000A8F63 [0042ADFB] 89 03                                        mov     [ebx], eax
000A8F65 [0042ADFD] 8b cc                                        mov     ecx, esp
000A8F67 [0042ADFF] 50                                           push    eax
000A8F68 [0042AE00] b8 50 ee 46 00                               mov     eax, 46EE50h
000A8F6D [0042AE05] ff d0                                        call    eax
000A8F6F [0042AE07] 8b 7c 24 04                                  mov     edi, [esp+4]
000A8F73 [0042AE0B] 85 ff                                        test    edi, edi
000A8F75 [0042AE0D] 74 23                                        jz      short near ptr unk_42AE32 ; game-relative-target=0x000A8F9A
000A8F77 [0042AE0F] 8b 6c 24 4c                                  mov     ebp, [esp+4Ch]
000A8F7B [0042AE13] 8d 54 2c 20                                  lea     edx, [esp+ebp+20h]
000A8F7F [0042AE17] 8b 47 08                                     mov     eax, [edi+8]
000A8F82 [0042AE1A] 85 c0                                        test    eax, eax
000A8F84 [0042AE1C] 74 0e                                        jz      short near ptr unk_42AE2C ; game-relative-target=0x000A8F94
000A8F86 [0042AE1E] 39 1a                                        cmp     [edx], ebx
000A8F88 [0042AE20] 75 03                                        jnz     short near ptr unk_42AE25 ; game-relative-target=0x000A8F8D
000A8F8A [0042AE22] 83 c2 04                                     add     edx, 4
000A8F8D [0042AE25] 8b 0a                                        mov     ecx, [edx]
000A8F8F [0042AE27] 89 01                                        mov     [ecx], eax
000A8F91 [0042AE29] 83 c2 04                                     add     edx, 4
000A8F94 [0042AE2C] 8b 3f                                        mov     edi, [edi]
000A8F96 [0042AE2E] 85 ff                                        test    edi, edi
000A8F98 [0042AE30] 75 e5                                        jnz     short near ptr unk_42AE17 ; game-relative-target=0x000A8F7F
000A8F9A [0042AE32] 8b ce                                        mov     ecx, esi
000A8F9C [0042AE34] b8 00 84 4e 00                               mov     eax, 4E8400h
000A8FA1 [0042AE39] ff d0                                        call    eax
000A8FA3 [0042AE3B] 8b ce                                        mov     ecx, esi
000A8FA5 [0042AE3D] 8b 06                                        mov     eax, [esi]
000A8FA7 [0042AE3F] 6a 01                                        push    1
000A8FA9 [0042AE41] ff 90 ec 00 00 00                            call    dword ptr [eax+0ECh]
000A8FAF [0042AE47] 8b cc                                        mov     ecx, esp
000A8FB1 [0042AE49] b8 10 0e 47 00                               mov     eax, 470E10h
000A8FB6 [0042AE4E] ff d0                                        call    eax
000A8FB8 [0042AE50] 83 c4 50                                     add     esp, 50h ; 'P'
000A8FBB [0042AE53] 5b                                           pop     ebx
000A8FBC [0042AE54] 5d                                           pop     ebp
000A8FBD [0042AE55] 5f                                           pop     edi
000A8FBE [0042AE56] 5e                                           pop     esi
000A8FBF [0042AE57] c3                                           retn
