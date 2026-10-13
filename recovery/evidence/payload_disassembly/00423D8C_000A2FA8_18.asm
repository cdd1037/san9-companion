; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423D8C; baseline game VA=0x000A2FA8; size=24
; Relative branch annotations use the baseline game destination.
000A2FA8 [00423D8C] 00    db 0x00
000A2FA9 [00423D8D] 00 08                                        add     [eax], cl
000A2FAB [00423D8F] 00 10                                        add     [eax], dl
000A2FAD [00423D91] 00 01                                        add     [ecx], al
000A2FAF [00423D93] 00 03                                        add     [ebx], al
000A2FB1 [00423D95] 00 06                                        add     [esi], al
000A2FB3 [00423D97] 00    db 0x00
000A2FB4 [00423D98] 00 02                                        add     [edx], al
000A2FB6 [00423D9A] 00 04 00                                     add     [eax+eax], al
000A2FB9 [00423D9D] 08 00                                        or      [eax], al
000A2FBB [00423D9F] 00 40 00                                     add     [eax+0], al
000A2FBE [00423DA2] 80    db 0x80
000A2FBF [00423DA3] 00    db 0x00
