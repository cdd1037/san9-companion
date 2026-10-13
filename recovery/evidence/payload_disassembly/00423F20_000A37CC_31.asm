; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423F20; baseline game VA=0x000A37CC; size=49
; Relative branch annotations use the baseline game destination.
000A37CC [00423F20] 51                                           push    ecx
000A37CD [00423F21] 8b ce                                        mov     ecx, esi
000A37CF [00423F23] b8 e0 2d 0a 00                               mov     eax, 0A2DE0h
000A37D4 [00423F28] ff d0                                        call    eax
000A37D6 [00423F2A] 59                                           pop     ecx
000A37D7 [00423F2B] 3c 02                                        cmp     al, 2
000A37D9 [00423F2D] 74 1c                                        jz      short near ptr unk_423F4B ; game-relative-target=0x000A37F7
000A37DB [00423F2F] 3c 01                                        cmp     al, 1
000A37DD [00423F31] 74 0f                                        jz      short near ptr unk_423F42 ; game-relative-target=0x000A37EE
000A37DF [00423F33] 80 79 0c 00                                  cmp     byte ptr [ecx+0Ch], 0
000A37E3 [00423F37] 75 06                                        jnz     short near ptr unk_423F3F ; game-relative-target=0x000A37EB
000A37E5 [00423F39] 58                                           pop     eax
000A37E6 [00423F3A] 68 3c 83 4b 00                               push    4B833Ch
000A37EB [00423F3F] c2 04 00                                     retn    4
000A37EE [00423F42] 51                                           push    ecx
000A37EF [00423F43] b8 e0 80 51 00                               mov     eax, 5180E0h
000A37F4 [00423F48] ff d0                                        call    eax
000A37F6 [00423F4A] 59                                           pop     ecx
000A37F7 [00423F4B] 68 70 ef 46 00                               push    46EF70h
000A37FC [00423F50] c3                                           retn
