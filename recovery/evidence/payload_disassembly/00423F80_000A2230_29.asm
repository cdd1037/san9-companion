; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423F80; baseline game VA=0x000A2230; size=41
; Relative branch annotations use the baseline game destination.
000A2230 [00423F80] 8b 8c 24 e0 00 00 00                         mov     ecx, [esp+0E0h]
000A2237 [00423F87] b8 e0 2d 0a 00                               mov     eax, 0A2DE0h
000A223C [00423F8C] ff d0                                        call    eax
000A223E [00423F8E] 3c 02                                        cmp     al, 2
000A2240 [00423F90] 74 0d                                        jz      short near ptr unk_423F9F ; game-relative-target=0x000A224F
000A2242 [00423F92] 3c 01                                        cmp     al, 1
000A2244 [00423F94] 74 06                                        jz      short near ptr unk_423F9C ; game-relative-target=0x000A224C
000A2246 [00423F96] 58                                           pop     eax
000A2247 [00423F97] 68 67 1c 4a 00                               push    4A1C67h
000A224C [00423F9C] c2 04 00                                     retn    4
000A224F [00423F9F] f6 44 24 58 01                               test    byte ptr [esp+58h], 1
000A2254 [00423FA4] 75 f0                                        jnz     short near ptr unk_423F96 ; game-relative-target=0x000A2246
000A2256 [00423FA6] c2 04 00                                     retn    4
