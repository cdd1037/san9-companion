; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422CD8; baseline game VA=0x000A3C60; size=93
; Relative branch annotations use the baseline game destination.
000A3C60 [00422CD8] ff 15 dc f2 5f 00                            call    dword ptr ds:5FF2DCh
000A3C66 [00422CDE] a8 01                                        test    al, 1
000A3C68 [00422CE0] 74 05                                        jz      short near ptr unk_422CE7 ; game-relative-target=0x000A3C6F
000A3C6A [00422CE2] 33 c0                                        xor     eax, eax
000A3C6C [00422CE4] c2 04 00                                     retn    4
000A3C6F [00422CE7] 56                                           push    esi
000A3C70 [00422CE8] 53                                           push    ebx
000A3C71 [00422CE9] 55                                           push    ebp
000A3C72 [00422CEA] 57                                           push    edi
000A3C73 [00422CEB] 8b 6c 24 18                                  mov     ebp, [esp+18h]
000A3C77 [00422CEF] 33 ff                                        xor     edi, edi
000A3C79 [00422CF1] 8b 4c 24 14                                  mov     ecx, [esp+14h]
000A3C7D [00422CF5] 8b 71 04                                     mov     esi, [ecx+4]
000A3C80 [00422CF8] bb ff ff ff 7f                               mov     ebx, 7FFFFFFFh
000A3C85 [00422CFD] 8b 4e 08                                     mov     ecx, [esi+8]
000A3C88 [00422D00] b8 40 58 43 00                               mov     eax, 435840h
000A3C8D [00422D05] ff d0                                        call    eax
000A3C8F [00422D07] 85 c0                                        test    eax, eax
000A3C91 [00422D09] 74 1b                                        jz      short near ptr unk_422D26 ; game-relative-target=0x000A3CAE
000A3C93 [00422D0B] 6a 1a                                        push    1Ah
000A3C95 [00422D0D] 6a 1a                                        push    1Ah
000A3C97 [00422D0F] ff 76 08                                     push    dword ptr [esi+8]
000A3C9A [00422D12] 55                                           push    ebp
000A3C9B [00422D13] b8 80 a6 44 00                               mov     eax, 44A680h
000A3CA0 [00422D18] ff d0                                        call    eax
000A3CA2 [00422D1A] 83 c4 10                                     add     esp, 10h
000A3CA5 [00422D1D] 3b c3                                        cmp     eax, ebx
000A3CA7 [00422D1F] 7d 05                                        jge     short near ptr unk_422D26 ; game-relative-target=0x000A3CAE
000A3CA9 [00422D21] 8b d8                                        mov     ebx, eax
000A3CAB [00422D23] 8b 7e 08                                     mov     edi, [esi+8]
000A3CAE [00422D26] 8b 36                                        mov     esi, [esi]
000A3CB0 [00422D28] 85 f6                                        test    esi, esi
000A3CB2 [00422D2A] 75 d1                                        jnz     short near ptr unk_422CFD ; game-relative-target=0x000A3C85
000A3CB4 [00422D2C] 8b c7                                        mov     eax, edi
000A3CB6 [00422D2E] 5f                                           pop     edi
000A3CB7 [00422D2F] 5d                                           pop     ebp
000A3CB8 [00422D30] 5b                                           pop     ebx
000A3CB9 [00422D31] 5e                                           pop     esi
000A3CBA [00422D32] c2 04 00                                     retn    4
