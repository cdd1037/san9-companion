; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423308; baseline game VA=0x000A3990; size=28
; Relative branch annotations use the baseline game destination.
000A3990 [00423308] 8b 70 08                                     mov     esi, [eax+8]
000A3993 [0042330B] 8b 38                                        mov     edi, [eax]
000A3995 [0042330D] 85 ff                                        test    edi, edi
000A3997 [0042330F] 74 10                                        jz      short near ptr unk_423321 ; game-relative-target=0x000A39A9
000A3999 [00423311] 8b 7f 08                                     mov     edi, [edi+8]
000A399C [00423314] 89 3d 08 fc 43 00                            mov     ds:43FC08h, edi
000A39A2 [0042331A] 33 c0                                        xor     eax, eax
000A39A4 [0042331C] a3 0c fc 43 00                               mov     ds:43FC0Ch, eax
000A39A9 [00423321] 85 f6                                        test    esi, esi
000A39AB [00423323] c3                                           retn
