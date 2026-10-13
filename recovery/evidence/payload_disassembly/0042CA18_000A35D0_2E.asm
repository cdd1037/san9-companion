; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042CA18; baseline game VA=0x000A35D0; size=46
; Relative branch annotations use the baseline game destination.
000A35D0 [0042CA18] 8b 16                                        mov     edx, [esi]
000A35D2 [0042CA1A] ff 92 ec 00 00 00                            call    dword ptr [edx+0ECh]
000A35D8 [0042CA20] 8d 8e c4 01 00 00                            lea     ecx, [esi+1C4h]
000A35DE [0042CA26] 39 01                                        cmp     [ecx], eax
000A35E0 [0042CA28] 7d 01                                        jge     short near ptr unk_42CA2B ; game-relative-target=0x000A35E3
000A35E2 [0042CA2A] 47                                           inc     edi
000A35E3 [0042CA2B] 8b 41 08                                     mov     eax, [ecx+8]
000A35E6 [0042CA2E] 3b 41 10                                     cmp     eax, [ecx+10h]
000A35E9 [0042CA31] 7c 11                                        jl      short near ptr unk_42CA44 ; game-relative-target=0x000A35FC
000A35EB [0042CA33] 8b 51 0c                                     mov     edx, [ecx+0Ch]
000A35EE [0042CA36] 3b 51 14                                     cmp     edx, [ecx+14h]
000A35F1 [0042CA39] 7c 09                                        jl      short near ptr unk_42CA44 ; game-relative-target=0x000A35FC
000A35F3 [0042CA3B] 0f b7 46 3c                                  movzx   eax, word ptr [esi+3Ch]
000A35F7 [0042CA3F] 3b 41 04                                     cmp     eax, [ecx+4]
000A35FA [0042CA42] 7d 01                                        jge     short near ptr unk_42CA45 ; game-relative-target=0x000A35FD
000A35FC [0042CA44] 47                                           inc     edi
000A35FD [0042CA45] c3                                           retn
