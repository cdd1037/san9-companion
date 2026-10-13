; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004251F4; baseline game VA=0x000A54B0; size=80
; Relative branch annotations use the baseline game destination.
000A54B0 [004251F4] 85 f6                                        test    esi, esi
000A54B2 [004251F6] 75 01                                        jnz     short near ptr unk_4251F9 ; game-relative-target=0x000A54B5
000A54B4 [004251F8] c3                                           retn
000A54B5 [004251F9] 7f 06                                        jg      short near ptr unk_425201 ; game-relative-target=0x000A54BD
000A54B7 [004251FB] 8b 4c 24 70                                  mov     ecx, [esp+70h]
000A54BB [004251FF] eb 3a                                        jmp     short near ptr unk_42523B ; game-relative-target=0x000A54F7
000A54BD [00425201] 80 7f 06 05                                  cmp     byte ptr [edi+6], 5
000A54C1 [00425205] 75 08                                        jnz     short near ptr unk_42520F ; game-relative-target=0x000A54CB
000A54C3 [00425207] 81 fe 00 17 00 00                            cmp     esi, 1700h
000A54C9 [0042520D] 7e 34                                        jle     short near ptr unk_425243 ; game-relative-target=0x000A54FF
000A54CB [0042520F] 80 7f 7c 01                                  cmp     byte ptr [edi+7Ch], 1
000A54CF [00425213] 75 2e                                        jnz     short near ptr unk_425243 ; game-relative-target=0x000A54FF
000A54D1 [00425215] f6 47 7a 40                                  test    byte ptr [edi+7Ah], 40h ; '@'
000A54D5 [00425219] 75 28                                        jnz     short near ptr unk_425243 ; game-relative-target=0x000A54FF
000A54D7 [0042521B] 8b 87 cc 00 00 00                            mov     eax, [edi+0CCh]
000A54DD [00425221] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A54E1 [00425225] 75 1c                                        jnz     short near ptr unk_425243 ; game-relative-target=0x000A54FF
000A54E3 [00425227] 8b cf                                        mov     ecx, edi
000A54E5 [00425229] 8b 01                                        mov     eax, [ecx]
000A54E7 [0042522B] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A54EA [0042522E] 80 b8 00 0d 0a 00 08                         cmp     byte ptr [eax+0A0D00h], 8
000A54F1 [00425235] 7d 0c                                        jge     short near ptr unk_425243 ; game-relative-target=0x000A54FF
000A54F3 [00425237] 8b 4c 24 6c                                  mov     ecx, [esp+6Ch]
000A54F7 [0042523B] 57                                           push    edi
000A54F8 [0042523C] b8 70 ef 46 00                               mov     eax, 46EF70h
000A54FD [00425241] ff d0                                        call    eax
000A54FF [00425243] c3                                           retn
