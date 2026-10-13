; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429610; baseline game VA=0x000A7E50; size=90
; Relative branch annotations use the baseline game destination.
000A7E50 [00429610] 8b 44 24 04                                  mov     eax, [esp+4]
000A7E54 [00429614] 8b 08                                        mov     ecx, [eax]
000A7E56 [00429616] 0f b7 81 04 01 00 00                         movzx   eax, word ptr [ecx+104h]
000A7E5D [0042961D] 85 c0                                        test    eax, eax
000A7E5F [0042961F] 74 08                                        jz      short near ptr unk_429629 ; game-relative-target=0x000A7E69
000A7E61 [00429621] 8b 81 a0 00 00 00                            mov     eax, [ecx+0A0h]
000A7E67 [00429627] f7 d8                                        neg     eax
000A7E69 [00429629] c3                                           retn
000A7E6A [0042962A] 00    db 0x00
000A7E6B [0042962B] 00    db 0x00
000A7E6C [0042962C] 00    db 0x00
000A7E6D [0042962D] 00    db 0x00
000A7E6E [0042962E] 00    db 0x00
000A7E6F [0042962F] 00 0f                                        add     [edi], cl
000A7E71 [00429631] b7 81                                        mov     bh, 81h
000A7E73 [00429633] 04 01                                        add     al, 1
000A7E75 [00429635] 00    db 0x00
000A7E76 [00429636] 00 85 c0 75 04 83                            add     [ebp-7CFB8A40h], al
000A7E7C [0042963C] c8 ff c3 c1                                  enter   0FFFFC3FFh, 0C1h
000A7E80 [00429640] e8 04 f6 c4 08                               call    near ptr 9078C49h ; game-relative-target=0x08CF7489
000A7E85 [00429645] 74 03                                        jz      short near ptr unk_42964A ; game-relative-target=0x000A7E8A
000A7E87 [00429647] 8b 41 04                                     mov     eax, [ecx+4]
000A7E8A [0042964A] 25 ff 03 00 00                               and     eax, 3FFh
000A7E8F [0042964F] c3                                           retn
000A7E90 [00429650] 8b 44 24 04                                  mov     eax, [esp+4]
000A7E94 [00429654] 8b 08                                        mov     ecx, [eax]
000A7E96 [00429656] 33 c0                                        xor     eax, eax
000A7E98 [00429658] 0f b7 91 04 01 00 00                         movzx   edx, word ptr [ecx+104h]
000A7E9F [0042965F] 85 d2                                        test    edx, edx
000A7EA1 [00429661] 74 06                                        jz      short near ptr unk_429669 ; game-relative-target=0x000A7EA9
000A7EA3 [00429663] f6 c6 80                                     test    dh, 80h
000A7EA6 [00429666] 0f 95 c0                                     setnz   al
000A7EA9 [00429669] c3                                           retn
