; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421530; baseline game VA=0x000A2B00; size=162
; Relative branch annotations use the baseline game destination.
000A2B00 [00421530] 56                                           push    esi
000A2B01 [00421531] 57                                           push    edi
000A2B02 [00421532] 33 ff                                        xor     edi, edi
000A2B04 [00421534] 57                                           push    edi
000A2B05 [00421535] b8 00 71 47 00                               mov     eax, 477100h
000A2B0A [0042153A] ff d0                                        call    eax
000A2B0C [0042153C] 85 c0                                        test    eax, eax
000A2B0E [0042153E] 74 71                                        jz      short near ptr unk_4215B1 ; game-relative-target=0x000A2B81
000A2B10 [00421540] 8b f0                                        mov     esi, eax
000A2B12 [00421542] 8b ce                                        mov     ecx, esi
000A2B14 [00421544] b8 20 54 43 00                               mov     eax, 435420h
000A2B19 [00421549] ff d0                                        call    eax
000A2B1B [0042154B] 85 c0                                        test    eax, eax
000A2B1D [0042154D] 7e 62                                        jle     short near ptr unk_4215B1 ; game-relative-target=0x000A2B81
000A2B1F [0042154F] 56                                           push    esi
000A2B20 [00421550] 6a 7f                                        push    7Fh
000A2B22 [00421552] 6a 00                                        push    0
000A2B24 [00421554] 6a 00                                        push    0
000A2B26 [00421556] 8b c4                                        mov     eax, esp
000A2B28 [00421558] 6a 00                                        push    0
000A2B2A [0042155A] 50                                           push    eax
000A2B2B [0042155B] 68 80 0f 0a 00                               push    0A0F80h
000A2B30 [00421560] b9 20 05 0a 00                               mov     ecx, 0A0520h
000A2B35 [00421565] b8 80 f2 46 00                               mov     eax, 46F280h
000A2B3A [0042156A] ff d0                                        call    eax
000A2B3C [0042156C] 83 c4 10                                     add     esp, 10h
000A2B3F [0042156F] 68 60 45 47 00                               push    474560h
000A2B44 [00421574] b9 20 05 0a 00                               mov     ecx, 0A0520h
000A2B49 [00421579] b8 30 e8 46 00                               mov     eax, 46E830h
000A2B4E [0042157E] ff d0                                        call    eax
000A2B50 [00421580] 85 c0                                        test    eax, eax
000A2B52 [00421582] 7e 2d                                        jle     short near ptr unk_4215B1 ; game-relative-target=0x000A2B81
000A2B54 [00421584] 50                                           push    eax
000A2B55 [00421585] 8b ce                                        mov     ecx, esi
000A2B57 [00421587] b8 f0 00 0a 00                               mov     eax, 0A00F0h
000A2B5C [0042158C] ff d0                                        call    eax
000A2B5E [0042158E] 85 c0                                        test    eax, eax
000A2B60 [00421590] 7f 1f                                        jg      short near ptr unk_4215B1 ; game-relative-target=0x000A2B81
000A2B62 [00421592] 8b 35 24 05 0a 00                            mov     esi, ds:0A0524h
000A2B68 [00421598] 8b 4e 08                                     mov     ecx, [esi+8]
000A2B6B [0042159B] 8b 41 74                                     mov     eax, [ecx+74h]
000A2B6E [0042159E] f6 40 34 05                                  test    byte ptr [eax+34h], 5
000A2B72 [004215A2] 75 07                                        jnz     short near ptr unk_4215AB ; game-relative-target=0x000A2B7B
000A2B74 [004215A4] b8 60 5b 0a 00                               mov     eax, 0A5B60h
000A2B79 [004215A9] ff d0                                        call    eax
000A2B7B [004215AB] 8b 36                                        mov     esi, [esi]
000A2B7D [004215AD] 85 f6                                        test    esi, esi
000A2B7F [004215AF] 75 e7                                        jnz     short near ptr unk_421598 ; game-relative-target=0x000A2B68
000A2B81 [004215B1] 47                                           inc     edi
000A2B82 [004215B2] 81 ff fa 00 00 00                            cmp     edi, 0FAh
000A2B88 [004215B8] 0f 8c 76 ff ff ff                            jl      near ptr unk_421534 ; game-relative-target=0x000A2B04
000A2B8E [004215BE] b9 20 05 0a 00                               mov     ecx, 0A0520h
000A2B93 [004215C3] b8 e0 80 51 00                               mov     eax, 5180E0h
000A2B98 [004215C8] ff d0                                        call    eax
000A2B9A [004215CA] 5f                                           pop     edi
000A2B9B [004215CB] 5e                                           pop     esi
000A2B9C [004215CC] 68 10 ec 50 00                               push    50EC10h
000A2BA1 [004215D1] c3                                           retn
