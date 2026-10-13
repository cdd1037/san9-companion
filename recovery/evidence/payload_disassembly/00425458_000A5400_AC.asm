; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425458; baseline game VA=0x000A5400; size=172
; Relative branch annotations use the baseline game destination.
000A5400 [00425458] b8 a0 c8 45 00                               mov     eax, 45C8A0h
000A5405 [0042545D] ff d0                                        call    eax
000A5407 [0042545F] 8b 48 48                                     mov     ecx, [eax+48h]
000A540A [00425462] 85 c9                                        test    ecx, ecx
000A540C [00425464] 75 08                                        jnz     short near ptr unk_42546E ; game-relative-target=0x000A5416
000A540E [00425466] 68 86 b8 4b 00                               push    4BB886h
000A5413 [0042546B] c2 04 00                                     retn    4
000A5416 [0042546E] f6 40 3d 80                                  test    byte ptr [eax+3Dh], 80h
000A541A [00425472] 75 f2                                        jnz     short near ptr unk_425466 ; game-relative-target=0x000A540E
000A541C [00425474] 80 79 04 0a                                  cmp     byte ptr [ecx+4], 0Ah
000A5420 [00425478] 7d 2d                                        jge     short near ptr unk_4254A7 ; game-relative-target=0x000A544F
000A5422 [0042547A] 50                                           push    eax
000A5423 [0042547B] 50                                           push    eax
000A5424 [0042547C] 8b cd                                        mov     ecx, ebp
000A5426 [0042547E] 8b 01                                        mov     eax, [ecx]
000A5428 [00425480] ff 50 30                                     call    dword ptr [eax+30h]
000A542B [00425483] 50                                           push    eax
000A542C [00425484] b8 00 07 4b 00                               mov     eax, 4B0700h
000A5431 [00425489] ff d0                                        call    eax
000A5433 [0042548B] 83 c4 08                                     add     esp, 8
000A5436 [0042548E] 85 c0                                        test    eax, eax
000A5438 [00425490] 58                                           pop     eax
000A5439 [00425491] 74 d3                                        jz      short near ptr unk_425466 ; game-relative-target=0x000A540E
000A543B [00425493] 8b 88 cc 00 00 00                            mov     ecx, [eax+0CCh]
000A5441 [00425499] f6 41 34 01                                  test    byte ptr [ecx+34h], 1
000A5445 [0042549D] 74 08                                        jz      short near ptr unk_4254A7 ; game-relative-target=0x000A544F
000A5447 [0042549F] 68 dc b8 4b 00                               push    4BB8DCh
000A544C [004254A4] c2 04 00                                     retn    4
000A544F [004254A7] 53                                           push    ebx
000A5450 [004254A8] 83 ec 18                                     sub     esp, 18h
000A5453 [004254AB] 8b d8                                        mov     ebx, eax
000A5455 [004254AD] 54                                           push    esp
000A5456 [004254AE] 8b ce                                        mov     ecx, esi
000A5458 [004254B0] b8 60 ce 45 00                               mov     eax, 45CE60h
000A545D [004254B5] ff d0                                        call    eax
000A545F [004254B7] 8d 44 24 08                                  lea     eax, [esp+8]
000A5463 [004254BB] 50                                           push    eax
000A5464 [004254BC] 8b cb                                        mov     ecx, ebx
000A5466 [004254BE] b8 40 a9 44 00                               mov     eax, 44A940h
000A546B [004254C3] ff d0                                        call    eax
000A546D [004254C5] 8b 4b 48                                     mov     ecx, [ebx+48h]
000A5470 [004254C8] b8 01 00 00 00                               mov     eax, 1
000A5475 [004254CD] 80 79 04 0a                                  cmp     byte ptr [ecx+4], 0Ah
000A5479 [004254D1] 7d 02                                        jge     short near ptr unk_4254D5 ; game-relative-target=0x000A547D
000A547B [004254D3] b0 03                                        mov     al, 3
000A547D [004254D5] 29 44 24 08                                  sub     [esp+8], eax
000A5481 [004254D9] 29 44 24 0c                                  sub     [esp+0Ch], eax
000A5485 [004254DD] 40                                           inc     eax
000A5486 [004254DE] 01 44 24 10                                  add     [esp+10h], eax
000A548A [004254E2] 01 44 24 14                                  add     [esp+14h], eax
000A548E [004254E6] 8d 44 24 08                                  lea     eax, [esp+8]
000A5492 [004254EA] 50                                           push    eax
000A5493 [004254EB] ff 15 6c f3 5f 00                            call    dword ptr ds:5FF36Ch
000A5499 [004254F1] 83 c4 10                                     add     esp, 10h
000A549C [004254F4] 5b                                           pop     ebx
000A549D [004254F5] 85 c0                                        test    eax, eax
000A549F [004254F7] b8 86 b8 4b 00                               mov     eax, 4BB886h
000A54A4 [004254FC] 74 02                                        jz      short near ptr unk_425500 ; game-relative-target=0x000A54A8
000A54A6 [004254FE] b0 dc                                        mov     al, 0DCh
000A54A8 [00425500] 50                                           push    eax
000A54A9 [00425501] c2 04 00                                     retn    4
