; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428AF0; baseline game VA=0x000A4EA0; size=10
; Relative branch annotations use the baseline game destination.
000A4EA0 [00428AF0] 85 c9                                        test    ecx, ecx
000A4EA2 [00428AF2] 7d 03                                        jge     short near ptr unk_428AF7 ; game-relative-target=0x000A4EA7
000A4EA4 [00428AF4] c1 e1 02                                     shl     ecx, 2
000A4EA7 [00428AF7] 33 d2                                        xor     edx, edx
000A4EA9 [00428AF9] c3                                           retn
