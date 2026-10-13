; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B2B8; baseline game VA=0x000A92A0; size=188
; Relative branch annotations use the baseline game destination.
000A92A0 [0042B2B8] 57                                           push    edi
000A92A1 [0042B2B9] bf 00 92 0a 00                               mov     edi, 0A9200h
000A92A6 [0042B2BE] 8b 80 6c 26 00 00                            mov     eax, [eax+266Ch]
000A92AC [0042B2C4] 80 78 06 03                                  cmp     byte ptr [eax+6], 3
000A92B0 [0042B2C8] 74 13                                        jz      short near ptr unk_42B2DD ; game-relative-target=0x000A92C5
000A92B2 [0042B2CA] 8b 52 04                                     mov     edx, [edx+4]
000A92B5 [0042B2CD] 8b 12                                        mov     edx, [edx]
000A92B7 [0042B2CF] 89 17                                        mov     [edi], edx
000A92B9 [0042B2D1] 8d 41 31                                     lea     eax, [ecx+31h]
000A92BC [0042B2D4] c6 47 05 46                                  mov     byte ptr [edi+5], 46h ; 'F'
000A92C0 [0042B2D8] 88 47 06                                     mov     [edi+6], al
000A92C3 [0042B2DB] eb 35                                        jmp     short near ptr unk_42B312 ; game-relative-target=0x000A92FA
000A92C5 [0042B2DD] f6 40 22 30                                  test    byte ptr [eax+22h], 30h ; '0'
000A92C9 [0042B2E1] 75 0d                                        jnz     short near ptr unk_42B2F0 ; game-relative-target=0x000A92D8
000A92CB [0042B2E3] 81 fa 00 80 65 00                            cmp     edx, 658000h
000A92D1 [0042B2E9] 75 05                                        jnz     short near ptr unk_42B2F0 ; game-relative-target=0x000A92D8
000A92D3 [0042B2EB] ba 84 a7 66 00                               mov     edx, 66A784h
000A92D8 [0042B2F0] 8b 52 04                                     mov     edx, [edx+4]
000A92DB [0042B2F3] 8b 12                                        mov     edx, [edx]
000A92DD [0042B2F5] 89 17                                        mov     [edi], edx
000A92DF [0042B2F7] 83 f9 03                                     cmp     ecx, 3
000A92E2 [0042B2FA] 76 05                                        jbe     short near ptr unk_42B301 ; game-relative-target=0x000A92E9
000A92E4 [0042B2FC] b9 03 00 00 00                               mov     ecx, 3
000A92E9 [0042B301] 6b c9 08                                     imul    ecx, 8
000A92EC [0042B304] b8 41 53 44 3f                               mov     eax, 3F445341h
000A92F1 [0042B309] d3 e8                                        shr     eax, cl
000A92F3 [0042B30B] 88 47 05                                     mov     [edi+5], al
000A92F6 [0042B30E] c6 47 06 00                                  mov     byte ptr [edi+6], 0
000A92FA [0042B312] 8b c7                                        mov     eax, edi
000A92FC [0042B314] 5f                                           pop     edi
000A92FD [0042B315] c3                                           retn
000A92FE [0042B316] 00    db 0x00
000A92FF [0042B317] 00 8b 44 24 24 81                            add     [ebx-7EDBDBBCh], cl
000A9305 [0042B31D] 38 38                                        cmp     [eax], bh
000A9307 [0042B31F] a2 60 00 75 0f                               mov     ds:0F750060h, al
000A930C [0042B324] 8b d7                                        mov     edx, edi
000A930E [0042B326] 8b 4c 24 20                                  mov     ecx, [esp+20h]
000A9312 [0042B32A] e8 89 ff ff ff                               call    near ptr unk_42B2B8 ; game-relative-target=0x000A92A0
000A9317 [0042B32F] 89 44 24 08                                  mov     [esp+8], eax
000A931B [0042B333] 68 60 85 42 00                               push    428560h
000A9320 [0042B338] c3                                           retn
000A9321 [0042B339] 8b 44 24 28                                  mov     eax, [esp+28h]
000A9325 [0042B33D] 81 38 38 a2 60 00                            cmp     dword ptr [eax], 60A238h
000A932B [0042B343] 75 0f                                        jnz     short near ptr unk_42B354 ; game-relative-target=0x000A933C
000A932D [0042B345] 8b d6                                        mov     edx, esi
000A932F [0042B347] 8b 4c 24 34                                  mov     ecx, [esp+34h]
000A9333 [0042B34B] e8 68 ff ff ff                               call    near ptr unk_42B2B8 ; game-relative-target=0x000A92A0
000A9338 [0042B350] 89 44 24 08                                  mov     [esp+8], eax
000A933C [0042B354] 68 60 85 42 00                               push    428560h
000A9341 [0042B359] c3                                           retn
000A9342 [0042B35A] 8b 44 24 30                                  mov     eax, [esp+30h]
000A9346 [0042B35E] 81 38 38 a2 60 00                            cmp     dword ptr [eax], 60A238h
000A934C [0042B364] 75 08                                        jnz     short near ptr unk_42B36E ; game-relative-target=0x000A9356
000A934E [0042B366] c7 44 24 04 00 92 0a 00                      mov     dword ptr [esp+4], 0A9200h
000A9356 [0042B36E] 68 70 8c 42 00                               push    428C70h
000A935B [0042B373] c3                                           retn
