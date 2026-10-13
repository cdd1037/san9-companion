; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426220; baseline game VA=0x000A5B60; size=189
; Relative branch annotations use the baseline game destination.
000A5B60 [00426220] 80 61 21 ef                                  and     byte ptr [ecx+21h], 0EFh
000A5B64 [00426224] 33 c0                                        xor     eax, eax
000A5B66 [00426226] 89 41 7c                                     mov     [ecx+7Ch], eax
000A5B69 [00426229] b0 34                                        mov     al, 34h ; '4'
000A5B6B [0042622B] 89 41 58                                     mov     [ecx+58h], eax
000A5B6E [0042622E] 8b 41 74                                     mov     eax, [ecx+74h]
000A5B71 [00426231] f6 40 34 05                                  test    byte ptr [eax+34h], 5
000A5B75 [00426235] 75 16                                        jnz     short near ptr unk_42624D ; game-relative-target=0x000A5B8D
000A5B77 [00426237] 8b 41 6c                                     mov     eax, [ecx+6Ch]
000A5B7A [0042623A] 80 78 04 08                                  cmp     byte ptr [eax+4], 8
000A5B7E [0042623E] 7c 0d                                        jl      short near ptr unk_42624D ; game-relative-target=0x000A5B8D
000A5B80 [00426240] 80 78 04 0b                                  cmp     byte ptr [eax+4], 0Bh
000A5B84 [00426244] 7f 07                                        jg      short near ptr unk_42624D ; game-relative-target=0x000A5B8D
000A5B86 [00426246] c7 41 6c a0 0e 50 01                         mov     dword ptr [ecx+6Ch], 1500EA0h
000A5B8D [0042624D] 56                                           push    esi
000A5B8E [0042624E] 57                                           push    edi
000A5B8F [0042624F] 55                                           push    ebp
000A5B90 [00426250] 53                                           push    ebx
000A5B91 [00426251] 8b f1                                        mov     esi, ecx
000A5B93 [00426253] 8b 7e 78                                     mov     edi, [esi+78h]
000A5B96 [00426256] 83 ec 20                                     sub     esp, 20h ; ' '
000A5B99 [00426259] 8b cc                                        mov     ecx, esp
000A5B9B [0042625B] b8 70 c9 46 00                               mov     eax, 46C970h
000A5BA0 [00426260] ff d0                                        call    eax
000A5BA2 [00426262] 6a 00                                        push    0
000A5BA4 [00426264] 6a 00                                        push    0
000A5BA6 [00426266] 50                                           push    eax
000A5BA7 [00426267] 8b 4e 74                                     mov     ecx, [esi+74h]
000A5BAA [0042626A] b8 50 e2 43 00                               mov     eax, 43E250h
000A5BAF [0042626F] ff d0                                        call    eax
000A5BB1 [00426271] 48                                           dec     eax
000A5BB2 [00426272] 7e 4f                                        jle     short near ptr unk_4262C3 ; game-relative-target=0x000A5C03
000A5BB4 [00426274] 8b 5c 24 04                                  mov     ebx, [esp+4]
000A5BB8 [00426278] 8b 4b 08                                     mov     ecx, [ebx+8]
000A5BBB [0042627B] 57                                           push    edi
000A5BBC [0042627C] b8 80 ee 45 00                               mov     eax, 45EE80h
000A5BC1 [00426281] ff d0                                        call    eax
000A5BC3 [00426283] 8b 1b                                        mov     ebx, [ebx]
000A5BC5 [00426285] 85 db                                        test    ebx, ebx
000A5BC7 [00426287] 75 ef                                        jnz     short near ptr unk_426278 ; game-relative-target=0x000A5BB8
000A5BC9 [00426289] 8b cc                                        mov     ecx, esp
000A5BCB [0042628B] 6a 01                                        push    1
000A5BCD [0042628D] 68 60 e9 46 00                               push    46E960h
000A5BD2 [00426292] b8 10 f6 46 00                               mov     eax, 46F610h
000A5BD7 [00426297] ff d0                                        call    eax
000A5BD9 [00426299] 8b 5c 24 04                                  mov     ebx, [esp+4]
000A5BDD [0042629D] 8b 6b 08                                     mov     ebp, [ebx+8]
000A5BE0 [004262A0] 8b cd                                        mov     ecx, ebp
000A5BE2 [004262A2] b8 c0 61 43 00                               mov     eax, 4361C0h
000A5BE7 [004262A7] ff d0                                        call    eax
000A5BE9 [004262A9] 8b f8                                        mov     edi, eax
000A5BEB [004262AB] 55                                           push    ebp
000A5BEC [004262AC] b8 50 25 0a 00                               mov     eax, 0A2550h
000A5BF1 [004262B1] ff d0                                        call    eax
000A5BF3 [004262B3] 03 46 30                                     add     eax, [esi+30h]
000A5BF6 [004262B6] 03 46 34                                     add     eax, [esi+34h]
000A5BF9 [004262B9] 3b c7                                        cmp     eax, edi
000A5BFB [004262BB] 7c 09                                        jl      short near ptr unk_4262C6 ; game-relative-target=0x000A5C06
000A5BFD [004262BD] 8b 1b                                        mov     ebx, [ebx]
000A5BFF [004262BF] 85 db                                        test    ebx, ebx
000A5C01 [004262C1] 75 da                                        jnz     short near ptr unk_42629D ; game-relative-target=0x000A5BDD
000A5C03 [004262C3] 8b 6e 64                                     mov     ebp, [esi+64h]
000A5C06 [004262C6] 8b 45 04                                     mov     eax, [ebp+4]
000A5C09 [004262C9] 89 46 50                                     mov     [esi+50h], eax
000A5C0C [004262CC] 8b cc                                        mov     ecx, esp
000A5C0E [004262CE] b8 90 c9 46 00                               mov     eax, 46C990h
000A5C13 [004262D3] ff d0                                        call    eax
000A5C15 [004262D5] 83 c4 20                                     add     esp, 20h ; ' '
000A5C18 [004262D8] 5b                                           pop     ebx
000A5C19 [004262D9] 5d                                           pop     ebp
000A5C1A [004262DA] 5f                                           pop     edi
000A5C1B [004262DB] 5e                                           pop     esi
000A5C1C [004262DC] c3                                           retn
