; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004272E0; baseline game VA=0x000A7000; size=24
; Relative branch annotations use the baseline game destination.
000A7000 [004272E0] c6 44 24 78 0b                               mov     byte ptr [esp+78h], 0Bh
000A7005 [004272E5] b8 e0 4e 0a 00                               mov     eax, 0A4EE0h
000A700A [004272EA] ff d0                                        call    eax
000A700C [004272EC] 8b cf                                        mov     ecx, edi
000A700E [004272EE] 85 c0                                        test    eax, eax
000A7010 [004272F0] 75 05                                        jnz     short near ptr unk_4272F7 ; game-relative-target=0x000A7017
000A7012 [004272F2] c6 44 24 08 90                               mov     byte ptr [esp+8], 90h
000A7017 [004272F7] c3                                           retn
