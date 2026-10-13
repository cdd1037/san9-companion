; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423350; baseline game VA=0x000A1D00; size=43
; Relative branch annotations use the baseline game destination.
000A1D00 [00423350] a1 08 fc 43 00                               mov     eax, ds:43FC08h
000A1D05 [00423355] 85 c0                                        test    eax, eax
000A1D07 [00423357] 74 1b                                        jz      short near ptr unk_423374 ; game-relative-target=0x000A1D24
000A1D09 [00423359] 8b d8                                        mov     ebx, eax
000A1D0B [0042335B] 33 c0                                        xor     eax, eax
000A1D0D [0042335D] a3 08 fc 43 00                               mov     ds:43FC08h, eax
000A1D12 [00423362] a1 0c fc 43 00                               mov     eax, ds:43FC0Ch
000A1D17 [00423367] 85 c0                                        test    eax, eax
000A1D19 [00423369] 74 09                                        jz      short near ptr unk_423374 ; game-relative-target=0x000A1D24
000A1D1B [0042336B] 8b f8                                        mov     edi, eax
000A1D1D [0042336D] 58                                           pop     eax
000A1D1E [0042336E] 68 cb 63 4b 00                               push    4B63CBh
000A1D23 [00423373] c3                                           retn
000A1D24 [00423374] 8b 86 24 08 00 00                            mov     eax, [esi+824h]
000A1D2A [0042337A] c3                                           retn
