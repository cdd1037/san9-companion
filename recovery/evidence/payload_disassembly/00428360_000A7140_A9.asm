; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428360; baseline game VA=0x000A7140; size=169
; Relative branch annotations use the baseline game destination.
000A7140 [00428360] 51                                           push    ecx
000A7141 [00428361] ff 77 28                                     push    dword ptr [edi+28h]
000A7144 [00428364] b8 f0 3c 47 00                               mov     eax, 473CF0h
000A7149 [00428369] ff d0                                        call    eax
000A714B [0042836B] 8b 40 74                                     mov     eax, [eax+74h]
000A714E [0042836E] f6 40 0d 01                                  test    byte ptr [eax+0Dh], 1
000A7152 [00428372] 59                                           pop     ecx
000A7153 [00428373] 8b 7e 78                                     mov     edi, [esi+78h]
000A7156 [00428376] 75 0a                                        jnz     short near ptr unk_428382 ; game-relative-target=0x000A7162
000A7158 [00428378] 8b 86 80 00 00 00                            mov     eax, [esi+80h]
000A715E [0042837E] 85 c0                                        test    eax, eax
000A7160 [00428380] 75 0a                                        jnz     short near ptr unk_42838C ; game-relative-target=0x000A716C
000A7162 [00428382] 89 7c 24 04                                  mov     [esp+4], edi
000A7166 [00428386] 68 70 a3 47 00                               push    47A370h
000A716B [0042838B] c3                                           retn
000A716C [0042838C] 53                                           push    ebx
000A716D [0042838D] 83 ec 20                                     sub     esp, 20h ; ' '
000A7170 [00428390] 8b d9                                        mov     ebx, ecx
000A7172 [00428392] 55                                           push    ebp
000A7173 [00428393] 50                                           push    eax
000A7174 [00428394] 6a 00                                        push    0
000A7176 [00428396] 56                                           push    esi
000A7177 [00428397] b8 c0 a3 47 00                               mov     eax, 47A3C0h
000A717C [0042839C] ff d0                                        call    eax
000A717E [0042839E] 8b cc                                        mov     ecx, esp
000A7180 [004283A0] b8 b0 34 47 00                               mov     eax, 4734B0h
000A7185 [004283A5] ff d0                                        call    eax
000A7187 [004283A7] 8b cb                                        mov     ecx, ebx
000A7189 [004283A9] 54                                           push    esp
000A718A [004283AA] b8 90 82 47 00                               mov     eax, 478290h
000A718F [004283AF] ff d0                                        call    eax
000A7191 [004283B1] 8b cb                                        mov     ecx, ebx
000A7193 [004283B3] b8 20 9f 47 00                               mov     eax, 479F20h
000A7198 [004283B8] ff d0                                        call    eax
000A719A [004283BA] ff b6 80 00 00 00                            push    dword ptr [esi+80h]
000A71A0 [004283C0] 57                                           push    edi
000A71A1 [004283C1] 6a 00                                        push    0
000A71A3 [004283C3] 56                                           push    esi
000A71A4 [004283C4] 8b cb                                        mov     ecx, ebx
000A71A6 [004283C6] b8 c0 a3 47 00                               mov     eax, 47A3C0h
000A71AB [004283CB] ff d0                                        call    eax
000A71AD [004283CD] 8b cb                                        mov     ecx, ebx
000A71AF [004283CF] 8d 44 24 4c                                  lea     eax, [esp+4Ch]
000A71B3 [004283D3] 50                                           push    eax
000A71B4 [004283D4] b8 90 82 47 00                               mov     eax, 478290h
000A71B9 [004283D9] ff d0                                        call    eax
000A71BB [004283DB] 8b cc                                        mov     ecx, esp
000A71BD [004283DD] b8 10 82 51 00                               mov     eax, 518210h
000A71C2 [004283E2] ff d0                                        call    eax
000A71C4 [004283E4] 8d 4c 24 4c                                  lea     ecx, [esp+4Ch]
000A71C8 [004283E8] 8b c4                                        mov     eax, esp
000A71CA [004283EA] 6a 7f                                        push    7Fh
000A71CC [004283EC] 50                                           push    eax
000A71CD [004283ED] b8 80 ef 46 00                               mov     eax, 46EF80h
000A71D2 [004283F2] ff d0                                        call    eax
000A71D4 [004283F4] 8b cc                                        mov     ecx, esp
000A71D6 [004283F6] b8 e0 80 51 00                               mov     eax, 5180E0h
000A71DB [004283FB] ff d0                                        call    eax
000A71DD [004283FD] 83 c4 20                                     add     esp, 20h ; ' '
000A71E0 [00428400] 5b                                           pop     ebx
000A71E1 [00428401] 68 bc 2d 4a 00                               push    4A2DBCh
000A71E6 [00428406] c2 0c 00                                     retn    0Ch
