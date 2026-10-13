; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429728; baseline game VA=0x000A7EB0; size=72
; Relative branch annotations use the baseline game destination.
000A7EB0 [00429728] 68 b0 bf 44 00                               push    44BFB0h
000A7EB5 [0042972D] b8 70 7e 0a 00                               mov     eax, 0A7E70h
000A7EBA [00429732] ff d0                                        call    eax
000A7EBC [00429734] 85 c0                                        test    eax, eax
000A7EBE [00429736] 7d 01                                        jge     short near ptr unk_429739 ; game-relative-target=0x000A7EC1
000A7EC0 [00429738] c3                                           retn
000A7EC1 [00429739] 50                                           push    eax
000A7EC2 [0042973A] b8 b0 31 45 00                               mov     eax, 4531B0h
000A7EC7 [0042973F] ff d0                                        call    eax
000A7EC9 [00429741] 5a                                           pop     edx
000A7ECA [00429742] 85 c0                                        test    eax, eax
000A7ECC [00429744] 74 27                                        jz      short near ptr unk_42976D ; game-relative-target=0x000A7EF5
000A7ECE [00429746] 33 c9                                        xor     ecx, ecx
000A7ED0 [00429748] 3b f0                                        cmp     esi, eax
000A7ED2 [0042974A] 74 0d                                        jz      short near ptr unk_429759 ; game-relative-target=0x000A7EE1
000A7ED4 [0042974C] 8a 8e 04 01 00 00                            mov     cl, [esi+104h]
000A7EDA [00429752] 41                                           inc     ecx
000A7EDB [00429753] 80 e1 07                                     and     cl, 7
000A7EDE [00429756] c1 e1 0a                                     shl     ecx, 0Ah
000A7EE1 [00429759] 0f b6 40 68                                  movzx   eax, byte ptr [eax+68h]
000A7EE5 [0042975D] f7 d8                                        neg     eax
000A7EE7 [0042975F] c1 e0 17                                     shl     eax, 17h
000A7EEA [00429762] 09 c8                                        or      eax, ecx
000A7EEC [00429764] c1 e2 0d                                     shl     edx, 0Dh
000A7EEF [00429767] 09 d0                                        or      eax, edx
000A7EF1 [00429769] 09 44 24 08                                  or      [esp+8], eax
000A7EF5 [0042976D] 8b ce                                        mov     ecx, esi
000A7EF7 [0042976F] c3                                           retn
