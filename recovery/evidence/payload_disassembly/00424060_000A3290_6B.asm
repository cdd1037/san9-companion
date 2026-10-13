; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424060; baseline game VA=0x000A3290; size=107
; Relative branch annotations use the baseline game destination.
000A3290 [00424060] 56                                           push    esi
000A3291 [00424061] b8 80 e1 45 00                               mov     eax, 45E180h
000A3296 [00424066] ff d0                                        call    eax
000A3298 [00424068] 85 c0                                        test    eax, eax
000A329A [0042406A] 74 54                                        jz      short near ptr unk_4240C0 ; game-relative-target=0x000A32F0
000A329C [0042406C] 89 44 24 04                                  mov     [esp+4], eax
000A32A0 [00424070] 8b cf                                        mov     ecx, edi
000A32A2 [00424072] 8b fe                                        mov     edi, esi
000A32A4 [00424074] 8b f1                                        mov     esi, ecx
000A32A6 [00424076] 8b ff                                        mov     edi, edi
000A32A8 [00424078] 80 79 58 26                                  cmp     byte ptr [ecx+58h], 26h ; '&'
000A32AC [0042407C] 75 45                                        jnz     short near ptr unk_4240C3 ; game-relative-target=0x000A32F3
000A32AE [0042407E] 8a 41 52                                     mov     al, [ecx+52h]
000A32B1 [00424081] 3c 03                                        cmp     al, 3
000A32B3 [00424083] 74 3e                                        jz      short near ptr unk_4240C3 ; game-relative-target=0x000A32F3
000A32B5 [00424085] 0f b6 51 50                                  movzx   edx, byte ptr [ecx+50h]
000A32B9 [00424089] b9 70 2f 45 00                               mov     ecx, 452F70h
000A32BE [0042408E] 3c 05                                        cmp     al, 5
000A32C0 [00424090] 74 02                                        jz      short near ptr unk_424094 ; game-relative-target=0x000A32C4
000A32C2 [00424092] b1 10                                        mov     cl, 10h
000A32C4 [00424094] 52                                           push    edx
000A32C5 [00424095] ff d1                                        call    ecx
000A32C7 [00424097] 5a                                           pop     edx
000A32C8 [00424098] 8b 88 cc 00 00 00                            mov     ecx, [eax+0CCh]
000A32CE [0042409E] 85 c9                                        test    ecx, ecx
000A32D0 [004240A0] 74 21                                        jz      short near ptr unk_4240C3 ; game-relative-target=0x000A32F3
000A32D2 [004240A2] f6 41 34 01                                  test    byte ptr [ecx+34h], 1
000A32D6 [004240A6] 74 1b                                        jz      short near ptr unk_4240C3 ; game-relative-target=0x000A32F3
000A32D8 [004240A8] 57                                           push    edi
000A32D9 [004240A9] b8 50 18 44 00                               mov     eax, 441850h
000A32DE [004240AE] ff d0                                        call    eax
000A32E0 [004240B0] 85 c0                                        test    eax, eax
000A32E2 [004240B2] 75 0f                                        jnz     short near ptr unk_4240C3 ; game-relative-target=0x000A32F3
000A32E4 [004240B4] 80 3c 24 83                                  cmp     byte ptr [esp], 83h
000A32E8 [004240B8] 74 06                                        jz      short near ptr unk_4240C0 ; game-relative-target=0x000A32F0
000A32EA [004240BA] 5a                                           pop     edx
000A32EB [004240BB] 68 0d 4c 46 00                               push    464C0Dh
000A32F0 [004240C0] c2 04 00                                     retn    4
000A32F3 [004240C3] 8b ce                                        mov     ecx, esi
000A32F5 [004240C5] 68 50 0e 46 00                               push    460E50h
000A32FA [004240CA] c3                                           retn
