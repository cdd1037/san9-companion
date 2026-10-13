; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422E90; baseline game VA=0x000A28D0; size=40
; Relative branch annotations use the baseline game destination.
000A28D0 [00422E90] 8b b7 b8 00 00 00                            mov     esi, [edi+0B8h]
000A28D6 [00422E96] 3b c6                                        cmp     eax, esi
000A28D8 [00422E98] 75 01                                        jnz     short near ptr unk_422E9B ; game-relative-target=0x000A28DB
000A28DA [00422E9A] c3                                           retn
000A28DB [00422E9B] 8b 8c 24 88 00 00 00                         mov     ecx, [esp+88h]
000A28E2 [00422EA2] 8b 89 cc 00 00 00                            mov     ecx, [ecx+0CCh]
000A28E8 [00422EA8] 85 c9                                        test    ecx, ecx
000A28EA [00422EAA] 74 06                                        jz      short near ptr unk_422EB2 ; game-relative-target=0x000A28F2
000A28EC [00422EAC] f6 41 34 01                                  test    byte ptr [ecx+34h], 1
000A28F0 [00422EB0] 75 03                                        jnz     short near ptr unk_422EB5 ; game-relative-target=0x000A28F5
000A28F2 [00422EB2] 3b c6                                        cmp     eax, esi
000A28F4 [00422EB4] c3                                           retn
000A28F5 [00422EB5] 3b c0                                        cmp     eax, eax
000A28F7 [00422EB7] c3                                           retn
