; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428534; baseline game VA=0x000A7600; size=164
; Relative branch annotations use the baseline game destination.
000A7600 [00428534] 55                                           push    ebp
000A7601 [00428535] 53                                           push    ebx
000A7602 [00428536] 83 ec 20                                     sub     esp, 20h ; ' '
000A7605 [00428539] 8b cc                                        mov     ecx, esp
000A7607 [0042853B] b8 c0 3c 47 00                               mov     eax, 473CC0h
000A760C [00428540] ff d0                                        call    eax
000A760E [00428542] 33 db                                        xor     ebx, ebx
000A7610 [00428544] bd b0 93 4b 01                               mov     ebp, 14B93B0h
000A7615 [00428549] 8b 47 04                                     mov     eax, [edi+4]
000A7618 [0042854C] 39 45 50                                     cmp     [ebp+50h], eax
000A761B [0042854F] 75 13                                        jnz     short near ptr unk_428564 ; game-relative-target=0x000A7630
000A761D [00428551] f6 45 20 02                                  test    byte ptr [ebp+20h], 2
000A7621 [00428555] 75 0d                                        jnz     short near ptr unk_428564 ; game-relative-target=0x000A7630
000A7623 [00428557] 03 5d 30                                     add     ebx, [ebp+30h]
000A7626 [0042855A] 8b cc                                        mov     ecx, esp
000A7628 [0042855C] 55                                           push    ebp
000A7629 [0042855D] b8 70 ef 46 00                               mov     eax, 46EF70h
000A762E [00428562] ff d0                                        call    eax
000A7630 [00428564] 81 c5 04 01 00 00                            add     ebp, 104h
000A7636 [0042856A] 81 fd f8 f2 4e 01                            cmp     ebp, 14EF2F8h
000A763C [00428570] 7c d7                                        jl      short near ptr unk_428549 ; game-relative-target=0x000A7615
000A763E [00428572] 54                                           push    esp
000A763F [00428573] 8b cf                                        mov     ecx, edi
000A7641 [00428575] b8 00 75 0a 00                               mov     eax, 0A7500h
000A7646 [0042857A] ff d0                                        call    eax
000A7648 [0042857C] 3b d8                                        cmp     ebx, eax
000A764A [0042857E] 7d 24                                        jge     short near ptr unk_4285A4 ; game-relative-target=0x000A7670
000A764C [00428580] 2b 47 30                                     sub     eax, [edi+30h]
000A764F [00428583] 6b c0 0a                                     imul    eax, 0Ah
000A7652 [00428586] c1 e8 04                                     shr     eax, 4
000A7655 [00428589] 3b c3                                        cmp     eax, ebx
000A7657 [0042858B] 7c 15                                        jl      short near ptr unk_4285A2 ; game-relative-target=0x000A766E
000A7659 [0042858D] 8b 6c 24 04                                  mov     ebp, [esp+4]
000A765D [00428591] 8b 4d 08                                     mov     ecx, [ebp+8]
000A7660 [00428594] b8 d0 00 0a 00                               mov     eax, 0A00D0h
000A7665 [00428599] ff d0                                        call    eax
000A7667 [0042859B] 8b 6d 00                                     mov     ebp, [ebp+0]
000A766A [0042859E] 85 ed                                        test    ebp, ebp
000A766C [004285A0] 75 ef                                        jnz     short near ptr unk_428591 ; game-relative-target=0x000A765D
000A766E [004285A2] eb 1d                                        jmp     short near ptr unk_4285C1 ; game-relative-target=0x000A768D
000A7670 [004285A4] 8b e8                                        mov     ebp, eax
000A7672 [004285A6] 8b 7c 24 04                                  mov     edi, [esp+4]
000A7676 [004285AA] 8b 4f 08                                     mov     ecx, [edi+8]
000A7679 [004285AD] 2b 59 30                                     sub     ebx, [ecx+30h]
000A767C [004285B0] 3b dd                                        cmp     ebx, ebp
000A767E [004285B2] 7c 0d                                        jl      short near ptr unk_4285C1 ; game-relative-target=0x000A768D
000A7680 [004285B4] b8 d0 00 0a 00                               mov     eax, 0A00D0h
000A7685 [004285B9] ff d0                                        call    eax
000A7687 [004285BB] 8b 3f                                        mov     edi, [edi]
000A7689 [004285BD] 85 ff                                        test    edi, edi
000A768B [004285BF] 75 e9                                        jnz     short near ptr unk_4285AA ; game-relative-target=0x000A7676
000A768D [004285C1] 8b cc                                        mov     ecx, esp
000A768F [004285C3] b8 e0 80 51 00                               mov     eax, 5180E0h
000A7694 [004285C8] ff d0                                        call    eax
000A7696 [004285CA] 83 c4 20                                     add     esp, 20h ; ' '
000A7699 [004285CD] 5b                                           pop     ebx
000A769A [004285CE] 5d                                           pop     ebp
000A769B [004285CF] 5f                                           pop     edi
000A769C [004285D0] 8b ce                                        mov     ecx, esi
000A769E [004285D2] 68 70 0e 46 00                               push    460E70h
000A76A3 [004285D7] c3                                           retn
