; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421914; baseline game VA=0x000A1500; size=318
; Relative branch annotations use the baseline game destination.
000A1500 [00421914] b8 f0 0d 47 00                               mov     eax, 470DF0h
000A1505 [00421919] ff d0                                        call    eax
000A1507 [0042191B] 8b 4f 38                                     mov     ecx, [edi+38h]
000A150A [0042191E] 8b 89 b8 00 00 00                            mov     ecx, [ecx+0B8h]
000A1510 [00421924] 8b 41 70                                     mov     eax, [ecx+70h]
000A1513 [00421927] a3 f3 fa 43 00                               mov     ds:43FAF3h, eax
000A1518 [0042192C] 8a 43 04                                     mov     al, [ebx+4]
000A151B [0042192F] 3c 01                                        cmp     al, 1
000A151D [00421931] 7f 10                                        jg      short near ptr unk_421943 ; game-relative-target=0x000A152F
000A151F [00421933] 6a 01                                        push    1
000A1521 [00421935] 6a 01                                        push    1
000A1523 [00421937] 8d 4e 2c                                     lea     ecx, [esi+2Ch]
000A1526 [0042193A] b8 00 30 0a 00                               mov     eax, 0A3000h
000A152B [0042193F] ff d0                                        call    eax
000A152D [00421941] eb 62                                        jmp     short near ptr unk_4219A5 ; game-relative-target=0x000A1591
000A152F [00421943] 3c 03                                        cmp     al, 3
000A1531 [00421945] 7f 5e                                        jg      short near ptr unk_4219A5 ; game-relative-target=0x000A1591
000A1533 [00421947] 6a 01                                        push    1
000A1535 [00421949] 6a 00                                        push    0
000A1537 [0042194B] 8d 4e 2c                                     lea     ecx, [esi+2Ch]
000A153A [0042194E] b8 00 30 0a 00                               mov     eax, 0A3000h
000A153F [00421953] ff d0                                        call    eax
000A1541 [00421955] 85 c0                                        test    eax, eax
000A1543 [00421957] 7f 4c                                        jg      short near ptr unk_4219A5 ; game-relative-target=0x000A1591
000A1545 [00421959] 6a 00                                        push    0
000A1547 [0042195B] 8d 4e 2c                                     lea     ecx, [esi+2Ch]
000A154A [0042195E] b8 60 bb 48 00                               mov     eax, 48BB60h
000A154F [00421963] ff d0                                        call    eax
000A1551 [00421965] 85 c0                                        test    eax, eax
000A1553 [00421967] 7e 3c                                        jle     short near ptr unk_4219A5 ; game-relative-target=0x000A1591
000A1555 [00421969] 50                                           push    eax
000A1556 [0042196A] 6a 01                                        push    1
000A1558 [0042196C] 8d 4e 2c                                     lea     ecx, [esi+2Ch]
000A155B [0042196F] b8 60 bb 48 00                               mov     eax, 48BB60h
000A1560 [00421974] ff d0                                        call    eax
000A1562 [00421976] 59                                           pop     ecx
000A1563 [00421977] 3b c1                                        cmp     eax, ecx
000A1565 [00421979] 7f 2a                                        jg      short near ptr unk_4219A5 ; game-relative-target=0x000A1591
000A1567 [0042197B] 6a 01                                        push    1
000A1569 [0042197D] 6a 01                                        push    1
000A156B [0042197F] 8d 4e 2c                                     lea     ecx, [esi+2Ch]
000A156E [00421982] b8 00 30 0a 00                               mov     eax, 0A3000h
000A1573 [00421987] ff d0                                        call    eax
000A1575 [00421989] 85 c0                                        test    eax, eax
000A1577 [0042198B] 7e 18                                        jle     short near ptr unk_4219A5 ; game-relative-target=0x000A1591
000A1579 [0042198D] 33 c0                                        xor     eax, eax
000A157B [0042198F] f6 45 04 01                                  test    byte ptr [ebp+4], 1
000A157F [00421993] 74 02                                        jz      short near ptr unk_421997 ; game-relative-target=0x000A1583
000A1581 [00421995] b0 01                                        mov     al, 1
000A1583 [00421997] 50                                           push    eax
000A1584 [00421998] b8 90 38 45 00                               mov     eax, 453890h
000A1589 [0042199D] ff d0                                        call    eax
000A158B [0042199F] 59                                           pop     ecx
000A158C [004219A0] 89 46 30                                     mov     [esi+30h], eax
000A158F [004219A3] 8b d8                                        mov     ebx, eax
000A1591 [004219A5] 8a 45 58                                     mov     al, [ebp+58h]
000A1594 [004219A8] 3c 28                                        cmp     al, 28h ; '('
000A1596 [004219AA] 7c 0a                                        jl      short near ptr unk_4219B6 ; game-relative-target=0x000A15A2
000A1598 [004219AC] 3c 32                                        cmp     al, 32h ; '2'
000A159A [004219AE] 7f 06                                        jg      short near ptr unk_4219B6 ; game-relative-target=0x000A15A2
000A159C [004219B0] f6 45 22 08                                  test    byte ptr [ebp+22h], 8
000A15A0 [004219B4] 74 01                                        jz      short near ptr unk_4219B7 ; game-relative-target=0x000A15A3
000A15A2 [004219B6] c3                                           retn
000A15A3 [004219B7] 83 ec 60                                     sub     esp, 60h ; '`'
000A15A6 [004219BA] 8b cc                                        mov     ecx, esp
000A15A8 [004219BC] b8 b0 34 47 00                               mov     eax, 4734B0h
000A15AD [004219C1] ff d0                                        call    eax
000A15AF [004219C3] 8b cd                                        mov     ecx, ebp
000A15B1 [004219C5] b8 40 1f 46 00                               mov     eax, 461F40h
000A15B6 [004219CA] ff d0                                        call    eax
000A15B8 [004219CC] 89 86 a4 00 00 00                            mov     [esi+0A4h], eax
000A15BE [004219D2] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A15C2 [004219D6] 50                                           push    eax
000A15C3 [004219D7] 8b 97 c0 08 00 00                            mov     edx, [edi+8C0h]
000A15C9 [004219DD] ff b2 d0 00 00 00                            push    dword ptr [edx+0D0h]
000A15CF [004219E3] b8 70 a3 47 00                               mov     eax, 47A370h
000A15D4 [004219E8] ff d0                                        call    eax
000A15D6 [004219EA] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A15DA [004219EE] 54                                           push    esp
000A15DB [004219EF] b8 90 82 47 00                               mov     eax, 478290h
000A15E0 [004219F4] ff d0                                        call    eax
000A15E2 [004219F6] 8b cc                                        mov     ecx, esp
000A15E4 [004219F8] b8 10 82 51 00                               mov     eax, 518210h
000A15E9 [004219FD] ff d0                                        call    eax
000A15EB [004219FF] 8b cc                                        mov     ecx, esp
000A15ED [00421A01] b8 80 7b 43 00                               mov     eax, 437B80h
000A15F2 [00421A06] ff d0                                        call    eax
000A15F4 [00421A08] 8b cc                                        mov     ecx, esp
000A15F6 [00421A0A] 8b 46 34                                     mov     eax, [esi+34h]
000A15F9 [00421A0D] ff 70 5c                                     push    dword ptr [eax+5Ch]
000A15FC [00421A10] ff 73 5c                                     push    dword ptr [ebx+5Ch]
000A15FF [00421A13] 51                                           push    ecx
000A1600 [00421A14] b8 c0 a4 44 00                               mov     eax, 44A4C0h
000A1605 [00421A19] ff d0                                        call    eax
000A1607 [00421A1B] 83 c4 0c                                     add     esp, 0Ch
000A160A [00421A1E] 50                                           push    eax
000A160B [00421A1F] 8b cf                                        mov     ecx, edi
000A160D [00421A21] 55                                           push    ebp
000A160E [00421A22] 54                                           push    esp
000A160F [00421A23] b8 d0 16 4a 00                               mov     eax, 4A16D0h
000A1614 [00421A28] ff d0                                        call    eax
000A1616 [00421A2A] 5a                                           pop     edx
000A1617 [00421A2B] 5a                                           pop     edx
000A1618 [00421A2C] 2b c2                                        sub     eax, edx
000A161A [00421A2E] 85 c0                                        test    eax, eax
000A161C [00421A30] 7d 02                                        jge     short near ptr unk_421A34 ; game-relative-target=0x000A1620
000A161E [00421A32] 33 c0                                        xor     eax, eax
000A1620 [00421A34] 89 86 a0 00 00 00                            mov     [esi+0A0h], eax
000A1626 [00421A3A] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A162A [00421A3E] b8 10 9f 47 00                               mov     eax, 479F10h
000A162F [00421A43] ff d0                                        call    eax
000A1631 [00421A45] 8b cc                                        mov     ecx, esp
000A1633 [00421A47] b8 e0 80 51 00                               mov     eax, 5180E0h
000A1638 [00421A4C] ff d0                                        call    eax
000A163A [00421A4E] 83 c4 60                                     add     esp, 60h ; '`'
000A163D [00421A51] c3                                           retn
