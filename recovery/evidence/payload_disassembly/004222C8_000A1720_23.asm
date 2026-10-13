; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004222C8; baseline game VA=0x000A1720; size=35
; Relative branch annotations use the baseline game destination.
000A1720 [004222C8] 33 c0                                        xor     eax, eax
000A1722 [004222CA] 83 ff 0b                                     cmp     edi, 0Bh
000A1725 [004222CD] 7e 03                                        jle     short near ptr unk_4222D2 ; game-relative-target=0x000A172A
000A1727 [004222CF] c2 04 00                                     retn    4
000A172A [004222D2] b0 01                                        mov     al, 1
000A172C [004222D4] 83 ff 08                                     cmp     edi, 8
000A172F [004222D7] 7d f6                                        jge     short near ptr unk_4222CF ; game-relative-target=0x000A1727
000A1731 [004222D9] 8a 87 c4 4a 45 00                            mov     al, [edi+454AC4h]
000A1737 [004222DF] 8b 74 24 28                                  mov     esi, [esp+28h]
000A173B [004222E3] 68 59 fa 52 00                               push    52FA59h
000A1740 [004222E8] c2 08 00                                     retn    8
