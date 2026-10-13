; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424420; baseline game VA=0x000A3250; size=29
; Relative branch annotations use the baseline game destination.
000A3250 [00424420] 8b 8d 64 08 00 00                            mov     ecx, [ebp+864h]
000A3256 [00424426] 8a 85 68 08 00 00                            mov     al, [ebp+868h]
000A325C [0042442C] 3c 01                                        cmp     al, 1
000A325E [0042442E] 74 0c                                        jz      short near ptr unk_42443C ; game-relative-target=0x000A326C
000A3260 [00424430] 3c 03                                        cmp     al, 3
000A3262 [00424432] 7d 05                                        jge     short near ptr unk_424439 ; game-relative-target=0x000A3269
000A3264 [00424434] f6 c1 10                                     test    cl, 10h
000A3267 [00424437] 75 03                                        jnz     short near ptr unk_42443C ; game-relative-target=0x000A326C
000A3269 [00424439] 8b 49 04                                     mov     ecx, [ecx+4]
000A326C [0042443C] c3                                           retn
