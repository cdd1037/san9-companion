; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423DA4; baseline game VA=0x000A5D00; size=32
; Relative branch annotations use the baseline game destination.
000A5D00 [00423DA4] b8 90 c9 46 00                               mov     eax, 46C990h
000A5D05 [00423DA9] ff d0                                        call    eax
000A5D07 [00423DAB] 33 c0                                        xor     eax, eax
000A5D09 [00423DAD] a3 08 fc 43 00                               mov     ds:43FC08h, eax
000A5D0E [00423DB2] 8b 46 38                                     mov     eax, [esi+38h]
000A5D11 [00423DB5] 8b 88 b8 00 00 00                            mov     ecx, [eax+0B8h]
000A5D17 [00423DBB] 8b 41 70                                     mov     eax, [ecx+70h]
000A5D1A [00423DBE] a3 f3 fa 43 00                               mov     ds:43FAF3h, eax
000A5D1F [00423DC3] c3                                           retn
