; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424298; baseline game VA=0x000A3200; size=79
; Relative branch annotations use the baseline game destination.
000A3200 [00424298] 6a 23                                        push    23h ; '#'
000A3202 [0042429A] b8 b0 f7 43 00                               mov     eax, 43F7B0h
000A3207 [0042429F] ff d0                                        call    eax
000A3209 [004242A1] b9 38 3c 25 01                               mov     ecx, 1253C38h
000A320E [004242A6] 33 d2                                        xor     edx, edx
000A3210 [004242A8] f6 41 34 30                                  test    byte ptr [ecx+34h], 30h ; '0'
000A3214 [004242AC] 74 2a                                        jz      short near ptr unk_4242D8 ; game-relative-target=0x000A3240
000A3216 [004242AE] 3b 89 b8 00 00 00                            cmp     ecx, [ecx+0B8h]
000A321C [004242B4] 75 22                                        jnz     short near ptr unk_4242D8 ; game-relative-target=0x000A3240
000A321E [004242B6] 3b ce                                        cmp     ecx, esi
000A3220 [004242B8] 74 1e                                        jz      short near ptr unk_4242D8 ; game-relative-target=0x000A3240
000A3222 [004242BA] 0f b6 41 14                                  movzx   eax, byte ptr [ecx+14h]
000A3226 [004242BE] 24 0f                                        and     al, 0Fh
000A3228 [004242C0] 3c 05                                        cmp     al, 5
000A322A [004242C2] 7d 02                                        jge     short near ptr unk_4242C6 ; game-relative-target=0x000A322E
000A322C [004242C4] 04 08                                        add     al, 8
000A322E [004242C6] 03 41 1c                                     add     eax, [ecx+1Ch]
000A3231 [004242C9] 3d e8 03 00 00                               cmp     eax, 3E8h
000A3236 [004242CE] 7e 05                                        jle     short near ptr unk_4242D5 ; game-relative-target=0x000A323D
000A3238 [004242D0] b8 e8 03 00 00                               mov     eax, 3E8h
000A323D [004242D5] 89 41 1c                                     mov     [ecx+1Ch], eax
000A3240 [004242D8] 81 c1 d4 00 00 00                            add     ecx, 0D4h
000A3246 [004242DE] 42                                           inc     edx
000A3247 [004242DF] 80 fa 32                                     cmp     dl, 32h ; '2'
000A324A [004242E2] 7c c4                                        jl      short near ptr unk_4242A8 ; game-relative-target=0x000A3210
000A324C [004242E4] c2 04 00                                     retn    4
