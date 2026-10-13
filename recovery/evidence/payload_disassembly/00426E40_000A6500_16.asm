; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426E40; baseline game VA=0x000A6500; size=22
; Relative branch annotations use the baseline game destination.
000A6500 [00426E40] b8 70 3b 46 00                               mov     eax, 463B70h
000A6505 [00426E45] ff d0                                        call    eax
000A6507 [00426E47] 85 c0                                        test    eax, eax
000A6509 [00426E49] 75 01                                        jnz     short near ptr unk_426E4C ; game-relative-target=0x000A650C
000A650B [00426E4B] c3                                           retn
000A650C [00426E4C] 8b ce                                        mov     ecx, esi
000A650E [00426E4E] b8 20 5d 0a 00                               mov     eax, 0A5D20h
000A6513 [00426E53] ff d0                                        call    eax
000A6515 [00426E55] c3                                           retn
