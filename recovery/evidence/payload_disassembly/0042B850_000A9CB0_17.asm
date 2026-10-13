; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B850; baseline game VA=0x000A9CB0; size=23
; Relative branch annotations use the baseline game destination.
000A9CB0 [0042B850] 33 c0                                        xor     eax, eax
000A9CB2 [0042B852] 87 05 28 9c 0a 00                            xchg    eax, ds:0A9C28h
000A9CB8 [0042B858] 85 c0                                        test    eax, eax
000A9CBA [0042B85A] 74 03                                        jz      short near ptr unk_42B85F ; game-relative-target=0x000A9CBF
000A9CBC [0042B85C] c2 04 00                                     retn    4
000A9CBF [0042B85F] 8b cf                                        mov     ecx, edi
000A9CC1 [0042B861] 68 f0 35 51 00                               push    5135F0h
000A9CC6 [0042B866] c3                                           retn
