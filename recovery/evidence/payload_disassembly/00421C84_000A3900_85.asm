; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421C84; baseline game VA=0x000A3900; size=133
; Relative branch annotations use the baseline game destination.
000A3900 [00421C84] 33 c0                                        xor     eax, eax
000A3902 [00421C86] 80 3d 14 ff 43 00 02                         cmp     byte ptr ds:43FF14h, 2
000A3909 [00421C8D] 75 01                                        jnz     short near ptr unk_421C90 ; game-relative-target=0x000A390C
000A390B [00421C8F] c3                                           retn
000A390C [00421C90] 57                                           push    edi
000A390D [00421C91] 8b be cc 00 00 00                            mov     edi, [esi+0CCh]
000A3913 [00421C97] b8 90 4b 45 00                               mov     eax, 454B90h
000A3918 [00421C9C] ff d0                                        call    eax
000A391A [00421C9E] 05 fe 01 00 00                               add     eax, 1FEh
000A391F [00421CA3] 50                                           push    eax
000A3920 [00421CA4] 8b cf                                        mov     ecx, edi
000A3922 [00421CA6] b8 e0 ed 43 00                               mov     eax, 43EDE0h
000A3927 [00421CAB] ff d0                                        call    eax
000A3929 [00421CAD] 2b 47 18                                     sub     eax, [edi+18h]
000A392C [00421CB0] 85 c0                                        test    eax, eax
000A392E [00421CB2] 7e 14                                        jle     short near ptr unk_421CC8 ; game-relative-target=0x000A3944
000A3930 [00421CB4] 50                                           push    eax
000A3931 [00421CB5] 68 68 01 00 00                               push    168h
000A3936 [00421CBA] 8b cf                                        mov     ecx, edi
000A3938 [00421CBC] b8 80 da 43 00                               mov     eax, 43DA80h
000A393D [00421CC1] ff d0                                        call    eax
000A393F [00421CC3] 5a                                           pop     edx
000A3940 [00421CC4] 3b c2                                        cmp     eax, edx
000A3942 [00421CC6] 7c 39                                        jl      short near ptr unk_421D01 ; game-relative-target=0x000A397D
000A3944 [00421CC8] 8b 86 d0 01 00 00                            mov     eax, [esi+1D0h]
000A394A [00421CCE] 6b c0 64                                     imul    eax, 64h ; 'd'
000A394D [00421CD1] 99                                           cdq
000A394E [00421CD2] 8b 8e d8 01 00 00                            mov     ecx, [esi+1D8h]
000A3954 [00421CD8] f7 f1                                        div     ecx
000A3956 [00421CDA] f7 d8                                        neg     eax
000A3958 [00421CDC] 83 c0 64                                     add     eax, 64h ; 'd'
000A395B [00421CDF] 8b 96 c0 01 00 00                            mov     edx, [esi+1C0h]
000A3961 [00421CE5] c1 ea 0a                                     shr     edx, 0Ah
000A3964 [00421CE8] 03 c2                                        add     eax, edx
000A3966 [00421CEA] 50                                           push    eax
000A3967 [00421CEB] ff 15 dc f2 5f 00                            call    dword ptr ds:5FF2DCh
000A396D [00421CF1] 33 d2                                        xor     edx, edx
000A396F [00421CF3] b9 64 00 00 00                               mov     ecx, 64h ; 'd'
000A3974 [00421CF8] f7 f1                                        div     ecx
000A3976 [00421CFA] 59                                           pop     ecx
000A3977 [00421CFB] 33 c0                                        xor     eax, eax
000A3979 [00421CFD] 3b d1                                        cmp     edx, ecx
000A397B [00421CFF] 7d 06                                        jge     short near ptr unk_421D07 ; game-relative-target=0x000A3983
000A397D [00421D01] 8b 86 d8 01 00 00                            mov     eax, [esi+1D8h]
000A3983 [00421D07] 5f                                           pop     edi
000A3984 [00421D08] c3                                           retn
