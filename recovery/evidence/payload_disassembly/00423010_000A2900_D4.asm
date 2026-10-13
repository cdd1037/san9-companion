; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423010; baseline game VA=0x000A2900; size=212
; Relative branch annotations use the baseline game destination.
000A2900 [00423010] 56                                           push    esi
000A2901 [00423011] b8 60 eb 46 00                               mov     eax, 46EB60h
000A2906 [00423016] ff d0                                        call    eax
000A2908 [00423018] 85 c0                                        test    eax, eax
000A290A [0042301A] 74 03                                        jz      short near ptr unk_42301F ; game-relative-target=0x000A290F
000A290C [0042301C] c2 04 00                                     retn    4
000A290F [0042301F] 8b 4c 24 24                                  mov     ecx, [esp+24h]
000A2913 [00423023] f6 41 34 04                                  test    byte ptr [ecx+34h], 4
000A2917 [00423027] 75 f3                                        jnz     short near ptr unk_42301C ; game-relative-target=0x000A290C
000A2919 [00423029] 8b ce                                        mov     ecx, esi
000A291B [0042302B] b8 d0 53 43 00                               mov     eax, 4353D0h
000A2920 [00423030] ff d0                                        call    eax
000A2922 [00423032] ba 10 27 00 00                               mov     edx, 2710h
000A2927 [00423037] 3c 02                                        cmp     al, 2
000A2929 [00423039] 7f 06                                        jg      short near ptr unk_423041 ; game-relative-target=0x000A2931
000A292B [0042303B] 3c 01                                        cmp     al, 1
000A292D [0042303D] 74 02                                        jz      short near ptr unk_423041 ; game-relative-target=0x000A2931
000A292F [0042303F] d1 e2                                        shl     edx, 1
000A2931 [00423041] b0 01                                        mov     al, 1
000A2933 [00423043] 39 96 88 00 00 00                            cmp     [esi+88h], edx
000A2939 [00423049] 7c d1                                        jl      short near ptr unk_42301C ; game-relative-target=0x000A290C
000A293B [0042304B] 8b 94 24 5c 01 00 00                         mov     edx, [esp+15Ch]
000A2942 [00423052] 8b ce                                        mov     ecx, esi
000A2944 [00423054] b8 90 29 0a 00                               mov     eax, 0A2990h
000A2949 [00423059] ff d0                                        call    eax
000A294B [0042305B] c2 04 00                                     retn    4
000A294E [0042305E] 00    db 0x00
000A294F [0042305F] 00 6a ff                                     add     [edx-1], ch
000A2952 [00423062] 68 10 45 5e 00                               push    5E4510h
000A2957 [00423067] 64 a1 00 00 00 00                            mov     eax, large fs:0
000A295D [0042306D] 50                                           push    eax
000A295E [0042306E] 64 89 25 00 00 00 00                         mov     large fs:0, esp
000A2965 [00423075] 83 ec 64                                     sub     esp, 64h ; 'd'
000A2968 [00423078] 56                                           push    esi
000A2969 [00423079] 8b 4c 24 7c                                  mov     ecx, [esp+7Ch]
000A296D [0042307D] 8b 01                                        mov     eax, [ecx]
000A296F [0042307F] ff 90 b8 00 00 00                            call    dword ptr [eax+0B8h]
000A2975 [00423085] 8b f0                                        mov     esi, eax
000A2977 [00423087] 57                                           push    edi
000A2978 [00423088] 8b 4c 24 7c                                  mov     ecx, [esp+7Ch]
000A297C [0042308C] 8b 01                                        mov     eax, [ecx]
000A297E [0042308E] ff 90 b8 00 00 00                            call    dword ptr [eax+0B8h]
000A2984 [00423094] 68 c2 a5 44 00                               push    44A5C2h
000A2989 [00423099] c3                                           retn
000A298A [0042309A] 00    db 0x00
000A298B [0042309B] 00    db 0x00
000A298C [0042309C] 00    db 0x00
000A298D [0042309D] 00    db 0x00
000A298E [0042309E] 00    db 0x00
000A298F [0042309F] 00 57 56                                     add     [edi+56h], dl
000A2992 [004230A2] 53                                           push    ebx
000A2993 [004230A3] 55                                           push    ebp
000A2994 [004230A4] 33 db                                        xor     ebx, ebx
000A2996 [004230A6] 8b 7a 44                                     mov     edi, [edx+44h]
000A2999 [004230A9] 8b 71 44                                     mov     esi, [ecx+44h]
000A299C [004230AC] 6a 0c                                        push    0Ch
000A299E [004230AE] 6a 0b                                        push    0Bh
000A29A0 [004230B0] 52                                           push    edx
000A29A1 [004230B1] 51                                           push    ecx
000A29A2 [004230B2] e8 a9 ff ff ff                               call    near ptr unk_423060 ; game-relative-target=0x000A2950
000A29A7 [004230B7] 83 c4 10                                     add     esp, 10h
000A29AA [004230BA] 8b e8                                        mov     ebp, eax
000A29AC [004230BC] 3b f7                                        cmp     esi, edi
000A29AE [004230BE] 74 1b                                        jz      short near ptr unk_4230DB ; game-relative-target=0x000A29CB
000A29B0 [004230C0] 83 f8 32                                     cmp     eax, 32h ; '2'
000A29B3 [004230C3] 7e 16                                        jle     short near ptr unk_4230DB ; game-relative-target=0x000A29CB
000A29B5 [004230C5] 6a 0c                                        push    0Ch
000A29B7 [004230C7] 6a 0b                                        push    0Bh
000A29B9 [004230C9] 57                                           push    edi
000A29BA [004230CA] 56                                           push    esi
000A29BB [004230CB] e8 90 ff ff ff                               call    near ptr unk_423060 ; game-relative-target=0x000A2950
000A29C0 [004230D0] 83 c4 10                                     add     esp, 10h
000A29C3 [004230D3] 8d 48 0a                                     lea     ecx, [eax+0Ah]
000A29C6 [004230D6] 3b e9                                        cmp     ebp, ecx
000A29C8 [004230D8] 0f 9f c3                                     setnle  bl
000A29CB [004230DB] 8b c3                                        mov     eax, ebx
000A29CD [004230DD] 8b d5                                        mov     edx, ebp
000A29CF [004230DF] 5d                                           pop     ebp
000A29D0 [004230E0] 5b                                           pop     ebx
000A29D1 [004230E1] 5e                                           pop     esi
000A29D2 [004230E2] 5f                                           pop     edi
000A29D3 [004230E3] c3                                           retn
