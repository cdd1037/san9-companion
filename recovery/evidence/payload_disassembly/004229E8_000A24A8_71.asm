; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004229E8; baseline game VA=0x000A24A8; size=113
; Relative branch annotations use the baseline game destination.
000A24A8 [004229E8] f6 40 34 04                                  test    byte ptr [eax+34h], 4
000A24AC [004229EC] 74 04                                        jz      short near ptr unk_4229F2 ; game-relative-target=0x000A24B2
000A24AE [004229EE] 83 f8 00                                     cmp     eax, 0
000A24B1 [004229F1] c3                                           retn
000A24B2 [004229F2] 50                                           push    eax
000A24B3 [004229F3] 8b c8                                        mov     ecx, eax
000A24B5 [004229F5] b8 b0 d9 43 00                               mov     eax, 43D9B0h
000A24BA [004229FA] ff d0                                        call    eax
000A24BC [004229FC] 59                                           pop     ecx
000A24BD [004229FD] 8b 91 84 00 00 00                            mov     edx, [ecx+84h]
000A24C3 [00422A03] 80 fa 02                                     cmp     dl, 2
000A24C6 [00422A06] 7d 02                                        jge     short near ptr unk_422A0A ; game-relative-target=0x000A24CA
000A24C8 [00422A08] b2 02                                        mov     dl, 2
000A24CA [00422A0A] 80 fa 0a                                     cmp     dl, 0Ah
000A24CD [00422A0D] 7e 02                                        jle     short near ptr unk_422A11 ; game-relative-target=0x000A24D1
000A24CF [00422A0F] b2 0a                                        mov     dl, 0Ah
000A24D1 [00422A11] c1 e2 0b                                     shl     edx, 0Bh
000A24D4 [00422A14] 03 c2                                        add     eax, edx
000A24D6 [00422A16] 39 41 14                                     cmp     [ecx+14h], eax
000A24D9 [00422A19] 7d 01                                        jge     short near ptr unk_422A1C ; game-relative-target=0x000A24DC
000A24DB [00422A1B] c3                                           retn
000A24DC [00422A1C] 51                                           push    ecx
000A24DD [00422A1D] b8 90 4b 45 00                               mov     eax, 454B90h
000A24E2 [00422A22] ff d0                                        call    eax
000A24E4 [00422A24] 59                                           pop     ecx
000A24E5 [00422A25] 83 c0 3c                                     add     eax, 3Ch ; '<'
000A24E8 [00422A28] 51                                           push    ecx
000A24E9 [00422A29] 50                                           push    eax
000A24EA [00422A2A] b8 e0 ed 43 00                               mov     eax, 43EDE0h
000A24EF [00422A2F] ff d0                                        call    eax
000A24F1 [00422A31] 59                                           pop     ecx
000A24F2 [00422A32] 39 41 18                                     cmp     [ecx+18h], eax
000A24F5 [00422A35] 7d 01                                        jge     short near ptr unk_422A38 ; game-relative-target=0x000A24F8
000A24F7 [00422A37] c3                                           retn
000A24F8 [00422A38] 51                                           push    ecx
000A24F9 [00422A39] b8 d0 f4 43 00                               mov     eax, 43F4D0h
000A24FE [00422A3E] ff d0                                        call    eax
000A2500 [00422A40] 59                                           pop     ecx
000A2501 [00422A41] f6 41 0d 01                                  test    byte ptr [ecx+0Dh], 1
000A2505 [00422A45] 75 05                                        jnz     short near ptr unk_422A4C ; game-relative-target=0x000A250C
000A2507 [00422A47] 6b c0 0a                                     imul    eax, 0Ah
000A250A [00422A4A] eb 03                                        jmp     short near ptr unk_422A4F ; game-relative-target=0x000A250F
000A250C [00422A4C] 6b c0 10                                     imul    eax, 10h
000A250F [00422A4F] c1 e8 05                                     shr     eax, 5
000A2512 [00422A52] 3b 81 84 00 00 00                            cmp     eax, [ecx+84h]
000A2518 [00422A58] c3                                           retn
