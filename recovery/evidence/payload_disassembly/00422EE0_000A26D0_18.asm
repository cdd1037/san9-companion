; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422EE0; baseline game VA=0x000A26D0; size=24
; Relative branch annotations use the baseline game destination.
000A26D0 [00422EE0] f6 42 34 04                                  test    byte ptr [edx+34h], 4
000A26D4 [00422EE4] 75 0c                                        jnz     short near ptr unk_422EF2 ; game-relative-target=0x000A26E2
000A26D6 [00422EE6] 8b 86 cc 00 00 00                            mov     eax, [esi+0CCh]
000A26DC [00422EEC] 85 c0                                        test    eax, eax
000A26DE [00422EEE] 75 02                                        jnz     short near ptr unk_422EF2 ; game-relative-target=0x000A26E2
000A26E0 [00422EF0] 40                                           inc     eax
000A26E1 [00422EF1] c3                                           retn
000A26E2 [00422EF2] 68 00 07 4b 00                               push    4B0700h
000A26E7 [00422EF7] c3                                           retn
