; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424378; baseline game VA=0x004BBBAE; size=50
; Relative branch annotations use the baseline game destination.
004BBBAE [00424378] 5a                                           pop     edx
004BBBAF [00424379] 85 c0                                        test    eax, eax
004BBBB1 [0042437B] 74 29                                        jz      short near ptr unk_4243A6 ; game-relative-target=0x004BBBDC
004BBBB3 [0042437D] 8b 8e cc 00 00 00                            mov     ecx, [esi+0CCh]
004BBBB9 [00424383] 8b 54 24 08                                  mov     edx, [esp+8]
004BBBBD [00424387] 3b 4a 0c                                     cmp     ecx, [edx+0Ch]
004BBBC0 [0042438A] 74 0c                                        jz      short near ptr unk_424398 ; game-relative-target=0x004BBBCE
004BBBC2 [0042438C] 51                                           push    ecx
004BBBC3 [0042438D] e8 d8 33 f8 ff                               call    near ptr 3A776Ah ; game-relative-target=0x0043EFA0
004BBBC8 [00424392] 59                                           pop     ecx
004BBBC9 [00424393] 39 41 18                                     cmp     [ecx+18h], eax
004BBBCC [00424396] 7e 0e                                        jle     short near ptr unk_4243A6 ; game-relative-target=0x004BBBDC
004BBBCE [00424398] 33 c0                                        xor     eax, eax
004BBBD0 [0042439A] 81 7e 08 78 ec ff ff                         cmp     dword ptr [esi+8], 0FFFFEC78h
004BBBD7 [004243A1] 0f 9c c0                                     setl    al
004BBBDA [004243A4] 5e                                           pop     esi
004BBBDB [004243A5] c3                                           retn
004BBBDC [004243A6] 33 c0                                        xor     eax, eax
004BBBDE [004243A8] 5e                                           pop     esi
004BBBDF [004243A9] c3                                           retn
