; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421C50; baseline game VA=0x000A1780; size=52
; Relative branch annotations use the baseline game destination.
000A1780 [00421C50] 55                                           push    ebp
000A1781 [00421C51] 57                                           push    edi
000A1782 [00421C52] 8b e9                                        mov     ebp, ecx
000A1784 [00421C54] 8b 7d 04                                     mov     edi, [ebp+4]
000A1787 [00421C57] 85 ff                                        test    edi, edi
000A1789 [00421C59] 74 1f                                        jz      short near ptr unk_421C7A ; game-relative-target=0x000A17AA
000A178B [00421C5B] 8b 4f 08                                     mov     ecx, [edi+8]
000A178E [00421C5E] 8b 3f                                        mov     edi, [edi]
000A1790 [00421C60] 8b 41 58                                     mov     eax, [ecx+58h]
000A1793 [00421C63] 83 f8 26                                     cmp     eax, 26h ; '&'
000A1796 [00421C66] 75 06                                        jnz     short near ptr unk_421C6E ; game-relative-target=0x000A179E
000A1798 [00421C68] 80 79 52 03                                  cmp     byte ptr [ecx+52h], 3
000A179C [00421C6C] 74 e9                                        jz      short near ptr unk_421C57 ; game-relative-target=0x000A1787
000A179E [00421C6E] 51                                           push    ecx
000A179F [00421C6F] 8b cd                                        mov     ecx, ebp
000A17A1 [00421C71] b8 50 ee 46 00                               mov     eax, 46EE50h
000A17A6 [00421C76] ff d0                                        call    eax
000A17A8 [00421C78] eb dd                                        jmp     short near ptr unk_421C57 ; game-relative-target=0x000A1787
000A17AA [00421C7A] 8b cd                                        mov     ecx, ebp
000A17AC [00421C7C] 5f                                           pop     edi
000A17AD [00421C7D] 5d                                           pop     ebp
000A17AE [00421C7E] 68 30 e8 46 00                               push    46E830h
000A17B3 [00421C83] c3                                           retn
