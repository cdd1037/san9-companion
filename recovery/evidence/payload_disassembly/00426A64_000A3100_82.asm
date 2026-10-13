; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426A64; baseline game VA=0x000A3100; size=130
; Relative branch annotations use the baseline game destination.
000A3100 [00426A64] b8 cc cc cc 0c                               mov     eax, 0CCCCCCCh
000A3105 [00426A69] 8b 51 54                                     mov     edx, [ecx+54h]
000A3108 [00426A6C] 80 fa 04                                     cmp     dl, 4
000A310B [00426A6F] 75 06                                        jnz     short near ptr unk_426A77 ; game-relative-target=0x000A3113
000A310D [00426A71] 6b c0 08                                     imul    eax, 8
000A3110 [00426A74] c2 04 00                                     retn    4
000A3113 [00426A77] 7c 06                                        jl      short near ptr unk_426A7F ; game-relative-target=0x000A311B
000A3115 [00426A79] 6b c0 05                                     imul    eax, 5
000A3118 [00426A7C] c2 04 00                                     retn    4
000A311B [00426A7F] 8b 4c 24 04                                  mov     ecx, [esp+4]
000A311F [00426A83] 80 fa 02                                     cmp     dl, 2
000A3122 [00426A86] 75 18                                        jnz     short near ptr unk_426AA0 ; game-relative-target=0x000A313C
000A3124 [00426A88] 8a 51 04                                     mov     dl, [ecx+4]
000A3127 [00426A8B] 80 fa 02                                     cmp     dl, 2
000A312A [00426A8E] 74 0a                                        jz      short near ptr unk_426A9A ; game-relative-target=0x000A3136
000A312C [00426A90] 80 fa 05                                     cmp     dl, 5
000A312F [00426A93] 74 05                                        jz      short near ptr unk_426A9A ; game-relative-target=0x000A3136
000A3131 [00426A95] 80 fa 10                                     cmp     dl, 10h
000A3134 [00426A98] 75 df                                        jnz     short near ptr unk_426A79 ; game-relative-target=0x000A3115
000A3136 [00426A9A] 6b c0 0a                                     imul    eax, 0Ah
000A3139 [00426A9D] c2 04 00                                     retn    4
000A313C [00426AA0] 80 fa 03                                     cmp     dl, 3
000A313F [00426AA3] 75 14                                        jnz     short near ptr unk_426AB9 ; game-relative-target=0x000A3155
000A3141 [00426AA5] 8a 51 04                                     mov     dl, [ecx+4]
000A3144 [00426AA8] 80 fa 04                                     cmp     dl, 4
000A3147 [00426AAB] 74 ed                                        jz      short near ptr unk_426A9A ; game-relative-target=0x000A3136
000A3149 [00426AAD] 80 fa 05                                     cmp     dl, 5
000A314C [00426AB0] 74 e8                                        jz      short near ptr unk_426A9A ; game-relative-target=0x000A3136
000A314E [00426AB2] 80 fa 08                                     cmp     dl, 8
000A3151 [00426AB5] 74 e3                                        jz      short near ptr unk_426A9A ; game-relative-target=0x000A3136
000A3153 [00426AB7] eb c0                                        jmp     short near ptr unk_426A79 ; game-relative-target=0x000A3115
000A3155 [00426AB9] 80 fa 01                                     cmp     dl, 1
000A3158 [00426ABC] 75 19                                        jnz     short near ptr unk_426AD7 ; game-relative-target=0x000A3173
000A315A [00426ABE] 8a 51 04                                     mov     dl, [ecx+4]
000A315D [00426AC1] 80 fa 02                                     cmp     dl, 2
000A3160 [00426AC4] 74 d4                                        jz      short near ptr unk_426A9A ; game-relative-target=0x000A3136
000A3162 [00426AC6] 80 fa 03                                     cmp     dl, 3
000A3165 [00426AC9] 74 cf                                        jz      short near ptr unk_426A9A ; game-relative-target=0x000A3136
000A3167 [00426ACB] 80 fa 10                                     cmp     dl, 10h
000A316A [00426ACE] 74 ca                                        jz      short near ptr unk_426A9A ; game-relative-target=0x000A3136
000A316C [00426AD0] 80 fa 11                                     cmp     dl, 11h
000A316F [00426AD3] 74 c5                                        jz      short near ptr unk_426A9A ; game-relative-target=0x000A3136
000A3171 [00426AD5] eb a2                                        jmp     short near ptr unk_426A79 ; game-relative-target=0x000A3115
000A3173 [00426AD7] 8a 51 04                                     mov     dl, [ecx+4]
000A3176 [00426ADA] 80 fa 00                                     cmp     dl, 0
000A3179 [00426ADD] 74 bb                                        jz      short near ptr unk_426A9A ; game-relative-target=0x000A3136
000A317B [00426ADF] 80 fa 01                                     cmp     dl, 1
000A317E [00426AE2] 74 b6                                        jz      short near ptr unk_426A9A ; game-relative-target=0x000A3136
000A3180 [00426AE4] eb 93                                        jmp     short near ptr unk_426A79 ; game-relative-target=0x000A3115
