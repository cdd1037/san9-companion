; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004246A0; baseline game VA=0x000A3510; size=29
; Relative branch annotations use the baseline game destination.
000A3510 [004246A0] 3b 7b 30                                     cmp     edi, [ebx+30h]
000A3513 [004246A3] 75 06                                        jnz     short near ptr unk_4246AB ; game-relative-target=0x000A351B
000A3515 [004246A5] 68 d0 6e 56 00                               push    566ED0h
000A351A [004246AA] c3                                           retn
000A351B [004246AB] 80 7a 54 04                                  cmp     byte ptr [edx+54h], 4
000A351F [004246AF] 74 f4                                        jz      short near ptr unk_4246A5 ; game-relative-target=0x000A3515
000A3521 [004246B1] 8b 87 f8 00 00 00                            mov     eax, [edi+0F8h]
000A3527 [004246B7] 89 44 24 14                                  mov     [esp+14h], eax
000A352B [004246BB] eb e8                                        jmp     short near ptr unk_4246A5 ; game-relative-target=0x000A3515
