; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423288; baseline game VA=0x000A2080; size=127
; Relative branch annotations use the baseline game destination.
000A2080 [00423288] 56                                           push    esi
000A2081 [00423289] 8b 54 24 08                                  mov     edx, [esp+8]
000A2085 [0042328D] 8b 82 cc 00 00 00                            mov     eax, [edx+0CCh]
000A208B [00423293] 8b b0 b8 00 00 00                            mov     esi, [eax+0B8h]
000A2091 [00423299] f6 46 34 01                                  test    byte ptr [esi+34h], 1
000A2095 [0042329D] 74 04                                        jz      short near ptr unk_4232A3 ; game-relative-target=0x000A209B
000A2097 [0042329F] 5e                                           pop     esi
000A2098 [004232A0] c2 04 00                                     retn    4
000A209B [004232A3] 8b 51 0c                                     mov     edx, [ecx+0Ch]
000A209E [004232A6] c1 ea 0c                                     shr     edx, 0Ch
000A20A1 [004232A9] 8b c2                                        mov     eax, edx
000A20A3 [004232AB] 24 0f                                        and     al, 0Fh
000A20A5 [004232AD] 3c 02                                        cmp     al, 2
000A20A7 [004232AF] 75 09                                        jnz     short near ptr unk_4232BA ; game-relative-target=0x000A20B2
000A20A9 [004232B1] c1 ea 04                                     shr     edx, 4
000A20AC [004232B4] 4a                                           dec     edx
000A20AD [004232B5] 3a 56 04                                     cmp     dl, [esi+4]
000A20B0 [004232B8] 74 e5                                        jz      short near ptr unk_42329F ; game-relative-target=0x000A2097
000A20B2 [004232BA] 8b 81 bc 00 00 00                            mov     eax, [ecx+0BCh]
000A20B8 [004232C0] ff 70 74                                     push    dword ptr [eax+74h]
000A20BB [004232C3] 56                                           push    esi
000A20BC [004232C4] b8 60 14 44 00                               mov     eax, 441460h
000A20C1 [004232C9] ff d0                                        call    eax
000A20C3 [004232CB] 83 e8 3c                                     sub     eax, 3Ch ; '<'
000A20C6 [004232CE] f7 d8                                        neg     eax
000A20C8 [004232D0] 85 c0                                        test    eax, eax
000A20CA [004232D2] 5a                                           pop     edx
000A20CB [004232D3] 7e 2c                                        jle     short near ptr unk_423301 ; game-relative-target=0x000A20F9
000A20CD [004232D5] 8a 0d cc f4 43 00                            mov     cl, ds:43F4CCh
000A20D3 [004232DB] 84 c9                                        test    cl, cl
000A20D5 [004232DD] 74 07                                        jz      short near ptr unk_4232E6 ; game-relative-target=0x000A20DE
000A20D7 [004232DF] c1 e0 04                                     shl     eax, 4
000A20DA [004232E2] d3 e8                                        shr     eax, cl
000A20DC [004232E4] eb 11                                        jmp     short near ptr unk_4232F7 ; game-relative-target=0x000A20EF
000A20DE [004232E6] c1 e8 01                                     shr     eax, 1
000A20E1 [004232E9] 83 ea 05                                     sub     edx, 5
000A20E4 [004232EC] 85 d2                                        test    edx, edx
000A20E6 [004232EE] 7d 02                                        jge     short near ptr unk_4232F2 ; game-relative-target=0x000A20EA
000A20E8 [004232F0] 33 d2                                        xor     edx, edx
000A20EA [004232F2] 6b d2 07                                     imul    edx, 7
000A20ED [004232F5] 03 c2                                        add     eax, edx
000A20EF [004232F7] 50                                           push    eax
000A20F0 [004232F8] b8 f0 ef 4a 00                               mov     eax, 4AEFF0h
000A20F5 [004232FD] ff d0                                        call    eax
000A20F7 [004232FF] eb 02                                        jmp     short near ptr unk_423303 ; game-relative-target=0x000A20FB
000A20F9 [00423301] 33 c0                                        xor     eax, eax
000A20FB [00423303] 5e                                           pop     esi
000A20FC [00423304] c2 04 00                                     retn    4
