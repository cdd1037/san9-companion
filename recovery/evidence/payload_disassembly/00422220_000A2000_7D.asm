; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422220; baseline game VA=0x000A2000; size=125
; Relative branch annotations use the baseline game destination.
000A2000 [00422220] b8 00 1b 0a 00                               mov     eax, 0A1B00h
000A2005 [00422225] ff d0                                        call    eax
000A2007 [00422227] 85 c0                                        test    eax, eax
000A2009 [00422229] 74 6a                                        jz      short near ptr unk_422295 ; game-relative-target=0x000A2075
000A200B [0042222B] 83 7e 58 26                                  cmp     dword ptr [esi+58h], 26h ; '&'
000A200F [0042222F] 75 64                                        jnz     short near ptr unk_422295 ; game-relative-target=0x000A2075
000A2011 [00422231] 81 7e 30 00 0c 00 00                         cmp     dword ptr [esi+30h], 0C00h
000A2018 [00422238] 7e 5b                                        jle     short near ptr unk_422295 ; game-relative-target=0x000A2075
000A201A [0042223A] 83 be 80 00 00 00 00                         cmp     dword ptr [esi+80h], 0
000A2021 [00422241] 75 52                                        jnz     short near ptr unk_422295 ; game-relative-target=0x000A2075
000A2023 [00422243] 8b 46 54                                     mov     eax, [esi+54h]
000A2026 [00422246] 85 c0                                        test    eax, eax
000A2028 [00422248] 7e 4b                                        jle     short near ptr unk_422295 ; game-relative-target=0x000A2075
000A202A [0042224A] 50                                           push    eax
000A202B [0042224B] b8 e0 32 45 00                               mov     eax, 4532E0h
000A2030 [00422250] ff d0                                        call    eax
000A2032 [00422252] 5a                                           pop     edx
000A2033 [00422253] f6 40 20 01                                  test    byte ptr [eax+20h], 1
000A2037 [00422257] 74 09                                        jz      short near ptr unk_422262 ; game-relative-target=0x000A2042
000A2039 [00422259] 81 78 30 00 04 00 00                         cmp     dword ptr [eax+30h], 400h
000A2040 [00422260] 7e 33                                        jle     short near ptr unk_422295 ; game-relative-target=0x000A2075
000A2042 [00422262] 50                                           push    eax
000A2043 [00422263] 50                                           push    eax
000A2044 [00422264] 8b ce                                        mov     ecx, esi
000A2046 [00422266] b8 60 58 46 00                               mov     eax, 465860h
000A204B [0042226B] ff d0                                        call    eax
000A204D [0042226D] 85 c0                                        test    eax, eax
000A204F [0042226F] 58                                           pop     eax
000A2050 [00422270] 74 23                                        jz      short near ptr unk_422295 ; game-relative-target=0x000A2075
000A2052 [00422272] f6 40 20 01                                  test    byte ptr [eax+20h], 1
000A2056 [00422276] 75 06                                        jnz     short near ptr unk_42227E ; game-relative-target=0x000A205E
000A2058 [00422278] f6 46 21 10                                  test    byte ptr [esi+21h], 10h
000A205C [0042227C] 75 08                                        jnz     short near ptr unk_422286 ; game-relative-target=0x000A2066
000A205E [0042227E] 8b 46 50                                     mov     eax, [esi+50h]
000A2061 [00422281] 3b 46 54                                     cmp     eax, [esi+54h]
000A2064 [00422284] 75 0f                                        jnz     short near ptr unk_422295 ; game-relative-target=0x000A2075
000A2066 [00422286] 8b 54 24 04                                  mov     edx, [esp+4]
000A206A [0042228A] 8b 42 08                                     mov     eax, [edx+8]
000A206D [0042228D] 89 02                                        mov     [edx], eax
000A206F [0042228F] 8b 42 0c                                     mov     eax, [edx+0Ch]
000A2072 [00422292] 89 42 04                                     mov     [edx+4], eax
000A2075 [00422295] 8b ce                                        mov     ecx, esi
000A2077 [00422297] 68 00 ac 44 00                               push    44AC00h
000A207C [0042229C] c3                                           retn
