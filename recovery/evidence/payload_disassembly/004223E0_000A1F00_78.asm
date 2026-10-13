; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004223E0; baseline game VA=0x000A1F00; size=120
; Relative branch annotations use the baseline game destination.
000A1F00 [004223E0] 58                                           pop     eax
000A1F01 [004223E1] 8b 41 38                                     mov     eax, [ecx+38h]
000A1F04 [004223E4] 8b 90 b8 00 00 00                            mov     edx, [eax+0B8h]
000A1F0A [004223EA] f6 42 34 01                                  test    byte ptr [edx+34h], 1
000A1F0E [004223EE] 75 0a                                        jnz     short near ptr unk_4223FA ; game-relative-target=0x000A1F1A
000A1F10 [004223F0] b8 32 1f 0a 00                               mov     eax, 0A1F32h
000A1F15 [004223F5] a3 05 05 4b 00                               mov     ds:4B0505h, eax
000A1F1A [004223FA] b8 b0 04 4b 00                               mov     eax, 4B04B0h
000A1F1F [004223FF] ff d0                                        call    eax
000A1F21 [00422401] b9 f0 cc 46 00                               mov     ecx, 46CCF0h
000A1F26 [00422406] 89 0d 05 05 4b 00                            mov     ds:4B0505h, ecx
000A1F2C [0042240C] 68 e6 6b 4b 00                               push    4B6BE6h
000A1F31 [00422411] c3                                           retn
000A1F32 [00422412] 8b 54 24 04                                  mov     edx, [esp+4]
000A1F36 [00422416] 8b 0a                                        mov     ecx, [edx]
000A1F38 [00422418] 8b 81 cc 00 00 00                            mov     eax, [ecx+0CCh]
000A1F3E [0042241E] 85 c0                                        test    eax, eax
000A1F40 [00422420] 74 13                                        jz      short near ptr unk_422435 ; game-relative-target=0x000A1F55
000A1F42 [00422422] 8b 80 b8 00 00 00                            mov     eax, [eax+0B8h]
000A1F48 [00422428] 8b 4a 0c                                     mov     ecx, [edx+0Ch]
000A1F4B [0042242B] 3b 81 b8 00 00 00                            cmp     eax, [ecx+0B8h]
000A1F51 [00422431] 74 24                                        jz      short near ptr unk_422457 ; game-relative-target=0x000A1F77
000A1F53 [00422433] eb 20                                        jmp     short near ptr unk_422455 ; game-relative-target=0x000A1F75
000A1F55 [00422435] 8b 0a                                        mov     ecx, [edx]
000A1F57 [00422437] 8b 41 44                                     mov     eax, [ecx+44h]
000A1F5A [0042243A] 8b 80 cc 00 00 00                            mov     eax, [eax+0CCh]
000A1F60 [00422440] 85 c0                                        test    eax, eax
000A1F62 [00422442] 74 13                                        jz      short near ptr unk_422457 ; game-relative-target=0x000A1F77
000A1F64 [00422444] 8b 80 b8 00 00 00                            mov     eax, [eax+0B8h]
000A1F6A [0042244A] 8b 4a 0c                                     mov     ecx, [edx+0Ch]
000A1F6D [0042244D] 3b 81 b8 00 00 00                            cmp     eax, [ecx+0B8h]
000A1F73 [00422453] 74 02                                        jz      short near ptr unk_422457 ; game-relative-target=0x000A1F77
000A1F75 [00422455] 33 c0                                        xor     eax, eax
000A1F77 [00422457] c3                                           retn
