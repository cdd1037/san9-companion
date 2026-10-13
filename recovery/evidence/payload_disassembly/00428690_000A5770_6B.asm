; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428690; baseline game VA=0x000A5770; size=107
; Relative branch annotations use the baseline game destination.
000A5770 [00428690] 51                                           push    ecx
000A5771 [00428691] ba d3 4d 62 10                               mov     edx, 10624DD3h
000A5776 [00428696] 8b 8e cc 00 00 00                            mov     ecx, [esi+0CCh]
000A577C [0042869C] 85 c9                                        test    ecx, ecx
000A577E [0042869E] 74 57                                        jz      short near ptr unk_4286F7 ; game-relative-target=0x000A57D7
000A5780 [004286A0] 8b 89 b8 00 00 00                            mov     ecx, [ecx+0B8h]
000A5786 [004286A6] f6 41 34 04                                  test    byte ptr [ecx+34h], 4
000A578A [004286AA] 75 4b                                        jnz     short near ptr unk_4286F7 ; game-relative-target=0x000A57D7
000A578C [004286AC] f6 41 34 01                                  test    byte ptr [ecx+34h], 1
000A5790 [004286B0] 75 0b                                        jnz     short near ptr unk_4286BD ; game-relative-target=0x000A579D
000A5792 [004286B2] f6 05 16 ff 43 00 01                         test    byte ptr ds:43FF16h, 1
000A5799 [004286B9] 74 02                                        jz      short near ptr unk_4286BD ; game-relative-target=0x000A579D
000A579B [004286BB] d1 e2                                        shl     edx, 1
000A579D [004286BD] 52                                           push    edx
000A579E [004286BE] b8 10 30 44 00                               mov     eax, 443010h
000A57A3 [004286C3] ff d0                                        call    eax
000A57A5 [004286C5] 5a                                           pop     edx
000A57A6 [004286C6] c1 e8 0c                                     shr     eax, 0Ch
000A57A9 [004286C9] 8b ca                                        mov     ecx, edx
000A57AB [004286CB] c1 e9 02                                     shr     ecx, 2
000A57AE [004286CE] 3d 80 00 00 00                               cmp     eax, 80h
000A57B3 [004286D3] 7c 04                                        jl      short near ptr unk_4286D9 ; game-relative-target=0x000A57B9
000A57B5 [004286D5] 8b d1                                        mov     edx, ecx
000A57B7 [004286D7] eb 1e                                        jmp     short near ptr unk_4286F7 ; game-relative-target=0x000A57D7
000A57B9 [004286D9] 3a 05 c0 64 0a 00                            cmp     al, ds:0A64C0h
000A57BF [004286DF] 7c 16                                        jl      short near ptr unk_4286F7 ; game-relative-target=0x000A57D7
000A57C1 [004286E1] 2b d1                                        sub     edx, ecx
000A57C3 [004286E3] 3a 05 c1 64 0a 00                            cmp     al, ds:0A64C1h
000A57C9 [004286E9] 7c 0c                                        jl      short near ptr unk_4286F7 ; game-relative-target=0x000A57D7
000A57CB [004286EB] 2b d1                                        sub     edx, ecx
000A57CD [004286ED] 3a 05 c2 64 0a 00                            cmp     al, ds:0A64C2h
000A57D3 [004286F3] 7c 02                                        jl      short near ptr unk_4286F7 ; game-relative-target=0x000A57D7
000A57D5 [004286F5] 2b d1                                        sub     edx, ecx
000A57D7 [004286F7] 8b c2                                        mov     eax, edx
000A57D9 [004286F9] 59                                           pop     ecx
000A57DA [004286FA] c3                                           retn
