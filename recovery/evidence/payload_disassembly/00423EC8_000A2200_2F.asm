; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423EC8; baseline game VA=0x000A2200; size=47
; Relative branch annotations use the baseline game destination.
000A2200 [00423EC8] 50                                           push    eax
000A2201 [00423EC9] b8 d0 b8 48 00                               mov     eax, 48B8D0h
000A2206 [00423ECE] ff d0                                        call    eax
000A2208 [00423ED0] 85 c0                                        test    eax, eax
000A220A [00423ED2] 75 14                                        jnz     short near ptr unk_423EE8 ; game-relative-target=0x000A2220
000A220C [00423ED4] 8b 8c 24 2c 01 00 00                         mov     ecx, [esp+12Ch]
000A2213 [00423EDB] b8 e0 2d 0a 00                               mov     eax, 0A2DE0h
000A2218 [00423EE0] ff d0                                        call    eax
000A221A [00423EE2] 3c 02                                        cmp     al, 2
000A221C [00423EE4] 74 05                                        jz      short near ptr unk_423EEB ; game-relative-target=0x000A2223
000A221E [00423EE6] 34 01                                        xor     al, 1
000A2220 [00423EE8] c2 04 00                                     retn    4
000A2223 [00423EEB] 6a 32                                        push    32h ; '2'
000A2225 [00423EED] b8 f0 ef 4a 00                               mov     eax, 4AEFF0h
000A222A [00423EF2] ff d0                                        call    eax
000A222C [00423EF4] c2 04 00                                     retn    4
