; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426F10; baseline game VA=0x000A6C00; size=108
; Relative branch annotations use the baseline game destination.
000A6C00 [00426F10] 56                                           push    esi
000A6C01 [00426F11] 57                                           push    edi
000A6C02 [00426F12] 8b 31                                        mov     esi, [ecx]
000A6C04 [00426F14] 81 ee 00 19 00 00                            sub     esi, 1900h
000A6C0A [00426F1A] 6b f6 0a                                     imul    esi, 0Ah
000A6C0D [00426F1D] c1 fe 06                                     sar     esi, 6
000A6C10 [00426F20] 8b 79 04                                     mov     edi, [ecx+4]
000A6C13 [00426F23] 6b ff 0a                                     imul    edi, 0Ah
000A6C16 [00426F26] c1 ef 05                                     shr     edi, 5
000A6C19 [00426F29] 4f                                           dec     edi
000A6C1A [00426F2A] 8b c6                                        mov     eax, esi
000A6C1C [00426F2C] 03 c7                                        add     eax, edi
000A6C1E [00426F2E] d1 e8                                        shr     eax, 1
000A6C20 [00426F30] 2b fe                                        sub     edi, esi
000A6C22 [00426F32] d1 ef                                        shr     edi, 1
000A6C24 [00426F34] 8b f0                                        mov     esi, eax
000A6C26 [00426F36] 8b 4c 24 0c                                  mov     ecx, [esp+0Ch]
000A6C2A [00426F3A] 8b 11                                        mov     edx, [ecx]
000A6C2C [00426F3C] 81 ea 00 19 00 00                            sub     edx, 1900h
000A6C32 [00426F42] 6b d2 0a                                     imul    edx, 0Ah
000A6C35 [00426F45] c1 fa 06                                     sar     edx, 6
000A6C38 [00426F48] 8b 49 04                                     mov     ecx, [ecx+4]
000A6C3B [00426F4B] 6b c9 0a                                     imul    ecx, 0Ah
000A6C3E [00426F4E] c1 e9 05                                     shr     ecx, 5
000A6C41 [00426F51] 49                                           dec     ecx
000A6C42 [00426F52] 8b c2                                        mov     eax, edx
000A6C44 [00426F54] 03 c1                                        add     eax, ecx
000A6C46 [00426F56] d1 e8                                        shr     eax, 1
000A6C48 [00426F58] 2b ca                                        sub     ecx, edx
000A6C4A [00426F5A] d1 e9                                        shr     ecx, 1
000A6C4C [00426F5C] 2b c6                                        sub     eax, esi
000A6C4E [00426F5E] 0f af c0                                     imul    eax, eax
000A6C51 [00426F61] 2b cf                                        sub     ecx, edi
000A6C53 [00426F63] 0f af c9                                     imul    ecx, ecx
000A6C56 [00426F66] 03 c1                                        add     eax, ecx
000A6C58 [00426F68] 3d 00 64 00 00                               cmp     eax, 6400h
000A6C5D [00426F6D] 7f 08                                        jg      short near ptr unk_426F77 ; game-relative-target=0x000A6C67
000A6C5F [00426F6F] 50                                           push    eax
000A6C60 [00426F70] ff 15 1c f3 5f 00                            call    dword ptr ds:5FF31Ch
000A6C66 [00426F76] 5a                                           pop     edx
000A6C67 [00426F77] 5f                                           pop     edi
000A6C68 [00426F78] 5e                                           pop     esi
000A6C69 [00426F79] c2 04 00                                     retn    4
