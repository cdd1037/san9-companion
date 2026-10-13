; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428CC0; baseline game VA=0x000A7940; size=100
; Relative branch annotations use the baseline game destination.
000A7940 [00428CC0] b8 1f 85 eb 51                               mov     eax, 51EB851Fh
000A7945 [00428CC5] 80 3d 1a ff 43 00 00                         cmp     byte ptr ds:43FF1Ah, 0
000A794C [00428CCC] 75 01                                        jnz     short near ptr unk_428CCF ; game-relative-target=0x000A794F
000A794E [00428CCE] c3                                           retn
000A794F [00428CCF] 51                                           push    ecx
000A7950 [00428CD0] 56                                           push    esi
000A7951 [00428CD1] 0f b6 4f 04                                  movzx   ecx, byte ptr [edi+4]
000A7955 [00428CD5] 81 c1 00 79 0a 00                            add     ecx, 0A7900h
000A795B [00428CDB] 0f b6 11                                     movzx   edx, byte ptr [ecx]
000A795E [00428CDE] 80 7c 24 08 6f                               cmp     byte ptr [esp+8], 6Fh ; 'o'
000A7963 [00428CE3] 75 03                                        jnz     short near ptr unk_428CE8 ; game-relative-target=0x000A7968
000A7965 [00428CE5] 42                                           inc     edx
000A7966 [00428CE6] 88 11                                        mov     [ecx], dl
000A7968 [00428CE8] b8 81 5a bf 52                               mov     eax, 52BF5A81h
000A796D [00428CED] 4a                                           dec     edx
000A796E [00428CEE] 74 31                                        jz      short near ptr unk_428D21 ; game-relative-target=0x000A79A1
000A7970 [00428CF0] 50                                           push    eax
000A7971 [00428CF1] 0f b6 35 1a ff 43 00                         movzx   esi, byte ptr ds:43FF1Ah
000A7978 [00428CF8] 8b c6                                        mov     eax, esi
000A797A [00428CFA] 0f af f2                                     imul    esi, edx
000A797D [00428CFD] 99                                           cdq
000A797E [00428CFE] 6a 03                                        push    3
000A7980 [00428D00] 59                                           pop     ecx
000A7981 [00428D01] f7 f9                                        idiv    ecx
000A7983 [00428D03] 8a 15 15 ff 43 00                            mov     dl, ds:43FF15h
000A7989 [00428D09] 80 e2 03                                     and     dl, 3
000A798C [00428D0C] 3a d0                                        cmp     dl, al
000A798E [00428D0E] 58                                           pop     eax
000A798F [00428D0F] 7f 10                                        jg      short near ptr unk_428D21 ; game-relative-target=0x000A79A1
000A7991 [00428D11] 83 fe 0a                                     cmp     esi, 0Ah
000A7994 [00428D14] 7e 03                                        jle     short near ptr unk_428D19 ; game-relative-target=0x000A7999
000A7996 [00428D16] 6a 0a                                        push    0Ah
000A7998 [00428D18] 5e                                           pop     esi
000A7999 [00428D19] 69 f6 f0 2e 15 00                            imul    esi, 152EF0h
000A799F [00428D1F] 2b c6                                        sub     eax, esi
000A79A1 [00428D21] 5e                                           pop     esi
000A79A2 [00428D22] 59                                           pop     ecx
000A79A3 [00428D23] c3                                           retn
