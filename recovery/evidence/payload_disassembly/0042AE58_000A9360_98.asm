; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042AE58; baseline game VA=0x000A9360; size=152
; Relative branch annotations use the baseline game destination.
000A9360 [0042AE58] 83 fa 46                                     cmp     edx, 46h ; 'F'
000A9363 [0042AE5B] 75 0b                                        jnz     short near ptr unk_42AE68 ; game-relative-target=0x000A9370
000A9365 [0042AE5D] ba f0 03 00 00                               mov     edx, 3F0h
000A936A [0042AE62] 68 00 84 0a 00                               push    0A8400h
000A936F [0042AE67] c3                                           retn
000A9370 [0042AE68] 56                                           push    esi
000A9371 [0042AE69] 57                                           push    edi
000A9372 [0042AE6A] 55                                           push    ebp
000A9373 [0042AE6B] 8b f1                                        mov     esi, ecx
000A9375 [0042AE6D] 8d b9 8c 07 00 00                            lea     edi, [ecx+78Ch]
000A937B [0042AE73] 8b ea                                        mov     ebp, edx
000A937D [0042AE75] 33 c9                                        xor     ecx, ecx
000A937F [0042AE77] ba 51 57 45 52                               mov     edx, 52455751h
000A9384 [0042AE7C] 0f b6 c2                                     movzx   eax, dl
000A9387 [0042AE7F] 3b c5                                        cmp     eax, ebp
000A9389 [0042AE81] 75 08                                        jnz     short near ptr unk_42AE8B ; game-relative-target=0x000A9393
000A938B [0042AE83] 8d 14 8f                                     lea     edx, [edi+ecx*4]
000A938E [0042AE86] 83 32 01                                     xor     dword ptr [edx], 1
000A9391 [0042AE89] eb 36                                        jmp     short near ptr unk_42AEC1 ; game-relative-target=0x000A93C9
000A9393 [0042AE8B] 41                                           inc     ecx
000A9394 [0042AE8C] c1 ea 08                                     shr     edx, 8
000A9397 [0042AE8F] 83 f9 03                                     cmp     ecx, 3
000A939A [0042AE92] 7e e8                                        jle     short near ptr unk_42AE7C ; game-relative-target=0x000A9384
000A939C [0042AE94] 83 fd 41                                     cmp     ebp, 41h ; 'A'
000A939F [0042AE97] 75 12                                        jnz     short near ptr unk_42AEAB ; game-relative-target=0x000A93B3
000A93A1 [0042AE99] 8b 07                                        mov     eax, [edi]
000A93A3 [0042AE9B] 83 f0 01                                     xor     eax, 1
000A93A6 [0042AE9E] 89 07                                        mov     [edi], eax
000A93A8 [0042AEA0] 89 47 04                                     mov     [edi+4], eax
000A93AB [0042AEA3] 89 47 08                                     mov     [edi+8], eax
000A93AE [0042AEA6] 89 47 0c                                     mov     [edi+0Ch], eax
000A93B1 [0042AEA9] eb 16                                        jmp     short near ptr unk_42AEC1 ; game-relative-target=0x000A93C9
000A93B3 [0042AEAB] 83 fd 53                                     cmp     ebp, 53h ; 'S'
000A93B6 [0042AEAE] 75 1d                                        jnz     short near ptr unk_42AECD ; game-relative-target=0x000A93D5
000A93B8 [0042AEB0] 8b 47 04                                     mov     eax, [edi+4]
000A93BB [0042AEB3] 89 07                                        mov     [edi], eax
000A93BD [0042AEB5] 89 47 0c                                     mov     [edi+0Ch], eax
000A93C0 [0042AEB8] 83 f0 01                                     xor     eax, 1
000A93C3 [0042AEBB] 89 47 04                                     mov     [edi+4], eax
000A93C6 [0042AEBE] 89 47 08                                     mov     [edi+8], eax
000A93C9 [0042AEC1] 8b ce                                        mov     ecx, esi
000A93CB [0042AEC3] 8b 01                                        mov     eax, [ecx]
000A93CD [0042AEC5] 6a 01                                        push    1
000A93CF [0042AEC7] ff 90 ec 00 00 00                            call    dword ptr [eax+0ECh]
000A93D5 [0042AECD] 5d                                           pop     ebp
000A93D6 [0042AECE] 5f                                           pop     edi
000A93D7 [0042AECF] 5e                                           pop     esi
000A93D8 [0042AED0] c3                                           retn
000A93D9 [0042AED1] 90                                           nop
000A93DA [0042AED2] 90                                           nop
000A93DB [0042AED3] 90                                           nop
000A93DC [0042AED4] 90                                           nop
000A93DD [0042AED5] 90                                           nop
000A93DE [0042AED6] 90                                           nop
000A93DF [0042AED7] 90                                           nop
000A93E0 [0042AED8] 83 fa 57                                     cmp     edx, 57h ; 'W'
000A93E3 [0042AEDB] 74 01                                        jz      short near ptr unk_42AEDE ; game-relative-target=0x000A93E6
000A93E5 [0042AEDD] c3                                           retn
000A93E6 [0042AEDE] 83 b1 90 07 00 00 01                         xor     dword ptr [ecx+790h], 1
000A93ED [0042AEE5] 8b 01                                        mov     eax, [ecx]
000A93EF [0042AEE7] 6a 01                                        push    1
000A93F1 [0042AEE9] ff 90 ec 00 00 00                            call    dword ptr [eax+0ECh]
000A93F7 [0042AEEF] c3                                           retn
