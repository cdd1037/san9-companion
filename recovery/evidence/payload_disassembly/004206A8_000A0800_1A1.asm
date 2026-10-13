; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004206A8; baseline game VA=0x000A0800; size=417
; Relative branch annotations use the baseline game destination.
000A0800 [004206A8] 8b cb                                        mov     ecx, ebx
000A0802 [004206AA] 8b 01                                        mov     eax, [ecx]
000A0804 [004206AC] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A0807 [004206AF] b9 8b f8 43 00                               mov     ecx, 43F88Bh
000A080C [004206B4] 66 3b 01                                     cmp     ax, [ecx]
000A080F [004206B7] 74 19                                        jz      short near ptr unk_4206D2 ; game-relative-target=0x000A082A
000A0811 [004206B9] 66 89 01                                     mov     [ecx], ax
000A0814 [004206BC] 8b cb                                        mov     ecx, ebx
000A0816 [004206BE] 8d 44 24 54                                  lea     eax, [esp+54h]
000A081A [004206C2] 50                                           push    eax
000A081B [004206C3] b8 00 60 0a 00                               mov     eax, 0A6000h
000A0820 [004206C8] ff d0                                        call    eax
000A0822 [004206CA] 66 a3 8d f8 43 00                            mov     ds:43F88Dh, ax
000A0828 [004206D0] eb 04                                        jmp     short near ptr unk_4206D6 ; game-relative-target=0x000A082E
000A082A [004206D2] 0f b7 41 02                                  movzx   eax, word ptr [ecx+2]
000A082E [004206D6] 2b 83 88 00 00 00                            sub     eax, [ebx+88h]
000A0834 [004206DC] f7 d8                                        neg     eax
000A0836 [004206DE] 3d 70 17 00 00                               cmp     eax, 1770h
000A083B [004206E3] 7d 08                                        jge     short near ptr unk_4206ED ; game-relative-target=0x000A0845
000A083D [004206E5] 68 d8 3d 4a 00                               push    4A3DD8h
000A0842 [004206EA] c2 04 00                                     retn    4
000A0845 [004206ED] 56                                           push    esi
000A0846 [004206EE] 57                                           push    edi
000A0847 [004206EF] 53                                           push    ebx
000A0848 [004206F0] 55                                           push    ebp
000A0849 [004206F1] 3d 80 3e 00 00                               cmp     eax, 3E80h
000A084E [004206F6] 7d 3a                                        jge     short near ptr unk_420732 ; game-relative-target=0x000A088A
000A0850 [004206F8] 8b f8                                        mov     edi, eax
000A0852 [004206FA] 3d e0 2e 00 00                               cmp     eax, 2EE0h
000A0857 [004206FF] 7c 1d                                        jl      short near ptr unk_42071E ; game-relative-target=0x000A0876
000A0859 [00420701] 83 7c 24 50 01                               cmp     dword ptr [esp+50h], 1
000A085E [00420706] 74 09                                        jz      short near ptr unk_420711 ; game-relative-target=0x000A0869
000A0860 [00420708] d1 ef                                        shr     edi, 1
000A0862 [0042070A] be 02 00 00 00                               mov     esi, 2
000A0867 [0042070F] eb 4e                                        jmp     short near ptr unk_42075F ; game-relative-target=0x000A08B7
000A0869 [00420711] 3d c8 32 00 00                               cmp     eax, 32C8h
000A086E [00420716] 7c 06                                        jl      short near ptr unk_42071E ; game-relative-target=0x000A0876
000A0870 [00420718] 81 ef e8 03 00 00                            sub     edi, 3E8h
000A0876 [0042071E] 3d 10 27 00 00                               cmp     eax, 2710h
000A087B [00420723] 7c 06                                        jl      short near ptr unk_42072B ; game-relative-target=0x000A0883
000A087D [00420725] 81 ef e8 03 00 00                            sub     edi, 3E8h
000A0883 [0042072B] be 01 00 00 00                               mov     esi, 1
000A0888 [00420730] eb 2d                                        jmp     short near ptr unk_42075F ; game-relative-target=0x000A08B7
000A088A [00420732] 8b f0                                        mov     esi, eax
000A088C [00420734] 8b 7c 24 50                                  mov     edi, [esp+50h]
000A0890 [00420738] b9 40 1f 00 00                               mov     ecx, 1F40h
000A0895 [0042073D] 8b c6                                        mov     eax, esi
000A0897 [0042073F] 99                                           cdq
000A0898 [00420740] f7 f1                                        div     ecx
000A089A [00420742] 3b f8                                        cmp     edi, eax
000A089C [00420744] 7d 0e                                        jge     short near ptr unk_420754 ; game-relative-target=0x000A08AC
000A089E [00420746] 81 c1 d0 07 00 00                            add     ecx, 7D0h
000A08A4 [0042074C] 81 f9 20 4e 00 00                            cmp     ecx, 4E20h
000A08AA [00420752] 7e e9                                        jle     short near ptr unk_42073D ; game-relative-target=0x000A0895
000A08AC [00420754] 8b c8                                        mov     ecx, eax
000A08AE [00420756] 8b c6                                        mov     eax, esi
000A08B0 [00420758] 8b f1                                        mov     esi, ecx
000A08B2 [0042075A] 99                                           cdq
000A08B3 [0042075B] f7 f1                                        div     ecx
000A08B5 [0042075D] 8b f8                                        mov     edi, eax
000A08B7 [0042075F] 89 35 04 fc 43 00                            mov     ds:43FC04h, esi
000A08BD [00420765] 57                                           push    edi
000A08BE [00420766] 8b 44 24 54                                  mov     eax, [esp+54h]
000A08C2 [0042076A] 99                                           cdq
000A08C3 [0042076B] f7 f6                                        div     esi
000A08C5 [0042076D] 52                                           push    edx
000A08C6 [0042076E] 83 f8 04                                     cmp     eax, 4
000A08C9 [00420771] 7e 07                                        jle     short near ptr unk_42077A ; game-relative-target=0x000A08D2
000A08CB [00420773] b8 04 00 00 00                               mov     eax, 4
000A08D0 [00420778] eb 09                                        jmp     short near ptr unk_420783 ; game-relative-target=0x000A08DB
000A08D2 [0042077A] 85 c0                                        test    eax, eax
000A08D4 [0042077C] 75 05                                        jnz     short near ptr unk_420783 ; game-relative-target=0x000A08DB
000A08D6 [0042077E] b0 01                                        mov     al, 1
000A08D8 [00420780] 5a                                           pop     edx
000A08D9 [00420781] 6a 00                                        push    0
000A08DB [00420783] 48                                           dec     eax
000A08DC [00420784] 75 06                                        jnz     short near ptr unk_42078C ; game-relative-target=0x000A08E4
000A08DE [00420786] 68 78 1a 0a 00                               push    0A1A78h
000A08E3 [0042078B] c3                                           retn
000A08E4 [0042078C] 50                                           push    eax
000A08E5 [0042078D] 33 ff                                        xor     edi, edi
000A08E7 [0042078F] 8b 5c 24 54                                  mov     ebx, [esp+54h]
000A08EB [00420793] 8b 4b 08                                     mov     ecx, [ebx+8]
000A08EE [00420796] b8 90 64 0a 00                               mov     eax, 0A6490h
000A08F3 [0042079B] ff d0                                        call    eax
000A08F5 [0042079D] 85 c0                                        test    eax, eax
000A08F7 [0042079F] 74 01                                        jz      short near ptr unk_4207A2 ; game-relative-target=0x000A08FA
000A08F9 [004207A1] 47                                           inc     edi
000A08FA [004207A2] 8b 1b                                        mov     ebx, [ebx]
000A08FC [004207A4] 85 db                                        test    ebx, ebx
000A08FE [004207A6] 75 eb                                        jnz     short near ptr unk_420793 ; game-relative-target=0x000A08EB
000A0900 [004207A8] 8b cd                                        mov     ecx, ebp
000A0902 [004207AA] b8 90 64 0a 00                               mov     eax, 0A6490h
000A0907 [004207AF] ff d0                                        call    eax
000A0909 [004207B1] 85 c0                                        test    eax, eax
000A090B [004207B3] 74 01                                        jz      short near ptr unk_4207B6 ; game-relative-target=0x000A090E
000A090D [004207B5] 47                                           inc     edi
000A090E [004207B6] 8b d8                                        mov     ebx, eax
000A0910 [004207B8] 8b c7                                        mov     eax, edi
000A0912 [004207BA] 99                                           cdq
000A0913 [004207BB] f7 f6                                        div     esi
000A0915 [004207BD] 8b 7c 24 10                                  mov     edi, [esp+10h]
000A0919 [004207C1] 3b 7f 44                                     cmp     edi, [edi+44h]
000A091C [004207C4] 75 13                                        jnz     short near ptr unk_4207D9 ; game-relative-target=0x000A0931
000A091E [004207C6] f6 47 51 ff                                  test    byte ptr [edi+51h], 0FFh
000A0922 [004207CA] 75 0d                                        jnz     short near ptr unk_4207D9 ; game-relative-target=0x000A0931
000A0924 [004207CC] 3c 01                                        cmp     al, 1
000A0926 [004207CE] 74 14                                        jz      short near ptr unk_4207E4 ; game-relative-target=0x000A093C
000A0928 [004207D0] 3c 02                                        cmp     al, 2
000A092A [004207D2] 75 05                                        jnz     short near ptr unk_4207D9 ; game-relative-target=0x000A0931
000A092C [004207D4] 85 d2                                        test    edx, edx
000A092E [004207D6] 75 0c                                        jnz     short near ptr unk_4207E4 ; game-relative-target=0x000A093C
000A0930 [004207D8] 48                                           dec     eax
000A0931 [004207D9] 85 d2                                        test    edx, edx
000A0933 [004207DB] 74 01                                        jz      short near ptr unk_4207DE ; game-relative-target=0x000A0936
000A0935 [004207DD] 40                                           inc     eax
000A0936 [004207DE] 3c 02                                        cmp     al, 2
000A0938 [004207E0] 7e 02                                        jle     short near ptr unk_4207E4 ; game-relative-target=0x000A093C
000A093A [004207E2] b0 02                                        mov     al, 2
000A093C [004207E4] 85 db                                        test    ebx, ebx
000A093E [004207E6] 74 01                                        jz      short near ptr unk_4207E9 ; game-relative-target=0x000A0941
000A0940 [004207E8] 48                                           dec     eax
000A0941 [004207E9] 5e                                           pop     esi
000A0942 [004207EA] 3b c6                                        cmp     eax, esi
000A0944 [004207EC] 7e 02                                        jle     short near ptr unk_4207F0 ; game-relative-target=0x000A0948
000A0946 [004207EE] 8b c6                                        mov     eax, esi
000A0948 [004207F0] 8b d8                                        mov     ebx, eax
000A094A [004207F2] 2b f3                                        sub     esi, ebx
000A094C [004207F4] b8 a8 09 0a 00                               mov     eax, 0A09A8h
000A0951 [004207F9] ff d0                                        call    eax
000A0953 [004207FB] 8b 7c 24 50                                  mov     edi, [esp+50h]
000A0957 [004207FF] 8b 4f 08                                     mov     ecx, [edi+8]
000A095A [00420802] b8 90 64 0a 00                               mov     eax, 0A6490h
000A095F [00420807] ff d0                                        call    eax
000A0961 [00420809] 85 c0                                        test    eax, eax
000A0963 [0042080B] 74 26                                        jz      short near ptr unk_420833 ; game-relative-target=0x000A098B
000A0965 [0042080D] 85 db                                        test    ebx, ebx
000A0967 [0042080F] 74 12                                        jz      short near ptr unk_420823 ; game-relative-target=0x000A097B
000A0969 [00420811] 4b                                           dec     ebx
000A096A [00420812] 8d 8c 24 10 01 00 00                         lea     ecx, [esp+110h]
000A0971 [00420819] ff 77 08                                     push    dword ptr [edi+8]
000A0974 [0042081C] b8 70 ef 46 00                               mov     eax, 46EF70h
000A0979 [00420821] ff d0                                        call    eax
000A097B [00420823] 8d 4c 24 4c                                  lea     ecx, [esp+4Ch]
000A097F [00420827] 57                                           push    edi
000A0980 [00420828] 8b 3f                                        mov     edi, [edi]
000A0982 [0042082A] b8 10 64 41 00                               mov     eax, 416410h
000A0987 [0042082F] ff d0                                        call    eax
000A0989 [00420831] eb 02                                        jmp     short near ptr unk_420835 ; game-relative-target=0x000A098D
000A098B [00420833] 8b 3f                                        mov     edi, [edi]
000A098D [00420835] 85 ff                                        test    edi, edi
000A098F [00420837] 75 c6                                        jnz     short near ptr unk_4207FF ; game-relative-target=0x000A0957
000A0991 [00420839] 85 f6                                        test    esi, esi
000A0993 [0042083B] 75 06                                        jnz     short near ptr unk_420843 ; game-relative-target=0x000A099B
000A0995 [0042083D] 68 78 1a 0a 00                               push    0A1A78h
000A099A [00420842] c3                                           retn
000A099B [00420843] 68 00 1a 0a 00                               push    0A1A00h
000A09A0 [00420848] c3                                           retn
