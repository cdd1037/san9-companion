; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426E9C; baseline game VA=0x000A6AE0; size=29
; Relative branch annotations use the baseline game destination.
000A6AE0 [00426E9C] ff 74 24 04                                  push    dword ptr [esp+4]
000A6AE4 [00426EA0] b8 b0 e1 45 00                               mov     eax, 45E1B0h
000A6AE9 [00426EA5] ff d0                                        call    eax
000A6AEB [00426EA7] 85 c0                                        test    eax, eax
000A6AED [00426EA9] 75 0b                                        jnz     short near ptr unk_426EB6 ; game-relative-target=0x000A6AFA
000A6AEF [00426EAB] 8b ce                                        mov     ecx, esi
000A6AF1 [00426EAD] b8 20 5d 0a 00                               mov     eax, 0A5D20h
000A6AF6 [00426EB2] ff d0                                        call    eax
000A6AF8 [00426EB4] 34 01                                        xor     al, 1
000A6AFA [00426EB6] c2 04 00                                     retn    4
