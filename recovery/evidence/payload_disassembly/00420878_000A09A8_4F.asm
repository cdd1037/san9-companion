; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420878; baseline game VA=0x000A09A8; size=79
; Relative branch annotations use the baseline game destination.
000A09A8 [00420878] 56                                           push    esi
000A09A9 [00420879] 53                                           push    ebx
000A09AA [0042087A] 8b 1d 04 fc 43 00                            mov     ebx, ds:43FC04h
000A09B0 [00420880] 85 db                                        test    ebx, ebx
000A09B2 [00420882] 74 40                                        jz      short near ptr unk_4208C4 ; game-relative-target=0x000A09F4
000A09B4 [00420884] ff 74 24 18                                  push    dword ptr [esp+18h]
000A09B8 [00420888] 68 00 05 0a 00                               push    0A0500h
000A09BD [0042088D] b8 00 16 4a 00                               mov     eax, 4A1600h
000A09C2 [00420892] ff d0                                        call    eax
000A09C4 [00420894] 8b 3d 04 05 0a 00                            mov     edi, ds:0A0504h
000A09CA [0042089A] ff 77 08                                     push    dword ptr [edi+8]
000A09CD [0042089D] 8d 4c 24 5c                                  lea     ecx, [esp+5Ch]
000A09D1 [004208A1] b8 50 ee 46 00                               mov     eax, 46EE50h
000A09D6 [004208A6] ff d0                                        call    eax
000A09D8 [004208A8] 4b                                           dec     ebx
000A09D9 [004208A9] 74 06                                        jz      short near ptr unk_4208B1 ; game-relative-target=0x000A09E1
000A09DB [004208AB] 8b 3f                                        mov     edi, [edi]
000A09DD [004208AD] 85 ff                                        test    edi, edi
000A09DF [004208AF] 75 e9                                        jnz     short near ptr unk_42089A ; game-relative-target=0x000A09CA
000A09E1 [004208B1] b9 00 05 0a 00                               mov     ecx, 0A0500h
000A09E6 [004208B6] b8 e0 80 51 00                               mov     eax, 5180E0h
000A09EB [004208BB] ff d0                                        call    eax
000A09ED [004208BD] 33 c0                                        xor     eax, eax
000A09EF [004208BF] a3 04 fc 43 00                               mov     ds:43FC04h, eax
000A09F4 [004208C4] 5b                                           pop     ebx
000A09F5 [004208C5] 5e                                           pop     esi
000A09F6 [004208C6] c3                                           retn
