; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426D68; baseline game VA=0x000A6360; size=155
; Relative branch annotations use the baseline game destination.
000A6360 [00426D68] 56                                           push    esi
000A6361 [00426D69] 8b f1                                        mov     esi, ecx
000A6363 [00426D6B] b8 d0 64 0a 00                               mov     eax, 0A64D0h
000A6368 [00426D70] ff d0                                        call    eax
000A636A [00426D72] 85 c0                                        test    eax, eax
000A636C [00426D74] 75 04                                        jnz     short near ptr unk_426D7A ; game-relative-target=0x000A6372
000A636E [00426D76] b0 01                                        mov     al, 1
000A6370 [00426D78] 5e                                           pop     esi
000A6371 [00426D79] c3                                           retn
000A6372 [00426D7A] 8b 4e 74                                     mov     ecx, [esi+74h]
000A6375 [00426D7D] 85 c9                                        test    ecx, ecx
000A6377 [00426D7F] 75 04                                        jnz     short near ptr unk_426D85 ; game-relative-target=0x000A637D
000A6379 [00426D81] 33 c0                                        xor     eax, eax
000A637B [00426D83] 5e                                           pop     esi
000A637C [00426D84] c3                                           retn
000A637D [00426D85] 39 81 b8 00 00 00                            cmp     [ecx+0B8h], eax
000A6383 [00426D8B] 74 e9                                        jz      short near ptr unk_426D76 ; game-relative-target=0x000A636E
000A6385 [00426D8D] 83 7e 48 00                                  cmp     dword ptr [esi+48h], 0
000A6389 [00426D91] 7f ee                                        jg      short near ptr unk_426D81 ; game-relative-target=0x000A6379
000A638B [00426D93] 57                                           push    edi
000A638C [00426D94] 55                                           push    ebp
000A638D [00426D95] 53                                           push    ebx
000A638E [00426D96] 33 ff                                        xor     edi, edi
000A6390 [00426D98] 8b e8                                        mov     ebp, eax
000A6392 [00426D9A] f6 46 20 01                                  test    byte ptr [esi+20h], 1
000A6396 [00426D9E] 74 03                                        jz      short near ptr unk_426DA3 ; game-relative-target=0x000A639B
000A6398 [00426DA0] 8b 76 64                                     mov     esi, [esi+64h]
000A639B [00426DA3] 57                                           push    edi
000A639C [00426DA4] b8 f0 3c 47 00                               mov     eax, 473CF0h
000A63A1 [00426DA9] ff d0                                        call    eax
000A63A3 [00426DAB] 8b 48 74                                     mov     ecx, [eax+74h]
000A63A6 [00426DAE] 85 c9                                        test    ecx, ecx
000A63A8 [00426DB0] 74 3d                                        jz      short near ptr unk_426DEF ; game-relative-target=0x000A63E7
000A63AA [00426DB2] 39 a9 b8 00 00 00                            cmp     [ecx+0B8h], ebp
000A63B0 [00426DB8] 75 35                                        jnz     short near ptr unk_426DEF ; game-relative-target=0x000A63E7
000A63B2 [00426DBA] 33 db                                        xor     ebx, ebx
000A63B4 [00426DBC] b7 04                                        mov     bh, 4
000A63B6 [00426DBE] ba 87 f8 43 00                               mov     edx, 43F887h
000A63BB [00426DC3] 8b c8                                        mov     ecx, eax
000A63BD [00426DC5] 81 ff fa 00 00 00                            cmp     edi, 0FAh
000A63C3 [00426DCB] 7d 0e                                        jge     short near ptr unk_426DDB ; game-relative-target=0x000A63D3
000A63C5 [00426DCD] 8b 48 64                                     mov     ecx, [eax+64h]
000A63C8 [00426DD0] b7 04                                        mov     bh, 4
000A63CA [00426DD2] 42                                           inc     edx
000A63CB [00426DD3] 83 ff 32                                     cmp     edi, 32h ; '2'
000A63CE [00426DD6] 7d 03                                        jge     short near ptr unk_426DDB ; game-relative-target=0x000A63D3
000A63D0 [00426DD8] b7 04                                        mov     bh, 4
000A63D2 [00426DDA] 42                                           inc     edx
000A63D3 [00426DDB] 39 58 30                                     cmp     [eax+30h], ebx
000A63D6 [00426DDE] 7c 0f                                        jl      short near ptr unk_426DEF ; game-relative-target=0x000A63E7
000A63D8 [00426DE0] 0f b6 1a                                     movzx   ebx, byte ptr [edx]
000A63DB [00426DE3] 56                                           push    esi
000A63DC [00426DE4] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A63E1 [00426DE9] ff d0                                        call    eax
000A63E3 [00426DEB] 3b c3                                        cmp     eax, ebx
000A63E5 [00426DED] 7e 0d                                        jle     short near ptr unk_426DFC ; game-relative-target=0x000A63F4
000A63E7 [00426DEF] 47                                           inc     edi
000A63E8 [00426DF0] 81 ff 4c 04 00 00                            cmp     edi, 44Ch
000A63EE [00426DF6] 7c ab                                        jl      short near ptr unk_426DA3 ; game-relative-target=0x000A639B
000A63F0 [00426DF8] 33 c0                                        xor     eax, eax
000A63F2 [00426DFA] eb 02                                        jmp     short near ptr unk_426DFE ; game-relative-target=0x000A63F6
000A63F4 [00426DFC] b0 01                                        mov     al, 1
000A63F6 [00426DFE] 5b                                           pop     ebx
000A63F7 [00426DFF] 5d                                           pop     ebp
000A63F8 [00426E00] 5f                                           pop     edi
000A63F9 [00426E01] 5e                                           pop     esi
000A63FA [00426E02] c3                                           retn
