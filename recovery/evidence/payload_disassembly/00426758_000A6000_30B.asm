; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426758; baseline game VA=0x000A6000; size=779
; Relative branch annotations use the baseline game destination.
000A6000 [00426758] 56                                           push    esi
000A6001 [00426759] 57                                           push    edi
000A6002 [0042675A] 55                                           push    ebp
000A6003 [0042675B] 53                                           push    ebx
000A6004 [0042675C] 8b 7c 24 14                                  mov     edi, [esp+14h]
000A6008 [00426760] bb 30 75 00 00                               mov     ebx, 7530h
000A600D [00426765] bd b8 0b 00 00                               mov     ebp, 0BB8h
000A6012 [0042676A] 53                                           push    ebx
000A6013 [0042676B] 83 ec 20                                     sub     esp, 20h ; ' '
000A6016 [0042676E] 89 6c 24 0c                                  mov     [esp+0Ch], ebp
000A601A [00426772] 8b 47 0c                                     mov     eax, [edi+0Ch]
000A601D [00426775] 85 c0                                        test    eax, eax
000A601F [00426777] 74 67                                        jz      short near ptr unk_4267E0 ; game-relative-target=0x000A6088
000A6021 [00426779] 69 c0 88 13 00 00                            imul    eax, 1388h
000A6027 [0042677F] 03 c5                                        add     eax, ebp
000A6029 [00426781] 8b 91 88 00 00 00                            mov     edx, [ecx+88h]
000A602F [00426787] 3b c2                                        cmp     eax, edx
000A6031 [00426789] 7e 02                                        jle     short near ptr unk_42678D ; game-relative-target=0x000A6035
000A6033 [0042678B] 8b c2                                        mov     eax, edx
000A6035 [0042678D] 3b c3                                        cmp     eax, ebx
000A6037 [0042678F] 7e 02                                        jle     short near ptr unk_426793 ; game-relative-target=0x000A603B
000A6039 [00426791] 8b c3                                        mov     eax, ebx
000A603B [00426793] 89 04 24                                     mov     [esp], eax
000A603E [00426796] 8b f1                                        mov     esi, ecx
000A6040 [00426798] 6a 01                                        push    1
000A6042 [0042679A] 8b 01                                        mov     eax, [ecx]
000A6044 [0042679C] ff 90 88 00 00 00                            call    dword ptr [eax+88h]
000A604A [004267A2] d1 e0                                        shl     eax, 1
000A604C [004267A4] 8b 96 c4 00 00 00                            mov     edx, [esi+0C4h]
000A6052 [004267AA] 0f af 42 6c                                  imul    eax, [edx+6Ch]
000A6056 [004267AE] b9 0f 00 00 00                               mov     ecx, 0Fh
000A605B [004267B3] 99                                           cdq
000A605C [004267B4] f7 f1                                        div     ecx
000A605E [004267B6] 8b d8                                        mov     ebx, eax
000A6060 [004267B8] 0f b6 05 46 a4 49 00                         movzx   eax, byte ptr ds:49A446h
000A6067 [004267BF] 66 f7 6e 3c                                  imul    word ptr [esi+3Ch]
000A606B [004267C3] b1 05                                        mov     cl, 5
000A606D [004267C5] 99                                           cdq
000A606E [004267C6] f7 f1                                        div     ecx
000A6070 [004267C8] 03 c3                                        add     eax, ebx
000A6072 [004267CA] 89 44 24 04                                  mov     [esp+4], eax
000A6076 [004267CE] 8b ce                                        mov     ecx, esi
000A6078 [004267D0] b8 d0 53 43 00                               mov     eax, 4353D0h
000A607D [004267D5] ff d0                                        call    eax
000A607F [004267D7] 89 44 24 08                                  mov     [esp+8], eax
000A6083 [004267DB] 8b 7f 04                                     mov     edi, [edi+4]
000A6086 [004267DE] 85 ff                                        test    edi, edi
000A6088 [004267E0] 0f 84 5d 02 00 00                            jz      near ptr unk_426A43 ; game-relative-target=0x000A62EB
000A608E [004267E6] 8b 6f 08                                     mov     ebp, [edi+8]
000A6091 [004267E9] 8b cd                                        mov     ecx, ebp
000A6093 [004267EB] 56                                           push    esi
000A6094 [004267EC] b8 70 88 46 00                               mov     eax, 468870h
000A6099 [004267F1] ff d0                                        call    eax
000A609B [004267F3] 83 e8 02                                     sub     eax, 2
000A609E [004267F6] 80 7e 06 05                                  cmp     byte ptr [esi+6], 5
000A60A2 [004267FA] 75 01                                        jnz     short near ptr unk_4267FD ; game-relative-target=0x000A60A5
000A60A4 [004267FC] 48                                           dec     eax
000A60A5 [004267FD] 33 db                                        xor     ebx, ebx
000A60A7 [004267FF] 85 c0                                        test    eax, eax
000A60A9 [00426801] 7f 03                                        jg      short near ptr unk_426806 ; game-relative-target=0x000A60AE
000A60AB [00426803] 33 c0                                        xor     eax, eax
000A60AD [00426805] 43                                           inc     ebx
000A60AE [00426806] 8b 55 24                                     mov     edx, [ebp+24h]
000A60B1 [00426809] 8b 4d 28                                     mov     ecx, [ebp+28h]
000A60B4 [0042680C] 80 fa 04                                     cmp     dl, 4
000A60B7 [0042680F] 75 04                                        jnz     short near ptr unk_426815 ; game-relative-target=0x000A60BD
000A60B9 [00426811] 03 c1                                        add     eax, ecx
000A60BB [00426813] 03 c1                                        add     eax, ecx
000A60BD [00426815] 80 fa 06                                     cmp     dl, 6
000A60C0 [00426818] 75 02                                        jnz     short near ptr unk_42681C ; game-relative-target=0x000A60C4
000A60C2 [0042681A] 03 c1                                        add     eax, ecx
000A60C4 [0042681C] 3c 01                                        cmp     al, 1
000A60C6 [0042681E] 7e 0f                                        jle     short near ptr unk_42682F ; game-relative-target=0x000A60D7
000A60C8 [00426820] 85 db                                        test    ebx, ebx
000A60CA [00426822] 75 0b                                        jnz     short near ptr unk_42682F ; game-relative-target=0x000A60D7
000A60CC [00426824] f7 45 20 04 00 40 00                         test    dword ptr [ebp+20h], 400004h
000A60D3 [0042682B] 74 02                                        jz      short near ptr unk_42682F ; game-relative-target=0x000A60D7
000A60D5 [0042682D] d1 e0                                        shl     eax, 1
000A60D7 [0042682F] 89 44 24 14                                  mov     [esp+14h], eax
000A60DB [00426833] 2a 05 15 ff 43 00                            sub     al, ds:43FF15h
000A60E1 [00426839] f6 d8                                        neg     al
000A60E3 [0042683B] 84 c0                                        test    al, al
000A60E5 [0042683D] 0f 8e f9 01 00 00                            jle     near ptr unk_426A3C ; game-relative-target=0x000A62E4
000A60EB [00426843] 89 44 24 10                                  mov     [esp+10h], eax
000A60EF [00426847] 33 c0                                        xor     eax, eax
000A60F1 [00426849] 80 fa 05                                     cmp     dl, 5
000A60F4 [0042684C] 75 0c                                        jnz     short near ptr unk_42685A ; game-relative-target=0x000A6102
000A60F6 [0042684E] 8b c1                                        mov     eax, ecx
000A60F8 [00426850] 2b 44 24 14                                  sub     eax, [esp+14h]
000A60FC [00426854] 85 c0                                        test    eax, eax
000A60FE [00426856] 7d 02                                        jge     short near ptr unk_42685A ; game-relative-target=0x000A6102
000A6100 [00426858] 33 c0                                        xor     eax, eax
000A6102 [0042685A] 2b 44 24 10                                  sub     eax, [esp+10h]
000A6106 [0042685E] f7 d8                                        neg     eax
000A6108 [00426860] 85 c0                                        test    eax, eax
000A610A [00426862] 0f 8e d4 01 00 00                            jle     near ptr unk_426A3C ; game-relative-target=0x000A62E4
000A6110 [00426868] 89 44 24 18                                  mov     [esp+18h], eax
000A6114 [0042686C] 6a 01                                        push    1
000A6116 [0042686E] 8b cd                                        mov     ecx, ebp
000A6118 [00426870] 8b 01                                        mov     eax, [ecx]
000A611A [00426872] ff 90 88 00 00 00                            call    dword ptr [eax+88h]
000A6120 [00426878] 8b d8                                        mov     ebx, eax
000A6122 [0042687A] c6 44 24 1c 00                               mov     byte ptr [esp+1Ch], 0
000A6127 [0042687F] 80 7c 24 08 01                               cmp     byte ptr [esp+8], 1
000A612C [00426884] 75 17                                        jnz     short near ptr unk_42689D ; game-relative-target=0x000A6145
000A612E [00426886] 8b cd                                        mov     ecx, ebp
000A6130 [00426888] b8 90 e3 45 00                               mov     eax, 45E390h
000A6135 [0042688D] ff d0                                        call    eax
000A6137 [0042688F] 85 c0                                        test    eax, eax
000A6139 [00426891] 74 0a                                        jz      short near ptr unk_42689D ; game-relative-target=0x000A6145
000A613B [00426893] 8b 4d 70                                     mov     ecx, [ebp+70h]
000A613E [00426896] c6 44 24 1c 01                               mov     byte ptr [esp+1Ch], 1
000A6143 [0042689B] eb 03                                        jmp     short near ptr unk_4268A0 ; game-relative-target=0x000A6148
000A6145 [0042689D] 8b 4d 6c                                     mov     ecx, [ebp+6Ch]
000A6148 [004268A0] 8b 41 64                                     mov     eax, [ecx+64h]
000A614B [004268A3] 0f af c3                                     imul    eax, ebx
000A614E [004268A6] d1 e0                                        shl     eax, 1
000A6150 [004268A8] b9 19 00 00 00                               mov     ecx, 19h
000A6155 [004268AD] 99                                           cdq
000A6156 [004268AE] f7 f1                                        div     ecx
000A6158 [004268B0] 2b 44 24 04                                  sub     eax, [esp+4]
000A615C [004268B4] 05 84 03 00 00                               add     eax, 384h
000A6161 [004268B9] 0f af c0                                     imul    eax, eax
000A6164 [004268BC] c1 e8 0b                                     shr     eax, 0Bh
000A6167 [004268BF] 8b d8                                        mov     ebx, eax
000A6169 [004268C1] 8b 45 30                                     mov     eax, [ebp+30h]
000A616C [004268C4] 03 04 24                                     add     eax, [esp]
000A616F [004268C7] 8b 4c 24 18                                  mov     ecx, [esp+18h]
000A6173 [004268CB] 83 e9 2c                                     sub     ecx, 2Ch ; ','
000A6176 [004268CE] f7 d9                                        neg     ecx
000A6178 [004268D0] 0f af c1                                     imul    eax, ecx
000A617B [004268D3] b9 4e 0c 00 00                               mov     ecx, 0C4Eh
000A6180 [004268D8] 99                                           cdq
000A6181 [004268D9] f7 f1                                        div     ecx
000A6183 [004268DB] 05 90 01 00 00                               add     eax, 190h
000A6188 [004268E0] 0f af c3                                     imul    eax, ebx
000A618B [004268E3] b9 58 02 00 00                               mov     ecx, 258h
000A6190 [004268E8] 99                                           cdq
000A6191 [004268E9] f7 f1                                        div     ecx
000A6193 [004268EB] 0f af 44 24 18                               imul    eax, [esp+18h]
000A6198 [004268F0] 01 44 24 0c                                  add     [esp+0Ch], eax
000A619C [004268F4] 56                                           push    esi
000A619D [004268F5] 57                                           push    edi
000A619E [004268F6] 6a 00                                        push    0
000A61A0 [004268F8] 6a 00                                        push    0
000A61A2 [004268FA] 8b bd 88 00 00 00                            mov     edi, [ebp+88h]
000A61A8 [00426900] 8b 77 08                                     mov     esi, [edi+8]
000A61AB [00426903] 80 7c 24 2c 00                               cmp     byte ptr [esp+2Ch], 0
000A61B0 [00426908] 74 24                                        jz      short near ptr unk_42692E ; game-relative-target=0x000A61D6
000A61B2 [0042690A] 8b 4d 70                                     mov     ecx, [ebp+70h]
000A61B5 [0042690D] 8a 41 04                                     mov     al, [ecx+4]
000A61B8 [00426910] 3c 14                                        cmp     al, 14h
000A61BA [00426912] 75 04                                        jnz     short near ptr unk_426918 ; game-relative-target=0x000A61C0
000A61BC [00426914] 6a 1f                                        push    1Fh
000A61BE [00426916] eb 0a                                        jmp     short near ptr unk_426922 ; game-relative-target=0x000A61CA
000A61C0 [00426918] 3c 16                                        cmp     al, 16h
000A61C2 [0042691A] 74 04                                        jz      short near ptr unk_426920 ; game-relative-target=0x000A61C8
000A61C4 [0042691C] 3c 17                                        cmp     al, 17h
000A61C6 [0042691E] 75 0e                                        jnz     short near ptr unk_42692E ; game-relative-target=0x000A61D6
000A61C8 [00426920] 6a 20                                        push    20h ; ' '
000A61CA [00426922] b8 20 37 45 00                               mov     eax, 453720h
000A61CF [00426927] ff d0                                        call    eax
000A61D1 [00426929] 5a                                           pop     edx
000A61D2 [0042692A] 8b d8                                        mov     ebx, eax
000A61D4 [0042692C] eb 25                                        jmp     short near ptr unk_426953 ; game-relative-target=0x000A61FB
000A61D6 [0042692E] 8b 9e f8 00 00 00                            mov     ebx, [esi+0F8h]
000A61DC [00426934] 85 db                                        test    ebx, ebx
000A61DE [00426936] 74 4b                                        jz      short near ptr unk_426983 ; game-relative-target=0x000A622B
000A61E0 [00426938] 80 7c 24 2c 00                               cmp     byte ptr [esp+2Ch], 0
000A61E5 [0042693D] 74 0b                                        jz      short near ptr unk_42694A ; game-relative-target=0x000A61F2
000A61E7 [0042693F] 8a 43 54                                     mov     al, [ebx+54h]
000A61EA [00426942] 3c 07                                        cmp     al, 7
000A61EC [00426944] 74 04                                        jz      short near ptr unk_42694A ; game-relative-target=0x000A61F2
000A61EE [00426946] 3c 08                                        cmp     al, 8
000A61F0 [00426948] 75 39                                        jnz     short near ptr unk_426983 ; game-relative-target=0x000A622B
000A61F2 [0042694A] 80 bb 84 00 00 00 00                         cmp     byte ptr [ebx+84h], 0
000A61F9 [00426951] 74 30                                        jz      short near ptr unk_426983 ; game-relative-target=0x000A622B
000A61FB [00426953] 8d 8e 80 00 00 00                            lea     ecx, [esi+80h]
000A6201 [00426959] 8b 01                                        mov     eax, [ecx]
000A6203 [0042695B] 3b 41 18                                     cmp     eax, [ecx+18h]
000A6206 [0042695E] 7d 03                                        jge     short near ptr unk_426963 ; game-relative-target=0x000A620B
000A6208 [00426960] 8b 41 18                                     mov     eax, [ecx+18h]
000A620B [00426963] 85 c0                                        test    eax, eax
000A620D [00426965] 74 0a                                        jz      short near ptr unk_426971 ; game-relative-target=0x000A6219
000A620F [00426967] 2b 44 24 24                                  sub     eax, [esp+24h]
000A6213 [0042696B] 85 c0                                        test    eax, eax
000A6215 [0042696D] 7d 02                                        jge     short near ptr unk_426971 ; game-relative-target=0x000A6219
000A6217 [0042696F] 33 c0                                        xor     eax, eax
000A6219 [00426971] 2b 44 24 20                                  sub     eax, [esp+20h]
000A621D [00426975] f7 d8                                        neg     eax
000A621F [00426977] 8b 54 24 28                                  mov     edx, [esp+28h]
000A6223 [0042697B] 3b c2                                        cmp     eax, edx
000A6225 [0042697D] 7e 02                                        jle     short near ptr unk_426981 ; game-relative-target=0x000A6229
000A6227 [0042697F] 8b c2                                        mov     eax, edx
000A6229 [00426981] 85 c0                                        test    eax, eax
000A622B [00426983] 0f 8e 96 00 00 00                            jle     near ptr unk_426A1F ; game-relative-target=0x000A62C7
000A6231 [00426989] 89 44 24 04                                  mov     [esp+4], eax
000A6235 [0042698D] 57                                           push    edi
000A6236 [0042698E] 8b 7b 54                                     mov     edi, [ebx+54h]
000A6239 [00426991] 83 ff 04                                     cmp     edi, 4
000A623C [00426994] 7e 05                                        jle     short near ptr unk_42699B ; game-relative-target=0x000A6243
000A623E [00426996] ff 76 58                                     push    dword ptr [esi+58h]
000A6241 [00426999] eb 03                                        jmp     short near ptr unk_42699E ; game-relative-target=0x000A6246
000A6243 [0042699B] ff 76 50                                     push    dword ptr [esi+50h]
000A6246 [0042699E] b8 00 d3 41 00                               mov     eax, 41D300h
000A624B [004269A3] ff d0                                        call    eax
000A624D [004269A5] 5a                                           pop     edx
000A624E [004269A6] 83 c0 2d                                     add     eax, 2Dh ; '-'
000A6251 [004269A9] 83 f8 46                                     cmp     eax, 46h ; 'F'
000A6254 [004269AC] 7d 02                                        jge     short near ptr unk_4269B0 ; game-relative-target=0x000A6258
000A6256 [004269AE] b0 46                                        mov     al, 46h ; 'F'
000A6258 [004269B0] 50                                           push    eax
000A6259 [004269B1] 57                                           push    edi
000A625A [004269B2] 8b ce                                        mov     ecx, esi
000A625C [004269B4] b8 40 c9 44 00                               mov     eax, 44C940h
000A6261 [004269B9] ff d0                                        call    eax
000A6263 [004269BB] d1 e8                                        shr     eax, 1
000A6265 [004269BD] 05 e8 03 00 00                               add     eax, 3E8h
000A626A [004269C2] 5a                                           pop     edx
000A626B [004269C3] 0f af c2                                     imul    eax, edx
000A626E [004269C6] 83 ff 04                                     cmp     edi, 4
000A6271 [004269C9] 7e 10                                        jle     short near ptr unk_4269DB ; game-relative-target=0x000A6283
000A6273 [004269CB] 0f b6 4b 04                                  movzx   ecx, byte ptr [ebx+4]
000A6277 [004269CF] 83 e9 17                                     sub     ecx, 17h
000A627A [004269D2] 0f b6 91 e7 d8 45 00                         movzx   edx, byte ptr [ecx+45D8E7h]
000A6281 [004269D9] eb 03                                        jmp     short near ptr unk_4269DE ; game-relative-target=0x000A6286
000A6283 [004269DB] 8b 53 64                                     mov     edx, [ebx+64h]
000A6286 [004269DE] 0f af c2                                     imul    eax, edx
000A6289 [004269E1] c1 e8 0a                                     shr     eax, 0Ah
000A628C [004269E4] 0f af 44 24 08                               imul    eax, [esp+8]
000A6291 [004269E9] 83 ff 04                                     cmp     edi, 4
000A6294 [004269EC] 74 10                                        jz      short near ptr unk_4269FE ; game-relative-target=0x000A62A6
000A6296 [004269EE] 8b f8                                        mov     edi, eax
000A6298 [004269F0] 8b ce                                        mov     ecx, esi
000A629A [004269F2] b8 00 cd 44 00                               mov     eax, 44CD00h
000A629F [004269F7] ff d0                                        call    eax
000A62A1 [004269F9] 83 e8 04                                     sub     eax, 4
000A62A4 [004269FC] f7 d8                                        neg     eax
000A62A6 [004269FE] 0f af c7                                     imul    eax, edi
000A62A9 [00426A01] b9 28 00 00 00                               mov     ecx, 28h ; '('
000A62AE [00426A06] 99                                           cdq
000A62AF [00426A07] f7 f1                                        div     ecx
000A62B1 [00426A09] 8b f8                                        mov     edi, eax
000A62B3 [00426A0B] ff 75 6c                                     push    dword ptr [ebp+6Ch]
000A62B6 [00426A0E] 8b cb                                        mov     ecx, ebx
000A62B8 [00426A10] b8 00 31 0a 00                               mov     eax, 0A3100h
000A62BD [00426A15] ff d0                                        call    eax
000A62BF [00426A17] f7 ef                                        imul    edi
000A62C1 [00426A19] d1 e2                                        shl     edx, 1
000A62C3 [00426A1B] 5f                                           pop     edi
000A62C4 [00426A1C] 01 14 24                                     add     [esp], edx
000A62C7 [00426A1F] 8b 3f                                        mov     edi, [edi]
000A62C9 [00426A21] 85 ff                                        test    edi, edi
000A62CB [00426A23] 0f 85 d7 fe ff ff                            jnz     near ptr unk_426900 ; game-relative-target=0x000A61A8
000A62D1 [00426A29] 58                                           pop     eax
000A62D2 [00426A2A] 59                                           pop     ecx
000A62D3 [00426A2B] 5f                                           pop     edi
000A62D4 [00426A2C] 5e                                           pop     esi
000A62D5 [00426A2D] ba 40 1f 00 00                               mov     edx, 1F40h
000A62DA [00426A32] 3b c2                                        cmp     eax, edx
000A62DC [00426A34] 7e 02                                        jle     short near ptr unk_426A38 ; game-relative-target=0x000A62E0
000A62DE [00426A36] 8b c2                                        mov     eax, edx
000A62E0 [00426A38] 01 44 24 0c                                  add     [esp+0Ch], eax
000A62E4 [00426A3C] 8b 3f                                        mov     edi, [edi]
000A62E6 [00426A3E] e9 9b fd ff ff                               jmp     near ptr unk_4267DE ; game-relative-target=0x000A6086
000A62EB [00426A43] 8b 44 24 0c                                  mov     eax, [esp+0Ch]
000A62EF [00426A47] 83 c4 20                                     add     esp, 20h ; ' '
000A62F2 [00426A4A] 5a                                           pop     edx
000A62F3 [00426A4B] 5b                                           pop     ebx
000A62F4 [00426A4C] 5d                                           pop     ebp
000A62F5 [00426A4D] 5f                                           pop     edi
000A62F6 [00426A4E] 5e                                           pop     esi
000A62F7 [00426A4F] 3b c2                                        cmp     eax, edx
000A62F9 [00426A51] 7e 02                                        jle     short near ptr unk_426A55 ; game-relative-target=0x000A62FD
000A62FB [00426A53] 8b c2                                        mov     eax, edx
000A62FD [00426A55] ba 70 17 00 00                               mov     edx, 1770h
000A6302 [00426A5A] 3b c2                                        cmp     eax, edx
000A6304 [00426A5C] 7d 02                                        jge     short near ptr unk_426A60 ; game-relative-target=0x000A6308
000A6306 [00426A5E] 8b c2                                        mov     eax, edx
000A6308 [00426A60] c2 04 00                                     retn    4
