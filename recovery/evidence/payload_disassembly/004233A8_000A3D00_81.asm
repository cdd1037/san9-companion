; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004233A8; baseline game VA=0x000A3D00; size=129
; Relative branch annotations use the baseline game destination.
000A3D00 [004233A8] 56                                           push    esi
000A3D01 [004233A9] 57                                           push    edi
000A3D02 [004233AA] 53                                           push    ebx
000A3D03 [004233AB] 55                                           push    ebp
000A3D04 [004233AC] 8b f1                                        mov     esi, ecx
000A3D06 [004233AE] 83 ec 20                                     sub     esp, 20h ; ' '
000A3D09 [004233B1] 8b cc                                        mov     ecx, esp
000A3D0B [004233B3] b8 70 c9 46 00                               mov     eax, 46C970h
000A3D10 [004233B8] ff d0                                        call    eax
000A3D12 [004233BA] 56                                           push    esi
000A3D13 [004233BB] 50                                           push    eax
000A3D14 [004233BC] b8 40 5c 47 00                               mov     eax, 475C40h
000A3D19 [004233C1] ff d0                                        call    eax
000A3D1B [004233C3] bb ff ff ff 7f                               mov     ebx, 7FFFFFFFh
000A3D20 [004233C8] 8b eb                                        mov     ebp, ebx
000A3D22 [004233CA] 8b 7c 24 04                                  mov     edi, [esp+4]
000A3D26 [004233CE] 85 ff                                        test    edi, edi
000A3D28 [004233D0] 74 34                                        jz      short near ptr unk_423406 ; game-relative-target=0x000A3D5E
000A3D2A [004233D2] 8b 4f 08                                     mov     ecx, [edi+8]
000A3D2D [004233D5] 80 79 06 05                                  cmp     byte ptr [ecx+6], 5
000A3D31 [004233D9] 75 27                                        jnz     short near ptr unk_423402 ; game-relative-target=0x000A3D5A
000A3D33 [004233DB] 56                                           push    esi
000A3D34 [004233DC] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A3D39 [004233E1] ff d0                                        call    eax
000A3D3B [004233E3] 50                                           push    eax
000A3D3C [004233E4] 56                                           push    esi
000A3D3D [004233E5] 8b 4f 08                                     mov     ecx, [edi+8]
000A3D40 [004233E8] b8 80 57 43 00                               mov     eax, 435780h
000A3D45 [004233ED] ff d0                                        call    eax
000A3D47 [004233EF] 85 c0                                        test    eax, eax
000A3D49 [004233F1] 58                                           pop     eax
000A3D4A [004233F2] 74 08                                        jz      short near ptr unk_4233FC ; game-relative-target=0x000A3D54
000A3D4C [004233F4] 3b c3                                        cmp     eax, ebx
000A3D4E [004233F6] 7d 02                                        jge     short near ptr unk_4233FA ; game-relative-target=0x000A3D52
000A3D50 [004233F8] 8b d8                                        mov     ebx, eax
000A3D52 [004233FA] eb 06                                        jmp     short near ptr unk_423402 ; game-relative-target=0x000A3D5A
000A3D54 [004233FC] 3b c5                                        cmp     eax, ebp
000A3D56 [004233FE] 7d 02                                        jge     short near ptr unk_423402 ; game-relative-target=0x000A3D5A
000A3D58 [00423400] 8b e8                                        mov     ebp, eax
000A3D5A [00423402] 8b 3f                                        mov     edi, [edi]
000A3D5C [00423404] eb c8                                        jmp     short near ptr unk_4233CE ; game-relative-target=0x000A3D26
000A3D5E [00423406] 8b cc                                        mov     ecx, esp
000A3D60 [00423408] b8 e0 80 51 00                               mov     eax, 5180E0h
000A3D65 [0042340D] ff d0                                        call    eax
000A3D67 [0042340F] 83 c4 20                                     add     esp, 20h ; ' '
000A3D6A [00423412] 33 c0                                        xor     eax, eax
000A3D6C [00423414] 83 fb 50                                     cmp     ebx, 50h ; 'P'
000A3D6F [00423417] 7f 04                                        jg      short near ptr unk_42341D ; game-relative-target=0x000A3D75
000A3D71 [00423419] b0 02                                        mov     al, 2
000A3D73 [0042341B] eb 07                                        jmp     short near ptr unk_423424 ; game-relative-target=0x000A3D7C
000A3D75 [0042341D] 83 fb 50                                     cmp     ebx, 50h ; 'P'
000A3D78 [00423420] 7f 02                                        jg      short near ptr unk_423424 ; game-relative-target=0x000A3D7C
000A3D7A [00423422] b0 01                                        mov     al, 1
000A3D7C [00423424] 5d                                           pop     ebp
000A3D7D [00423425] 5b                                           pop     ebx
000A3D7E [00423426] 5f                                           pop     edi
000A3D7F [00423427] 5e                                           pop     esi
000A3D80 [00423428] c3                                           retn
