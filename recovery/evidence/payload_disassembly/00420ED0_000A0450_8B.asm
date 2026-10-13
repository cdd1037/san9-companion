; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420ED0; baseline game VA=0x000A0450; size=139
; Relative branch annotations use the baseline game destination.
000A0450 [00420ED0] 80 7e 06 05                                  cmp     byte ptr [esi+6], 5
000A0454 [00420ED4] 74 4d                                        jz      short near ptr unk_420F23 ; game-relative-target=0x000A04A3
000A0456 [00420ED6] 8b 4c 24 18                                  mov     ecx, [esp+18h]
000A045A [00420EDA] 8b 49 38                                     mov     ecx, [ecx+38h]
000A045D [00420EDD] 8d 49 78                                     lea     ecx, [ecx+78h]
000A0460 [00420EE0] 83 79 0c 01                                  cmp     dword ptr [ecx+0Ch], 1
000A0464 [00420EE4] 75 0f                                        jnz     short near ptr unk_420EF5 ; game-relative-target=0x000A0475
000A0466 [00420EE6] 8b 41 04                                     mov     eax, [ecx+4]
000A0469 [00420EE9] 3b 58 08                                     cmp     ebx, [eax+8]
000A046C [00420EEC] 75 07                                        jnz     short near ptr unk_420EF5 ; game-relative-target=0x000A0475
000A046E [00420EEE] bd 01 00 00 00                               mov     ebp, 1
000A0473 [00420EF3] eb 21                                        jmp     short near ptr unk_420F16 ; game-relative-target=0x000A0496
000A0475 [00420EF5] 81 fd 87 13 00 00                            cmp     ebp, 1387h
000A047B [00420EFB] 7d 19                                        jge     short near ptr unk_420F16 ; game-relative-target=0x000A0496
000A047D [00420EFD] 8b ce                                        mov     ecx, esi
000A047F [00420EFF] b8 00 3d 0a 00                               mov     eax, 0A3D00h
000A0484 [00420F04] ff d0                                        call    eax
000A0486 [00420F06] 3c 02                                        cmp     al, 2
000A0488 [00420F08] 7c 07                                        jl      short near ptr unk_420F11 ; game-relative-target=0x000A0491
000A048A [00420F0A] bd 87 13 00 00                               mov     ebp, 1387h
000A048F [00420F0F] eb 05                                        jmp     short near ptr unk_420F16 ; game-relative-target=0x000A0496
000A0491 [00420F11] 85 ed                                        test    ebp, ebp
000A0493 [00420F13] 75 01                                        jnz     short near ptr unk_420F16 ; game-relative-target=0x000A0496
000A0495 [00420F15] 45                                           inc     ebp
000A0496 [00420F16] 8b 86 88 00 00 00                            mov     eax, [esi+88h]
000A049C [00420F1C] 3b c5                                        cmp     eax, ebp
000A049E [00420F1E] 7d 02                                        jge     short near ptr unk_420F22 ; game-relative-target=0x000A04A2
000A04A0 [00420F20] 8b c5                                        mov     eax, ebp
000A04A2 [00420F22] c3                                           retn
000A04A3 [00420F23] 33 ed                                        xor     ebp, ebp
000A04A5 [00420F25] 8b ce                                        mov     ecx, esi
000A04A7 [00420F27] b8 90 19 0a 00                               mov     eax, 0A1990h
000A04AC [00420F2C] ff d0                                        call    eax
000A04AE [00420F2E] 8b be 88 00 00 00                            mov     edi, [esi+88h]
000A04B4 [00420F34] 03 c7                                        add     eax, edi
000A04B6 [00420F36] 2d 10 27 00 00                               sub     eax, 2710h
000A04BB [00420F3B] 50                                           push    eax
000A04BC [00420F3C] 4f                                           dec     edi
000A04BD [00420F3D] 8b 4c 24 1c                                  mov     ecx, [esp+1Ch]
000A04C1 [00420F41] 56                                           push    esi
000A04C2 [00420F42] 54                                           push    esp
000A04C3 [00420F43] b8 90 11 4a 00                               mov     eax, 4A1190h
000A04C8 [00420F48] ff d0                                        call    eax
000A04CA [00420F4A] 5a                                           pop     edx
000A04CB [00420F4B] 2b f8                                        sub     edi, eax
000A04CD [00420F4D] 58                                           pop     eax
000A04CE [00420F4E] 3b c7                                        cmp     eax, edi
000A04D0 [00420F50] 7e 02                                        jle     short near ptr unk_420F54 ; game-relative-target=0x000A04D4
000A04D2 [00420F52] 8b c7                                        mov     eax, edi
000A04D4 [00420F54] 85 c0                                        test    eax, eax
000A04D6 [00420F56] 7d 02                                        jge     short near ptr unk_420F5A ; game-relative-target=0x000A04DA
000A04D8 [00420F58] 33 c0                                        xor     eax, eax
000A04DA [00420F5A] c3                                           retn
