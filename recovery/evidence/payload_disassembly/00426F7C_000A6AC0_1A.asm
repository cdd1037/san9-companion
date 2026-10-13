; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426F7C; baseline game VA=0x000A6AC0; size=26
; Relative branch annotations use the baseline game destination.
000A6AC0 [00426F7C] 56                                           push    esi
000A6AC1 [00426F7D] b8 a0 1e 44 00                               mov     eax, 441EA0h
000A6AC6 [00426F82] ff d0                                        call    eax
000A6AC8 [00426F84] 85 c0                                        test    eax, eax
000A6ACA [00426F86] 75 0b                                        jnz     short near ptr unk_426F93 ; game-relative-target=0x000A6AD7
000A6ACC [00426F88] 8b cf                                        mov     ecx, edi
000A6ACE [00426F8A] b8 20 5d 0a 00                               mov     eax, 0A5D20h
000A6AD3 [00426F8F] ff d0                                        call    eax
000A6AD5 [00426F91] 34 01                                        xor     al, 1
000A6AD7 [00426F93] c2 04 00                                     retn    4
