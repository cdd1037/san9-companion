; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004218A8; baseline game VA=0x000A1990; size=106
; Relative branch annotations use the baseline game destination.
000A1990 [004218A8] 55                                           push    ebp
000A1991 [004218A9] 56                                           push    esi
000A1992 [004218AA] 57                                           push    edi
000A1993 [004218AB] 33 ff                                        xor     edi, edi
000A1995 [004218AD] bd b0 93 4b 01                               mov     ebp, 14B93B0h
000A199A [004218B2] 8b f1                                        mov     esi, ecx
000A199C [004218B4] 8b 45 58                                     mov     eax, [ebp+58h]
000A199F [004218B7] 3c 34                                        cmp     al, 34h ; '4'
000A19A1 [004218B9] 74 08                                        jz      short near ptr unk_4218C3 ; game-relative-target=0x000A19AB
000A19A3 [004218BB] 3c 33                                        cmp     al, 33h ; '3'
000A19A5 [004218BD] 74 04                                        jz      short near ptr unk_4218C3 ; game-relative-target=0x000A19AB
000A19A7 [004218BF] 3c 27                                        cmp     al, 27h ; '''
000A19A9 [004218C1] 75 3b                                        jnz     short near ptr unk_4218FE ; game-relative-target=0x000A19E6
000A19AB [004218C3] 8b 46 04                                     mov     eax, [esi+4]
000A19AE [004218C6] 39 45 50                                     cmp     [ebp+50h], eax
000A19B1 [004218C9] 75 33                                        jnz     short near ptr unk_4218FE ; game-relative-target=0x000A19E6
000A19B3 [004218CB] 83 7d 54 ff                                  cmp     dword ptr [ebp+54h], 0FFFFFFFFh
000A19B7 [004218CF] 75 2d                                        jnz     short near ptr unk_4218FE ; game-relative-target=0x000A19E6
000A19B9 [004218D1] 83 7d 24 06                                  cmp     dword ptr [ebp+24h], 6
000A19BD [004218D5] 74 27                                        jz      short near ptr unk_4218FE ; game-relative-target=0x000A19E6
000A19BF [004218D7] 83 7d 24 04                                  cmp     dword ptr [ebp+24h], 4
000A19C3 [004218DB] 74 21                                        jz      short near ptr unk_4218FE ; game-relative-target=0x000A19E6
000A19C5 [004218DD] 56                                           push    esi
000A19C6 [004218DE] 8b cd                                        mov     ecx, ebp
000A19C8 [004218E0] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A19CD [004218E5] ff d0                                        call    eax
000A19CF [004218E7] 83 f8 1e                                     cmp     eax, 1Eh
000A19D2 [004218EA] 7e 0f                                        jle     short near ptr unk_4218FB ; game-relative-target=0x000A19E3
000A19D4 [004218EC] 56                                           push    esi
000A19D5 [004218ED] 8b cd                                        mov     ecx, ebp
000A19D7 [004218EF] b8 70 88 46 00                               mov     eax, 468870h
000A19DC [004218F4] ff d0                                        call    eax
000A19DE [004218F6] 83 f8 09                                     cmp     eax, 9
000A19E1 [004218F9] 7f 03                                        jg      short near ptr unk_4218FE ; game-relative-target=0x000A19E6
000A19E3 [004218FB] 03 7d 30                                     add     edi, [ebp+30h]
000A19E6 [004218FE] 81 c5 04 01 00 00                            add     ebp, 104h
000A19EC [00421904] 66 81 7d 04 51 03                            cmp     word ptr [ebp+4], 351h
000A19F2 [0042190A] 7c a8                                        jl      short near ptr unk_4218B4 ; game-relative-target=0x000A199C
000A19F4 [0042190C] 8b c7                                        mov     eax, edi
000A19F6 [0042190E] 5f                                           pop     edi
000A19F7 [0042190F] 5e                                           pop     esi
000A19F8 [00421910] 5d                                           pop     ebp
000A19F9 [00421911] c3                                           retn
