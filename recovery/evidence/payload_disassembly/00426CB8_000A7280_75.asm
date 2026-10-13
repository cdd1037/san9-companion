; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426CB8; baseline game VA=0x000A7280; size=117
; Relative branch annotations use the baseline game destination.
000A7280 [00426CB8] 57                                           push    edi
000A7281 [00426CB9] 55                                           push    ebp
000A7282 [00426CBA] bf e4 5e 54 01                               mov     edi, 1545EE4h
000A7287 [00426CBF] 33 ed                                        xor     ebp, ebp
000A7289 [00426CC1] 8d 47 38                                     lea     eax, [edi+38h]
000A728C [00426CC4] 50                                           push    eax
000A728D [00426CC5] 8b cb                                        mov     ecx, ebx
000A728F [00426CC7] b8 20 63 0a 00                               mov     eax, 0A6320h
000A7294 [00426CCC] ff d0                                        call    eax
000A7296 [00426CCE] 85 c0                                        test    eax, eax
000A7298 [00426CD0] 75 36                                        jnz     short near ptr unk_426D08 ; game-relative-target=0x000A72D0
000A729A [00426CD2] b4 04                                        mov     ah, 4
000A729C [00426CD4] b9 87 f8 43 00                               mov     ecx, 43F887h
000A72A1 [00426CD9] 81 fd fa 00 00 00                            cmp     ebp, 0FAh
000A72A7 [00426CDF] 7d 0b                                        jge     short near ptr unk_426CEC ; game-relative-target=0x000A72B4
000A72A9 [00426CE1] b4 04                                        mov     ah, 4
000A72AB [00426CE3] 41                                           inc     ecx
000A72AC [00426CE4] 83 fd 32                                     cmp     ebp, 32h ; '2'
000A72AF [00426CE7] 7d 03                                        jge     short near ptr unk_426CEC ; game-relative-target=0x000A72B4
000A72B1 [00426CE9] b4 04                                        mov     ah, 4
000A72B3 [00426CEB] 41                                           inc     ecx
000A72B4 [00426CEC] 39 47 10                                     cmp     [edi+10h], eax
000A72B7 [00426CEF] 7c 17                                        jl      short near ptr unk_426D08 ; game-relative-target=0x000A72D0
000A72B9 [00426CF1] 51                                           push    ecx
000A72BA [00426CF2] 8d 47 08                                     lea     eax, [edi+8]
000A72BD [00426CF5] 50                                           push    eax
000A72BE [00426CF6] 8d 4e 04                                     lea     ecx, [esi+4]
000A72C1 [00426CF9] b8 00 6c 0a 00                               mov     eax, 0A6C00h
000A72C6 [00426CFE] ff d0                                        call    eax
000A72C8 [00426D00] 59                                           pop     ecx
000A72C9 [00426D01] 0f b6 11                                     movzx   edx, byte ptr [ecx]
000A72CC [00426D04] 3b c2                                        cmp     eax, edx
000A72CE [00426D06] 7e 1e                                        jle     short near ptr unk_426D26 ; game-relative-target=0x000A72EE
000A72D0 [00426D08] 81 c7 80 00 00 00                            add     edi, 80h
000A72D6 [00426D0E] 81 fd fa 00 00 00                            cmp     ebp, 0FAh
000A72DC [00426D14] 7c 03                                        jl      short near ptr unk_426D19 ; game-relative-target=0x000A72E1
000A72DE [00426D16] 83 c7 10                                     add     edi, 10h
000A72E1 [00426D19] 45                                           inc     ebp
000A72E2 [00426D1A] 81 fd 4c 04 00 00                            cmp     ebp, 44Ch
000A72E8 [00426D20] 7c 9f                                        jl      short near ptr unk_426CC1 ; game-relative-target=0x000A7289
000A72EA [00426D22] 33 c0                                        xor     eax, eax
000A72EC [00426D24] eb 04                                        jmp     short near ptr unk_426D2A ; game-relative-target=0x000A72F2
000A72EE [00426D26] 8b 47 04                                     mov     eax, [edi+4]
000A72F1 [00426D29] 40                                           inc     eax
000A72F2 [00426D2A] 5d                                           pop     ebp
000A72F3 [00426D2B] 5f                                           pop     edi
000A72F4 [00426D2C] c3                                           retn
