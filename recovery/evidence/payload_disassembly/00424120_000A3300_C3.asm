; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424120; baseline game VA=0x000A3300; size=195
; Relative branch annotations use the baseline game destination.
000A3300 [00424120] f6 46 3d 80                                  test    byte ptr [esi+3Dh], 80h
000A3304 [00424124] 74 03                                        jz      short near ptr unk_424129 ; game-relative-target=0x000A3309
000A3306 [00424126] 33 c0                                        xor     eax, eax
000A3308 [00424128] c3                                           retn
000A3309 [00424129] 8b 4c 24 0c                                  mov     ecx, [esp+0Ch]
000A330D [0042412D] 8b 49 78                                     mov     ecx, [ecx+78h]
000A3310 [00424130] b8 40 cc 45 00                               mov     eax, 45CC40h
000A3315 [00424135] ff d0                                        call    eax
000A3317 [00424137] 85 c0                                        test    eax, eax
000A3319 [00424139] 74 01                                        jz      short near ptr unk_42413C ; game-relative-target=0x000A331C
000A331B [0042413B] c3                                           retn
000A331C [0042413C] 8b 4c 24 0c                                  mov     ecx, [esp+0Ch]
000A3320 [00424140] 8b 41 74                                     mov     eax, [ecx+74h]
000A3323 [00424143] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A3327 [00424147] 74 01                                        jz      short near ptr unk_42414A ; game-relative-target=0x000A332A
000A3329 [00424149] c3                                           retn
000A332A [0042414A] 8b 51 6c                                     mov     edx, [ecx+6Ch]
000A332D [0042414D] 8b 42 04                                     mov     eax, [edx+4]
000A3330 [00424150] 3c 0e                                        cmp     al, 0Eh
000A3332 [00424152] 74 05                                        jz      short near ptr unk_424159 ; game-relative-target=0x000A3339
000A3334 [00424154] 3c 06                                        cmp     al, 6
000A3336 [00424156] 74 01                                        jz      short near ptr unk_424159 ; game-relative-target=0x000A3339
000A3338 [00424158] c3                                           retn
000A3339 [00424159] 8b 41 50                                     mov     eax, [ecx+50h]
000A333C [0042415C] 3b 46 04                                     cmp     eax, [esi+4]
000A333F [0042415F] 75 01                                        jnz     short near ptr unk_424162 ; game-relative-target=0x000A3342
000A3341 [00424161] c3                                           retn
000A3342 [00424162] 57                                           push    edi
000A3343 [00424163] 53                                           push    ebx
000A3344 [00424164] 83 ec 60                                     sub     esp, 60h ; '`'
000A3347 [00424167] 8b f9                                        mov     edi, ecx
000A3349 [00424169] 0f b7 d0                                     movzx   edx, ax
000A334C [0042416C] c1 e8 10                                     shr     eax, 10h
000A334F [0042416F] 3c 05                                        cmp     al, 5
000A3351 [00424171] 74 03                                        jz      short near ptr unk_424176 ; game-relative-target=0x000A3356
000A3353 [00424173] 83 c2 32                                     add     edx, 32h ; '2'
000A3356 [00424176] 52                                           push    edx
000A3357 [00424177] b8 00 71 47 00                               mov     eax, 477100h
000A335C [0042417C] ff d0                                        call    eax
000A335E [0042417E] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A3362 [00424182] ff b0 d0 00 00 00                            push    dword ptr [eax+0D0h]
000A3368 [00424188] 57                                           push    edi
000A3369 [00424189] b8 30 a3 47 00                               mov     eax, 47A330h
000A336E [0042418E] ff d0                                        call    eax
000A3370 [00424190] 8b cc                                        mov     ecx, esp
000A3372 [00424192] b8 b0 34 47 00                               mov     eax, 4734B0h
000A3377 [00424197] ff d0                                        call    eax
000A3379 [00424199] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A337D [0042419D] 54                                           push    esp
000A337E [0042419E] b8 90 82 47 00                               mov     eax, 478290h
000A3383 [004241A3] ff d0                                        call    eax
000A3385 [004241A5] 33 db                                        xor     ebx, ebx
000A3387 [004241A7] 8b 7c 24 04                                  mov     edi, [esp+4]
000A338B [004241AB] 43                                           inc     ebx
000A338C [004241AC] 8b 4f 08                                     mov     ecx, [edi+8]
000A338F [004241AF] b8 70 d0 45 00                               mov     eax, 45D070h
000A3394 [004241B4] ff d0                                        call    eax
000A3396 [004241B6] 3b c6                                        cmp     eax, esi
000A3398 [004241B8] 74 0d                                        jz      short near ptr unk_4241C7 ; game-relative-target=0x000A33A7
000A339A [004241BA] 80 fb 09                                     cmp     bl, 9
000A339D [004241BD] 7d 06                                        jge     short near ptr unk_4241C5 ; game-relative-target=0x000A33A5
000A339F [004241BF] 8b 3f                                        mov     edi, [edi]
000A33A1 [004241C1] 85 ff                                        test    edi, edi
000A33A3 [004241C3] 75 e6                                        jnz     short near ptr unk_4241AB ; game-relative-target=0x000A338B
000A33A5 [004241C5] 33 db                                        xor     ebx, ebx
000A33A7 [004241C7] 8b cc                                        mov     ecx, esp
000A33A9 [004241C9] b8 e0 80 51 00                               mov     eax, 5180E0h
000A33AE [004241CE] ff d0                                        call    eax
000A33B0 [004241D0] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A33B4 [004241D4] b8 10 9f 47 00                               mov     eax, 479F10h
000A33B9 [004241D9] ff d0                                        call    eax
000A33BB [004241DB] 83 c4 60                                     add     esp, 60h ; '`'
000A33BE [004241DE] 8b c3                                        mov     eax, ebx
000A33C0 [004241E0] 5b                                           pop     ebx
000A33C1 [004241E1] 5f                                           pop     edi
000A33C2 [004241E2] c3                                           retn
