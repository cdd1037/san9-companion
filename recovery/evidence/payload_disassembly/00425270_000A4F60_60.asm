; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425270; baseline game VA=0x000A4F60; size=96
; Relative branch annotations use the baseline game destination.
000A4F60 [00425270] 53                                           push    ebx
000A4F61 [00425271] 8d 8f 58 08 00 00                            lea     ecx, [edi+858h]
000A4F67 [00425277] b8 60 b9 4b 00                               mov     eax, 4BB960h
000A4F6C [0042527C] ff d0                                        call    eax
000A4F6E [0042527E] 33 ff                                        xor     edi, edi
000A4F70 [00425280] 8b 46 e4                                     mov     eax, [esi-1Ch]
000A4F73 [00425283] 8b 48 08                                     mov     ecx, [eax+8]
000A4F76 [00425286] 81 79 08 78 e8 ff ff                         cmp     dword ptr [ecx+8], 0FFFFE878h
000A4F7D [0042528D] 7e 01                                        jle     short near ptr unk_425290 ; game-relative-target=0x000A4F80
000A4F7F [0042528F] 47                                           inc     edi
000A4F80 [00425290] 8b 5b 04                                     mov     ebx, [ebx+4]
000A4F83 [00425293] 8b 4b 08                                     mov     ecx, [ebx+8]
000A4F86 [00425296] 80 79 06 05                                  cmp     byte ptr [ecx+6], 5
000A4F8A [0042529A] 75 09                                        jnz     short near ptr unk_4252A5 ; game-relative-target=0x000A4F95
000A4F8C [0042529C] 81 79 08 00 17 00 00                         cmp     dword ptr [ecx+8], 1700h
000A4F93 [004252A3] 7e 1d                                        jle     short near ptr unk_4252C2 ; game-relative-target=0x000A4FB2
000A4F95 [004252A5] 83 b9 e8 00 00 00 00                         cmp     dword ptr [ecx+0E8h], 0
000A4F9C [004252AC] 7e 14                                        jle     short near ptr unk_4252C2 ; game-relative-target=0x000A4FB2
000A4F9E [004252AE] 85 ff                                        test    edi, edi
000A4FA0 [004252B0] 74 06                                        jz      short near ptr unk_4252B8 ; game-relative-target=0x000A4FA8
000A4FA2 [004252B2] f6 41 0f 04                                  test    byte ptr [ecx+0Fh], 4
000A4FA6 [004252B6] 75 0a                                        jnz     short near ptr unk_4252C2 ; game-relative-target=0x000A4FB2
000A4FA8 [004252B8] 51                                           push    ecx
000A4FA9 [004252B9] 8b ce                                        mov     ecx, esi
000A4FAB [004252BB] b8 70 ef 46 00                               mov     eax, 46EF70h
000A4FB0 [004252C0] ff d0                                        call    eax
000A4FB2 [004252C2] 8b 1b                                        mov     ebx, [ebx]
000A4FB4 [004252C4] 85 db                                        test    ebx, ebx
000A4FB6 [004252C6] 75 cb                                        jnz     short near ptr unk_425293 ; game-relative-target=0x000A4F83
000A4FB8 [004252C8] 58                                           pop     eax
000A4FB9 [004252C9] 04 39                                        add     al, 39h ; '9'
000A4FBB [004252CB] 50                                           push    eax
000A4FBC [004252CC] c2 08 00                                     retn    8
000A4FBF [004252CF] cc                                           int     3
