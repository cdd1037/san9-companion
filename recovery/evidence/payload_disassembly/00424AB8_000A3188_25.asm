; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424AB8; baseline game VA=0x000A3188; size=37
; Relative branch annotations use the baseline game destination.
000A3188 [00424AB8] eb 0e                                        jmp     short near ptr unk_424AC8 ; game-relative-target=0x000A3198
000A318A [00424ABA] 39 44 24 20                                  cmp     [esp+20h], eax
000A318E [00424ABE] 74 14                                        jz      short near ptr unk_424AD4 ; game-relative-target=0x000A31A4
000A3190 [00424AC0] 68 57 24 50 00                               push    502457h
000A3195 [00424AC5] c2 04 00                                     retn    4
000A3198 [00424AC8] 8b 50 54                                     mov     edx, [eax+54h]
000A319B [00424ACB] 8b 4c 24 20                                  mov     ecx, [esp+20h]
000A319F [00424ACF] 39 51 54                                     cmp     [ecx+54h], edx
000A31A2 [00424AD2] 75 ec                                        jnz     short near ptr unk_424AC0 ; game-relative-target=0x000A3190
000A31A4 [00424AD4] 3b 85 f8 00 00 00                            cmp     eax, [ebp+0F8h]
000A31AA [00424ADA] 75 e4                                        jnz     short near ptr unk_424AC0 ; game-relative-target=0x000A3190
000A31AC [00424ADC] c3                                           retn
