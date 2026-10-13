; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421800; baseline game VA=0x000A27A0; size=82
; Relative branch annotations use the baseline game destination.
000A27A0 [00421800] ff 74 24 04                                  push    dword ptr [esp+4]
000A27A4 [00421804] b8 50 ee 46 00                               mov     eax, 46EE50h
000A27A9 [00421809] ff d0                                        call    eax
000A27AB [0042180B] 85 c0                                        test    eax, eax
000A27AD [0042180D] 74 40                                        jz      short near ptr unk_42184F ; game-relative-target=0x000A27EF
000A27AF [0042180F] 33 d2                                        xor     edx, edx
000A27B1 [00421811] 8b 4c 24 20                                  mov     ecx, [esp+20h]
000A27B5 [00421815] 85 c9                                        test    ecx, ecx
000A27B7 [00421817] 74 1b                                        jz      short near ptr unk_421834 ; game-relative-target=0x000A27D4
000A27B9 [00421819] 8b 41 08                                     mov     eax, [ecx+8]
000A27BC [0042181C] 8b 09                                        mov     ecx, [ecx]
000A27BE [0042181E] 83 78 54 07                                  cmp     dword ptr [eax+54h], 7
000A27C2 [00421822] 74 f1                                        jz      short near ptr unk_421815 ; game-relative-target=0x000A27B5
000A27C4 [00421824] 83 78 54 08                                  cmp     dword ptr [eax+54h], 8
000A27C8 [00421828] 74 eb                                        jz      short near ptr unk_421815 ; game-relative-target=0x000A27B5
000A27CA [0042182A] 39 50 64                                     cmp     [eax+64h], edx
000A27CD [0042182D] 7e e6                                        jle     short near ptr unk_421815 ; game-relative-target=0x000A27B5
000A27CF [0042182F] 8b 50 64                                     mov     edx, [eax+64h]
000A27D2 [00421832] eb e1                                        jmp     short near ptr unk_421815 ; game-relative-target=0x000A27B5
000A27D4 [00421834] 8b 8c 24 e0 00 00 00                         mov     ecx, [esp+0E0h]
000A27DB [0042183B] 8b 41 58                                     mov     eax, [ecx+58h]
000A27DE [0042183E] 2b 41 50                                     sub     eax, [ecx+50h]
000A27E1 [00421841] 33 c9                                        xor     ecx, ecx
000A27E3 [00421843] 85 d2                                        test    edx, edx
000A27E5 [00421845] 0f 94 c1                                     setz    cl
000A27E8 [00421848] 3b c2                                        cmp     eax, edx
000A27EA [0042184A] 0f 9f c1                                     setnle  cl
000A27ED [0042184D] 8b c1                                        mov     eax, ecx
000A27EF [0042184F] c2 04 00                                     retn    4
