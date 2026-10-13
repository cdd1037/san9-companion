; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004246E8; baseline game VA=0x000A4E00; size=59
; Relative branch annotations use the baseline game destination.
000A4E00 [004246E8] 83 7c 24 20 00                               cmp     dword ptr [esp+20h], 0
000A4E05 [004246ED] 74 25                                        jz      short near ptr unk_424714 ; game-relative-target=0x000A4E2C
000A4E07 [004246EF] 8b 4e 38                                     mov     ecx, [esi+38h]
000A4E0A [004246F2] 80 79 24 01                                  cmp     byte ptr [ecx+24h], 1
000A4E0E [004246F6] 74 01                                        jz      short near ptr unk_4246F9 ; game-relative-target=0x000A4E11
000A4E10 [004246F8] c3                                           retn
000A4E11 [004246F9] ff 15 dc f2 5f 00                            call    dword ptr ds:5FF2DCh
000A4E17 [004246FF] 02 43 04                                     add     al, [ebx+4]
000A4E1A [00424702] a8 05                                        test    al, 5
000A4E1C [00424704] 75 03                                        jnz     short near ptr unk_424709 ; game-relative-target=0x000A4E21
000A4E1E [00424706] 85 c0                                        test    eax, eax
000A4E20 [00424708] c3                                           retn
000A4E21 [00424709] 8d 4c 24 14                                  lea     ecx, [esp+14h]
000A4E25 [0042470D] b8 e0 80 51 00                               mov     eax, 5180E0h
000A4E2A [00424712] ff d0                                        call    eax
000A4E2C [00424714] 83 7e 50 00                                  cmp     dword ptr [esi+50h], 0
000A4E30 [00424718] 75 01                                        jnz     short near ptr unk_42471B ; game-relative-target=0x000A4E33
000A4E32 [0042471A] c3                                           retn
000A4E33 [0042471B] 68 37 fa 49 00                               push    49FA37h
000A4E38 [00424720] c2 04 00                                     retn    4
