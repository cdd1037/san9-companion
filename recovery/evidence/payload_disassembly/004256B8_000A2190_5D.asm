; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004256B8; baseline game VA=0x000A2190; size=93
; Relative branch annotations use the baseline game destination.
000A2190 [004256B8] 99                                           cdq
000A2191 [004256B9] b9 fa 00 00 00                               mov     ecx, 0FAh
000A2196 [004256BE] f7 f1                                        div     ecx
000A2198 [004256C0] 83 e8 04                                     sub     eax, 4
000A219B [004256C3] f7 d8                                        neg     eax
000A219D [004256C5] 85 c0                                        test    eax, eax
000A219F [004256C7] 7f 04                                        jg      short near ptr unk_4256CD ; game-relative-target=0x000A21A5
000A21A1 [004256C9] 33 c0                                        xor     eax, eax
000A21A3 [004256CB] b0 01                                        mov     al, 1
000A21A5 [004256CD] 3c 04                                        cmp     al, 4
000A21A7 [004256CF] 7e 02                                        jle     short near ptr unk_4256D3 ; game-relative-target=0x000A21AB
000A21A9 [004256D1] b0 04                                        mov     al, 4
000A21AB [004256D3] 0f af 44 24 08                               imul    eax, [esp+8]
000A21B0 [004256D8] 99                                           cdq
000A21B1 [004256D9] b1 03                                        mov     cl, 3
000A21B3 [004256DB] f7 f1                                        div     ecx
000A21B5 [004256DD] 89 44 24 08                                  mov     [esp+8], eax
000A21B9 [004256E1] 83 ff 04                                     cmp     edi, 4
000A21BC [004256E4] 7f 29                                        jg      short near ptr unk_42570F ; game-relative-target=0x000A21E7
000A21BE [004256E6] 0f b7 46 04                                  movzx   eax, word ptr [esi+4]
000A21C2 [004256EA] 3d 20 03 00 00                               cmp     eax, 320h
000A21C7 [004256EF] 7d 1e                                        jge     short near ptr unk_42570F ; game-relative-target=0x000A21E7
000A21C9 [004256F1] 8b 04 85 00 40 0a 00                         mov     eax, ds:0A4000h[eax*4]
000A21D0 [004256F8] 8b cf                                        mov     ecx, edi
000A21D2 [004256FA] d1 e1                                        shl     ecx, 1
000A21D4 [004256FC] d3 e8                                        shr     eax, cl
000A21D6 [004256FE] 24 03                                        and     al, 3
000A21D8 [00425700] 3c 03                                        cmp     al, 3
000A21DA [00425702] 75 0b                                        jnz     short near ptr unk_42570F ; game-relative-target=0x000A21E7
000A21DC [00425704] 66 a1 de ff 43 00                            mov     ax, ds:43FFDEh
000A21E2 [0042570A] 66 89 44 24 0c                               mov     [esp+0Ch], ax
000A21E7 [0042570F] ff 25 0c f3 5f 00                            jmp     dword ptr ds:5FF30Ch
