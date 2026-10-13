; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426540; baseline game VA=0x000AA500; size=256
; Relative branch annotations use the baseline game destination.
000AA500 [00426540] c6 05 cb f4 43 00 01                         mov     byte ptr ds:43F4CBh, 1
000AA507 [00426547] b8 10 4b 45 00                               mov     eax, 454B10h
000AA50C [0042654C] ff d0                                        call    eax
000AA50E [0042654E] 3d 68 01 00 00                               cmp     eax, 168h
000AA513 [00426553] 7c 41                                        jl      short near ptr unk_426596 ; game-relative-target=0x000AA556
000AA515 [00426555] b8 90 4b 45 00                               mov     eax, 454B90h
000AA51A [0042655A] ff d0                                        call    eax
000AA51C [0042655C] 3d 68 01 00 00                               cmp     eax, 168h
000AA521 [00426561] 74 07                                        jz      short near ptr unk_42656A ; game-relative-target=0x000AA52A
000AA523 [00426563] 3d b4 00 00 00                               cmp     eax, 0B4h
000AA528 [00426568] 75 2c                                        jnz     short near ptr unk_426596 ; game-relative-target=0x000AA556
000AA52A [0042656A] 8b 56 38                                     mov     edx, [esi+38h]
000AA52D [0042656D] 8b 8a b8 00 00 00                            mov     ecx, [edx+0B8h]
000AA533 [00426573] b8 70 f3 43 00                               mov     eax, 43F370h
000AA538 [00426578] ff d0                                        call    eax
000AA53A [0042657A] 83 f8 02                                     cmp     eax, 2
000AA53D [0042657D] 7c 17                                        jl      short near ptr unk_426596 ; game-relative-target=0x000AA556
000AA53F [0042657F] 8b 56 38                                     mov     edx, [esi+38h]
000AA542 [00426582] 3b 92 b8 00 00 00                            cmp     edx, [edx+0B8h]
000AA548 [00426588] 74 05                                        jz      short near ptr unk_42658F ; game-relative-target=0x000AA54F
000AA54A [0042658A] 33 c0                                        xor     eax, eax
000AA54C [0042658C] c2 08 00                                     retn    8
000AA54F [0042658F] c6 05 cb f4 43 00 00                         mov     byte ptr ds:43F4CBh, 0
000AA556 [00426596] 8d 4e 08                                     lea     ecx, [esi+8]
000AA559 [00426599] b8 40 db 4b 00                               mov     eax, 4BDB40h
000AA55E [0042659E] ff d0                                        call    eax
000AA560 [004265A0] 8b ce                                        mov     ecx, esi
000AA562 [004265A2] 68 90 9c 4a 00                               push    4A9C90h
000AA567 [004265A7] c3                                           retn
000AA568 [004265A8] 56                                           push    esi
000AA569 [004265A9] 57                                           push    edi
000AA56A [004265AA] 8b 7c 24 0c                                  mov     edi, [esp+0Ch]
000AA56E [004265AE] 8d 47 f8                                     lea     eax, [edi-8]
000AA571 [004265B1] ba 30 0f 46 00                               mov     edx, 460F30h
000AA576 [004265B6] ff d2                                        call    edx
000AA578 [004265B8] 85 c0                                        test    eax, eax
000AA57A [004265BA] 74 2d                                        jz      short near ptr unk_4265E9 ; game-relative-target=0x000AA5A9
000AA57C [004265BC] 8b f0                                        mov     esi, eax
000AA57E [004265BE] 8b c8                                        mov     ecx, eax
000AA580 [004265C0] b8 f0 be 44 00                               mov     eax, 44BEF0h
000AA585 [004265C5] ff d0                                        call    eax
000AA587 [004265C7] 85 c0                                        test    eax, eax
000AA589 [004265C9] 74 1e                                        jz      short near ptr unk_4265E9 ; game-relative-target=0x000AA5A9
000AA58B [004265CB] 0f b6 05 cb f4 43 00                         movzx   eax, byte ptr ds:43F4CBh
000AA592 [004265D2] f7 d8                                        neg     eax
000AA594 [004265D4] 1b c0                                        sbb     eax, eax
000AA596 [004265D6] 83 e0 04                                     and     eax, 4
000AA599 [004265D9] 8b ce                                        mov     ecx, esi
000AA59B [004265DB] 8b 16                                        mov     edx, [esi]
000AA59D [004265DD] ff 54 10 30                                  call    dword ptr [eax+edx+30h]
000AA5A1 [004265E1] 2b 47 0c                                     sub     eax, [edi+0Ch]
000AA5A4 [004265E4] f7 d8                                        neg     eax
000AA5A6 [004265E6] 1b c0                                        sbb     eax, eax
000AA5A8 [004265E8] 40                                           inc     eax
000AA5A9 [004265E9] 5f                                           pop     edi
000AA5AA [004265EA] 5e                                           pop     esi
000AA5AB [004265EB] c3                                           retn
000AA5AC [004265EC] 00    db 0x00
000AA5AD [004265ED] 00    db 0x00
000AA5AE [004265EE] 00    db 0x00
000AA5AF [004265EF] 00 5a 80                                     add     [edx-80h], bl
000AA5B2 [004265F2] 3d cb f4 43 00                               cmp     eax, 43F4CBh
000AA5B7 [004265F7] 00 74 07 68                                  add     [edi+eax+68h], dh
000AA5BB [004265FB] 40                                           inc     eax
000AA5BC [004265FC] cd 46                                        int     46h ; 'F'
000AA5BE [004265FE] 00 ff                                        add     bh, bh
000AA5C0 [00426600] e2 68                                        loop    near ptr unk_42666A ; game-relative-target=0x000AA62A
000AA5C2 [00426602] 80 cc 46                                     or      ah, 46h ; 'F'
000AA5C5 [00426605] 00 ff                                        add     bh, bh
000AA5C7 [00426607] e2 80                                        loop    near ptr unk_426589 ; game-relative-target=0x000AA549
000AA5C9 [00426609] 3d cb f4 43 00                               cmp     eax, 43F4CBh
000AA5CE [0042660E] 00 74 06 68                                  add     [esi+eax+68h], dh
000AA5D2 [00426612] 80 f0 43                                     xor     al, 43h ; 'C'
000AA5D5 [00426615] 00 c3                                        add     bl, al
000AA5D7 [00426617] b8 20 0f 44 00                               mov     eax, 440F20h
000AA5DC [0042661C] ff d0                                        call    eax
000AA5DE [0042661E] 8b d8                                        mov     ebx, eax
000AA5E0 [00426620] d1 eb                                        shr     ebx, 1
000AA5E2 [00426622] 8b ce                                        mov     ecx, esi
000AA5E4 [00426624] b8 30 f2 43 00                               mov     eax, 43F230h
000AA5E9 [00426629] ff d0                                        call    eax
000AA5EB [0042662B] 03 d8                                        add     ebx, eax
000AA5ED [0042662D] 8b ce                                        mov     ecx, esi
000AA5EF [0042662F] b8 d0 f0 43 00                               mov     eax, 43F0D0h
000AA5F4 [00426634] ff d0                                        call    eax
000AA5F6 [00426636] 03 d8                                        add     ebx, eax
000AA5F8 [00426638] 68 2f 9b 4a 00                               push    4A9B2Fh
000AA5FD [0042663D] c2 04 00                                     retn    4
