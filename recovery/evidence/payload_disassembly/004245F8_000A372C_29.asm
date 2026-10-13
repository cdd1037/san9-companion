; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004245F8; baseline game VA=0x000A372C; size=41
; Relative branch annotations use the baseline game destination.
000A372C [004245F8] 50                                           push    eax
000A372D [004245F9] 3b c8                                        cmp     ecx, eax
000A372F [004245FB] 7e 20                                        jle     short near ptr unk_42461D ; game-relative-target=0x000A3751
000A3731 [004245FD] 8b 8b b8 00 00 00                            mov     ecx, [ebx+0B8h]
000A3737 [00424603] f6 41 34 01                                  test    byte ptr [ecx+34h], 1
000A373B [00424607] 74 12                                        jz      short near ptr unk_42461B ; game-relative-target=0x000A374F
000A373D [00424609] 99                                           cdq
000A373E [0042460A] b9 19 00 00 00                               mov     ecx, 19h
000A3743 [0042460F] f7 f1                                        div     ecx
000A3745 [00424611] 50                                           push    eax
000A3746 [00424612] b8 f0 ef 4a 00                               mov     eax, 4AEFF0h
000A374B [00424617] ff d0                                        call    eax
000A374D [00424619] 34 01                                        xor     al, 1
000A374F [0042461B] 85 c0                                        test    eax, eax
000A3751 [0042461D] 58                                           pop     eax
000A3752 [0042461E] c2 0c 00                                     retn    0Ch
