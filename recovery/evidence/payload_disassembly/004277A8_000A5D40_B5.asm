; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004277A8; baseline game VA=0x000A5D40; size=181
; Relative branch annotations use the baseline game destination.
000A5D40 [004277A8] 83 79 0c 01                                  cmp     dword ptr [ecx+0Ch], 1
000A5D44 [004277AC] 7f 03                                        jg      short near ptr unk_4277B1 ; game-relative-target=0x000A5D49
000A5D46 [004277AE] c2 04 00                                     retn    4
000A5D49 [004277B1] 56                                           push    esi
000A5D4A [004277B2] 57                                           push    edi
000A5D4B [004277B3] 55                                           push    ebp
000A5D4C [004277B4] 53                                           push    ebx
000A5D4D [004277B5] 8b f1                                        mov     esi, ecx
000A5D4F [004277B7] 8b 7c 24 14                                  mov     edi, [esp+14h]
000A5D53 [004277BB] 8b cf                                        mov     ecx, edi
000A5D55 [004277BD] 8b 01                                        mov     eax, [ecx]
000A5D57 [004277BF] ff 50 3c                                     call    dword ptr [eax+3Ch]
000A5D5A [004277C2] 85 c0                                        test    eax, eax
000A5D5C [004277C4] 74 09                                        jz      short near ptr unk_4277CF ; game-relative-target=0x000A5D67
000A5D5E [004277C6] 8b ce                                        mov     ecx, esi
000A5D60 [004277C8] b8 a0 3e 0a 00                               mov     eax, 0A3EA0h
000A5D65 [004277CD] ff d0                                        call    eax
000A5D67 [004277CF] 33 db                                        xor     ebx, ebx
000A5D69 [004277D1] 8b 6e 04                                     mov     ebp, [esi+4]
000A5D6C [004277D4] 8b 4d 08                                     mov     ecx, [ebp+8]
000A5D6F [004277D7] f6 41 21 10                                  test    byte ptr [ecx+21h], 10h
000A5D73 [004277DB] 75 10                                        jnz     short near ptr unk_4277ED ; game-relative-target=0x000A5D85
000A5D75 [004277DD] 57                                           push    edi
000A5D76 [004277DE] b8 70 88 46 00                               mov     eax, 468870h
000A5D7B [004277E3] ff d0                                        call    eax
000A5D7D [004277E5] 8b 4d 08                                     mov     ecx, [ebp+8]
000A5D80 [004277E8] 89 41 08                                     mov     [ecx+8], eax
000A5D83 [004277EB] 03 d8                                        add     ebx, eax
000A5D85 [004277ED] 8b 6d 00                                     mov     ebp, [ebp+0]
000A5D88 [004277F0] 85 ed                                        test    ebp, ebp
000A5D8A [004277F2] 75 e0                                        jnz     short near ptr unk_4277D4 ; game-relative-target=0x000A5D6C
000A5D8C [004277F4] 8b c3                                        mov     eax, ebx
000A5D8E [004277F6] 99                                           cdq
000A5D8F [004277F7] f7 76 0c                                     div     dword ptr [esi+0Ch]
000A5D92 [004277FA] 8b d8                                        mov     ebx, eax
000A5D94 [004277FC] 33 ff                                        xor     edi, edi
000A5D96 [004277FE] 8b 6e 04                                     mov     ebp, [esi+4]
000A5D99 [00427801] 8b 4d 08                                     mov     ecx, [ebp+8]
000A5D9C [00427804] f6 41 21 10                                  test    byte ptr [ecx+21h], 10h
000A5DA0 [00427808] 75 0d                                        jnz     short near ptr unk_427817 ; game-relative-target=0x000A5DAF
000A5DA2 [0042780A] 8b 41 08                                     mov     eax, [ecx+8]
000A5DA5 [0042780D] 2b c3                                        sub     eax, ebx
000A5DA7 [0042780F] 85 c0                                        test    eax, eax
000A5DA9 [00427811] 7d 02                                        jge     short near ptr unk_427815 ; game-relative-target=0x000A5DAD
000A5DAB [00427813] f7 d8                                        neg     eax
000A5DAD [00427815] 03 f8                                        add     edi, eax
000A5DAF [00427817] 8b 6d 00                                     mov     ebp, [ebp+0]
000A5DB2 [0042781A] 85 ed                                        test    ebp, ebp
000A5DB4 [0042781C] 75 e3                                        jnz     short near ptr unk_427801 ; game-relative-target=0x000A5D99
000A5DB6 [0042781E] 8b c7                                        mov     eax, edi
000A5DB8 [00427820] 99                                           cdq
000A5DB9 [00427821] f7 76 0c                                     div     dword ptr [esi+0Ch]
000A5DBC [00427824] 8b e8                                        mov     ebp, eax
000A5DBE [00427826] d1 ed                                        shr     ebp, 1
000A5DC0 [00427828] 03 dd                                        add     ebx, ebp
000A5DC2 [0042782A] 8b 6e 04                                     mov     ebp, [esi+4]
000A5DC5 [0042782D] 8b 4d 08                                     mov     ecx, [ebp+8]
000A5DC8 [00427830] f6 41 21 10                                  test    byte ptr [ecx+21h], 10h
000A5DCC [00427834] 75 19                                        jnz     short near ptr unk_42784F ; game-relative-target=0x000A5DE7
000A5DCE [00427836] 8b 41 08                                     mov     eax, [ecx+8]
000A5DD1 [00427839] 2b c3                                        sub     eax, ebx
000A5DD3 [0042783B] f7 d8                                        neg     eax
000A5DD5 [0042783D] 85 c0                                        test    eax, eax
000A5DD7 [0042783F] 7d 02                                        jge     short near ptr unk_427843 ; game-relative-target=0x000A5DDB
000A5DD9 [00427841] 33 c0                                        xor     eax, eax
000A5DDB [00427843] 83 f8 09                                     cmp     eax, 9
000A5DDE [00427846] 7e 04                                        jle     short near ptr unk_42784C ; game-relative-target=0x000A5DE4
000A5DE0 [00427848] 33 c0                                        xor     eax, eax
000A5DE2 [0042784A] b0 09                                        mov     al, 9
000A5DE4 [0042784C] 89 41 48                                     mov     [ecx+48h], eax
000A5DE7 [0042784F] 8b 6d 00                                     mov     ebp, [ebp+0]
000A5DEA [00427852] 85 ed                                        test    ebp, ebp
000A5DEC [00427854] 75 d7                                        jnz     short near ptr unk_42782D ; game-relative-target=0x000A5DC5
000A5DEE [00427856] 5b                                           pop     ebx
000A5DEF [00427857] 5d                                           pop     ebp
000A5DF0 [00427858] 5f                                           pop     edi
000A5DF1 [00427859] 5e                                           pop     esi
000A5DF2 [0042785A] c2 04 00                                     retn    4
