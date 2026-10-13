; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420D10; baseline game VA=0x000A0300; size=326
; Relative branch annotations use the baseline game destination.
000A0300 [00420D10] b8 90 c9 46 00                               mov     eax, 46C990h
000A0305 [00420D15] ff d0                                        call    eax
000A0307 [00420D17] 56                                           push    esi
000A0308 [00420D18] 57                                           push    edi
000A0309 [00420D19] a1 e4 fb 43 00                               mov     eax, ds:43FBE4h
000A030E [00420D1E] 3b d8                                        cmp     ebx, eax
000A0310 [00420D20] 74 17                                        jz      short near ptr unk_420D39 ; game-relative-target=0x000A0329
000A0312 [00420D22] 85 c0                                        test    eax, eax
000A0314 [00420D24] 75 10                                        jnz     short near ptr unk_420D36 ; game-relative-target=0x000A0326
000A0316 [00420D26] 8b cb                                        mov     ecx, ebx
000A0318 [00420D28] 8b 01                                        mov     eax, [ecx]
000A031A [00420D2A] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A031D [00420D2D] 80 b8 00 0e 0a 00 00                         cmp     byte ptr [eax+0A0E00h], 0
000A0324 [00420D34] 74 0b                                        jz      short near ptr unk_420D41 ; game-relative-target=0x000A0331
000A0326 [00420D36] 5f                                           pop     edi
000A0327 [00420D37] 5e                                           pop     esi
000A0328 [00420D38] c3                                           retn
000A0329 [00420D39] 8b 1d e8 fb 43 00                            mov     ebx, ds:43FBE8h
000A032F [00420D3F] eb 32                                        jmp     short near ptr unk_420D73 ; game-relative-target=0x000A0363
000A0331 [00420D41] 53                                           push    ebx
000A0332 [00420D42] 54                                           push    esp
000A0333 [00420D43] 8b cd                                        mov     ecx, ebp
000A0335 [00420D45] b8 90 11 4a 00                               mov     eax, 4A1190h
000A033A [00420D4A] ff d0                                        call    eax
000A033C [00420D4C] 8b f0                                        mov     esi, eax
000A033E [00420D4E] b8 a0 12 4a 00                               mov     eax, 4A12A0h
000A0343 [00420D53] ff d0                                        call    eax
000A0345 [00420D55] 2b f0                                        sub     esi, eax
000A0347 [00420D57] 3d 20 4e 00 00                               cmp     eax, 4E20h
000A034C [00420D5C] 7d 05                                        jge     short near ptr unk_420D63 ; game-relative-target=0x000A0353
000A034E [00420D5E] b8 20 4e 00 00                               mov     eax, 4E20h
000A0353 [00420D63] 6b c0 0b                                     imul    eax, 0Bh
000A0356 [00420D66] c1 e8 04                                     shr     eax, 4
000A0359 [00420D69] 3b f0                                        cmp     esi, eax
000A035B [00420D6B] 7f c9                                        jg      short near ptr unk_420D36 ; game-relative-target=0x000A0326
000A035D [00420D6D] 89 35 ec fb 43 00                            mov     ds:43FBECh, esi
000A0363 [00420D73] 8b 4b 44                                     mov     ecx, [ebx+44h]
000A0366 [00420D76] 0f b6 41 04                                  movzx   eax, byte ptr [ecx+4]
000A036A [00420D7A] c1 e0 03                                     shl     eax, 3
000A036D [00420D7D] 05 00 6e 0a 00                               add     eax, 0A6E00h
000A0372 [00420D82] 8b f0                                        mov     esi, eax
000A0374 [00420D84] bf 08 00 00 00                               mov     edi, 8
000A0379 [00420D89] a1 e4 fb 43 00                               mov     eax, ds:43FBE4h
000A037E [00420D8E] 85 c0                                        test    eax, eax
000A0380 [00420D90] 74 11                                        jz      short near ptr unk_420DA3 ; game-relative-target=0x000A0393
000A0382 [00420D92] 8a 50 04                                     mov     dl, [eax+4]
000A0385 [00420D95] 38 16                                        cmp     [esi], dl
000A0387 [00420D97] 74 06                                        jz      short near ptr unk_420D9F ; game-relative-target=0x000A038F
000A0389 [00420D99] 46                                           inc     esi
000A038A [00420D9A] 4f                                           dec     edi
000A038B [00420D9B] 75 f8                                        jnz     short near ptr unk_420D95 ; game-relative-target=0x000A0385
000A038D [00420D9D] eb 66                                        jmp     short near ptr unk_420E05 ; game-relative-target=0x000A03F5
000A038F [00420D9F] 46                                           inc     esi
000A0390 [00420DA0] 4f                                           dec     edi
000A0391 [00420DA1] 74 62                                        jz      short near ptr unk_420E05 ; game-relative-target=0x000A03F5
000A0393 [00420DA3] 0f b6 06                                     movzx   eax, byte ptr [esi]
000A0396 [00420DA6] 50                                           push    eax
000A0397 [00420DA7] b8 70 2f 45 00                               mov     eax, 452F70h
000A039C [00420DAC] ff d0                                        call    eax
000A039E [00420DAE] 5a                                           pop     edx
000A039F [00420DAF] 85 c0                                        test    eax, eax
000A03A1 [00420DB1] 74 4c                                        jz      short near ptr unk_420DFF ; game-relative-target=0x000A03EF
000A03A3 [00420DB3] 8b 90 cc 00 00 00                            mov     edx, [eax+0CCh]
000A03A9 [00420DB9] 85 d2                                        test    edx, edx
000A03AB [00420DBB] 74 42                                        jz      short near ptr unk_420DFF ; game-relative-target=0x000A03EF
000A03AD [00420DBD] 8b 8a b8 00 00 00                            mov     ecx, [edx+0B8h]
000A03B3 [00420DC3] 3b 4d 38                                     cmp     ecx, [ebp+38h]
000A03B6 [00420DC6] 75 37                                        jnz     short near ptr unk_420DFF ; game-relative-target=0x000A03EF
000A03B8 [00420DC8] 83 b8 e8 00 00 00 00                         cmp     dword ptr [eax+0E8h], 0
000A03BF [00420DCF] 7e 2e                                        jle     short near ptr unk_420DFF ; game-relative-target=0x000A03EF
000A03C1 [00420DD1] 50                                           push    eax
000A03C2 [00420DD2] 54                                           push    esp
000A03C3 [00420DD3] 8b cd                                        mov     ecx, ebp
000A03C5 [00420DD5] b8 70 12 4a 00                               mov     eax, 4A1270h
000A03CA [00420DDA] ff d0                                        call    eax
000A03CC [00420DDC] 59                                           pop     ecx
000A03CD [00420DDD] 85 c0                                        test    eax, eax
000A03CF [00420DDF] 7f 1e                                        jg      short near ptr unk_420DFF ; game-relative-target=0x000A03EF
000A03D1 [00420DE1] 56                                           push    esi
000A03D2 [00420DE2] 51                                           push    ecx
000A03D3 [00420DE3] 51                                           push    ecx
000A03D4 [00420DE4] 54                                           push    esp
000A03D5 [00420DE5] 8b cd                                        mov     ecx, ebp
000A03D7 [00420DE7] b8 90 11 4a 00                               mov     eax, 4A1190h
000A03DC [00420DEC] ff d0                                        call    eax
000A03DE [00420DEE] 8b f0                                        mov     esi, eax
000A03E0 [00420DF0] b8 a0 12 4a 00                               mov     eax, 4A12A0h
000A03E5 [00420DF5] ff d0                                        call    eax
000A03E7 [00420DF7] 59                                           pop     ecx
000A03E8 [00420DF8] 8b d6                                        mov     edx, esi
000A03EA [00420DFA] 3b f0                                        cmp     esi, eax
000A03EC [00420DFC] 5e                                           pop     esi
000A03ED [00420DFD] 7e 0a                                        jle     short near ptr unk_420E09 ; game-relative-target=0x000A03F9
000A03EF [00420DFF] 83 c6 01                                     add     esi, 1
000A03F2 [00420E02] 4f                                           dec     edi
000A03F3 [00420E03] 75 9e                                        jnz     short near ptr unk_420DA3 ; game-relative-target=0x000A0393
000A03F5 [00420E05] 33 f6                                        xor     esi, esi
000A03F7 [00420E07] eb 3e                                        jmp     short near ptr unk_420E47 ; game-relative-target=0x000A0437
000A03F9 [00420E09] 8b f1                                        mov     esi, ecx
000A03FB [00420E0B] 81 c2 40 1f 00 00                            add     edx, 1F40h
000A0401 [00420E11] 3b d0                                        cmp     edx, eax
000A0403 [00420E13] eb 02                                        jmp     short near ptr unk_420E17 ; game-relative-target=0x000A0407
000A0405 [00420E15] 8b c2                                        mov     eax, edx
000A0407 [00420E17] 3d 10 27 00 00                               cmp     eax, 2710h
000A040C [00420E1C] 7d 05                                        jge     short near ptr unk_420E23 ; game-relative-target=0x000A0413
000A040E [00420E1E] b8 10 27 00 00                               mov     eax, 2710h
000A0413 [00420E23] 03 05 ec fb 43 00                            add     eax, ds:43FBECh
000A0419 [00420E29] 05 88 13 00 00                               add     eax, 1388h
000A041E [00420E2E] 51                                           push    ecx
000A041F [00420E2F] 8b d4                                        mov     edx, esp
000A0421 [00420E31] 50                                           push    eax
000A0422 [00420E32] 52                                           push    edx
000A0423 [00420E33] 8b cd                                        mov     ecx, ebp
000A0425 [00420E35] b8 60 11 4a 00                               mov     eax, 4A1160h
000A042A [00420E3A] ff d0                                        call    eax
000A042C [00420E3C] 8d 4c 24 30                                  lea     ecx, [esp+30h]
000A0430 [00420E40] b8 70 ef 46 00                               mov     eax, 46EF70h
000A0435 [00420E45] ff d0                                        call    eax
000A0437 [00420E47] 89 35 e4 fb 43 00                            mov     ds:43FBE4h, esi
000A043D [00420E4D] 89 1d e8 fb 43 00                            mov     ds:43FBE8h, ebx
000A0443 [00420E53] 5f                                           pop     edi
000A0444 [00420E54] 5e                                           pop     esi
000A0445 [00420E55] c3                                           retn
