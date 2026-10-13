; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421230; baseline game VA=0x000A1000; size=724
; Relative branch annotations use the baseline game destination.
000A1000 [00421230] b8 10 ec 50 00                               mov     eax, 50EC10h
000A1005 [00421235] ff d0                                        call    eax
000A1007 [00421237] 85 c0                                        test    eax, eax
000A1009 [00421239] 75 0d                                        jnz     short near ptr unk_421248 ; game-relative-target=0x000A1018
000A100B [0042123B] c6 05 ca f4 43 00 01                         mov     byte ptr ds:43F4CAh, 1
000A1012 [00421242] 68 00 2b 0a 00                               push    0A2B00h
000A1017 [00421247] c3                                           retn
000A1018 [00421248] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A101C [0042124C] 74 01                                        jz      short near ptr unk_42124F ; game-relative-target=0x000A101F
000A101E [0042124E] c3                                           retn
000A101F [0042124F] 3b 80 b8 00 00 00                            cmp     eax, [eax+0B8h]
000A1025 [00421255] 74 01                                        jz      short near ptr unk_421258 ; game-relative-target=0x000A1028
000A1027 [00421257] c3                                           retn
000A1028 [00421258] f6 05 ca f4 43 00 01                         test    byte ptr ds:43F4CAh, 1
000A102F [0042125F] 75 01                                        jnz     short near ptr unk_421262 ; game-relative-target=0x000A1032
000A1031 [00421261] c3                                           retn
000A1032 [00421262] 57                                           push    edi
000A1033 [00421263] ff 35 9c 26 23 01                            push    dword ptr ds:123269Ch
000A1039 [00421269] b8 50 aa 46 00                               mov     eax, 46AA50h
000A103E [0042126E] ff d0                                        call    eax
000A1040 [00421270] a2 14 ff 43 00                               mov     ds:43FF14h, al
000A1045 [00421275] 33 c0                                        xor     eax, eax
000A1047 [00421277] a3 64 fa 43 00                               mov     ds:43FA64h, eax
000A104C [0042127C] a3 e4 fb 43 00                               mov     ds:43FBE4h, eax
000A1051 [00421281] a3 08 fc 43 00                               mov     ds:43FC08h, eax
000A1056 [00421286] a2 ca f4 43 00                               mov     ds:43F4CAh, al
000A105B [0042128B] b9 30 00 00 00                               mov     ecx, 30h ; '0'
000A1060 [00421290] bf 00 0d 0a 00                               mov     edi, 0A0D00h
000A1065 [00421295] f3 ab                                        rep stosd
000A1067 [00421297] 56                                           push    esi
000A1068 [00421298] 33 ff                                        xor     edi, edi
000A106A [0042129A] 57                                           push    edi
000A106B [0042129B] b8 00 71 47 00                               mov     eax, 477100h
000A1070 [004212A0] ff d0                                        call    eax
000A1072 [004212A2] 85 c0                                        test    eax, eax
000A1074 [004212A4] 74 56                                        jz      short near ptr unk_4212FC ; game-relative-target=0x000A10CC
000A1076 [004212A6] 8b f0                                        mov     esi, eax
000A1078 [004212A8] 8b ce                                        mov     ecx, esi
000A107A [004212AA] b8 20 54 43 00                               mov     eax, 435420h
000A107F [004212AF] ff d0                                        call    eax
000A1081 [004212B1] 85 c0                                        test    eax, eax
000A1083 [004212B3] 7e 47                                        jle     short near ptr unk_4212FC ; game-relative-target=0x000A10CC
000A1085 [004212B5] 56                                           push    esi
000A1086 [004212B6] 6a 7f                                        push    7Fh
000A1088 [004212B8] 6a 00                                        push    0
000A108A [004212BA] 6a 00                                        push    0
000A108C [004212BC] 8b c4                                        mov     eax, esp
000A108E [004212BE] 6a 00                                        push    0
000A1090 [004212C0] 50                                           push    eax
000A1091 [004212C1] 68 80 0f 0a 00                               push    0A0F80h
000A1096 [004212C6] b9 20 05 0a 00                               mov     ecx, 0A0520h
000A109B [004212CB] b8 80 f2 46 00                               mov     eax, 46F280h
000A10A0 [004212D0] ff d0                                        call    eax
000A10A2 [004212D2] 83 c4 10                                     add     esp, 10h
000A10A5 [004212D5] 68 60 45 47 00                               push    474560h
000A10AA [004212DA] b9 20 05 0a 00                               mov     ecx, 0A0520h
000A10AF [004212DF] b8 30 e8 46 00                               mov     eax, 46E830h
000A10B4 [004212E4] ff d0                                        call    eax
000A10B6 [004212E6] 85 c0                                        test    eax, eax
000A10B8 [004212E8] 7e 12                                        jle     short near ptr unk_4212FC ; game-relative-target=0x000A10CC
000A10BA [004212EA] c1 e8 0a                                     shr     eax, 0Ah
000A10BD [004212ED] 3d ff 00 00 00                               cmp     eax, 0FFh
000A10C2 [004212F2] 7e 02                                        jle     short near ptr unk_4212F6 ; game-relative-target=0x000A10C6
000A10C4 [004212F4] b0 ff                                        mov     al, 0FFh
000A10C6 [004212F6] 88 87 00 0d 0a 00                            mov     [edi+0A0D00h], al
000A10CC [004212FC] 47                                           inc     edi
000A10CD [004212FD] 81 ff fa 00 00 00                            cmp     edi, 0FAh
000A10D3 [00421303] 7c 95                                        jl      short near ptr unk_42129A ; game-relative-target=0x000A106A
000A10D5 [00421305] b9 20 05 0a 00                               mov     ecx, 0A0520h
000A10DA [0042130A] b8 e0 80 51 00                               mov     eax, 5180E0h
000A10DF [0042130F] ff d0                                        call    eax
000A10E1 [00421311] 5e                                           pop     esi
000A10E2 [00421312] c6 05 15 ff 43 00 0a                         mov     byte ptr ds:43FF15h, 0Ah
000A10E9 [00421319] c6 05 8c f8 43 00 70                         mov     byte ptr ds:43F88Ch, 70h ; 'p'
000A10F0 [00421320] b9 00 0e 0a 00                               mov     ecx, 0A0E00h
000A10F5 [00421325] ba c0 00 00 00                               mov     edx, 0C0h
000A10FA [0042132A] 8a 01                                        mov     al, [ecx]
000A10FC [0042132C] 84 c0                                        test    al, al
000A10FE [0042132E] 74 04                                        jz      short near ptr unk_421334 ; game-relative-target=0x000A1104
000A1100 [00421330] fe c8                                        dec     al
000A1102 [00421332] 88 01                                        mov     [ecx], al
000A1104 [00421334] 41                                           inc     ecx
000A1105 [00421335] 4a                                           dec     edx
000A1106 [00421336] 75 f2                                        jnz     short near ptr unk_42132A ; game-relative-target=0x000A10FA
000A1108 [00421338] f6 05 ce f4 43 00 01                         test    byte ptr ds:43F4CEh, 1
000A110F [0042133F] 74 78                                        jz      short near ptr unk_4213B9 ; game-relative-target=0x000A1189
000A1111 [00421341] b9 58 db 24 01                               mov     ecx, 124DB58h
000A1116 [00421346] bf c8 00 00 00                               mov     edi, 0C8h
000A111B [0042134B] 8b 81 cc 00 00 00                            mov     eax, [ecx+0CCh]
000A1121 [00421351] 85 c0                                        test    eax, eax
000A1123 [00421353] 7e 56                                        jle     short near ptr unk_4213AB ; game-relative-target=0x000A117B
000A1125 [00421355] f6 40 34 04                                  test    byte ptr [eax+34h], 4
000A1129 [00421359] 75 50                                        jnz     short near ptr unk_4213AB ; game-relative-target=0x000A117B
000A112B [0042135B] f6 41 7a 40                                  test    byte ptr [ecx+7Ah], 40h ; '@'
000A112F [0042135F] 75 4a                                        jnz     short near ptr unk_4213AB ; game-relative-target=0x000A117B
000A1131 [00421361] 51                                           push    ecx
000A1132 [00421362] 68 00 05 0a 00                               push    0A0500h
000A1137 [00421367] b8 20 6c 43 00                               mov     eax, 436C20h
000A113C [0042136C] ff d0                                        call    eax
000A113E [0042136E] 59                                           pop     ecx
000A113F [0042136F] 85 c0                                        test    eax, eax
000A1141 [00421371] 75 38                                        jnz     short near ptr unk_4213AB ; game-relative-target=0x000A117B
000A1143 [00421373] 8b d1                                        mov     edx, ecx
000A1145 [00421375] 81 c2 bc 01 00 00                            add     edx, 1BCh
000A114B [0042137B] 8b 42 08                                     mov     eax, [edx+8]
000A114E [0042137E] 3b c7                                        cmp     eax, edi
000A1150 [00421380] 7c 09                                        jl      short near ptr unk_42138B ; game-relative-target=0x000A115B
000A1152 [00421382] 6b c0 7e                                     imul    eax, 7Eh ; '~'
000A1155 [00421385] c1 e8 07                                     shr     eax, 7
000A1158 [00421388] 89 42 08                                     mov     [edx+8], eax
000A115B [0042138B] 8b 42 10                                     mov     eax, [edx+10h]
000A115E [0042138E] 3b c7                                        cmp     eax, edi
000A1160 [00421390] 7c 09                                        jl      short near ptr unk_42139B ; game-relative-target=0x000A116B
000A1162 [00421392] 6b c0 7e                                     imul    eax, 7Eh ; '~'
000A1165 [00421395] c1 e8 07                                     shr     eax, 7
000A1168 [00421398] 89 42 10                                     mov     [edx+10h], eax
000A116B [0042139B] 8b 42 14                                     mov     eax, [edx+14h]
000A116E [0042139E] 3b c7                                        cmp     eax, edi
000A1170 [004213A0] 7c 09                                        jl      short near ptr unk_4213AB ; game-relative-target=0x000A117B
000A1172 [004213A2] 6b c0 7e                                     imul    eax, 7Eh ; '~'
000A1175 [004213A5] c1 e8 07                                     shr     eax, 7
000A1178 [004213A8] 89 42 14                                     mov     [edx+14h], eax
000A117B [004213AB] 81 c1 f0 01 00 00                            add     ecx, 1F0h
000A1181 [004213B1] 81 f9 38 3c 25 01                            cmp     ecx, 1253C38h
000A1187 [004213B7] 7c 92                                        jl      short near ptr unk_42134B ; game-relative-target=0x000A111B
000A1189 [004213B9] b9 00 05 0a 00                               mov     ecx, 0A0500h
000A118E [004213BE] b8 e0 80 51 00                               mov     eax, 5180E0h
000A1193 [004213C3] ff d0                                        call    eax
000A1195 [004213C5] 80 3d cf f4 43 00 00                         cmp     byte ptr ds:43F4CFh, 0
000A119C [004213CC] 0f 84 93 00 00 00                            jz      near ptr unk_421465 ; game-relative-target=0x000A1235
000A11A2 [004213D2] 56                                           push    esi
000A11A3 [004213D3] 53                                           push    ebx
000A11A4 [004213D4] 55                                           push    ebp
000A11A5 [004213D5] bd 96 00 00 00                               mov     ebp, 96h
000A11AA [004213DA] 0f b6 1d cf f4 43 00                         movzx   ebx, byte ptr ds:43F4CFh
000A11B1 [004213E1] 6b db 0a                                     imul    ebx, 0Ah
000A11B4 [004213E4] be 64 8f 25 01                               mov     esi, 1258F64h
000A11B9 [004213E9] 83 3e 03                                     cmp     dword ptr [esi], 3
000A11BC [004213EC] 7f 66                                        jg      short near ptr unk_421454 ; game-relative-target=0x000A1224
000A11BE [004213EE] 83 3e 01                                     cmp     dword ptr [esi], 1
000A11C1 [004213F1] 7c 61                                        jl      short near ptr unk_421454 ; game-relative-target=0x000A1224
000A11C3 [004213F3] 8b 46 70                                     mov     eax, [esi+70h]
000A11C6 [004213F6] 8b 48 74                                     mov     ecx, [eax+74h]
000A11C9 [004213F9] 8b 89 b8 00 00 00                            mov     ecx, [ecx+0B8h]
000A11CF [004213FF] 8b b9 bc 00 00 00                            mov     edi, [ecx+0BCh]
000A11D5 [00421405] 3b 87 f4 00 00 00                            cmp     eax, [edi+0F4h]
000A11DB [0042140B] 75 47                                        jnz     short near ptr unk_421454 ; game-relative-target=0x000A1224
000A11DD [0042140D] 83 fb 64                                     cmp     ebx, 64h ; 'd'
000A11E0 [00421410] 7d 17                                        jge     short near ptr unk_421429 ; game-relative-target=0x000A11F9
000A11E2 [00421412] ff 15 dc f2 5f 00                            call    dword ptr ds:5FF2DCh
000A11E8 [00421418] 0f af 46 e8                                  imul    eax, [esi-18h]
000A11EC [0042141C] 33 d2                                        xor     edx, edx
000A11EE [0042141E] b9 64 00 00 00                               mov     ecx, 64h ; 'd'
000A11F3 [00421423] f7 f9                                        idiv    ecx
000A11F5 [00421425] 3b d3                                        cmp     edx, ebx
000A11F7 [00421427] 7d 2b                                        jge     short near ptr unk_421454 ; game-relative-target=0x000A1224
000A11F9 [00421429] 8b 47 6c                                     mov     eax, [edi+6Ch]
000A11FC [0042142C] 8b 56 e8                                     mov     edx, [esi-18h]
000A11FF [0042142F] 2b c2                                        sub     eax, edx
000A1201 [00421431] 85 c0                                        test    eax, eax
000A1203 [00421433] 7c 10                                        jl      short near ptr unk_421445 ; game-relative-target=0x000A1215
000A1205 [00421435] 74 1d                                        jz      short near ptr unk_421454 ; game-relative-target=0x000A1224
000A1207 [00421437] 83 f8 4b                                     cmp     eax, 4Bh ; 'K'
000A120A [0042143A] 7e 0e                                        jle     short near ptr unk_42144A ; game-relative-target=0x000A121A
000A120C [0042143C] 4a                                           dec     edx
000A120D [0042143D] 85 d2                                        test    edx, edx
000A120F [0042143F] 7d 02                                        jge     short near ptr unk_421443 ; game-relative-target=0x000A1213
000A1211 [00421441] 03 d5                                        add     edx, ebp
000A1213 [00421443] eb 0c                                        jmp     short near ptr unk_421451 ; game-relative-target=0x000A1221
000A1215 [00421445] 83 f8 b5                                     cmp     eax, 0FFFFFFB5h
000A1218 [00421448] 7d f2                                        jge     short near ptr unk_42143C ; game-relative-target=0x000A120C
000A121A [0042144A] 42                                           inc     edx
000A121B [0042144B] 3b d5                                        cmp     edx, ebp
000A121D [0042144D] 7c 02                                        jl      short near ptr unk_421451 ; game-relative-target=0x000A1221
000A121F [0042144F] 2b d5                                        sub     edx, ebp
000A1221 [00421451] 89 56 e8                                     mov     [esi-18h], edx
000A1224 [00421454] 81 c6 28 01 00 00                            add     esi, 128h
000A122A [0042145A] 81 fe b0 65 29 01                            cmp     esi, 12965B0h
000A1230 [00421460] 7c 87                                        jl      short near ptr unk_4213E9 ; game-relative-target=0x000A11B9
000A1232 [00421462] 5d                                           pop     ebp
000A1233 [00421463] 5b                                           pop     ebx
000A1234 [00421464] 5e                                           pop     esi
000A1235 [00421465] bf b0 93 4b 01                               mov     edi, 14B93B0h
000A123A [0042146A] f6 47 20 08                                  test    byte ptr [edi+20h], 8
000A123E [0042146E] 74 29                                        jz      short near ptr unk_421499 ; game-relative-target=0x000A1269
000A1240 [00421470] f6 47 22 10                                  test    byte ptr [edi+22h], 10h
000A1244 [00421474] 74 23                                        jz      short near ptr unk_421499 ; game-relative-target=0x000A1269
000A1246 [00421476] f6 47 22 40                                  test    byte ptr [edi+22h], 40h ; '@'
000A124A [0042147A] 74 1d                                        jz      short near ptr unk_421499 ; game-relative-target=0x000A1269
000A124C [0042147C] 8b 47 74                                     mov     eax, [edi+74h]
000A124F [0042147F] f6 40 34 05                                  test    byte ptr [eax+34h], 5
000A1253 [00421483] 75 14                                        jnz     short near ptr unk_421499 ; game-relative-target=0x000A1269
000A1255 [00421485] 8b 47 34                                     mov     eax, [edi+34h]
000A1258 [00421488] 6b c0 05                                     imul    eax, 5
000A125B [0042148B] 3b 47 30                                     cmp     eax, [edi+30h]
000A125E [0042148E] 7c 09                                        jl      short near ptr unk_421499 ; game-relative-target=0x000A1269
000A1260 [00421490] 8b cf                                        mov     ecx, edi
000A1262 [00421492] b8 b0 42 46 00                               mov     eax, 4642B0h
000A1267 [00421497] ff d0                                        call    eax
000A1269 [00421499] 81 c7 04 01 00 00                            add     edi, 104h
000A126F [0042149F] 66 81 7f 04 51 03                            cmp     word ptr [edi+4], 351h
000A1275 [004214A5] 7c c3                                        jl      short near ptr unk_42146A ; game-relative-target=0x000A123A
000A1277 [004214A7] f6 05 cd f4 43 00 01                         test    byte ptr ds:43F4CDh, 1
000A127E [004214AE] 74 4d                                        jz      short near ptr unk_4214FD ; game-relative-target=0x000A12CD
000A1280 [004214B0] 33 ff                                        xor     edi, edi
000A1282 [004214B2] b9 38 3c 25 01                               mov     ecx, 1253C38h
000A1287 [004214B7] 8d 81 b8 00 00 00                            lea     eax, [ecx+0B8h]
000A128D [004214BD] 83 78 04 00                                  cmp     dword ptr [eax+4], 0
000A1291 [004214C1] 74 2e                                        jz      short near ptr unk_4214F1 ; game-relative-target=0x000A12C1
000A1293 [004214C3] 8b 00                                        mov     eax, [eax]
000A1295 [004214C5] 3b c1                                        cmp     eax, ecx
000A1297 [004214C7] 74 28                                        jz      short near ptr unk_4214F1 ; game-relative-target=0x000A12C1
000A1299 [004214C9] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A129D [004214CD] 75 22                                        jnz     short near ptr unk_4214F1 ; game-relative-target=0x000A12C1
000A129F [004214CF] f6 40 72 08                                  test    byte ptr [eax+72h], 8
000A12A3 [004214D3] 75 1c                                        jnz     short near ptr unk_4214F1 ; game-relative-target=0x000A12C1
000A12A5 [004214D5] 51                                           push    ecx
000A12A6 [004214D6] 51                                           push    ecx
000A12A7 [004214D7] 6a 00                                        push    0
000A12A9 [004214D9] 6a 00                                        push    0
000A12AB [004214DB] 6a 01                                        push    1
000A12AD [004214DD] b8 70 24 44 00                               mov     eax, 442470h
000A12B2 [004214E2] ff d0                                        call    eax
000A12B4 [004214E4] b9 c0 26 23 01                               mov     ecx, 12326C0h
000A12B9 [004214E9] b8 50 ee 46 00                               mov     eax, 46EE50h
000A12BE [004214EE] ff d0                                        call    eax
000A12C0 [004214F0] 59                                           pop     ecx
000A12C1 [004214F1] 81 c1 d4 00 00 00                            add     ecx, 0D4h
000A12C7 [004214F7] 47                                           inc     edi
000A12C8 [004214F8] 83 ff 32                                     cmp     edi, 32h ; '2'
000A12CB [004214FB] 7c ba                                        jl      short near ptr unk_4214B7 ; game-relative-target=0x000A1287
000A12CD [004214FD] 5f                                           pop     edi
000A12CE [004214FE] 68 10 ec 50 00                               push    50EC10h
000A12D3 [00421503] c3                                           retn
