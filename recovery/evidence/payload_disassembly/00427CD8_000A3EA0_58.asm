; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427CD8; baseline game VA=0x000A3EA0; size=88
; Relative branch annotations use the baseline game destination.
000A3EA0 [00427CD8] 56                                           push    esi
000A3EA1 [00427CD9] 53                                           push    ebx
000A3EA2 [00427CDA] 8b 71 04                                     mov     esi, [ecx+4]
000A3EA5 [00427CDD] 8b 4e 08                                     mov     ecx, [esi+8]
000A3EA8 [00427CE0] 8b 51 6c                                     mov     edx, [ecx+6Ch]
000A3EAB [00427CE3] 8a 42 04                                     mov     al, [edx+4]
000A3EAE [00427CE6] 3c 00                                        cmp     al, 0
000A3EB0 [00427CE8] 75 09                                        jnz     short near ptr unk_427CF3 ; game-relative-target=0x000A3EBB
000A3EB2 [00427CEA] bb 12 00 00 00                               mov     ebx, 12h
000A3EB7 [00427CEF] 6a 0f                                        push    0Fh
000A3EB9 [00427CF1] eb 0b                                        jmp     short near ptr unk_427CFE ; game-relative-target=0x000A3EC6
000A3EBB [00427CF3] 3c 02                                        cmp     al, 2
000A3EBD [00427CF5] 75 30                                        jnz     short near ptr unk_427D27 ; game-relative-target=0x000A3EEF
000A3EBF [00427CF7] bb 10 00 00 00                               mov     ebx, 10h
000A3EC4 [00427CFC] 6a 0a                                        push    0Ah
000A3EC6 [00427CFE] b8 f0 ef 4a 00                               mov     eax, 4AEFF0h
000A3ECB [00427D03] ff d0                                        call    eax
000A3ECD [00427D05] 85 c0                                        test    eax, eax
000A3ECF [00427D07] 74 1e                                        jz      short near ptr unk_427D27 ; game-relative-target=0x000A3EEF
000A3ED1 [00427D09] 8b 4e 08                                     mov     ecx, [esi+8]
000A3ED4 [00427D0C] f6 41 21 10                                  test    byte ptr [ecx+21h], 10h
000A3ED8 [00427D10] 74 09                                        jz      short near ptr unk_427D1B ; game-relative-target=0x000A3EE3
000A3EDA [00427D12] f7 c6 00 01 00 00                            test    esi, 100h
000A3EE0 [00427D18] 74 01                                        jz      short near ptr unk_427D1B ; game-relative-target=0x000A3EE3
000A3EE2 [00427D1A] 40                                           inc     eax
000A3EE3 [00427D1B] 53                                           push    ebx
000A3EE4 [00427D1C] b8 90 38 45 00                               mov     eax, 453890h
000A3EE9 [00427D21] ff d0                                        call    eax
000A3EEB [00427D23] 5b                                           pop     ebx
000A3EEC [00427D24] 89 41 6c                                     mov     [ecx+6Ch], eax
000A3EEF [00427D27] 8b 36                                        mov     esi, [esi]
000A3EF1 [00427D29] 85 f6                                        test    esi, esi
000A3EF3 [00427D2B] 75 b0                                        jnz     short near ptr unk_427CDD ; game-relative-target=0x000A3EA5
000A3EF5 [00427D2D] 5b                                           pop     ebx
000A3EF6 [00427D2E] 5e                                           pop     esi
000A3EF7 [00427D2F] c3                                           retn
