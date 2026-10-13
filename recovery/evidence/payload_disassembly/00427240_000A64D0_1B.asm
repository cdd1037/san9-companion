; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427240; baseline game VA=0x000A64D0; size=27
; Relative branch annotations use the baseline game destination.
000A64D0 [00427240] 33 d2                                        xor     edx, edx
000A64D2 [00427242] b8 38 3c 25 01                               mov     eax, 1253C38h
000A64D7 [00427247] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A64DB [0042724B] 75 0d                                        jnz     short near ptr unk_42725A ; game-relative-target=0x000A64EA
000A64DD [0042724D] 05 d4 00 00 00                               add     eax, 0D4h
000A64E2 [00427252] 42                                           inc     edx
000A64E3 [00427253] 80 fa 32                                     cmp     dl, 32h ; '2'
000A64E6 [00427256] 7c ef                                        jl      short near ptr unk_427247 ; game-relative-target=0x000A64D7
000A64E8 [00427258] 33 c0                                        xor     eax, eax
000A64EA [0042725A] c3                                           retn
