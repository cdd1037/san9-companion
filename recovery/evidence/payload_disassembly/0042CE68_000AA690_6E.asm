; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042CE68; baseline game VA=0x000AA690; size=110
; Relative branch annotations use the baseline game destination.
000AA690 [0042CE68] 3d fa 00 00 00                               cmp     eax, 0FAh
000AA695 [0042CE6D] 72 03                                        jb      short near ptr unk_42CE72 ; game-relative-target=0x000AA69A
000AA697 [0042CE6F] 33 d2                                        xor     edx, edx
000AA699 [0042CE71] c3                                           retn
000AA69A [0042CE72] 3c bb                                        cmp     al, 0BBh
000AA69C [0042CE74] 73 05                                        jnb     short near ptr unk_42CE7B ; game-relative-target=0x000AA6A3
000AA69E [0042CE76] 80 04 24 02                                  add     byte ptr [esp], 2
000AA6A2 [0042CE7A] c3                                           retn
000AA6A3 [0042CE7B] 55                                           push    ebp
000AA6A4 [0042CE7C] 8b e8                                        mov     ebp, eax
000AA6A6 [0042CE7E] 8d 8b e4 01 00 00                            lea     ecx, [ebx+1E4h]
000AA6AC [0042CE84] b8 e0 80 51 00                               mov     eax, 5180E0h
000AA6B1 [0042CE89] ff d0                                        call    eax
000AA6B3 [0042CE8B] 33 ff                                        xor     edi, edi
000AA6B5 [0042CE8D] 33 f6                                        xor     esi, esi
000AA6B7 [0042CE8F] 69 c7 c8 00 00 00                            imul    eax, edi, 0C8h
000AA6BD [0042CE95] 03 c6                                        add     eax, esi
000AA6BF [0042CE97] 6b c0 38                                     imul    eax, 38h ; '8'
000AA6C2 [0042CE9A] 05 b0 65 29 01                               add     eax, 12965B0h
000AA6C7 [0042CE9F] f6 40 35 04                                  test    byte ptr [eax+35h], 4
000AA6CB [0042CEA3] 75 13                                        jnz     short near ptr unk_42CEB8 ; game-relative-target=0x000AA6E0
000AA6CD [0042CEA5] 39 68 28                                     cmp     [eax+28h], ebp
000AA6D0 [0042CEA8] 75 0e                                        jnz     short near ptr unk_42CEB8 ; game-relative-target=0x000AA6E0
000AA6D2 [0042CEAA] 50                                           push    eax
000AA6D3 [0042CEAB] 8d 8b e4 01 00 00                            lea     ecx, [ebx+1E4h]
000AA6D9 [0042CEB1] b8 70 82 51 00                               mov     eax, 518270h
000AA6DE [0042CEB6] ff d0                                        call    eax
000AA6E0 [0042CEB8] 46                                           inc     esi
000AA6E1 [0042CEB9] 81 fe c8 00 00 00                            cmp     esi, 0C8h
000AA6E7 [0042CEBF] 7c ce                                        jl      short near ptr unk_42CE8F ; game-relative-target=0x000AA6B7
000AA6E9 [0042CEC1] 47                                           inc     edi
000AA6EA [0042CEC2] 81 ff c8 00 00 00                            cmp     edi, 0C8h
000AA6F0 [0042CEC8] 7c c3                                        jl      short near ptr unk_42CE8D ; game-relative-target=0x000AA6B5
000AA6F2 [0042CECA] 8b bb e8 01 00 00                            mov     edi, [ebx+1E8h]
000AA6F8 [0042CED0] 5d                                           pop     ebp
000AA6F9 [0042CED1] 80 04 24 0c                                  add     byte ptr [esp], 0Ch
000AA6FD [0042CED5] c3                                           retn
