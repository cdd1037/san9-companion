; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427BA0; baseline game VA=0x000A6A00; size=188
; Relative branch annotations use the baseline game destination.
000A6A00 [00427BA0] 51                                           push    ecx
000A6A01 [00427BA1] 8b 4e 74                                     mov     ecx, [esi+74h]
000A6A04 [00427BA4] f6 41 34 05                                  test    byte ptr [ecx+34h], 5
000A6A08 [00427BA8] 75 18                                        jnz     short near ptr unk_427BC2 ; game-relative-target=0x000A6A22
000A6A0A [00427BAA] 83 7f 0c 26                                  cmp     dword ptr [edi+0Ch], 26h ; '&'
000A6A0E [00427BAE] 75 12                                        jnz     short near ptr unk_427BC2 ; game-relative-target=0x000A6A22
000A6A10 [00427BB0] 80 7f 06 03                                  cmp     byte ptr [edi+6], 3
000A6A14 [00427BB4] 74 0c                                        jz      short near ptr unk_427BC2 ; game-relative-target=0x000A6A22
000A6A16 [00427BB6] f6 46 21 10                                  test    byte ptr [esi+21h], 10h
000A6A1A [00427BBA] 74 06                                        jz      short near ptr unk_427BC2 ; game-relative-target=0x000A6A22
000A6A1C [00427BBC] 80 7f 0a 03                                  cmp     byte ptr [edi+0Ah], 3
000A6A20 [00427BC0] 75 07                                        jnz     short near ptr unk_427BC9 ; game-relative-target=0x000A6A29
000A6A22 [00427BC2] 59                                           pop     ecx
000A6A23 [00427BC3] 68 c0 cc 49 00                               push    49CCC0h
000A6A28 [00427BC8] c3                                           retn
000A6A29 [00427BC9] 57                                           push    edi
000A6A2A [00427BCA] bd ff ff ff 7f                               mov     ebp, 7FFFFFFFh
000A6A2F [00427BCF] 8b 99 9c 00 00 00                            mov     ebx, [ecx+9Ch]
000A6A35 [00427BD5] 8b 4b 08                                     mov     ecx, [ebx+8]
000A6A38 [00427BD8] f6 41 20 02                                  test    byte ptr [ecx+20h], 2
000A6A3C [00427BDC] 75 42                                        jnz     short near ptr unk_427C20 ; game-relative-target=0x000A6A80
000A6A3E [00427BDE] 83 79 58 26                                  cmp     dword ptr [ecx+58h], 26h ; '&'
000A6A42 [00427BE2] 75 3c                                        jnz     short near ptr unk_427C20 ; game-relative-target=0x000A6A80
000A6A44 [00427BE4] 8b 41 50                                     mov     eax, [ecx+50h]
000A6A47 [00427BE7] 3b 46 50                                     cmp     eax, [esi+50h]
000A6A4A [00427BEA] 75 34                                        jnz     short near ptr unk_427C20 ; game-relative-target=0x000A6A80
000A6A4C [00427BEC] f6 41 21 10                                  test    byte ptr [ecx+21h], 10h
000A6A50 [00427BF0] 75 2e                                        jnz     short near ptr unk_427C20 ; game-relative-target=0x000A6A80
000A6A52 [00427BF2] a1 14 ff 43 00                               mov     eax, ds:43FF14h
000A6A57 [00427BF7] 39 41 08                                     cmp     [ecx+8], eax
000A6A5A [00427BFA] 74 24                                        jz      short near ptr unk_427C20 ; game-relative-target=0x000A6A80
000A6A5C [00427BFC] 56                                           push    esi
000A6A5D [00427BFD] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A6A62 [00427C02] ff d0                                        call    eax
000A6A64 [00427C04] 8b 4b 08                                     mov     ecx, [ebx+8]
000A6A67 [00427C07] 8b 51 64                                     mov     edx, [ecx+64h]
000A6A6A [00427C0A] 3b 56 64                                     cmp     edx, [esi+64h]
000A6A6D [00427C0D] 74 09                                        jz      short near ptr unk_427C18 ; game-relative-target=0x000A6A78
000A6A6F [00427C0F] 83 f8 32                                     cmp     eax, 32h ; '2'
000A6A72 [00427C12] 7f 0c                                        jg      short near ptr unk_427C20 ; game-relative-target=0x000A6A80
000A6A74 [00427C14] 40                                           inc     eax
000A6A75 [00427C15] c1 e0 18                                     shl     eax, 18h
000A6A78 [00427C18] 3b c5                                        cmp     eax, ebp
000A6A7A [00427C1A] 7d 04                                        jge     short near ptr unk_427C20 ; game-relative-target=0x000A6A80
000A6A7C [00427C1C] 8b e8                                        mov     ebp, eax
000A6A7E [00427C1E] 8b f9                                        mov     edi, ecx
000A6A80 [00427C20] 8b 1b                                        mov     ebx, [ebx]
000A6A82 [00427C22] 85 db                                        test    ebx, ebx
000A6A84 [00427C24] 75 af                                        jnz     short near ptr unk_427BD5 ; game-relative-target=0x000A6A35
000A6A86 [00427C26] 81 fd ff ff ff 7f                            cmp     ebp, 7FFFFFFFh
000A6A8C [00427C2C] 74 26                                        jz      short near ptr unk_427C54 ; game-relative-target=0x000A6AB4
000A6A8E [00427C2E] a1 14 ff 43 00                               mov     eax, ds:43FF14h
000A6A93 [00427C33] 89 47 08                                     mov     [edi+8], eax
000A6A96 [00427C36] 81 fd 00 00 00 01                            cmp     ebp, 1000000h
000A6A9C [00427C3C] 7c 03                                        jl      short near ptr unk_427C41 ; game-relative-target=0x000A6AA1
000A6A9E [00427C3E] c1 ed 18                                     shr     ebp, 18h
000A6AA1 [00427C41] 83 fd 14                                     cmp     ebp, 14h
000A6AA4 [00427C44] 7e 0e                                        jle     short near ptr unk_427C54 ; game-relative-target=0x000A6AB4
000A6AA6 [00427C46] c7 46 7c 00 00 00 00                         mov     dword ptr [esi+7Ch], 0
000A6AAD [00427C4D] 8b 47 78                                     mov     eax, [edi+78h]
000A6AB0 [00427C50] 89 44 24 10                                  mov     [esp+10h], eax
000A6AB4 [00427C54] 5f                                           pop     edi
000A6AB5 [00427C55] 59                                           pop     ecx
000A6AB6 [00427C56] 68 c0 cc 49 00                               push    49CCC0h
000A6ABB [00427C5B] c3                                           retn
