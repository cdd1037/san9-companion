; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424BC8; baseline game VA=0x000A2DB0; size=48
; Relative branch annotations use the baseline game destination.
000A2DB0 [00424BC8] 53                                           push    ebx
000A2DB1 [00424BC9] 8b 5c 24 08                                  mov     ebx, [esp+8]
000A2DB5 [00424BCD] 8d 44 24 08                                  lea     eax, [esp+8]
000A2DB9 [00424BD1] 6a 01                                        push    1
000A2DBB [00424BD3] 6a 05                                        push    5
000A2DBD [00424BD5] 50                                           push    eax
000A2DBE [00424BD6] 8b 01                                        mov     eax, [ecx]
000A2DC0 [00424BD8] ff 90 c8 00 00 00                            call    dword ptr [eax+0C8h]
000A2DC6 [00424BDE] 85 c0                                        test    eax, eax
000A2DC8 [00424BE0] 74 04                                        jz      short near ptr unk_424BE6 ; game-relative-target=0x000A2DCE
000A2DCA [00424BE2] 8b 44 24 08                                  mov     eax, [esp+8]
000A2DCE [00424BE6] 2d 58 02 00 00                               sub     eax, 258h
000A2DD3 [00424BEB] c1 e0 15                                     shl     eax, 15h
000A2DD6 [00424BEE] f7 eb                                        imul    ebx
000A2DD8 [00424BF0] 03 da                                        add     ebx, edx
000A2DDA [00424BF2] 8b c3                                        mov     eax, ebx
000A2DDC [00424BF4] 5b                                           pop     ebx
000A2DDD [00424BF5] c2 04 00                                     retn    4
