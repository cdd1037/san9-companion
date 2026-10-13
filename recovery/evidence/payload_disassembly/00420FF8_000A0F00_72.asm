; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420FF8; baseline game VA=0x000A0F00; size=114
; Relative branch annotations use the baseline game destination.
000A0F00 [00420FF8] 8b 47 34                                     mov     eax, [edi+34h]
000A0F03 [00420FFB] 3c 17                                        cmp     al, 17h
000A0F05 [00420FFD] 74 0c                                        jz      short near ptr unk_42100B ; game-relative-target=0x000A0F13
000A0F07 [00420FFF] 3c 18                                        cmp     al, 18h
000A0F09 [00421001] 74 08                                        jz      short near ptr unk_42100B ; game-relative-target=0x000A0F13
000A0F0B [00421003] 3c 1d                                        cmp     al, 1Dh
000A0F0D [00421005] 7c 09                                        jl      short near ptr unk_421010 ; game-relative-target=0x000A0F18
000A0F0F [00421007] 3c 1f                                        cmp     al, 1Fh
000A0F11 [00421009] 7f 05                                        jg      short near ptr unk_421010 ; game-relative-target=0x000A0F18
000A0F13 [0042100B] e8 01 00 00 00                               call    near ptr unk_421011 ; game-relative-target=0x000A0F19
000A0F18 [00421010] c3                                           retn
000A0F19 [00421011] 55                                           push    ebp
000A0F1A [00421012] 53                                           push    ebx
000A0F1B [00421013] 33 db                                        xor     ebx, ebx
000A0F1D [00421015] 8b 6f 48                                     mov     ebp, [edi+48h]
000A0F20 [00421018] 85 ed                                        test    ebp, ebp
000A0F22 [0042101A] 74 2c                                        jz      short near ptr unk_421048 ; game-relative-target=0x000A0F50
000A0F24 [0042101C] 8b 4d 08                                     mov     ecx, [ebp+8]
000A0F27 [0042101F] 39 99 f4 00 00 00                            cmp     [ecx+0F4h], ebx
000A0F2D [00421025] 74 1a                                        jz      short near ptr unk_421041 ; game-relative-target=0x000A0F49
000A0F2F [00421027] 8b 99 f4 00 00 00                            mov     ebx, [ecx+0F4h]
000A0F35 [0042102D] 8b 4b 64                                     mov     ecx, [ebx+64h]
000A0F38 [00421030] 8b 01                                        mov     eax, [ecx]
000A0F3A [00421032] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A0F3D [00421035] 0f b6 90 00 0d 0a 00                         movzx   edx, byte ptr [eax+0A0D00h]
000A0F44 [0042103C] 83 fa 0a                                     cmp     edx, 0Ah
000A0F47 [0042103F] 7d 0a                                        jge     short near ptr unk_42104B ; game-relative-target=0x000A0F53
000A0F49 [00421041] 8b 6d 00                                     mov     ebp, [ebp+0]
000A0F4C [00421044] 85 ed                                        test    ebp, ebp
000A0F4E [00421046] 75 d4                                        jnz     short near ptr unk_42101C ; game-relative-target=0x000A0F24
000A0F50 [00421048] 5b                                           pop     ebx
000A0F51 [00421049] 5d                                           pop     ebp
000A0F52 [0042104A] c3                                           retn
000A0F53 [0042104B] 55                                           push    ebp
000A0F54 [0042104C] 8b 6d 00                                     mov     ebp, [ebp+0]
000A0F57 [0042104F] 8d 4f 44                                     lea     ecx, [edi+44h]
000A0F5A [00421052] b8 10 64 41 00                               mov     eax, 416410h
000A0F5F [00421057] ff d0                                        call    eax
000A0F61 [00421059] 85 ed                                        test    ebp, ebp
000A0F63 [0042105B] 74 eb                                        jz      short near ptr unk_421048 ; game-relative-target=0x000A0F50
000A0F65 [0042105D] 8b 4d 08                                     mov     ecx, [ebp+8]
000A0F68 [00421060] 39 99 f4 00 00 00                            cmp     [ecx+0F4h], ebx
000A0F6E [00421066] 74 e3                                        jz      short near ptr unk_42104B ; game-relative-target=0x000A0F53
000A0F70 [00421068] eb bd                                        jmp     short near ptr unk_421027 ; game-relative-target=0x000A0F2F
