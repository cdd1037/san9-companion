; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C4F0; baseline game VA=0x000AA7B0; size=78
; Relative branch annotations use the baseline game destination.
000AA7B0 [0042C4F0] 83 c9 ff                                     or      ecx, 0FFFFFFFFh
000AA7B3 [0042C4F3] 41                                           inc     ecx
000AA7B4 [0042C4F4] 81 f9 51 03 00 00                            cmp     ecx, 351h
000AA7BA [0042C4FA] 7f 3d                                        jg      short near ptr dword_42C4FC+3Dh ; game-relative-target=0x000AA7F9
000AA7BC [0042C4FC] 69 c1 04 01 00 00                            imul    eax, ecx, 104h
000AA7C2 [0042C502] 05 b0 93 4b 01                               add     eax, 14B93B0h
000AA7C7 [0042C507] 3b c6                                        cmp     eax, esi
000AA7C9 [0042C509] 74 e8                                        jz      short near ptr unk_42C4F3 ; game-relative-target=0x000AA7B3
000AA7CB [0042C50B] 83 78 24 00                                  cmp     dword ptr [eax+24h], 0
000AA7CF [0042C50F] 74 e2                                        jz      short near ptr unk_42C4F3 ; game-relative-target=0x000AA7B3
000AA7D1 [0042C511] f6 40 20 02                                  test    byte ptr [eax+20h], 2
000AA7D5 [0042C515] 75 dc                                        jnz     short near ptr unk_42C4F3 ; game-relative-target=0x000AA7B3
000AA7D7 [0042C517] 69 c1 90 00 00 00                            imul    eax, ecx, 90h
000AA7DD [0042C51D] 05 6c dc 54 01                               add     eax, 154DC6Ch
000AA7E2 [0042C522] 8b 10                                        mov     edx, [eax]
000AA7E4 [0042C524] 3b 57 04                                     cmp     edx, [edi+4]
000AA7E7 [0042C527] 75 ca                                        jnz     short near ptr unk_42C4F3 ; game-relative-target=0x000AA7B3
000AA7E9 [0042C529] 8b 50 04                                     mov     edx, [eax+4]
000AA7EC [0042C52C] 3b 57 08                                     cmp     edx, [edi+8]
000AA7EF [0042C52F] 75 c2                                        jnz     short near ptr unk_42C4F3 ; game-relative-target=0x000AA7B3
000AA7F1 [0042C531] 83 47 04 05                                  add     dword ptr [edi+4], 5
000AA7F5 [0042C535] 83 47 08 05                                  add     dword ptr [edi+8], 5
000AA7F9 [0042C539] 8b 16                                        mov     edx, [esi]
000AA7FB [0042C53B] c2 14 00                                     retn    14h
