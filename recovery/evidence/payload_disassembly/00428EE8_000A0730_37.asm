; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428EE8; baseline game VA=0x000A0730; size=55
; Relative branch annotations use the baseline game destination.
000A0730 [00428EE8] 55                                           push    ebp
000A0731 [00428EE9] 56                                           push    esi
000A0732 [00428EEA] b8 a0 86 40 00                               mov     eax, 4086A0h
000A0737 [00428EEF] ff d0                                        call    eax
000A0739 [00428EF1] 0f b6 05 d1 f3 43 00                         movzx   eax, byte ptr ds:43F3D1h
000A0740 [00428EF8] 85 c0                                        test    eax, eax
000A0742 [00428EFA] 74 20                                        jz      short near ptr unk_428F1C ; game-relative-target=0x000A0764
000A0744 [00428EFC] 6b c0 03                                     imul    eax, 3
000A0747 [00428EFF] 8d 56 4c                                     lea     edx, [esi+4Ch]
000A074A [00428F02] 6a 04                                        push    4
000A074C [00428F04] 59                                           pop     ecx
000A074D [00428F05] 28 02                                        sub     [edx], al
000A074F [00428F07] 83 c2 08                                     add     edx, 8
000A0752 [00428F0A] 49                                           dec     ecx
000A0753 [00428F0B] 75 f8                                        jnz     short near ptr unk_428F05 ; game-relative-target=0x000A074D
000A0755 [00428F0D] 8d 96 34 01 00 00                            lea     edx, [esi+134h]
000A075B [00428F13] 6a 08                                        push    8
000A075D [00428F15] 59                                           pop     ecx
000A075E [00428F16] 28 02                                        sub     [edx], al
000A0760 [00428F18] 42                                           inc     edx
000A0761 [00428F19] 49                                           dec     ecx
000A0762 [00428F1A] 75 fa                                        jnz     short near ptr unk_428F16 ; game-relative-target=0x000A075E
000A0764 [00428F1C] c2 08 00                                     retn    8
