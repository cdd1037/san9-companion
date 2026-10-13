; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426FE8; baseline game VA=0x000A6D00; size=184
; Relative branch annotations use the baseline game destination.
000A6D00 [00426FE8] 8b f9                                        mov     edi, ecx
000A6D02 [00426FEA] b8 d0 64 0a 00                               mov     eax, 0A64D0h
000A6D07 [00426FEF] ff d0                                        call    eax
000A6D09 [00426FF1] 85 c0                                        test    eax, eax
000A6D0B [00426FF3] 75 07                                        jnz     short near ptr unk_426FFC ; game-relative-target=0x000A6D14
000A6D0D [00426FF5] 8b 56 50                                     mov     edx, [esi+50h]
000A6D10 [00426FF8] 8b 4e 54                                     mov     ecx, [esi+54h]
000A6D13 [00426FFB] c3                                           retn
000A6D14 [00426FFC] 53                                           push    ebx
000A6D15 [00426FFD] 8b 88 bc 00 00 00                            mov     ecx, [eax+0BCh]
000A6D1B [00427003] 8d 59 10                                     lea     ebx, [ecx+10h]
000A6D1E [00427006] 8d 46 58                                     lea     eax, [esi+58h]
000A6D21 [00427009] 50                                           push    eax
000A6D22 [0042700A] 8b cb                                        mov     ecx, ebx
000A6D24 [0042700C] b8 20 63 0a 00                               mov     eax, 0A6320h
000A6D29 [00427011] ff d0                                        call    eax
000A6D2B [00427013] 85 c0                                        test    eax, eax
000A6D2D [00427015] 75 03                                        jnz     short near ptr unk_42701A ; game-relative-target=0x000A6D32
000A6D2F [00427017] 5b                                           pop     ebx
000A6D30 [00427018] eb db                                        jmp     short near ptr unk_426FF5 ; game-relative-target=0x000A6D0D
000A6D32 [0042701A] c6 46 54 00                                  mov     byte ptr [esi+54h], 0
000A6D36 [0042701E] b8 80 72 0a 00                               mov     eax, 0A7280h
000A6D3B [00427023] ff d0                                        call    eax
000A6D3D [00427025] 85 c0                                        test    eax, eax
000A6D3F [00427027] 75 3c                                        jnz     short near ptr unk_427065 ; game-relative-target=0x000A6D7D
000A6D41 [00427029] 33 c0                                        xor     eax, eax
000A6D43 [0042702B] 89 46 0c                                     mov     [esi+0Ch], eax
000A6D46 [0042702E] 89 46 74                                     mov     [esi+74h], eax
000A6D49 [00427031] 66 8b 46 16                                  mov     ax, [esi+16h]
000A6D4D [00427035] 66 89 46 14                                  mov     [esi+14h], ax
000A6D51 [00427039] 80 4e 34 88                                  or      byte ptr [esi+34h], 88h
000A6D55 [0042703D] 80 66 34 ff                                  and     byte ptr [esi+34h], 0FFh
000A6D59 [00427041] c6 46 50 01                                  mov     byte ptr [esi+50h], 1
000A6D5D [00427045] f6 47 20 08                                  test    byte ptr [edi+20h], 8
000A6D61 [00427049] 75 18                                        jnz     short near ptr unk_427063 ; game-relative-target=0x000A6D7B
000A6D63 [0042704B] 80 77 20 08                                  xor     byte ptr [edi+20h], 8
000A6D67 [0042704F] 8b 0d 41 f4 43 00                            mov     ecx, ds:43F441h
000A6D6D [00427055] 85 c9                                        test    ecx, ecx
000A6D6F [00427057] 7c 0a                                        jl      short near ptr unk_427063 ; game-relative-target=0x000A6D7B
000A6D71 [00427059] 6a 01                                        push    1
000A6D73 [0042705B] 57                                           push    edi
000A6D74 [0042705C] b8 a0 2c 53 00                               mov     eax, 532CA0h
000A6D79 [00427061] ff d0                                        call    eax
000A6D7B [00427063] eb b2                                        jmp     short near ptr unk_427017 ; game-relative-target=0x000A6D2F
000A6D7D [00427065] 8b 16                                        mov     edx, [esi]
000A6D7F [00427067] 42                                           inc     edx
000A6D80 [00427068] f7 ea                                        imul    edx
000A6D82 [0042706A] 0f b6 15 14 ff 43 00                         movzx   edx, byte ptr ds:43FF14h
000A6D89 [00427071] 42                                           inc     edx
000A6D8A [00427072] f7 ea                                        imul    edx
000A6D8C [00427074] 8b d8                                        mov     ebx, eax
000A6D8E [00427076] 0f b6 0d 8a f8 43 00                         movzx   ecx, byte ptr ds:43F88Ah
000A6D95 [0042707D] 41                                           inc     ecx
000A6D96 [0042707E] 99                                           cdq
000A6D97 [0042707F] f7 f9                                        idiv    ecx
000A6D99 [00427081] 8b c2                                        mov     eax, edx
000A6D9B [00427083] f7 6e 0c                                     imul    dword ptr [esi+0Ch]
000A6D9E [00427086] 99                                           cdq
000A6D9F [00427087] b9 64 00 00 00                               mov     ecx, 64h ; 'd'
000A6DA4 [0042708C] f7 f9                                        idiv    ecx
000A6DA6 [0042708E] f6 c3 01                                     test    bl, 1
000A6DA9 [00427091] 74 02                                        jz      short near ptr unk_427095 ; game-relative-target=0x000A6DAD
000A6DAB [00427093] f7 d8                                        neg     eax
000A6DAD [00427095] 01 46 0c                                     add     [esi+0Ch], eax
000A6DB0 [00427098] f6 47 20 08                                  test    byte ptr [edi+20h], 8
000A6DB4 [0042709C] 75 ad                                        jnz     short near ptr unk_42704B ; game-relative-target=0x000A6D63
000A6DB6 [0042709E] eb c3                                        jmp     short near ptr unk_427063 ; game-relative-target=0x000A6D7B
