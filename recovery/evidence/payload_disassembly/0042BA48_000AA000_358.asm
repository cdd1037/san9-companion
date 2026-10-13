; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042BA48; baseline game VA=0x000AA000; size=856
; Relative branch annotations use the baseline game destination.
000AA000 [0042BA48] 56                                           push    esi
000AA001 [0042BA49] 57                                           push    edi
000AA002 [0042BA4A] 53                                           push    ebx
000AA003 [0042BA4B] 55                                           push    ebp
000AA004 [0042BA4C] 8d 5c 24 2c                                  lea     ebx, [esp+2Ch]
000AA008 [0042BA50] b9 07 00 00 00                               mov     ecx, 7
000AA00D [0042BA55] 99                                           cdq
000AA00E [0042BA56] f7 f1                                        div     ecx
000AA010 [0042BA58] 81 ec c0 04 00 00                            sub     esp, 4C0h
000AA016 [0042BA5E] 89 44 24 64                                  mov     [esp+64h], eax
000AA01A [0042BA62] 89 74 24 68                                  mov     [esp+68h], esi
000AA01E [0042BA66] 8b 46 38                                     mov     eax, [esi+38h]
000AA021 [0042BA69] 89 44 24 6c                                  mov     [esp+6Ch], eax
000AA025 [0042BA6D] 8b a8 bc 00 00 00                            mov     ebp, [eax+0BCh]
000AA02B [0042BA73] 8b 8d f4 00 00 00                            mov     ecx, [ebp+0F4h]
000AA031 [0042BA79] 8b 41 64                                     mov     eax, [ecx+64h]
000AA034 [0042BA7C] 8b 48 44                                     mov     ecx, [eax+44h]
000AA037 [0042BA7F] 89 4c 24 70                                  mov     [esp+70h], ecx
000AA03B [0042BA83] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000AA03F [0042BA87] b8 70 d7 46 00                               mov     eax, 46D770h
000AA044 [0042BA8C] ff d0                                        call    eax
000AA046 [0042BA8E] 8b c8                                        mov     ecx, eax
000AA048 [0042BA90] 53                                           push    ebx
000AA049 [0042BA91] b8 00 f2 46 00                               mov     eax, 46F200h
000AA04E [0042BA96] ff d0                                        call    eax
000AA050 [0042BA98] 8b 53 04                                     mov     edx, [ebx+4]
000AA053 [0042BA9B] 8b 4a 08                                     mov     ecx, [edx+8]
000AA056 [0042BA9E] 0f b6 49 04                                  movzx   ecx, byte ptr [ecx+4]
000AA05A [0042BAA2] 83 4c ce 64 01                               or      dword ptr [esi+ecx*8+64h], 1
000AA05F [0042BAA7] 89 6c ce 68                                  mov     [esi+ecx*8+68h], ebp
000AA063 [0042BAAB] 8b 12                                        mov     edx, [edx]
000AA065 [0042BAAD] 85 d2                                        test    edx, edx
000AA067 [0042BAAF] 75 ea                                        jnz     short near ptr unk_42BA9B ; game-relative-target=0x000AA053
000AA069 [0042BAB1] 8b 46 38                                     mov     eax, [esi+38h]
000AA06C [0042BAB4] 83 b8 84 00 00 00 03                         cmp     dword ptr [eax+84h], 3
000AA073 [0042BABB] 7f 04                                        jg      short near ptr unk_42BAC1 ; game-relative-target=0x000AA079
000AA075 [0042BABD] 33 ff                                        xor     edi, edi
000AA077 [0042BABF] eb 44                                        jmp     short near ptr unk_42BB05 ; game-relative-target=0x000AA0BD
000AA079 [0042BAC1] 85 ff                                        test    edi, edi
000AA07B [0042BAC3] 74 40                                        jz      short near ptr unk_42BB05 ; game-relative-target=0x000AA0BD
000AA07D [0042BAC5] 8b 5e 48                                     mov     ebx, [esi+48h]
000AA080 [0042BAC8] 8b 6b 08                                     mov     ebp, [ebx+8]
000AA083 [0042BACB] 83 c5 78                                     add     ebp, 78h ; 'x'
000AA086 [0042BACE] 8b 45 0c                                     mov     eax, [ebp+0Ch]
000AA089 [0042BAD1] 83 e8 04                                     sub     eax, 4
000AA08C [0042BAD4] 83 f8 04                                     cmp     eax, 4
000AA08F [0042BAD7] 72 03                                        jb      short near ptr unk_42BADC ; game-relative-target=0x000AA094
000AA091 [0042BAD9] 4f                                           dec     edi
000AA092 [0042BADA] eb 23                                        jmp     short near ptr unk_42BAFF ; game-relative-target=0x000AA0B7
000AA094 [0042BADC] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000AA098 [0042BAE0] 55                                           push    ebp
000AA099 [0042BAE1] b8 80 ee 46 00                               mov     eax, 46EE80h
000AA09E [0042BAE6] ff d0                                        call    eax
000AA0A0 [0042BAE8] 8b 45 44                                     mov     eax, [ebp+44h]
000AA0A3 [0042BAEB] 8b 55 04                                     mov     edx, [ebp+4]
000AA0A6 [0042BAEE] 8b 4a 08                                     mov     ecx, [edx+8]
000AA0A9 [0042BAF1] 0f b6 49 04                                  movzx   ecx, byte ptr [ecx+4]
000AA0AD [0042BAF5] 89 44 ce 68                                  mov     [esi+ecx*8+68h], eax
000AA0B1 [0042BAF9] 8b 12                                        mov     edx, [edx]
000AA0B3 [0042BAFB] 85 d2                                        test    edx, edx
000AA0B5 [0042BAFD] 75 ef                                        jnz     short near ptr unk_42BAEE ; game-relative-target=0x000AA0A6
000AA0B7 [0042BAFF] 8b 1b                                        mov     ebx, [ebx]
000AA0B9 [0042BB01] 85 db                                        test    ebx, ebx
000AA0BB [0042BB03] 75 c3                                        jnz     short near ptr unk_42BAC8 ; game-relative-target=0x000AA080
000AA0BD [0042BB05] 89 7c 24 60                                  mov     [esp+60h], edi
000AA0C1 [0042BB09] 39 7c 24 64                                  cmp     [esp+64h], edi
000AA0C5 [0042BB0D] 0f 8e 73 02 00 00                            jle     near ptr unk_42BD86 ; game-relative-target=0x000AA33E
000AA0CB [0042BB13] 83 7c 24 2c 08                               cmp     dword ptr [esp+2Ch], 8
000AA0D0 [0042BB18] 0f 8e 68 02 00 00                            jle     near ptr unk_42BD86 ; game-relative-target=0x000AA33E
000AA0D6 [0042BB1E] 83 c8 ff                                     or      eax, 0FFFFFFFFh
000AA0D9 [0042BB21] 33 db                                        xor     ebx, ebx
000AA0DB [0042BB23] bd 32 00 00 00                               mov     ebp, 32h ; '2'
000AA0E0 [0042BB28] 8d b4 24 98 00 00 00                         lea     esi, [esp+98h]
000AA0E7 [0042BB2F] 8b d6                                        mov     edx, esi
000AA0E9 [0042BB31] 89 1a                                        mov     [edx], ebx
000AA0EB [0042BB33] 89 5a 04                                     mov     [edx+4], ebx
000AA0EE [0042BB36] 89 42 08                                     mov     [edx+8], eax
000AA0F1 [0042BB39] 89 42 0c                                     mov     [edx+0Ch], eax
000AA0F4 [0042BB3C] 83 c2 10                                     add     edx, 10h
000AA0F7 [0042BB3F] 4d                                           dec     ebp
000AA0F8 [0042BB40] 75 ef                                        jnz     short near ptr unk_42BB31 ; game-relative-target=0x000AA0E9
000AA0FA [0042BB42] 8b cc                                        mov     ecx, esp
000AA0FC [0042BB44] b8 70 d7 46 00                               mov     eax, 46D770h
000AA101 [0042BB49] ff d0                                        call    eax
000AA103 [0042BB4B] bd 58 db 24 01                               mov     ebp, 124DB58h
000AA108 [0042BB50] 55                                           push    ebp
000AA109 [0042BB51] b8 20 58 40 00                               mov     eax, 405820h
000AA10E [0042BB56] ff d0                                        call    eax
000AA110 [0042BB58] 59                                           pop     ecx
000AA111 [0042BB59] 85 c0                                        test    eax, eax
000AA113 [0042BB5B] 74 64                                        jz      short near ptr unk_42BBC1 ; game-relative-target=0x000AA179
000AA115 [0042BB5D] 3b 6c 24 70                                  cmp     ebp, [esp+70h]
000AA119 [0042BB61] 75 03                                        jnz     short near ptr unk_42BB66 ; game-relative-target=0x000AA11E
000AA11B [0042BB63] 80 0e 04                                     or      byte ptr [esi], 4
000AA11E [0042BB66] 8b 11                                        mov     edx, [ecx]
000AA120 [0042BB68] ff 52 30                                     call    dword ptr [edx+30h]
000AA123 [0042BB6B] 3b 44 24 6c                                  cmp     eax, [esp+6Ch]
000AA127 [0042BB6F] 75 50                                        jnz     short near ptr unk_42BBC1 ; game-relative-target=0x000AA179
000AA129 [0042BB71] 8b d4                                        mov     edx, esp
000AA12B [0042BB73] 6a 00                                        push    0
000AA12D [0042BB75] 6a 00                                        push    0
000AA12F [0042BB77] 52                                           push    edx
000AA130 [0042BB78] 8b cd                                        mov     ecx, ebp
000AA132 [0042BB7A] b8 60 b0 43 00                               mov     eax, 43B060h
000AA137 [0042BB7F] ff d0                                        call    eax
000AA139 [0042BB81] 85 c0                                        test    eax, eax
000AA13B [0042BB83] 74 3c                                        jz      short near ptr unk_42BBC1 ; game-relative-target=0x000AA179
000AA13D [0042BB85] 8b 7c 24 04                                  mov     edi, [esp+4]
000AA141 [0042BB89] 8b 4f 08                                     mov     ecx, [edi+8]
000AA144 [0042BB8C] 3b 4c 24 70                                  cmp     ecx, [esp+70h]
000AA148 [0042BB90] 75 03                                        jnz     short near ptr unk_42BB95 ; game-relative-target=0x000AA14D
000AA14A [0042BB92] 80 0e 08                                     or      byte ptr [esi], 8
000AA14D [0042BB95] 8b 11                                        mov     edx, [ecx]
000AA14F [0042BB97] ff 52 30                                     call    dword ptr [edx+30h]
000AA152 [0042BB9A] 3b 44 24 6c                                  cmp     eax, [esp+6Ch]
000AA156 [0042BB9E] 74 05                                        jz      short near ptr unk_42BBA5 ; game-relative-target=0x000AA15D
000AA158 [0042BBA0] 80 0e 01                                     or      byte ptr [esi], 1
000AA15B [0042BBA3] eb 16                                        jmp     short near ptr unk_42BBBB ; game-relative-target=0x000AA173
000AA15D [0042BBA5] 8b 46 04                                     mov     eax, [esi+4]
000AA160 [0042BBA8] 83 f8 08                                     cmp     eax, 8
000AA163 [0042BBAB] 7d 0e                                        jge     short near ptr unk_42BBBB ; game-relative-target=0x000AA173
000AA165 [0042BBAD] 8b 4f 08                                     mov     ecx, [edi+8]
000AA168 [0042BBB0] 8a 51 04                                     mov     dl, [ecx+4]
000AA16B [0042BBB3] 88 54 30 08                                  mov     [eax+esi+8], dl
000AA16F [0042BBB7] 40                                           inc     eax
000AA170 [0042BBB8] 89 46 04                                     mov     [esi+4], eax
000AA173 [0042BBBB] 8b 3f                                        mov     edi, [edi]
000AA175 [0042BBBD] 85 ff                                        test    edi, edi
000AA177 [0042BBBF] 75 c8                                        jnz     short near ptr unk_42BB89 ; game-relative-target=0x000AA141
000AA179 [0042BBC1] 8b 46 04                                     mov     eax, [esi+4]
000AA17C [0042BBC4] 8a 26                                        mov     ah, [esi]
000AA17E [0042BBC6] f6 c4 01                                     test    ah, 1
000AA181 [0042BBC9] 75 03                                        jnz     short near ptr unk_42BBCE ; game-relative-target=0x000AA186
000AA183 [0042BBCB] 80 cc 20                                     or      ah, 20h ; ' '
000AA186 [0042BBCE] 89 45 08                                     mov     [ebp+8], eax
000AA189 [0042BBD1] 88 5e 02                                     mov     [esi+2], bl
000AA18C [0042BBD4] 81 c5 f0 01 00 00                            add     ebp, 1F0h
000AA192 [0042BBDA] 83 c6 10                                     add     esi, 10h
000AA195 [0042BBDD] 43                                           inc     ebx
000AA196 [0042BBDE] 83 fb 32                                     cmp     ebx, 32h ; '2'
000AA199 [0042BBE1] 0f 8c 69 ff ff ff                            jl      near ptr unk_42BB50 ; game-relative-target=0x000AA108
000AA19F [0042BBE7] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000AA1A3 [0042BBEB] 6a 01                                        push    1
000AA1A5 [0042BBED] 68 60 e9 46 00                               push    46E960h
000AA1AA [0042BBF2] b8 10 f6 46 00                               mov     eax, 46F610h
000AA1AF [0042BBF7] ff d0                                        call    eax
000AA1B1 [0042BBF9] 8b 54 24 70                                  mov     edx, [esp+70h]
000AA1B5 [0042BBFD] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000AA1B9 [0042BC01] 52                                           push    edx
000AA1BA [0042BC02] b8 50 ee 46 00                               mov     eax, 46EE50h
000AA1BF [0042BC07] ff d0                                        call    eax
000AA1C1 [0042BC09] 8d 4c 24 78                                  lea     ecx, [esp+78h]
000AA1C5 [0042BC0D] b8 70 d7 46 00                               mov     eax, 46D770h
000AA1CA [0042BC12] ff d0                                        call    eax
000AA1CC [0042BC14] 8d 4c 24 40                                  lea     ecx, [esp+40h]
000AA1D0 [0042BC18] b8 70 d7 46 00                               mov     eax, 46D770h
000AA1D5 [0042BC1D] ff d0                                        call    eax
000AA1D7 [0042BC1F] 8d 54 24 20                                  lea     edx, [esp+20h]
000AA1DB [0042BC23] 8b c8                                        mov     ecx, eax
000AA1DD [0042BC25] 52                                           push    edx
000AA1DE [0042BC26] b8 00 f2 46 00                               mov     eax, 46F200h
000AA1E3 [0042BC2B] ff d0                                        call    eax
000AA1E5 [0042BC2D] 8b 7c 24 24                                  mov     edi, [esp+24h]
000AA1E9 [0042BC31] 8b 6f 08                                     mov     ebp, [edi+8]
000AA1EC [0042BC34] 8d 4c 24 40                                  lea     ecx, [esp+40h]
000AA1F0 [0042BC38] 6a 00                                        push    0
000AA1F2 [0042BC3A] 55                                           push    ebp
000AA1F3 [0042BC3B] b8 f0 5c 41 00                               mov     eax, 415CF0h
000AA1F8 [0042BC40] ff d0                                        call    eax
000AA1FA [0042BC42] 85 c0                                        test    eax, eax
000AA1FC [0042BC44] 0f 84 0c 01 00 00                            jz      near ptr unk_42BD56 ; game-relative-target=0x000AA30E
000AA202 [0042BC4A] 0f b6 45 04                                  movzx   eax, byte ptr [ebp+4]
000AA206 [0042BC4E] c1 e0 04                                     shl     eax, 4
000AA209 [0042BC51] 8d 94 04 a0 00 00 00                         lea     edx, [esp+eax+0A0h]
000AA210 [0042BC58] 8a 42 f8                                     mov     al, [edx-8]
000AA213 [0042BC5B] a8 01                                        test    al, 1
000AA215 [0042BC5D] 0f 84 04 01 00 00                            jz      near ptr unk_42BD67 ; game-relative-target=0x000AA31F
000AA21B [0042BC63] a8 0c                                        test    al, 0Ch
000AA21D [0042BC65] 0f 85 fc 00 00 00                            jnz     near ptr unk_42BD67 ; game-relative-target=0x000AA31F
000AA223 [0042BC6B] 8b 42 fc                                     mov     eax, [edx-4]
000AA226 [0042BC6E] 85 c0                                        test    eax, eax
000AA228 [0042BC70] 0f 8e e0 00 00 00                            jle     near ptr unk_42BD56 ; game-relative-target=0x000AA30E
000AA22E [0042BC76] 8b cc                                        mov     ecx, esp
000AA230 [0042BC78] 50                                           push    eax
000AA231 [0042BC79] 52                                           push    edx
000AA232 [0042BC7A] b8 c0 ef 46 00                               mov     eax, 46EFC0h
000AA237 [0042BC7F] ff d0                                        call    eax
000AA239 [0042BC81] 8b cc                                        mov     ecx, esp
000AA23B [0042BC83] 8d 54 24 40                                  lea     edx, [esp+40h]
000AA23F [0042BC87] 52                                           push    edx
000AA240 [0042BC88] b8 d0 f6 46 00                               mov     eax, 46F6D0h
000AA245 [0042BC8D] ff d0                                        call    eax
000AA247 [0042BC8F] 85 c0                                        test    eax, eax
000AA249 [0042BC91] 0f 84 bf 00 00 00                            jz      near ptr unk_42BD56 ; game-relative-target=0x000AA30E
000AA24F [0042BC97] 83 f8 03                                     cmp     eax, 3
000AA252 [0042BC9A] 7c 0e                                        jl      short near ptr unk_42BCAA ; game-relative-target=0x000AA262
000AA254 [0042BC9C] 8b dc                                        mov     ebx, esp
000AA256 [0042BC9E] 55                                           push    ebp
000AA257 [0042BC9F] 8b cb                                        mov     ecx, ebx
000AA259 [0042BCA1] b8 70 82 51 00                               mov     eax, 518270h
000AA25E [0042BCA6] ff d0                                        call    eax
000AA260 [0042BCA8] eb 6c                                        jmp     short near ptr unk_42BD16 ; game-relative-target=0x000AA2CE
000AA262 [0042BCAA] 8d 5c 24 78                                  lea     ebx, [esp+78h]
000AA266 [0042BCAE] 8b 74 24 04                                  mov     esi, [esp+4]
000AA26A [0042BCB2] 8b 56 08                                     mov     edx, [esi+8]
000AA26D [0042BCB5] 8d 4c 24 40                                  lea     ecx, [esp+40h]
000AA271 [0042BCB9] 6a 00                                        push    0
000AA273 [0042BCBB] 52                                           push    edx
000AA274 [0042BCBC] b8 f0 5c 41 00                               mov     eax, 415CF0h
000AA279 [0042BCC1] ff d0                                        call    eax
000AA27B [0042BCC3] 85 c0                                        test    eax, eax
000AA27D [0042BCC5] 74 47                                        jz      short near ptr unk_42BD0E ; game-relative-target=0x000AA2C6
000AA27F [0042BCC7] 8b 4e 08                                     mov     ecx, [esi+8]
000AA282 [0042BCCA] 0f b6 41 04                                  movzx   eax, byte ptr [ecx+4]
000AA286 [0042BCCE] c1 e0 04                                     shl     eax, 4
000AA289 [0042BCD1] 8d 94 04 a0 00 00 00                         lea     edx, [esp+eax+0A0h]
000AA290 [0042BCD8] f6 42 f8 0c                                  test    byte ptr [edx-8], 0Ch
000AA294 [0042BCDC] 75 30                                        jnz     short near ptr unk_42BD0E ; game-relative-target=0x000AA2C6
000AA296 [0042BCDE] 8b 42 fc                                     mov     eax, [edx-4]
000AA299 [0042BCE1] 8b cb                                        mov     ecx, ebx
000AA29B [0042BCE3] 50                                           push    eax
000AA29C [0042BCE4] 52                                           push    edx
000AA29D [0042BCE5] b8 c0 ef 46 00                               mov     eax, 46EFC0h
000AA2A2 [0042BCEA] ff d0                                        call    eax
000AA2A4 [0042BCEC] 8d 54 24 40                                  lea     edx, [esp+40h]
000AA2A8 [0042BCF0] 52                                           push    edx
000AA2A9 [0042BCF1] 8b cb                                        mov     ecx, ebx
000AA2AB [0042BCF3] b8 d0 f6 46 00                               mov     eax, 46F6D0h
000AA2B0 [0042BCF8] ff d0                                        call    eax
000AA2B2 [0042BCFA] 83 f8 03                                     cmp     eax, 3
000AA2B5 [0042BCFD] 7e 0f                                        jle     short near ptr unk_42BD0E ; game-relative-target=0x000AA2C6
000AA2B7 [0042BCFF] 8b 56 08                                     mov     edx, [esi+8]
000AA2BA [0042BD02] 52                                           push    edx
000AA2BB [0042BD03] 8b cb                                        mov     ecx, ebx
000AA2BD [0042BD05] b8 70 82 51 00                               mov     eax, 518270h
000AA2C2 [0042BD0A] ff d0                                        call    eax
000AA2C4 [0042BD0C] eb 08                                        jmp     short near ptr unk_42BD16 ; game-relative-target=0x000AA2CE
000AA2C6 [0042BD0E] 8b 36                                        mov     esi, [esi]
000AA2C8 [0042BD10] 85 f6                                        test    esi, esi
000AA2CA [0042BD12] 75 9e                                        jnz     short near ptr unk_42BCB2 ; game-relative-target=0x000AA26A
000AA2CC [0042BD14] eb 40                                        jmp     short near ptr unk_42BD56 ; game-relative-target=0x000AA30E
000AA2CE [0042BD16] 53                                           push    ebx
000AA2CF [0042BD17] b8 10 78 48 00                               mov     eax, 487810h
000AA2D4 [0042BD1C] ff d0                                        call    eax
000AA2D6 [0042BD1E] 59                                           pop     ecx
000AA2D7 [0042BD1F] 85 c0                                        test    eax, eax
000AA2D9 [0042BD21] 74 33                                        jz      short near ptr unk_42BD56 ; game-relative-target=0x000AA30E
000AA2DB [0042BD23] 8b 51 04                                     mov     edx, [ecx+4]
000AA2DE [0042BD26] 8b 6c 24 68                                  mov     ebp, [esp+68h]
000AA2E2 [0042BD2A] 8b 4a 08                                     mov     ecx, [edx+8]
000AA2E5 [0042BD2D] 0f b6 49 04                                  movzx   ecx, byte ptr [ecx+4]
000AA2E9 [0042BD31] 89 44 cd 68                                  mov     [ebp+ecx*8+68h], eax
000AA2ED [0042BD35] 8b 12                                        mov     edx, [edx]
000AA2EF [0042BD37] 85 d2                                        test    edx, edx
000AA2F1 [0042BD39] 75 ef                                        jnz     short near ptr unk_42BD2A ; game-relative-target=0x000AA2E2
000AA2F3 [0042BD3B] 8b 44 24 60                                  mov     eax, [esp+60h]
000AA2F7 [0042BD3F] 40                                           inc     eax
000AA2F8 [0042BD40] 89 44 24 60                                  mov     [esp+60h], eax
000AA2FC [0042BD44] 3b 44 24 64                                  cmp     eax, [esp+64h]
000AA300 [0042BD48] 7d 1d                                        jge     short near ptr unk_42BD67 ; game-relative-target=0x000AA31F
000AA302 [0042BD4A] 8d 4c 24 40                                  lea     ecx, [esp+40h]
000AA306 [0042BD4E] 53                                           push    ebx
000AA307 [0042BD4F] b8 80 ee 46 00                               mov     eax, 46EE80h
000AA30C [0042BD54] ff d0                                        call    eax
000AA30E [0042BD56] 83 7c 24 4c 08                               cmp     dword ptr [esp+4Ch], 8
000AA313 [0042BD5B] 7e 0a                                        jle     short near ptr unk_42BD67 ; game-relative-target=0x000AA31F
000AA315 [0042BD5D] 8b 3f                                        mov     edi, [edi]
000AA317 [0042BD5F] 85 ff                                        test    edi, edi
000AA319 [0042BD61] 0f 85 ca fe ff ff                            jnz     near ptr unk_42BC31 ; game-relative-target=0x000AA1E9
000AA31F [0042BD67] 8d 4c 24 78                                  lea     ecx, [esp+78h]
000AA323 [0042BD6B] b8 90 d7 46 00                               mov     eax, 46D790h
000AA328 [0042BD70] ff d0                                        call    eax
000AA32A [0042BD72] 8d 4c 24 40                                  lea     ecx, [esp+40h]
000AA32E [0042BD76] b8 90 d7 46 00                               mov     eax, 46D790h
000AA333 [0042BD7B] ff d0                                        call    eax
000AA335 [0042BD7D] 8b cc                                        mov     ecx, esp
000AA337 [0042BD7F] b8 90 d7 46 00                               mov     eax, 46D790h
000AA33C [0042BD84] ff d0                                        call    eax
000AA33E [0042BD86] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000AA342 [0042BD8A] b8 90 d7 46 00                               mov     eax, 46D790h
000AA347 [0042BD8F] ff d0                                        call    eax
000AA349 [0042BD91] 8b 44 24 60                                  mov     eax, [esp+60h]
000AA34D [0042BD95] 81 c4 c0 04 00 00                            add     esp, 4C0h
000AA353 [0042BD9B] 5d                                           pop     ebp
000AA354 [0042BD9C] 5b                                           pop     ebx
000AA355 [0042BD9D] 5f                                           pop     edi
000AA356 [0042BD9E] 5e                                           pop     esi
000AA357 [0042BD9F] c3                                           retn
