; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C5C0; baseline game VA=0x000A2600; size=42
; Relative branch annotations use the baseline game destination.
000A2600 [0042C5C0] 5a                                           pop     edx
000A2601 [0042C5C1] 83 7c 24 08 00                               cmp     dword ptr [esp+8], 0
000A2606 [0042C5C6] 75 1b                                        jnz     short near ptr unk_42C5E3 ; game-relative-target=0x000A2623
000A2608 [0042C5C8] c7 44 24 08 b9 20 00 00                      mov     dword ptr [esp+8], 20B9h
000A2610 [0042C5D0] 8b 41 04                                     mov     eax, [ecx+4]
000A2613 [0042C5D3] 8b 40 08                                     mov     eax, [eax+8]
000A2616 [0042C5D6] 80 78 06 03                                  cmp     byte ptr [eax+6], 3
000A261A [0042C5DA] 75 07                                        jnz     short near ptr unk_42C5E3 ; game-relative-target=0x000A2623
000A261C [0042C5DC] 68 18 ca 66 00                               push    66CA18h
000A2621 [0042C5E1] ff e2                                        jmp     edx
000A2623 [0042C5E3] 68 14 c2 66 00                               push    66C214h
000A2628 [0042C5E8] ff e2                                        jmp     edx
