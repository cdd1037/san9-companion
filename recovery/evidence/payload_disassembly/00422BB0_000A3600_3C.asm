; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422BB0; baseline game VA=0x000A3600; size=60
; Relative branch annotations use the baseline game destination.
000A3600 [00422BB0] 56                                           push    esi
000A3601 [00422BB1] 57                                           push    edi
000A3602 [00422BB2] 53                                           push    ebx
000A3603 [00422BB3] 8b f9                                        mov     edi, ecx
000A3605 [00422BB5] 33 db                                        xor     ebx, ebx
000A3607 [00422BB7] 8b 35 24 05 0a 00                            mov     esi, ds:0A0524h
000A360D [00422BBD] 8b 56 08                                     mov     edx, [esi+8]
000A3610 [00422BC0] 8b 42 6c                                     mov     eax, [edx+6Ch]
000A3613 [00422BC3] 80 78 04 06                                  cmp     byte ptr [eax+4], 6
000A3617 [00422BC7] 75 17                                        jnz     short near ptr unk_422BE0 ; game-relative-target=0x000A3630
000A3619 [00422BC9] 8b cf                                        mov     ecx, edi
000A361B [00422BCB] b8 10 38 0a 00                               mov     eax, 0A3810h
000A3620 [00422BD0] ff d0                                        call    eax
000A3622 [00422BD2] 85 c0                                        test    eax, eax
000A3624 [00422BD4] 75 0a                                        jnz     short near ptr unk_422BE0 ; game-relative-target=0x000A3630
000A3626 [00422BD6] 8b 4e 08                                     mov     ecx, [esi+8]
000A3629 [00422BD9] 8b 41 30                                     mov     eax, [ecx+30h]
000A362C [00422BDC] d1 e8                                        shr     eax, 1
000A362E [00422BDE] 03 d8                                        add     ebx, eax
000A3630 [00422BE0] 8b 36                                        mov     esi, [esi]
000A3632 [00422BE2] 85 f6                                        test    esi, esi
000A3634 [00422BE4] 75 d7                                        jnz     short near ptr unk_422BBD ; game-relative-target=0x000A360D
000A3636 [00422BE6] 8b c3                                        mov     eax, ebx
000A3638 [00422BE8] 5b                                           pop     ebx
000A3639 [00422BE9] 5f                                           pop     edi
000A363A [00422BEA] 5e                                           pop     esi
000A363B [00422BEB] c3                                           retn
