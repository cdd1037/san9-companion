; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427A10; baseline game VA=0x000A1640; size=78
; Relative branch annotations use the baseline game destination.
000A1640 [00427A10] b8 00 e9 46 00                               mov     eax, 46E900h
000A1645 [00427A15] ff d0                                        call    eax
000A1647 [00427A17] 8b f8                                        mov     edi, eax
000A1649 [00427A19] bb 70 f7 44 00                               mov     ebx, 44F770h
000A164E [00427A1E] 8b 8e 80 00 00 00                            mov     ecx, [esi+80h]
000A1654 [00427A24] 8b 51 70                                     mov     edx, [ecx+70h]
000A1657 [00427A27] 0f b6 42 04                                  movzx   eax, byte ptr [edx+4]
000A165B [00427A2B] 83 e8 15                                     sub     eax, 15h
000A165E [00427A2E] 85 c0                                        test    eax, eax
000A1660 [00427A30] 7c 29                                        jl      short near ptr unk_427A5B ; game-relative-target=0x000A168B
000A1662 [00427A32] 3c 02                                        cmp     al, 2
000A1664 [00427A34] 7f 25                                        jg      short near ptr unk_427A5B ; game-relative-target=0x000A168B
000A1666 [00427A36] 74 0b                                        jz      short near ptr unk_427A43 ; game-relative-target=0x000A1673
000A1668 [00427A38] 04 0c                                        add     al, 0Ch
000A166A [00427A3A] 50                                           push    eax
000A166B [00427A3B] 8b cf                                        mov     ecx, edi
000A166D [00427A3D] ff d3                                        call    ebx
000A166F [00427A3F] 85 c0                                        test    eax, eax
000A1671 [00427A41] 75 18                                        jnz     short near ptr unk_427A5B ; game-relative-target=0x000A168B
000A1673 [00427A43] 6a 0e                                        push    0Eh
000A1675 [00427A45] 8b cf                                        mov     ecx, edi
000A1677 [00427A47] ff d3                                        call    ebx
000A1679 [00427A49] 85 c0                                        test    eax, eax
000A167B [00427A4B] 75 0e                                        jnz     short near ptr unk_427A5B ; game-relative-target=0x000A168B
000A167D [00427A4D] ff 15 dc f2 5f 00                            call    dword ptr ds:5FF2DCh
000A1683 [00427A53] a8 01                                        test    al, 1
000A1685 [00427A55] 75 04                                        jnz     short near ptr unk_427A5B ; game-relative-target=0x000A168B
000A1687 [00427A57] c6 04 24 2a                                  mov     byte ptr [esp], 2Ah ; '*'
000A168B [00427A5B] 8b c7                                        mov     eax, edi
000A168D [00427A5D] c3                                           retn
