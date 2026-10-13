; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422628; baseline game VA=0x000A3F30; size=89
; Relative branch annotations use the baseline game destination.
000A3F30 [00422628] 56                                           push    esi
000A3F31 [00422629] 8b f1                                        mov     esi, ecx
000A3F33 [0042262B] 8b 4d 3c                                     mov     ecx, [ebp+3Ch]
000A3F36 [0042262E] 8b 41 30                                     mov     eax, [ecx+30h]
000A3F39 [00422631] 3d 10 27 00 00                               cmp     eax, 2710h
000A3F3E [00422636] 7d 17                                        jge     short near ptr unk_42264F ; game-relative-target=0x000A3F57
000A3F40 [00422638] 50                                           push    eax
000A3F41 [00422639] ff 15 1c f3 5f 00                            call    dword ptr ds:5FF31Ch
000A3F47 [0042263F] 5a                                           pop     edx
000A3F48 [00422640] 0f af 06                                     imul    eax, [esi]
000A3F4B [00422643] 99                                           cdq
000A3F4C [00422644] b9 64 00 00 00                               mov     ecx, 64h ; 'd'
000A3F51 [00422649] f7 f1                                        div     ecx
000A3F53 [0042264B] 89 06                                        mov     [esi], eax
000A3F55 [0042264D] 5e                                           pop     esi
000A3F56 [0042264E] c3                                           retn
000A3F57 [0042264F] 50                                           push    eax
000A3F58 [00422650] 8b 4d 30                                     mov     ecx, [ebp+30h]
000A3F5B [00422653] 8b 41 68                                     mov     eax, [ecx+68h]
000A3F5E [00422656] 83 e8 3c                                     sub     eax, 3Ch ; '<'
000A3F61 [00422659] 85 c0                                        test    eax, eax
000A3F63 [0042265B] 7d 02                                        jge     short near ptr unk_42265F ; game-relative-target=0x000A3F67
000A3F65 [0042265D] 33 c0                                        xor     eax, eax
000A3F67 [0042265F] 69 c0 e8 03 00 00                            imul    eax, 3E8h
000A3F6D [00422665] 59                                           pop     ecx
000A3F6E [00422666] 3b c1                                        cmp     eax, ecx
000A3F70 [00422668] 7e 02                                        jle     short near ptr unk_42266C ; game-relative-target=0x000A3F74
000A3F72 [0042266A] 8b c1                                        mov     eax, ecx
000A3F74 [0042266C] 05 a0 86 01 00                               add     eax, 186A0h
000A3F79 [00422671] c1 e8 04                                     shr     eax, 4
000A3F7C [00422674] 0f af 06                                     imul    eax, [esi]
000A3F7F [00422677] b9 6a 18 00 00                               mov     ecx, 186Ah
000A3F84 [0042267C] 99                                           cdq
000A3F85 [0042267D] f7 f1                                        div     ecx
000A3F87 [0042267F] eb ca                                        jmp     short near ptr unk_42264B ; game-relative-target=0x000A3F53
