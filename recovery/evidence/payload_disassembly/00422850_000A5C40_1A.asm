; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422850; baseline game VA=0x000A5C40; size=26
; Relative branch annotations use the baseline game destination.
000A5C40 [00422850] 8b 87 e8 00 00 00                            mov     eax, [edi+0E8h]
000A5C46 [00422856] 40                                           inc     eax
000A5C47 [00422857] 40                                           inc     eax
000A5C48 [00422858] 69 c0 88 13 00 00                            imul    eax, 1388h
000A5C4E [0042285E] 03 c6                                        add     eax, esi
000A5C50 [00422860] 89 44 24 04                                  mov     [esp+4], eax
000A5C54 [00422864] 68 a0 73 43 00                               push    4373A0h
000A5C59 [00422869] c3                                           retn
