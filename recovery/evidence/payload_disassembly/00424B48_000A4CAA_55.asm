; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424B48; baseline game VA=0x000A4CAA; size=85
; Relative branch annotations use the baseline game destination.
000A4CAA [00424B48] 51                                           push    ecx
000A4CAB [00424B49] 8b 4d 38                                     mov     ecx, [ebp+38h]
000A4CAE [00424B4C] b8 c3 4c 0a 00                               mov     eax, 0A4CC3h
000A4CB3 [00424B51] ff d0                                        call    eax
000A4CB5 [00424B53] 85 c0                                        test    eax, eax
000A4CB7 [00424B55] 59                                           pop     ecx
000A4CB8 [00424B56] 74 06                                        jz      short near ptr unk_424B5E ; game-relative-target=0x000A4CC0
000A4CBA [00424B58] 68 50 f7 46 00                               push    46F750h
000A4CBF [00424B5D] c3                                           retn
000A4CC0 [00424B5E] c2 08 00                                     retn    8
000A4CC3 [00424B61] 8b 81 b8 00 00 00                            mov     eax, [ecx+0B8h]
000A4CC9 [00424B67] 3b c8                                        cmp     ecx, eax
000A4CCB [00424B69] 75 01                                        jnz     short near ptr unk_424B6C ; game-relative-target=0x000A4CCE
000A4CCD [00424B6B] c3                                           retn
000A4CCE [00424B6C] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A4CD2 [00424B70] 75 03                                        jnz     short near ptr unk_424B75 ; game-relative-target=0x000A4CD7
000A4CD4 [00424B72] 33 c0                                        xor     eax, eax
000A4CD6 [00424B74] c3                                           retn
000A4CD7 [00424B75] ba 38 3c 25 01                               mov     edx, 1253C38h
000A4CDC [00424B7A] 3b d0                                        cmp     edx, eax
000A4CDE [00424B7C] 74 0c                                        jz      short near ptr unk_424B8A ; game-relative-target=0x000A4CEC
000A4CE0 [00424B7E] 3b d1                                        cmp     edx, ecx
000A4CE2 [00424B80] 74 16                                        jz      short near ptr unk_424B98 ; game-relative-target=0x000A4CFA
000A4CE4 [00424B82] 39 82 b8 00 00 00                            cmp     [edx+0B8h], eax
000A4CEA [00424B88] 74 0e                                        jz      short near ptr unk_424B98 ; game-relative-target=0x000A4CFA
000A4CEC [00424B8A] 81 c2 d4 00 00 00                            add     edx, 0D4h
000A4CF2 [00424B90] 81 fa cc 64 25 01                            cmp     edx, 12564CCh
000A4CF8 [00424B96] 7e e2                                        jle     short near ptr unk_424B7A ; game-relative-target=0x000A4CDC
000A4CFA [00424B98] 3b d1                                        cmp     edx, ecx
000A4CFC [00424B9A] 75 d6                                        jnz     short near ptr unk_424B72 ; game-relative-target=0x000A4CD4
000A4CFE [00424B9C] c3                                           retn
