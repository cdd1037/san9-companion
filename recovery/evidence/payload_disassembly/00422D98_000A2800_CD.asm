; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422D98; baseline game VA=0x000A2800; size=205
; Relative branch annotations use the baseline game destination.
000A2800 [00422D98] 8b 46 38                                     mov     eax, [esi+38h]
000A2803 [00422D9B] 83 78 24 02                                  cmp     dword ptr [eax+24h], 2
000A2807 [00422D9F] 7c 06                                        jl      short near ptr unk_422DA7 ; game-relative-target=0x000A280F
000A2809 [00422DA1] 68 60 5e 4b 00                               push    4B5E60h
000A280E [00422DA6] c3                                           retn
000A280F [00422DA7] 8b 80 b8 00 00 00                            mov     eax, [eax+0B8h]
000A2815 [00422DAD] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A2819 [00422DB1] 74 05                                        jz      short near ptr unk_422DB8 ; game-relative-target=0x000A2820
000A281B [00422DB3] 33 c0                                        xor     eax, eax
000A281D [00422DB5] c2 04 00                                     retn    4
000A2820 [00422DB8] 8b 4c 24 04                                  mov     ecx, [esp+4]
000A2824 [00422DBC] 53                                           push    ebx
000A2825 [00422DBD] 57                                           push    edi
000A2826 [00422DBE] 8b 59 04                                     mov     ebx, [ecx+4]
000A2829 [00422DC1] 8b 7b 08                                     mov     edi, [ebx+8]
000A282C [00422DC4] 8b 97 cc 00 00 00                            mov     edx, [edi+0CCh]
000A2832 [00422DCA] 85 d2                                        test    edx, edx
000A2834 [00422DCC] 74 7f                                        jz      short near ptr unk_422E4D ; game-relative-target=0x000A28B5
000A2836 [00422DCE] f6 42 34 01                                  test    byte ptr [edx+34h], 1
000A283A [00422DD2] 74 79                                        jz      short near ptr unk_422E4D ; game-relative-target=0x000A28B5
000A283C [00422DD4] 52                                           push    edx
000A283D [00422DD5] ff 76 38                                     push    dword ptr [esi+38h]
000A2840 [00422DD8] b8 70 06 4b 00                               mov     eax, 4B0670h
000A2845 [00422DDD] ff d0                                        call    eax
000A2847 [00422DDF] 83 c4 08                                     add     esp, 8
000A284A [00422DE2] 85 c0                                        test    eax, eax
000A284C [00422DE4] 74 67                                        jz      short near ptr unk_422E4D ; game-relative-target=0x000A28B5
000A284E [00422DE6] 0f b6 47 04                                  movzx   eax, byte ptr [edi+4]
000A2852 [00422DEA] 80 b8 00 0d 0a 00 09                         cmp     byte ptr [eax+0A0D00h], 9
000A2859 [00422DF1] 7d 64                                        jge     short near ptr unk_422E57 ; game-relative-target=0x000A28BF
000A285B [00422DF3] 83 ec 20                                     sub     esp, 20h ; ' '
000A285E [00422DF6] 8b cc                                        mov     ecx, esp
000A2860 [00422DF8] b8 70 c9 46 00                               mov     eax, 46C970h
000A2865 [00422DFD] ff d0                                        call    eax
000A2867 [00422DFF] 57                                           push    edi
000A2868 [00422E00] 50                                           push    eax
000A2869 [00422E01] b8 40 5c 47 00                               mov     eax, 475C40h
000A286E [00422E06] ff d0                                        call    eax
000A2870 [00422E08] 8b 4c 24 04                                  mov     ecx, [esp+4]
000A2874 [00422E0C] 85 c9                                        test    ecx, ecx
000A2876 [00422E0E] 74 2b                                        jz      short near ptr unk_422E3B ; game-relative-target=0x000A28A3
000A2878 [00422E10] 8b 51 08                                     mov     edx, [ecx+8]
000A287B [00422E13] 8b 82 cc 00 00 00                            mov     eax, [edx+0CCh]
000A2881 [00422E19] 3b 87 cc 00 00 00                            cmp     eax, [edi+0CCh]
000A2887 [00422E1F] 75 16                                        jnz     short near ptr unk_422E37 ; game-relative-target=0x000A289F
000A2889 [00422E21] 0f b6 42 04                                  movzx   eax, byte ptr [edx+4]
000A288D [00422E25] 80 7a 06 05                                  cmp     byte ptr [edx+6], 5
000A2891 [00422E29] 74 0c                                        jz      short near ptr unk_422E37 ; game-relative-target=0x000A289F
000A2893 [00422E2B] 83 c0 32                                     add     eax, 32h ; '2'
000A2896 [00422E2E] 80 b8 00 0d 0a 00 09                         cmp     byte ptr [eax+0A0D00h], 9
000A289D [00422E35] 7d 04                                        jge     short near ptr unk_422E3B ; game-relative-target=0x000A28A3
000A289F [00422E37] 8b 09                                        mov     ecx, [ecx]
000A28A1 [00422E39] eb d1                                        jmp     short near ptr unk_422E0C ; game-relative-target=0x000A2874
000A28A3 [00422E3B] 8b f9                                        mov     edi, ecx
000A28A5 [00422E3D] 8b cc                                        mov     ecx, esp
000A28A7 [00422E3F] b8 e0 80 51 00                               mov     eax, 5180E0h
000A28AC [00422E44] ff d0                                        call    eax
000A28AE [00422E46] 83 c4 20                                     add     esp, 20h ; ' '
000A28B1 [00422E49] 85 ff                                        test    edi, edi
000A28B3 [00422E4B] 75 0a                                        jnz     short near ptr unk_422E57 ; game-relative-target=0x000A28BF
000A28B5 [00422E4D] 8b 1b                                        mov     ebx, [ebx]
000A28B7 [00422E4F] 85 db                                        test    ebx, ebx
000A28B9 [00422E51] 0f 85 6a ff ff ff                            jnz     near ptr unk_422DC1 ; game-relative-target=0x000A2829
000A28BF [00422E57] 33 c0                                        xor     eax, eax
000A28C1 [00422E59] 85 db                                        test    ebx, ebx
000A28C3 [00422E5B] 74 03                                        jz      short near ptr unk_422E60 ; game-relative-target=0x000A28C8
000A28C5 [00422E5D] 8b 43 08                                     mov     eax, [ebx+8]
000A28C8 [00422E60] 5f                                           pop     edi
000A28C9 [00422E61] 5b                                           pop     ebx
000A28CA [00422E62] c2 04 00                                     retn    4
