; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004280C4; baseline game VA=0x000A4D40; size=64
; Relative branch annotations use the baseline game destination.
000A4D40 [004280C4] 51                                           push    ecx
000A4D41 [004280C5] 83 fb 01                                     cmp     ebx, 1
000A4D44 [004280C8] 7e 06                                        jle     short near ptr unk_4280D0 ; game-relative-target=0x000A4D4C
000A4D46 [004280CA] 83 f9 1e                                     cmp     ecx, 1Eh
000A4D49 [004280CD] 7c 01                                        jl      short near ptr unk_4280D0 ; game-relative-target=0x000A4D4C
000A4D4B [004280CF] 4b                                           dec     ebx
000A4D4C [004280D0] 6a 17                                        push    17h
000A4D4E [004280D2] b8 20 37 45 00                               mov     eax, 453720h
000A4D53 [004280D7] ff d0                                        call    eax
000A4D55 [004280D9] 5a                                           pop     edx
000A4D56 [004280DA] 8b 50 64                                     mov     edx, [eax+64h]
000A4D59 [004280DD] 85 d2                                        test    edx, edx
000A4D5B [004280DF] 75 08                                        jnz     short near ptr unk_4280E9 ; game-relative-target=0x000A4D65
000A4D5D [004280E1] 68 b7 4f 50 00                               push    504FB7h
000A4D62 [004280E6] c2 08 00                                     retn    8
000A4D65 [004280E9] b9 28 00 00 00                               mov     ecx, 28h ; '('
000A4D6A [004280EE] 2b ca                                        sub     ecx, edx
000A4D6C [004280F0] 83 f9 10                                     cmp     ecx, 10h
000A4D6F [004280F3] 7d 02                                        jge     short near ptr unk_4280F7 ; game-relative-target=0x000A4D73
000A4D71 [004280F5] b1 10                                        mov     cl, 10h
000A4D73 [004280F7] b8 67 66 66 66                               mov     eax, 66666667h
000A4D78 [004280FC] 99                                           cdq
000A4D79 [004280FD] f7 f9                                        idiv    ecx
000A4D7B [004280FF] 6b c0 14                                     imul    eax, 14h
000A4D7E [00428102] 59                                           pop     ecx
000A4D7F [00428103] c3                                           retn
