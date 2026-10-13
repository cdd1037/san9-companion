; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A5D8; baseline game VA=0x000A9800; size=396
; Relative branch annotations use the baseline game destination.
000A9800 [0042A5D8] 8d 47 86                                     lea     eax, [edi-7Ah]
000A9803 [0042A5DB] 83 f8 01                                     cmp     eax, 1
000A9806 [0042A5DE] 77 08                                        ja      short near ptr unk_42A5E8 ; game-relative-target=0x000A9810
000A9808 [0042A5E0] 68 b4 99 0a 00                               push    0A99B4h
000A980D [0042A5E5] c3                                           retn
000A980E [0042A5E6] 90                                           nop
000A980F [0042A5E7] 90                                           nop
000A9810 [0042A5E8] 33 c9                                        xor     ecx, ecx
000A9812 [0042A5EA] ba 52 54 59 55                               mov     edx, 55595452h
000A9817 [0042A5EF] 0f b6 c2                                     movzx   eax, dl
000A981A [0042A5F2] 3b c7                                        cmp     eax, edi
000A981C [0042A5F4] 74 0a                                        jz      short near ptr unk_42A600 ; game-relative-target=0x000A9828
000A981E [0042A5F6] c1 ea 08                                     shr     edx, 8
000A9821 [0042A5F9] 41                                           inc     ecx
000A9822 [0042A5FA] 83 f9 03                                     cmp     ecx, 3
000A9825 [0042A5FD] 7e f0                                        jle     short near ptr unk_42A5EF ; game-relative-target=0x000A9817
000A9827 [0042A5FF] c3                                           retn
000A9828 [0042A600] 55                                           push    ebp
000A9829 [0042A601] 53                                           push    ebx
000A982A [0042A602] 57                                           push    edi
000A982B [0042A603] 56                                           push    esi
000A982C [0042A604] 8b e9                                        mov     ebp, ecx
000A982E [0042A606] 83 ec 48                                     sub     esp, 48h ; 'H'
000A9831 [0042A609] 8b dc                                        mov     ebx, esp
000A9833 [0042A60B] 33 c0                                        xor     eax, eax
000A9835 [0042A60D] 89 43 40                                     mov     [ebx+40h], eax
000A9838 [0042A610] 89 43 44                                     mov     [ebx+44h], eax
000A983B [0042A613] 8d 53 40                                     lea     edx, [ebx+40h]
000A983E [0042A616] 52                                           push    edx
000A983F [0042A617] b8 b0 ed 47 00                               mov     eax, 47EDB0h
000A9844 [0042A61C] ff d0                                        call    eax
000A9846 [0042A61E] 8b c8                                        mov     ecx, eax
000A9848 [0042A620] b8 10 33 43 00                               mov     eax, 433310h
000A984D [0042A625] ff d0                                        call    eax
000A984F [0042A627] 8d 4b 20                                     lea     ecx, [ebx+20h]
000A9852 [0042A62A] b8 d0 03 47 00                               mov     eax, 4703D0h
000A9857 [0042A62F] ff d0                                        call    eax
000A9859 [0042A631] 6a ff                                        push    0FFFFFFFFh
000A985B [0042A633] 8d 53 40                                     lea     edx, [ebx+40h]
000A985E [0042A636] 52                                           push    edx
000A985F [0042A637] 50                                           push    eax
000A9860 [0042A638] 8b ce                                        mov     ecx, esi
000A9862 [0042A63A] b8 40 d4 51 00                               mov     eax, 51D440h
000A9867 [0042A63F] ff d0                                        call    eax
000A9869 [0042A641] 8b 43 24                                     mov     eax, [ebx+24h]
000A986C [0042A644] 85 c0                                        test    eax, eax
000A986E [0042A646] 74 62                                        jz      short near ptr unk_42A6AA ; game-relative-target=0x000A98D2
000A9870 [0042A648] 8b 48 08                                     mov     ecx, [eax+8]
000A9873 [0042A64B] 85 c9                                        test    ecx, ecx
000A9875 [0042A64D] 74 5b                                        jz      short near ptr unk_42A6AA ; game-relative-target=0x000A98D2
000A9877 [0042A64F] 8b f9                                        mov     edi, ecx
000A9879 [0042A651] 8b 11                                        mov     edx, [ecx]
000A987B [0042A653] ff 52 10                                     call    dword ptr [edx+10h]
000A987E [0042A656] 85 c0                                        test    eax, eax
000A9880 [0042A658] 74 50                                        jz      short near ptr unk_42A6AA ; game-relative-target=0x000A98D2
000A9882 [0042A65A] 8b 4e 18                                     mov     ecx, [esi+18h]
000A9885 [0042A65D] 8b 89 8c 00 00 00                            mov     ecx, [ecx+8Ch]
000A988B [0042A663] b8 d0 e3 47 00                               mov     eax, 47E3D0h
000A9890 [0042A668] ff d0                                        call    eax
000A9892 [0042A66A] 8b f0                                        mov     esi, eax
000A9894 [0042A66C] 85 ed                                        test    ebp, ebp
000A9896 [0042A66E] 75 3f                                        jnz     short near ptr unk_42A6AF ; game-relative-target=0x000A98D7
000A9898 [0042A670] 8b cf                                        mov     ecx, edi
000A989A [0042A672] 8b 17                                        mov     edx, [edi]
000A989C [0042A674] ff 52 30                                     call    dword ptr [edx+30h]
000A989F [0042A677] 89 46 38                                     mov     [esi+38h], eax
000A98A2 [0042A67A] 8b cb                                        mov     ecx, ebx
000A98A4 [0042A67C] b8 70 df 46 00                               mov     eax, 46DF70h
000A98A9 [0042A681] ff d0                                        call    eax
000A98AB [0042A683] 6a 00                                        push    0
000A98AD [0042A685] 68 d0 e3 46 00                               push    46E3D0h
000A98B2 [0042A68A] 8b cb                                        mov     ecx, ebx
000A98B4 [0042A68C] b8 00 f3 46 00                               mov     eax, 46F300h
000A98B9 [0042A691] ff d0                                        call    eax
000A98BB [0042A693] 53                                           push    ebx
000A98BC [0042A694] 8d 46 38                                     lea     eax, [esi+38h]
000A98BF [0042A697] 50                                           push    eax
000A98C0 [0042A698] 8b ce                                        mov     ecx, esi
000A98C2 [0042A69A] b8 e0 73 51 00                               mov     eax, 5173E0h
000A98C7 [0042A69F] ff d0                                        call    eax
000A98C9 [0042A6A1] 8b cb                                        mov     ecx, ebx
000A98CB [0042A6A3] b8 90 df 46 00                               mov     eax, 46DF90h
000A98D0 [0042A6A8] ff d0                                        call    eax
000A98D2 [0042A6AA] e9 a3 00 00 00                               jmp     near ptr unk_42A752 ; game-relative-target=0x000A997A
000A98D7 [0042A6AF] 4d                                           dec     ebp
000A98D8 [0042A6B0] 75 28                                        jnz     short near ptr unk_42A6DA ; game-relative-target=0x000A9902
000A98DA [0042A6B2] 0f b6 57 06                                  movzx   edx, byte ptr [edi+6]
000A98DE [0042A6B6] 83 ea 03                                     sub     edx, 3
000A98E1 [0042A6B9] 74 11                                        jz      short near ptr unk_42A6CC ; game-relative-target=0x000A98F4
000A98E3 [0042A6BB] 4a                                           dec     edx
000A98E4 [0042A6BC] 74 07                                        jz      short near ptr unk_42A6C5 ; game-relative-target=0x000A98ED
000A98E6 [0042A6BE] b8 50 6e 51 00                               mov     eax, 516E50h
000A98EB [0042A6C3] eb 0c                                        jmp     short near ptr unk_42A6D1 ; game-relative-target=0x000A98F9
000A98ED [0042A6C5] b8 70 6a 51 00                               mov     eax, 516A70h
000A98F2 [0042A6CA] eb 05                                        jmp     short near ptr unk_42A6D1 ; game-relative-target=0x000A98F9
000A98F4 [0042A6CC] b8 20 67 51 00                               mov     eax, 516720h
000A98F9 [0042A6D1] 89 7e 38                                     mov     [esi+38h], edi
000A98FC [0042A6D4] 8b ce                                        mov     ecx, esi
000A98FE [0042A6D6] ff d0                                        call    eax
000A9900 [0042A6D8] eb 78                                        jmp     short near ptr unk_42A752 ; game-relative-target=0x000A997A
000A9902 [0042A6DA] 4d                                           dec     ebp
000A9903 [0042A6DB] 75 4c                                        jnz     short near ptr unk_42A729 ; game-relative-target=0x000A9951
000A9905 [0042A6DD] 8b cb                                        mov     ecx, ebx
000A9907 [0042A6DF] b8 c0 3c 47 00                               mov     eax, 473CC0h
000A990C [0042A6E4] ff d0                                        call    eax
000A990E [0042A6E6] 80 7f 06 03                                  cmp     byte ptr [edi+6], 3
000A9912 [0042A6EA] 75 1c                                        jnz     short near ptr unk_42A708 ; game-relative-target=0x000A9930
000A9914 [0042A6EC] 6a 00                                        push    0
000A9916 [0042A6EE] 68 70 3d 47 00                               push    473D70h
000A991B [0042A6F3] 8d 53 20                                     lea     edx, [ebx+20h]
000A991E [0042A6F6] 52                                           push    edx
000A991F [0042A6F7] 8b cb                                        mov     ecx, ebx
000A9921 [0042A6F9] b8 c0 f3 46 00                               mov     eax, 46F3C0h
000A9926 [0042A6FE] ff d0                                        call    eax
000A9928 [0042A700] 83 f8 01                                     cmp     eax, 1
000A992B [0042A703] 7f 0f                                        jg      short near ptr unk_42A714 ; game-relative-target=0x000A993C
000A992D [0042A705] 8b 7f 64                                     mov     edi, [edi+64h]
000A9930 [0042A708] 8b cf                                        mov     ecx, edi
000A9932 [0042A70A] 6a 00                                        push    0
000A9934 [0042A70C] 53                                           push    ebx
000A9935 [0042A70D] b8 20 6a 43 00                               mov     eax, 436A20h
000A993A [0042A712] ff d0                                        call    eax
000A993C [0042A714] 53                                           push    ebx
000A993D [0042A715] 8b ce                                        mov     ecx, esi
000A993F [0042A717] b8 b0 49 51 00                               mov     eax, 5149B0h
000A9944 [0042A71C] ff d0                                        call    eax
000A9946 [0042A71E] 8b cb                                        mov     ecx, ebx
000A9948 [0042A720] b8 e0 3c 47 00                               mov     eax, 473CE0h
000A994D [0042A725] ff d0                                        call    eax
000A994F [0042A727] eb 29                                        jmp     short near ptr unk_42A752 ; game-relative-target=0x000A997A
000A9951 [0042A729] 4d                                           dec     ebp
000A9952 [0042A72A] 75 26                                        jnz     short near ptr unk_42A752 ; game-relative-target=0x000A997A
000A9954 [0042A72C] 0f b6 57 06                                  movzx   edx, byte ptr [edi+6]
000A9958 [0042A730] 83 ea 03                                     sub     edx, 3
000A995B [0042A733] 74 11                                        jz      short near ptr unk_42A746 ; game-relative-target=0x000A996E
000A995D [0042A735] 4a                                           dec     edx
000A995E [0042A736] 74 07                                        jz      short near ptr unk_42A73F ; game-relative-target=0x000A9967
000A9960 [0042A738] ba 60 44 51 00                               mov     edx, 514460h
000A9965 [0042A73D] eb 0c                                        jmp     short near ptr unk_42A74B ; game-relative-target=0x000A9973
000A9967 [0042A73F] ba 50 45 51 00                               mov     edx, 514550h
000A996C [0042A744] eb 05                                        jmp     short near ptr unk_42A74B ; game-relative-target=0x000A9973
000A996E [0042A746] ba 20 46 51 00                               mov     edx, 514620h
000A9973 [0042A74B] 8b ce                                        mov     ecx, esi
000A9975 [0042A74D] 89 7e 38                                     mov     [esi+38h], edi
000A9978 [0042A750] ff d2                                        call    edx
000A997A [0042A752] 8d 4b 20                                     lea     ecx, [ebx+20h]
000A997D [0042A755] b8 10 04 47 00                               mov     eax, 470410h
000A9982 [0042A75A] ff d0                                        call    eax
000A9984 [0042A75C] 83 c4 48                                     add     esp, 48h ; 'H'
000A9987 [0042A75F] 5e                                           pop     esi
000A9988 [0042A760] 5f                                           pop     edi
000A9989 [0042A761] 5b                                           pop     ebx
000A998A [0042A762] 5d                                           pop     ebp
000A998B [0042A763] c3                                           retn
