; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004298B8; baseline game VA=0x000A1748; size=54
; Relative branch annotations use the baseline game destination.
000A1748 [004298B8] 8a 44 24 1f                                  mov     al, [esp+1Fh]
000A174C [004298BC] 3c 02                                        cmp     al, 2
000A174E [004298BE] 74 0a                                        jz      short near ptr unk_4298CA ; game-relative-target=0x000A175A
000A1750 [004298C0] 3c 09                                        cmp     al, 9
000A1752 [004298C2] 74 0f                                        jz      short near ptr unk_4298D3 ; game-relative-target=0x000A1763
000A1754 [004298C4] 68 e0 73 45 00                               push    4573E0h
000A1759 [004298C9] c3                                           retn
000A175A [004298CA] 6a 00                                        push    0
000A175C [004298CC] b8 c0 42 45 00                               mov     eax, 4542C0h
000A1761 [004298D1] eb 0a                                        jmp     short near ptr unk_4298DD ; game-relative-target=0x000A176D
000A1763 [004298D3] 68 50 c0 bf 01                               push    1BFC050h
000A1768 [004298D8] b8 20 74 45 00                               mov     eax, 457420h
000A176D [004298DD] 51                                           push    ecx
000A176E [004298DE] ff d0                                        call    eax
000A1770 [004298E0] 89 04 24                                     mov     [esp], eax
000A1773 [004298E3] b8 80 41 45 00                               mov     eax, 454180h
000A1778 [004298E8] ff d0                                        call    eax
000A177A [004298EA] 83 c4 08                                     add     esp, 8
000A177D [004298ED] c3                                           retn
