; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429138; baseline game VA=0x000A7BD0; size=53
; Relative branch annotations use the baseline game destination.
000A7BD0 [00429138] 8b 8e 84 00 00 00                            mov     ecx, [esi+84h]
000A7BD6 [0042913E] 8b 01                                        mov     eax, [ecx]
000A7BD8 [00429140] ff 90 b4 00 00 00                            call    dword ptr [eax+0B4h]
000A7BDE [00429146] 85 c0                                        test    eax, eax
000A7BE0 [00429148] 74 1d                                        jz      short near ptr unk_429167 ; game-relative-target=0x000A7BFF
000A7BE2 [0042914A] 8b 0f                                        mov     ecx, [edi]
000A7BE4 [0042914C] 8b 86 84 00 00 00                            mov     eax, [esi+84h]
000A7BEA [00429152] 8b 11                                        mov     edx, [ecx]
000A7BEC [00429154] 6a 01                                        push    1
000A7BEE [00429156] 50                                           push    eax
000A7BEF [00429157] ff 92 a8 00 00 00                            call    dword ptr [edx+0A8h]
000A7BF5 [0042915D] 85 c0                                        test    eax, eax
000A7BF7 [0042915F] 74 06                                        jz      short near ptr unk_429167 ; game-relative-target=0x000A7BFF
000A7BF9 [00429161] 68 75 20 50 00                               push    502075h
000A7BFE [00429166] c3                                           retn
000A7BFF [00429167] 68 3d 20 50 00                               push    50203Dh
000A7C04 [0042916C] c3                                           retn
