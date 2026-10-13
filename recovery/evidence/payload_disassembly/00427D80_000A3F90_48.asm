; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427D80; baseline game VA=0x000A3F90; size=72
; Relative branch annotations use the baseline game destination.
000A3F90 [00427D80] 56                                           push    esi
000A3F91 [00427D81] 8b f1                                        mov     esi, ecx
000A3F93 [00427D83] 8b 4d 40                                     mov     ecx, [ebp+40h]
000A3F96 [00427D86] f6 41 20 01                                  test    byte ptr [ecx+20h], 1
000A3F9A [00427D8A] 74 3a                                        jz      short near ptr unk_427DC6 ; game-relative-target=0x000A3FD6
000A3F9C [00427D8C] 8b 45 34                                     mov     eax, [ebp+34h]
000A3F9F [00427D8F] 3c 06                                        cmp     al, 6
000A3FA1 [00427D91] 7c 33                                        jl      short near ptr unk_427DC6 ; game-relative-target=0x000A3FD6
000A3FA3 [00427D93] 3c 0b                                        cmp     al, 0Bh
000A3FA5 [00427D95] 7f 2f                                        jg      short near ptr unk_427DC6 ; game-relative-target=0x000A3FD6
000A3FA7 [00427D97] 3c 08                                        cmp     al, 8
000A3FA9 [00427D99] 7e 0c                                        jle     short near ptr unk_427DA7 ; game-relative-target=0x000A3FB7
000A3FAB [00427D9B] 8b 55 3c                                     mov     edx, [ebp+3Ch]
000A3FAE [00427D9E] 8b 42 6c                                     mov     eax, [edx+6Ch]
000A3FB1 [00427DA1] 80 78 04 08                                  cmp     byte ptr [eax+4], 8
000A3FB5 [00427DA5] 74 1f                                        jz      short near ptr unk_427DC6 ; game-relative-target=0x000A3FD6
000A3FB7 [00427DA7] 0f b7 41 e4                                  movzx   eax, word ptr [ecx-1Ch]
000A3FBB [00427DAB] 2d 00 08 00 00                               sub     eax, 800h
000A3FC0 [00427DB0] f7 d8                                        neg     eax
000A3FC2 [00427DB2] 3d 00 04 00 00                               cmp     eax, 400h
000A3FC7 [00427DB7] 7d 05                                        jge     short near ptr unk_427DBE ; game-relative-target=0x000A3FCE
000A3FC9 [00427DB9] b8 00 04 00 00                               mov     eax, 400h
000A3FCE [00427DBE] 0f af 06                                     imul    eax, [esi]
000A3FD1 [00427DC1] c1 e8 0b                                     shr     eax, 0Bh
000A3FD4 [00427DC4] 89 06                                        mov     [esi], eax
000A3FD6 [00427DC6] 5e                                           pop     esi
000A3FD7 [00427DC7] c3                                           retn
