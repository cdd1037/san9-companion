; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425EA0; baseline game VA=0x000A5900; size=189
; Relative branch annotations use the baseline game destination.
000A5900 [00425EA0] 3d 10 27 00 00                               cmp     eax, 2710h
000A5905 [00425EA5] 7e 28                                        jle     short near ptr unk_425ECF ; game-relative-target=0x000A592F
000A5907 [00425EA7] 81 fe 20 4e 00 00                            cmp     esi, 4E20h
000A590D [00425EAD] 7c 20                                        jl      short near ptr unk_425ECF ; game-relative-target=0x000A592F
000A590F [00425EAF] 8b cf                                        mov     ecx, edi
000A5911 [00425EB1] b8 d0 53 43 00                               mov     eax, 4353D0h
000A5916 [00425EB6] ff d0                                        call    eax
000A5918 [00425EB8] 8d af dc 00 00 00                            lea     ebp, [edi+0DCh]
000A591E [00425EBE] 8b 55 0c                                     mov     edx, [ebp+0Ch]
000A5921 [00425EC1] 3c 02                                        cmp     al, 2
000A5923 [00425EC3] 7f 05                                        jg      short near ptr unk_425ECA ; game-relative-target=0x000A592A
000A5925 [00425EC5] 3c 01                                        cmp     al, 1
000A5927 [00425EC7] 74 01                                        jz      short near ptr unk_425ECA ; game-relative-target=0x000A592A
000A5929 [00425EC9] 4a                                           dec     edx
000A592A [00425ECA] 83 fa 01                                     cmp     edx, 1
000A592D [00425ECD] 7f 06                                        jg      short near ptr unk_425ED5 ; game-relative-target=0x000A5935
000A592F [00425ECF] ff 25 08 f3 5f 00                            jmp     dword ptr ds:5FF308h
000A5935 [00425ED5] 57                                           push    edi
000A5936 [00425ED6] 52                                           push    edx
000A5937 [00425ED7] 8b c6                                        mov     eax, esi
000A5939 [00425ED9] b9 98 3a 00 00                               mov     ecx, 3A98h
000A593E [00425EDE] 99                                           cdq
000A593F [00425EDF] f7 f1                                        div     ecx
000A5941 [00425EE1] 81 fa 10 27 00 00                            cmp     edx, 2710h
000A5947 [00425EE7] 7c 01                                        jl      short near ptr unk_425EEA ; game-relative-target=0x000A594A
000A5949 [00425EE9] 40                                           inc     eax
000A594A [00425EEA] 59                                           pop     ecx
000A594B [00425EEB] 3b c8                                        cmp     ecx, eax
000A594D [00425EED] 7e 02                                        jle     short near ptr unk_425EF1 ; game-relative-target=0x000A5951
000A594F [00425EEF] 8b c8                                        mov     ecx, eax
000A5951 [00425EF1] 8b c6                                        mov     eax, esi
000A5953 [00425EF3] 99                                           cdq
000A5954 [00425EF4] f7 f1                                        div     ecx
000A5956 [00425EF6] 8b d8                                        mov     ebx, eax
000A5958 [00425EF8] 8b f1                                        mov     esi, ecx
000A595A [00425EFA] 49                                           dec     ecx
000A595B [00425EFB] 51                                           push    ecx
000A595C [00425EFC] 8b cd                                        mov     ecx, ebp
000A595E [00425EFE] b8 80 e8 46 00                               mov     eax, 46E880h
000A5963 [00425F03] ff d0                                        call    eax
000A5965 [00425F05] 8b e8                                        mov     ebp, eax
000A5967 [00425F07] 8b 7c 24 08                                  mov     edi, [esp+8]
000A596B [00425F0B] 83 fe 01                                     cmp     esi, 1
000A596E [00425F0E] 7f 11                                        jg      short near ptr unk_425F21 ; game-relative-target=0x000A5981
000A5970 [00425F10] 3b 7c 24 0c                                  cmp     edi, [esp+0Ch]
000A5974 [00425F14] 7d 04                                        jge     short near ptr unk_425F1A ; game-relative-target=0x000A597A
000A5976 [00425F16] 89 7c 24 0c                                  mov     [esp+0Ch], edi
000A597A [00425F1A] 5f                                           pop     edi
000A597B [00425F1B] ff 25 08 f3 5f 00                            jmp     dword ptr ds:5FF308h
000A5981 [00425F21] 3b 5c 24 0c                                  cmp     ebx, [esp+0Ch]
000A5985 [00425F25] 7d f3                                        jge     short near ptr unk_425F1A ; game-relative-target=0x000A597A
000A5987 [00425F27] 8b 4d 08                                     mov     ecx, [ebp+8]
000A598A [00425F2A] b8 00 d7 44 00                               mov     eax, 44D700h
000A598F [00425F2F] ff d0                                        call    eax
000A5991 [00425F31] 3b c3                                        cmp     eax, ebx
000A5993 [00425F33] 7c 06                                        jl      short near ptr unk_425F3B ; game-relative-target=0x000A599B
000A5995 [00425F35] 89 5c 24 0c                                  mov     [esp+0Ch], ebx
000A5999 [00425F39] eb df                                        jmp     short near ptr unk_425F1A ; game-relative-target=0x000A597A
000A599B [00425F3B] 2b f8                                        sub     edi, eax
000A599D [00425F3D] 4e                                           dec     esi
000A599E [00425F3E] 83 fe 01                                     cmp     esi, 1
000A59A1 [00425F41] 74 cd                                        jz      short near ptr unk_425F10 ; game-relative-target=0x000A5970
000A59A3 [00425F43] 8b 6d 04                                     mov     ebp, [ebp+4]
000A59A6 [00425F46] 8b 4d 08                                     mov     ecx, [ebp+8]
000A59A9 [00425F49] b8 00 d7 44 00                               mov     eax, 44D700h
000A59AE [00425F4E] ff d0                                        call    eax
000A59B0 [00425F50] 3b c3                                        cmp     eax, ebx
000A59B2 [00425F52] 7e e7                                        jle     short near ptr unk_425F3B ; game-relative-target=0x000A599B
000A59B4 [00425F54] 8b c7                                        mov     eax, edi
000A59B6 [00425F56] 99                                           cdq
000A59B7 [00425F57] f7 f6                                        div     esi
000A59B9 [00425F59] 8b d8                                        mov     ebx, eax
000A59BB [00425F5B] eb c4                                        jmp     short near ptr unk_425F21 ; game-relative-target=0x000A5981
