; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424DF0; baseline game VA=0x000A5000; size=854
; Relative branch annotations use the baseline game destination.
000A5000 [00424DF0] 56                                           push    esi
000A5001 [00424DF1] b8 00 71 47 00                               mov     eax, 477100h
000A5006 [00424DF6] ff d0                                        call    eax
000A5008 [00424DF8] 8b f8                                        mov     edi, eax
000A500A [00424DFA] 80 4f 0f 80                                  or      byte ptr [edi+0Fh], 80h
000A500E [00424DFE] 57                                           push    edi
000A500F [00424DFF] 8b 8f cc 00 00 00                            mov     ecx, [edi+0CCh]
000A5015 [00424E05] b8 50 36 0a 00                               mov     eax, 0A3650h
000A501A [00424E0A] ff d0                                        call    eax
000A501C [00424E0C] a8 12                                        test    al, 12h
000A501E [00424E0E] 75 20                                        jnz     short near ptr unk_424E30 ; game-relative-target=0x000A5040
000A5020 [00424E10] 33 ed                                        xor     ebp, ebp
000A5022 [00424E12] 45                                           inc     ebp
000A5023 [00424E13] 80 7f 06 05                                  cmp     byte ptr [edi+6], 5
000A5027 [00424E17] 75 12                                        jnz     short near ptr unk_424E2B ; game-relative-target=0x000A503B
000A5029 [00424E19] bd 10 27 00 00                               mov     ebp, 2710h
000A502E [00424E1E] 8b cf                                        mov     ecx, edi
000A5030 [00424E20] 8b 01                                        mov     eax, [ecx]
000A5032 [00424E22] ff 50 3c                                     call    dword ptr [eax+3Ch]
000A5035 [00424E25] 85 c0                                        test    eax, eax
000A5037 [00424E27] 74 02                                        jz      short near ptr unk_424E2B ; game-relative-target=0x000A503B
000A5039 [00424E29] d1 ed                                        shr     ebp, 1
000A503B [00424E2B] e9 90 02 00 00                               jmp     near ptr unk_4250C0 ; game-relative-target=0x000A52D0
000A5040 [00424E30] 80 4f 0f 40                                  or      byte ptr [edi+0Fh], 40h ; '@'
000A5044 [00424E34] 8b 6f 44                                     mov     ebp, [edi+44h]
000A5047 [00424E37] 83 ec 40                                     sub     esp, 40h ; '@'
000A504A [00424E3A] 8b cc                                        mov     ecx, esp
000A504C [00424E3C] b8 70 d7 46 00                               mov     eax, 46D770h
000A5051 [00424E41] ff d0                                        call    eax
000A5053 [00424E43] 6a 00                                        push    0
000A5055 [00424E45] 6a 00                                        push    0
000A5057 [00424E47] 50                                           push    eax
000A5058 [00424E48] 8b cd                                        mov     ecx, ebp
000A505A [00424E4A] b8 60 b0 43 00                               mov     eax, 43B060h
000A505F [00424E4F] ff d0                                        call    eax
000A5061 [00424E51] 8b cc                                        mov     ecx, esp
000A5063 [00424E53] 55                                           push    ebp
000A5064 [00424E54] b8 20 ef 46 00                               mov     eax, 46EF20h
000A5069 [00424E59] ff d0                                        call    eax
000A506B [00424E5B] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A506F [00424E5F] b8 70 c9 46 00                               mov     eax, 46C970h
000A5074 [00424E64] ff d0                                        call    eax
000A5076 [00424E66] 8b 6c 24 04                                  mov     ebp, [esp+4]
000A507A [00424E6A] 56                                           push    esi
000A507B [00424E6B] 33 f6                                        xor     esi, esi
000A507D [00424E6D] 8b 45 08                                     mov     eax, [ebp+8]
000A5080 [00424E70] ff b0 cc 00 00 00                            push    dword ptr [eax+0CCh]
000A5086 [00424E76] 8b 8f cc 00 00 00                            mov     ecx, [edi+0CCh]
000A508C [00424E7C] b8 10 18 44 00                               mov     eax, 441810h
000A5091 [00424E81] ff d0                                        call    eax
000A5093 [00424E83] 03 f0                                        add     esi, eax
000A5095 [00424E85] 8d 44 24 24                                  lea     eax, [esp+24h]
000A5099 [00424E89] 6a 01                                        push    1
000A509B [00424E8B] 6a 00                                        push    0
000A509D [00424E8D] 50                                           push    eax
000A509E [00424E8E] 8b 4d 08                                     mov     ecx, [ebp+8]
000A50A1 [00424E91] b8 20 a8 43 00                               mov     eax, 43A820h
000A50A6 [00424E96] ff d0                                        call    eax
000A50A8 [00424E98] 8b 6d 00                                     mov     ebp, [ebp+0]
000A50AB [00424E9B] 85 ed                                        test    ebp, ebp
000A50AD [00424E9D] 75 ce                                        jnz     short near ptr unk_424E6D ; game-relative-target=0x000A507D
000A50AF [00424E9F] 45                                           inc     ebp
000A50B0 [00424EA0] 85 f6                                        test    esi, esi
000A50B2 [00424EA2] 5e                                           pop     esi
000A50B3 [00424EA3] 0f 84 cd 01 00 00                            jz      near ptr unk_425076 ; game-relative-target=0x000A5286
000A50B9 [00424EA9] 66 bd 88 13                                  mov     bp, 1388h
000A50BD [00424EAD] 8b cf                                        mov     ecx, edi
000A50BF [00424EAF] b8 d0 53 43 00                               mov     eax, 4353D0h
000A50C4 [00424EB4] ff d0                                        call    eax
000A50C6 [00424EB6] 3c 02                                        cmp     al, 2
000A50C8 [00424EB8] 7f 06                                        jg      short near ptr unk_424EC0 ; game-relative-target=0x000A50D0
000A50CA [00424EBA] 3c 01                                        cmp     al, 1
000A50CC [00424EBC] 74 02                                        jz      short near ptr unk_424EC0 ; game-relative-target=0x000A50D0
000A50CE [00424EBE] d1 e5                                        shl     ebp, 1
000A50D0 [00424EC0] 56                                           push    esi
000A50D1 [00424EC1] 8b 74 24 28                                  mov     esi, [esp+28h]
000A50D5 [00424EC5] 83 ec 60                                     sub     esp, 60h ; '`'
000A50D8 [00424EC8] 8b cc                                        mov     ecx, esp
000A50DA [00424ECA] b8 b0 34 47 00                               mov     eax, 4734B0h
000A50DF [00424ECF] ff d0                                        call    eax
000A50E1 [00424ED1] 8b 4e 08                                     mov     ecx, [esi+8]
000A50E4 [00424ED4] 3b cf                                        cmp     ecx, edi
000A50E6 [00424ED6] 74 46                                        jz      short near ptr unk_424F1E ; game-relative-target=0x000A512E
000A50E8 [00424ED8] 8b 81 cc 00 00 00                            mov     eax, [ecx+0CCh]
000A50EE [00424EDE] 50                                           push    eax
000A50EF [00424EDF] 8b 8f cc 00 00 00                            mov     ecx, [edi+0CCh]
000A50F5 [00424EE5] b8 00 4f 0a 00                               mov     eax, 0A4F00h
000A50FA [00424EEA] ff d0                                        call    eax
000A50FC [00424EEC] 85 c0                                        test    eax, eax
000A50FE [00424EEE] 74 2e                                        jz      short near ptr unk_424F1E ; game-relative-target=0x000A512E
000A5100 [00424EF0] 3c 02                                        cmp     al, 2
000A5102 [00424EF2] 75 17                                        jnz     short near ptr unk_424F0B ; game-relative-target=0x000A511B
000A5104 [00424EF4] f6 47 0f 30                                  test    byte ptr [edi+0Fh], 30h ; '0'
000A5108 [00424EF8] 75 24                                        jnz     short near ptr unk_424F1E ; game-relative-target=0x000A512E
000A510A [00424EFA] 8b 4e 08                                     mov     ecx, [esi+8]
000A510D [00424EFD] 81 b9 88 00 00 00 88 13 00 00                cmp     dword ptr [ecx+88h], 1388h
000A5117 [00424F07] 7d 1a                                        jge     short near ptr unk_424F23 ; game-relative-target=0x000A5133
000A5119 [00424F09] eb 13                                        jmp     short near ptr unk_424F1E ; game-relative-target=0x000A512E
000A511B [00424F0B] 3c 04                                        cmp     al, 4
000A511D [00424F0D] 75 14                                        jnz     short near ptr unk_424F23 ; game-relative-target=0x000A5133
000A511F [00424F0F] 8b 4e 08                                     mov     ecx, [esi+8]
000A5122 [00424F12] 80 79 06 05                                  cmp     byte ptr [ecx+6], 5
000A5126 [00424F16] 75 06                                        jnz     short near ptr unk_424F1E ; game-relative-target=0x000A512E
000A5128 [00424F18] f6 47 0f 36                                  test    byte ptr [edi+0Fh], 36h ; '6'
000A512C [00424F1C] 74 05                                        jz      short near ptr unk_424F23 ; game-relative-target=0x000A5133
000A512E [00424F1E] e9 3c 01 00 00                               jmp     near ptr unk_42505F ; game-relative-target=0x000A526F
000A5133 [00424F23] 50                                           push    eax
000A5134 [00424F24] 55                                           push    ebp
000A5135 [00424F25] 53                                           push    ebx
000A5136 [00424F26] 6a 00                                        push    0
000A5138 [00424F28] 8d 58 00                                     lea     ebx, [eax+0]
000A513B [00424F2B] 8d 4c 24 30                                  lea     ecx, [esp+30h]
000A513F [00424F2F] 8b 46 08                                     mov     eax, [esi+8]
000A5142 [00424F32] ff b0 d0 00 00 00                            push    dword ptr [eax+0D0h]
000A5148 [00424F38] 57                                           push    edi
000A5149 [00424F39] b8 30 a3 47 00                               mov     eax, 47A330h
000A514E [00424F3E] ff d0                                        call    eax
000A5150 [00424F40] 8d 4c 24 30                                  lea     ecx, [esp+30h]
000A5154 [00424F44] 8d 44 24 10                                  lea     eax, [esp+10h]
000A5158 [00424F48] 50                                           push    eax
000A5159 [00424F49] b8 90 82 47 00                               mov     eax, 478290h
000A515E [00424F4E] ff d0                                        call    eax
000A5160 [00424F50] 8b 6c 24 14                                  mov     ebp, [esp+14h]
000A5164 [00424F54] 8b 4d 08                                     mov     ecx, [ebp+8]
000A5167 [00424F57] b8 70 d0 45 00                               mov     eax, 45D070h
000A516C [00424F5C] ff d0                                        call    eax
000A516E [00424F5E] 85 c0                                        test    eax, eax
000A5170 [00424F60] 74 0a                                        jz      short near ptr unk_424F6C ; game-relative-target=0x000A517C
000A5172 [00424F62] 3b 04 24                                     cmp     eax, [esp]
000A5175 [00424F65] 74 05                                        jz      short near ptr unk_424F6C ; game-relative-target=0x000A517C
000A5177 [00424F67] 89 04 24                                     mov     [esp], eax
000A517A [00424F6A] 3b c7                                        cmp     eax, edi
000A517C [00424F6C] 74 7e                                        jz      short near ptr unk_424FEC ; game-relative-target=0x000A51FC
000A517E [00424F6E] 3b 46 08                                     cmp     eax, [esi+8]
000A5181 [00424F71] 74 32                                        jz      short near ptr unk_424FA5 ; game-relative-target=0x000A51B5
000A5183 [00424F73] f6 40 3d 80                                  test    byte ptr [eax+3Dh], 80h
000A5187 [00424F77] 75 73                                        jnz     short near ptr unk_424FEC ; game-relative-target=0x000A51FC
000A5189 [00424F79] 8b c8                                        mov     ecx, eax
000A518B [00424F7B] b8 40 54 43 00                               mov     eax, 435440h
000A5190 [00424F80] ff d0                                        call    eax
000A5192 [00424F82] 85 c0                                        test    eax, eax
000A5194 [00424F84] 74 03                                        jz      short near ptr unk_424F89 ; game-relative-target=0x000A5199
000A5196 [00424F86] 4b                                           dec     ebx
000A5197 [00424F87] eb 5f                                        jmp     short near ptr unk_424FE8 ; game-relative-target=0x000A51F8
000A5199 [00424F89] 8b 0c 24                                     mov     ecx, [esp]
000A519C [00424F8C] ff b1 cc 00 00 00                            push    dword ptr [ecx+0CCh]
000A51A2 [00424F92] 8b 8f cc 00 00 00                            mov     ecx, [edi+0CCh]
000A51A8 [00424F98] b8 10 18 44 00                               mov     eax, 441810h
000A51AD [00424F9D] ff d0                                        call    eax
000A51AF [00424F9F] 85 c0                                        test    eax, eax
000A51B1 [00424FA1] 74 04                                        jz      short near ptr unk_424FA7 ; game-relative-target=0x000A51B7
000A51B3 [00424FA3] 33 db                                        xor     ebx, ebx
000A51B5 [00424FA5] eb 50                                        jmp     short near ptr unk_424FF7 ; game-relative-target=0x000A5207
000A51B7 [00424FA7] 8a 44 24 0c                                  mov     al, [esp+0Ch]
000A51BB [00424FAB] 3c 04                                        cmp     al, 4
000A51BD [00424FAD] 74 3d                                        jz      short near ptr unk_424FEC ; game-relative-target=0x000A51FC
000A51BF [00424FAF] 3c 05                                        cmp     al, 5
000A51C1 [00424FB1] 74 39                                        jz      short near ptr unk_424FEC ; game-relative-target=0x000A51FC
000A51C3 [00424FB3] 83 7c 24 1c 18                               cmp     dword ptr [esp+1Ch], 18h
000A51C8 [00424FB8] 7c 3d                                        jl      short near ptr unk_424FF7 ; game-relative-target=0x000A5207
000A51CA [00424FBA] 4b                                           dec     ebx
000A51CB [00424FBB] 8b 0c 24                                     mov     ecx, [esp]
000A51CE [00424FBE] 81 b9 88 00 00 00 40 1f 00 00                cmp     dword ptr [ecx+88h], 1F40h
000A51D8 [00424FC8] 7c 1e                                        jl      short near ptr unk_424FE8 ; game-relative-target=0x000A51F8
000A51DA [00424FCA] 8b 46 08                                     mov     eax, [esi+8]
000A51DD [00424FCD] ff b0 cc 00 00 00                            push    dword ptr [eax+0CCh]
000A51E3 [00424FD3] ff b1 cc 00 00 00                            push    dword ptr [ecx+0CCh]
000A51E9 [00424FD9] b8 70 06 4b 00                               mov     eax, 4B0670h
000A51EE [00424FDE] ff d0                                        call    eax
000A51F0 [00424FE0] 83 c4 08                                     add     esp, 8
000A51F3 [00424FE3] 85 c0                                        test    eax, eax
000A51F5 [00424FE5] 74 01                                        jz      short near ptr unk_424FE8 ; game-relative-target=0x000A51F8
000A51F7 [00424FE7] 4b                                           dec     ebx
000A51F8 [00424FE8] 85 db                                        test    ebx, ebx
000A51FA [00424FEA] 7e 0b                                        jle     short near ptr unk_424FF7 ; game-relative-target=0x000A5207
000A51FC [00424FEC] 8b 6d 00                                     mov     ebp, [ebp+0]
000A51FF [00424FEF] 85 ed                                        test    ebp, ebp
000A5201 [00424FF1] 0f 85 5d ff ff ff                            jnz     near ptr unk_424F54 ; game-relative-target=0x000A5164
000A5207 [00424FF7] 8d 4c 24 30                                  lea     ecx, [esp+30h]
000A520B [00424FFB] b8 10 9f 47 00                               mov     eax, 479F10h
000A5210 [00425000] ff d0                                        call    eax
000A5212 [00425002] 8b c3                                        mov     eax, ebx
000A5214 [00425004] 5a                                           pop     edx
000A5215 [00425005] 5b                                           pop     ebx
000A5216 [00425006] 5d                                           pop     ebp
000A5217 [00425007] 59                                           pop     ecx
000A5218 [00425008] 85 c0                                        test    eax, eax
000A521A [0042500A] 7e 53                                        jle     short near ptr unk_42505F ; game-relative-target=0x000A526F
000A521C [0042500C] 80 f9 04                                     cmp     cl, 4
000A521F [0042500F] 75 06                                        jnz     short near ptr unk_425017 ; game-relative-target=0x000A5227
000A5221 [00425011] 80 4f 0f 04                                  or      byte ptr [edi+0Fh], 4
000A5225 [00425015] eb 48                                        jmp     short near ptr unk_42505F ; game-relative-target=0x000A526F
000A5227 [00425017] 80 f9 05                                     cmp     cl, 5
000A522A [0042501A] 75 06                                        jnz     short near ptr unk_425022 ; game-relative-target=0x000A5232
000A522C [0042501C] 80 4f 0f 02                                  or      byte ptr [edi+0Fh], 2
000A5230 [00425020] eb 3d                                        jmp     short near ptr unk_42505F ; game-relative-target=0x000A526F
000A5232 [00425022] 80 f9 02                                     cmp     cl, 2
000A5235 [00425025] 74 34                                        jz      short near ptr unk_42505B ; game-relative-target=0x000A526B
000A5237 [00425027] 3c 01                                        cmp     al, 1
000A5239 [00425029] 74 30                                        jz      short near ptr unk_42505B ; game-relative-target=0x000A526B
000A523B [0042502B] 80 4f 0f 20                                  or      byte ptr [edi+0Fh], 20h ; ' '
000A523F [0042502F] 8b 44 24 0c                                  mov     eax, [esp+0Ch]
000A5243 [00425033] 66 3d 14 00                                  cmp     ax, 14h
000A5247 [00425037] 7d 04                                        jge     short near ptr unk_42503D ; game-relative-target=0x000A524D
000A5249 [00425039] 66 b8 14 00                                  mov     ax, 14h
000A524D [0042503D] 83 e8 5a                                     sub     eax, 5Ah ; 'Z'
000A5250 [00425040] f7 d8                                        neg     eax
000A5252 [00425042] 85 c0                                        test    eax, eax
000A5254 [00425044] 7e 19                                        jle     short near ptr unk_42505F ; game-relative-target=0x000A526F
000A5256 [00425046] 8b 4e 08                                     mov     ecx, [esi+8]
000A5259 [00425049] f7 a9 88 00 00 00                            imul    dword ptr [ecx+88h]
000A525F [0042504F] 99                                           cdq
000A5260 [00425050] b9 3c 00 00 00                               mov     ecx, 3Ch ; '<'
000A5265 [00425055] f7 f1                                        div     ecx
000A5267 [00425057] 03 e8                                        add     ebp, eax
000A5269 [00425059] eb 04                                        jmp     short near ptr unk_42505F ; game-relative-target=0x000A526F
000A526B [0042505B] 80 4f 0f 10                                  or      byte ptr [edi+0Fh], 10h
000A526F [0042505F] 8b 36                                        mov     esi, [esi]
000A5271 [00425061] 85 f6                                        test    esi, esi
000A5273 [00425063] 0f 85 68 fe ff ff                            jnz     near ptr unk_424ED1 ; game-relative-target=0x000A50E1
000A5279 [00425069] 8b cc                                        mov     ecx, esp
000A527B [0042506B] b8 e0 80 51 00                               mov     eax, 5180E0h
000A5280 [00425070] ff d0                                        call    eax
000A5282 [00425072] 83 c4 60                                     add     esp, 60h ; '`'
000A5285 [00425075] 5e                                           pop     esi
000A5286 [00425076] 8b cc                                        mov     ecx, esp
000A5288 [00425078] b8 e0 80 51 00                               mov     eax, 5180E0h
000A528D [0042507D] ff d0                                        call    eax
000A528F [0042507F] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A5293 [00425083] b8 e0 80 51 00                               mov     eax, 5180E0h
000A5298 [00425088] ff d0                                        call    eax
000A529A [0042508A] 83 c4 40                                     add     esp, 40h ; '@'
000A529D [0042508D] 8b cf                                        mov     ecx, edi
000A529F [0042508F] b8 c0 61 43 00                               mov     eax, 4361C0h
000A52A4 [00425094] ff d0                                        call    eax
000A52A6 [00425096] 6b c0 7b                                     imul    eax, 7Bh ; '{'
000A52A9 [00425099] c1 e8 07                                     shr     eax, 7
000A52AC [0042509C] 3b e8                                        cmp     ebp, eax
000A52AE [0042509E] 7e 02                                        jle     short near ptr unk_4250A2 ; game-relative-target=0x000A52B2
000A52B0 [004250A0] 8b e8                                        mov     ebp, eax
000A52B2 [004250A2] 2b 04 b3                                     sub     eax, [ebx+esi*4]
000A52B5 [004250A5] 7f 19                                        jg      short near ptr unk_4250C0 ; game-relative-target=0x000A52D0
000A52B7 [004250A7] 80 4f 0f 08                                  or      byte ptr [edi+0Fh], 8
000A52BB [004250AB] f7 d8                                        neg     eax
000A52BD [004250AD] 3d 88 13 00 00                               cmp     eax, 1388h
000A52C2 [004250B2] 7e 08                                        jle     short near ptr unk_4250BC ; game-relative-target=0x000A52CC
000A52C4 [004250B4] 3b 87 88 00 00 00                            cmp     eax, [edi+88h]
000A52CA [004250BA] 7c 02                                        jl      short near ptr unk_4250BE ; game-relative-target=0x000A52CE
000A52CC [004250BC] 33 c0                                        xor     eax, eax
000A52CE [004250BE] eb 7e                                        jmp     short near ptr unk_42513E ; game-relative-target=0x000A534E
000A52D0 [004250C0] 8b 04 b3                                     mov     eax, [ebx+esi*4]
000A52D3 [004250C3] 2b c5                                        sub     eax, ebp
000A52D5 [004250C5] f6 47 0f 20                                  test    byte ptr [edi+0Fh], 20h ; ' '
000A52D9 [004250C9] 74 12                                        jz      short near ptr unk_4250DD ; game-relative-target=0x000A52ED
000A52DB [004250CB] ba 78 ec ff ff                               mov     edx, 0FFFFEC78h
000A52E0 [004250D0] 3b c2                                        cmp     eax, edx
000A52E2 [004250D2] 7c 02                                        jl      short near ptr unk_4250D6 ; game-relative-target=0x000A52E6
000A52E4 [004250D4] 8b c2                                        mov     eax, edx
000A52E6 [004250D6] 2d ff 03 00 00                               sub     eax, 3FFh
000A52EB [004250DB] eb 4d                                        jmp     short near ptr unk_42512A ; game-relative-target=0x000A533A
000A52ED [004250DD] f6 47 0f 10                                  test    byte ptr [edi+0Fh], 10h
000A52F1 [004250E1] 74 17                                        jz      short near ptr unk_4250FA ; game-relative-target=0x000A530A
000A52F3 [004250E3] ff 15 dc f2 5f 00                            call    dword ptr ds:5FF2DCh
000A52F9 [004250E9] f7 6f 04                                     imul    dword ptr [edi+4]
000A52FC [004250EC] 25 ff 03 00 00                               and     eax, 3FFh
000A5301 [004250F1] 05 88 13 00 00                               add     eax, 1388h
000A5306 [004250F6] f7 d8                                        neg     eax
000A5308 [004250F8] eb 30                                        jmp     short near ptr unk_42512A ; game-relative-target=0x000A533A
000A530A [004250FA] f6 47 0f 02                                  test    byte ptr [edi+0Fh], 2
000A530E [004250FE] 74 11                                        jz      short near ptr unk_425111 ; game-relative-target=0x000A5321
000A5310 [00425100] 03 c5                                        add     eax, ebp
000A5312 [00425102] bd 50 c3 00 00                               mov     ebp, 0C350h
000A5317 [00425107] 2b c5                                        sub     eax, ebp
000A5319 [00425109] 85 c0                                        test    eax, eax
000A531B [0042510B] 7d 02                                        jge     short near ptr unk_42510F ; game-relative-target=0x000A531F
000A531D [0042510D] 33 c0                                        xor     eax, eax
000A531F [0042510F] eb 0f                                        jmp     short near ptr unk_425120 ; game-relative-target=0x000A5330
000A5321 [00425111] f6 47 0f 04                                  test    byte ptr [edi+0Fh], 4
000A5325 [00425115] 74 09                                        jz      short near ptr unk_425120 ; game-relative-target=0x000A5330
000A5327 [00425117] 03 c5                                        add     eax, ebp
000A5329 [00425119] bd 20 4e 00 00                               mov     ebp, 4E20h
000A532E [0042511E] 2b c5                                        sub     eax, ebp
000A5330 [00425120] eb 0a                                        jmp     short near ptr unk_42512C ; game-relative-target=0x000A533C
000A5332 [00425122] f6 47 0f 30                                  test    byte ptr [edi+0Fh], 30h ; '0'
000A5336 [00425126] 74 04                                        jz      short near ptr unk_42512C ; game-relative-target=0x000A533C
000A5338 [00425128] 33 c0                                        xor     eax, eax
000A533A [0042512A] eb 12                                        jmp     short near ptr unk_42513E ; game-relative-target=0x000A534E
000A533C [0042512C] 85 c0                                        test    eax, eax
000A533E [0042512E] 7e 0e                                        jle     short near ptr unk_42513E ; game-relative-target=0x000A534E
000A5340 [00425130] 8b 87 88 00 00 00                            mov     eax, [edi+88h]
000A5346 [00425136] 2b c5                                        sub     eax, ebp
000A5348 [00425138] 85 c0                                        test    eax, eax
000A534A [0042513A] 7d 02                                        jge     short near ptr unk_42513E ; game-relative-target=0x000A534E
000A534C [0042513C] 33 c0                                        xor     eax, eax
000A534E [0042513E] 89 04 b3                                     mov     [ebx+esi*4], eax
000A5351 [00425141] 58                                           pop     eax
000A5352 [00425142] 04 03                                        add     al, 3
000A5354 [00425144] 50                                           push    eax
000A5355 [00425145] c3                                           retn
