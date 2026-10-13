; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426040; baseline game VA=0x000A59C0; size=53
; Relative branch annotations use the baseline game destination.
000A59C0 [00426040] 50                                           push    eax
000A59C1 [00426041] f7 d8                                        neg     eax
000A59C3 [00426043] 1b c0                                        sbb     eax, eax
000A59C5 [00426045] 83 e0 19                                     and     eax, 19h
000A59C8 [00426048] 83 c0 73                                     add     eax, 73h ; 's'
000A59CB [0042604B] 8b 4d 38                                     mov     ecx, [ebp+38h]
000A59CE [0042604E] 8b 89 bc 00 00 00                            mov     ecx, [ecx+0BCh]
000A59D4 [00426054] 8b 51 78                                     mov     edx, [ecx+78h]
000A59D7 [00426057] 6b d2 0a                                     imul    edx, 0Ah
000A59DA [0042605A] 03 c2                                        add     eax, edx
000A59DC [0042605C] 0f af f0                                     imul    esi, eax
000A59DF [0042605F] 58                                           pop     eax
000A59E0 [00426060] 85 c0                                        test    eax, eax
000A59E2 [00426062] b8 1f 85 eb 51                               mov     eax, 51EB851Fh
000A59E7 [00426067] 74 06                                        jz      short near ptr unk_42606F ; game-relative-target=0x000A59EF
000A59E9 [00426069] 68 aa 5a 4b 00                               push    4B5AAAh
000A59EE [0042606E] c3                                           retn
000A59EF [0042606F] 68 06 5b 4b 00                               push    4B5B06h
000A59F4 [00426074] c3                                           retn
